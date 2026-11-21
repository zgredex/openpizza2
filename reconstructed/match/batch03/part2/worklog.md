# batch03/part2 worklog

Part 2 of batch 3: 25 tiny functions (18-24 bytes) from `../part2.json`.
Toolchain: `/tmp/opencode/vc6-sp3-toolchain/VC98` (`wine CL.EXE`, C2.DLL
12.00.8447). Every candidate is genuine C++ compiled `/O2 /TP`; there is no
`__asm`/`asm {` and no hand-written machine code.

## Verification

From the repository root:

```sh
bash reconstructed/match/batch03/part2/verify_strict.sh
```

The script runs `tools/match_decomp.py` once per record with the manifest
length, the candidate's own mangled entry symbol, `/O2 /TP`, `--strict` and
`--auto-symbols`, and accepts only `"strict_match": true`.

Result on the final tree: **25/25 strict matches**. Every relocation target
resolves through `--auto-symbols`; no explicit `--symbol` map is needed.

The batch-runner form gives the same result:

```sh
python3 tools/match_batch.py reconstructed/match/batch03/part2.json \
  reconstructed/match/batch03/part2 --flags "/O2 /TP" \
  --strict --auto-symbols
```

## Matched (25)

| address | name | bytes | entry | notes |
|---|---|---|---|---|
| 0x4dd650 | Game_SetGlobalWord16 | 21 | `?SetGlobalWord16@Game@@QAEXG@Z` | ushort store at +4, then zero-extend to global 0x57dfbc with `and eax,0xffff`; `ret 4` |
| 0x4ddca0 | Player_RemoveObjectReference | 19 | `?RemoveObjectReference@Player@@QAEXH@Z` | IDMap at +0x180, calls `IDMap_RemoveByKey` 0x401790 |
| 0x4e4160 | Object_GetPair68 | 21 | `?GetPair68@Object@@QAEXPAH0@Z` | copies fields +0x68 and +0x6c to the two out pointers |
| 0x4e4180 | Array_FindEmptySlot8 | 21 | `?FindEmptySlot8@Array8@@QAEXXZ` | flat `for` over 8 slots of stride 12; returns on `short == -1` |
| 0x4eacb0 | Game_RemoveIDMapEntry | 19 | `?RemoveIDMapEntry@Game@@QAEXH@Z` | Map at +0x2c3f8; helper must be class `Map` so auto-symbols maps `Map_LookupLinear` (0x401930) |
| 0x4eb8e0 | Map_MissingNameFallback | 22 | `?Map_MissingNameFallback@@YAHHH@Z` | cdecl `Debug_WarningMessageBox(&DAT_00571af4, arg2)`, then `return -1`; first arg is unused |
| 0x4f2a60 | IsMenuId352 | 18 | `?IsMenuId352@@YG_NH@Z` | `__stdcall bool`; `cmp ecx,0x352; sete al; ret 4` |
| 0x4f3b10 | Array_GetField4Stride12 | 21 | `?Array_GetField4Stride12@@YGHHH@Z` | `__stdcall`; `*(base+8) + index*12 + 4` |
| 0x50d7f0 | Object_GetLevelProperty | 24 | `?GetLevelProperty@Object@@QAEHH@Z` | `Object_GetClampedLevel` 0x50e810; table 0x56d0e0 indexed by `index + level*2 + level` to get the `lea`/`add` pair |
| 0x50dbd0 | State_Is2DOr2E | 22 | `?State_Is2DOr2E@@YIHPAX@Z` | field +0x38 equals 0x2d or 0x2e; shared true block |
| 0x50e4c0 | Object_SetChildField2C | 20 | `?SetChildField2C@Object@@QAEXH@Z` | child pointer at +0xc8; guarded store at child +0x2c |
| 0x50e520 | Person_ClearCompletedAction | 23 | `?ClearCompletedAction@Person@@QAEXXZ` | loads field +0x74 into eax before the -1 store at +0x108, then tail-jumps to `Person_ReturnToHomeBase` 0x507fd0 |
| 0x50efc0 | Player_ResetAiState | 21 | `?Player_ResetAiState@@YIXPAX@Z` | stores 1 at +0x84 and 0 at +0x88 |
| 0x50fe50 | Game_CountActiveStats | 23 | `?Game_CountActiveStats@@YIHPAX@Z` | 0x56 ints from +0x64; count in eax, counter in edx, pointer in ecx |
| 0x5104d0 | Game_MapInputIndex | 23 | `?MapInputIndex@Game@@QAEXH@Z` | maps 8 to 5, then thiscall `Index_Map8To5` 0x513980 |
| 0x510c70 | Output_StorePair | 23 | `?Output_StorePair@@YGXPAM0MM@Z` | `__stdcall` with two pointers and two floats; x87 load/store order preserved |
| 0x5140e0 | Storage_ChargePurchaseCost | 22 | `?ChargePurchaseCost@Storage@@QAEXXZ` | byte +0x3c zero test, `fild` int +0x40, thiscall call 0x514100 with `(float, 1)` and `push ecx` used as the float slot |
| 0x514220 | LookupTable_HasKey | 23 | `?HasKey@Array@@QAE_NH@Z` | `FindPair(key) != -1`; helper must be class `Array` so auto-symbols maps `Array_FindPair` (0x5140b0) |
| 0x514240 | Array_CountNonZero20 | 23 | `?Array_CountNonZero20@@YIHPAX@Z` | 0x14 entries of stride 0xc from +0x60, count non-zero |
| 0x51ea00 | RefPtr_Release | 21 | `?RefPtr_Release@@YIXPAX@Z` | clears +0x14, virtual `Release(1)` through `[obj][0]` |
| 0x51ef60 | Object_GetByte36Max7 | 22 | `?Object_GetByte36Max7@@YIHPAH@Z` | combined `child != 0 && byte <= 7` condition; CSE keeps the byte in al and zero-extends with `and eax,0xff` |
| 0x521ae0 | UI_GetChildSize | 21 | `?GetChildSize@UI@@QAEXPAH0@Z` | sprite at +0x60, calls `Sprite_GetSize` 0x53d090 |
| 0x521b10 | Object_GetActiveValue | 23 | `?Object_GetActiveValue@@YIIPAX@Z` | tests field +0x6c for non-zero first, then `field78 != 0 ? 0 : value`; mask is `neg/sbb/not/and` |
| 0x522f20 | Array_Destroy | 21 | `?Destroy@Array@@QAEXXZ` | installs vtable 0x55c774, then cdecl `Mem_Free` 0x54dd78 with `pop ecx` cleanup |
| 0x5260e0 | Object_GetId | 20 | `?Object_GetId@@YGHPAX@Z` | `__stdcall`; null returns -1, otherwise field +4 |

## Findings

- All 25 are thiscall members or `__fastcall`/`__stdcall` free functions.
  VC6's C front end rejects `__thiscall`, so every thiscall is modelled as a
  C++ member function and the file is compiled with `/TP`. No dummy second
  `__fastcall` argument is needed in this part.
- Auto-symbol resolution depends on the helper class name. `IDMap::LookupLinear`
  produced `?LookupLinear@IDMap@@QAEXH@Z`, which has no entry in the shipped
  symbol map, and `LookupTable::FindPair` likewise missed `Array_FindPair`.
  Both candidates matched byte-for-byte but failed strict on the unresolved
  relocation; naming the helper classes `Map` and `Array` makes
  `llvm-undname` + `resolve_auto_symbol` find the shipped names.
- VC6 unrolled the do/while form of 0x4e4180 into a 32-byte two-way loop.
  The equivalent flat `for (int i = 0; i < 8; i++)` keeps the shipped rolled
  21-byte loop.
- 0x51ef60 is sensitive to how the clamp is written. A byte temporary plus two
  separate `if` statements compiles to a 48-byte branchless `sbb/not/and`
  clamp with a stack spill. Writing the two source loads inside one combined
  condition lets CSE keep the byte in `al` and emit the shipped
  `mov al,[eax+0x36]; cmp al,7; ja; and eax,0xff` sequence.
- Block layout matters for strict full-extent equality even when the
  instruction set is identical: 0x521b10 only matches when the non-zero case
  is tested first (`je` to the field68 return). Testing the zero case first
  emits the mirror image (`jne`) with the same semantics.
- 0x50d7f0 needs the index expression written as `index + level*2 + level`;
  `index + level*3` changes the `lea`/`add` pairing.

## Unmatched

None. Five superseded attempts are kept under `nonmatching/` for evidence:

| address | attempt | first difference |
|---|---|---|
| 0x4e4180 | do/while pointer loop | offset 0: original 0x33 (`xor eax,eax`) vs 0x8d (`lea`); candidate extent 32 vs 21 |
| 0x51ef60 | `unsigned char` temp + two ifs | offset 0: original 0x8b (`mov eax,[ecx]`) vs 0x51 (`push ecx`); candidate extent 48 vs 22 |
| 0x521b10 | zero case tested first | offset 5: original 0x74 (`je`) vs 0x75 (`jne`); 14 differing bytes |
| 0x4eacb0 | `IDMap` helper class | bytes equal; strict issue `undefined symbol ?LookupLinear@IDMap@@QAEXH@Z` |
| 0x514220 | `LookupTable` helper class | bytes equal; strict issue `undefined symbol ?FindPair@LookupTable@@QAEHH@Z` |
