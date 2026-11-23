#!/usr/bin/env python3
"""Generate and strict-verify a family of VC6 C++ destructors.

The spec supplies the shared COM-style base class, one or more derived
classes with field offsets and destructor body statements, and the original
vtable/method addresses. The generator emits one source per class, compiles
and matches it with the pinned toolchain, and writes a family batch spec for
tools/run_family_batch.py.
"""

import argparse
import json
from pathlib import Path

import match_decomp as match


def parse_address(value):
    return int(value, 0)


def field_block(fields, first_offset=4):
    """Return declarations with explicit padding between requested offsets."""
    declarations = []
    cursor = first_offset
    for index, field in enumerate(fields):
        offset = int(field.get("offset", cursor))
        if offset < cursor:
            raise ValueError(f"field offset {offset:#x} overlaps at {cursor:#x}")
        if offset > cursor:
            declarations.append(f"    char pad{index}[{offset - cursor:#x}];")
        declarations.append(f"    {field['decl']}")
        cursor = offset + int(field.get("size", 4))
    return "\n".join(declarations)


def member_source(member):
    fields = field_block(member.get("fields", []), first_offset=0)
    body = "\n".join(f"    {line}" for line in member.get("body", []))
    if member.get("inline"):
        return f"""struct {member['class']} {{
{fields}
    ~{member['class']}() {{
{body}
    }}
}};"""
    return f"""struct {member['class']} {{
{fields}
    ~{member['class']}();
}};

{member['class']}::~{member['class']}()
{{
{body}
}}"""


def source_for(spec, item):
    base = spec["base"]["class"]
    body = "\n".join(f"    {line}" for line in item["body"])
    fields = field_block(item.get("fields", []))
    common = spec.get("common", "")
    members = "\n\n".join(member_source(member) for member in spec.get("members", []))
    return f"""{spec.get('prelude', '')}
{common}
{members}
struct {base} {{
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual ~{base}() {{}}
}};

struct {item['class']} : {base} {{
{fields}
    virtual ~{item['class']}();
}};

{item['class']}::~{item['class']}()
{{
{body}
}}
"""


def symbols_for(spec, item):
    base = spec["base"]
    symbols = {}
    symbols[f"??_7{base['class']}@@6B@"] = parse_address(base["vtable"])
    symbols[f"??_E{base['class']}@@UAEPAXI@Z"] = parse_address(base["deleting"])
    for index, address in enumerate(base["methods"]):
        symbols[f"?m{index}@{base['class']}@@UAEXXZ"] = parse_address(address)
    symbols[f"??_7{item['class']}@@6B@"] = parse_address(item["vtable"])
    symbols[f"??_E{item['class']}@@UAEPAXI@Z"] = parse_address(item["deleting"])
    for member in spec.get("members", []):
        if member.get("address"):
            symbols[f"??1{member['class']}@@QAE@XZ"] = parse_address(member["address"])
    return symbols


def build_one(out, item, spec, vc6, scratch):
    source = out / f"0x{parse_address(item['address']):08x}.cpp"
    source.write_text(source_for(spec, item))
    obj = scratch / f"0x{parse_address(item['address']):08x}.obj"
    flags = item.get("flags", ["/O2", "/GX", "/TP"])
    match.compile_candidate(source, vc6, obj, flags)
    entry = item.get("entry", f"??1{item['class']}@@UAE@XZ")
    symbols = symbols_for(spec, item)
    result = match.match_object(
        parse_address(item["address"]), obj, symbols,
        length=int(item["length"]), entry=entry, strict=True, auto_symbols=True)
    unwind = None
    try:
        import compare_vc6_unwind as unwind_tool
        unwind = unwind_tool.compare(parse_address(item["address"]), obj, entry, symbols)
    except (OSError, ValueError, ImportError):
        pass
    return source, result, entry, flags, unwind


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--spec", required=True, type=Path)
    parser.add_argument("--out", required=True, type=Path)
    parser.add_argument("--vc6", type=Path, default=match.DEFAULT_VC6)
    parser.add_argument("--jobs", type=int, default=1)
    args = parser.parse_args()
    try:
        spec = json.loads(args.spec.read_text())
        out = args.out.resolve()
        out.mkdir(parents=True, exist_ok=True)
        scratch = out / "objects"
        scratch.mkdir()
        recipes = []
        rows = []
        for item in spec["classes"]:
            source, result, entry, flags, unwind = build_one(out, item, spec, args.vc6.resolve(), scratch)
            rows.append({
                "address": item["address"], "class": item["class"],
                "strict_match": result["strict_match"], "match": result["match"],
                "length": result["length"], "candidate_length": result["candidate_length"],
                "difference_count": result["difference_count"],
                "first_difference": result["first_difference"],
                "strict_issues": result["strict_issues"],
                "relocation_issues": result["relocation_issues"],
                "unwind": None if unwind is None else {
                    "original_states": len(unwind["original"]["states"]),
                    "candidate_states": len(unwind["candidate"]["states"]),
                    "differences": unwind["difference_counts"],
                },
            })
            try:
                source_path = str(source.relative_to(match.ROOT))
            except ValueError:
                source_path = str(source)
            recipes.append({
                "address": item["address"], "name": item["class"],
                "length": item["length"], "entry": entry,
                "source": source_path, "flags": flags,
                "symbols": {name: hex(address) for name, address in symbols_for(spec, item).items()},
            })
        family = {"schema": "pc2.family_batch.v1", "family": spec.get("family", "destructors"),
                  "recipes": recipes}
        (out / "family.json").write_text(json.dumps(family, indent=2) + "\n")
        report = {"schema": "pc2.destructor_family.v1", "family": spec.get("family", "destructors"),
                  "classes": rows}
        (out / "report.json").write_text(json.dumps(report, indent=2) + "\n")
        strict = sum(row["strict_match"] for row in rows)
        print(f"{strict}/{len(rows)} strict destructors")
        for row in rows:
            detail = "strict" if row["strict_match"] else f"diff {row['difference_count']}"
            print(f"  {row['address']} {row['length']:>4} {row['class']}: {detail}")
        return 0 if strict == len(rows) else 1
    except (OSError, ValueError, KeyError, TypeError) as error:
        parser.exit(2, f"destructor family: {error}\n")


if __name__ == "__main__":
    raise SystemExit(main())
