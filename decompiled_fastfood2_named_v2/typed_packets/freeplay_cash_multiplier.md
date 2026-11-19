# Free-play cash multiplier dependency packet

Executable SHA-256:
`18cfd32e0ac5d6d98162ec016e058a2b51808d9ca49ebee933ce3166ff9922fd`

Raw scanner output: `freeplay_cash_multiplier.scan.json`
Machine-readable packet: `freeplay_cash_multiplier.json`
Fixture: `fixtures/freeplay_cash_multiplier.result.json`
Verifier: `tools/verify_freeplay_cash_multiplier.py`

This path demonstrates the base-minus-offset recovery called out in the
dependency table: the final address `0x57B97C` appears nowhere in the
disassembly as a literal.  It is reached as `[eax-0x30]` with
`eax = 0x57B9AC` and as `[eax-0x18]` with `eax = 0x57B994`.

## 1. Globals

### `0x57B97C` — six cash-multiplier settings slots

| Site | Routine | Access | Width | Original instruction | Resolution |
|---|---|---|---:|---|---|
| `0x406B90` | `Settings_InitDefaults` | write 100 | 4 | `89 48 d0` `mov [eax-0x30],ecx` | `eax=0x57B9AC` |
| `0x4CBEB7` | `FreePlaySetup_InitWindow` | read | 4 | `8b 50 e8` `mov edx,[eax-0x18]` | `eax=0x57B994` |
| `0x4CD4AE` | unnamed free-play window procedure | write | 4 | `89 51 e8` `mov [ecx-0x18],edx` | `ecx=0x57B994` |

Initializer path:

1. `Settings_InitDefaults` zeroes `0x59` dwords from `0x57B8A8` to `0x57BA0B`.
2. Only when `Settings_LoadFromRegistry() == 0`, it enters the loop at
   `0x406B7F`.
3. `eax = 0x57B9AC`, `ecx = 100`, `esi = 0`.
4. Six iterations write `100` at `0x57B97C, 0x57B980, 0x57B984, 0x57B988,
   0x57B98C, 0x57B990`; write `0` at `0x57B994..0x57B9A8`; and write the
   `setl` flags at `0x57B9AC..0x57B9C0` (`1,1,0,0,0,0`).

## 2. Object layout

The six profiles start at `0x57BCD8` with stride `0xC0`.

| Offset | Width | Name | Evidence |
|---|---:|---|---|
| `0x00` | 4 | `cash_multiplier` | `0x48203D` direct read; `0x482089` indexed read; `0x481F01` default 100; UI range 70..990 |
| `0x04` | 4 | `characteristic_adjust` | free-play UI "Characteristics:" value; range -6..+6; `0x4821B4..0x482327` applies abs(value) random ±1 changes to AI Player `+0x3C..+0x50`, clamped -3..3 |
| `0x08` | 4 | `buyer` | CharacterSelect label at `0x411`, value at `0x418`; copied by `0x4C7B65`; Player `+0x3C`; CompanyOverview "Character values:" |
| `0x0C` | 4 | `gangsters` | CharacterSelect label at `0x412`, value at `0x419`; Player `+0x40` |
| `0x10` | 4 | `specialist` | CharacterSelect label at `0x413`, value at `0x41A`; Player `+0x44` |
| `0x14` | 4 | `politicians` | CharacterSelect label at `0x414`, value at `0x41B`; Player `+0x48` |
| `0x18` | 4 | `seller` | CharacterSelect label at `0x415`, value at `0x41C`; Player `+0x4C` |
| `0x1C` | 4 | `guard` | CharacterSelect label at `0x416`, value at `0x41D`; Player `+0x50` |
| `0x20` | 4 | `gender` | `0x4051B5` `Random_RangeFast(0,1)`; `0x40523D` `IDMap_GetRandomName`; `0x4822E5` writes Character `+0x24`; `UI_DrawOverlaySprites` `param_2==0` selects male sprite lists |
| `0x24` | 4 | `hair` | `0x4051CC` range `0x58557C-1`; `0x58557C` = min(HAARE_M `+0x88`, HAARE_F `+0xA4`); `0x4822EB` Character `+0x28`; UI `param_5` selects `+0x74/+0x90` |
| `0x28` | 4 | `eyes` | `0x4051DE` range `0x585580-1`; `0x585580` = min(AUGEN_M `+0x50`, AUGEN_F `+0x6C`); `0x4822F4` Character `+0x2C`; UI `param_4` selects `+0x3C/+0x58` |
| `0x2C` | 4 | `mouth` | `0x4051E9` range `0x585584-1`; `0x585584` = min(MUND_M `+0xC0`, MUND_F `+0xDC`); `0x4822FD` Character `+0x30`; UI `param_6` selects `+0xAC/+0xC8` |
| `0x30` | 4 | `head` | `0x405206` range `0x585588-1`; `0x585588` = min(HEAD_M `+0x18`, HEAD_F `+0x34`); `0x482306` Character `+0x34`; UI `param_3` selects `+0x04/+0x20` |
| `0x34` | 4 | `logo` | `0x405209` reads shuffled permutation `0x57B76C`; `0x482029/0x48202C` writes Company `+0x1E0`; `0x4A28F0` formats `LOGOS__%d.spr` with this `+1`; `0x4C7B7C` copies the selected logo |
| `0x38` | 4 | `color` | `0x40520C` reads shuffled permutation `0x57C25C`; `0x48200C/0x48201C` indexes the 8-entry color table `0x563874` and writes Company `+0x1DC`; `SetTextColor` consumes it; `0x4C7B81` copies the selected color |
| `0x3C` | 4 | `active` | `0x4CBEC8`, `0x40525C`, `0x481EFE` write; `0x481EA3`, `0x4CB494` compare |

Recovered C layout and asserts:

- `reconstructed/freeplay/freeplay_profiles.h`
- `reconstructed/freeplay/freeplay_profiles.c`
- `reconstructed/freeplay/test_freeplay_profiles.c`

```c
_Static_assert(sizeof(FreePlayProfile) == 0xC0, ...);
_Static_assert(offsetof(FreePlayProfile, cash_multiplier) == 0x00, ...);
_Static_assert(offsetof(FreePlayProfile, active) == 0x3C, ...);
_Static_assert(FREEPLAY_PROFILE_COUNT == 6, ...);
```

No save/load pair was found for this array; the packet keeps that as an open
question rather than assuming session-only state.

### Characteristic adjustment and character values

`+0x04` is the free-play "Characteristics:" value.  The UI clamps it to
`-6..+6` at `0x4CC973/0x4CC9C4`.  During scenario setup
(`0x4821B4..0x482327`) the game:

1. Loads it with `mov eax,[ecx-0x34]` where `ecx = profile+0x38`.
2. Uses the sign to choose `+1` or `-1`.
3. Repeats `abs(value)` times: picks a random character value `0..5`, adds the
   sign, and accepts the change only while the result stays inside `-3..3`.
4. Applies this only to AI players; the human player calls `Player_AIState_Init`.

The six base character values are named directly by the CharacterSelect screen:

| Profile offset | CharacterSelect label | Value control | Player offset |
|---|---|---|---:|---|
| `+0x08` | Buyer | `0x418` | `+0x3C` |
| `+0x0C` | Gangsters | `0x419` | `+0x40` |
| `+0x10` | Specialist | `0x41A` | `+0x44` |
| `+0x14` | Politicians | `0x41B` | `+0x48` |
| `+0x18` | Seller | `0x41C` | `+0x4C` |
| `+0x1C` | Guard | `0x41D` | `+0x50` |

The CompanyOverview page renders them as "Character values:" with Base, Extra
and Total columns (`0x2332..0x234D`); `CompanyOverview_FillTotals` adds
Player `+0x54..+0x68` (extra) to `+0x3C..+0x50` (base).

### Field semantics proof

The `+0x20..+0x38` fields are not opaque random values:

- `EmployeeAvatar_Construct` (`0x54B460`) loads the eight sprite families:
  `HEAD_M +0x04`, `HEAD_F +0x20`, `AUGEN_M +0x3C`, `AUGEN_F +0x58`,
  `HAARE_M +0x74`, `HAARE_F +0x90`, `MUND_M +0xAC`, `MUND_F +0xC8`.
- It sets the four random limits from the male/female list counts:
  - `0x585588` = head count
  - `0x585580` = eyes count
  - `0x585584` = mouth count
  - `0x58557C` = hair count
- `UI_DrawOverlaySprites` (`0x54B770`) branches on gender:
  - `param_2 == 0` male lists; otherwise female lists.
  - `param_3` = head, `param_4` = eyes, `param_5` = hair, `param_6` = mouth.
- `UI_ComposeOverlayWindowFromRecord` (`0x54BB00`) reads the same order from a
  character record: `+0x24` gender, `+0x34` head, `+0x2C` eyes, `+0x28` hair,
  `+0x30` mouth.
- `Game_InitScenario` (`0x4822E5..0x48230C`) copies profile
  `+0x20..+0x30` into Character `+0x24..+0x34`.
- `0x57B76C` and `0x57C25C` are eight-entry permutations initialized to `0..7`
  and shuffled before AI generation. Profile `+0x34` becomes Company `+0x1E0`
  (logo) and `+0x38` indexes the color table `0x563874` for Company `+0x1DC`.

### Copy and UI rings

`FreePlaySetup_InitWindow` at `0x4CBEB2..0x4CBED1` copies the three parallel
settings arrays into six profiles:

- `0x4CBEBD`: `[ecx-4] = [eax-0x18]` → profile `+0x00`
- `0x4CBEC3`: `[ecx] = [eax-4]` → profile `+0x04`
- `0x4CBEC8`: `[ecx+0x38] = [eax+0x14]` with `ecx=0x57BCDC` → profile `+0x3C`

The reverse copy at `0x4CD4AE/0x4CD4B7/0x4CD4BF` writes profile `+0x00`,
`+0x04` and `+0x3C` back into `0x57B97C`, `0x57B994` and `0x57B9AC`.

UI adjustment commands in the unnamed procedure:

| Site | Effect | Clamp |
|---|---|---|
| `0x4CC8CB` / `0x4CC8DC` | profile `+0x00` -= 10 | minimum 70 at `0x4CC8E3` |
| `0x4CC91D` / `0x4CC92E` | profile `+0x00` += 10 | maximum 990 at `0x4CC938` |
| `0x4CC973` / `0x4CC982` | profile `+0x04` -= 1 | minimum -6 at `0x4CC989` |
| `0x4CC9C4` / `0x4CC9D3` | profile `+0x04` += 1 | maximum 6 at `0x4CC9DA` |

## 3. Lookup tables

Not applicable to this path.  The values are fixed parallel arrays and a
six-entry profile array, not a keyed table with an index guard and fallback.

## 4. x87 rounding

The starting-cash formula is integer arithmetic followed by an integer-to-double
store:

- `0x482043 mov eax,0x51EB851F`
- `0x482048 imul ecx,DWORD PTR [esp+0x18]`
- `0x48204D imul ecx`
- `0x48204F sar edx,0x5`
- `0x482057 add edx,eax` (sign correction)
- `0x482063 fild DWORD PTR [esp+0x1c]`

No control-word change occurs in this fragment.  The width-specific detail is
the 32-bit `imul` wrap before the signed `/100`; it is exercised by the
`65536 * 65536` and `65536 * 50000` cases.

## 5. Indirect calls

No indirect call exists in the three selected ranges.  The enclosing unnamed
free-play window procedure has vtable-style calls at `0x4CD30B`, `0x4CD376`
and `0x4CD38B`; the packet records them as unresolved rather than guessing a
receiver or slot.

## Fixture

`tools/emulate_freeplay_profiles.py` compiles a Unicorn harness and runs three
original byte ranges:

- `init`: `0x406B7F..0x406BA7`
- `copy`: `0x4CBEB2..0x4CBED8`
- `cash`: `0x48203D..0x482063`
- `appearance`: `0x4822DF..0x48230F`
- `logo-color`: `0x48200C..0x482032`

Result: 11/11 cases matched.

```sh
python3 tools/emulate_freeplay_profiles.py \
  --json-out decompiled_fastfood2_named_v2/typed_packets/fixtures/freeplay_cash_multiplier.result.json
```

Cases cover the initializer, all six profile copies, the default/half/1.5x/zero
and negative multipliers, two 32-bit wrap boundaries, the profile-to-Character
appearance copy, and the logo/color mapping into Company `+0x1E0/+0x1DC`.

## Open questions

- The UI command procedure entry is absent from the retained decompile index.
- No save/load pair was found for `0x57BCD8`.
- The three vtable-style calls in the UI procedure are unresolved.
