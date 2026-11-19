// rea decompile_all
// name: Stats_ComputePlayerAggregateStats
// address: 0x4df480
// body: available
// range: 0x4df480-0x4df777 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Stats_ComputePlayerAggregateStats(void *this,int *param_1)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  longlong lVar6;
  ulonglong uVar7;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  local_c = 1;
  local_8 = 1;
  local_4 = 1;
  iVar4 = 0;
  iVar5 = *(ushort *)(*(int *)((int)DAT_0057c670 + 0x94) + 10) - 1;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  if (0 < *(int *)((int)this + 0x15c)) {
    do {
      iVar1 = IDMap_Lookup((void *)((int)this + 0x148),iVar4,(int *)0x0);
      Stats_SumFilteredRecordFloats20(iVar1,-1,iVar5);
      lVar6 = __ftol();
      iVar2 = (int)lVar6;
      local_24 = local_24 + iVar2;
      if (local_18 < iVar2) {
        local_18 = iVar2;
      }
      Stats_SumFilteredFloats(iVar1,-1,-1,iVar5);
      uVar7 = __ftol();
      Stats_SumFilteredFloats2(iVar1,-1,-1,iVar5);
      lVar6 = __ftol();
      iVar1 = (int)lVar6;
      iVar2 = (int)uVar7 - iVar1;
      if (iVar2 < 0) {
        iVar2 = 0;
      }
      local_20 = local_20 + iVar2;
      if (local_14 < iVar2) {
        local_14 = iVar2;
      }
      if (iVar1 < 1) {
        iVar1 = 0;
      }
      else {
        iVar1 = (int)((longlong)((ulonglong)(uint)((int)uVar7 >> 0x1f) << 0x20 | uVar7 & 0xffffffff)
                     / (longlong)iVar1);
      }
      local_1c = local_1c + iVar1;
      if (local_10 < iVar1) {
        local_10 = iVar1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)((int)this + 0x15c));
  }
  local_28 = 0;
  do {
    pvVar3 = (void *)Game_GetPlayerBySlot(DAT_0057c670,local_28);
    if (((pvVar3 != (void *)0x0) && (pvVar3 != this)) &&
       (iVar4 = 0, 0 < *(int *)((int)pvVar3 + 0x15c))) {
      do {
        iVar1 = IDMap_Lookup((void *)((int)pvVar3 + 0x148),iVar4,(int *)0x0);
        Stats_SumFilteredRecordFloats20(iVar1,-1,iVar5);
        lVar6 = __ftol();
        if (local_18 < (int)lVar6) {
          local_c = 0;
        }
        Stats_SumFilteredFloats(iVar1,-1,-1,iVar5);
        uVar7 = __ftol();
        Stats_SumFilteredFloats2(iVar1,-1,-1,iVar5);
        lVar6 = __ftol();
        iVar1 = (int)lVar6;
        iVar2 = (int)uVar7 - iVar1;
        if (iVar2 < 0) {
          iVar2 = 0;
        }
        if (local_14 < iVar2) {
          local_8 = 0;
        }
        if (iVar1 < 1) {
          iVar1 = 0;
        }
        else {
          iVar1 = (int)((longlong)
                        ((ulonglong)(uint)((int)uVar7 >> 0x1f) << 0x20 | uVar7 & 0xffffffff) /
                       (longlong)iVar1);
        }
        if (local_10 < iVar1) {
          local_4 = 0;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)((int)pvVar3 + 0x15c));
    }
    local_28 = local_28 + 1;
  } while (local_28 < 6);
  if (local_24 == 0) {
    local_c = 0;
  }
  if (local_20 == 0) {
    local_8 = 0;
  }
  if (local_1c == 0) {
    local_4 = 0;
  }
  *(int *)(*param_1 + 0x60) = local_24;
  *(int *)(*param_1 + 100) = local_18;
  *(int *)(*param_1 + 400) = local_24 / 100 + local_c * 5000;
  *(int *)(*param_1 + 0x68) = local_20;
  *(int *)(*param_1 + 0x6c) = local_14;
  *(int *)(*param_1 + 0x194) = local_20 / 10 + local_8 * 5000;
  *(int *)(*param_1 + 0x70) = local_1c;
  *(int *)(*param_1 + 0x74) = local_10;
  *(int *)(*param_1 + 0x198) = (local_1c + local_4 * 10) * 500;
  lVar6 = __ftol();
  *(int *)(*param_1 + 0x78) = (int)lVar6;
  lVar6 = __ftol();
  *(int *)(*param_1 + 0x19c) = (int)lVar6;
  return;
}

