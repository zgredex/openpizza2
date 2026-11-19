// rea decompile_all
// name: Settings_InitDefaults
// address: 0x406a90
// body: available
// range: 0x406a90-0x406ba7 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Settings_InitDefaults(void)

{
  bool bVar1;
  undefined3 extraout_var;
  uint *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar4 = &DAT_0057b8a8;
                    /* Depth-2 proposal batch 3. */
  for (iVar3 = 0x59; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  bVar1 = FUN_00406bb0();
  if (CONCAT31(extraout_var,bVar1) == 0) {
    DAT_0057b9f0 = 5;
    DAT_0057b9f8 = 4;
    DAT_0057b9fc = 0;
    DAT_0057b9f4 = 0;
    DAT_0057b938 = FUN_004034d0(0,1);
    DAT_0057b93c = FUN_004034d0(0,DAT_0058557c - 1);
    DAT_0057b940 = FUN_004034d0(0,DAT_00585580 - 1);
    DAT_0057b944 = FUN_004034d0(0,DAT_00585584 - 1);
    DAT_0057b948 = FUN_004034d0(0,DAT_00585588 - 1);
    DAT_0057b9c8 = 0xfa;
    DAT_0057b9d0 = 0xffffffff;
    DAT_0057b9d4 = 0xffffffff;
    DAT_0057b9d8 = 0xffffffff;
    DAT_0057b9cc = 0xb;
    DAT_0057b964 = 1;
    DAT_0057b968 = 0;
    DAT_0057b96c = 1;
    DAT_0057b970 = 1;
    _DAT_0057b9dc = 3;
    DAT_0057b978 = 6;
    puVar2 = &DAT_0057b9ac;
    do {
      puVar2[-0xc] = 100;
      puVar2[-6] = 0;
      *puVar2 = (uint)((int)puVar2 < 0x57b9b4);
      puVar2 = puVar2 + 1;
    } while ((int)puVar2 < 0x57b9c4);
  }
  return;
}

