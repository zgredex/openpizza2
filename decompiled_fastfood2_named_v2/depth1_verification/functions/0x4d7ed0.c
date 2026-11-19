// rea decompile_all
// name: FUN_004d7ed0
// address: 0x4d7ed0
// body: available
// range: 0x4d7ed0-0x4d808c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall FUN_004d7ed0(void *this,int param_1,int param_2,int param_3)

{
  void *this_00;
  void *pvVar1;
  undefined4 *this_01;
  int iVar2;
  int iVar3;
  int iVar4;
  void *this_02;
  int iVar5;
  int local_18;
  int local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005590eb;
  local_c = ExceptionList;
  this_00 = *(void **)((int)this + 0xfa8);
  ExceptionList = &local_c;
  local_10 = this;
  pvVar1 = operator_new(0x1c);
  iVar5 = 0;
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    this_01 = (undefined4 *)0x0;
  }
  else {
    this_01 = FUN_004013a0(pvVar1,0);
  }
  local_4 = 0xffffffff;
  if (*(int *)((int)this + 0xfc0) < 1) {
    ExceptionList = local_c;
    return this_01;
  }
  do {
    iVar2 = FUN_004017f0((void *)((int)this + 0xfac),iVar5,(int *)0x0);
    if ((((*(int *)(iVar2 + 4) == 0xf) || (*(int *)(iVar2 + 4) == 0x1b)) &&
        (*(int *)(iVar2 + 0x74) != 0)) &&
       (iVar3 = Game_GetAdjustedValue(*(int *)(iVar2 + 0x74)), iVar3 != -1)) {
      UI_GetRecordCenteredRect(this_00,*(int *)(iVar2 + 0x24),&local_18,&local_14);
      if (*(int *)(iVar2 + 0x74) == 0) {
        iVar3 = -1;
      }
      else {
        iVar3 = Game_GetAdjustedValue(*(int *)(iVar2 + 0x74));
      }
      if (*(int *)(iVar2 + 0x74) == 0) {
        iVar4 = -1;
      }
      else {
        iVar4 = Game_GetAdjustedValue(*(int *)(iVar2 + 0x74));
      }
      if ((local_18 - param_2) * (local_18 - param_2) +
          (local_14 - param_3) * (local_14 - param_3) * 4 < iVar4 * iVar3 * 4) {
        if (*(int *)(iVar2 + 4) == 0x1b) {
          pvVar1 = (void *)FUN_00488be0(DAT_0057c670,*(int *)(iVar2 + 8));
          this_02 = (void *)Game_FindPlanByTarget(pvVar1,iVar2);
          if ((*(int *)((int)this_02 + 4) == 0) ||
             (iVar2 = FUN_0050f870(this_02,*(int *)((int)pvVar1 + 0x48),param_1), iVar2 < 0x33))
          goto LAB_004d804f;
          iVar2 = FUN_004017f0((void *)((int)pvVar1 + 0x148),*(int *)((int)this_02 + 0xc),(int *)0x0
                              );
          iVar2 = *(int *)(iVar2 + 0x16f0);
        }
        iVar3 = FUN_00401930(this_01,iVar2);
        if (iVar3 == -1) {
          FUN_004014b0(this_01,iVar2);
        }
      }
    }
LAB_004d804f:
    iVar5 = iVar5 + 1;
    this = local_10;
    if (*(int *)((int)local_10 + 0xfc0) <= iVar5) {
      ExceptionList = local_c;
      return this_01;
    }
  } while( true );
}

