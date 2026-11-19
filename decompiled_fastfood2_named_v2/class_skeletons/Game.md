# Game

- Vtable: `0x55c5d0`
- Constructor: `Game_Construct`
- Destructor: `Game_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

## Virtual methods

| # | Method |
|---:|---|
| 0 | `Game_Delete` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 1 | Game_InitDateState |
| `0x8` | 4 | 1 | Game_InitDateState |
| `0xc` | 4 | 3 | Game_Construct, Game_Destroy, Game_InitDateState |
| `0x10` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x14` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x18` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x1c` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x20` | 4 | 1 | Game_Construct |
| `0x31` | 2 | 1 | Game_InitDateState |
| `0x33` | 1 | 1 | Game_InitDateState |
| `0x34` | 4 | 1 | Game_InitStatBaselines |
| `0x6c` | 4 | 1 | Game_ResetBuildingUtilization |
| `0x90` | 4 | 2 | Game_InitScenario, Game_LoadSaveGame |
| `0x94` | 0 | 1 | Game_LoadSaveGame |
| `0x9c` | 4 | 1 | Game_LoadSaveGame |
| `0xa8` | 4 | 1 | Game_ResetBuildingUtilization |
| `0xc0` | 4 | 1 | Game_InitDateState |
| `0xc6` | 1 | 1 | Game_InitDateState |
| `0xc8` | 4 | 1 | Game_InitDateState |
| `0xd0` | 4 | 1 | Game_InitDateState |
| `0xd4` | 4 | 1 | Game_InitDateState |
| `0x124` | 4 | 1 | Game_ResetRecordTurnCounters |
| `0x1cc` | 4 | 1 | Game_ResetBuildingUtilization |
| `0x200` | 4 | 1 | Game_InitScenario |
| `0x224` | 4 | 2 | Game_InitScenario, Game_LoadSaveGame |
| `0x240` | 4 | 3 | Game_InitScenario, Game_LoadBackgroundImage, Game_ResetStats |
| `0x244` | 4 | 1 | Game_ResetStats |
| `0x248` | 4 | 1 | Game_ResetStats |
| `0x24c` | 4 | 1 | Game_ResetStats |
| `0x250` | 4 | 1 | Game_ResetStats |
| `0x254` | 4 | 1 | Game_ResetStats |
| `0x258` | 4 | 1 | Game_ResetStats |
| `0x25c` | 4 | 1 | Game_ResetStats |
| `0x260` | 4 | 1 | Game_ResetStats |
| `0x298` | 0 | 1 | Game_LoadSaveGame |
| `0x2b8` | 0 | 1 | Game_LoadSaveGame |
| `0x2d8` | 4 | 1 | Game_LoadSaveGame |
| `0x2dc` | 4 | 1 | Game_LoadSaveGame |
| `0x2e8` | 4 | 1 | Game_LoadSaveGame |
| `0x2ec` | 4 | 1 | Game_LoadSaveGame |
| `0x2f0` | 4 | 1 | Game_LoadSaveGame |
| `0x2f4` | 4 | 1 | Game_LoadSaveGame |
| `0x2f8` | 4 | 1 | Game_LoadSaveGame |
| `0x300` | 4 | 1 | Game_LoadBackgroundImage |
| `0x33c` | 4 | 1 | Game_LoadSaveGame |
| `0x340` | 4 | 1 | Game_LoadSaveGame |
| `0x344` | 4 | 1 | Game_LoadSaveGame |
| `0x348` | 4 | 1 | Game_LoadSaveGame |
| `0x34c` | 4 | 1 | Game_LoadSaveGame |
| `0x350` | 4 | 1 | Game_LoadSaveGame |
| `0x354` | 4 | 1 | Game_LoadSaveGame |
| `0x358` | 4 | 1 | Game_LoadSaveGame |
| `0x35c` | 4 | 1 | Game_LoadSaveGame |
| `0x360` | 4 | 1 | Game_LoadSaveGame |
| `0x364` | 4 | 1 | Game_LoadSaveGame |
| `0x368` | 4 | 1 | Game_LoadSaveGame |
| `0x81c` | 4 | 1 | Game_ResetPlayerStatsByCity |
| `0x820` | 4 | 1 | Game_ResetPlayerStatsByCity |
| `0x1148` | 4 | 1 | Game_InitCompanyAIStrategy |
| `0x114c` | 4 | 1 | Game_InitCompanyAIStrategy |
| `0x1150` | 4 | 1 | Game_InitCompanyAIStrategy |
| `0x1154` | 4 | 1 | Game_InitCompanyAIStrategy |
| `0x14d8` | 4 | 1 | Game_InitStatBaselines |
| `0x186c` | 4 | 1 | Game_InitStatBaselines |
| `0x2d90` | 4 | 1 | Game_LoadSaveGame |
| `0x2e24` | 4 | 1 | Game_LoadSaveGame |
| `0x2bf44` | 4 | 1 | Game_Construct |
| `0x2bf48` | 1 | 1 | Game_Construct |
| `0x2bf4c` | 4 | 1 | Game_Construct |
| `0x2bf50` | 4 | 1 | Game_Construct |
| `0x2bf54` | 4 | 1 | Game_Construct |
| `0x2bf58` | 4 | 1 | Game_Construct |
| `0x2bf5c` | 4 | 1 | Game_Construct |
| `0x2bf60` | 4 | 1 | Game_Construct |
| `0x2bf64` | 4 | 1 | Game_Construct |
| `0x2bf68` | 4 | 1 | Game_Construct |
| `0x2bf74` | 4 | 1 | Game_Construct |
| `0x2bf78` | 4 | 1 | Game_Construct |
| `0x2bf7c` | 4 | 1 | Game_Construct |
| `0x2bf80` | 4 | 1 | Game_Construct |
| `0x2bf84` | 4 | 1 | Game_Construct |
| `0x2bf88` | 4 | 1 | Game_Construct |
| `0x2bf90` | 4 | 1 | Game_Construct |
| `0x2bf94` | 4 | 1 | Game_Construct |
| `0x2bf98` | 4 | 1 | Game_Construct |
| `0x2bf9c` | 4 | 1 | Game_Construct |
| `0x2bfa4` | 4 | 1 | Game_Construct |
| `0x2bfa8` | 4 | 1 | Game_Construct |
| `0x2bfac` | 4 | 1 | Game_Construct |
| `0x2bfc0` | 4 | 1 | Game_Construct |
| `0x2bfc4` | 4 | 1 | Game_Construct |
| `0x2bfc8` | 4 | 1 | Game_Construct |
| `0x2bfcc` | 4 | 1 | Game_Construct |
| `0x2bfd0` | 4 | 1 | Game_Construct |
| `0x2bfd4` | 4 | 1 | Game_Construct |
| `0x2bfe0` | 4 | 1 | Game_Construct |
| `0x2bfe4` | 4 | 1 | Game_Construct |
| `0x2bfe8` | 4 | 1 | Game_Construct |
| `0x2bfec` | 4 | 1 | Game_Construct |
| `0x2c00c` | 4 | 1 | Game_Construct |
| `0x2c010` | 4 | 1 | Game_Construct |
| `0x2c014` | 4 | 1 | Game_Construct |
| `0x2c018` | 4 | 1 | Game_Construct |
| `0x2c01c` | 4 | 1 | Game_Construct |
| `0x2c020` | 4 | 1 | Game_Construct |
| `0x2c024` | 4 | 1 | Game_Construct |
| `0x2c028` | 4 | 1 | Game_Construct |
| `0x2c048` | 4 | 1 | Game_Construct |
| `0x2c050` | 4 | 1 | Game_Construct |
| `0x2c054` | 4 | 1 | Game_Construct |
| `0x2c058` | 4 | 1 | Game_Construct |
| `0x2c05c` | 4 | 1 | Game_Construct |
| `0x2c0a0` | 4 | 1 | Game_Construct |
| `0x2c0a4` | 4 | 1 | Game_Construct |
| `0x2c0a8` | 4 | 1 | Game_Construct |
| `0x2c0ac` | 4 | 1 | Game_Construct |
| `0x2c0cc` | 4 | 1 | Game_Construct |
| `0x2c0d0` | 4 | 1 | Game_Construct |
| `0x2c0d4` | 4 | 1 | Game_Construct |
| `0x2c0d8` | 4 | 1 | Game_Construct |
| `0x2c0dc` | 4 | 1 | Game_Construct |
| `0x2c0e0` | 4 | 1 | Game_Construct |
| `0x2c0e4` | 4 | 1 | Game_Construct |
| `0x2c0e8` | 4 | 1 | Game_Construct |
| `0x2c0ec` | 4 | 1 | Game_Construct |
| `0x2c0f0` | 4 | 1 | Game_Construct |
| `0x2c0f4` | 4 | 1 | Game_Construct |
| `0x2c0f8` | 4 | 1 | Game_Construct |
| `0x2c0fc` | 4 | 1 | Game_Construct |
| `0x2c100` | 4 | 1 | Game_Construct |
| `0x2c104` | 4 | 1 | Game_Construct |
| `0x2c108` | 4 | 1 | Game_Construct |
| `0x2c10c` | 4 | 1 | Game_Construct |
| `0x2c110` | 4 | 1 | Game_Construct |
| `0x2c114` | 4 | 1 | Game_Construct |
| `0x2c118` | 4 | 1 | Game_Construct |
| `0x2c11c` | 4 | 1 | Game_Construct |
| `0x2c120` | 4 | 1 | Game_Construct |
| `0x2c124` | 4 | 1 | Game_Construct |
| `0x2c128` | 4 | 1 | Game_Construct |
| `0x2c12c` | 4 | 1 | Game_Construct |
| `0x2c130` | 4 | 1 | Game_Construct |
| `0x2c134` | 4 | 1 | Game_Construct |
| `0x2c138` | 4 | 1 | Game_Construct |
| `0x2c13c` | 4 | 1 | Game_Construct |
| `0x2c140` | 4 | 1 | Game_Construct |
| `0x2c144` | 4 | 1 | Game_Construct |
| `0x2c148` | 4 | 1 | Game_Construct |
| `0x2c14c` | 4 | 1 | Game_Construct |
| `0x2c150` | 4 | 1 | Game_Construct |
| `0x2c154` | 4 | 1 | Game_Construct |
| `0x2c158` | 4 | 1 | Game_Construct |
| `0x2c15c` | 4 | 1 | Game_Construct |
| `0x2c160` | 4 | 1 | Game_Construct |
| `0x2c164` | 4 | 1 | Game_Construct |
| `0x2c168` | 4 | 1 | Game_Construct |
| `0x2c16c` | 4 | 1 | Game_Construct |
| `0x2c170` | 4 | 1 | Game_Construct |
| `0x2c174` | 4 | 1 | Game_Construct |
| `0x2c178` | 4 | 1 | Game_Construct |
| `0x2c17c` | 4 | 1 | Game_Construct |
| `0x2c180` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c184` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c188` | 4 | 1 | Game_Construct |
| `0x2c18c` | 4 | 1 | Game_Construct |
| `0x2c190` | 4 | 1 | Game_Construct |
| `0x2c194` | 4 | 1 | Game_Construct |
| `0x2c198` | 4 | 1 | Game_Construct |
| `0x2c19c` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c1a0` | 4 | 1 | Game_Construct |
| `0x2c1a4` | 4 | 1 | Game_Construct |
| `0x2c1a8` | 4 | 1 | Game_Construct |
| `0x2c1ac` | 4 | 1 | Game_Construct |
| `0x2c1b0` | 4 | 1 | Game_Construct |
| `0x2c1b4` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c1b8` | 4 | 1 | Game_Construct |
| `0x2c1bc` | 4 | 1 | Game_Construct |
| `0x2c1c0` | 4 | 1 | Game_Construct |
| `0x2c1c4` | 4 | 1 | Game_Construct |
| `0x2c1c8` | 4 | 1 | Game_Construct |
| `0x2c1cc` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c1d0` | 4 | 1 | Game_Construct |
| `0x2c1d4` | 4 | 1 | Game_Construct |
| `0x2c1d8` | 4 | 1 | Game_Construct |
| `0x2c1dc` | 4 | 1 | Game_Construct |
| `0x2c1e0` | 4 | 1 | Game_Construct |
| `0x2c1e4` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c1e8` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c1ec` | 4 | 1 | Game_Construct |
| `0x2c1f0` | 4 | 1 | Game_Construct |
| `0x2c1f4` | 4 | 1 | Game_Construct |
| `0x2c1f8` | 4 | 1 | Game_Construct |
| `0x2c1fc` | 4 | 1 | Game_Construct |
| `0x2c200` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c204` | 4 | 1 | Game_Construct |
| `0x2c208` | 4 | 1 | Game_Construct |
| `0x2c20c` | 4 | 1 | Game_Construct |
| `0x2c210` | 4 | 1 | Game_Construct |
| `0x2c214` | 4 | 1 | Game_Construct |
| `0x2c218` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c21c` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c220` | 4 | 1 | Game_Construct |
| `0x2c224` | 4 | 1 | Game_Construct |
| `0x2c228` | 4 | 1 | Game_Construct |
| `0x2c22c` | 4 | 1 | Game_Construct |
| `0x2c230` | 4 | 1 | Game_Construct |
| `0x2c234` | 4 | 1 | Game_Construct |
| `0x2c238` | 4 | 1 | Game_Construct |
| `0x2c23c` | 4 | 1 | Game_Construct |
| `0x2c240` | 4 | 1 | Game_Construct |
| `0x2c244` | 4 | 1 | Game_Construct |
| `0x2c248` | 4 | 1 | Game_Construct |
| `0x2c24c` | 4 | 1 | Game_Construct |
| `0x2c250` | 4 | 1 | Game_Construct |
| `0x2c25c` | 4 | 1 | Game_Construct |
| `0x2c260` | 4 | 1 | Game_Construct |
| `0x2c268` | 4 | 1 | Game_Construct |
| `0x2c26c` | 4 | 1 | Game_Construct |
| `0x2c270` | 4 | 1 | Game_Construct |
| `0x2c278` | 4 | 1 | Game_Construct |
| `0x2c27c` | 4 | 1 | Game_Construct |
| `0x2c280` | 4 | 1 | Game_Construct |
| `0x2c284` | 4 | 1 | Game_Construct |
| `0x2c28c` | 4 | 1 | Game_Construct |
| `0x2c290` | 4 | 1 | Game_Construct |
| `0x2c294` | 4 | 1 | Game_Construct |
| `0x2c29c` | 4 | 1 | Game_Construct |
| `0x2c2a0` | 4 | 1 | Game_Construct |
| `0x2c2a4` | 4 | 1 | Game_Construct |
| `0x2c2a8` | 4 | 1 | Game_Construct |
| `0x2c2ac` | 4 | 1 | Game_Construct |
| `0x2c2b0` | 4 | 1 | Game_Construct |
| `0x2c2b4` | 4 | 1 | Game_Construct |
| `0x2c2b8` | 4 | 1 | Game_Construct |
| `0x2c2f4` | 4 | 1 | Game_Construct |
| `0x2c2f8` | 4 | 1 | Game_Construct |
| `0x2c2fc` | 4 | 1 | Game_Construct |
| `0x2c300` | 4 | 1 | Game_Construct |
| `0x2c304` | 4 | 1 | Game_Construct |
| `0x2c308` | 4 | 1 | Game_Construct |
| `0x2c30c` | 4 | 1 | Game_Construct |
| `0x2c310` | 4 | 1 | Game_Construct |
| `0x2c330` | 4 | 1 | Game_Construct |
| `0x2c338` | 4 | 1 | Game_Construct |
| `0x2c33c` | 4 | 1 | Game_Construct |
| `0x2c340` | 4 | 1 | Game_Construct |
| `0x2c344` | 4 | 1 | Game_Construct |
| `0x2c3b4` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c3b8` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c3bc` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c3c0` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c3c4` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c3c8` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c3cc` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c3d0` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c3d4` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c3d8` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c3dc` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c3e0` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c3e4` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c3e8` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c3ec` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c3f0` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c3f4` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c414` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c418` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2f87c` | 4 | 1 | Game_Construct |
| `0x2f880` | 4 | 1 | Game_Construct |
| `0x2f884` | 4 | 1 | Game_Construct |
| `0x2f888` | 4 | 1 | Game_Construct |
| `0x2f88c` | 4 | 1 | Game_Construct |

## Vtable references

- `Game_Construct`
- `Game_Destroy`
