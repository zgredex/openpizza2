# Character selection screen

`Screen_CharacterSelect` (`0x46dbd0`) is the original next screen after
**Start new game** / **Start free game**. REA establishes the background,
control table and callback dispatch.

## Screen construction

The screen loads:

- `pictures/pe_charakterauswahl.tga` at 800x600
- `fonts/timesfont.fnt`, `fonts/times14.fnt`, `fonts/verdana8.fnt`
- `sprites/pb22_00.spr`, `pb24_00.spr`, `pb26_00.spr`, `pb27_00.spr`
- `sprites/fotorahmen00.spr`, `fotodummy00.spr`,
  `geschlecht_m_00.spr`, `geschlecht_w_00.spr`
- `sprites/playlog_2_01_00.spr`, `logofenster.spr`
- `sprites/leuchtfeld_00_00.spr`, `sl02_00.spr`
- the yellow and green `TEXTPBTRANSP*_00..08.spr` button panel tiles

The visible text controls recovered from `0x46dbd0` are:

| Control | Position | Width | Label / role |
|---|---:|---:|---|
| `0x420` | 13, 5 | 560 | Select player character |
| `0x422` | 608, 5 | 180 | Enterprises: |
| `0x41f` | 259, 77 | 310 | Characteristics: |
| `0x40b` | 44, 304 | 180 | Player's name: |
| `0x409` | 609, 304 | 180 | Enterprise name: |
| `0x410`–`0x40d` | 91, 140/172/206/239 | 83 | Hair / Eyes / Mouth / Chin |
| `0x411`–`0x416` | 323, 140/173/207/239/273/305 | 133 | Buyer / Gangsters / Specialist / Politicians / Seller / Guard |
| `0x418`–`0x41e` | 501, 140/173/207/239/273/305/360 | 40 | attribute values |
| `0x406` | 609, 425 | 180 | Level of difficulty |
| `0x407` | 617, 461 | 175 | difficulty slider (`SL02_00.spr`) |
| `0x408` | 609, 478 | 180 | Very easy |
| `0x423` | 655, 208 | 83 | Logo |
| `0x424` | 655, 239 | 83 | color |
| `0x434` | 595, 509 | 204x38 | To main menu |
| `0x435` | 595, 551 | 204x38 | Start game |

The appearance rows use `PB22/PB24` arrows around the four labels. The
attribute rows use `PB26/PB27` arrows around the six labels and value column.
The right panel has the selected portrait and the `Logo`/`color` rows.

The six labels and two button labels are read from the installed
`language.ldf` at indices `0x879`, `0x8a9`, `0x730`, `0x735`, `0x767`,
`0x74b`, `0x836`, `0x8b4`, `0x8be`, `0x8dc` and `0x877`.

## Actions

The `0x4c75a0` callback handles the screen. The appearance arrows operate on `DAT_0057dda0` (hair), `DAT_0057ddfc`
(eyes), `DAT_0057ddb8` (mouth) and `DAT_0057dda4` (head). Gender buttons at
`0x43a`/`0x43b` set `DAT_0057ddac`; each change calls the face compositor.
The six attribute arrows adjust `DAT_0057dd48..` in the original and maintain
the total at `0x41e`. Logo and color arrows at `0x3f6..0x3f9` select one of the
8x8 `PLAYLOG_%d_0%d_00` portraits.

The two bottom buttons are:

- `0x434` **To main menu** — returns to `Screen_MainMenu`
- `0x435` **Start game** — starts the playable branch

The modern screen supports Up/Down or W/S, Enter/Space, Esc, and mouse
hover/click. Arrow, gender and text-field controls use the original 3-state
sprite sets for normal/hover/pressed feedback. Hovering a control displays the
matching original help string from `language.ldf` in the 0x429 help area.

Back and Start launch their destinations as separate viewer processes so winit
never has to recreate an event loop. A failed launch leaves the screen open
with an error status.

## Start profile handoff

The `0x4c7a5b` Start handler copies the selected gender, face indices, logo,
color, difficulty, six attributes, player name and enterprise name into the
character/company globals (`0x57b938..`, `0x57b8f4..`, `0x57b8b0`, `0x57b8ac`,
`0x57bb24`, `0x57b94c`, `0x57b8f8`, `0x57b8b8`) before changing the screen
state. It checks the free-game flag at `0x57bb20`: free games go to screen
`0x18`, campaigns to `0x16`.

The reconstructed Start action serializes the same fields plus the campaign/free
mode into `--character-profile` when launching the branch viewer.
`pc2_sim::World` stores the typed `CharacterProfile` in its snapshot, and the
branch overlay displays `PLAYER`, `COMPANY`, and `MODE`, so the values survive
the process transition and snapshot round-trip.

## Free Play Setup (screen `0x18`)

The dispatcher at `0x4052c0` sends a free game to `Screen_FreePlaySetup`
(`0x472da0`) and calls `FreePlaySetup_InitWindow` (`0x4cbcd0`); a campaign goes
to `Screen_MissionBriefing` (`0x474df0`). The reconstructed flow now inserts a
distinct Free Play Setup process between Character Select and gameplay:
Character Select Start launches `pc2-viewer --free-play-setup --window`, and
that screen's Start launches the branch with the committed profile/scenario.

The reconstructed screen loads `pictures/pe_freies_spiel.tga` at 800x600,
`fonts/timesfont.fnt` and the original `textpbtranspgelb` panel tiles. It shows
the Berlin city/map and the committed population, length, difficulty, starting
capital, opponents, player and enterprise. Its controls use the same bottom
layout as the character screen:

| Control | Position | Action |
|---|---:|---|
| `0x4e2` | 595, 509 | Back, sets screen state `0x15` (main menu) at `0x4cd2b9` |
| `0x4e3` | 595, 550 | Start, sets screen state `0x17` at `0x4cd33d` |

The screen's callback is the code immediately after `0x4cc640`. Its Start
handler writes the setup globals and then dispatches to gameplay. The Start
branch at `0x4cd3aa..0x4cd4cc` commits:

| Original | Value | Stored as |
|---|---|---|
| `DAT_0057bb48/4c/50` | three opponent slots | `DAT_0057b9d0/d4/d8` |
| `DAT_0057bb28` | population | `DAT_0057b9c8` |
| `DAT_0057bb2c` | game length | `DAT_0057b9cc` |
| `DAT_0057bb24` | difficulty | `DAT_0057b8b4` |
| `DAT_0057bb40` | selected map-list index | index into `DAT_0057de38` |
| map record `+0x40` | city short name | `DAT_0057b9c4` and `DAT_0057bb44` |

`MapList_LoadAllMapDefinitions` (`0x4cd960`) scans `daten\*.ini`. The first
entry is `ber.ini`, whose `SHORT` is `ber`; `City_ConstructFromName`
(`0x4d44e0`) then builds `ber.ini` and `ber.iso` from that name. The shipped
`game/Isokarten/Ber.iso` is the corresponding city map. `extracted/daten/ber.ini`
records `STARTGELD 70000`, `SPIELZEIT 3`, `BEVOELKERUNG 260` and
`GEGNERANZAHL 2` for campaign play.

`Settings_InitDefaults` (`0x406a90`) supplies the untouched default
free-play settings: population `250`, game length `11`, opponent slots
`-1/-1/-1`, and difficulty `0` (the registry path may overwrite the latter).
The remaining new-game character values are generated by the original random
player path; the Rust preview keeps deterministic defaults until that path is
adopted.

`Game_InitScenario` (`0x481d90`) uses `DAT_0057bb44` as the city name and
`DAT_0057bb28` as the free-play population. Difficulty is consumed by
`Game_GetStartingCapital` (`0x48d3a0`):

| Difficulty | Starting capital |
|---:|---:|
| 0 | 1,000,000 |
| 1 | 500,000 |
| 2 | 200,000 |
| 3 | 100,000 |
| 4 | 75,000 |
| 5 | 50,000 |
| 6 | 40,000 |
| 7 | 30,000 |
| 8 | 25,000 |
| 9 | 22,000 |
| 10 | 20,000 |

Campaign player capital is the city's `STARTGELD` instead. Difficulty also
feeds `Game_InitCompanySlots` (`0x4f6e70`) as the verified
`difficulty * 6 .. difficulty * 9` company-slot roll.

### Rust initialization

`pc2_sim::ScenarioSetup` carries the committed city (`ber`), display name
(`Berlin`), map (`Ber.iso`), population, game length and opponent slots
alongside `CharacterProfile`. `World::with_profile` plus `World::with_scenario`
apply the verified starting capital, store both structs in `WorldSnapshot`, and
the branch overlay shows:

```text
CITY: BERLIN (BER)   POP: 250   LENGTH: 11Y   OPP: -1/-1/-1
```

The reconstructed setup screen is deterministic:

```sh
cargo run -p pc2-app -- --free-play-setup \
  --character-profile 'mode=free;...;difficulty=9;player=Ada;enterprise=Ada Pizza' \
  --scenario 'mode=free;city=ber;name=Berlin;map=Ber.iso;population=250;length=11;opponents=-1,-1,-1' \
  --output free_play_setup.png
```

![Free Play Setup screen](samples/free_play_setup.png)

Its Start action launches the branch with the same profile/scenario. The
headless chain command exercises the real menu, character and setup action
objects and compares its world with the replay world:

```sh
cargo run -p pc2-app -- --free-play-chain \
  --character-profile 'mode=free;...;difficulty=9;...' \
  --scenario 'mode=free;city=ber;name=Berlin;map=Ber.iso;population=250;length=11;opponents=-1,-1,-1'
```

```text
free-play-chain: menu=StartFreeGame
free-play-chain: character=Start profile=mode=free;...;difficulty=9;...
free-play-chain: setup=Start city=ber map=Ber.iso starting_capital=22000
free-play-chain: world={... "cash":22013.420525 ... "sales":1 ...}
free-play-chain: replay={... "cash":22013.420525 ... "sales":1 ...}
free-play-chain: MATCH sales=1 cash=22013.420525
```

The windowed chain was also run through Menu Start Free Game -> Character
Select Start -> Free Play Setup Start -> branch. The branch overlay reached the
same first sale (`11:10`, cash `22013.42`, stock `399/400`, sales `1`), and its
final 11:15 snapshot matched the headless replay JSON exactly.

![Free Play chain first sale](samples/free_play_chain_first_sale.png)

The windowed branch and the headless replay both call the same
`initialize_world` and `apply_world_command` helpers. The replay therefore
decodes `--character-profile` and `--scenario` instead of ignoring them.

```text
profile: mode=FreeGame ... difficulty=9 ...
scenario: mode=FreeGame city=ber name=Berlin map=Ber.iso population=250
          length=11 opponents=[-1, -1, -1] starting_capital=22000
sim: {"open":true,...,"cash":22013.420525,"stock":399.000000,...,"sales":1,...}
```

The same command run with `--window --frames 1 --playable-script` produces the
same `sim:` line, so the visible branch and the replay start from one state.
Campaign uses the same path with `ScenarioSetup::campaign_berlin()` and the
city's verified 70,000 starting capital.

## Replay

```sh
cargo run -p pc2-app -- --character-select --output character_select.png
cargo run -p pc2-app -- --character-select \
  --character-script 'down;enter' --output character_start.png
```

```text
character: background=pictures\pe_charakterauswahl.tga 800x600
character: button 0 label="To main menu" id=0x434 x=595 y=509 w=204 h=38
character: button 1 label="Start game" id=0x435 x=595 y=551 w=204 h=38
character: selected=0 label="To main menu"
character: action=Start id=0x435 label="Start game"
character: final_action=Start
vulkan: 800x600 readback, 0 byte mismatches
result: OK
```

![Character selection screen](samples/character_select.png)

`verify_all.py` checks the screen render, Back/Start coordinates, the Start
action, invalid-command rejection and the fixed screenshot hash.

## Face compositor

`CharacterSelect_DrawPortrait` calls `FUN_0054b970 -> FUN_0054b770`, which
selects the male or female arrays and draws four layers in this order:

1. `HEAD_*`
2. `MUND_*` (mouth)
3. `AUGEN_*` (eyes)
4. `HAARE_*` (hair)

The Rust screen loads all ten variants of each layer for both genders from
`sprites/pizzaimages/` and composites them into the 60x50 preview. Each sprite
is placed with its header hotspot at `0x0b`/`0x0d`; `Sprite_Draw` adds those
offsets, and the 60x50 target clips wider strips such as the 120-pixel female
head sprite. The right portrait is selected independently from the 8x8
`PLAYLOG_*` table.

The player and enterprise name fields are editable in the modern screen. The
difficulty slider uses the recovered 0..10 range and the language table's
`Dishwasher`..`Godfather` labels after a change.

## Still pending

The recovered text colors are black for labels, `0xff` red for negative
attributes, `0xa000` green for positive attributes, and `0x868686` for empty
input placeholders. The initial new-game character values are generated by the
original random-player path; the reconstruction uses deterministic preview
defaults. Difficulty now has two verified consumers (starting capital and the
`Game_InitCompanySlots` roll). The six Player fields at `+0x3c..+0x50` are
copied, saved and loaded; `Game_GetPlayerStaff` (`0x501df0`) also reads
`+0x40` and `+0x50` in its band sum, but no sale-economy formula is established,
so none is invented. The Mission Briefing screen
(`0x16`) is not redrawn yet, although campaign launches already use the shared
Free Play Setup initialization path. Original runtime comparison remains open.

## Confidence

- **Static:** background, font and sprite paths, all text/sprite positions,
  button IDs and callback dispatch from `0x46dbd0` and `0x4c75a0`.
- **Controlled:** deterministic 800x600 render, Back/Start replay, invalid
  command rejection, headless Vulkan readback.
- **Runtime pending:** original face composition, exact font colors, editable
  name fields, attribute/difficulty interactions and original-game comparisons.
