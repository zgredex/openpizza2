// rea decompile_all
// name: FUN_004d73c0
// address: 0x4d73c0
// body: available
// range: 0x4d73c0-0x4d74be inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_004d73c0(undefined4 *param_1)

{
  undefined4 *puVar1;
  LPVOID pvVar2;
  int iVar3;
  int iVar4;
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_005590cc;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_0055c500;
  local_4 = 1;
  if ((undefined4 *)param_1[0x3ea] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x3ea])(1);
  }
  iVar3 = 0;
  if (0 < (int)param_1[0x3f0]) {
    do {
      puVar1 = (undefined4 *)FUN_004017f0(param_1 + 0x3eb,iVar3,(int *)0x0);
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)param_1[0x3f0]);
  }
  List_Node_Reset((int)(param_1 + 0x3eb));
  iVar3 = param_1[0x3f7];
  iVar4 = 0;
  if (0 < iVar3) {
    do {
      pvVar2 = (LPVOID)FUN_004017f0(param_1 + 0x3f2,iVar4,(int *)0x0);
      FUN_0054dd78(pvVar2);
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar3);
  }
  List_Node_Reset((int)(param_1 + 0x3f2));
  if ((undefined4 *)param_1[0x42a] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x42a])(1);
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00401480(param_1 + 0x3f2);
  local_4 = 0xffffffff;
  FUN_00401480(param_1 + 0x3eb);
  ExceptionList = pvStack_c;
  return;
}

