// rea decompile_all
// name: FUN_004df200
// address: 0x4df200
// body: available
// range: 0x4df200-0x4df473 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004df200(void *this,int *param_1)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_38;
  int local_30;
  int local_2c;
  int local_28;
  int local_20;
  int local_1c;
  int local_18;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  iVar3 = 0;
  iVar5 = 0;
  iVar4 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_38 = 0;
  if (0 < *(int *)((int)this + 0x15c)) {
    do {
      pvVar1 = (void *)IDMap_Lookup((void *)((int)this + 0x148),local_38,(int *)0x0);
      iVar2 = FUN_0047aac0(pvVar1,0);
      local_30 = local_30 + iVar2;
      if (iVar4 < iVar2) {
        iVar4 = iVar2;
        local_20 = iVar2;
      }
      iVar2 = FUN_0047aac0(pvVar1,2);
      local_2c = local_2c + iVar2;
      if (local_1c < iVar2) {
        local_1c = iVar2;
      }
      iVar2 = FUN_0047aac0(pvVar1,1);
      iVar5 = iVar5 + iVar2;
      if (iVar3 < iVar2) {
        iVar3 = iVar2;
      }
      iVar2 = FUN_0047aac0(pvVar1,3);
      local_28 = local_28 + iVar2;
      if (local_18 < iVar2) {
        local_18 = iVar2;
      }
      local_38 = local_38 + 1;
    } while (local_38 < *(int *)((int)this + 0x15c));
  }
  local_38 = 0;
  *(int *)(*param_1 + 0x40) = local_30;
  *(int *)(*param_1 + 0x44) = iVar4;
  *(int *)(*param_1 + 0x48) = local_2c;
  *(int *)(*param_1 + 0x4c) = local_1c;
  *(int *)(*param_1 + 0x50) = local_28;
  *(int *)(*param_1 + 0x54) = local_18;
  *(int *)(*param_1 + 0x58) = iVar5;
  local_10 = 1;
  local_c = 1;
  *(int *)(*param_1 + 0x5c) = iVar3;
  local_8 = 1;
  local_4 = 1;
  do {
    pvVar1 = (void *)Game_GetPlayerBySlot(DAT_0057c670,local_38);
    if ((pvVar1 != (void *)0x0) && (pvVar1 != this)) {
      iVar4 = FUN_004e0830(pvVar1,0);
      if (local_20 <= iVar4) {
        local_10 = 0;
      }
      iVar4 = FUN_004e0830(pvVar1,2);
      if (local_1c <= iVar4) {
        local_c = 0;
      }
      iVar4 = FUN_004e0830(pvVar1,1);
      if (iVar3 <= iVar4) {
        local_4 = 0;
      }
      iVar4 = FUN_004e0830(pvVar1,3);
      if (local_18 <= iVar4) {
        local_8 = 0;
      }
    }
    local_38 = local_38 + 1;
  } while (local_38 < 6);
  if (local_30 == 0) {
    local_10 = 0;
  }
  if (local_2c == 0) {
    local_c = 0;
  }
  if (local_28 == 0) {
    local_8 = 0;
  }
  if (iVar5 == 0) {
    local_4 = 0;
  }
  *(int *)(*param_1 + 0x140) = (local_30 + local_10 * 0x19) * 200;
  *(int *)(*param_1 + 0x144) = (local_2c + local_c * 0x19) * 200;
  *(int *)(*param_1 + 0x148) = (local_28 + local_8 * 0x19) * 200;
  *(int *)(*param_1 + 0x14c) = (iVar5 + local_4 * 0x19) * 200;
  return;
}

