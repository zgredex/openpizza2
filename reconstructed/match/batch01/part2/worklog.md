# Batch 01 / part 2 worklog

25 records from `reconstructed/match/batch01/part2.json`.

**Result: 15 matched, 10 unresolved.**  Run
`reconstructed/match/batch01/part2/verify_matches.sh` to re-check every match.
The script prints `address match first_difference difference_count` and only
`True` lines are matches.

## Toolchain notes

* Candidates are compiled by `tools/match_decomp.py` with `/O2`; functions with
  `thiscall` callees need C++ mode, so they are passed `--flags "/O2 /TP"`.
  Constructors that need MSVC unwind frames additionally use `/GX`.
  VC6's C front end rejects `__thiscall` (C4234), and emulating it with
  `__fastcall` + a dummy `edx` parameter perturbs register allocation in larger
  functions.  Plain C + `__fastcall` is used only for the four scalar deleting
  destructors.
* Since commit `5cb2219c` the matcher copies the original PE's linker-resolved
  `DIR32`/`REL32` fields at the same offset, so COMDAT `.text$x` EH thunks and
  other linker-placed targets no longer need to be expressed with `--symbol`.
  `--symbol` is now only used for the optional `--strict-symbols` check.
* String/float operations: `#pragma intrinsic(strcpy/strcat)` reproduces the
  inline `rep movs` sequences; `__ftol`, `_strrchr`, `_rand` and
  `_operator_new` are resolved with `--symbol` (see the verify script for the
  exact addresses).
* Jump tables emitted immediately after a function body work correctly: the
  COFF `DIR32` relocation resolves to `address + table_symbol.value`, which
  equals the original table address whenever the table follows the function in
  `.text` (verified for 0x48c220, 0x499600 and 0x49d300).

## Matches

| address | entry symbol | flags | notes |
|---|---|---|---|
| 0x4012e0 | `@NamedLockable_Delete@12` | `/O2` | C, `__fastcall` thiscall emulation |
| 0x4039d0 | `?Construct@TimerClass@@QAEPAXXZ` | `/O2 /TP` | inline `strcpy`, `_CreateEventA` (stdcall ptr), `_CRT_BeginThread` |
| 0x47a920 | `?ApplyStatsToOwner@Branch@@QAEXXZ` | `/O2 /TP` | nested lookup call had to be written as a call argument to reproduce the early `push 0` |
| 0x48c220 | `?AbortOrdersTargetingObject@GameRoot@@QAEXHHPAX@Z` | `/O2 /TP` | switch table at function+0x78 |
| 0x499600 | `?CreateRecipePage_FillIngredientDetails@@YAXPAXH@Z` | `/O2 /TP` | format calls inside each switch case; `double` temp forced the original `fld qword` first |
| 0x49d300 | `?ContestRecipePage_FillIngredientDetails@@YAXPAXH@Z` | `/O2 /TP` | same body as 0x499600 with contest globals |
| 0x4a7180 | `?BauenPage_UpdateBuildingMarket@@YAXPAXD@Z` | `/O2 /TP` | virtual dtor calls; a local `value` variable reproduces the conditional else-load |
| 0x4cfa20 | `?BranchScreen_UpdateTabButtons@@YAXPAX@Z` | `/O2 /TP` | count local must *not* replace `param_1`; `iVar2 <= 2 || count <= 0` reproduces `cmp ebx,2/jle` |
| 0x4e47c0 | `@Ingredient_Delete@12` | `/O2` | |
| 0x4f5e20 | `@Player_MissionState_Delete@12` | `/O2` | |
| 0x501a10 | `@AwardNode_Delete@12` | `/O2` | |
| 0x527090 | `?LoadFontByName@UI@@QAEIPAD@Z` | `/O2 /TP` | inline `strcpy` + `strcat`, `strrchr` call |
| 0x5316f0 | `?SetChildVisibleByID@UI_SetChildVisibleByID_t@@QAEHHH@Z` | `/O2 /TP` | branch polarity (`!= 0` first) was needed |
| 0x4ddb80 | `?AddBranchPlan@Player@@QAEHPAX@Z` | `/O2 /GX /TP` | `new GamePlan` EH frame; handler thunk normalized by `5cb2219c` |
| 0x5335f0 | `??1SpriteFile@@UAE@XZ` | `/O2 /GX /TP` | destructor with base-destructor EH frame; pointer temporary forced the original `mov eax,[esi+0x80]` form |

Reproduce any match with the exact command in `verify_matches.sh`.

## Unresolved

Candidates for the four reconstructed-but-not-matching EH functions are in
`part2/nonmatching/`; they are **not** matches.

| address | length | first diff | diagnosis |
|---|---|---|---|
| 0x4eef40 | 373 | +0x2: orig `55` (`push ebp`), cand `8b` | Register allocation: original spills `this` to `[esp+4]` and keeps `param_1` in `ebp`; VC6 keeps `this` in `ebp` and `param_1` in `ebx`. Tried typed structs, source/declaration reordering, a local `this_`, free `__fastcall`, and `/Gx /Oi /Ob1 /Og /Oa /Ow /Op /Os /Ot /Oy /Zi`; prologue never changes. |
| 0x509a20 | 438 | +0x15 (branch displacement), then +0x171 `4c` vs `4a` | Switch sharing: original emits `cmp eax,N; jmp common; common: jl after` and a single `store 100; ret` block shared by cases 0/2/3/default. `/O2` duplicates the `jl` and fail block per case. `/O1` produces the shared form but the wrong frame-less `/O2` epilogue. Polarity (`>=`/`<`), explicit `goto fail`, a `limit` variable, and case source order permutations were tried. |
| 0x4c4bd0 | 600 | +0x8: orig `8b` (`mov ecx,DAT_0057dcf4`), cand `53` (`push ebx`) | Scheduling/register choice in the first block: original evaluates the member-call object before pushing its argument and uses `ebx` for the zero init; VC6 uses `edi` and loads the object late. Zeroing order, `int local_c[3] = {0}`, a `Game *game` local, and `volatile` variants were tried. |
| 0x4dc760 | 559 | +0x2: orig `18` (frame 0x18), cand `1c` (frame 0x1c) | `this_00` (the `[DAT_0057c5cc+0x2c3d4]` pointer) gets a stack home slot in the candidate; the original keeps it in `ebp` with exactly six 4-byte locals. Typed `RecSet*`, `const`, `register`, `static`, declaration order and inlining the global expression were tried. Inlining removes the frame delta but reloads the global at every call. |
| 0x4cec60 | 893 | +0x36 `84` vs `ac` (no volatile), +0x3c `8b` vs `89` (volatile count) | Long-lived company-value local: original spills it to `[esp+0x10]` (then uses `ebx`/`ebp` for the boolean pairs); candidate keeps it in `ebp`. Marking it `volatile` reproduces the spill (`+0x3c` only differs by store scheduling relative to `mov esi,[esp+0x18]`). |
| 0x4d87f0 | 960 | +0x17: orig `0c`, cand `10` (frame `0x10c` vs `0x110`) | EH/frame size from the reconstructed `new`-heavy loop and its local/exception slots; much of the switch/new code also differs (`746` differing bytes). Candidate in `nonmatching/`. |
| 0x521000 | 349 | +0x1d: orig `18`, cand `1c` | Constructor argument/register allocation: original saves only `ebx/esi/edi` at entry and pushes `ebp` later; candidate allocates `ebp` early for the fourth base-ctor argument. Candidate in `nonmatching/`. |
| 0x532400 | 178 | +0x1d: orig `d9` (`mov ebx,ecx`), cand `e9` (`mov ebp,ecx`) | Register permutation for `this`/`new` result (`ebx`/`edi` in original vs `ebp`/`esi` in candidate); EH frame and state values otherwise match. Candidate in `nonmatching/`. |
| 0x547030 | 401 | +0x71: orig `88` (`mov [esi+0xfe],bl`), cand `b8` | EH state-store scheduling after the lock constructor; also the `[esi+0x174]` zero store is folded to `mov [esi+0x174],ebx` instead of the original `lea eax,[esi+0x174]` + `mov [eax],ebx`. Candidate in `nonmatching/`. |
| 0x4aab00 | 2812 | — | largest record; not attempted in the available time. |

### EH-frame status

Commit `5cb2219c` normalizes linker-resolved `DIR32`/`REL32` fields from the
original PE, which removes the old `.text$x` thunk-address blocker.  With that
matcher, `0x4ddb80` and `0x5335f0` are now exact C++ `/GX` matches.  The other
four EH functions are reconstructed (`nonmatching/`) but still differ for the
ordinary codegen reasons listed above, not because of EH relocation handling.
