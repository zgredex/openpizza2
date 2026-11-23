# batch21 part1 worklog

Scope: 9 functions from `reconstructed/match/batch21/part1.json` (the nine
smallest untried records of batch21). Work is confined to
`reconstructed/match/batch21/part1/`.

Toolchain: pinned persistent VC6 SP3 MSVC 6.0
(`~/.local/share/pc2/vc6-sp3-toolchain/VC98`, C2.DLL 12.00.8447).
`sh reconstructed/match/runtime01/verify_strict.sh` reported 6/6 before this
work. Every accepted function is genuine C/C++ and passes
`tools/match_decomp.py --strict --auto-symbols` with the manifest length and
the exact candidate entry symbol.

Reproduce with:

```sh
sh reconstructed/match/batch21/part1/verify_strict.sh
```

Result: **7 / 9 strict matches**, 9 / 9 records attempted. The two
remaining records have genuine C/C++ candidates under `nonmatching/` with the
matcher JSON beside them.

## Matches

| address | function | flags | entry | notes |
| --- | --- | --- | --- | --- |
| 0x5086e0 | `UI_ShiftChildRect` | /O2 /TP | `?UI_ShiftChildRect@@YIXPAD@Z` | C++ member calls (`CS::Enter/Leave`, `Gfx::BlitRectList`) resolve through the decorated-alias rule; `DAT_0058072c` is a pointer variable loaded into ECX. |
| 0x522f40 | `Array::InsertGrow` | /O2 /TP | `?InsertGrow@Array@@QAEHH@Z` | `__thiscall` member; `memcpy` is the compiler's inline `rep movsd/movsb`; `capacity` reloaded after `operator_new`. |
| 0x404460 | `ResourceManager_OpenArchivePath` | /O2 /TP | `?ResourceManager_OpenArchivePath@@YAHPAUResourceManager@@PAD@Z` | `GetFileAttributesA` is a dllimport (`mov edi,ds:IAT` on the two calls); the second probe's shipped test is the signed `% 16` sequence, so the source uses `attributes % 16 != 0`; `Pak_Open` is a `__thiscall` member call bound explicitly (`?Pak_Open@ResourceManager@@QAEXPAD@Z=0x401af0`). |
| 0x4a1940 | `SaveGame_Scan` | /O2 /TP /GX | `?SaveGame_Scan@@YAXPAUList@@H@Z` | Genuine C++ `new UI_ListEntry(...)` with a declared destructor. The compiler-generated `.text$x` funclet/handler and `.xdata$x` FuncInfo/unwind map match the shipped image at 0x558870/0x55e2c8 and are located from the original handler immediate. Needs `??0UI_ListEntry@@QAE@HH@Z=0x403370`. |
| 0x513c90 | `Storage::Storage` | /O2 /TP /GX | `??0Storage@@QAE@PAUIStream@@@Z` | Genuine constructor with a `List` member subobject at +0x44; the member-initializer try region reproduces the shipped `.text$x` (0x55a4f0) and `.xdata$x` (0x55fe00). The vptr store is written as `*(void **)this = DAT_0055c700;` so no local vtable is emitted. Needs `??0List@@QAE@H@Z=0x4013a0` and `??1List@@QAE@XZ=0x401480`. |
| 0x5317b0 | `UI::CreateMovieWindow` | /O2 /TP /GX | `?CreateMovieWindow@UI@@QAEHHHHHH@Z` | Genuine C++ `new MovieWindow(...)` with a declared destructor. The 0x44-byte frame is a `MovieParams { char name[0x40]; int value; }`; the fourth argument initializes `params.value` and `&params` is the constructor's descriptor argument, which reproduces the shipped temp slot and the `[ebp+0x10]` cleanup funclet. Needs `??0MovieWindow@@QAE@HHHHPAXPADH0@Z=0x52ae20`. |
| 0x49f640 | `UI_RecordList_SetVisibleRange` | /O2 /TP | `?UI_RecordList_SetVisibleRange@@YAXPAUUI@@HH@Z` | The 6-byte `Slot` passed to `ReadSlot98`/`SetSlot6_98` is `{ short value; short last; short reserved; }`: the shipped code only writes offsets 0 and 2, so the visible range ends at +2, not +4. The out-parameter must be a separate local (`int outId;`) so `id` stays a plain value parameter and is cached in ESI across the first call. |

## Non-matching evidence

All three are complete genuine C/C++ reconstructions; the matcher was run with
the manifest length, the exact entry, `/O2 /TP`, `--strict --auto-symbols`.

| address | function | first diff | differing bytes | diagnosis |
| --- | --- | --- | --- | --- |
| 0x47cb70 | `Game::GetAverageCompanyValueByByte8` | 0x60: original 0x44 (`mov eax,[esp+0x18]`) vs candidate 0x4c (`mov ecx,[esp+0x18]`) | 2 | Everything through the loop body is byte-identical, including the double/float accumulation order (`fld qword [eax+0x70]; fadd dword [esp+0x10]`) and the count/sum slot reuse. Only the scratch register used to reload the spilled `this` for the loop bound differs (EAX vs ECX). Fifteen source variants (do/while, for, while, unsigned `i`, `this->`, `Game&`, `Game*` aliases, declaration/initializer permutations) all produce the same ECX choice. |
| 0x535c10 | `Font::WrapText` | 0x03: original 0x89 (`mov [esp],ecx`) vs candidate 0x53 (`push ebx`) | 133 | The shipped body keeps `text` in ECX / reloads it from the argument slot after each `GetCharWidth` and defers the EBX/EBP pushes until after the newline loop. This build caches `text` in EBP and shrink-wraps the pushes to the function entry, which shifts the entire body (the local allocation i=EBX, width=ESI, lastSpace=EDI is otherwise identical). Variants with a char temp, helper inlining, `volatile` text and reordered declarations did not change the `text`-in-EBP choice and the char-temp form additionally spills the char. |

## Compiler-pattern findings

* **C++ EH is reproducible without asm.** Compile with `/GX`; a member
  subobject with a destructor, or a `new` expression whose class has a
  destructor, installs the FS-based frame and C2 emits `.text$x` funclets plus
  a `.xdata$x` FuncInfo. When the source is structurally right those bytes are
  identical to the shipped image. `match_decomp.py --strict` locates them from
  the original handler immediate (the `push <handler>` field) and verifies
  them as `derived_section_anchor` spans. This overturns the batch16/part1
  note that these three records needed instruction-level asm.
* **Constructor member layout.** The `Storage` EH funclet destroys the member
  at `this+0x44`; a 4-byte vptr pad plus a manual
  `*(void **)this = vtable_address` store reproduces both the vptr store and
  the funclet without emitting a local vtable section.
* **`new` cleanup slot.** C2 stores the allocation pointer in a dead argument
  slot that the cleanup funclet reads as `[ebp+0x10]`. The source that matched
  passes a 0x44-byte descriptor struct by address and initialises its trailing
  `int` from the fourth parameter; making that value a plain unused argument
  moves the temp into a local and changes the funclet.
* **Decorated aliases.** A class method `C::M` resolves to the simple symbol
  `C_M` via the matcher's decorated-alias rule, which avoids `--symbol` for
  `CS_Enter`, `List_Add`, `String_SetOwned`, `Gfx_BlitRectList`, etc.
  `__thiscall` free functions cannot be declared in VC6, so member calls are
  used; only the genuinely unaliased constructors/`Pak_Open` need explicit
  `--symbol` bindings.
* **`dllimport` calls.** `__declspec(dllimport) __stdcall GetFileAttributesA`
  makes MSVC read the IAT slot directly; when the function is called twice the
  compiler hoists the slot load into EDI (`mov edi,ds:IAT`), matching the
  shipped `GetFileAttributes` probe.
* **Slots are 6 bytes but the visible range is 2 shorts.** `RecordList`
  slots copy 6 bytes, but the record/variant writes in the shipped
  `UI_RecordList_SetVisibleRange` touch only +0 and +2. Declaring the middle
  `short first` field moved the range end to +4 and left a 2-byte residue; the
  matched layout is `{ short value; short last; short reserved; }`.
* **Signed power-of-two test.** The shipped second probe is
  `and eax,0x8000000f; jns; dec; or 0xfffffff0; inc; jne`, which is VC6's
  signed `% 16` sequence, not an `and 0x10` test.

## Commits

| commit | content |
| --- | --- |
| `99cf69ff` | three strict matches (0x5086e0, 0x522f40, 0x404460) |
| `06720d67` | three strict C++ EH matches (0x4a1940, 0x513c90, 0x5317b0) plus the EH findings |
| `bf760570` | near-miss evidence for 0x47cb70, 0x49f640, 0x535c10 (0x49f640 was later promoted) |
| `c75bd011` | promote 0x49f640 to strict and record the final 7/9 result |

## Reproduction

```sh
# strict set
sh reconstructed/match/batch21/part1/verify_strict.sh

# one near miss (must report match false with the row's first diff)
python3 tools/match_decomp.py 0x47cb70 \
  reconstructed/match/batch21/part1/nonmatching/0x47cb70.c \
  --length 156 --entry '?GetAverageCompanyValueByByte8@Game@@QAEHD@Z' \
  --flags '/O2 /TP' --strict --auto-symbols
```
