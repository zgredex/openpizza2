# Ingredient_LoadMarketTable at `0x4e4930`

The shipped function covers 5,163 bytes. The loader opens `Size.tab`, allocates 86 entries with `new Ingredient(id)`, reads 32 pairs of words into each entry, and makes 86 calls to `Game_SetBuildingDesc`. The generator recovers the repeated calls from the named export. Its declarations use signed bytes for the narrow arguments and reconstruct the `double` from the export's low and high dwords. The pinned PE confirms the direct call counts. Comparison of the original and compiled descriptor calls checked all 1,204 stack argument slots.

```sh
python reconstructed/match/investigations/0x4e4930/ingredient_loader.py \
  --out /tmp/pc2-ingredient-loader --verify
```

Run with Capstone 5.0.7 and the [pinned VC6 SP3 toolchain](../../VC6_TOOLCHAIN.md). The strict recipe uses `/O2 /GX /TP`. Generation alone omits `--verify`. The verifier writes the candidate, COFF, and full receipt in the chosen scratch directory.

The final generator is a **strict match across all 5,163 code bytes**. Declaring both word buffers before the nested row and column loops preserves their lifetime across iterations. With that scope, VC6 loads the low word in DX and stores it before loading the high word in AX, matching the shipped instruction sequence. Independent relocation also compares the 4,880-byte descriptor tail at `0x4e4a4b` and verifies the 21-byte EH code at `0x559530` and 40-byte data at `0x55f0e0`. The EH anchor is the unique CRT dispatch stub between two independently identified neighboring funclets. The verified spans linked into a byte-identical scratch PE.

The initial `/O2 /GX /TP` candidate had 1,567 code-byte differences. Ordering the outer setup and separating the slot and index updates reduced that to 18. The final 12-case matrix held the flags and the rest of the source fixed.

| Word-copy source shape | Cases | Code-byte differences | Relocated tail equal |
| --- | ---: | ---: | --- |
| Buffers declared outside the nested loops | 1 | 0 | Yes |
| Explicit pointer to the low destination | 1 | 8 | Yes |
| Array or struct buffers, declaration order, signed locals, named copies, comma sequencing | 8 | 18 | Yes |
| Volatile read or read/write views | 2 | 3,889 | No |
