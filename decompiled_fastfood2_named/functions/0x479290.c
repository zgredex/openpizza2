// rea decompile_all
// name: FUN_00479290
// address: 0x479290
// body: available
// range: 0x479290-0x4793a8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00479290(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  float local_20;
  int local_14 [5];
  
  local_14[0] = 0;
  local_14[1] = 0;
  local_14[2] = 0;
  local_14[3] = 0;
  iVar3 = -1;
  local_14[4] = 0;
  iVar4 = 0;
  local_20 = 100.0;
  if (0 < *(int *)(param_1 + 0x170c)) {
    do {
      iVar1 = IDMap_Lookup((void *)(param_1 + 0x16f8),iVar4,(int *)0x0);
      if (iVar1 != 0) {
        iVar1 = IDMap_Lookup((void *)(DAT_0057c670 + 0x74),*(int *)(iVar1 + 4),(int *)0x0);
        iVar1 = *(int *)(iVar1 + 0x10);
        if (iVar1 != 4) {
          local_14[iVar1] = local_14[iVar1] + 1;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x170c));
  }
  iVar4 = 0;
  iVar1 = 0;
  piVar2 = local_14;
  do {
    if (iVar4 < *piVar2) {
      iVar3 = iVar1;
      iVar4 = *piVar2;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 < 5);
  if (iVar3 == -1) {
    *(undefined4 *)(param_1 + 0x1854) = 0;
    return;
  }
  iVar1 = 0;
  piVar2 = local_14;
  do {
    if (((iVar1 != iVar3) && (*piVar2 != 0)) && (0 < iVar4)) {
      local_20 = local_20 - ((float)*piVar2 / (float)iVar4) * 100.0;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 < 4);
  if (iVar4 == 0) {
    local_20 = 0.0;
  }
  lVar5 = FUN_00403850(local_20);
  *(int *)(param_1 + 0x1854) = (int)lVar5;
  FUN_00477100((int *)(param_1 + 0x1854));
  return;
}

