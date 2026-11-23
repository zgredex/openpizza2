# OpenPizza2 source-port queue (heuristic; NOT proof of correctness)

Exported pseudocode bodies: 3919
Available for porting: 3476
Submitted source (not build verified): 443
Explicit stubs excluded from recovery: 0

## First candidates (lowest estimated complexity)

| Address | Name | Cost | Lines | Direct named dependencies |
|---|---|---:|---:|---:|
| `0x54f140` | `__ftol` | 1.0 | 9 | 0 |
| `0x4f5f70` | `Array_SetSlot` | 1.1 | 16 | 0 |
| `0x4c3c70` | `Lookup_BytePlusOne` | 1.1 | 8 | 0 |
| `0x54e84c` | `__global_unwind2` | 1.1 | 9 | 0 |
| `0x4f5fa0` | `Array_SearchSet` | 1.2 | 18 | 0 |
| `0x4973f0` | `Supplier_GetValuePlusOne` | 1.2 | 8 | 0 |
| `0x4dd650` | `Game_SetGlobalWord16` | 1.2 | 7 | 0 |
| `0x4a8450` | `Personnel_GetTrainingLevel` | 1.2 | 8 | 0 |
| `0x54fe6c` | `CRT_StackFrameStub` | 1.3 | 7 | 0 |
| `0x53efd0` | `SoundBuffer_SetBaseVTable` | 1.3 | 6 | 0 |
| `0x4dd0f0` | `Economy_ApplyTablePercent` | 1.4 | 6 | 0 |
| `0x54e5a7` | `CRT_Unwind` | 1.4 | 11 | 0 |
| `0x553934` | `Thread_InitLocks` | 1.4 | 9 | 0 |
| `0x54d84e` | `Thunk_SetVTable55CCA4` | 1.4 | 6 | 0 |
| `0x54d484` | `COM_SetSecondaryVTable` | 1.4 | 6 | 0 |
| `0x4032a0` | `RegistryKey_WriteValue` | 1.5 | 13 | 0 |
| `0x53a1e0` | `SpriteBase_Construct` | 1.5 | 7 | 0 |
| `0x53a210` | `SpriteBase_Destructor` | 1.5 | 7 | 0 |
| `0x4d3f80` | `Character_Destroy` | 1.5 | 7 | 0 |
| `0x50fb30` | `GamePlan_Destructor` | 1.5 | 7 | 0 |
| `0x557ae0` | `KERNEL32.DLL::RtlUnwind` | 1.5 | 8 | 0 |
| `0x5539be` | `CS_LeaveIndexed` | 1.5 | 6 | 0 |
| `0x4d1ca0` | `RecipeTopping_Destroy` | 1.5 | 7 | 0 |
| `0x4e4920` | `Ingredient_Destroy` | 1.5 | 7 | 0 |
| `0x501a30` | `AwardNode_Destructor` | 1.5 | 7 | 0 |
| `0x4e4050` | `FurnitureType_Destroy` | 1.5 | 7 | 0 |
| `0x4e4390` | `BuildingValue_Destroy` | 1.5 | 7 | 0 |
| `0x54cb86` | `DDRAW.DLL::DirectDrawCreate_Thunk` | 1.5 | 8 | 0 |
| `0x401270` | `StatsPeriodReport_Destroy` | 1.5 | 7 | 0 |
| `0x4e5de0` | `ConstructionOrder_Destructor` | 1.6 | 7 | 0 |

Cost is only a text-based triage heuristic, not a measurement of effort, recoverability or runnable coverage.
After each batch: re-run this script; mark real compiled functions using your build manifest, not file existence.
For running the game, additionally prioritize the actual entrypoint call graph and critical startup APIs.
