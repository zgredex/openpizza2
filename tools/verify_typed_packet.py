#!/usr/bin/env python3
"""Reproduce and cross-check typed function packets.

For every `typed_packets/*.expectations.json` this tool:

1. regenerates the JSON and Markdown from the checked-in annotations,
2. compares the regenerated files byte-for-byte,
3. checks the target executable hash,
4. decodes expected dispatch tables from the PE image,
5. checks structured signatures and field-to-instruction links,
6. checks ordered trace instruction prefixes and cash fixtures,
7. mutates signatures, tables, dispatch targets and trace bytes to prove the
   verifier rejects the changes.
"""

from __future__ import annotations

import argparse
import copy
import glob
import hashlib
import json
import os
import struct
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BASE = os.path.join(ROOT, "decompiled_fastfood2_named_v2", "typed_packets")
TARGET = os.path.join(ROOT, "game", "fastfood2.exe")
EXPECTED_SHA256 = (
    "18cfd32e0ac5d6d98162ec016e058a2b51808d9ca49ebee933ce3166ff9922fd"
)


def sha256_file(path):
    digest = hashlib.sha256()
    with open(path, "rb") as fh:
        for chunk in iter(lambda: fh.read(1 << 20), b""):
            digest.update(chunk)
    return digest.hexdigest()


def pe_sections(path):
    with open(path, "rb") as fh:
        data = fh.read()
    pe_offset = struct.unpack_from("<I", data, 0x3C)[0]
    section_count = struct.unpack_from("<H", data, pe_offset + 6)[0]
    optional_size = struct.unpack_from("<H", data, pe_offset + 20)[0]
    image_base = struct.unpack_from("<I", data, pe_offset + 24 + 28)[0]
    section_table = pe_offset + 24 + optional_size
    sections = []
    for index in range(section_count):
        offset = section_table + index * 40
        virtual_size, virtual_address = struct.unpack_from("<II", data, offset + 8)
        raw_size, raw_pointer = struct.unpack_from("<II", data, offset + 16)
        sections.append(
            (image_base + virtual_address, virtual_size, raw_pointer, raw_size))
    return data, sections


def read_va(data, sections, address, length):
    for virtual_address, virtual_size, raw_pointer, raw_size in sections:
        span = max(virtual_size, raw_size)
        if virtual_address <= address < virtual_address + span:
            offset = raw_pointer + (address - virtual_address)
            chunk = data[offset:offset + length]
            if len(chunk) != length:
                return None
            return chunk
    return None


def block_from_va(data, sections, address):
    for virtual_address, virtual_size, raw_pointer, raw_size in sections:
        span = max(virtual_size, raw_size)
        if virtual_address <= address < virtual_address + span:
            offset = raw_pointer + (address - virtual_address)
            return data[offset:offset + (virtual_address + span - address)]
    return None


def address_set(packet):
    addresses = set()

    def add(value):
        if isinstance(value, str) and value.startswith("0x"):
            addresses.add(value.lower())
        elif isinstance(value, dict):
            for nested in value.values():
                add(nested)
        elif isinstance(value, list):
            for nested in value:
                add(nested)

    for record in packet.get("records", {}).values():
        for field in record.get("fields", []):
            add(field.get("instruction"))
        for item in record.get("dispatch", []):
            add(item.get("instruction"))
        for item in record.get("event_order", []):
            add(item.get("address"))
    for step in packet.get("trace", []):
        add(step.get("address"))
    return addresses


def validate_packet(packet, expectations, data, sections):
    errors = []
    if packet.get("schema") != "pc2.function_batch.v1":
        errors.append("unexpected schema")
    if packet.get("target", {}).get("sha256") != EXPECTED_SHA256:
        errors.append("target sha256 mismatch")
    records = packet.get("records", {})
    missing = sorted(set(expectations["required_records"]) - set(records))
    if missing:
        errors.append(f"missing records: {missing}")
    for address, record in records.items():
        if record.get("packet_key") != f"{EXPECTED_SHA256}:{address}":
            errors.append(f"{address} has a bad packet_key")
        signature = record.get("signature")
        if not isinstance(signature, dict):
            errors.append(f"{address} signature is not structured")
        else:
            for key in ("recovered", "confidence"):
                if not signature.get(key):
                    errors.append(f"{address} signature lacks {key}")
            expected_signature = expectations["expected_signatures"].get(address)
            if expected_signature is None:
                errors.append(f"{address} has no expected signature")
            elif signature.get("recovered") != expected_signature:
                errors.append(
                    f"{address} signature mismatch: "
                    f"{signature.get('recovered')!r} != {expected_signature!r}")

    trace = packet.get("trace", [])
    if len(trace) < expectations.get("min_trace_steps", 0):
        errors.append("trace is shorter than expected")
    trace_names = {step.get("name") for step in trace}
    for name, address in expectations["required_trace"].items():
        if name not in trace_names:
            errors.append(f"missing trace step {name}")
    by_name = {step.get("name"): step for step in trace}
    for name, address in expectations["required_trace"].items():
        if name in by_name and by_name[name].get("address") != address:
            errors.append(f"{name} address changed")
    for index, step in enumerate(trace, 1):
        if step.get("step") != index:
            errors.append(f"trace order mismatch at {step.get('name')}")
        raw = step.get("bytes")
        address = step.get("address")
        if not raw or not address:
            errors.append(f"trace step missing bytes/address: {step.get('name')}")
            continue
        expected = bytes.fromhex(raw)
        actual = read_va(data, sections, int(address, 16), len(expected))
        if actual != expected:
            errors.append(
                f"{step.get('name')} bytes mismatch at {address}: "
                f"{expected.hex()} != {actual.hex() if actual else 'unmapped'}")

    tables = {table.get("id"): table for table in packet.get("tables", [])}
    expected_tables = expectations["expected_tables"]
    if set(tables) != set(expected_tables):
        errors.append(
            f"table set mismatch: {sorted(tables)} != {sorted(expected_tables)}")
    for table_id, expected in expected_tables.items():
        table = tables.get(table_id)
        if table is None:
            continue
        for key in ("address", "width", "count"):
            if table.get(key) != expected.get(key):
                errors.append(f"table {table_id} {key} changed")
        if table.get("entries") != expected.get("entries"):
            errors.append(f"table {table_id} entries changed")
        raw = table.get("bytes", "")
        expected_length = expected["width"] * expected["count"]
        if len(raw) != expected_length * 2:
            errors.append(f"table {table_id} byte length mismatch")
            continue
        decoded = {}
        width = expected["width"]
        for index in range(expected["count"]):
            chunk = bytes.fromhex(raw[index * width * 2:(index + 1) * width * 2])
            decoded[str(index)] = hex(int.from_bytes(chunk, "little"))
        expected_indices = list(expected["entries"])
        key_kind = "hex" if all(key.startswith("0x") for key in expected_indices) else "index"
        if key_kind == "index":
            if set(decoded) != set(expected_indices):
                errors.append(f"table {table_id} index set mismatch")
            for index, expected_target in expected["entries"].items():
                if decoded.get(index) != expected_target:
                    errors.append(f"table {table_id}[{index}] target changed")
        else:
            base = min(int(index, 16) for index in expected_indices)
            for index, expected_target in expected["entries"].items():
                slot = int(index, 16) - base
                if slot < 0 or slot >= expected["count"]:
                    errors.append(f"table {table_id} entry {index} out of range")
                    continue
                chunk = bytes.fromhex(
                    raw[slot * width * 2:(slot + 1) * width * 2])
                decoded_target = hex(int.from_bytes(chunk, "little"))
                if decoded_target != expected_target:
                    errors.append(f"table {table_id}[{index}] target changed")
        byte_target = read_va(data, sections, int(expected["address"], 16),
                             len(bytes.fromhex(raw)))
        if byte_target != bytes.fromhex(raw):
            errors.append(f"table {table_id} bytes differ from executable")

    fixtures = packet.get("fixtures", [])
    expected_fixtures = expectations.get("expected_fixtures", [])
    if len(fixtures) != len(expected_fixtures):
        errors.append("fixture count mismatch")
    for fixture, expected in zip(fixtures, expected_fixtures):
        if fixture.get("id") != expected.get("id"):
            errors.append(f"fixture id mismatch: {fixture.get('id')}")
        if "base_capital" in fixture:
            calculated = (
                fixture.get("base_capital", 0)
                * fixture.get("ownership_percent", 0) // 100)
            if calculated != fixture.get("expected_capital"):
                errors.append(f"fixture {fixture.get('id')} arithmetic mismatch")
        if fixture != expected:
            errors.append(f"fixture {fixture.get('id')} changed")

    if "expected_controls" in expectations and packet.get("controls") != expectations.get("expected_controls"):
        errors.append("control semantics changed")
    if "expected_imports" in expectations and packet.get("imports") != expectations.get("expected_imports"):
        errors.append("import identities changed")

    mentioned = address_set(packet)
    for address, record in records.items():
        for field in record.get("fields", []):
            for key in ("name", "direction", "instruction", "role"):
                if not field.get(key):
                    errors.append(f"{address} field lacks {key}")
            if field.get("direction") not in {"read", "write", "read-write"}:
                errors.append(f"{address} field has bad direction")
            if field.get("instruction") not in mentioned:
                errors.append(
                    f"{address} field {field.get('name')} instruction "
                    f"{field.get('instruction')} is not linked to an event")
    for address, fields in expectations.get("expected_field_instructions", {}).items():
        record = records.get(address, {})
        actual = {
            field.get("name"): field.get("instruction")
            for field in record.get("fields", [])
        }
        for name, instruction in fields.items():
            if actual.get(name) != instruction:
                errors.append(
                    f"{address} field {name} instruction "
                    f"{actual.get(name)} != {instruction}")

    for address, targets in expectations.get("expected_dispatch_targets", {}).items():
        record = records.get(address, {})
        seen = set()
        for item in record.get("dispatch", []):
            value = item.get("targets", {})
            if isinstance(value, dict):
                seen.update(value.values())
            elif isinstance(value, list):
                seen.update(value)
        for target in targets:
            if target not in seen:
                errors.append(f"{address} dispatch target {target} missing")
    return errors


def regenerate(expectations, directory):
    packet_path = os.path.join(BASE, expectations["packet"])
    markdown_path = os.path.join(BASE, expectations["markdown"])
    annotations = os.path.join(BASE, expectations["annotations"])
    generated_json = os.path.join(directory, "packet.json")
    generated_md = os.path.join(directory, "packet.md")
    command = [
        sys.executable, os.path.join(ROOT, "tools", "function_batch.py"),
        *expectations["addresses"],
        "--annotations", annotations,
        "--json-out", generated_json,
        "--out", generated_md,
    ]
    result = subprocess.run(
        command, cwd=ROOT, text=True, capture_output=True, timeout=300)
    if result.returncode != 0:
        return None, [f"regeneration failed: {result.stderr[-800:]}"]
    errors = []
    if sha256_file(generated_json) != sha256_file(packet_path):
        errors.append(f"{expectations['packet']} is not reproducible")
    if sha256_file(generated_md) != sha256_file(markdown_path):
        errors.append(f"{expectations['markdown']} is not reproducible")
    return json.load(open(generated_json)), errors


def mutation_checks(packet, expectations, data, sections):
    mutations = []
    mutated = copy.deepcopy(packet)
    first_record = next(iter(mutated["records"]))
    mutated["records"][first_record]["signature"]["recovered"] = "void wrong(void)"
    mutations.append(("changed signature", mutated))

    table_ids = list(expectations.get("expected_tables", {}))
    for table_id in table_ids[:2]:
        mutated = copy.deepcopy(packet)
        mutated["tables"] = [t for t in mutated["tables"] if t["id"] != table_id]
        mutations.append((f"missing table {table_id}", mutated))
    if table_ids:
        table_id = table_ids[0]
        mutated = copy.deepcopy(packet)
        for table in mutated["tables"]:
            if table["id"] == table_id:
                first_entry = next(iter(table["entries"]))
                table["entries"][first_entry] = "0x405463"
        mutations.append((f"changed table {table_id} target", mutated))

    for address, targets in expectations.get("expected_dispatch_targets", {}).items():
        if not targets:
            continue
        mutated = copy.deepcopy(packet)
        for item in mutated["records"].get(address, {}).get("dispatch", []):
            if isinstance(item.get("targets"), dict):
                first_key = next(iter(item["targets"]))
                item["targets"][first_key] = "0x405463"
            elif isinstance(item.get("targets"), list) and item["targets"]:
                item["targets"][0] = "0x405463"
        mutations.append((f"changed dispatch target {address}", mutated))
        break

    required_trace = list(expectations.get("required_trace", {}))
    if required_trace:
        mutated = copy.deepcopy(packet)
        remove_name = required_trace[-1]
        mutated["trace"] = [s for s in mutated["trace"] if s["name"] != remove_name]
        mutations.append((f"missing trace step {remove_name}", mutated))
    mutated = copy.deepcopy(packet)
    if mutated["trace"]:
        first = mutated["trace"][0]
        first["bytes"] = "00" * (len(first["bytes"]) // 2)
        mutations.append(("changed instruction bytes", mutated))
    if packet.get("controls"):
        mutated = copy.deepcopy(packet)
        first_control = next(iter(mutated["controls"]))
        if isinstance(mutated["controls"][first_control], dict):
            mutated["controls"][first_control]["family"] = "changed"
        mutations.append(("changed control semantics", mutated))
    if packet.get("imports"):
        mutated = copy.deepcopy(packet)
        first_import = next(iter(mutated["imports"]))
        mutated["imports"][first_import]["name"] = "ChangedImport"
        mutations.append(("changed import identity", mutated))

    rejected = 0
    for name, candidate in mutations:
        errors = validate_packet(candidate, expectations, data, sections)
        if errors:
            rejected += 1
        else:
            print(f"mutation accepted but should fail: {name}")
    return rejected, len(mutations)


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--expectations")
    args = parser.parse_args()
    paths = ([args.expectations] if args.expectations else
             sorted(glob.glob(os.path.join(BASE, "*.expectations.json"))))
    if not paths:
        print("typed packet: no expectations found")
        return 1
    data, sections = pe_sections(TARGET)
    if sha256_file(TARGET) != EXPECTED_SHA256:
        print("typed packet: executable sha256 mismatch")
        return 1
    total_records = 0
    total_steps = 0
    total_tables = 0
    total_fixtures = 0
    total_checked = 0
    total_mutations = 0
    rejected = 0
    for path in paths:
        expectations = json.load(open(path))
        with tempfile.TemporaryDirectory() as directory:
            packet, errors = regenerate(expectations, directory)
        mutation_count = 0
        mutation_rejected = 0
        if packet is not None:
            errors.extend(validate_packet(packet, expectations, data, sections))
            mutation_rejected, mutation_count = mutation_checks(
                packet, expectations, data, sections)
            if mutation_rejected != mutation_count:
                errors.append("one or more verifier mutations were accepted")
        if errors:
            print(f"typed packet {expectations['packet']}: FAILED")
            for error in errors:
                print(f"  - {error}")
            return 1
        total_records += len(packet["records"])
        total_steps += len(packet["trace"])
        total_tables += len(packet.get("tables", []))
        total_fixtures += len(packet.get("fixtures", []))
        total_checked += len(packet["trace"])
        total_mutations += mutation_count
        rejected += mutation_rejected
    print(
        f"typed packets: {len(paths)} packet(s), {total_records} records, "
        f"{total_steps} trace steps, {total_tables} tables, "
        f"{total_fixtures} fixtures, {total_checked}/{total_checked} "
        f"instruction prefixes match, {rejected}/{total_mutations} "
        f"mutations rejected")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
