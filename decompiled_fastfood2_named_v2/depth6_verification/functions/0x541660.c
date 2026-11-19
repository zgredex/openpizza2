// rea decompile_all
// name: FUN_00541660
// address: 0x541660
// body: available
// range: 0x541660-0x541722 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00541660(undefined4 *param_1)

{
  int *piVar1;
  LPVOID pvVar2;
  LPVOID pvVar3;
  int iVar4;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0055af5b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_LAB_0055c8c8;
  piVar1 = (int *)param_1[0x17];
  local_4 = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *param_1 = &PTR_LAB_0055c874;
  local_4 = 2;
  if (*(char *)(param_1 + 0xd) != '\0') {
    FUN_00540f60((int)param_1);
  }
  piVar1 = (int *)param_1[0x12];
  if (piVar1 != (int *)0x0) {
    iVar4 = (**(code **)(*piVar1 + 0x48))(piVar1);
    if (-1 < iVar4) {
      if (*(char *)(param_1 + 0xd) != '\0') {
        FUN_00540f60((int)param_1);
      }
      (**(code **)(*(int *)param_1[0x12] + 0x34))((int *)param_1[0x12],0);
    }
    (**(code **)(*(int *)param_1[0x12] + 8))((int *)param_1[0x12]);
  }
  local_4 = CONCAT31(local_4._1_3_,1);
  pvVar3 = (LPVOID)param_1[0xe];
  while (pvVar3 != (LPVOID)0x0) {
    pvVar2 = *(LPVOID *)((int)pvVar3 + 4);
    FUN_0054dd78(pvVar3);
    pvVar3 = pvVar2;
  }
  param_1[0xe] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  *param_1 = &PTR_LAB_0055c840;
  ExceptionList = pvStack_c;
  return;
}

