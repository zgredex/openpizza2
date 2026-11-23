# batch20 part1 worklog

Scope: 25 functions from `reconstructed/match/batch20/part1.json`.
Toolchain: `~/.local/share/pc2/vc6-sp3-toolchain/VC98` (MSVC 6.0 SP3,
C2.DLL 12.00.8447). Every accepted function is genuine C/C++ and passes
`tools/match_decomp.py --strict --auto-symbols` with the manifest length and
the exact candidate entry symbol. `sh reconstructed/match/runtime01/verify_strict.sh`
reported 6/6 before this work.

## Result: 2 / 25 strict matches

Reproduce with:

```sh
sh reconstructed/match/batch20/part1/verify_strict.sh
```

Matches (2):

| address | function | flags | entry |
| --- | --- | --- | --- |
| 0x4015b0 | `IDMapHelper::InsertGrow` | /O2 /TP | `?InsertGrow@IDMapHelper@@QAEHHH@Z` |
| 0x513d50 | `Storage::LoadRecord` | /O2 /TP | `?LoadRecord@Storage@@QAEXPAVIStream@@@Z` |

Notes:

* `0x4015b0`: the growth test had to be written `count >= capacity` (not
  `capacity <= count`) and the maximum update `index >= maxIndex` to reproduce
  the original `cmp ecx,eax; jg` / `cmp esi,eax; jl` encodings. `g_Liste_Lock`
  (0x579af0, `data_symbols.csv`) needs C linkage so the COFF spelling is
  `_g_Liste_Lock` and auto-resolution reaches the data name. The two block
  copies use the compiler's inline `memcpy` (`rep movsd` + `rep movsb`).
* `0x513d50`: `IStream::Read` resolves through the symbol registry
  (`?Read@IStream@@QAEXPAXH@Z`), and `List::Add` through the decorated alias
  `List_Add`. Keeping the first map key in a named local (`int key`) was
  required: the inline expression made MSVC reload the key into `edx` and emit
  16 differing bytes.

## Non-matching evidence

Genuine C/C++ attempts are under `nonmatching/`, each with the matcher JSON
recorded beside the source. All use the manifest length, exact entry, and
`--strict --auto-symbols`.

| address | function | first diff (offset: original vs candidate) | differing bytes | diagnosis |
| --- | --- | --- | --- | --- |
| 0x4d73c0 | `City::~City` | 0xc0: 0xbf vs 0x8f | 25 | Everything matches through the two inlined `List_Node_Destroy` tail calls. The shipped body emits EH try-level stores (`movb [esp+0x20],0` / `movl [esp+0x20],-1`) before those calls; this C2 build omits them for member-only destructors. The FuncInfo shape (maxState 2, unwind actions at 0x5590b0/0x5590be) and `??_7City@@6B@` at 0x55c500 were confirmed. |
| 0x4bd230 | `GuardMenu_FillSummary` | 0x24: 0xbe vs 0xbf | 11 | Only the callee-saved register choice for `percent` (ESI) versus `page` (EDI) differs. Requires `--symbol '?CountFreeBuildingsByType@BuildingManager@@QAEHH@Z=0x4d2ae0'`: the registry records the same function as void-decorated `?CountFreeBuildingsByType@BuildingManager@@QAEXH@Z`, while the shipped caller consumes EAX as the count. Independent evidence: `reconstructed/match/symbol_registry.json` entry 0x4d2ae0 (candidate declaration and ABI observation) and the `imul ebx,edx` use at 0x4bd2fd. |
| 0x4cb950 | `HighScore_ReadRegistryBlob` | n/a (main body exact) | 0 | All 257 code bytes match. The object is C++ (`extern "C"` suppresses the EH frame, so the symbol is `?HighScore_ReadRegistryBlob@@YAIPBDPAE@Z`). The registry ctor/dtor need explicit symbols `??0RegistryKey@@QAE@XZ=0x403190` and `??1RegistryKey@@QAE@XZ=0x4031a0` (both in `full_game_symbols.json`, dtor also called by the unwind action). Strict fails only on the 18-byte `.text$x` COMDAT: the unwind action is `lea -0x14(%ebp),%ecx` here versus `lea -0x10(%ebp),%ecx` in the shipped funclet at 0x558bd0; every other byte including the handler thunk shape is identical. |
| 0x478ae0 | `Rating_ComputeEightCategories` | 0x6e: 0xbb vs 0xbd | 123 | Prologue, zero initialization, tables and both loops match up to the inner-loop preheader; the shipped code puts the loop count in EBX and the row value in EBP, this candidate the reverse. The zero stores require zeroing `values[5]` with a loop; initializer syntax is dead-store eliminated. |
| 0x48ce70 | `Palette_Expand` | 0xb: 0x08 vs 0x18 | 209 | Register allocation differs from the prologue onward (source pointer in EBX instead of ECX, byte lanes in ECX/ESI/EDI instead of EAX/EBP/EDI). Switch case formulas and the byte-level branch layout were recovered from the jump table at 0x48cf74. |
| 0x54a490 | `Sound::PlayStatisticPageSfx` | 0xa: 0xf4 vs 0xad | 118 | The shipped switch hoists `xor edx,edx` before dispatch and materializes each ID/variant pair in EAX/EDX (`mov eax,0x14; push edx; push eax`). Literal-argument C source always becomes `push imm8`; explicit per-case variables produce either per-case `xor edx,edx` or folded immediates. |

## Not attempted

The remaining 17 records were not reached in this pass and have no candidate:

`0x47c8a0`, `0x406e90`, `0x4b7a00`, `0x524860`, `0x538fa0`,
`0x4ffad0`, `0x4a0a70`, `0x4d5250`, `0x4871a0`, `0x4d9ef0`, `0x4fb060`,
`0x541fc0`, `0x543c00`, `0x479ca0`, `0x4f88c0`, `0x5449a0`, `0x4bd340`.
