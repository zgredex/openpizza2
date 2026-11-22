# Lifted PC2 trace capture

Use `capture.py` to replay an interaction on the lifted Linux host and collect the functions, call edges, messages, and guest state associated with it. It builds a separate instrumented host under `PC2_WORK/pc2-capture` and keeps the normal `pc2-native` build available.

## Run the main-menu examples

From the repository root, use the same `--work` directory as your pinned build. The first run builds the normal lift if needed and compiles the instrumented host. It runs with SDL's dummy video and audio drivers. A fresh output directory keeps the run and its evidence together.

```sh
python3 tools/pcrecomp_pc2/capture.py run \
  tools/pcrecomp_pc2/scenarios/menu-click.json \
  --work /tmp/opencode/pcrecomp-pc2-fresh \
  --out /tmp/pc2-menu-click
```

This waits for the main menu, posts the same mouse message sequence as the campaign smoke test, and verifies that the dispatcher opens Character Select (`screen` changes from `21` to `28`). A second scenario sends pointer events through the normal HLE input path and verifies that releasing outside the button leaves the menu active.

```sh
python3 tools/pcrecomp_pc2/capture.py run \
  tools/pcrecomp_pc2/scenarios/menu-drag.json \
  --work /tmp/opencode/pcrecomp-pc2-fresh \
  --out /tmp/pc2-menu-drag --skip-build
```

The runner uses Python 3.11 or later on Linux. `--work` defaults to `PC2_WORK` or `/tmp/opencode/pcrecomp-pc2`. Use `--skip-build` when the instrumented host is already current. `--timeout` gives the guest a wall-clock limit in seconds after the build. The default is 120 seconds. The default capture limit is 2,000,000 runtime records, about 88 MB of binary data. `--max-events 0` allows unlimited recording within the time limit. Use short named phases around the action of interest. A scenario whose first step is `begin` starts recording after PE mapping and before the guest CRT entry.

## Replay a scratch image

Use `--image` to map a [verified scratch PE](../../reconstructed/match/README.md#scratch-pe-verification)
through the pinned lift. The runner checks that the image SHA-256 matches the
original before starting the host. Keep its installed assets in the image's
directory, which becomes the host working directory. `run.json` records the
image path and hash alongside the host hash.

```sh
python3 tools/pcrecomp_pc2/capture.py run tools/pcrecomp_pc2/scenarios/menu-click.json \
  --work /tmp/opencode/pcrecomp-pc2-fresh --skip-build \
  --image "$scratch/fastfood2.exe" --out /tmp/pc2-scratch-menu-click
```

Add `--linked-manifest "$scratch/batch-manifest.json"` to `run`, or apply it
afterward with `capture.py report`. The report counts entries at manifest VAs
within captured phases and lists linked addresses that were not seen. This
measures the scenario on the pinned lift.

```sh
python3 tools/pcrecomp_pc2/capture.py report /tmp/pc2-scratch-menu-click \
  --linked-manifest "$scratch/batch-manifest.json"
```

## Read the evidence

| File | Contents |
| --- | --- |
| `report.json` | Per-phase function, edge, and message counts, including thread counts. Replay steps carry the state watch results and execution time. Known addresses link to generated C and existing decompilation. |
| `events.bin` | Ordered records from the capture phases. Function entries include the eight x86 general-purpose registers. Edges capture the guest caller, site when available, resolved target, and the active HLE shim. |
| `imports.tsv` | The registered Win32 and COM shim names for synthetic guest addresses. |
| `host.log` | Startup diagnostics, guest errors, and existing PC2 trace messages. |
| `scenario.json`, `run.json`, `plan.bin` | Replay input, executable hashes and process outcome, and the compiled replay plan. |

`complete: true` means the scenario finished, its assertions succeeded, and the runtime record limit was respected. `replay_completed` reports scenario success even if the event limit was reached. A timeout, assertion failure, or early guest exit produces a partial report and a nonzero CLI result. Check `host.log`, the last reached step, and any edges with `resolution: "no_dispatch"`. That resolution describes the runtime lookup at the call site. A guest exception continuation can still be handled by the runtime after a lookup miss.

Inspect chronology, list the whole lift, or extract source for the LLM.

```sh
# Inspect call order around the menu callback.
python3 tools/pcrecomp_pc2/capture.py events /tmp/pc2-menu-click \
  --phase posted-click-inside --address 0x004CEB80 --limit 20

# Export the C body and any existing Ghidra output for a reached function.
# Omit --address to extract every function reached in the phase.
python3 tools/pcrecomp_pc2/capture.py sources /tmp/pc2-menu-click \
  --phase posted-click-inside --address 0x004CEB80 --out /tmp/pc2-menu-sources.json

# Include dispatch entries from all game code, including code this replay never reached.
python3 tools/pcrecomp_pc2/capture.py inventory \
  --work /tmp/opencode/pcrecomp-pc2-fresh --out /tmp/pc2-lift-inventory.json

# Rebuild report.json from a saved run and the current symbol files.
python3 tools/pcrecomp_pc2/capture.py report /tmp/pc2-menu-click
```

`events` writes JSON Lines. `--type` selects `entry`, `edge`, `message`, `step`, `watch`, `finish`, or `limit`. `--address` matches a function entry or an edge's caller, target, or instruction site. At a `watch` event, `value` is decoded using its declared type and `bits` preserves its raw representation. Unmapped or null pointers produce `readable: false`. Source export reads the lift from the recorded `--work` directory. Keep that generated build available when extracting bodies later.

## Write a scenario

Copy one of the menu scenarios. Define named guest memory watches and a list of steps. Each step has one command. Addresses take a JSON integer, a hexadecimal string, or an exact symbol from the function map. A watch can specify `u8`, `i8`, `u16`, `i16`, `u32`, `i32`, `u64`, `i64`, `f32`, or `f64`.

```json
{
  "name": "inspect a menu phase",
  "watches": {
    "screen": {"address": "0x0057C5B8", "type": "u32"},
    "ui_width": {"address": "0x0057C5E0", "offsets": ["0x270"], "type": "u32"}
  },
  "steps": [
    {"wait_function": "Screen_MainMenu"},
    {"begin": "inspection"},
    {"mouse": {"action": "move", "x": 650, "y": 18}},
    {"delay_ms": 120},
    {"snapshot": "after-hover"},
    {"assert_value": {"watch": "screen", "equals": 21}},
    {"end": "inspection"}
  ]
}
```

Each `offsets` element dereferences a 32-bit guest pointer at the current address, then adds that offset. For the example `ui_width` watch, the host reads the pointer stored at `0x0057C5E0` and reads the width at the pointed-to object plus `0x270`. Put `begin` and `end` around each interaction to record its before and after state automatically. Use `snapshot` for another checkpoint inside or outside a phase.

| Command | Meaning |
| --- | --- |
| `begin`, `end`, `snapshot` | Take a watch snapshot. `begin` and `end` name and delimit a capture phase. Phase names are unique within a scenario. |
| `wait_function` | Wait for the next entry at an address or symbol. Use `{"address":"0x…","count":2}` to wait for multiple entries after the step is armed. |
| `wait_value`, `assert_value` | Wait for a watch to equal the expected value, or check it immediately and mark a mismatch as a failed replay. Both take `{"watch":"name","equals":value}`. Floating-point comparisons use the recorded bit representation. |
| `delay_ms` | Wait a given number of milliseconds. Use a function or state wait when the game exposes a suitable readiness signal. |
| `mouse`, `key`, `wheel` | Send input through the same HLE input path as SDL. Mouse coordinates are in guest screen space. Actions are `move`, `down`, `up`, `right_down`, `right_up`, `middle_down`, and `middle_up`. A key step takes `action`, `vk`, and an optional `scan`. Wheel deltas are in Win32 units, typically 120 per notch. |
| `post` | Post a raw Win32 message to the first window with `message`, optional `wparam`, and optional `lparam`. Adjacent `post` steps are queued together. This path keeps the host pointer and key state untouched. Use it to reproduce existing smoke tests that post messages directly. |
| `click` | Post a move, left-button down, and left-button up together to the first window. Takes guest client coordinates `x` and `y`. Follow it with a state or function wait when the next click depends on its outcome. |

A scenario can set `env` to an object of PC2 option names and string values. Use it to reuse the campaign bootstrap while recording later gameplay. The replay script controls when tracing begins. The capture runner reads those options from the scenario so terminal settings for another test cannot quietly inject input.

## Use a trace to port a behavior

1. Start with `report.json`. Find the action's screen or state change and identify the functions and indirect targets around it.
2. Filter the raw events to check message order and function entry registers. Extract the relevant C bodies and use their addresses to find existing layout notes and typed packets.
3. Use the same starting state and inputs as a Rust replay fixture. Verify the resulting state, then add another scenario for alternate outcomes.

The report describes the executed lift and the configured state watches. Intra-function branches, per-instruction memory accesses, and untaken code paths have no runtime records in this format. The inventory lists every dispatch entry in the lift, including compiler helpers and aliases. Confirm behavior against the shipped executable when input routing, timers, exception handling, or another `win32hle` behavior could affect the result.

## Recheck a function fixture without booting

Add `--function-fixtures` to capture up to 16 completed calls per reviewed
routine. The first capture needs an instrumented host rebuild. The runner
records before and return snapshots for `Surface_ResetFlags` (`0x539f20`) and
`UI_SetClampedValue` (`0x52a3a0`). These snapshots are separate from the phase
event budget, so initialization calls can be collected before the first phase.

```sh
python3 tools/pcrecomp_pc2/capture.py run tools/pcrecomp_pc2/scenarios/menu-click.json \
  --work /tmp/pc2-fixture-host --out /tmp/pc2-function-capture --function-fixtures
python3 tools/pcrecomp_pc2/function_fixtures.py extract /tmp/pc2-function-capture \
  --cache /tmp/pc2-function-cache --out /tmp/pc2-function-fixture.json
/tmp/pc2-fixture-host/venv/bin/python tools/pcrecomp_pc2/function_fixtures.py verify \
  /tmp/pc2-function-fixture.json --repeat 3
```

Extraction checks the capture and snapshot SHA-256s and deduplicates equivalent
calls. It reports unsupported text callbacks separately. The UI fixture checks
the selected integer slot, range fields, and guard writes for slots 0–3 when the
text callback is null. The surface fixture checks the flag at `ECX+0x74` with
the CPUID feature input seen in the lift. Offline verification executes the
original PE functions in Unicorn with the recorded inputs and checks the return
snapshots, stack cleanup, and callee-saved registers.

Use `verify --address 0x52a3a0 --source /path/to/candidate.c` to check a single
C implementation exposing `pc2_candidate` with the original i386 `thiscall`
ABI. Each case gets a fresh emulator instance. Add `--cache` to reuse the
compiled ELF across invocations for self-contained sources. The JSON routes
passing candidates to `strict_match` and differences to `inspect_mismatch`.
Run the strict matcher separately for byte verification. `verify --regression`
deliberately changes the surface flag write and the UI slot write and returns
nonzero. `reference` creates separate bootless smoke cases from seeded inputs
and labels their origin accordingly.

The headless menu replay advanced from screen 21 to 28 and had zero unresolved
dispatch edges. It produced one surface case and 16 UI cases, all of which passed
three bootless runs against the original. Known-good C probes passed on a cold
and warm cache for each address, and both deliberate changes were rejected.
The live UI cases exercised the unclamped path. The seeded reference cases
also exercise ascending and descending clamp bounds.
