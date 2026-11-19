# ResourceFile-ID-7654 `.pak` format

Reverse engineered from `game/fastfood2.exe` with REA/Ghidra. The named loader
layer is exported in `pak_layer_final/functions/`: `Pak_Open` (`0x401af0`),
`Pak_DecodeIndex` (`0x401f30`), `Pak_FindEntry` (`0x402060`), and the resource
facade `Resource_Open` (`0x402290`). A standalone reader is in
`../tools/pak_tool.py`.

## Header (0x6c bytes)

| Offset | Type | Meaning |
|---|---|---|
| `0x00` | `char[0x20]` | magic `ResourceFile-ID-7654\n\r\x1a`, NUL padded |
| `0x20` | `char[0x40]` | `Created:<date>` text, NUL padded |
| `0x60` | `u32` | index size in bytes |
| `0x64` | `u32` | `100` in every shipped pak (loader rejects larger) |
| `0x68` | `u32` | `1` = obfuscated index (all shipped paks) |
| `0x6c` | `byte[index_size]` | encoded index |

## Index

Decode every byte `i` before parsing:

```python
decoded[i] = (((encoded[i] - (i & 0xff)) & 0xff) ^ 0xaa)
```

Then:

| Offset | Type | Meaning |
|---|---|---|
| `0x00` | `u32` | entry count |
| `0x04` | `entry[count]` | 0x14-byte entries |
| `4 + count*0x14` | `char[]` | NUL-terminated name table |

Entry (0x14 bytes):

| Offset | Type | Meaning |
|---|---|---|
| `+0x00` | `u32` | unknown metadata (`meta0`) |
| `+0x04` | `u32` | unknown metadata (`meta1`) |
| `+0x08` | `u32` | file size |
| `+0x0c` | `u32` | file offset relative to `0x6c` |
| `+0x10` | `u32` | name offset relative to the name table |

Actual file data:

```
offset = 0x6c + entry.rel_offset
size   = entry.size
```

No compression or per-entry encryption was observed: payload bytes are stored
contiguously after the index. The loader fixes up each name pointer and sorts the
in-memory entries by name for binary search; on-disk order need not be sorted.

## Validation

`tools/pak_tool.py info` on the shipped GOG paks:

| Pak | Size | Index | Entries | Payload bytes |
|---|---:|---:|---:|---:|
| `main.pak` | 50,439,167 | 156,500 | 3,168 | 50,282,547 |
| `update.pak` | 245,120 | 4,552 | 100 | 240,448 |
| `iso.pak` | 153,087,393 | 248,068 | 4,276 | 152,839,217 |
| `sound.pak` | 101,793,940 | 82,060 | 1,489 | 101,711,772 |
| `movie.pak` | 143,582,272 | 4,828 | 109 | 143,577,324 |

All **9,142** entries pass bounds checks and every name decodes to a valid path.
Full extraction produced 9,142 files / 447 MB.

## Tool

```bash
python3 tools/pak_tool.py info   game/Resources/main.pak
python3 tools/pak_tool.py list   game/Resources/main.pak --filter 'daten\\.*\.ini$' --sort
python3 tools/pak_tool.py extract game/Resources/main.pak extracted
```

Extraction normalizes `\` to `/`, preserves subdirectories, rejects `..` paths,
and writes raw entry bytes.

## Repacking

```bash
python3 tools/pak_tool.py list  game/Resources/main.pak --csv main.csv
python3 tools/pak_tool.py pack  extracted main_new.pak \
  --manifest main.csv \
  --only-manifest \
  --header-from game/Resources/main.pak
```

The repacker rebuilds the encoded index, recalculates all data offsets and writes
the payload in manifest order. `--header-from` preserves the original magic/date
header. A round-trip of `main.pak` preserves all 3,168 names, sizes and payload
bytes; the file is not byte-identical because the original archive leaves gaps in
its name table, which the game does not require.

## What this unlocked

- **Assets:** 4,276 iso sprites/animations, 1,489 sounds, 109 Bink movies,
  3,168 main-pak resources, and 100 update files.
- **Mission/campaign data:** `main.pak` contains `daten\<city>.ini` for all ten
  cities. These files define city name/country, rent/purchase/income modifiers,
  population and target-group preferences, difficulty, police count, campaign
  length, goal IDs (`ZIELE`), starting HQ/money, opponents, and briefing/debriefing
  text. A normalized table is in `mission_data.csv`; a city summary and field
  reference are in `MISSION_DATA.md`.
- **City maps:** `Isokarten\<city>.iso` and `Resources/iso.pak` (isometric tile
  data). `Isokarten\*.STY` are style definitions.
- **Save files:** the executable formats paths
  `save\games\save_%03d.piz`, `save\games\auto_%03d.piz`, `save\piz\%s.piz`,
  and `save\menu\%s.men`. The `.piz` **header and save-list layer** are documented
  in `PIZ_FORMAT.md`; the payload graph is not decoded yet. The writer starts at
  `SaveGame_Write` (`0x487520`) and calls `SaveGame_Serialize` (`0x487b50`).

## Unknowns

- `meta0`/`meta1` in each entry are not used by the extractor; their meaning is
  not established (possibly checksums, IDs or timestamps).
- The `header64 = 100` field is only checked as an upper bound by the loader.
- `Isodaten.idx` and `language.ldf` are separate formats and are not covered by
  this document.
- The `.piz` save serialization remains to be reversed from a sample.
