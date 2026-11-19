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
| `0x04` | 4 | `field_04` | `0x4CBEBD` copy; `0x405220` AI reset; UI range -6..6 |
| `0x08` | 20 | `field_08_1c` | `0x40522A` clears six dwords for AI profiles |
| `0x20` | 28 | `field_20_38` | `0x4051B5..0x40520C` random AI fields |
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

Result: 9/9 cases matched.

```sh
python3 tools/emulate_freeplay_profiles.py \
  --json-out decompiled_fastfood2_named_v2/typed_packets/fixtures/freeplay_cash_multiplier.result.json
```

Cases cover the initializer, all six profile copies, the default/half/1.5x/zero
and negative multipliers, and two 32-bit wrap boundaries.

## Open questions

- The UI command procedure entry is absent from the retained decompile index.
- Profile `+0x20..+0x38` are random AI fields with no recovered meaning yet.
- No save/load pair was found for `0x57BCD8`.
- The three vtable-style calls in the UI procedure are unresolved.
