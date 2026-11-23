# batch18 part3 worklog

Scope: 25 functions from `reconstructed/match/batch18/part3.json`.
Toolchain: `~/.local/share/pc2/vc6-sp3-toolchain/VC98` (MSVC 6.0 SP3,
C2.DLL 12.00.8447). Every accepted function is genuine C/C++ and passes
`tools/match_decomp.py --strict --auto-symbols` with the manifest length,
the `/O2 /TP` flags, and the exact candidate entry symbol.

## Result: 2 / 25 strict matches

Reproduce with:

```sh
sh reconstructed/match/batch18/part3/verify_strict.sh
```

Strict matches:

| address | function | flags | entry |
| --- | --- | --- | --- |
| 0x401f90 | ResourceIterator_Next | /O2 /TP | `?Next@ResourceIterator@@QAEHPAD@Z` |
| 0x402f10 | NamePool_AddName | /O2 /TP | `?AddName@NamePool@@QAEXPADH@Z` |

## Non-matching evidence

Genuine C/C++ attempts that do not reproduce the shipped bytes are in
`nonmatching/` with the entry symbol, first differing byte offset, and the
matcher relocation/strict issues recorded in the matching `.json` file.

| address | function | entry | first diff (offset: original vs candidate) |
| --- | --- | --- | --- |
| 0x403880 | String_CompareLocalizedNoCase | `_String_CompareLocalizedNoCase` | 1: 68 vs 76 |
| 0x480130 | Game_CountGoalTargets | `?CountGoalTargets@Game@@QAEHH@Z` | 0: 83 vs 81 |
| 0x4c3610 | FurnitureMenu_InitOvenPage | `_UI_InitOvenPage` | 5: 199 vs 129 |
| 0x4d54a0 | City_SpawnFlyerBoy | `_City_SpawnFlyerBoy` | 0: 106 vs 86 |
| 0x4d5580 | Branch_ExpelCustomers | `_Branch_ExpelCustomers@4` | 14: 232 vs 51 |
| 0x4d8140 | Game_FindBestCompositeRatedBranch | `_Game_FindBestCompositeRatedBranch` | 181: 68 vs 116 |
| 0x4e4060 | Game_ComputePrice | `?ComputePrice@Game@@QAEHPAX@Z` | 175: 220 vs 221 |
| 0x4eb280 | IsoMap_ConstructFromStream | `_IsoMap_ConstructFromStream` | 0: 106 vs 86 |
| 0x4ed980 | Map_ComputeVisibleTileRange | `?ComputeVisibleTileRange@Map@@QAEXPAH00000@Z` | 104: 4 vs 16 |
| 0x4f5660 | Sprite_LoadIntoSlot78 | `?LoadIntoSlot78@Object@@QAEXH@Z` | 0: 100 vs 81 |
| 0x4fefb0 | AI_Annoy_SendGangsterGroup | `?SendGangsterGroup@AI@@QAEHPAX0@Z` | 0: 81 vs 83 |
| 0x50e8e0 | Player_Construct | `?Construct@Player@@QAEPAU1@PAH@Z` | 0: 106 vs 83 |
| 0x51ee80 | Renderer_ApplySpriteTint | `?ApplySpriteTint@Renderer@@QAEXHH@Z` | 11: 189 vs 188 |
| 0x5211a0 | UI_CustomControl_Destructor | `?DestroyControl@UI_CustomControl@@QAEXXZ` | 0: 106 vs 86 |
| 0x52bc80 | UI_Text_Construct | `?Construct@UI_TextElement@@QAEPAHHHHPAD0PAXPAH@Z` | 0: 106 vs 139 |
| 0x5390b0 | Surface_GetDescription | `?GetDescription@Image@@QAEXPAH0@Z` | 4: 85 vs 86 |
| 0x53dd90 | Sprite_FillColor8 | `?FillColor8@Sprite@@QAEHXZ` | 10: 117 vs 15 |
| 0x53fcc0 | SoundPakManager_Destruct | `?Destroy@SoundPakManager@@QAEXXZ` | 0: 106 vs 86 |
| 0x540960 | SoundBuffer_Init | `?Init@SoundBuffer@@QAEXPAXPADH@Z` | 0: 106 vs 83 |
| 0x540a80 | SoundBuffer_LockSample | `?LockSample@SoundBuffer@@QAEHHH@Z` | 3: 139 vs 87 |
| 0x5427e0 | SoundMixerThread_Destroy | `?Destroy@SoundMixerThread@@QAEXXZ` | 0: 106 vs 86 |
| 0x544620 | SoundBuffer_StopPlaybackLocked | `?StopPlaybackLocked@SoundBuffer@@QAEHXZ` | 0: 106 vs 86 |
| 0x5448c0 | Sound_QueryStatusLocked | `?QueryStatusLocked@SoundBuffer@@QAEHPAXPAH@Z` | 0: 106 vs 81 |

## Notes

- No inline assembly, no generated C, and no explicit symbol overrides were
  used; every relocation target is resolved by `--auto-symbols` from the
  shipped symbol maps, data symbols, address labels, or the registry.
- The closest failures are one-instruction tail or block-layout
  differences (for example `0x4d8140` differs only in the final
  conditional return and `0x4dec10` only in the register used for the
  `List::Add` argument after the inlined `memset`).
- The functions with an `fs:[0]` prologue are C++ constructors and
  destructors with unwind records; the EH model was not reproduced and
  their attempts stop at the first prologue byte.
