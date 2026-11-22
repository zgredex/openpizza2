"""Bounded scalar thiscall fixture plans shared by capture and replay."""

import struct


SCHEMA = "pc2.function_capture_plan.v1"
SNAPSHOT = struct.Struct("<23I")
HEADER = struct.Struct("<2I")
MAGIC = 0x32584650
MAX_TARGETS = 32
MAX_FIELDS = 8
MAX_ARGUMENTS = 4


def number(value, minimum, maximum, name):
    if isinstance(value, str):
        value = int(value, 0)
    if type(value) is not int or not minimum <= value <= maximum:
        raise ValueError(f"invalid {name}: {value!r}")
    return value


def normalize_plan(plan):
    if plan.get("schema") != SCHEMA or set(plan) != {"schema", "targets"}:
        raise ValueError("unsupported fixture plan schema")
    targets = plan["targets"]
    if not isinstance(targets, list) or not 1 <= len(targets) <= MAX_TARGETS:
        raise ValueError(f"fixture plan requires 1–{MAX_TARGETS} targets")
    indexed = {}
    for row in targets:
        if set(row) != {"address", "name", "argument_words", "return", "max_cases", "fields"}:
            raise ValueError("fixture target keys differ from the scalar thiscall contract")
        address = number(row["address"], 1, 0xFFFFFFFF, "target address")
        if address in indexed:
            raise ValueError(f"duplicate fixture target {address:#x}")
        if not isinstance(row["name"], str) or not 1 <= len(row["name"]) <= 80 or row["return"] not in {"eax", "void"}:
            raise ValueError(f"invalid fixture name or return at {address:#x}")
        arguments = number(row["argument_words"], 0, MAX_ARGUMENTS, "argument word count")
        limit = number(row["max_cases"], 1, 64, "fixture case limit")
        fields = []
        if not isinstance(row["fields"], list) or len(row["fields"]) > MAX_FIELDS:
            raise ValueError(f"fixture target requires at most {MAX_FIELDS} fields")
        occupied = set()
        for field in row["fields"]:
            if not {"offset", "size"} <= set(field) or set(field) - {"offset", "size", "writable"}:
                raise ValueError("invalid fixture field keys")
            size = number(field["size"], 1, 4, "scalar field size")
            offset = number(field["offset"], 0, 0x10000 - size, "object offset")
            writable = field.get("writable", False)
            selected = set(range(offset, offset + size))
            if size == 3 or type(writable) is not bool or occupied & selected:
                raise ValueError(f"invalid or overlapping fixture field at {offset:#x}")
            occupied.update(selected)
            fields.append({"offset": hex(offset), "size": size, "writable": writable})
        if not fields and row["return"] == "void":
            raise ValueError(f"fixture target has no observations at {address:#x}")
        indexed[address] = {"address": hex(address), "name": row["name"], "argument_words": arguments,
                            "return": row["return"], "max_cases": limit, "fields": fields}
    return {"schema": SCHEMA, "targets": [indexed[address] for address in sorted(indexed)]}


def binary_plan(plan):
    data = bytearray(HEADER.pack(MAGIC, len(plan["targets"])))
    for target in plan["targets"]:
        fields = target["fields"]
        data.extend(struct.pack("<4I", int(target["address"], 16), target["argument_words"],
                                target["max_cases"], len(fields)))
        for field in fields:
            data.extend(struct.pack("<2I", int(field["offset"], 16), field["size"]))
        data.extend(bytes((MAX_FIELDS - len(fields)) * 8))
    return data
