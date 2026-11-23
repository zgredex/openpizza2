# batch19 part3 worklog

Target: `game/fastfood2.exe`, MSVC 6.0 SP3 (`C2.DLL 12.00.8447`), genuine
C++ (`/O2 /TP`), no inline assembly.

Result: **9 / 25 strict matches**. All 25 manifest records have either a
strict match in the part root or a genuine compiled attempt under
`nonmatching/` with a matcher JSON record and first-difference evidence.

`verify_strict.sh` checks the nine accepted recipes with the manifest lengths,
exact entries, `/O2 /TP`, `--strict`, and `--auto-symbols`.

## Strict matches

| address | function | bytes | entry | notes |
|---|---:|---:|---|---|
| 0x4d2b90 | Object_SetMarketValueByType | 235 | `?SetMarketValueByType@Object@@QAEXXZ` | ascending case order emits a direct jump table |
| 0x47a9d0 | Branch_RemoveStaffMember | 237 | `?RemoveStaffMember@Branch@@QAEXPAHH@Z` | cast class names resolve map helpers |
| 0x4f57f0 | Grid_GetDirectionBetweenNodes | 236 | `?Grid_GetDirectionBetweenNodes@@YGHPAUGridNode@@0@Z` | eight independent `x`/`y` conditions |
| 0x4fc630 | City_TickBranches | 237 | `?TickBranches@City@@QAEHH@Z` | `AutoTunePrice` takes the branch record as an argument |
| 0x502030 | Game_GetBuildingQualityBand | 239 | `_Game_GetBuildingQualityBand` | `if (sum > best)` gives the original operand order |
| 0x507ee0 | Person_SelectRouteStopForTimeSlot | 236 | `?SelectRouteStopForTimeSlot@Person@@QAEHH@Z` | corrected 0x108 field offset |
| 0x525fd0 | Window_DispatchWindowMessage | 237 | `?DispatchWindowMessage@Window@@QAEXIPAXI@Z` | split 0x100/0x102 bodies, `command != 0` first |
| 0x5346a0 | RecordList_BlitIndexedRLE | 233 | `?BlitIndexedRLE@RecordList@@QAEXHPAIHNN@Z` | `Surface_BlitRLESkipToRGB` is a `Surface` method |
| 0x54b770 | UI_DrawOverlaySprites | 233 | `?DrawOverlaySprites@OverlaySprites@@QAEXHHPAXHHH@Z` | eight 0x1c-byte `IDMapHelper` maps at +4 |

## Nonmatching attempts

Each row has `<address>.c` and `<address>.json` under `nonmatching/`. The JSON
records the exact matcher invocation result; `first diff` is
`original byte`/`candidate byte` at that offset.

| address | function | bytes | first diff | cause |
|---|---:|---:|---|---|
| 0x4ba250 | Game_AdvanceCurrentRecord | 236 | 2: `0c`/`08` | 12-byte original frame; flag packed into index slot |
| 0x4dc330 | City_ResetPoliceDistrictSlot | 235 | 27: `8c`/`44` | original clobbers `ecx` with the second district offset |
| 0x542630 | Sound_UpdateBufferFade | 235 | 151: `8b`/`46` | critical-section argument register |
| 0x4fd520 | City_EnsurePedestrianCoverage | 240 | 213: `0f`/`07` | loop tail loads `*list` into `ecx` vs `eax` |
| 0x487940 | SaveGame_SerializeRuntimeList | 240 | 44: `91`/`82` | enabled flag zero-extension to `eax` |
| 0x523e20 | UI_RenderScene | 237 | 50: `3a`/`39` | null `IsReady` argument uses `xor eax,eax; push eax` |
| 0x52bad0 | Movie_UpdateFrame | 237 | 26: `ca`/`c6` | record-enabled flag zero-extension |
| 0x48e0b0 | Game_CacheCurrentCityGlobals | 236 | 199: `83`/`5e` | copy loop keeps independent source/destination pointers |
| 0x4f9df0 | MapObject_CreateFromTile | 236 | 6: `56`/`8b` | prologue push scheduling and store ordering |
| 0x508eb0 | Game_UpdatePlayerObject | 239 | 0: `53`/`56` | `record`/`cell` callee-saved register roles swapped |
| 0x4d5160 | City_CreateExplosionEffect | 240 | 0: `6a`/`83` | SEH/`new`/inline `strcpy` frame not reconstructed |
| 0x4fde00 | AI_SendGraffitiPunk | 241 | 78: `8b`/`6a` | float call-argument evaluation/scheduling |
| 0x4febb0 | Branch_ApplyStyleSettings | 241 | 0: `8b`/`53` | prologue/`this` register allocation |
| 0x48c060 | Market_ComputeWeightedAveragePrice | 242 | 0: `8b`/`83` | x87 accumulator/`fidiv` scheduling |
| 0x4dcd00 | Person_RefreshShopChoices | 242 | 3: `53`/`89` | frame/prologue and map-vtable call shape |
| 0x5478c0 | Sound_LoadSpeechSet | 242 | 6: `33`/`56` | local buffer/frame and virtual-call shape |

All attempted sources are genuine C++; no inline assembly was used.
