# Modding workflow

## 1. Unpack assets

```bash
python3 tools/pak_tool.py extract game/Resources/main.pak extracted
python3 tools/pak_tool.py extract game/Resources/iso.pak   extracted
python3 tools/pak_tool.py extract game/Resources/sound.pak extracted
python3 tools/pak_tool.py extract game/Resources/movie.pak extracted
python3 tools/pak_tool.py extract game/Resources/update.pak extracted
```

`extracted/` currently contains all 9,142 entries (447 MB): UI sprites, iso
sprites/animations, sounds, Bink movies, and text/data files.

## 2. Repack a `.pak`

```bash
# optional: capture the original order/metadata
python3 tools/pak_tool.py list game/Resources/main.pak --csv main.csv

# rebuild after editing files under extracted/
python3 tools/pak_tool.py pack extracted main_new.pak \
  --manifest main.csv \
  --only-manifest \
  --header-from game/Resources/main.pak
```

Notes:

- `--only-manifest` is important when packing from the mixed `extracted/` tree;
  without it, files belonging to other paks are appended. Alternatively extract
  each pak into its own directory first.
- Without `--manifest`, files are packed in sorted order with `meta0=meta1=0`.
- `--header-from` preserves the original magic/date header and sets the index
  size; data offsets are recalculated.
- The repacked archive is functionally valid: entry names, sizes and payload
  bytes match the source. It is **not necessarily byte-identical** to the
  original because the shipped archives leave gaps in the name table. The game
  loader only follows the per-entry name pointers, so compact naming is valid.
- Round-trip validation is done by re-opening the output with
  `pak_tool.py info/list` and comparing entries.

`.pak` layout is documented in `PAK_FORMAT.md`.

## 3. Export sprites

`.spr` files decode to RGBA PNGs (header, palette and alpha/RLE tokens are
documented in `SPR_NOTES.md`):

```bash
python3 tools/spr_tool.py info  extracted/sprites/pizzaimages/haare_f_08.spr
python3 tools/spr_tool.py export extracted extracted_png
python3 tools/spr_tool.py export extracted/pictures png_out --limit 20
```

The full export is already in `extracted_png/` (6,947 PNGs, 65 MB). There is no
PNG→`.spr` importer yet.

## 4. Edit localization

The string table is `game/language.ldf`, a flat `u32 count` + NUL-terminated
cp1252 strings file. See `LDF_FORMAT.md`.

```bash
python3 tools/ldf_tool.py dump game/language.ldf language.json
# edit language.json
python3 tools/ldf_tool.py pack language.json language.ldf
```

Keep the string order/count stable: the game indexes this table by ID. Preserve
`%s`/`%d` and UI markup such as `{c0,128,0}`, `{f1}`, `{t}`.

## 4. Edit campaign data

City/campaign definitions are `daten/<city>.ini` inside `main.pak` (extracted to
`extracted/daten/`). Fields and normalized values are documented in
`MISSION_DATA.md`; the CSV is `mission_data.csv`.

## 5. Install

Back up `game/Resources/*.pak` first, then replace the relevant archive with the
repacked file. Keep the original filenames (`main.pak`, `update.pak`, …).

## Current limits

- `.spr` → PNG export works for raw and alpha/RLE 16bpp sprites; 8bpp palette
  colors are best-effort. PNG → `.spr` import is not implemented yet.
- `.piz` save payloads are not decoded; only the save header is.
- `Isodaten.idx` and `.ani`/`.fnt` formats are not yet documented.
