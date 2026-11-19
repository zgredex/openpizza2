# Trade-offer `City+0x8C` / `City+0x94` trace

The earlier hypothesis that these fields belonged to `MapObject` was wrong.
Raw assembly shows they are **City** fields.

## `this` is the City

`Game_ComputeTradeOffers` (`0x4D5DD0`, `__thiscall`) uses:

```text
[edi+0x94]        edi = this (saved at [esp+0x18])
[eax+0x8C]        eax = this
[ecx+edx*4+0xCC8] ecx = this, edx = param_5 (company slot)
```

Callers pass a City:

- `AI_ImproveSecurity` (`0x4FFAD0`):
  `city = IDMap_Lookup(Game+4, Game+0x2F4)`, then
  `Game_ComputeTradeOffers(city, plot, 2, ...)`.
- `Player_BuildStorage` (`0x4F7710`) uses `this+0xDC4`, a City counter loaded
  by `MapObjectList_Load`.
- `AI_FindBranchPlotNearOwn` uses `City+0xFAC/+0xFC0`.

## Static float writers

`City+0x8C` and `City+0x94` are produced by the city definition parser, not by
`MapObject`:

1. `CityDefinition_ParseIni` (`0x4DB430`) allocates `operator_new(0xC18)` and
   parses the shipped `daten/<city>.ini`.
2. INI key tuples are `[key, type, dest, count]`. Type 1 converts with
   `*0.02` (`50` = neutral):

   | INI key | struct dest | city field |
   |---|---|---|
   | `MIETEN` | `stack+0x424` | `City+0x8C` |
   | `GEDULT` | `stack+0x428` | `City+0x90` |
   | `KAUFPREIS` | `stack+0x42C` | `City+0x94` |
   | `EINKOMMEN` | `stack+0x430` | `City+0x98` |
   | `QUALITAET` | `stack+0x434` | `City+0x9C` |
   | `KOMFORT` | `stack+0x438` | `City+0xA0` |

   The parser struct starts at `stack+0x39C`, and `City_ConstructFromName`
   copies 0x306 dwords from it to `City+4` (`0x4D4593`), so struct offsets
   0x88/0x90 become `City+0x8C`/`City+0x94`.

3. `City_ConstructFromName` also defaults `City+0xCC8[0..5]` to **60** (neutral
   city adjustment) and `City+0xD40[0..5]` to 100.

Berlin INI (`extracted/daten/ber.ini`):

```text
MIETEN 65      -> City+0x8C = 1.3   (rent factor)
KAUFPREIS 70   -> City+0x94 = 1.4   (purchase factor)
```

## MapObject `+0x8C` (for completeness)

`MapObject+0x8C` is a child-record count: `MapObject_Save` writes it,
`MapObject_Load` reads it into a local but does not restore the field. It is
unrelated to the trade-off multiplier. The float reads in
`Game_ComputeTradeOffers` are `[this+0x8C]` with `this` = City.

## Exact rent/trade table

```text
type 1 special ids 0x84C..0x857 -> [300, 600, 1200]
type 3 special ids 0x840..0x84B -> [200, 400,  800]
object+0x4C == 0 -> no rent offer
rent  = trunc(table[index] * base)
rent  = trunc(rent * City[0x8C])
rent += trunc(rent * (1 + (60 - City[0xCC8][slot]) * 0.005))
special mission fields player[0xA8]: free +0x10C, half +0xFC, bonus +0x1E0
mission free/half/bonus -> 0 / 0.5 / 1.5
non-special: type 1 +0xC0/+0x120/+0x1A4, type 3/4 +0x15C/+0x14C/+0x230,
             type 2 fixed 1.0 (sell = type_base)
```

`Math_RoundFloat` (`0x54F140`) sets x87 rounding control to truncate toward
zero, so all conversions are `int()`, not round-half-even.

Security (type 2) has base=0 and value=0, so:

```text
buy = sell = trunc(6000 * City[0x94])
```

Berlin: 6000 * 1.4 = 8400.

## Calibration

```text
type 1 rent 0/1/2  -> 780 / 1560 / 3120
type 3 rent 0/1/2  -> 520 / 1040 / 2080
missions           -> 780 / 390 / 1170 / 0
nearby 2/1 special -> 1978
security Berlin    -> 8400
non-special type 1 -> buy 21028, sell 5000
```

Simulator: `trade_offer_price()`, `special_trade_offer()`,
`CityProfile.rent_trade_factor`, `CityProfile.purchase_trade_factor`.
