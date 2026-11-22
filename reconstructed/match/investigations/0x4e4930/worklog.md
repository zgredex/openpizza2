# Ingredient_LoadMarketTable at `0x4e4930`

The shipped function covers 5,163 bytes. The loader opens `Size.tab`, allocates 86 entries with `new Ingredient(id)`, reads 32 pairs of words into each entry, and makes 86 calls to `Game_SetBuildingDesc`. The generator recovers the repeated calls from the named export. Its declarations use signed bytes for the narrow arguments and reconstruct the `double` from the export's low and high dwords. The pinned PE confirms the direct call counts. Comparison of the original and compiled descriptor calls checked all 1,204 stack argument slots.

```sh
python reconstructed/match/investigations/0x4e4930/ingredient_loader.py \
  --out /tmp/pc2-ingredient-loader --verify
```

Run with Capstone 5.0.7 and the [pinned VC6 SP3 toolchain](../../VC6_TOOLCHAIN.md). The best candidate uses `/O2 /GX /TP`. Generation alone omits `--verify`. The verifier writes the candidate, COFF, and full receipt in the chosen scratch directory and returns nonzero for a non-strict result.

The best candidate is **18 code bytes away from a strict match**. Its first difference is at `+0xc3`, where VC6 starts the pair of word loads with the high value in AX. The original starts with the low value in DX. The rest of the loop places the repeated tail at its original address. Independent relocation verifies all 4,880 tail bytes from `0x4e4a4b` through the return, including every descriptor-call chunk. The separate EH code at `0x559530` and data at `0x55f0e0` also verified. The handler anchor is the unique CRT dispatch stub between the independently identified neighboring funclets, and the strict matcher resolves and compares the EH sections.

The initial `/O2 /GX /TP` source had 1,567 code-byte differences. Ordering the outer loop setup and separating its slot and index updates reduced that to 18. The three subsequent inner-loop experiments had 18, 20, and 3,348 differences. This function remains outside the strict totals.
