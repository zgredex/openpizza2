# `language.ldf` string table

`game/language.ldf` is the game’s flat localized-string table. It is loaded by
`Language_LoadLDF` (`0x5145a0`) and indexed into globals by
`Language_MapStrings` (`0x5146d0`).

## Format

Little-endian, no compression:

| Offset | Type | Meaning |
|---|---|---|
| `0x00` | `u32` | string count |
| `0x04` | `char[]` | `count` NUL-terminated strings |
| EOF | — | immediately after the last terminator |

- Encoding: ANSI/cp1252 (German umlauts present).
- Strings are referenced by **index**, so the count and order must stay stable
  when editing.
- Placeholders such as `%s`, `%d`, `{c0,128,0}`, `{f1}`, `{t}` are interpreted by
  the UI; preserve them.
- Verified: 2,361 strings, 123,641 bytes, no trailing data.

## Tool

```bash
python3 tools/ldf_tool.py info  game/language.ldf
python3 tools/ldf_tool.py list  game/language.ldf --filter mission
python3 tools/ldf_tool.py dump  game/language.ldf language.json
# edit language.json
python3 tools/ldf_tool.py pack  language.json language.ldf
```

The `dump` → `pack` round-trip is byte-identical on the shipped file
(SHA-256 `b0d96b13b15b283b3beed2b52b9abfc0f857ff41dfc15e63e50d33f90acac2a6`).

## Notes

- `language.ldf` is loose in the game root, not inside a `.pak`.
- Mission/campaign `.ini` files also contain briefing/debriefing text; those are
  separate from this table and are documented in `MISSION_DATA.md`.
