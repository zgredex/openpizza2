// rea decompile_all
// name: Company_Destroy
// address: 0x4e1990
// body: available
// range: 0x4e1990-0x4e1b71 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall Company_Destroy(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  LPVOID pvVar3;
  int iVar4;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
                    /* Destroys a company record and all owned building, vehicle, person, and
                       storage maps. */
  puStack_8 = &LAB_005594c2;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_0055c568;
  iVar1 = param_1[0x57];
  iVar4 = 0;
  local_4 = 6;
  if (0 < iVar1) {
    do {
      puVar2 = (undefined4 *)FUN_004017f0(param_1 + 0x52,iVar4,(int *)0x0);
      if (puVar2 != (undefined4 *)0x0) {
        (**(code **)*puVar2)(1);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
  }
  FUN_00401440((int)(param_1 + 0x52));
  iVar1 = param_1[0x5e];
  iVar4 = 0;
  if (0 < iVar1) {
    do {
      puVar2 = (undefined4 *)FUN_004017f0(param_1 + 0x59,iVar4,(int *)0x0);
      if (puVar2 != (undefined4 *)0x0) {
        (**(code **)*puVar2)(1);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
  }
  FUN_00401440((int)(param_1 + 0x59));
  iVar1 = param_1[0x49];
  iVar4 = 0;
  if (0 < iVar1) {
    do {
      puVar2 = (undefined4 *)FUN_004017f0(param_1 + 0x44,iVar4,(int *)0x0);
      if (puVar2 != (undefined4 *)0x0) {
        (**(code **)*puVar2)(1);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
  }
  iVar1 = param_1[0x65];
  iVar4 = 0;
  if (0 < iVar1) {
    do {
      puVar2 = (undefined4 *)FUN_004017f0(param_1 + 0x60,iVar4,(int *)0x0);
      if (puVar2 != (undefined4 *)0x0) {
        (**(code **)*puVar2)(1);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
  }
  iVar1 = param_1[0x73];
  iVar4 = 0;
  if (0 < iVar1) {
    do {
      pvVar3 = (LPVOID)FUN_004017f0(param_1 + 0x6e,iVar4,(int *)0x0);
      FUN_0054dd78(pvVar3);
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
  }
  iVar1 = param_1[0x6c];
  iVar4 = 0;
  if (0 < iVar1) {
    do {
      pvVar3 = (LPVOID)FUN_004017f0(param_1 + 0x67,iVar4,(int *)0x0);
      FUN_0054dd78(pvVar3);
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
  }
  if ((undefined4 *)param_1[0x75] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x75])(1);
  }
  local_4._0_1_ = 5;
  FUN_00401480(param_1 + 0x6e);
  local_4._0_1_ = 4;
  FUN_00401480(param_1 + 0x67);
  local_4._0_1_ = 3;
  FUN_00401480(param_1 + 0x60);
  local_4._0_1_ = 2;
  FUN_00401480(param_1 + 0x59);
  local_4._0_1_ = 1;
  FUN_00401480(param_1 + 0x52);
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_00401480(param_1 + 0x4b);
  local_4 = 0xffffffff;
  FUN_00401480(param_1 + 0x44);
  ExceptionList = pvStack_c;
  return;
}

