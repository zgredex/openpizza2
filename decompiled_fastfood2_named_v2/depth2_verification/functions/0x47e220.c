// rea decompile_all
// name: FUN_0047e220
// address: 0x47e220
// body: available
// range: 0x47e220-0x47e3f3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_0047e220(undefined4 *param_1)

{
  undefined4 *puVar1;
  LPVOID pvVar2;
  int iVar3;
  int iVar4;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0055805e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_0055c30c;
  iVar3 = 0;
  local_4 = 8;
  *(undefined4 *)(param_1[0x5bc] + 0x94) = 0;
  puVar1 = *(undefined4 **)(param_1[0x5bc] + 0x74);
  if (puVar1 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1[0x5bc] + 0x74) = 0;
    (**(code **)*puVar1)(1);
  }
  IDMap_FreeValuesAndReset(param_1 + 0x540);
  if ((undefined4 *)param_1[0x538] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x538])(1);
  }
  iVar4 = param_1[0x5c3];
  if (0 < iVar4) {
    do {
      puVar1 = (undefined4 *)FUN_004017f0(param_1 + 0x5be,iVar3,(int *)0x0);
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar4);
  }
  iVar3 = param_1[0x53e];
  iVar4 = 0;
  if (0 < iVar3) {
    do {
      puVar1 = (undefined4 *)FUN_004017f0(param_1 + 0x539,iVar4,(int *)0x0);
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar3);
  }
  iVar3 = param_1[0x676];
  iVar4 = 0;
  if (0 < iVar3) {
    do {
      pvVar2 = (LPVOID)FUN_004017f0(param_1 + 0x671,iVar4,(int *)0x0);
      FUN_0054dd78(pvVar2);
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar3);
  }
  iVar3 = param_1[0x66b];
  iVar4 = 0;
  if (0 < iVar3) {
    do {
      pvVar2 = (LPVOID)FUN_004017f0(param_1 + 0x666,iVar4,(int *)0x0);
      FUN_0054dd78(pvVar2);
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar3);
  }
  FUN_004d28b0(param_1[0x5bc]);
  FUN_004810e0((int)param_1);
  local_4._0_1_ = 7;
  FUN_00401480(param_1 + 0x678);
  local_4._0_1_ = 6;
  FUN_00401480(param_1 + 0x671);
  local_4._0_1_ = 5;
  FUN_00401480(param_1 + 0x666);
  local_4._0_1_ = 4;
  FUN_00401480(param_1 + 0x5d8);
  local_4._0_1_ = 3;
  FUN_00401480(param_1 + 0x5d1);
  local_4._0_1_ = 2;
  FUN_00401480(param_1 + 0x5ca);
  local_4._0_1_ = 1;
  FUN_00401480(param_1 + 0x5be);
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_00401480(param_1 + 0x540);
  local_4 = 0xffffffff;
  FUN_00401480(param_1 + 0x539);
  ExceptionList = pvStack_c;
  return;
}

