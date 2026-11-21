#!/usr/bin/env python3
"""Rerun tracked PC2 verifier scripts and save strict per-function evidence."""

from __future__ import annotations

import argparse
from concurrent.futures import ThreadPoolExecutor
import json
import os
from pathlib import Path
import re
import subprocess
import sys

from match_decomp import ROOT

SHARED_REPORT_VERIFIERS = {
    "reconstructed/match/batch01/part1/verify.sh",
    "reconstructed/match/batch02/part1/verify_c.sh",
}


def tracked_verifiers():
    result = subprocess.run(["git", "ls-files", "-z", "--", "reconstructed/match"],
                            cwd=ROOT, capture_output=True, text=True, check=True)
    return [path for path in result.stdout.split("\0")
            if re.fullmatch(r"reconstructed/match/.+/verify[^/]*\.(?:sh|py)", path)]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--out", type=Path, required=True, help="fresh directory for JSON and logs")
    parser.add_argument("--jobs", type=int, choices=range(1, 17), default=1, metavar="N",
                        help="parallel verifier limit, 1–16 (default: 1)")
    parser.add_argument("scripts", nargs="*", type=Path, help="tracked verifier scripts (default: all)")
    args = parser.parse_args()
    try:
        available = tracked_verifiers()
        requested = ([str(path.resolve().relative_to(ROOT)) for path in args.scripts]
                     if args.scripts else available)
        if not requested or any(path not in available for path in requested):
            raise ValueError("provide tracked verifier scripts under reconstructed/match")
        output = args.out.resolve()
        output.mkdir(parents=True)
    except (OSError, ValueError, subprocess.CalledProcessError) as error:
        parser.exit(2, f"match audit could not start: {error}\n")

    records_dir = output / "functions"
    records_dir.mkdir()
    env = dict(os.environ, PC2_STRICT="1", PC2_AUTO_SYMBOLS="1",
               PC2_MATCH_AUDIT_DIR=str(records_dir))
    def run_script(job):
        index, script = job
        log_path = output / f"{index:03d}.log"
        if script.endswith(".py"):
            interpreter = sys.executable
        else:
            with (ROOT / script).open() as source:
                interpreter = "bash" if re.search(r"[/ ]bash\s*$", source.readline()) else "sh"
        with log_path.open("w") as log:
            result = subprocess.run([interpreter, script], cwd=ROOT, env=env, stdout=log,
                                    stderr=subprocess.STDOUT)
        print(f"{script} exit={result.returncode}", flush=True)
        return {"script": script, "exit_code": result.returncode, "log": log_path.name}

    jobs = list(enumerate(dict.fromkeys(requested), start=1))
    if args.jobs == 1:
        scripts = [run_script(job) for job in jobs]
    else:
        # These two verifiers use the same absolute report path.
        serial_jobs = [job for job in jobs if job[1] in SHARED_REPORT_VERIFIERS]
        with ThreadPoolExecutor(max_workers=args.jobs) as pool:
            serial_results = pool.submit(lambda: [run_script(job) for job in serial_jobs])
            parallel_jobs = [job for job in jobs if job[1] not in SHARED_REPORT_VERIFIERS]
            scripts = list(pool.map(run_script, parallel_jobs)) + serial_results.result()
        scripts.sort(key=lambda result: result["log"])

    records = [json.loads(path.read_text()) for path in sorted(records_dir.glob("*.json"))]
    addresses = {record["address"] for record in records}
    verified = {record["address"] for record in records if record.get("strict_match") is True}
    report = {"scripts": scripts, "attempts": len(records), "addresses": len(addresses),
              "strict_addresses": len(verified), "unverified_addresses": sorted(addresses - verified)}
    (output / "report.json").write_text(json.dumps(report, indent=2) + "\n")
    print(f"strict {len(verified)}/{len(addresses)} observed addresses from {len(records)} audited attempts")
    return int(not records or bool(addresses - verified) or any(row["exit_code"] for row in scripts))


if __name__ == "__main__":
    raise SystemExit(main())
