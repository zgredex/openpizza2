// rea decompile_all
// name: FUN_004d6770
// address: 0x4d6770
// body: available
// range: 0x4d6770-0x4d6a8a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * __thiscall FUN_004d6770(void *this,int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  int *piVar4;
  bool bVar5;
  void *pvVar6;
  uint *puVar7;
  undefined3 extraout_var;
  int iVar8;
  undefined3 extraout_var_00;
  LPVOID pvVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int local_54;
  undefined4 *local_50;
  int local_4c;
  int local_48;
  int local_40;
  int local_34;
  int local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  undefined4 local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055905b;
  pvStack_c = ExceptionList;
  local_48 = -1;
  local_54 = -1;
  _DAT_0057dfb0 = _DAT_0057dfb0 & 0xffffff00;
  _DAT_0057dfb4 = 0;
  ExceptionList = &pvStack_c;
  pvVar6 = operator_new(0x1c);
  local_4 = 0;
  if (pvVar6 == (void *)0x0) {
    local_50 = (undefined4 *)0x0;
  }
  else {
    local_50 = FUN_004013a0(pvVar6,0);
  }
  local_4 = 0xffffffff;
  FUN_004d6570(this,local_50,param_1,param_2);
  FUN_004d64b0(this,local_50,param_1,param_2);
  local_4c = 0;
  if (0 < (int)local_50[5]) {
    do {
      puVar7 = (uint *)FUN_004017f0(local_50,local_4c,(int *)0x0);
      if ((char)*puVar7 == '\x01') {
        FUN_00401320(*(int *)(DAT_0057c670 + 0x244));
        piVar4 = *(int **)(puVar7[1] + 200);
        if (piVar4 != (int *)0x0) {
          FUN_00533560((void *)piVar4[0x16],*piVar4,&local_30,&local_34);
          iVar11 = FUN_004ed5a0(*(void **)((int)this + 0xfa8),local_30 + 0xa0,local_34 + 0xd0,
                                (int *)0x1,0);
          if (local_48 < **(int **)(iVar11 + 8)) {
            local_24 = *puVar7;
            local_20 = puVar7[1];
            local_48 = **(int **)(iVar11 + 8);
          }
        }
        FUN_00401340(*(int *)(DAT_0057c670 + 0x244));
      }
      else if ((char)*puVar7 == '\x02') {
        FUN_00401320(*(int *)(DAT_0057c670 + 0x248));
        uVar2 = puVar7[1];
        local_14 = *(undefined4 *)(uVar2 + 0x18);
        local_10 = *(undefined4 *)(uVar2 + 0x1c);
        iVar11 = ((param_1 << ((byte)DAT_00580a50 & 0x1f)) +
                 *(int *)(*(int *)((int)this + 0xfa8) + 0x24)) - *(int *)(uVar2 + 0x10);
        iVar12 = ((param_2 << ((byte)DAT_00580a50 & 0x1f)) +
                 *(int *)(*(int *)((int)this + 0xfa8) + 0x28)) - *(int *)(uVar2 + 0x14);
        pvVar6 = (void *)FUN_004eab50(DAT_0057c5cc,*(int *)(uVar2 + 0x20));
        if (pvVar6 != (void *)0x0) {
          if (*(char *)((int)pvVar6 + 0x39) == '\0') {
            FUN_0053cea0(pvVar6);
          }
          bVar5 = FUN_0053a3f0(pvVar6,*(ushort **)((int)pvVar6 + 0x2c),iVar11,iVar12,(uint *)0x0);
          if ((CONCAT31(extraout_var,bVar5) != 0) && (local_54 < *(int *)(uVar2 + 0x24))) {
            local_2c = *puVar7;
            local_28 = puVar7[1];
            local_54 = *(int *)(uVar2 + 0x24);
          }
        }
        iVar10 = 0;
        local_40 = 0;
        iVar1 = *(int *)(*(int *)((int)this + 0xfa8) + 0x4c) + *(int *)(uVar2 + 0x24) * 0xc;
        iVar8 = *(int *)(iVar1 + 8);
        if (0 < *(int *)(iVar8 + 0x14)) {
          do {
            pcVar3 = *(char **)(*(int *)(iVar8 + 0x18) + 8 + iVar10);
            if (*pcVar3 != '\x02') {
              bVar5 = RecordList_BlitRecordSprite
                                (*(void **)(pcVar3 + 0x48),*(int *)(*(int *)(iVar8 + 0x18) + iVar10)
                                 ,iVar11,iVar12);
              if (CONCAT31(extraout_var_00,bVar5) != 0) {
                local_54 = *(int *)(uVar2 + 0x24);
                local_2c = *puVar7;
                local_28 = puVar7[1];
              }
            }
            local_40 = local_40 + 1;
            iVar10 = iVar10 + 0xc;
            iVar8 = *(int *)(iVar1 + 8);
          } while (local_40 < *(int *)(iVar8 + 0x14));
        }
        FUN_00401340(*(int *)(DAT_0057c670 + 0x248));
      }
      local_4c = local_4c + 1;
    } while (local_4c < (int)local_50[5]);
  }
  iVar11 = 0;
  if (0 < (int)local_50[5]) {
    do {
      pvVar9 = (LPVOID)FUN_004017f0(local_50,iVar11,(int *)0x0);
      FUN_0054dd78(pvVar9);
      iVar11 = iVar11 + 1;
    } while (iVar11 < (int)local_50[5]);
  }
  if (local_50 != (undefined4 *)0x0) {
    (**(code **)*local_50)(1);
  }
  if (local_48 == -1) {
    if (local_54 != -1) {
      _DAT_0057dfb0 = local_2c;
      _DAT_0057dfb4 = local_28;
    }
  }
  else {
    _DAT_0057dfb0 = local_24;
    _DAT_0057dfb4 = local_20;
  }
  ExceptionList = pvStack_c;
  return &DAT_0057dfb0;
}

