// rea decompile_all
// name: FUN_00488e20
// address: 0x488e20
// body: available
// range: 0x488e20-0x489039 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00488e20(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00558333;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_0055c44c;
  local_4 = 6;
  FUN_00488cc0(param_1);
  FUN_00528160((int)DAT_0057c5e0);
  if ((undefined4 *)param_1[0x24] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x24])(1);
  }
  param_1[0x24] = 0;
  if ((undefined4 *)param_1[0x25] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x25])(1);
  }
  param_1[0x25] = 0;
  if ((undefined4 *)param_1[0x24] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x24])(1);
  }
  param_1[0x24] = 0;
  if (DAT_0058072c != (undefined4 *)0x0) {
    (**(code **)*DAT_0058072c)(1);
    DAT_0058072c = (undefined4 *)0x0;
  }
  puVar1 = (undefined4 *)FUN_00528040(DAT_0057c5e0,param_1[0xb6b],(int *)0x0);
  FUN_00526700(DAT_0057c5e0,puVar1);
  if ((undefined4 *)param_1[0x29] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x29])(1);
  }
  if ((undefined4 *)param_1[0x28] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x28])(1);
  }
  puVar1 = (undefined4 *)param_1[0xb67];
  if (puVar1 != (undefined4 *)0x0) {
    UI_RemoveAllBriefings(puVar1);
    FUN_0054dd78(puVar1);
  }
  FUN_004830e0((int)param_1);
  FUN_00487310((int)param_1);
  piVar3 = param_1 + 0x2a;
  iVar2 = 0x56;
  do {
    if ((undefined4 *)*piVar3 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar3)(1);
      *piVar3 = 0;
    }
    piVar3 = piVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = param_1[0x22];
  iVar4 = 0;
  if (0 < iVar2) {
    do {
      puVar1 = (undefined4 *)FUN_004017f0(param_1 + 0x1d,iVar4,(int *)0x0);
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  FUN_00401440((int)(param_1 + 0x1d));
  if ((undefined4 *)param_1[0x8f] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x8f])(1);
  }
  if ((undefined4 *)param_1[0x90] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x90])(1);
  }
  if ((undefined4 *)param_1[0x91] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x91])(1);
  }
  if ((undefined4 *)param_1[0x92] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x92])(1);
  }
  if (param_1[0xa4] != 0x1d) {
    DAT_0057bb54._0_1_ = 0;
  }
  local_4._0_1_ = 5;
  FUN_00403a60(param_1 + 0xb47);
  local_4._0_1_ = 4;
  FUN_0054a8e0(param_1 + 0xc1);
  local_4._0_1_ = 3;
  FUN_00401480(param_1 + 0x1d);
  local_4._0_1_ = 2;
  FUN_00401480(param_1 + 0x16);
  local_4._0_1_ = 1;
  FUN_00401480(param_1 + 0xf);
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_00401480(param_1 + 8);
  local_4 = 0xffffffff;
  FUN_00401480(param_1 + 1);
  ExceptionList = pvStack_c;
  return;
}

