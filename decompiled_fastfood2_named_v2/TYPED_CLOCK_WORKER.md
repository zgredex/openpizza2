# Typed packet: clock worker and quarter-hour command

Machine-readable packet:
[`typed_packets/clock_worker.json`](typed_packets/clock_worker.json).
Curated annotations:
[`typed_packets/clock_worker.annotations.json`](typed_packets/clock_worker.annotations.json).
Human packet:
[`typed_packets/clock_worker.md`](typed_packets/clock_worker.md).
Retained REA evidence:
[`typed_packets/clock_worker.rea-evidence.json`](typed_packets/clock_worker.rea-evidence.json)
(121 records).

Target: `game/fastfood2.exe`
SHA-256: `18cfd32e0ac5d6d98162ec016e058a2b51808d9ca49ebee933ce3166ff9922fd`

This is the second typed batch. It contains **11 records**, **40 ordered trace
steps**, **1 dispatch table** and **6 fixtures**. It recovers the clock worker
at `0x4dd300` outside the named export, follows both queued commands to their
consumers, resolves the city-view pest controls, and identifies the wait
import.

## Records

| Address | Name | Signature / role |
|---|---|---|
| `0x4dd270` | `GameClock_Construct` | `GameClock *__thiscall (GameClock *this, int load_from_save)` |
| `0x4dd2d0` | `GameClock_ThreadThunk` | thread entry, loads first stack arg into ECX, jumps to `0x4dd300` |
| `0x4dd300` | `GameClock_Worker` | `void __fastcall (GameClock *this)`; disassembly-only body `0x4dd300..0x4dd49b` |
| `0x4dd4f0` | `GameCalendar_Save` | `void __thiscall (GameClock *this, void *stream)` |
| `0x4dd590` | `GameCalendar_Load` | `void __thiscall (GameClock *this, void *stream)` |
| `0x528190` | `UI_QueueChildCommand` | `int __thiscall (UI *this, int command, int value)` |
| `0x4058d0` | `Game_WindowProc` | `int __cdecl (int command, int value)` observed from stack use |
| `0x4034d0` | `Random_RangeFast` | `unsigned int __cdecl (int low, unsigned int high)` |
| `0x52ff20` | `Array_GetRecordByKeyPtr` | pointer observed in EAX though provider text says void |
| `0x531b70` | `UI_SetButtonRecordVariant` | `void __thiscall (UI *this, int control_id, int variant)` |
| `0x41a2b0` | `CityDetailView_CreateOwnCityWindow` | creates city-view animation controls `0x411..0x415` |

## Worker event order

`GameClock_Construct` registers the thread callback at `0x4dd29d` and calls
`CRT_BeginThread` at `0x4dd2be`. The callback thunk loads the clock pointer and
jumps to `0x4dd300` at `0x4dd2d4`.

The worker loop:

1. Reads the interval and computes the next wake deadline:
   `0x4dd30f`.
2. Derives the hour from the quarter counter: `0x4dd326`.
3. Increments and stores the five-minute counter: `0x4dd3da`, `0x4dd3e0`.
4. Wraps the counter at 12: `0x4dd3e8`.
5. Stores the five-minute unit at `clock+0x06`: `0x4dd3f2`.
6. Enters the quarter-hour branch when the unit is 0, 3, 6 or 9:
   `0x4dd3f5..0x4dd409`.
7. Pushes command `0xfffe79f7` at `0x4dd412`, increments `clock+0x19` at
   `0x4dd417`, and calls `UI_QueueChildCommand` at `0x4dd420`.
8. At `clock+0x19 == 0x60` (`0x4dd425`), resets it (`0x4dd42e`), advances the
   day counter (`0x4dd436`), wraps the year word (`0x4dd43d`) and advances the
   date word (`0x4dd448`).
9. When `(quarter & 3) == 0`, derives the hour (`0x4dd456`), stores
   `clock+0x07` (`0x4dd459`), pushes `0xfffe79de` (`0x4dd464`) and queues it
   (`0x4dd469`).

## Quarter-hour command consumer

`Game_WindowProc` compares the command with `0xfffe79f7` at `0x4058f5` and
branches to `0x405ae0` at `0x40591f`.

The case:

- rolls `Random_RangeFast(0, 100)` at `0x405b0c`;
- requires the roll to be greater than 75 (`0x4b`) at `0x405b14`;
- rolls one of five control IDs `0x411..0x415` at `0x405b38`/`0x405b3f`;
- looks up the control record at `0x405b49` (`Array_GetRecordByKeyPtr`);
- calls `UI_SetButtonRecordVariant` at `0x405b5b`.

The route and call targets are established. `CityDetailView_CreateOwnCityWindow`
`0x41a2b0` creates controls `0x411..0x415` as city-view pest animations:

| Control | Animation | Family | Creation |
|---|---|---|---|
| `0x411` | `KAKANIM2.ani` | cockroach | `0x41a5df`/`0x41a5e6` |
| `0x412` | `KAKANIM.ani` | cockroach | `0x41a68d`/`0x41a694` |
| `0x413` | `KAKANIM1.ani` | cockroach | `0x41a6a8`/`0x41a6af` |
| `0x414` | `TOMATENANIM.ani` | tomato | `0x41a6c0`/`0x41a6c7` |
| `0x415` | `SPIDERANIM.ani` | spider | `0x41a506`/`0x41a50d` |

`Game+0x25c` receives this own-city detail window at `0x485f92`. The
quarter-hour case therefore triggers one random city-view pest animation
variant. The exact gameplay intent is inferred from the animation names; the
control-to-animation mapping and call route are established.

### Hourly command consumer

`0xfffe79de` maps through `Game_WindowProc`'s command table:

- `0x405925` adds `0x18684` to the command, giving index `0x62`;
- `0x40592a` range-checks `0..0x7a`;
- `0x405935` loads selector byte `4` from `0x406640 + 0x62`;
- `0x40593b` jumps through `0x406618 + 4*4` to `0x405aa9`;
- `0x405aa9` calls `Game_EndOfHour 0x486590` at `0x405ab3`.

The selector table entry is at `0x4066a2` (byte `0x04`), and the target table
entry is at `0x406628` (`0x00405aa9`).

### Wait import

`0x55c090` is the KERNEL32 IAT slot for `WaitForSingleObject` (IAT RVA
`0x15c090`), confirmed from the PE import table. The worker calls it at
`0x4dd39d`.

## Saved state

`GameCalendar_Save` writes the clock fields in this order (size in bytes):

```text
+0x07:1  +0x06:1  +0x08:1  +0x04:2  +0x0a:2  +0x0c:4
+0x19:1  +0x18:1  +0x14:4  +0x10:4  DAT_0057dfbc:4
```

`GameCalendar_Load` reads the same order. It then forces the interval
`clock+0x14` to `0xc35` at `0x4dd616` and, for save versions at or below
`0x2d`, sets `DAT_0057dfbc` to `0x7d0` (2000) at `0x4dd640`; newer saves read
the stored value at `0x4dd633`.

## Fixtures

| Fixture | Expected |
|---|---|
| quarter-hour command | units 0/3/6/9 queue `0xfffe79f7`; consumer `0x405ae0` |
| hourly command | `(quarter & 3) == 0` queues `0xfffe79de` at `0x4dd469` |
| hourly consumer | `0xfffe79de` -> index `0x62`, selector 4, target `0x405aa9` |
| quarter-hour controls | `0x411..0x415` -> cockroach/tomato/spider animations |
| calendar save order | 11 fields in the exact order above |
| calendar load override | interval always becomes `0xc35` after the read |

## Emulated command fixture

A bounded Unicorn harness starts at `0x4058f5`, sets `EAX` to the command, and
stops at the consumer entry. Fixture:
[`typed_packets/fixtures/game_window_command_dispatch.fixture.json`](typed_packets/fixtures/game_window_command_dispatch.fixture.json).

| Command | Target | Index | Selector |
|---|---|---|---|
| `0xfffe79de` | `0x405aa9` | `0x62` | 4 |
| `0xfffe79f7` | `0x405ae0` | n/a | n/a |

```sh
python3 tools/emulate_clock_command.py
```

```text
2/2 cases match; evidence=emulated
```

## Unresolved evidence boundary

- The worker has no named procedure; its body is bounded by disassembly
  `0x4dd300..0x4dd49b` and the return at `0x4dd49b`.
- The 25% chance and variant `1` are established as the executed rule, but the
  gameplay intent of selecting a pest animation at quarter-hour intervals is
  inferred from the animation names.
- The hour-handler phase order is recorded elsewhere; this packet verifies only
  the command edge to `Game_EndOfHour`.

## Reproduction

```sh
python3 tools/function_batch.py \
  0x4dd270 0x4dd2d0 0x4dd300 0x4dd4f0 0x4dd590 \
  0x528190 0x4058d0 0x4034d0 0x52ff20 0x531b70 \
  --annotations decompiled_fastfood2_named_v2/typed_packets/clock_worker.annotations.json \
  --json-out decompiled_fastfood2_named_v2/typed_packets/clock_worker.json \
  --out decompiled_fastfood2_named_v2/typed_packets/clock_worker.md

python3 tools/verify_typed_packet.py --expectations decompiled_fastfood2_named_v2/typed_packets/clock_worker.expectations.json
```

```text
typed packets: 1 packet(s), 11 records, 40 trace steps, 1 tables, 6 fixtures,
40/40 instruction prefixes match, 8/8 mutations rejected
```
