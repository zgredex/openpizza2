# batch19 part3 worklog

Target: `game/fastfood2.exe`, MSVC 6.0 SP3 (`C2.DLL 12.00.8447`), all
candidates genuine C++ (`/O2 /TP`), no inline assembly.

Result: **9 / 25 strict matches** (`"strict_match": true`) with
`tools/match_decomp.py --length ... --entry ... --flags '/O2 /TP' --strict
--auto-symbols` and with `verify_strict.sh`.

## Strict matches

| address | function | bytes | entry | notes |
|---|---:|---:|---|---|
| 0x4d2b90 | Object_SetMarketValueByType | 235 | `?SetMarketValueByType@Object@@QAEXXZ` | case labels must be listed in ascending order so VC6 emits a direct jump table |
| 0x47a9d0 | Branch_RemoveStaffMember | 237 | `?RemoveStaffMember@Branch@@QAEXPAHH@Z` | map helpers reached through cast class names |
| 0x4f57f0 | Grid_GetDirectionBetweenNodes | 236 | `?Grid_GetDirectionBetweenNodes@@YGHPAUGridNode@@0@Z` | eight independent `x`/`y` conditions reproduce the reloaded comparisons |
| 0x4fc630 | City_TickBranches | 237 | `?TickBranches@City@@QAEHH@Z` | `AutoTunePrice` takes the branch record as an argument on `this` |
| 0x502030 | Game_GetBuildingQualityBand | 239 | `_Game_GetBuildingQualityBand` | `if (sum > best)` gives the original operand order |
| 0x507ee0 | Person_SelectRouteStopForTimeSlot | 236 | `?SelectRouteStopForTimeSlot@Person@@QAEHH@Z` | 0x108 field offset |
| 0x525fd0 | Window_DispatchWindowMessage | 237 | `?DispatchWindowMessage@Window@@QAEXIPAXI@Z` | split 0x100/0x102 bodies; `command != 0` first |
| 0x5346a0 | RecordList_BlitIndexedRLE | 233 | `?BlitIndexedRLE@RecordList@@QAEXHPAIHNN@Z` | `Surface_BlitRLESkipToRGB` is a `Surface` method |
| 0x54b770 | UI_DrawOverlaySprites | 233 | `?DrawOverlaySprites@OverlaySprites@@QAEXHHPAXHHH@Z` | 8 `IDMapHelper` maps of 0x1c bytes at +4 |

## Unmatched

Best genuine attempts are under `nonmatching/` with the first differing byte
(`original`, `candidate`).

| address | function | bytes | first diff | cause |
|---|---:|---:|---|---|
| 0x4ba250 | Game_AdvanceCurrentRecord | 236 | 2: `0c`/`08` | stack frame is 12 bytes in the original; candidate packs the `char` flag into the index slot |
| 0x4dc330 | City_ResetPoliceDistrictSlot | 235 | 27: `8c`/`44` | original clobbers `ecx` with the second district offset, candidate keeps the argument live |
| 0x542630 | Sound_UpdateBufferFade | 235 | 151: `8b`/`46` | critical-section argument register (`edx`/`eax`) differs |
| 0x4fd520 | City_EnsurePedestrianCoverage | 240 | 213: `0f`/`07` | loop tail loads `*list` into `ecx`; candidate uses `eax` |
| 0x487940 | SaveGame_SerializeRuntimeList | 240 | 44: `91`/`82` | enabled flag is zero-extended to `eax` in the original |
| 0x523e20 | UI_RenderScene | 237 | 50: `3a`/`39` | null `IsReady` argument is `xor eax,eax; push eax` in the original |
| 0x52bad0 | Movie_UpdateFrame | 237 | 26: `ca`/`c6` | record-enabled flag zero-extension differs |
| 0x48e0b0 | Game_CacheCurrentCityGlobals | 236 | 199: `83`/`5e` | copy loop keeps independent source/destination pointers in the original |
| 0x4f9df0 | MapObject_CreateFromTile | 236 | 6: `56`/`8b` | prologue push scheduling and store ordering |
| 0x508eb0 | Game_UpdatePlayerObject | 239 | 0: `53`/`56` | `record`/`cell` callee-saved register roles swapped |
| 0x4d5160 | City_CreateExplosionEffect | 240 | - | not attempted (SEH/`new`/inline `strcpy` frame) |
| 0x4fde00 | AI_SendGraffitiPunk | 241 | - | not attempted in this part budget |
| 0x4febb0 | Branch_ApplyStyleSettings | 241 | - | not attempted in this part budget |
| 0x48c060 | Market_ComputeWeightedAveragePrice | 242 | - | x87 accumulator/`fidiv` sharing not reconstructed |
| 0x4dcd00 | Person_RefreshShopChoices | 242 | - | not attempted in this part budget |
| 0x5478c0 | Sound_LoadSpeechSet | 242 | - | not attempted in this part budget |

All attempted sources are genuine C++; no inline assembly was used.
