# Typed packet: Free Play Start -> city -> initial world

Machine-readable packet:
[`typed_packets/free_play_start.json`](typed_packets/free_play_start.json).
Curated annotations:
[`typed_packets/free_play_start.annotations.json`](typed_packets/free_play_start.annotations.json).
Human packet:
[`typed_packets/free_play_start.md`](typed_packets/free_play_start.md).
Retained REA evidence:
[`typed_packets/free_play_start.rea-evidence.json`](typed_packets/free_play_start.rea-evidence.json)
(121 records).

Target: `game/fastfood2.exe`
SHA-256: `18cfd32e0ac5d6d98162ec016e058a2b51808d9ca49ebee933ce3166ff9922fd`

The packet contains 10 records, 40 ordered trace steps, 2 dispatch tables and 2 cash fixtures.
Each trace step stores
its PE virtual address, recovered instruction, and exact instruction-byte
prefix. `tools/verify_typed_packet.py` maps those addresses through the PE
section table and checks every prefix against the executable.

## Batch chain

```text
Screen_FreePlaySetup 0x472da0
  -> FreePlaySetup_InitWindow 0x4cbcd0
  -> FreePlaySetup_ControlCallback 0x4cc640 (unnamed callback entry)
  -> GameLoop_DispatchScreens 0x4052c0
  -> Game_RunSession 0x404af0
  -> Game_InitScenario 0x481d90
  -> City_ConstructFromName 0x4d44e0
```

The callback is not a named procedure in the retained export. It is recovered
from the registration at `0x472daa` (`PUSH 0x4cc640`) and bounded disassembly
`0x4cc640..0x4cd72d`. The callback's Start control is `0x4e3`; its dispatch
table is at `0x4cd770` with selector bytes at `0x4cd7e0`.

## Recovered dispatch edges

| From | Instruction | Edge |
|---|---|---|
| callback control `0x4e3` | `0x4cc7e9` | Start -> `0x4cd33d` |
| callback control `0x4e2` | `0x4cc7e9` | Back -> `0x4cd2b9` |
| Start handler | `0x4cd342` | screen state `DAT_0056386c = 0x17` |
| screen dispatcher | `0x405397` | state index `state - 0x15` |
| screen dispatcher | `0x4053a3` | jump table `0x4055a4`, case `0x17` -> `0x40542e` |
| case `0x17` | `0x405444` | `call Game_RunSession 0x404af0` |
| Game_RunSession | `0x404dfc` | `call Game_InitScenario 0x481d90` |
| Game_InitScenario | `0x481e85` | `call City_ConstructFromName 0x4d44e0` |

`Game_GetStartingCapital` (`0x48d3a0`) uses a jump table at `0x48d3f4` for
difficulty `0..9`; all other values return 20,000. Difficulty 9 returns
`0x55f0` = 22,000 at `0x48d3e7`.

## Selected values to first consumers

| Value | Producer | First consumer | Instruction |
|---|---|---|---|
| city index | `DAT_0057bb40` | map-list get + record `+0x40` | `0x4cd420`, `0x4cd44f`, `0x4cd454` |
| city short name | `DAT_0057bb44` | `City_ConstructFromName` | `0x4cd490`, `0x4cd498`, `0x481e7e`, `0x481e85` |
| city ini | `%s.ini` | config loader `0x4db430` | `0x4d455c`, `0x4d4562`, `0x4d4573` |
| city map | `%s.iso` | map loader `0x4eb0f0` | `0x4d46f7`, `0x4d46fd`, `0x4d472e` |
| population | `DAT_0057bb28` | `City_Register` -> `City_InitPopulation` | `0x481ec3`, `0x481ecd`, `0x482771`, `0x482779`, `0x4d4a45` |
| difficulty | `DAT_0057bb24` | `Game_GetStartingCapital` | `0x48d3a0`, `0x48d3aa`, `0x48d3e7` |
| starting capital | return value | company `+0x108` | `0x481f5f`, `0x481f64`, `0x482048`, `0x4820c1` |

### City

`FreePlaySetup_InitWindow` resets the selected index to zero at `0x4cbe69`,
compares map record `+0x40` short names with `DAT_0057b9c4` at `0x4cbe86`, and
stores the matching index in `DAT_0057bb40` at `0x4cbe9e`. The Start callback
fetches that record through the list at `DAT_0057de38` (`0x4cd44f`) and copies
record `+0x40` into both `DAT_0057b9c4` and `DAT_0057bb44` (`0x4cd498`).

`Game_InitScenario` pushes `DAT_0057bb44` at `0x481e7e` and calls
`City_ConstructFromName` at `0x481e85`. The constructor formats `%s.ini` at
`0x4d455c`/`0x4d4562` and `%s.iso` at `0x4d46f7`/`0x4d46fd`. For the traced
default city `ber`, these become `ber.ini` and `ber.iso`.

### Population

`FreePlaySetup_InitWindow` reads persisted population `DAT_0057b9c8` at
`0x4cbe4b` and writes screen population `DAT_0057bb28` at `0x4cbe51`. The Start
callback persists it back to `DAT_0057b9c8` at `0x4cd3f8`. `Game_InitScenario`
reads it at `0x481ec3` and calls `City_Register` at `0x481ecd`. `City_Register`
loads the population argument at `0x482771` and calls `City_InitPopulation` at
`0x482779`; the first observed write is `city+0x48` at `0x4d4a45`.

### Difficulty and starting cash

The Character Select Start and Free Play Start both store difficulty in
`DAT_0057bb24` (`0x4c7bdc` and `0x4cd415`/`0x4cd432`). `Game_InitScenario` calls
`Game_GetStartingCapital` at `0x481f5f`. The callee reads `DAT_0057bb24` at
`0x48d3a0` and dispatches through `0x48d3f4` at `0x48d3aa`.

For difficulty 9 the jump target is `0x48d3e7`, which returns `0x55f0` =
22,000. `Game_InitScenario` stores the return at `0x481f64`, multiplies it by
the player company's ownership percentage `DAT_0057bcd8` at `0x482048`, and
writes the resulting double to company `+0x108` at `0x4820c1`. With ownership
100, the initial cash is exactly 22,000.

The free-play ownership percentage is established. `Settings_InitDefaults`
writes 100 to `0x57b97c` at `0x406b90`. `FreePlaySetup_InitWindow` copies it to
`0x57bcd8` at `0x4cbebd`. The setup arrows adjust the working value by -10 at
`0x4cc8d7`/`0x4cc8dc` (minimum 70 at `0x4cc8e3`) and by +10 at
`0x4cc929`/`0x4cc92e` (maximum 990 at `0x4cc938`).

The cash field itself is established: `Stats_AddRecordValue` adds to the same
`+0x108` double, and `Game_CanAfford` reads it.

| Fixture | Base | Ownership | Cash |
|---|---:|---:|---:|
| difficulty 9, default | 22,000 | 100% | 22,000 |
| difficulty 9, +10 click | 22,000 | 110% | 24,200 |

## Emulated fixture

The first original-instruction fixture executes `Game_GetStartingCapital`
`0x48d3a0` from the PE bytes with Unicorn. The image is mapped at `0x400000`,
the difficulty dword is written at `0x57bb24`, and execution stops at the
first RET.

Fixture:
[`typed_packets/fixtures/game_get_starting_capital.fixture.json`](typed_packets/fixtures/game_get_starting_capital.fixture.json).
Checked-in result:
[`typed_packets/fixtures/game_get_starting_capital.result.json`](typed_packets/fixtures/game_get_starting_capital.result.json).

| Difficulty | EAX | Stop |
|---:|---:|---|
| 0 | 1,000,000 | `0x48d3b6` |
| 1 | 500,000 | `0x48d3bc` |
| 2 | 200,000 | `0x48d3c2` |
| 3 | 100,000 | `0x48d3c8` |
| 4 | 75,000 | `0x48d3ce` |
| 5 | 50,000 | `0x48d3d4` |
| 6 | 40,000 | `0x48d3da` |
| 7 | 30,000 | `0x48d3e0` |
| 8 | 25,000 | `0x48d3e6` |
| 9 | 22,000 | `0x48d3ec` |
| 10 / 255 | 20,000 | `0x48d3f2` |

```sh
python3 tools/emulate_starting_capital.py
```

```text
12/12 cases match; evidence=emulated; stop_reason=ret
```

This fixture covers the base-capital lookup only. The percentage multiplier
and company cash write are covered by the static trace and the two cash
fixtures above; they are not part of this Unicorn case.

## Recovered signatures

| Address | Procedure | Recovered signature | Basis |
|---|---|---|---|
| `0x406a90` | `Settings_InitDefaults` | `void __cdecl Settings_InitDefaults(void)` | no stack args; default write at `0x406b90` |
| `0x472da0` | `Screen_FreePlaySetup` | `void *__cdecl Screen_FreePlaySetup(int *state_out)` | call site `0x405478`, state write `0x472dc0` |
| `0x4cbcd0` | `FreePlaySetup_InitWindow` | `void __cdecl FreePlaySetup_InitWindow(void *window)` | call site `0x405480` |
| `0x4cc640` | callback (unnamed) | `int __cdecl callback(void *window, unsigned message, int control_id, int value)` | callback registration plus stack use |
| `0x4052c0` | `GameLoop_DispatchScreens` | state-machine `void __cdecl(void)`; provider signature has spurious stack parameters | internal dispatch |
| `0x404af0` | `Game_RunSession` | `void __cdecl Game_RunSession(void)` | call site `0x405444` |
| `0x481d90` | `Game_InitScenario` | `void __thiscall Game_InitScenario(Game *this)` | call site `0x404dfc`; provider carries spurious stack parameters |
| `0x48d3a0` | `Game_GetStartingCapital` | `int __cdecl Game_GetStartingCapital(void)` | no stack args; `RET` |
| `0x482740` | `City_Register` | `void __thiscall City_Register(Game *this, City *city, int population, int company_count)` | call site `0x481ecd` |
| `0x4d44e0` | `City_ConstructFromName` | `City *__thiscall City_ConstructFromName(City *this, const char *city_name, int unused)` | call site `0x481e85`; `EAX` return |

## Unresolved questions

- The callback body is outside the named export. Its full `0x3fa..0x4e3`
  control jump table is not annotated beyond Back/Start.
- Virtual cleanup calls in the setup callback (`0x4cd376`, `0x4cd38b`) have
  unresolved targets.
- The six Character Select attribute fields still lack an established
  sale-economy consumer. `Game_GetPlayerStaff 0x501df0` reads `+0x40` and
  `+0x50`, but the semantic formula is not proven.
- The clock worker is now the second typed packet
  ([TYPED_CLOCK_WORKER.md](TYPED_CLOCK_WORKER.md)).

## Reproduction

```sh
python3 tools/function_batch.py \
  0x472da0 0x4cbcd0 0x4cc640 0x4052c0 0x404af0 \
  0x481d90 0x48d3a0 0x482740 0x4d44e0 0x406a90 \
  --annotations decompiled_fastfood2_named_v2/typed_packets/free_play_start.annotations.json \
  --json-out decompiled_fastfood2_named_v2/typed_packets/free_play_start.json \
  --out decompiled_fastfood2_named_v2/typed_packets/free_play_start.md

python3 tools/verify_typed_packet.py --expectations decompiled_fastfood2_named_v2/typed_packets/free_play_start.expectations.json
```

```text
typed packets: 1 packet(s), 10 records, 40 trace steps, 2 tables, 2 fixtures,
40/40 instruction prefixes match, 7/7 mutations rejected
```
