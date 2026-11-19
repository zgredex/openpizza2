# `.tab` tables

Two shipped tables use the `.tab` container.

## `Size.tab`

Loader: `Ingredient_LoadMarketTable` (`0x4E4930`), resource name `Size.tab`.

- 86 records × **128 bytes** = **11,008 bytes**.
- Each record is four layers of eight `u16` pairs:
  `layer[4] slot[8] (width, height)`.
- Layer values feed the ingredient record's `+0x08`/`+0x48` size arrays.
  They are sprite sizes for the four menu/portion tiers.

Example (`extracted/daten/size.tab`, record 0):

```text
layer 0 slot 0 = (139, 140)
layer 0 slot 1 = (140, 139)
...
layer 3 slot 7 = (138, 141)
```

## `Ingredients.tab`

Loader: `Recipe_StreamConstruct` (`0x511BE0`), resource name
`Ingredients.tab`.

- **4,579,328 bytes** = **35,776 blocks** of 128 bytes.
- Each block is **32 `u16` coordinate pairs** `(x, y)` for one topping
  placement set.
- Block index formula from the loader:

```text
block = base(0..12)
      + (variant(0..3) + (quality + category*4)*8) * 13
```

The recipe constructor seeks to `block * 128 + position * 4` and reads the
pair. `base` selects the pizza/dough shape, `variant` the rotation/size,
`quality`/`category` select the ingredient tier.

Example block 0:

```text
(197, 22), (198, 22), (151, 27), (103, 43), ...
```

## Tool

```bash
python3 tools/tab_tool.py info extracted/daten/size.tab --kind size
python3 tools/tab_tool.py info extracted/daten/ingredients.tab --kind ingredients
python3 tools/tab_tool.py size-json extracted/daten/size.tab size.json
python3 tools/tab_tool.py size-csv  extracted/daten/size.tab size.csv
python3 tools/tab_tool.py block extracted/daten/ingredients.tab --index 0
```

Tests: `tests/test_tab_tool.py` — **5/5 pass** (exact sizes, block count,
first/last block access, CSV shape).

## Market records

The 86 market records are created by `Ingredient_LoadMarketTable` from
`Size.tab`, then patched by `Game_SetBuildingDesc` (`0x4E4860`):

- `+0xA8` byte: category/colour index
- `+0xAC..+0xB8`: four quantity tiers used by `PlayerStats_Reset`
- `+0xC0`: **double price**, consumed by
  `Market_ComputeWeightedAveragePrice` (`0x48C060`) and
  `Game_GetPlayerWeightedStat` (`0x50FE70`)

`market_table.json` stores all 86 records with exact prices, quantity tiers,
and `Size.tab` dimensions.
