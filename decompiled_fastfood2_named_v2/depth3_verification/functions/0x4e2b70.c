// rea decompile_all
// name: City_GetTopProductCategory
// address: 0x4e2b70
// body: available
// range: 0x4e2b70-0x4e2c08 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __fastcall City_GetTopProductCategory(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int local_1c [7];
  
                    /* Depth-3 proposal batch 3. */
  iVar1 = 0;
  puVar5 = &DAT_0057dfc0;
  for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  DAT_0057dfc0 = 0xffffffff;
  piVar2 = local_1c;
  do {
    *piVar2 = iVar1;
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 < 7);
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x124)) {
    do {
      iVar3 = FUN_004017f0((void *)(param_1 + 0x110),iVar1,(int *)0x0);
      piVar4 = &DAT_0057dfc4;
      piVar2 = (int *)(iVar3 + 0x1c0);
      do {
        iVar3 = *piVar2;
        piVar2 = piVar2 + 1;
        *piVar4 = *piVar4 + iVar3;
        piVar4 = piVar4 + 1;
      } while ((int)piVar4 < 0x57dfdc);
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x124));
  }
  FUN_0054ea8f(local_1c,(undefined4 *)0x7,4,&LAB_004e2c10);
  return local_1c[0];
}

