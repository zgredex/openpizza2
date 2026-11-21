# batch11 part1 non-matching attempts

All files are genuine C++ (`/O2 /TP`) and were the closest reachable shapes.
The matcher command is the same as `verify_strict.sh` with the function's
manifest length. First diffs are byte offsets from the function start.

| file | address | length | first diff | diff bytes | note |
|---|---|---:|---|---:|---|
| 0x505ef0.c | 0x505ef0 | 78 | offset 0x0c (12) | 29 | original `cmp eax,1` (dead compare of arg1) before the stores; candidate emits `cmp eax,1`-free code |
| 0x4da7c0.c | 0x4da7c0 | 79 | offset 0x3c (60) | 4 | stores `[eax-8]`/`[eax-4]` are swapped; all other bytes match |
| 0x52cba0.c | 0x52cba0 | 79 | offset 0x01 (1) | 54 | original `mov ecx,[esp+4]` (text in ecx); candidate uses edx and swaps text/start registers |
| 0x4a4190.c | 0x4a4190 | 80 | offset 0x07 (7) | 30 | original `push esi` then `xor ebx,ebx`; candidate initializes the counter before saving esi, and the loop back-edge differs |

Notes on the attempted variations:

- 0x505ef0: direct member access, local key/temporaries, `if`/`switch`/`?:`
  duplicate-store shapes, and `/O1`/`/Os`/`/Oy-` were tried; the original's
  dead compare on the mode argument could not be reproduced.
- 0x4da7c0: statement order, a temporary for the old value, direct member
  arrays and member-function forms were tried; the two stores are always
  scheduled in the opposite order.
- 0x52cba0: cdecl/stdcall/thiscall, `unsigned char *`, pointer scan, `while(1)`
  and `do` forms keep `text` in `edx` here.
- 0x4a4190: `do`/`while`/`for`, signed pointer casts, `index < 6` and
  `slot < 0x57d264` variants all produce a top test or an inverted loop.
