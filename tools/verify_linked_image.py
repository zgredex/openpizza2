#!/usr/bin/env python3
"""Relink strict COFF candidates into one byte-identical scratch PC2 image."""

from __future__ import annotations

import argparse
from collections import Counter
from concurrent.futures import ThreadPoolExecutor
from contextlib import ExitStack
from dataclasses import dataclass
import json
import os
from pathlib import Path
import struct
import subprocess
import tempfile

from coff_cache import (CACHE_FLAGS, cache_environment, cache_identity, cache_path,
                        hash_bytes as digest, store_object)
from match_decomp import (DEFAULT_VC6, GAME, ROOT, compile_candidate, compiler_provenance, function_lengths,
                          match_object, match_provenance, parse_coff, parse_symbols, pe_image,
                          relocation_target, relocation_value, resolve_auto_symbol,
                          section_relocations, write_function_audit)

PINNED_SHA256 = "18cfd32e0ac5d6d98162ec016e058a2b51808d9ca49ebee933ce3166ff9922fd"


class UnsupportedLink(ValueError):
    """A strict candidate requires a shape outside the scratch linker's scope."""


@dataclass(frozen=True)
class Recipe:
    address: int
    length: int
    file_offset: int
    source: Path
    source_sha256: str
    entry: str
    flags: tuple[str, ...]
    symbols: dict[str, int]
    audit_record: str | None = None


def link_body(obj, address, length, entry, symbols):
    object_bytes, sections, coff_symbols = parse_coff(obj)
    entries = [symbol for symbol in coff_symbols if symbol and symbol["name"] == entry]
    if len(entries) != 1 or not 0 < entries[0]["section"] <= len(sections):
        raise ValueError(f"expected one defined COFF entry for {entry}")
    entry_symbol = entries[0]
    index = entry_symbol["section"]
    section = sections[index - 1]
    raw = section["raw"]
    code_section = section["name"] == ".text" or section["name"].startswith(".text$")
    if (entry_symbol["value"] != 0 or not code_section
            or len(raw) < length or any(byte not in (0, 0x90, 0xCC) for byte in raw[length:])):
        raise UnsupportedLink("candidate has a prefix, non-padding extra bytes, or a non-code entry section")
    if any(symbol and symbol is not entry_symbol and symbol["section"] == index
           and symbol["type"] == 0x20 for symbol in coff_symbols):
        raise UnsupportedLink("candidate section contains another function")

    code = bytearray(raw[:length])
    bases = {index: (address, "candidate_entry")}
    calls = []
    previous_end = 0
    for offset, symbol_index, kind in sorted(section_relocations(object_bytes, section)):
        if offset < previous_end or offset + 4 > length:
            raise ValueError("COFF fixup crosses or overlaps the selected function extent")
        previous_end = offset + 4
        symbol = coff_symbols[symbol_index] if symbol_index < len(coff_symbols) else None
        if symbol is None:
            raise ValueError("COFF fixup has an invalid symbol index")
        if symbol["section"] > 0 and (symbol["section"] != index or symbol["value"] >= length):
            raise UnsupportedLink(f"COFF target {symbol['name']} is outside the single function extent")
        target, _ = relocation_target(symbol, bases, symbols, auto_symbols=True)
        if target is None:
            raise ValueError(f"unresolved COFF target {symbol['name']}")
        addend, = struct.unpack_from("<i", raw, offset)
        value = relocation_value(target, addend, address + offset, kind)
        struct.pack_into("<I", code, offset, value)
        if kind == 0x14 and offset > 0 and raw[offset - 1] == 0xE8:
            calls.append({"instruction": hex(address + offset - 1),
                          "target": hex((target + addend) & 0xffffffff), "symbol": symbol["name"]})
    return bytes(code), calls


def file_offset(image, address, length):
    _, base, sections = image
    for name, rva, virtual_size, raw_ptr, raw_size in sections:
        relative = address - base - rva
        size = min(virtual_size or raw_size, raw_size)
        if name == ".text" and 0 < length and 0 <= relative and relative + length <= size:
            return raw_ptr + relative
    raise ValueError("the whole function extent must be file-backed in PE .text")


def verified_image(image, address, code):
    offset = file_offset(image, address, len(code))
    return assemble_image(image[0], [(offset, code)]), offset


def assemble_image(original, replacements):
    result = bytearray(original)
    end = 0
    for offset, code in sorted(replacements):
        if offset < end or not code or offset + len(code) > len(original):
            raise ValueError("scratch write ranges overlap or fall outside the original PE")
        end = offset + len(code)
        result[offset:end] = code
    if result != original:
        raise ValueError("independently linked replacement differs from the original PE")
    return result


def write_outputs(outputs):
    created = []
    try:
        with ExitStack() as files:
            staged = []
            for path, data in outputs:
                stream = files.enter_context(tempfile.NamedTemporaryFile(dir=path.parent))
                stream.write(data)
                stream.flush()
                staged.append((stream.name, path))
            for temporary, path in staged:
                os.link(temporary, path)
                created.append(path)
    except BaseException:
        for path in created:
            path.unlink(missing_ok=True)
        raise


def batch_plan(audit, image, executable_sha256, compiler, priorities, limit):
    records = sorted((audit / "functions").glob("*.json"))
    if not records:
        raise ValueError(f"no audit records in {audit / 'functions'}")
    planned = {}
    excluded = []
    lengths = function_lengths()
    for path in records:
        row = json.loads(path.read_text())
        if row["executable_sha256"] != executable_sha256:
            raise ValueError(f"{path.name}: audit executable SHA-256 differs from the pinned image")
        address = int(row["address"], 0)
        reason = None
        if row.get("strict_match") is not True:
            reason = "audit was not strict"
        elif len(row["linked_sections"]) != 1:
            reason = "audit links multiple sections"
        elif lengths.get(address) != row["length"] or row["length"] is None:
            reason = "audit extent differs from contiguous inventory"
        elif not row["entry"] or not set(row["flags"]) <= CACHE_FLAGS:
            reason = "unsupported entry or compiler flags"
        if reason:
            excluded.append({"record": path.name, "address": hex(address), "reason": reason, "phase": "plan"})
            continue
        source = (ROOT / row["source"]).resolve()
        if not source.is_relative_to(ROOT) or not source.is_file() or digest(source.read_bytes()) != row["source_sha256"]:
            raise ValueError(f"{path.name}: audited source is missing, outside the checkout, or changed: {source}")
        if row["compiler"]["sha256"] != compiler or any(value is None for value in compiler.values()):
            raise ValueError(f"{path.name}: VC6 compiler inputs differ from the audit")
        if address in planned:
            excluded.append({"record": path.name, "address": hex(address), "reason": "duplicate VA", "phase": "plan"})
            continue
        length = row["length"]
        planned[address] = Recipe(address, length, file_offset(image, address, length), source,
                                  row["source_sha256"], row["entry"], tuple(row["flags"]),
                                  {k: int(v, 0) for k, v in row["symbol_overrides"].items()}, path.name)
    unavailable = [hex(address) for address in priorities if address not in planned]
    if unavailable:
        raise ValueError(f"priority addresses have no eligible audit recipe: {', '.join(unavailable)}")
    addresses = list(dict.fromkeys([*priorities, *sorted(planned)]))
    selected = [planned[address] for address in addresses[:limit]]
    for key in ("address", "file_offset"):
        end = 0
        for recipe in sorted(selected, key=lambda item: getattr(item, key)):
            start = getattr(recipe, key)
            if start < end:
                raise ValueError(f"overlapping planned {key} range at VA {recipe.address:#x}")
            end = start + recipe.length
    return selected, excluded, len(records), len(addresses) - len(selected)


def verify_recipe(recipe, vc6, scratch, original, cache_dir, cache_key, build_environment=None):
    source_bytes = recipe.source.read_bytes()
    if digest(source_bytes) != recipe.source_sha256:
        raise ValueError("source changed after planning")
    obj = scratch / f"{recipe.address:08x}.obj"
    flags = list(recipe.flags)
    cached = cache_path(cache_dir, cache_key, recipe.source, source_bytes, flags) if cache_dir else None
    if cached is not None and cached.is_symlink():
        raise ValueError(f"cache object is a symlink: {cached}")
    hit = cached is not None and cached.exists()
    if hit:
        obj.write_bytes(cached.read_bytes())
    else:
        compile_candidate(recipe.source, vc6, obj, flags,
                          environment=build_environment if cached is not None else None)
    if recipe.source.read_bytes() != source_bytes:
        raise ValueError("source changed during compilation")
    provenance = match_provenance(recipe.source, vc6, flags, recipe.symbols, True, True)
    audit = match_object(recipe.address, obj, recipe.symbols, recipe.length, recipe.entry,
                         strict=True, auto_symbols=True)
    audit.update(provenance)
    write_function_audit(audit)
    if not audit["strict_match"]:
        issues = audit["relocation_issues"] + audit["strict_issues"]
        reason = (issues[0] if issues else audit["first_difference"])
        reason = reason or f"candidate extent {audit['candidate_length']} of {recipe.length} bytes"
        raise ValueError(f"strict match failed: {reason}")
    if len(audit["linked_sections"]) != 1:
        raise UnsupportedLink("object links multiple sections")
    code, calls = link_body(obj, recipe.address, recipe.length, recipe.entry, recipe.symbols)
    end = recipe.file_offset + recipe.length
    if code != original[recipe.file_offset:end]:
        raise ValueError("independently linked replacement differs from the original PE")

    object_bytes = obj.read_bytes()
    if cached is not None and not hit:
        store_object(cached, object_bytes)
    return code, {
        "audit_record": recipe.audit_record,
        "source": {"path": str(recipe.source), "sha256": recipe.source_sha256},
        "object": {"name": obj.name, "sha256": digest(object_bytes)},
        "cache": "hit" if hit else "miss" if cached is not None else "bypass",
        "cache_key": cached.stem if cached is not None else None,
        "compiler": audit["compiler"], "flags": flags,
        "symbol_registry_sha256": audit["symbol_registry_sha256"],
        "symbol_overrides": audit["symbol_overrides"],
        "function": {"entry": recipe.entry, "start": hex(recipe.address),
                     "end_exclusive": hex(recipe.address + recipe.length), "length": recipe.length,
                     "file_offset": hex(recipe.file_offset), "file_end_exclusive": hex(end), "sha256": digest(code)},
        "relocations": audit["relocations"], "call_targets": calls,
    }


def verify_batch(recipes, jobs, vc6, scratch, original, cache_dir, cache_key, build_environment):
    def verify(recipe):
        try:
            return verify_recipe(recipe, vc6, scratch, original, cache_dir, cache_key, build_environment)
        except UnsupportedLink as error:
            return None, {"record": recipe.audit_record, "address": hex(recipe.address),
                          "reason": str(error), "phase": "link"}
        except (OSError, ValueError, struct.error, subprocess.TimeoutExpired) as error:
            raise ValueError(f"{recipe.address:#x}: {error}") from error

    # Fill the process-wide automatic symbol index before starting workers.
    resolve_auto_symbol("__except_list")
    pool = ThreadPoolExecutor(max_workers=jobs)
    try:
        return list(pool.map(verify, recipes))
    finally:
        pool.shutdown(wait=True, cancel_futures=True)


def bounded_count(value):
    count = int(value)
    if count < 1:
        raise argparse.ArgumentTypeError("must be a positive integer")
    return count


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("function_address", nargs="?", type=lambda val: int(val, 0), metavar="VA")
    parser.add_argument("source", nargs="?", type=Path)
    parser.add_argument("--length", type=lambda val: int(val, 0), help="assert the indexed full extent")
    parser.add_argument("--entry", help="exact COFF entry symbol for a single function")
    parser.add_argument("--flags")
    parser.add_argument("--symbol", action="append", default=[], metavar="NAME=0xADDRESS")
    parser.add_argument("--audit", type=Path, help="strict audit directory containing functions/*.json")
    parser.add_argument("--address", action="append", type=lambda val: int(val, 0), default=[],
                        help="prioritize an eligible audit VA (repeatable)")
    parser.add_argument("--limit", type=bounded_count, help="maximum audit recipes to compile or reuse")
    parser.add_argument("--jobs", type=int, choices=range(1, 17), default=1, metavar="N",
                        help="maximum concurrent workers, 1–16 (default: 1)")
    parser.add_argument("--cache", type=Path, help="optional local cache for self-contained COFF objects")
    parser.add_argument("--vc6", type=Path, default=DEFAULT_VC6)
    parser.add_argument("--image", type=Path, help="input PE copy identical to game/fastfood2.exe")
    parser.add_argument("--out", required=True, type=Path, help="new scratch executable")
    parser.add_argument("--manifest", type=Path, help="new JSON path (default: OUT.manifest.json)")
    args = parser.parse_args()
    if args.audit is None:
        if args.function_address is None or args.source is None or not args.entry:
            parser.error("provide VA SOURCE --entry SYMBOL or --audit DIR")
        if args.address or args.limit:
            parser.error("--address and --limit require --audit")
    elif any((args.function_address is not None, args.source, args.entry, args.length is not None,
              args.flags, args.symbol)):
        parser.error("--audit uses saved entries, lengths, compiler flags, and symbol overrides")
    try:
        out = args.out.absolute()
        manifest_path = (args.manifest or out.with_name(out.name + ".manifest.json")).absolute()
        if out.resolve() == manifest_path.resolve():
            raise ValueError("scratch executable and manifest require distinct output paths")
        for path in (out, manifest_path):
            if path.exists() or path.is_symlink():
                raise ValueError(f"output already exists: {path}")
            if not path.parent.is_dir():
                raise ValueError(f"output directory does not exist: {path.parent}")
        input_path = args.image.resolve(strict=True) if args.image is not None else GAME
        original = pe_image(GAME)
        output_digest = digest(original[0])
        if output_digest != PINNED_SHA256:
            raise ValueError("game/fastfood2.exe differs from the pinned executable SHA-256")
        image = pe_image(input_path) if input_path != GAME else original
        if image[0] != original[0]:
            raise ValueError("--image must be byte-identical to the canonical executable")

        vc6 = args.vc6.resolve()
        if args.audit:
            plans, exclusions, record_count, deferred = batch_plan(
                args.audit, image, output_digest, compiler_provenance(vc6)["sha256"], args.address, args.limit)
            if not plans:
                raise ValueError(f"no supported strict audit recipes: {dict(Counter(row['reason'] for row in exclusions))}")
            print(f"audit records={record_count} planned={len(plans)} preflight_exclusions={len(exclusions)} "
                  f"deferred={deferred} jobs={args.jobs}", flush=True)
        else:
            address = args.function_address
            length = function_lengths().get(address)
            if length is None:
                raise ValueError(f"no contiguous indexed extent at {address:#x}")
            if args.length is not None and args.length != length:
                raise ValueError(f"requested extent {args.length} differs from indexed extent {length}")
            source = args.source.resolve(strict=True)
            plan = Recipe(address, length, file_offset(image, address, length), source, digest(source.read_bytes()),
                          args.entry, tuple((args.flags or "/O2").split()), parse_symbols(args.symbol))

        cache_dir = args.cache.resolve() if args.cache is not None else None
        cache_key = build_environment = None
        if cache_dir is not None:
            cache_dir.mkdir(parents=True, exist_ok=True)
            build_environment = cache_environment()
            cache_key = cache_identity(vc6, ROOT, build_environment)
        with tempfile.TemporaryDirectory(prefix="pc2-verified-image-") as scratch:
            if args.audit:
                results = verify_batch(plans, args.jobs, vc6, Path(scratch), image[0], cache_dir, cache_key,
                                       build_environment)
                verified, replacements = [], []
                for recipe, (code, evidence) in zip(plans, results):
                    if code is None:
                        exclusions.append(evidence)
                    else:
                        verified.append(evidence)
                        replacements.append((recipe.file_offset, code))
                if not verified:
                    raise ValueError(f"none of the planned recipes could be linked: {dict(Counter(row['reason'] for row in exclusions))}")
                summary = {"audit_records": record_count, "planned": len(plans), "deferred": deferred,
                           "functions": len(verified), "union_code_bytes": sum(len(code) for _, code in replacements),
                           "excluded": dict(Counter(f"{row['phase']}: {row['reason']}" for row in exclusions)),
                           "cache": dict(Counter(row["cache"] for row in verified))}
                manifest = {"schema": "pc2.verified_linked_image_batch.v1", "audit": str(args.audit.resolve()),
                            "summary": summary, "functions": verified, "exclusions": exclusions}
            else:
                code, evidence = verify_recipe(plan, vc6, Path(scratch), image[0], cache_dir, cache_key,
                                               build_environment)
                replacements = [(plan.file_offset, code)]
                manifest = {"schema": "pc2.verified_linked_image.v1", **evidence}
            patched = assemble_image(image[0], replacements)

        if digest(GAME.read_bytes()) != output_digest:
            raise ValueError("canonical executable changed during verification")
        manifest.update({"original": {"path": str(GAME), "sha256": output_digest},
                         "input": {"path": str(input_path), "sha256": output_digest},
                         "output": {"path": str(out), "sha256": output_digest}})
        encoded = (json.dumps(manifest, indent=2) + "\n").encode()
        write_outputs([(out, patched), (manifest_path, encoded)])
    except (OSError, ValueError, TypeError, KeyError, struct.error, subprocess.TimeoutExpired) as error:
        parser.exit(1, f"linked image: {error}\n")
    if args.audit:
        print(f"verified {summary['functions']}/{summary['planned']} planned functions, {summary['union_code_bytes']} "
              f"code bytes, cache={summary['cache']}, image SHA-256 {output_digest}")
    else:
        print(f"{plan.address:#x} verified {plan.length} bytes, {len(evidence['call_targets'])} direct call fixups, "
              f"image SHA-256 {output_digest}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
