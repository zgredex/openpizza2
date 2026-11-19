# City

- Vtable: `0x55c500`
- Constructor: `City_ConstructFromName`
- Destructor: `City_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

## Virtual methods

| # | Method |
|---:|---|
| 0 | `City_Delete` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x14` | 4 | 1 | City_InitOfferSlots |
| `0x1c` | 4 | 1 | City_InitBuildings |
| `0x20` | 4 | 1 | City_InitBuildings |
| `0x24` | 4 | 1 | City_InitBuildings |
| `0x28` | 4 | 1 | City_InitBuildings |
| `0x48` | 4 | 1 | City_InitPopulation |
| `0xc1c` | 4 | 1 | City_InitPopulation |
| `0xdc4` | 4 | 1 | City_ConstructFromName |
| `0xfa8` | 4 | 4 | City_ConstructFromName, City_Destroy, City_InitBuildings, City_InitPopulation |
| `0xfc0` | 4 | 2 | City_Destroy, City_InitPopulation |
| `0xfdc` | 4 | 1 | City_Destroy |
| `0x10a4` | 4 | 1 | City_ConstructFromName |
| `0x10a8` | 4 | 1 | City_Destroy |
| `0x10ac` | 4 | 1 | City_ConstructFromName |
| `0x10b0` | 4 | 1 | City_ConstructFromName |
| `0x10b4` | 4 | 1 | City_ConstructFromName |
| `0x10b8` | 4 | 1 | City_ConstructFromName |
| `0x10bc` | 4 | 1 | City_ConstructFromName |
| `0x10c4` | 4 | 1 | City_ConstructFromName |
| `0x10c8` | 4 | 1 | City_ConstructFromName |
| `0x10cc` | 4 | 1 | City_ConstructFromName |
| `0x1148` | 4 | 1 | City_ConstructFromName |
| `0x114c` | 4 | 1 | City_ConstructFromName |
| `0x1150` | 4 | 1 | City_ConstructFromName |
| `0x1154` | 4 | 1 | City_ConstructFromName |

## Vtable references

- `City_Construct`
- `City_ConstructFromName`
- `City_Destroy`
