#!/usr/bin/env python3
"""Replay and inspect a scenario against the lifted Pizza Connection 2 host."""

import argparse
from collections import Counter, defaultdict
import fcntl
import hashlib
import json
import math
import os
from pathlib import Path
import re
import struct
import subprocess
import sys


HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
EXPORT = ROOT / "decompiled_fastfood2_named_v2"
DEFAULT_WORK = Path(os.environ.get("PC2_WORK", "/tmp/opencode/pcrecomp-pc2"))
GUEST_SHA256 = "18cfd32e0ac5d6d98162ec016e058a2b51808d9ca49ebee933ce3166ff9922fd"
FORMAT = "pc2.capture.v1"
EVENT = struct.Struct("<11I")
OP = dict(zip(("begin", "end", "snapshot", "wait_function", "wait_value", "delay_ms",
               "mouse", "key", "wheel", "assert_value", "post", "click"), range(1, 13)))
ENTRY, EDGE, MESSAGE, STEP, WATCH, FINISH, LIMIT = range(1, 8)
EVENTS = {ENTRY: "entry", EDGE: "edge", MESSAGE: "message", STEP: "step",
          WATCH: "watch", FINISH: "finish", LIMIT: "limit"}
EDGE_KINDS = {1: "direct", 2: "indirect", 3: "tail", 4: "return_jump", 5: "host_call"}
RESULTS = {0: "no_dispatch", 1: "resolved", 2: "return_sentinel"}
FINISH_REASONS = {1: "completed", 2: "assertion_failed", 3: "guest_exit"}
REGISTER_NAMES = ("eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi")
TYPES = {"u8": "B", "i8": "b", "u16": "H", "i16": "h", "u32": "I", "i32": "i",
         "u64": "Q", "i64": "q", "f32": "f", "f64": "d"}
MOUSE = {"move": 0x200, "down": 0x201, "up": 0x202, "right_down": 0x204,
         "right_up": 0x205, "middle_down": 0x207, "middle_up": 0x208}
MASK = 0xffffffff


def read_json(path):
    return json.loads(path.read_text(encoding="utf-8"))


def write_json(path, value):
    with path.open("w", encoding="utf-8") as output:
        json.dump(value, output, indent=2, ensure_ascii=False, allow_nan=False)
        output.write("\n")


def address(value):
    return f"0x{value:08X}" if value else None


def integer(value, field, low=0, high=MASK):
    if isinstance(value, str):
        try:
            value = int(value, 0)
        except ValueError:
            raise ValueError(f"{field} must be an integer") from None
    if type(value) is not int or not low <= value <= high:
        raise ValueError(f"{field} must be an integer from {low} to {high}")
    return value


def label(value, field):
    if not isinstance(value, str) or not value.strip():
        raise ValueError(f"{field} must be a nonempty string")
    return value


def check_keys(data, required, optional=()):
    if not isinstance(data, dict) or not set(required) <= data.keys() or data.keys() - set(required) - set(optional):
        raise ValueError(f"expected fields {', '.join(required)} (optional: {', '.join(optional)})")


def symbols():
    result = {}
    for name in ("full_game_symbols.json", "all_symbols_with_vtables.json"):
        for key, symbol in read_json(EXPORT / name).items():
            if re.fullmatch(r"0x[\da-f]+", key, re.I):
                result[int(key, 16)] = symbol
    return result


def named_address(value, names):
    if isinstance(value, str):
        matches = [va for va, name in names.items() if value == name]
        if len(matches) == 1:
            return matches[0]
        if matches:
            raise ValueError(f"ambiguous symbol {value!r}; use its guest address")
    return integer(value, "address", 1)


def bits_for(value, kind):
    form = TYPES[kind]
    size = struct.calcsize("<" + form)
    if kind.startswith("f"):
        if type(value) not in (int, float) or not math.isfinite(value):
            raise ValueError("floating-point expectations must be finite numbers")
    else:
        signed = kind.startswith("i")
        maximum = 1 << (8 * size - signed)
        value = integer(value, "watch expectation", -maximum if signed else 0, maximum - 1)
    return int.from_bytes(struct.pack("<" + form, value), "little")


def compile_plan(scenario, limit, names):
    check_keys(scenario, ("name", "steps"), ("watches", "env"))
    label(scenario["name"], "scenario name")
    watch_data = scenario.get("watches", {})
    if not isinstance(watch_data, dict) or len(watch_data) > 1024:
        raise ValueError("watches must be an object with up to 1,024 entries")
    commands = scenario["steps"]
    if not isinstance(commands, list) or not 1 <= len(commands) <= 10000:
        raise ValueError("steps must be an array with 1 to 10,000 entries")
    env = scenario.get("env", {})
    if not isinstance(env, dict) or any(
        not re.fullmatch(r"PC2_[A-Z0-9_]+", key) or key.startswith("PC2_CAPTURE_")
        or key in {"PC2_HEADLESS", "PC2_CDRIVE"} or not isinstance(value, str) or "\0" in value
        for key, value in env.items()
    ):
        raise ValueError("env must contain string values for game-specific PC2_* options")

    data = bytearray(struct.pack("<5I", 0x54324350, 1, len(commands), len(watch_data), limit))
    watch_indices = {key: i for i, key in enumerate(watch_data)}
    for key, watch in watch_data.items():
        label(key, "watch name")
        check_keys(watch, ("address", "type"), ("offsets",))
        kind = watch["type"]
        offsets = watch.get("offsets", [])
        if not isinstance(kind, str) or kind not in TYPES or not isinstance(offsets, list) or len(offsets) > 6:
            raise ValueError(f"invalid type or pointer offsets for watch {key!r}")
        offsets = [integer(offset, "pointer offset", -(1 << 31)) & MASK for offset in offsets]
        data.extend(struct.pack("<9I", named_address(watch["address"], names),
                                struct.calcsize("<" + TYPES[kind]), len(offsets),
                                *(offsets + [0] * (6 - len(offsets)))))

    active = None
    phases = set()
    for index, step in enumerate(commands):
        try:
            if not isinstance(step, dict) or len(step) != 1:
                raise ValueError("expected one command")
            command, value = next(iter(step.items()))
            a = b = c = 0
            if command == "begin":
                if active or label(value, command) in phases:
                    raise ValueError("phase names must be unique and phases cannot overlap")
                active = value
                phases.add(value)
            elif command == "end":
                if not active or value != active:
                    raise ValueError(f"end must name the open phase ({active!r})")
                active = None
            elif command == "snapshot":
                label(value, command)
            elif command == "wait_function":
                if not isinstance(value, dict):
                    value = {"address": value}
                check_keys(value, ("address",), ("count",))
                a = named_address(value["address"], names)
                b = integer(value.get("count", 1), "function count", 1)
            elif command in ("wait_value", "assert_value"):
                check_keys(value, ("watch", "equals"))
                key = label(value["watch"], "watch name")
                if key not in watch_indices:
                    raise ValueError(f"unknown watch {key!r}")
                bits = bits_for(value["equals"], watch_data[key]["type"])
                a, b, c = watch_indices[key], bits & MASK, bits >> 32
            elif command == "delay_ms":
                a = integer(value, command, high=(1 << 31) - 1)
            elif command == "mouse":
                check_keys(value, ("action", "x", "y"))
                action = label(value["action"], "mouse action")
                if action not in MOUSE:
                    raise ValueError(f"unknown mouse action {action!r}")
                a = MOUSE[action]
                b = integer(value["x"], "x", -32768, 32767) & MASK
                c = integer(value["y"], "y", -32768, 32767) & MASK
            elif command == "key":
                check_keys(value, ("action", "vk"), ("scan",))
                if value["action"] not in ("down", "up"):
                    raise ValueError("key action must be down or up")
                a = int(value["action"] == "down")
                b = integer(value["vk"], "virtual key", high=255)
                c = integer(value.get("scan", 0), "scan code", high=255)
            elif command == "wheel":
                a = integer(value, command, -32768, 32767) & MASK
            elif command == "post":
                check_keys(value, ("message",), ("wparam", "lparam"))
                a = integer(value["message"], "message", 1)
                b = integer(value.get("wparam", 0), "wparam")
                c = integer(value.get("lparam", 0), "lparam")
            elif command == "click":
                check_keys(value, ("x", "y"))
                a = integer(value["x"], "x", -32768, 32767) & MASK
                b = integer(value["y"], "y", -32768, 32767) & MASK
            else:
                raise ValueError(f"unknown command {command!r}")
            data.extend(struct.pack("<4I", OP[command], a, b, c))
        except (ValueError, OverflowError) as error:
            raise ValueError(f"step {index + 1}: {error}") from None
    if active or not phases:
        raise ValueError("the scenario needs at least one phase and each phase needs an end")
    return data


def catalog(work, names):
    generated = work / "gen"
    entries = {
        int(va, 16): {"address": address(int(va, 16)), "symbol": names.get(int(va, 16), fn),
                      "lifted_symbol": fn}
        for va, fn in re.findall(r"\{ (0x[0-9A-F]{8})u, (\w+) \}",
                                 (generated / "recomp_dispatch.c").read_text())
    }
    declarations = re.compile(r"^void (sub_([0-9A-Fa-f]{8}))\(void\) \{")
    for source in sorted(generated.glob("recomp_[0-9]*.c")):
        with source.open(encoding="utf-8") as file:
            for line, text in enumerate(file, 1):
                if text.startswith("void ") and (match := declarations.match(text)):
                    va = int(match[2], 16)
                    if va in entries:
                        entries[va]["lifted_source"] = {"path": str(source), "line": line}
    for va, entry in entries.items():
        decompiled = EXPORT / "full_game_verification" / "functions" / f"{va:#x}.c"
        if decompiled.is_file():
            entry["decompiled_source"] = str(decompiled)
    return entries


def registered_imports(directory):
    path = directory / "imports.tsv"
    if not path.is_file():
        return {}
    return {int(va, 16): name for va, name in (
        line.split("\t", 1) for line in path.read_text().splitlines() if "\t" in line
    )}


def read_events(directory):
    path = directory / "events.bin"
    if not path.is_file():
        return
    with path.open("rb") as file:
        remaining = os.fstat(file.fileno()).st_size // EVENT.size
        while remaining:
            chunk = min(remaining, 4096)
            yield from EVENT.iter_unpack(file.read(EVENT.size * chunk))
            remaining -= chunk


def watch_value(watches, index, lo, hi, readable, resolved):
    name, spec = watches[index]
    value = None
    if readable:
        bits = (hi << 32) | lo
        form = "<" + TYPES[spec["type"]]
        value = struct.unpack(form, bits.to_bytes(8, "little")[:struct.calcsize(form)])[0]
        if isinstance(value, float) and not math.isfinite(value):
            value = str(value)
    result = {"name": name, "type": spec["type"], "address": address(resolved), "value": value,
              "readable": bool(readable)}
    if readable:
        result["bits"] = f"0x{bits:0{struct.calcsize(form) * 2}X}"
    return result


def symbol(va, names, imports):
    return imports.get(va, names.get(va))


def describe_edge(key, names, imports):
    caller, site, target, kind, resolved, origin, nargs = key
    result = {"caller": address(caller), "caller_symbol": symbol(caller, names, imports),
              "site": address(site), "target": address(target), "target_symbol": symbol(target, names, imports),
              "kind": EDGE_KINDS[kind], "resolution": RESULTS[resolved]}
    if target in imports:
        result["target_kind"] = "hle_import"
    if origin:
        result["active_hle_import"] = {"address": address(origin), "name": imports.get(origin)}
    if kind == 5:
        result["argc"] = nargs
    return result


def describe_message(key):
    hwnd, msg, wp, lp, caller = key
    return {"hwnd": address(hwnd), "message": f"0x{msg:04X}", "wparam": wp,
            "lparam": lp, "caller": address(caller)}


def counted(records, describe):
    return [dict(describe(key), count=sum(threads.values()),
                 threads=dict(sorted(threads.items()))) for key, threads in sorted(records.items())]


def make_report(directory):
    scenario = read_json(directory / "scenario.json")
    run = read_json(directory / "run.json")
    names = symbols()
    work = Path(run["work"])
    entries = catalog(work, names) if (work / "gen" / "recomp_dispatch.c").is_file() else {}
    imports = registered_imports(directory)
    watches = list(scenario.get("watches", {}).items())
    phases = []
    steps = {}
    finish = None
    limit_hit = False
    phase = None
    for op, thread, *p in read_events(directory):
        a, b, c, d, e, f, g, _, _ = p
        if op == STEP:
            command, value = next(iter(scenario["steps"][a].items()))
            steps[a] = {"step": a + 1, "command": command, "value": value, "time_ms": b,
                        "thread": thread}
            if command == "begin":
                phase = {"name": value, "begin_step": a + 1, "end_step": None,
                         "functions": defaultdict(Counter), "edges": defaultdict(Counter),
                         "messages": defaultdict(Counter)}
                phases.append(phase)
            if phase is not None:
                steps[a]["phase"] = phase["name"]
                if command == "end":
                    phase["end_step"] = a + 1
                    phase = None
        elif op == WATCH:
            steps[a].setdefault("watches", []).append(watch_value(watches, b, c, d, e, f))
        elif op == FINISH:
            finish = {"reason": FINISH_REASONS[a], "status": b, "steps_completed": c}
        elif op == LIMIT:
            limit_hit = True
        elif phase is not None and op == ENTRY:
            phase["functions"][a][thread] += 1
        elif phase is not None and op == EDGE:
            phase["edges"][(a, b, c, d, e, f, g)][thread] += 1
        elif phase is not None and op == MESSAGE:
            phase["messages"][(a, b, c, d, e)][thread] += 1
    size = (directory / "events.bin").stat().st_size if (directory / "events.bin").exists() else 0
    replay_completed = bool(finish and finish["reason"] == "completed" and run["exit_status"] == 0)
    complete = replay_completed and not limit_hit and size % EVENT.size == 0
    for phase in phases:
        phase["functions"] = counted(phase["functions"], lambda va: entries.get(
            va, {"address": address(va), "symbol": symbol(va, names, imports)}))
        phase["edges"] = counted(phase["edges"], lambda key: describe_edge(key, names, imports))
        phase["messages"] = counted(phase["messages"], describe_message)
        phase["unresolved_edges"] = sum(edge["resolution"] == "no_dispatch" for edge in phase["edges"])
    return {"format": FORMAT, "scenario": scenario["name"], "complete": complete,
            "replay_completed": replay_completed, "finish": finish, "run": run,
            "records": size // EVENT.size, "partial_record_bytes": size % EVENT.size,
            "event_limit_reached": limit_hit, "phases": phases, "steps": list(steps.values())}


def linked_addresses(manifest, guest_hash):
    if manifest["output"]["sha256"] != guest_hash:
        raise ValueError("linked manifest image SHA-256 differs from the captured image")
    if manifest["schema"] == "pc2.verified_linked_image_batch.v1":
        functions = manifest["functions"]
    elif manifest["schema"] == "pc2.verified_linked_image.v1":
        functions = [manifest]
    else:
        raise ValueError("unsupported linked image manifest schema")
    linked = {int(item["function"]["start"], 0) for item in functions}
    if len(linked) != len(functions):
        raise ValueError("linked image manifest contains duplicate addresses")
    return linked


def linked_reachability(report, manifest):
    linked = linked_addresses(manifest, report["run"]["guest_sha256"])
    reached = defaultdict(Counter)
    for phase in report["phases"]:
        for item in phase["functions"]:
            va = int(item["address"], 0)
            if va in linked:
                reached[va][phase["name"]] += item["count"]
    return {"scenario_complete": report["complete"], "linked": len(linked),
            "reached": [{"address": address(va), "entries": sum(counts.values()), "phases": dict(counts)}
                        for va, counts in sorted(reached.items())],
            "not_seen": [address(va) for va in sorted(linked - reached.keys())]}


def save_report(directory, linked_manifest=None):
    report = make_report(directory)
    if linked_manifest is not None:
        reachability = linked_reachability(report, read_json(linked_manifest))
        report["linked_reachability"] = {"manifest": str(linked_manifest.resolve()), **reachability}
        print(f"linked reachability: {len(reachability['reached'])}/{reachability['linked']}")
    write_json(directory / "report.json", report)
    for phase in report["phases"]:
        print(f"{phase['name']}: {len(phase['functions'])} lifted entries, "
              f"{len(phase['edges'])} edge records, {phase['unresolved_edges']} unresolved")
    status = "complete" if report["complete"] else "partial"
    if not report["complete"]:
        finish = report["finish"] or {}
        print(f"exit={report['run']['exit_status']} finish={finish.get('reason')} "
              f"event_limit_reached={report['event_limit_reached']}", file=sys.stderr)
        if not report["replay_completed"]:
            next_step = (finish["steps_completed"] + 1 if "steps_completed" in finish
                         else len(report["steps"]) + 1)
            print(f"stopped near step {next_step}; see {directory / 'host.log'}", file=sys.stderr)
    print(f"{status}: {directory / 'report.json'}")
    return 0 if report["complete"] else 1


def capture_image(requested):
    original = ROOT / "game" / "fastfood2.exe"
    image = requested.absolute() if requested is not None else original
    with image.open("rb") as stream:
        guest_hash = hashlib.file_digest(stream, "sha256").hexdigest()
    if requested is not None:
        with original.open("rb") as stream:
            original_hash = hashlib.file_digest(stream, "sha256").hexdigest()
        if original_hash != GUEST_SHA256:
            raise ValueError(f"canonical image SHA-256 {original_hash} differs from the lift's pinned image")
        if guest_hash != original_hash:
            raise ValueError(f"--image SHA-256 {guest_hash} differs from the canonical image {original_hash}")
    return image, guest_hash


def run_capture(args):
    work = args.work.resolve()
    directory = args.out.resolve()
    scenario = read_json(args.scenario)
    plan = compile_plan(scenario, args.max_events, symbols())
    if not math.isfinite(args.timeout) or args.timeout <= 0:
        raise ValueError("timeout must be positive and finite")
    image, guest_hash = capture_image(args.image)
    if args.linked_manifest is not None:
        linked_addresses(read_json(args.linked_manifest), guest_hash)
    directory.mkdir(parents=True)
    write_json(directory / "scenario.json", scenario)
    (directory / "plan.bin").write_bytes(plan)
    host = work / "pc2-capture" / "pc2"
    if not args.skip_build:
        work.mkdir(parents=True, exist_ok=True)
        with (work / "capture-build.lock").open("w") as lock:
            fcntl.flock(lock, fcntl.LOCK_EX)
            subprocess.run([str(HERE / "build.sh")], cwd=ROOT, check=True, env={
                **os.environ, "PC2_WORK": str(work), "PC2_CAPTURE_BUILD": "1", "PC2_BUILD_ONLY": "1",
            })
    with host.open("rb") as executable:
        host_hash = hashlib.file_digest(executable, "sha256").hexdigest()
    # Only the scenario may opt into the legacy PC2 input scripts.
    env = {key: val for key, val in os.environ.items() if not key.startswith("PC2_")}
    env.update(scenario.get("env", {}))
    lib = str(work / "sysroot32" / "lib")
    if env.get("LD_LIBRARY_PATH"):
        lib += ":" + env["LD_LIBRARY_PATH"]
    env.update(LD_LIBRARY_PATH=lib, SDL_VIDEODRIVER="dummy", SDL_AUDIODRIVER="dummy",
               PC2_HEADLESS="1", PC2_CDRIVE=str(directory / "cdrive"),
               PC2_CAPTURE_PLAN=str(directory / "plan.bin"),
               PC2_CAPTURE_EVENTS=str(directory / "events.bin"),
               PC2_CAPTURE_IMPORTS=str(directory / "imports.tsv"))
    fixture_path = directory / "function-fixtures.bin"
    if args.function_fixtures:
        env["PC2_CAPTURE_FUNCTION_FIXTURES"] = str(fixture_path)
    with (directory / "host.log").open("wb") as log:
        try:
            status = subprocess.run([str(host), image.name], cwd=image.parent, env=env,
                                    stdout=log, stderr=subprocess.STDOUT, timeout=args.timeout).returncode
            timed_out = False
        except subprocess.TimeoutExpired:
            status, timed_out = None, True
    run = {"work": str(work), "host": str(host),
                                        "host_sha256": host_hash,
                                        "guest_image": str(image), "guest_sha256": guest_hash,
                                        "exit_status": status, "timed_out": timed_out,
                                        "timeout_seconds": args.timeout, "max_runtime_events": args.max_events}
    if args.function_fixtures and fixture_path.is_file():
        with fixture_path.open("rb") as stream:
            run["function_fixtures"] = {"format": "pc2.function_snapshots.v1",
                                        "sha256": hashlib.file_digest(stream, "sha256").hexdigest()}
    write_json(directory / "run.json", run)
    result = save_report(directory, args.linked_manifest)
    if args.function_fixtures and result == 0 and "function_fixtures" not in run:
        raise ValueError("capture host lacks function fixture support, rebuild without --skip-build")
    return result


def show_events(args):
    scenario = read_json(args.directory / "scenario.json")
    watches = list(scenario.get("watches", {}).items())
    names = symbols()
    imports = registered_imports(args.directory)
    target = named_address(args.address, names) if args.address else None
    phase = None
    step_phase = None
    shown = 0
    for seq, (op, thread, *p) in enumerate(read_events(args.directory), 1):
        a, b, c, d, e, f, g, _, _ = p
        if op == STEP:
            command, value = next(iter(scenario["steps"][a].items()))
            if command == "begin":
                phase = value
            step_phase = phase
            detail = {"step": a + 1, "command": command, "value": value, "time_ms": b}
        elif op == ENTRY:
            detail = {"address": address(a), "symbol": symbol(a, names, imports),
                      "registers": dict(zip(REGISTER_NAMES, p[1:]))}
        elif op == EDGE:
            detail = describe_edge((a, b, c, d, e, f, g), names, imports)
        elif op == MESSAGE:
            detail = describe_message((a, b, c, d, e))
        elif op == WATCH:
            detail = dict(watch_value(watches, b, c, d, e, f), step=a + 1)
        elif op == FINISH:
            detail = {"reason": FINISH_REASONS[a], "status": b, "steps_completed": c}
        else:
            detail = {"max_runtime_events": a}
        matches_address = target is None or (op == ENTRY and a == target) or (op == EDGE and target in (a, b, c))
        event_phase = step_phase if op == WATCH else phase
        if matches_address and (args.phase is None or event_phase == args.phase) and (args.type is None or EVENTS[op] == args.type):
            print(json.dumps(dict(detail, seq=seq, event=EVENTS[op], phase=event_phase, thread=thread)))
            shown += 1
            if args.limit and shown >= args.limit:
                break
        if op == STEP and command == "end":
            phase = None
    return 0


def extract_sources(args):
    report = read_json(args.directory / "report.json")
    phase = next((phase for phase in report["phases"] if phase["name"] == args.phase), None)
    if phase is None:
        raise ValueError(f"unknown phase {args.phase!r}")
    names = symbols()
    selected = {address(named_address(value, names)) for value in args.address}
    functions = [dict(function) for function in phase["functions"]
                 if not selected or function["address"] in selected]
    if selected - {function["address"] for function in functions}:
        raise ValueError("an address filter did not match a reached function in this phase")

    locations = defaultdict(dict)
    for function in functions:
        source = function.get("lifted_source")
        if source:
            locations[source["path"]][source["line"]] = function
        if function.get("decompiled_source"):
            function["decompiled_c"] = Path(function["decompiled_source"]).read_text(encoding="utf-8")
    for path, by_line in locations.items():
        with Path(path).open(encoding="utf-8") as file:
            lines = iter(enumerate(file, 1))
            for line_number, text in lines:
                if line_number in by_line:
                    function = by_line.pop(line_number)
                    if not text.startswith(f"void {function['lifted_symbol']}(void)"):
                        raise ValueError(f"stale source location in {path}; rerun the report command")
                    body = [text]
                    for _, text in lines:
                        body.append(text)
                        if text == "}\n":
                            break
                    function["lifted_c"] = "".join(body)
                    if not by_line:
                        break
            if by_line:
                raise ValueError(f"stale source locations in {path}; rerun the report command")
    write_json(args.out, {"format": "pc2.lift_sources.v1", "scenario": report["scenario"],
                          "phase": args.phase, "functions": functions})
    print(f"{len(functions)} reached entries: {args.out}")
    return 0


def main():
    cli = argparse.ArgumentParser(description=__doc__)
    commands = cli.add_subparsers(dest="command", required=True)
    run = commands.add_parser("run", help="build the instrumented host and replay a scenario")
    run.add_argument("scenario", type=Path)
    run.add_argument("--out", type=Path, required=True, help="new directory for capture files")
    run.add_argument("--work", type=Path, default=DEFAULT_WORK, help="cached pcrecomp build directory")
    run.add_argument("--image", type=Path, help="byte-identical copy of the pinned PE beside its assets")
    run.add_argument("--linked-manifest", type=Path, help="report captured entries for linked functions")
    run.add_argument("--function-fixtures", action="store_true",
                     help="capture bounded snapshots at the reviewed function boundaries")
    run.add_argument("--timeout", type=float, default=120)
    run.add_argument("--max-events", type=lambda x: integer(x, "event limit", high=MASK - 1), default=2_000_000,
                     help="limit for runtime records; 0 is unlimited (default: 2,000,000)")
    run.add_argument("--skip-build", action="store_true")
    report = commands.add_parser("report", help="rebuild the summary from existing capture files")
    report.add_argument("directory", type=Path)
    report.add_argument("--linked-manifest", type=Path, help="report captured entries for linked functions")
    events = commands.add_parser("events", help="inspect ordered raw events as JSON lines")
    events.add_argument("directory", type=Path)
    events.add_argument("--phase")
    events.add_argument("--type", choices=EVENTS.values())
    events.add_argument("--address", help="guest address or exact symbol, for entries and edges")
    events.add_argument("--limit", type=lambda x: integer(x, "output limit"), default=0)
    inventory = commands.add_parser("inventory", help="list every lifted dispatch entry")
    inventory.add_argument("--work", type=Path, default=DEFAULT_WORK)
    inventory.add_argument("--out", type=Path, required=True)
    sources = commands.add_parser("sources", help="extract reached function bodies from a phase")
    sources.add_argument("directory", type=Path)
    sources.add_argument("--phase", required=True)
    sources.add_argument("--address", action="append", default=[], help="include only this address or exact symbol; repeatable")
    sources.add_argument("--out", type=Path, required=True)
    args = cli.parse_args()
    try:
        if args.command == "run":
            return run_capture(args)
        if args.command == "report":
            return save_report(args.directory, args.linked_manifest)
        if args.command == "events":
            return show_events(args)
        if args.command == "sources":
            return extract_sources(args)
        entries = catalog(args.work.resolve(), symbols())
        write_json(args.out, {"format": "pc2.lift_inventory.v1", "entries": list(entries.values())})
        print(f"{len(entries)} entries: {args.out}")
        return 0
    except BrokenPipeError:
        return 0
    except (OSError, ValueError, KeyError, struct.error, subprocess.CalledProcessError) as error:
        print(f"capture: {error}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    sys.exit(main())
