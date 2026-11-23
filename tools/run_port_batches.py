#!/usr/bin/env python3
"""Run readable-port batches of 500 until the exported queue is exhausted.

Each batch:
  1. refresh tools/port_work_queue.py with --port-src source_port, so compiled
     and explicitly unsupported addresses leave the queue;
  2. generate the next batch with tools/generate_port_batch.py;
  3. compile each new source as permissive C;
  4. move compile failures to source_port/unsupported with PORT_STATUS: STUB;
  5. link the accumulated objects into the PE with /force:unresolved.

Compilation proves structural integration, not behavioral equivalence. Stubs
and unresolved externals are temporary and are never counted as recovered.
"""
from __future__ import annotations

import argparse
import concurrent.futures
import json
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SRC = ROOT / "source_port/src"
UNSUPPORTED = ROOT / "source_port/unsupported"
BUILD = ROOT / "source_port/build"
INCLUDE = ROOT / "source_port/include"
FLAGS = [
    "clang", "--target=i686-windows-gnu", "-x", "c", "-std=gnu99",
    "-ffreestanding", "-w", "-Wno-int-conversion",
    "-Wno-implicit-function-declaration", "-Wno-incompatible-pointer-types",
    "-I", str(INCLUDE),
]


def run(cmd, **kwargs):
    return subprocess.run(cmd, check=True, capture_output=True, text=True, **kwargs)


def compile_one(path: Path):
    obj = BUILD / (path.stem + ".obj")
    result = subprocess.run(FLAGS + ["-c", str(path), "-o", str(obj)],
                            capture_output=True, text=True)
    return path, obj, result


def first_error(text: str) -> str:
    for line in text.splitlines():
        if ": error: " in line or line.startswith("error: "):
            return line.strip()[:300]
    return (text.strip().splitlines() or ["unknown compile error"])[0][:300]


def mark_unsupported(path: Path, error: str):
    UNSUPPORTED.mkdir(parents=True, exist_ok=True)
    text = path.read_text(encoding="utf-8", errors="replace")
    (UNSUPPORTED / path.name).write_text(
        "// PORT_STATUS: STUB\n"
        f"// Bulk translation did not compile: {error}\n" + text,
        encoding="utf-8")
    path.unlink(missing_ok=True)
    obj = BUILD / (path.stem + ".obj")
    obj.unlink(missing_ok=True)


def link_pe():
    BUILD.mkdir(parents=True, exist_ok=True)
    objects = sorted(BUILD.glob("*.obj"))
    if not objects:
        return None
    result = subprocess.run(
        ["lld-link", "/entry:main", "/subsystem:console", "/nodefaultlib",
         "/force:unresolved", "/force:multiple", f"/out:{BUILD/'pc2_port.exe'}"] + [str(p) for p in objects],
        capture_output=True, text=True)
    if result.returncode:
        return first_error(result.stderr or result.stdout)
    return None


def refresh_symbols():
    run([sys.executable, str(ROOT / "tools/generate_port_batch.py"), "--limit", "0"])


def update_manifest():
    entries = []
    for path in sorted(SRC.glob("0x*.c*")):
        text = path.read_text(encoding="utf-8", errors="replace")
        marker = re.search(r"// original:\s*(0x[0-9a-f]+)", text, re.I)
        if not marker:
            continue
        name = re.search(r"//\s*([^:\n]+): ported from", text)
        entries.append({"address": marker.group(1).lower(),
                        "name": name.group(1).strip() if name else path.stem,
                        "source": str(path.relative_to(ROOT)),
                        "status": "compiled_not_verified"})
    (ROOT / "source_port/work_queue/port_manifest.json").write_text(
        json.dumps({"schema": "pc2.readable_port_manifest.v1",
                    "compiled": len(entries),
                    "note": "Compilation proves structural integration, not behavioral equivalence.",
                    "functions": entries}, indent=2) + "\n", encoding="utf-8")
    return len(entries)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--batch-size", type=int, default=500)
    parser.add_argument("--max-batches", type=int, default=20)
    parser.add_argument("--jobs", type=int, default=8)
    args = parser.parse_args()
    SRC.mkdir(parents=True, exist_ok=True)
    BUILD.mkdir(parents=True, exist_ok=True)
    for batch_no in range(1, args.max_batches + 1):
        run([sys.executable, str(ROOT / "tools/port_work_queue.py"),
             "--root", str(ROOT), "--port-src", "source_port", "--limit", "10"])
        manifest = Path(f"/tmp/opencode/port_batch_{batch_no}.json")
        before = json.loads((ROOT / "source_port/work_queue/queue.json").read_text())["summary"]
        run([sys.executable, str(ROOT / "tools/generate_port_batch.py"),
             "--limit", str(args.batch_size), "--manifest", str(manifest)])
        data = json.loads(manifest.read_text())
        files = [ROOT / item["source"] for item in data["functions"]]
        if not files:
            print(f"batch {batch_no}: nothing left (queue {before})")
            break
        compiled, failed = [], []
        with concurrent.futures.ThreadPoolExecutor(max_workers=args.jobs) as ex:
            for path, obj, result in ex.map(compile_one, files):
                if result.returncode:
                    failed.append((path, first_error(result.stderr or result.stdout)))
                else:
                    compiled.append(path)
        for path, error in failed:
            mark_unsupported(path, error)
        refresh_symbols()
        # Recompile the fixed scaffolding, then link all accumulated objects.
        for path in sorted(list(SRC.glob("port_entry.c")) + list((ROOT / "source_port/stubs").glob("*.c"))):
            result = subprocess.run(FLAGS + ["-c", str(path), "-o", str(BUILD / (path.stem + ".obj"))],
                                    capture_output=True, text=True)
            if result.returncode:
                print(f"batch {batch_no}: scaffold compile failed: {first_error(result.stderr or result.stdout)}")
        link_error = link_pe()
        print(f"batch {batch_no}: compiled {len(compiled)}, unsupported {len(failed)}, "
              f"queue before {before['queued']}, link {'ok' if not link_error else link_error}")
    total = update_manifest()
    run([sys.executable, str(ROOT / "tools/port_work_queue.py"),
         "--root", str(ROOT), "--port-src", "source_port", "--limit", "10"])
    summary = json.loads((ROOT / "source_port/work_queue/queue.json").read_text())["summary"]
    print(f"covered sources {total}; queue {summary}")


if __name__ == "__main__":
    raise SystemExit(main())
