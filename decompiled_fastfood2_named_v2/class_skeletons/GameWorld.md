# GameWorld

- Vtable: `0x55c44c`
- Constructor: `GameSession_Construct`
- Destructor: `GameWorld_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: renamed GameState -> GameWorld; slot0 and pointer symbol are GameWorld_Delete; constructor symbol is GameSession_Construct (base/sibling name)

## Virtual methods

| # | Method |
|---:|---|
| 0 | `GameWorld_Delete` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x88` | 4 | 1 | GameState_Destruct |
| `0x90` | 4 | 2 | GameSession_Construct, GameState_Destruct |
| `0x94` | 4 | 2 | GameSession_Construct, GameState_Destruct |
| `0x98` | 4 | 1 | GameSession_Construct |
| `0x9c` | 4 | 1 | GameSession_Construct |
| `0xa0` | 4 | 2 | GameSession_Construct, GameState_Destruct |
| `0xa4` | 4 | 2 | GameSession_Construct, GameState_Destruct |
| `0xa5` | 1 | 1 | GameSession_Construct |
| `0x218` | 4 | 1 | GameSession_Construct |
| `0x21c` | 4 | 1 | GameSession_Construct |
| `0x220` | 4 | 1 | GameSession_Construct |
| `0x23c` | 4 | 2 | GameSession_Construct, GameState_Destruct |
| `0x240` | 4 | 2 | GameSession_Construct, GameState_Destruct |
| `0x244` | 4 | 2 | GameSession_Construct, GameState_Destruct |
| `0x248` | 4 | 2 | GameSession_Construct, GameState_Destruct |
| `0x24c` | 4 | 1 | GameSession_Construct |
| `0x250` | 4 | 1 | GameSession_Construct |
| `0x254` | 4 | 1 | GameSession_Construct |
| `0x258` | 4 | 1 | GameSession_Construct |
| `0x25c` | 4 | 1 | GameSession_Construct |
| `0x260` | 4 | 1 | GameSession_Construct |
| `0x264` | 4 | 1 | GameSession_Construct |
| `0x268` | 4 | 1 | GameSession_Construct |
| `0x26c` | 4 | 1 | GameSession_Construct |
| `0x270` | 4 | 1 | GameSession_Construct |
| `0x274` | 4 | 1 | GameSession_Construct |
| `0x278` | 4 | 1 | GameSession_Construct |
| `0x27c` | 4 | 1 | GameSession_Construct |
| `0x280` | 4 | 1 | GameSession_Construct |
| `0x284` | 4 | 1 | GameSession_Construct |
| `0x290` | 4 | 2 | GameSession_Construct, GameState_Destruct |
| `0x29c` | 4 | 1 | GameSession_Construct |
| `0x2a0` | 4 | 1 | GameSession_Construct |
| `0x2a4` | 4 | 1 | GameSession_Construct |
| `0x2a8` | 4 | 1 | GameSession_Construct |
| `0x2ac` | 4 | 1 | GameSession_Construct |
| `0x2b0` | 4 | 1 | GameSession_Construct |
| `0x2b4` | 4 | 1 | GameSession_Construct |
| `0x2d8` | 4 | 1 | GameSession_Construct |
| `0x2dc` | 4 | 1 | GameSession_Construct |
| `0x2e0` | 4 | 1 | GameSession_Construct |
| `0x2e4` | 4 | 1 | GameSession_Construct |
| `0x2e8` | 4 | 1 | GameSession_Construct |
| `0x2ec` | 4 | 1 | GameSession_Construct |
| `0x2f0` | 4 | 1 | GameSession_Construct |
| `0x2f4` | 4 | 1 | GameSession_Construct |
| `0x2f8` | 4 | 1 | GameSession_Construct |
| `0x2fc` | 4 | 1 | GameSession_Construct |
| `0x300` | 4 | 1 | GameSession_Construct |
| `0x33c` | 4 | 1 | GameSession_Construct |
| `0x340` | 4 | 1 | GameSession_Construct |
| `0x344` | 4 | 1 | GameSession_Construct |
| `0x348` | 4 | 1 | GameSession_Construct |
| `0x34c` | 4 | 1 | GameSession_Construct |
| `0x350` | 4 | 1 | GameSession_Construct |
| `0x354` | 4 | 1 | GameSession_Construct |
| `0x358` | 4 | 1 | GameSession_Construct |
| `0x35c` | 4 | 1 | GameSession_Construct |
| `0x360` | 4 | 1 | GameSession_Construct |
| `0x364` | 4 | 1 | GameSession_Construct |
| `0x368` | 4 | 1 | GameSession_Construct |
| `0x384` | 4 | 1 | GameSession_Construct |
| `0xb65` | 1 | 1 | GameSession_Construct |
| `0x1508` | 4 | 1 | GameSession_Construct |
| `0x150c` | 4 | 1 | GameSession_Construct |
| `0x2d10` | 4 | 1 | GameSession_Construct |
| `0x2d14` | 4 | 1 | GameSession_Construct |
| `0x2d18` | 4 | 1 | GameSession_Construct |
| `0x2d8c` | 4 | 1 | GameSession_Construct |
| `0x2d90` | 4 | 1 | GameSession_Construct |
| `0x2d98` | 4 | 1 | GameSession_Construct |
| `0x2d9c` | 4 | 2 | GameSession_Construct, GameState_Destruct |
| `0x2da0` | 4 | 1 | GameSession_Construct |
| `0x2da4` | 4 | 1 | GameSession_Construct |
| `0x2da8` | 4 | 1 | GameSession_Construct |
| `0x2dac` | 4 | 2 | GameSession_Construct, GameState_Destruct |
| `0x2e18` | 4 | 1 | GameSession_Construct |

## Vtable references

- `GameSession_Construct`
- `GameState_Destruct`
