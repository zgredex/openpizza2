#!/usr/bin/env python3
"""Recheck tracked nonmatching C/C++ drafts with current VC6 symbol and EH evidence."""

import argparse
from collections import Counter
from concurrent.futures import ThreadPoolExecutor
import json
from pathlib import Path
import re
import struct
import subprocess
from tempfile import TemporaryDirectory

from coff_cache import cache_environment, cache_identity, cache_path, hash_bytes, store_object
from compare_vc6_unwind import handler_field_offset
import match_decomp as match
from verify_linked_image import PINNED_SHA256, assemble_image, merged_spans, write_outputs
from verify_vc6_eh_anchor import infer_anchor


ADDRESS_NAME = re.compile(r"0x[0-9a-f]+")
ASM = re.compile(rb"\b(?:__asm__|__asm|_asm)\b|\basm\s*[{(]")
ENTRY_HELPERS = ("??_G", "??_E", "??_D")
SEH_STATEMENT = re.compile(rb"\b__try\b")


def draft_sources():
    tracked = subprocess.check_output(["git", "ls-files", "-z", "--", "reconstructed/match"],
                                      cwd=match.ROOT, text=True).split("\0")
    candidates = {}
    accepted = set()
    for name in tracked:
        path = Path(name)
        if path.suffix.lower() not in {".c", ".cc", ".cpp", ".cxx"} or not ADDRESS_NAME.fullmatch(path.stem):
            continue
        address = int(path.stem, 16)
        if "nonmatching" not in path.parts and "asm" not in path.parts:
            accepted.add(address)
        elif "nonmatching" in path.parts and "asm" not in path.parts:
            candidates.setdefault(address, []).append(match.ROOT / path)
    return {address: paths[0] for address, paths in candidates.items()
            if address not in accepted and len(paths) == 1 and paths[0].is_file()}


def has_eh_frame(image, address, length):
    try:
        handler_field_offset(match.read_va(image, address, min(length, 32)))
    except ValueError:
        return False
    return True


def load_recipe(source, address, length, contents, compiler, has_eh):
    needs_cxx_eh = has_eh and not SEH_STATEMENT.search(contents)
    receipt = source.with_suffix(".json")
    if receipt.is_file():
        recorded = json.loads(receipt.read_text())
        if (isinstance(recorded, dict) and recorded.get("address") == hex(address) and recorded.get("length") == length
                and recorded.get("source_sha256") == hash_bytes(contents)
                and recorded.get("executable_sha256") == PINNED_SHA256
                and recorded.get("compiler", {}).get("sha256") == compiler):
            symbols = {name: int(va, 0) for name, va in recorded.get("symbol_overrides", {}).items()}
            flags = recorded["flags"]
            if needs_cxx_eh and "/GX" not in flags:
                flags = [flag for flag in flags if flag != "/GX-"] + ["/GX"]
            return flags, recorded.get("entry"), symbols, "recorded"
    return ["/O2", "/TP", *(["/GX"] if needs_cxx_eh else [])], None, {}, "default"


def select_entry(obj, address, length):
    _, sections, symbols = match.parse_coff(obj)
    functions = [symbol for symbol in symbols if symbol and symbol["section"] > 0 and symbol["type"] == 0x20
                 and symbol["storage"] == 2 and not symbol["name"].startswith(ENTRY_HELPERS)]
    if len(functions) != 1:
        indexed = [item for item in functions if match.resolve_auto_symbol(item["name"])[0] == address]
        if len(indexed) == 1:
            return indexed[0]["name"]
    if len(functions) != 1:
        functions = [item for item in functions if sections[item["section"] - 1]["name"] == ".text"
                     and 0 <= len(sections[item["section"] - 1]["raw"]) - item["value"] - length <= 15]
    if len(functions) != 1:
        raise ValueError("no unique emitted C/C++ entry")
    return functions[0]["name"]


def verify_one(address, source, image, vc6, compiler, cache, environment, identity, output, cache_only):
    length = match.function_length(address)
    has_eh = has_eh_frame(image, address, length)
    row = {"address": hex(address), "length": length, "source": str(source.relative_to(match.ROOT)),
           "has_eh": has_eh}
    try:
        contents = source.read_bytes()
        flags, entry, symbols, origin = load_recipe(source, address, length, contents, compiler, has_eh)
        cached = cache_path(cache, identity, source, contents, flags)
        row.update(flags=flags, recipe=origin)
        with TemporaryDirectory(prefix=f"{address:08x}-", dir=output) as folder:
            obj = Path(folder) / "candidate.obj"
            if cached is not None and cached.is_symlink():
                raise ValueError("cached object is a symlink")
            if cached is not None and cached.is_file():
                obj.write_bytes(cached.read_bytes())
                row["cache"] = "hit"
            elif cache_only:
                return {**row, "status": "cache_missing"}
            else:
                row["cache"] = "miss" if cached is not None else "bypass"
                match.compile_candidate(source, vc6, obj, flags,
                                        environment=environment if cached is not None else None)
                if source.read_bytes() != contents:
                    raise ValueError("source changed during compilation")
                data, _, _ = match.parse_coff(obj)
                if cached is not None:
                    store_object(cached, data)
            entry = entry or select_entry(obj, address, length)
            result = match.match_object(address, obj, symbols, length, entry, True, True, True)
            if has_eh and not result["strict_match"]:
                try:
                    evidence, anchors = infer_anchor(image, address, obj, entry, symbols)
                    row["inferred_anchors"] = {name: hex(va) for name, va in anchors.items()}
                    if anchors:
                        symbols.update(anchors)
                        result = match.match_object(address, obj, symbols, length, entry, True, True, True)
                    row["eh_candidates"] = evidence["compatible_handlers"]
                except (ValueError, struct.error) as error:
                    row["eh_diagnostic"] = str(error)
            result.update(match.match_provenance(source, vc6, flags, symbols, True, True, True))
            receipt = output / "functions" / f"{address:08x}.json"
            receipt.write_text(json.dumps(result, indent=2) + "\n")
            strict = result["strict_match"] and bool(result["linked_spans"])
            return {**row, "status": "strict" if strict else "miss",
                    "difference_count": result["difference_count"], "receipt": receipt.name,
                    "spans": result["linked_spans"] if strict else []}
    except (ValueError, OSError, KeyError, TypeError, struct.error, subprocess.TimeoutExpired) as error:
        return {**row, "status": "error", "error": str(error)}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--out", type=Path, required=True, help="fresh scratch report directory")
    parser.add_argument("--cache", type=Path, required=True, help="shared COFF cache directory")
    parser.add_argument("--cache-only", action="store_true")
    parser.add_argument("--eh-only", action="store_true")
    parser.add_argument("--address", action="append", type=lambda word: int(word, 0))
    parser.add_argument("--exclude", action="append", type=lambda word: int(word, 0), default=[])
    parser.add_argument("--jobs", type=int, choices=range(1, 9), default=4)
    args = parser.parse_args()
    try:
        image = match.pe_image(match.GAME)
        if hash_bytes(image[0]) != PINNED_SHA256:
            raise ValueError("draft sweep requires the pinned PE")
        extents = match.function_lengths()
        work = [(address, source) for address, source in sorted(draft_sources().items())
                if address not in args.exclude and address in extents
                and (not args.address or address in args.address)
                and not ASM.search(source.read_bytes())
                and (not args.eh_only or has_eh_frame(image, address, extents[address]))]
        if not work:
            raise ValueError("no eligible tracked drafts selected")
        vc6 = match.DEFAULT_VC6.resolve()
        compiler = match.compiler_provenance(vc6)["sha256"]
        environment = cache_environment()
        identity = cache_identity(vc6, match.ROOT, environment)
        cache, output = args.cache.resolve(), args.out.resolve()
        cache.mkdir(parents=True, exist_ok=True)
        output.mkdir(parents=True)
        (output / "functions").mkdir()
        with ThreadPoolExecutor(max_workers=args.jobs) as pool:
            rows = []
            for item in pool.map(lambda job: verify_one(*job, image, vc6, compiler, cache, environment, identity,
                                                        output, args.cache_only), work):
                rows.append(item)
                if len(rows) % 50 == 0:
                    print(f"{len(rows)}/{len(work)} drafts checked", flush=True)
        strict = [item for item in rows if item["status"] == "strict"]
        if strict:
            spans = merged_spans([(item["address"], item["spans"]) for item in strict])
            linked = assemble_image(image[0], [(int(s["file_offset"], 16), bytes.fromhex(s["hex_bytes"]))
                                               for s in spans])
            write_outputs([(output / "linked.exe", linked)])
        statuses = dict(Counter(item["status"] for item in rows))
        report = {"executable_sha256": PINNED_SHA256, "statuses": statuses,
                  "cache": dict(Counter(item["cache"] for item in rows if "cache" in item)),
                  "strict_bytes": sum(item["length"] for item in strict), "drafts": rows}
        (output / "summary.json").write_text(json.dumps(report, indent=2) + "\n")
        print(f"{len(rows)} drafts: {statuses}, {report['strict_bytes']} strict bytes")
        return int(args.cache_only and ("cache_missing" in statuses or "error" in statuses))
    except (ValueError, OSError, struct.error, subprocess.SubprocessError) as error:
        parser.exit(1, f"VC6 draft sweep: {error}\n")


if __name__ == "__main__":
    raise SystemExit(main())
