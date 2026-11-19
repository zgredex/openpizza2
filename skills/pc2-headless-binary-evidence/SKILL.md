---
name: pc2-headless-binary-evidence
description: Verify Pizza Connection 2 routines against the original PE32 bytes using headless Unicorn fixtures and focused binary evidence.
---

# Headless Pizza Connection 2 binary evidence

Work from the repo root on the requested routine and its fixture. Use `game/fastfood2.exe` as input bytes for Unicorn and static analysis. Keep execution headless.

## Run the existing fixture first

| Routine | Command |
|---|---|
| Starting capital `0x48d3a0` | `python3 tools/emulate_starting_capital.py` |
| Clock command dispatch | `python3 tools/emulate_clock_command.py` |

Both runners accept `--fixture` and `--json-out`. Fixtures and retained results are in `decompiled_fastfood2_named_v2/typed_packets/fixtures/`. For other routines, search `tools/` and the fixture directory by name or address before adding a runner.

## Investigate the first mismatch or missing dependency

- Match the executable SHA-256 before reusing addresses. Read the relevant record from `decompiled_fastfood2_named_v2/typed_packets/` and disassemble only the necessary address range. Expand the read when it resolves a specific missing input, call, or register assumption.
- For a new case, map the required PE sections at their preferred addresses, zero-fill virtual tails, and initialize the 32-bit x86 registers, stack, and globals. Specify the entry, expected stop, instruction limit, and time limit. Label synthetic state and any stubbed effects.
- Emit compact JSON with the executable hash, fixture ID, entry, stop reason, final address, and observed outputs. Report the first mismatch or blocked instruction with its missing dependency. Save full traces to a file when needed.

Run the affected fixture after edits. For typed packet changes, regenerate the affected packet with `tools/function_batch.py` and run `python3 tools/verify_typed_packet.py --expectations <packet.expectations.json>`. Use the broader suite when shared code or the request warrants it. Keep static findings and emulated results labeled separately. Finish when the requested check passes, or report the exact remaining blocker.
