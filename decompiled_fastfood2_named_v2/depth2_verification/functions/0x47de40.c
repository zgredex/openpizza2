// rea decompile_all
// name: FUN_0047de40
// address: 0x47de40
// body: available
// range: 0x47de40-0x47e0d0 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * __thiscall FUN_0047de40(void *this,int param_1,int param_2)

{
  int *piVar1;
  bool bVar2;
  uint *puVar3;
  void *this_00;
  undefined3 extraout_var;
  LPVOID pvVar4;
  int iVar5;
  int iVar6;
  int local_38;
  undefined4 *local_34;
  int local_30;
  int local_2c;
  int local_28;
  uint local_24;
  uint *local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00557fcb;
  local_c = ExceptionList;
  local_38 = -1;
  _DAT_0057c618 = _DAT_0057c618 & 0xffffff00;
  _DAT_0057c61c = 0;
  ExceptionList = &local_c;
  local_20 = operator_new(0x1c);
  local_4 = 0;
  if (local_20 == (uint *)0x0) {
    local_34 = (undefined4 *)0x0;
  }
  else {
    local_34 = FUN_004013a0(local_20,0);
  }
  local_4 = 0xffffffff;
  Game_CollectObjectsAtPoint(this,local_34,param_1,param_2);
  Game_CollectBuildingHitsAtPoint(this,local_34,param_1,param_2);
  FUN_0054a660(DAT_0057c1e0,0x400040,(byte *)s_found__d_00567c5c,local_34[5]);
  local_30 = 0;
  if (0 < (int)local_34[5]) {
    do {
      puVar3 = (uint *)FUN_004017f0(local_34,local_30,(int *)0x0);
      local_20 = puVar3;
      if ((char)*puVar3 == '\x01') {
        FUN_00401320(*(int *)(DAT_0057c670 + 0x244));
        piVar1 = *(int **)(puVar3[1] + 200);
        if (piVar1 != (int *)0x0) {
          FUN_00533560((void *)piVar1[0x16],*piVar1,&local_18,&local_1c);
          iVar5 = FUN_004ed5a0(*(void **)((int)this + 0x14e0),local_18 + 0xa0,local_1c + 0xd0,
                               (int *)0x1,0);
          if (local_38 < **(int **)(iVar5 + 8)) {
            _DAT_0057c618 = *puVar3;
            _DAT_0057c61c = puVar3[1];
            local_38 = **(int **)(iVar5 + 8);
          }
        }
        FUN_00401340(*(int *)(DAT_0057c670 + 0x244));
      }
      else if (((((char)*puVar3 == '\x03') && (local_24 = puVar3[1], local_24 != 0)) &&
               (piVar1 = (int *)(*(int *)(*(int *)((int)this + 0x14e0) + 0x4c) +
                                *(int *)(local_24 + 0x20) * 0xc), piVar1 != (int *)0x0)) &&
              (this_00 = (void *)FUN_004eab50(DAT_0057c5cc,*(int *)(piVar1[2] + 0x10)),
              this_00 != (void *)0x0)) {
        FUN_004ed780(*(void **)((int)this + 0x14e0),piVar1,this_00,&local_2c,&local_28);
        FUN_0053d100(this_00,&local_10,&local_14);
        iVar6 = param_1 - local_2c;
        iVar5 = param_2 - local_28;
        if (*(char *)((int)this_00 + 0x39) == '\0') {
          FUN_0053cea0(this_00);
        }
        bVar2 = FUN_0053a3f0(this_00,*(ushort **)((int)this_00 + 0x2c),iVar6,iVar5,(uint *)0x0);
        if ((CONCAT31(extraout_var,bVar2) != 0) && (local_38 < *(int *)(local_24 + 0x20))) {
          _DAT_0057c618 = *local_20;
          _DAT_0057c61c = local_20[1];
          local_38 = *(int *)(local_24 + 0x20);
        }
      }
      local_30 = local_30 + 1;
    } while (local_30 < (int)local_34[5]);
  }
  iVar5 = 0;
  if (0 < (int)local_34[5]) {
    do {
      pvVar4 = (LPVOID)FUN_004017f0(local_34,iVar5,(int *)0x0);
      FUN_0054dd78(pvVar4);
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)local_34[5]);
  }
  if (local_34 != (undefined4 *)0x0) {
    (**(code **)*local_34)(1);
  }
  ExceptionList = local_c;
  return &DAT_0057c618;
}

