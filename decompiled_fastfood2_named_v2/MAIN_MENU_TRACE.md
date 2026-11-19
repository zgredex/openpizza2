# Main menu reconstruction

The menu screen is `Screen_MainMenu` at `0x476920`, entered from screen state
`0x15`. It is the first screen rebuilt in the modern viewer.

## Screen construction

`Screen_MainMenu` calls:

```text
Window_CreatePictureWindow(UI, "Pe_Startscreen.TGA", callback 0x4ceb80)
UI_FindWindowByID(...) -> parent window
```

It then adds six text buttons with `TIMESFONT.fnt` and the
`TEXTPBTRANSPGELB_00.spr` panel tiles. The six labels are read from the
installed `language.ldf` using the indices in the table below; the loader
decodes the CP1252 string table from the install root. Every button uses
`Gadget_SetButtonColors(..., 0, 0, 0)` (black text) and
`Gadget_SetButtonTextLayout(..., 2, 0xcc, 0, 0, 0)`, which centers the label in
the 204-pixel row.

| Index | Control | Label | LDF index | x | y | Action |
|---:|---|---|---:|---:|---:|---|
| 0 | `0x3ee` | Start new game | `0x81d` | 595 | 6 | character select, screen `0x1c`, new-game flag 0 |
| 1 | `0x3ef` | Start free game | `0x762` | 595 | 48 | character select, screen `0x1c`, free-game flag 1 |
| 2 | `0x3f0` | Continue game | `0x876` | 595 | 91 | sub-start menu A, screen `0x19` |
| 3 | `0x3f1` | Options | `0x73b` | 595 | 133 | sub-start menu B, screen `0x1b` |
| 4 | `0x3f7` | Credits | `0x724` | 595 | 175 | `Movie_Play(credits_s.bik)` |
| 5 | `0x3f6` | Quit | `0x708` | 595 | 560 | post `WM_CLOSE` |

The callback at `0x4ceb80` receives notification code `1` and dispatches on
`control_id - 0x3ee` through a ten-entry jump table. The unresolved IDs
`0x3f2`..`0x3f5` are no-ops.

## Background and font assets

- `pictures/pe_startscreen.tga` is `800x600`, the exact asset named by
  `Screen_MainMenu`. `startscreen00.tga` is a localized logo alternate and is
  used only as a fallback if the named file is absent.
- `fonts/timesfont.fnt` is the original Times bitmap font.
- `sprites/textpbtranspgelb_00.spr` is the 3x3 button-panel tile set. The
  background already contains the visible six rows; the modern reconstruction
  keeps those rows and adds a keyboard/mouse focus marker.

### Button panel geometry

`UI_TextPanel_Construct` (`0x52d360`) expands
`TEXTPBTRANSPGELB_00.spr` into the nine files `_00`..`_08`. The files are
column-major states:

| State | Sprites | Use |
|---|---|---|
| normal | `_00`, `_03`, `_06` | cream idle button |
| hover | `_01`, `_04`, `_07` | yellow highlighted button |
| pressed | `_02`, `_05`, `_08` | alternate pressed button |

Each sprite is a 7..11 x 38..39 horizontal slice drawn on a 12x41 canvas.
`UI_ComputeElementRowExtent` (`0x52e230`) keeps the left/right slices at their
source widths and stretches the middle slice to the 204-pixel control width.
The resulting panel is 38 pixels tall. `UI_TextPanel_Construct` computes the
text inset as `(sprite canvas height 41 - TIMESFONT line height 23) / 2 = 9`,
which is why the 23-pixel text line is vertically centered in the 38-pixel
frame.

### `.fnt` layout

`Font_Load (0x535180)` reads:

| Offset | Size | Meaning |
|---:|---:|---|
| `0x000` | `0x0e0` | glyph widths, stored at 2x raster width |
| `0x0e0` | `0x0e0` | glyph heights |
| `0x1c0` | `0x0e0` | x offsets |
| `0x2a0` | `0x0e0` | y offsets |
| `0x380` | `0x1c0` | 224 little-endian compressed glyph byte counts |
| `0x540` | `0x0e0` | 224 advance widths |
| `0x620` | 4 | line height (low word), max width (high word) |
| `0x624` | rest | concatenated glyph RLE streams |

Each glyph stream contains `height` rows. A row consumes `width / 2` pixels:
`0x00 n` skips `n` pixels, `0x0f` is a solid pixel, and `0x01`..`0x0e` are
antialias coverage levels. `timesfont.fnt` reports line height 23 and max width
18; `A` is 16x14 at advance 16. The Rust decoder is
`crates/assets/src/fnt.rs`.

## Modern replay

```sh
cargo run -p pc2-app -- --menu --output main_menu.png
cargo run -p pc2-app -- --menu --menu-script 'down;down;enter' \
  --output menu_continue.png
```

```text
menu: background=pictures\pe_startscreen.tga 800x600
menu: font=fonts\timesfont.fnt line_height=23
menu: items=6
menu: item 0 label="Start new game" id=0x3ee x=595 y=6 w=204 h=38
menu: item 1 label="Start free game" id=0x3ef x=595 y=48 w=204 h=38
menu: item 2 label="Continue game" id=0x3f0 x=595 y=91 w=204 h=38
menu: item 3 label="Options" id=0x3f1 x=595 y=133 w=204 h=38
menu: item 4 label="Credits" id=0x3f7 x=595 y=175 w=204 h=38
menu: item 5 label="Quit" id=0x3f6 x=595 y=560 w=204 h=38
menu: selected=0 label="Start new game"
menu: selected=1 label="Start free game"
menu: selected=2 label="Continue game"
menu: action=ContinueGame id=0x3f0 label="Continue game"
menu: final_action=ContinueGame id=0x3f0
output: menu_continue.png
backend: Vulkan
vulkan: 800x600 readback, 0 byte mismatches
result: OK
```

Interactive controls: Up/Down or W/S select, Enter/Space activate, Esc exits.
The mouse hover uses the same button rectangles; left-click activates the
hovered row. Start new game and Start free game both open character selection;
Free then opens the rebuilt `Screen_FreePlaySetup` screen, whose Start launches
the branch at 10:55 with the committed Berlin scenario and profile. Continue,
Options and Credits show the status panel until their original sub-screens are
rebuilt.

![Rebuilt main menu](samples/main_menu.png)

`verify_all.py` checks all six labels, control IDs, original coordinates,
Continue and Quit dispatch, invalid-command rejection, the fixed screenshot
hash, and the Vulkan readback.

## Launch handoff

The default branch map is `game/Isokarten/Iso_Filiale_einf_klein.iso`. When the
viewer is started outside the repository, `resolve_branch_map` rewrites that
default under `--install` before it is passed to the child. Start new/free now
spawn `pc2-viewer --install ... --branch-map <resolved> --character-select
--window` (plus `--free-game` for Start free game); the character screen's
Start button then spawns the playable branch with the selected mode, profile
and the Free Play Setup city/settings (`--scenario`).
Spawning happens inside the menu event handler: success closes the menu, while a
failed spawn keeps the menu open and writes the error into the status panel.

Input is hit-tested from the last cursor position, so a click still selects the
button under the pointer after Up/Down keyboard navigation. Unknown menu replay
commands and out-of-range selections fail the headless command with a non-zero
exit.

## Confidence

- **Static:** `0x476920` screen creation, all six button labels and IDs, font
  path, control dimensions, callback dispatch and screen targets.
- **Controlled:** `.fnt` decoder against `timesfont.fnt`; exact control table
  test; deterministic 800x600 render; Continue/Quit replay.
- **Runtime pending:** original mouse/keyboard focus rendering, menu music
  (`mus_menue_start.wav`), the localized `startscreen00.tga` variant, and the
  two sub-start menus behind Continue and Options.
