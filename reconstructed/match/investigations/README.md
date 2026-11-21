# Miss investigation matrix

`tools/compiler_matrix.py` compiles each variant with the pinned VC6 SP3
compiler and records the compiler hashes, flags, entry, first differing
instruction and total differing bytes.

```sh
python3 tools/compiler_matrix.py \
  reconstructed/match/investigations/matrix01.json \
  --json-out reconstructed/match/investigations/matrix01.json.out
```

Compiler hashes for this matrix:

```text
CL.EXE    d9220fdfaf355c81f26e7b03c5dc628ec72ff81c99dc38ed98b1ad4bdbbb309c
C2.DLL    a0cc45f83fd0ed009aa4f43df5598105a1049ad9675de0b1089be7cce7d3c153
LINK.EXE  9672e578fdfaa43bdb8e9c16071682988665cb90bba2904bf02f6a5576d8ffbc
```

## Results

| target | variant | differing bytes | first instruction |
|---|---|---|---|
| 0x4ecd70 | base `/O2 /TP` | 9 | `mov esi,[esp+0x28]` |
| 0x4ecd70 | `/O2 /Oy` | 9 | same |
| 0x4ecd70 | `/O1` | 431 | `sub esp,0x18` |
| 0x4ecd70 | stream volatile | 505 | `push ebx` |
| 0x4ecd70 | self local | 9 | same |
| 0x509a20 | base `/O2` | 320 | `je 0x509a6c` |
| 0x509a20 | `/O1` | 293 | `push esi` |
| 0x509a20 | `/Os` | 388 | `push ebx` |
| 0x509a20 | `/Ot` | 384 | `push ebx` |
| 0x509a20 | inverted switch | **177** | `je 0x509a6c` |
| 0x509a20 | inverted + `/O1` | 294 | `push esi` |
| 0x532400 | base | 152 | `push 0xffffffff` |
| 0x532400 | base `/GX` | 110 | `mov ebx,ecx` |
| 0x532400 | out-of-line ctor `/GX` | **28** | `push 0xffffffff` |
| 0x532400 | volatile new | 134 | `sub esp,0x8` |

## Next experiments

- `0x4ecd70`: the nine-byte prologue difference is unchanged by `/Oy`,
  `/O1`, the volatile stream local, and the self local. Park the member
  signature; the next experiment should change the first live use of `this`
  without changing the body (e.g. an explicit self alias passed through the
  stream read).
- `0x509a20`: the inverted-switch source is the clear winner (177 vs 320).
  Next try `/Ob1`, `/Ob2`, `/Oy`, `/G6` and a `default:` block on that source,
  then inspect branch/table layout separately.
- `0x532400`: the out-of-line constructor is the clear winner (28 vs 110).
  Next try constructor initializer order, `new SelectionGroup()` parentheses,
  and `/Ob1`/`/Ob2` on that variant, then compare the EH state stores.

No compiler setting from this matrix has been applied across a batch. Any
batch-wide flag change must first rerun a known matching sibling.
