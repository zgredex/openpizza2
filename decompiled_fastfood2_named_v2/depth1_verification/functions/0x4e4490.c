// rea decompile_all
// name: Game_GetAdjustedValue
// address: 0x4e4490
// body: available
// range: 0x4e4490-0x4e45d7 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __fastcall Game_GetAdjustedValue(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  
                    /* Adjusts a value by the current player/company state. */
  lVar4 = __ftol();
  iVar2 = *(int *)(param_1 + 0xc);
  iVar3 = (int)lVar4 + *(int *)(param_1 + 0x18) + *(int *)(param_1 + 8);
  iVar1 = FUN_00482820((int)DAT_0057c670);
  if (iVar2 == iVar1) {
    iVar1 = *(int *)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8);
    if (*(int *)(iVar1 + 0xc4) == 0) {
      if (*(int *)(iVar1 + 0x1ac) != 0) {
        iVar3 = 0x78;
      }
    }
    else {
      iVar3 = (iVar3 * 0xf) / 10;
    }
  }
  if (iVar2 != -1) {
    FUN_004017f0((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),(int *)0x0);
    iVar2 = FUN_00488be0(DAT_0057c670,*(int *)(param_1 + 0xc));
    iVar2 = FUN_004ddcc0(iVar2);
    lVar4 = __ftol();
    iVar3 = ((int)lVar4 * ((*(int *)(iVar2 + 100) + *(int *)(iVar2 + 0x4c)) * 3 + 100)) / 100;
  }
  if ((0 < *(int *)(param_1 + 8)) && (iVar3 < 0x3c)) {
    return 0x3c;
  }
  iVar2 = 500;
  if (iVar3 < 0x1f5) {
    iVar2 = iVar3;
  }
  return iVar2;
}

