# batch16 part4 worklog

Scope: 25 functions from `reconstructed/match/batch16/part4.json`.
Toolchain: `~/.local/share/pc2/vc6-sp3-toolchain/VC98` (MSVC 6.0 SP3, C2.DLL
12.00.8447); `reconstructed/match/runtime01/verify_strict.sh` reports 6/6.
Every accepted function is genuine C/C++ and passes
`tools/match_decomp.py --strict --auto-symbols` with the manifest length and
the exact candidate entry symbol.

## Result: 5 / 25 strict matches

Reproduce with:

```sh
sh reconstructed/match/batch16/part4/verify_strict.sh
```

Matches:

| address | function | flags | entry |
| --- | --- | --- | --- |
| 0x4a14c0 | SaveGame_CompareTime | /O2 /TP | `_SaveGame_CompareTime` |
| 0x4dc0f0 | Company_PlaceScenarioBranches | /O2 /TP | `?PlaceScenarioBranches@ScenarioCompany@@QAEXPAX@Z` |
| 0x50e550 | Game_GetObjectStatusLevel | /O2 /TP | `@Game_GetObjectStatusLevel@4` |
| 0x50e600 | Person_ChooseWanderTarget | /O2 /TP | `?ChooseWanderTarget@Person@@QAEXPAX@Z` |
| 0x527d10 | UI_SetWaitCursor | /O2 /TP | `?SetWaitCursor@UI@@QAEXH@Z` |

Notes:

- `0x4a14c0` is a plain unsigned-short comparator. Both the `>`/`<` operand
  order and the final `-1` result had to follow the shipped block layout to
  reproduce the merged `cmp`/`jbe`/`sbb` sequence.
- `0x4dc0f0` keeps the scenario-loop in the `DAT_0057bb20 == 0` early-return
  path and uses `Company` and `ScenarioCompany` class names so the decorated
  aliases resolve to `Company_EnsureRequiredBranch` and
  `Company_OpenStartingBranch` without explicit symbols.
- `0x50e550` returns the status band with a ternary
  (`!= 2 ? 7 : 0`), matching the `sub al,2` / `neg al` / `sbb` sequence.
- `0x527d10` resolves all Win32 imports through PE IAT slots
  (`LoadCursorA`, `GetCurrentThreadId`, `SetClassLongA`, `SetCursor`,
  `ResetEvent`, `PostMessageA`, `WaitForSingleObject`).

## Non-matching evidence

The following are genuine C/C++ attempts. Sources and full
`match_decomp.py` reports are in `nonmatching/`.

| address | function | first diff (offset: original vs candidate) | differing bytes |
| --- | --- | --- | --- |
| 0x477fe0 | Stats_SumFilteredFloats | 0x0c: 0xc7 vs 0x89 | 138 |
| 0x478090 | Stats_SumFilteredFloats2 | 0x0c: 0xc7 vs 0x89 | 138 |
| 0x478eb0 | Stats_ComputeWeightedTotals | 0x00: 0x53 vs 0x51 | 155 |
| 0x47ec70 | Game_ToggleObjectFlag2 | 0x26: 0x6a vs 0x8b | 4 |
| 0x4f1f70 | Object_UpdateState | 0x00: 0x56 vs 0x8b | 164 |
| 0x4fe370 | Company_AssignStaffToBranch | 0x7f: 0x06 vs 0x16 | 2 |
| 0x4ffe00 | Game_RefreshObjectCategoryBins | 0x6b: 0x10 vs 0x0c | 45 |
| 0x5219a0 | Sprite_FillRectColor | 0x28: 0x89 vs 0x8b | 111 |
| 0x544af0 | List_RemoveNodeLocked | 0x47: 0x06 vs 0x03 | 1 |
| 0x547810 | Sound_LoadEffectBuffers | 0x00: 0x81 vs 0xa1 | 129 |
| 0x4cba60 | Config_WriteRegistryBlock | 0x3d: 0x22 vs 0x1a | 71 |

`0x544af0` now has the exact 166-byte extent, EH sections, relocations and guard destructor; the last byte is the `jne` displacement around the conditional `current` update. The candidate uses a null-first ternary, which reproduces the shipped EAX register choice.

`0x4cba60` reaches the shipped EH prologue only when the candidate is given
C++ linkage (`/O2 /TP /GX`); the attempt then differs in the first EH state
store and leaves the `.text$x`/`.xdata$x` handler and an out-of-line
`??1RegistryKey@@QAE@XZ` COMDAT unverified. `0x4fe370` and `0x47ec70` are the
closest attempts: `0x4fe370` differs only in
the register chosen for the `RemoveStaffMember` argument (2 bytes), and
`0x47ec70` differs only in whether the first `CountObjectsByType` call sets
ECX before or after pushing its literal argument (4 bytes). The remaining
first differences are register-allocation, block-layout, or FP-stack
scheduling differences.

## Not attempted

No candidate was produced for these manifest entries:

- `0x402ad0` ResourceManager_FindExtensionAlias
- `0x480690` Game_UpdateObjectRatingScales
- `0x4d6af0` Game_CollectObjectsByType
- `0x4e5f40` Game_ComputeEventValue
- `0x502220` Game_GetGlobalStatsBand
- `0x502b80` AI_SelectActionForType
- `0x5408b0` SoundBuffer_DestructDerived
- `0x545b20` List_ContainerDestruct
- `0x50e9e0` Player_Destroy

## Cleanliness

Only sources under `reconstructed/match/batch16/part4/` and their strict
verifier are tracked. Generated COFF objects and toolchain files are not
committed.
