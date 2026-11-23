# batch21 part2 worklog

Scope: 8 functions from `reconstructed/match/batch21/part2.json`.
Toolchain: `~/.local/share/pc2/vc6-sp3-toolchain/VC98` (MSVC 6.0 SP3,
C2.DLL 12.00.8447). `sh reconstructed/match/runtime01/verify_strict.sh`
reported 6/6 before this work. Every accepted function is genuine C++ and
passes `tools/match_decomp.py --strict --auto-symbols` with the manifest
length (156 bytes each) and the exact candidate entry symbol.

## Strict matches

| address | function | flags | entry | commit |
|---|---|---|---|---|
| 0x50f6b0 | `GamePlan_SaveRecord` | /O2 /TP | `?SaveRecord@GamePlan@@QAEXPAVOStream@@@Z` | |
| 0x50f750 | `GamePlan_LoadRecord` | /O2 /TP | `?LoadRecord@GamePlan@@QAEXPAVIStream@@@Z` | |
| 0x549e80 | `Sound_PlayBuildingSpecialSfx` | /O2 /TP | `?PlayBuildingSpecialSfx@Sound@@QAEXH@Z` | |

Notes:

* `0x50f6b0` / `0x50f750` are the same eleven-field serialization order
  (`+4,+8,+0x10,+0x14,+0x18,+0x1c,+0x20,+0x2c,+0xc,+0x24,+0x28`). Field
  declaration order in the class does not affect the emitted sequence; the
  call order does. The last write uses `add esi,0x28` because `this` is dead.
* `0x549e80`: the shipped switch jump table at `0x549f1c` matches a plain
  `switch` over cases 0..9; the city-name pointers are the existing packed
  strings at `0x576308`..`0x57632c` and the format string at `0x5762e0`.
  `Sound_PlayChannel` is called as a `Sound` member (thiscall), which is why
  `mov ecx,esi` precedes the call.
