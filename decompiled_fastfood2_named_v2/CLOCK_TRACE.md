# Original simulation clock and shared replay

The clock worker is at `0x4dd300` and is reached from the thread callback
registered by `GameClock_Construct` (`0x4dd270`) via `0x4dd2d0`. It is outside
the named export, so the field map below comes from bounded disassembly.

## Clock fields and tick math

| Offset | Meaning | Evidence |
|---|---|---|
| `+0x14` | real-time callback interval; initialized to `0xc35` = 3125 ms | `GameClock_Construct`/`0x4dd300` |
| `+0x10` | five-minute unit counter, 0..11 | `0x4dd3da`–`0x4dd3f2` |
| `+0x06` | five-minute minute field, `counter * 5` | writer at `0x4dd3f2`; reader `Game_GetDateFields 0x48b3c0` |
| `+0x19` | quarter-hour counter, 0..95 | `0x4dd40b`–`0x4dd44c` |
| `+0x07` | hour, `quarter_count >> 2` | writer at `0x4dd456`; `Game_GetDateFields` |
| `+0x18` | day/date counter advanced when quarter counter wraps 96 | `0x4dd42b`–`0x4dd44c` |
| `+0x04` | year/date word | `GameCalendar_Save`/`Load 0x4dd4f0`/`0x4dd590` |
| `+0x0a` | date word advanced at the day boundary | `0x4dd448` |
| `+0x0c` | saved calendar counter | `GameCalendar_Save` |
| `+0x1c`, `+0x20` | clock pause/worker flags | `0x4dd300` control flow |

At each worker tick:

1. `+0x10` increments; if it reaches 12 it wraps to 0.
2. `+0x06` is set to that five-minute unit.
3. When the unit is 0, 3, 6 or 9, `+0x19` increments.
4. When `+0x19 & 3 == 0`, `+0x07` is set to `+0x19 >> 2` and command
   `0xfffe79de` is queued.
5. When `+0x19` reaches 96 it resets; `+0x18` advances and the date word at
   `+0x0a` increments.

Therefore the five-minute fields produce four quarter-hour steps per hour.
`0xfffe79de` is signed `-0x18622`; `Game_WindowProc 0x4058d0` maps it through
index `0x62` and selector 4 of the tables at `0x406640`/`0x406618` to
`0x405aa9`, which calls `Game_EndOfHour 0x486590` at `0x405ab3`. `0xfffe79dd` is `-0x18623`, which dispatches to
`Game_AutoSaveTick`, not the hour handler. The `0xfffe79f7` command is queued
at quarter steps. Typed packet `TYPED_CLOCK_WORKER.md` follows it to
`Game_WindowProc`'s comparison at `0x4058f5` and case at `0x405ae0`: the case
rolls 0..100, requires >75, chooses one of controls `0x411..0x415`, and calls
`Array_GetRecordByKeyPtr` plus `UI_SetButtonRecordVariant`. Those controls are
the city-view pest animations created by `CityDetailView_CreateOwnCityWindow
0x41a2b0`: `0x411` `KAKANIM2.ani`, `0x412` `KAKANIM.ani`, `0x413`
`KAKANIM1.ani`, `0x414` `TOMATENANIM.ani`, `0x415` `SPIDERANIM.ani`.

## Hourly handler order

`Game_EndOfHour` first increments the clock's saved hour counter (`+0xc`) under
the state lock, then runs in this order:

1. `Rating_DecayAndUpdateIndicators` for characters;
2. `City_TickSimulation` for active cities;
3. `Player_MissionState_Tick` for six player slots;
4. `Company_ProcessHourlyTick` for six company slots;
5. `Object_CanDetach` cleanup, character/map removal and selection reset;
6. `Game_PurgeUnusedCompanyRecipes`;
7. at hour zero, the routine labeled `Game_EndOfQuarter`;
8. debug/UI notifications, a three-hour reset (`hour % 3 == 0`), unlock and
   thread signal.

The hour value used by the handler is `clock+7`, so 11:00 passes hour 11 and
00:00 passes hour 0. The `Game_EndOfQuarter` label at hour zero is retained as
a boundary event but its name is not treated as proof of quarterly semantics;
that remains **R**.

## One authoritative world

`pc2_sim::World` owns the minute, the scripted visit, the queue and the branch
economy. `ClockReplay` is an alias for `World`; there is no separate viewer
clock. Both `pc2-clock` and the viewer submit the same `open`, `close`,
`price=N` and `step` commands to it:

- `step` advances five minutes;
- the clock increments the branch minute on every tick;
- the hourly dispatch runs when `minute % 60 == 0`;
- one arrival is created when the branch is open and the visit is idle;
- the visit advances one phase per tick:
  `Waiting -> Producing -> settlement -> Departing -> Idle`;
- stock and cash change only at the settlement tick;
- the customer actor is hidden while the visit is idle and follows the world
  clock animation while waiting, producing or departing.

The queue admission here is a deliberate one-customer scripting rule, not a
recovered original rule. The original queue-admission logic remains **R**.

## Replay 1: 10:55 → 11:20 with a waiting snapshot

`pc2-clock --start 10:55 --end 11:20 --snapshot-at 11:00
--snapshot-resume`:

```text
11:00 tick
11:00 hourly hour=11 index=1
  phase characters
  phase cities
  phase missions
  phase companies
  phase object_cleanup
  phase recipes
11:00 arrival queue=1
11:05 tick
11:05 production_start
11:10 tick
11:10 queue_service remaining=0
11:10 sale stock=399 cash_delta=13.420525
11:15 tick
11:15 departure
11:20 tick
hourly_count=1
quarter_boundary_count=0
snapshot_resume=identical
branch_clock=11:20
final=11:20
```

The hourly event fires exactly once. The arrival is visible at 11:00, the
customer is in production at 11:05, the sale settles at 11:10, and the branch
returns to idle after the departure at 11:15. Stock and cash change only at
11:10: `400 -> 399` and `+13.4205247`.

## Replay 2: 23:55 → 00:05

```text
D+1 00:00 tick
D+1 00:00 hourly hour=0 index=1
  phase characters
  phase cities
  phase missions
  phase companies
  phase object_cleanup
  phase recipes
D+1 00:00 quarter_boundary hour=0
D+1 00:00 arrival queue=1
D+1 00:05 tick
D+1 00:05 production_start
hourly_count=1
quarter_boundary_count=1
snapshot_resume=identical
branch_clock=D+1 00:05
final=D+1 00:05
```

The midnight hourly and quarter boundary each fire once, and the same arrival
rule applies at hour zero.

## Snapshot contract

`WorldSnapshot` stores the minute, queue count, hourly count, visit state,
phase start minute and the complete `BranchSim` snapshot. `pc2-clock
--snapshot-at HH:MM --snapshot-resume` snapshots after the events at that
minute, runs uninterrupted to the end, restores the snapshot, runs the same
suffix again, and compares the full event vector and final simulation
snapshot. The Rust test snapshots at 11:00 while the customer is waiting,
resumes to 11:20, and requires identical events, clock, stock and cash.

Saved calendar fields are the ones written by `GameCalendar_Save 0x4dd4f0`:
hour, minute unit, date byte, year word, date word, calendar counter, quarter
counter, day counter, interval, minute counter and the date base. The Rust
snapshot keeps the full minute and sim state; gradual calendar field parity is
still pending.

## Confidence

- **Static:** worker field writes, 0x4dd300 control flow, command IDs,
  `Game_EndOfHour` phase order, `GameCalendar_Save` field list.
- **Controlled:** the five-minute replay, hourly-once assertion, one
  waiting/production/settlement/departure visit, midnight boundary, and
  snapshot equality while waiting.
- **Runtime pending:** gameplay intent of the random pest animation trigger,
  quarter/day semantics of `+0x18`/`+0x0a`, real-time 3125 ms scheduling,
  original queue admission and original event captures.
