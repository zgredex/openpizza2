# batch01/part4 worklog

Part 4 of batch 1: 25 functions from `../part4.json`. Toolchain:
`/tmp/opencode/vc6-sp3-toolchain/VC98` (CL 12.00.8168 driver, C2.DLL
12.00.8447). Genuine C candidates compile with `/O2 /TP`, and the
exception-handling functions with `/O2 /GX /TP`.

Verify all genuine C candidates:

```sh
python3 reconstructed/match/batch01/part4/verify.py
```

`verify.py` holds the per-function length, entry symbol and flags. Result on
the final tree: **17/17 genuine C candidates match**.

## Matched in C (17)

| address | name | length | flags |
|---|---|---|---|
| 0x401970 | ResourceManager_Construct | 133 | /O2 /TP |
| 0x477190 | Branch_SpawnWalkInCustomer | 456 | /O2 /GX /TP |
| 0x47e930 | Branch_StartConstructionOnPlot | 255 | /O2 /GX /TP |
| 0x498090 | Mission_CheckGamePlanCategoryGoal | 111 | /O2 /TP |
| 0x49b5f0 | Menu_BuildUnassignedMenuList | 293 | /O2 /GX /TP |
| 0x4a66d0 | Personnel_SetEmployeePhotoByKey | 120 | /O2 /TP |
| 0x4a80e0 | Rating_UpdateBarByKey | 266 | /O2 /TP |
| 0x4cded0 | SubStartMenuA_InitSaveGamePage | 437 | /O2 /GX /TP |
| 0x4dd2e0 | GameClock_Delete | 30 | /O2 /TP |
| 0x4fbee0 | Map_CommitPendingObjectEdits | 459 | /O2 /GX /TP |
| 0x505e00 | Object_IsVisibleThisFrame | 82 | /O2 /TP |
| 0x50f670 | GamePlan_Delete | 30 | /O2 /TP |
| 0x52fc00 | UI_CreateSlider | 191 | /O2 /GX /TP |
| 0x531c60 | UI_CreateBitmapGadget | 133 | /O2 /GX /TP |
| 0x532bf0 | AnimCritical_Init | 16 | /O2 /TP |
| 0x53c6e0 | SpriteCriticalSection_Init | 16 | /O2 /TP |
| 0x54a610 | DebugConsole_Delete | 30 | /O2 /TP |

### EH functions after matcher commit 5cb2219c

`tools/match_decomp.py` now copies linker-resolved DIR32/REL32 fields from the
original PE, so the COMDAT `.text$x` handler thunk addresses no longer need to
be hard-coded. The previously transcribed functions 0x477190, 0x47e930,
0x49b5f0, 0x4cded0, 0x4fbee0, 0x52fc00 and 0x531c60 are now genuine C++:

- The functions are C++ members (or C++-linkage free functions; `extern "C"`
  suppresses `/GX` unwind frames and must not be used).
- Allocations are real `new` expressions; the generated EH states
  (-1/0/1/2/...) and the `.text$x` thunks then match.
- Win32 calls in 0x523100 needed `__declspec(dllimport)` to produce
  `call DWORD PTR [__imp_...]`; the same rule applies to other import calls.
- 0x52fc00/0x531c60 use classes with the original allocation sizes
  (`UI_Bar` 0x4f8, `UI_ImageChild` 0xa0) and a virtual destructor where the
  failure path calls the scalar deleting destructor.
- 0x4cded0 required modelling `NamedLockable`/`Array`-style members with
  constructors and a virtual destructor so the compiler emits the member
  constructor calls before the vptr store.

## Unmatched (8)

The following candidates remain naked assembly transcriptions of the shipped
instructions. They are **not** decompiled C and do not count as matches. They
were moved to `nonmatching/` for reference.

| address | name | reason |
|---|---|---|
| 0x4b1a50 | PersonnelPlan_UpdateEmployeeDetail | not attempted in C this pass (large mixed global/frame expression) |
| 0x4cf380 | CityAdminPanel_UpdateTabButtons | same |
| 0x4d2420 | MapObject_SetTypeAndSprite | same |
| 0x4dc420 | Object_SetSignAndLogoVariant | C reached 49 differing bytes, first at 0x81 (destination-chain scheduling) |
| 0x4e41c0 | FurnitureType_InitTable | C reached 70 differing bytes, first at 0x1f/0x35 (extra loop-head record reload) |
| 0x4eb900 | IsoMap_DeserializeGrid | 3045-byte EH function, not attempted in C this pass |
| 0x4f21e0 | Object_UpdateWalkStep | not attempted in C this pass |
| 0x523100 | UI_Manager_Construct | C attempt reached the exact 1164-byte length but 448 bytes differ; first at 0xc1 (param_4/param_5 load scheduling), then a 1-byte shift from a zero-store register choice (`ebp` vs `eax`) and differing EH-state/scheduling details |

## Notes

- `0x4fbee0` needed the game-object `GetSizeName` call modelled as a
  `__thiscall` member of `*ctx` (not a free function), and a cached map
  pointer local so the frame layout matches.
- No files outside `reconstructed/match/batch01/part4/` were modified.
