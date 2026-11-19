// rea decompile_all
// name: FUN_004fdb20
// address: 0x4fdb20
// body: available
// range: 0x4fdb20-0x4fdbd7 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_004fdb20(void *param_1,undefined4 param_2,void *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = FUN_0047fed0((int)param_3);
  if (iVar1 != 0) {
    uVar2 = FUN_004fdcf0(param_1,(int)param_3,0);
    return uVar2;
  }
  iVar1 = Rating_GetInverse100((int)param_3);
  if (iVar1 < 0x29) {
    uVar2 = FUN_004fdcf0(param_1,(int)param_3,0);
    return uVar2;
  }
  iVar1 = FUN_0047aac0(param_3,0xffffffff);
  iVar5 = 0;
  if (0 < iVar1) {
    do {
      piVar3 = (int *)IDMap_Lookup((void *)((int)param_3 + 0x1500),iVar5,(int *)0x0);
      if (piVar3 != (int *)0x0) {
        if (*(int *)(*piVar3 + 0xc) < 0x15) {
LAB_004fdbbf:
          uVar2 = FUN_004fdcf0(param_1,(int)param_3,1);
          return uVar2;
        }
        iVar4 = Rating_AdjustB(*piVar3);
        if (iVar4 < 0x15) goto LAB_004fdbbf;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar1);
  }
  return 3;
}

