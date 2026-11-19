// rea decompile_all
// name: FUN_00489c50
// address: 0x489c50
// body: available
// range: 0x489c50-0x489e1c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_00489c50(void *this,void *param_1)

{
  void *this_00;
  void *this_01;
  undefined1 uVar1;
  int iVar2;
  undefined3 extraout_var;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  if (*(int *)((int)this + 0x9c) == 0) {
    return 1;
  }
  this_01 = *(void **)(*(int *)((int)this + 0x9c) + 0x16f0);
  if (this_01 == (void *)0x0) {
    return 1;
  }
  local_10 = 0;
  if (0 < *(int *)((int)this_01 + 0x8c)) {
    do {
      iVar2 = Game_MapRecordToGlobal(this_01,local_10);
      if ((iVar2 != 0) && (uVar1 = FUN_00505e00(iVar2), CONCAT31(extraout_var,uVar1) != 0)) {
        iVar3 = FUN_00509e20(iVar2);
        iVar6 = *(int *)(iVar2 + 200);
        if (*(short *)(iVar6 + 0x28) == -1) {
          local_1c = 0;
          local_18 = 0;
          local_14 = 0;
        }
        else {
          this_00 = (void *)(iVar6 + 0x14);
          iVar4 = FUN_0054b440(this_00,(int)*(short *)(iVar6 + 0x28));
          iVar5 = FUN_0054b440(this_00,*(short *)(iVar6 + 0x28) + 1);
          iVar6 = FUN_0054b440(this_00,*(short *)(iVar6 + 0x28) + 2);
          if (iVar4 != 0) {
            local_1c = *(int *)(*(int *)(iVar2 + 0xc4) + 0x4c) + *(int *)(iVar4 + 8) * 0xc;
          }
          if (iVar5 != 0) {
            local_18 = *(int *)(*(int *)(iVar2 + 0xc4) + 0x4c) + *(int *)(iVar5 + 8) * 0xc;
          }
          if (iVar6 != 0) {
            local_14 = *(int *)(*(int *)(iVar2 + 0xc4) + 0x4c) + *(int *)(iVar6 + 8) * 0xc;
          }
        }
        iVar2 = 0;
        if (0 < *(int *)((int)param_1 + 0x14)) {
          do {
            iVar6 = FUN_004017f0(param_1,iVar2,(int *)0x0);
            if (iVar3 == iVar6) {
              return 1;
            }
            if ((local_1c != 0) &&
               (iVar6 = FUN_004017f0(param_1,iVar2,(int *)0x0), local_1c == iVar6)) {
              return 1;
            }
            if ((local_18 != 0) &&
               (iVar6 = FUN_004017f0(param_1,iVar2,(int *)0x0), local_18 == iVar6)) {
              return 1;
            }
            if ((local_14 != 0) &&
               (iVar6 = FUN_004017f0(param_1,iVar2,(int *)0x0), local_14 == iVar6)) {
              return 1;
            }
            iVar2 = iVar2 + 1;
          } while (iVar2 < *(int *)((int)param_1 + 0x14));
        }
      }
      local_10 = local_10 + 1;
    } while (local_10 < *(int *)((int)this_01 + 0x8c));
  }
  return 0;
}

