# batch11 part2 non-matching attempts

All files are genuine C++ (`/O2 /TP` unless noted) and were the closest
reachable shapes. The matcher command is the same as `verify_strict.sh` with
the function's manifest length. First diffs are byte offsets from the
function start.

| file | address | length | first diff | diff bytes | note |
|---|---|---:|---|---:|---|
| 0x5349e0.c | 0x5349e0 | 80 | offset 0x07 (7) | 39 | original keeps the sub-record address in a register; candidate recomputes `[eax+ecx*2]`; zero path uses immediate stores |
| 0x4030f0.c | 0x4030f0 | 81 | offset 0x16 (22) | 3 | original `mov ecx,[esi+4]` / `add eax,ecx`; candidate `mov esi,[esi+4]` / `add eax,esi` |
| 0x477c20.c | 0x477c20 | 81 | offset 0x01 (1) | 71 | original `push ebp; mov ebp,[ecx+0x14f8]`; candidate pushes/saves different registers and loads the parameter early |
| 0x52f7a0.c | 0x52f7a0 | 81 | offset 0x07 (7) | 8 | original writes local shorts in order +2,+0,+6,+4; candidate writes +0,+2,+4,+6 |
| 0x49fa70.c | 0x49fa70 | 82 | offset 0x0e (14) | 25 | original `mov edx,[ecx+0x124]; cmp eax,edx; jl`; candidate `cmp eax,[ecx+0x124]; jl` and loads the global later |
| 0x535cf0.c | 0x535cf0 | 83 | offset 0x00 (0) | 17 | original `push edi; mov edi,ecx` (palette in esi); candidate `push esi; mov esi,ecx` |
| 0x401280.c | 0x401280 | 84 | offset 0x1e (30) | 21 | original hoists `lea ebp,[ebx+0x1c]` before the name-NULL branch; candidate emits it after the inlined `strlen` |

Notes on the attempted variations:

- 0x5349e0: field-by-field vs `*out = *record`, chained zero assignment,
  aggregate zero struct, and pointer/local forms were tried.
- 0x4030f0: initialized/uninitialized base/offset locals, branch-swapped
  forms, inline `<< 4`, and free `__fastcall` form were tried; only the final
  base register differs.
- 0x477c20: hoisted count, explicit map local, direct member access and
  declaration-order variants were tried.
- 0x52f7a0: 12-byte vs 16-byte layout (frame 0x10), statement orders and
  explicit offset stores were tried.
- 0x49fa70: pre/post increment, local `total`, `++global` expression and
  declaration-order variants were tried.
- 0x535cf0: member function, local list pointer, `int *`/`int **` palette
  types, and `while`/`for` forms were tried.
- 0x401280: `dest` local declared before/after the branch, and direct
  `strcpy((char *)this + 0x1c, ...)` were tried.
