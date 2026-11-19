// rea decompile_all
// name: FUN_004df780
// address: 0x4df780
// body: available
// range: 0x4df780-0x4dfae4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004df780(void *this,int *param_1)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  void *this_00;
  int iVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  int local_34;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  piVar1 = param_1;
  local_10 = 1;
  local_c = 1;
  local_8 = 1;
  local_4 = 1;
  local_24 = 0;
  local_2c = 0;
  local_28 = 0;
  iVar5 = 0;
  iVar6 = 0;
  iVar4 = *(ushort *)(*(int *)((int)DAT_0057c670 + 0x94) + 10) - 1;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  if (0 < *(int *)((int)this + 0x15c)) {
    do {
      pvVar2 = (void *)IDMap_Lookup((void *)((int)this + 0x148),iVar6,(int *)0x0);
      FUN_00478090((int)pvVar2,0x10,-1,iVar4);
      lVar7 = __ftol();
      if (local_20 < (int)lVar7) {
        local_20 = (int)lVar7;
      }
      iVar3 = *(int *)(*(int *)((int)pvVar2 + 0x16f0) + 0x74);
      if (iVar3 == 0) {
        iVar3 = -1;
      }
      else {
        iVar3 = FUN_004e4490(iVar3);
      }
      local_2c = local_2c + iVar3;
      if (local_1c < iVar3) {
        local_1c = iVar3;
      }
      iVar3 = FUN_0047a4f0(pvVar2,-1,-1);
      local_28 = local_28 + iVar3;
      if (local_18 < iVar3) {
        local_18 = iVar3;
      }
      iVar3 = FUN_0047a820(pvVar2,-1);
      local_24 = local_24 + iVar3;
      if (iVar5 < iVar3) {
        iVar5 = iVar3;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)((int)this + 0x15c));
  }
  FUN_004e0aa0((int)this,0xf,-1,iVar4);
  lVar7 = __ftol();
  FUN_004e0aa0((int)this,0x10,-1,iVar4);
  lVar8 = __ftol();
  FUN_004e0aa0((int)this,0x11,-1,iVar4);
  lVar9 = __ftol();
  iVar6 = (int)lVar7 + (int)lVar8 + (int)lVar9;
  local_34 = 0;
  *(int *)(*param_1 + 0x7c) = iVar6;
  *(int *)(*param_1 + 0x80) = local_20;
  *(int *)(*param_1 + 0x84) = local_2c;
  *(int *)(*param_1 + 0x88) = local_1c;
  *(int *)(*param_1 + 0x8c) = local_28;
  *(int *)(*param_1 + 0x90) = local_18;
  *(int *)(*param_1 + 0x94) = local_24;
  *(int *)(*param_1 + 0x98) = iVar5;
  do {
    pvVar2 = (void *)FUN_00488be0(DAT_0057c670,local_34);
    if (((pvVar2 != (void *)0x0) && (pvVar2 != this)) &&
       (param_1 = (int *)0x0, 0 < *(int *)((int)pvVar2 + 0x15c))) {
      do {
        this_00 = (void *)IDMap_Lookup((void *)((int)pvVar2 + 0x148),(int)param_1,(int *)0x0);
        FUN_00478090((int)this_00,0x10,-1,iVar4);
        lVar7 = __ftol();
        if (local_20 <= (int)lVar7) {
          local_10 = 0;
        }
        iVar3 = *(int *)(*(int *)((int)this_00 + 0x16f0) + 0x74);
        if (iVar3 == 0) {
          iVar3 = -1;
        }
        else {
          iVar3 = FUN_004e4490(iVar3);
        }
        if (local_1c <= iVar3) {
          local_c = 0;
        }
        iVar3 = FUN_0047a540(this_00,-1,-1);
        if (local_18 <= iVar3) {
          local_8 = 0;
        }
        iVar3 = FUN_0047a820(this_00,-1);
        if (iVar5 <= iVar3) {
          local_4 = 0;
        }
        param_1 = (int *)((int)param_1 + 1);
      } while ((int)param_1 < *(int *)((int)pvVar2 + 0x15c));
    }
    local_34 = local_34 + 1;
  } while (local_34 < 6);
  if (iVar6 == 0) {
    local_10 = 0;
  }
  if (local_2c == 0) {
    local_c = 0;
  }
  if (local_28 == 0) {
    local_8 = 0;
  }
  iVar5 = 0;
  if (local_24 != 0) {
    iVar5 = local_4;
  }
  *(int *)(*piVar1 + 0x160) = (iVar6 * 2) / 5 + local_10 * 5000;
  *(int *)(*piVar1 + 0x164) = (local_2c + local_c * 500) * 10;
  *(int *)(*piVar1 + 0x168) = (local_28 + local_8 * 500) * 10;
  *(int *)(*piVar1 + 0x16c) = (local_24 + iVar5 * 0x32) * 100;
  return;
}

