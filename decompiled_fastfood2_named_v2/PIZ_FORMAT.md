# Pizza Connection 2 `.piz` save format (header layer)

Reverse engineered with REA/Ghidra from `game/fastfood2.exe`. The save path is
`save\games\save_%03d.piz` (manual) or `save\games\auto_%03d.piz` (autosave);
recipe/menu files use `save\piz\*.piz` and `save\menu\*.men`.

Named save-layer pseudocode is exported in `save_layer_final/` and
`save_layer_enum_final/`.

| Address | Function | Role |
|---|---|---|
| `0x487520` | `SaveGame_Write` | builds the header, opens the file, calls the serializer |
| `0x487b50` | `SaveGame_Serialize` | writes the payload section graph |
| `0x4a1570` | `SaveGame_ReadHeaderEntry` | reads 0xF0 bytes, validates magic, builds save-list text |
| `0x4a14c0` | `SaveGame_CompareTime` | sorts saves by `SYSTEMTIME` |
| `0x4a1940` | `SaveGame_Scan` | adds autosave + manual saves to the list |
| `0x4a1450` | `SaveGame_AnyExist` | checks for `save_*.piz` / `auto_*.piz` |
| `0x4a13e0` | `SaveGame_NextFreeSlot` | finds the first free save slot |

## Header — 0xF0 bytes

Little-endian. Strings are fixed-size, NUL-terminated, ANSI/cp1252.

| Offset | Type | Meaning |
|---|---|---|
| `0x00` | `char[64]` | save title. Manual saves use the user label; autosaves use `auto_<date> <time>` |
| `0x40` | `char[64]` | company/player name |
| `0x80` | `char[64]` | city name |
| `0xC0` | `u8` | active company count (writer loops six slots) |
| `0xC1` | `u8[7]` | company flags: `0` empty, `1` current player, `2` other |
| `0xC8` | `u32` | game calendar field 1 |
| `0xCC` | `u32` | game calendar field 2 |
| `0xD0` | `u32` | game calendar field 3 |
| `0xD4` | `u32` | game calendar field 4 |
| `0xD8` | `SYSTEMTIME` (8 × `u16`) | real save timestamp: year, month, day-of-week, day, hour, minute, second, millisecond |
| `0xE8` | `u32` | version = `0x11` |
| `0xEC` | `u32` | magic = `0x13738317` |

The four `0xC8`–`0xD4` values come from the game calendar object
(`0x48b3c0`/`0x48b3f0`). Their exact units are not fully established; they are
distinct from the `SYSTEMTIME` at `0xD8`.

## Payload

The **full field-level writer order** is now decoded in
[`SAVE_SCHEMA.md`](SAVE_SCHEMA.md) and [`save_schema.json`](save_schema.json):
36 save/serializer functions, 368 explicit fields, 16,342 fixed bytes, and
27 exact Save↔Load field-sequence matches.

`SaveGame_Serialize` writes, in this observed order:

| Offset | Content |
|---|---|
| `0xF0` | 32-byte **section directory** (8 dwords), written last |
| `0x110` | `u32` start marker `0x2E` |
| `0x114` | `0x5B8`-byte global game block (`DAT_0057bb20`) |
| — | `0x20` bytes at game object `+0x298` |
| — | `0x20` bytes at game object `+0x2B8` |
| — | 20 `u32` scalar fields (`+0x2D8` … `+0x368`, `+0x2D90`) |
| — | 12 subsystem serializers (ingredient panel, city/company list, advertising, market share, company overview, statistics, personnel, branch flags/design/menu, warehouse) |
| — | `GameCalendar_Save`, `UI_BriefingList_Save`, `World_LoadNameIndexTable` |
| — | counted `IsoMap` list: `u32 count`; each `u32 id` + `IsoMap_Save` |
| — | counted `Character` list: `u32 count`; each `u32 id` + `Character_Save` |
| — | counted `City`/map-object list: `u32 count`; each `City_Construct`/`MapObjectList_Load` record |
| — | counted `Person` list: `u32 count`; each `u32 id` + `PersonList_Save` |
| — | counted `Car` list: `u32 count`; each `u32 id` + `CarList_Save` |
| — | 6 player slots: `u32 present` + `Player_Save` |
| — | 6 company slots: `u32 present` + `CompanyData_Save` |
| — | `AI_CompanySlots_Save`, selected player/company refs, runtime list |
| — | `u32` end marker `0x2A` |
| — | seek to `0xF0`, rewrite 32-byte directory, seek to end |

### The 0xF0 directory is not zero

Earlier notes called the 32-byte block “reserved zero”. The writer actually fills
it with section end offsets and rewrites it after the payload:

| Index | Meaning | Writer evidence |
|---:|---|---|
| 0 | end offset after the map-object/city list | line 112 |
| 1 | end offset after the iso-map list | line 88 |
| 2 | end offset after the character list | line 100 |
| 3 | end offset after the six player slots | line 152 |
| 4 | end offset after the car list | line 136 (`local_10`) |
| 5 | end offset after the six company slots | line 168 (`local_c`) |
| 6 | end offset after the person list | line 124 (`local_8`) |
| 7 | end of payload | line 184 (`local_4`); also the load-progress denominator |

`Game_LoadSaveGame` reads these 32 bytes first and validates each subsequent
section boundary with `Stream_GetReadPosition` before moving to the next counted
list. Index 7 is the payload end and doubles as the load-progress denominator.

The payload is a graph of serializers, not one flat struct. `SAVE_SCHEMA.md`
lists every writer’s field order, offset, size, type hint, nested serializer and
loader pairing.

## Validation

- `SaveGame_ReadHeaderEntry` reads exactly `0xF0` bytes and accepts the file only
  when the `u32` at `0xEC` equals `0x13738317`.
- `SaveGame_CompareTime` compares `SYSTEMTIME` year, month, day, hour, minute and
  second to sort the save list.
- Autosaves and manual saves share the same header.
- The 32-byte reserved block is zero in this build; its purpose is unknown.

No real `.piz` sample was present in the GOG installer, so the header was derived
statically. `tools/piz_tool.py` includes a synthetic round-trip test:
`samples/synthetic.piz`.

## Tool

```bash
python3 tools/piz_tool.py info  path/to/save_000.piz
python3 tools/piz_tool.py list  path/to/save/games
python3 tools/piz_tool.py synth /tmp/test.piz --title "Test" --company "Pizza Inc." --city London
```

`info` prints title, company, city, player slots, game date, system time, version,
magic, start marker and payload size. `--json` is available.

## Limits

- Header, save-list layer, directory and field-level payload schema are decoded;
  variable-length sub-records (strings, sprite/actor records) are catalogued by
  their writer calls but not byte-expanded.
- No checksum was identified; the directory is offsets, not a checksum.
- `.men` menu files and `save\piz\*.piz` recipe files may use other layouts.
- A real save file is needed to validate payload offsets at runtime.
