// rea decompile_all
// name: FUN_0050fec0
// address: 0x50fec0
// body: available
// range: 0x50fec0-0x50ff7e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_0050fec0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  
  puVar6 = (undefined4 *)(param_1 + 0x1bc);
  for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  puVar6 = (undefined4 *)(param_1 + 100);
  for (iVar3 = 0x56; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  iVar5 = 0;
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x5c)) {
    do {
      iVar2 = IDMap_Lookup((void *)(param_1 + 0x48),iVar3,(int *)0x0);
      if (*(char *)(iVar2 + 0x11) == '\0') {
        iVar1 = *(int *)(DAT_0057c670 + 0xa8 + (uint)*(byte *)(iVar2 + 4) * 4);
        piVar4 = (int *)(param_1 + 100 + (uint)*(byte *)(iVar2 + 4) * 4);
        *piVar4 = *piVar4 + *(int *)(iVar1 + 0xac + (uint)*(byte *)(iVar2 + 6) * 4);
        piVar4 = (int *)(param_1 + 0x1bc + (uint)*(byte *)(iVar2 + 5) * 4);
        *piVar4 = *piVar4 + *(int *)(iVar1 + 0xac + (uint)*(byte *)(iVar2 + 6) * 4);
        iVar5 = iVar5 + *(int *)(iVar1 + 0xac + (uint)*(byte *)(iVar2 + 6) * 4);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x5c));
    if (0 < iVar5) {
      iVar3 = 7;
      piVar4 = (int *)(param_1 + 0x1bc);
      do {
        iVar3 = iVar3 + -1;
        *piVar4 = (*piVar4 * 100) / iVar5;
        piVar4 = piVar4 + 1;
      } while (iVar3 != 0);
    }
  }
  *(int *)(param_1 + 0x1d8) = iVar5;
  return;
}

