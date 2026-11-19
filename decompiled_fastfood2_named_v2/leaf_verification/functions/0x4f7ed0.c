// rea decompile_all
// name: FUN_004f7ed0
// address: 0x4f7ed0
// body: available
// range: 0x4f7ed0-0x4f8236 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_004f7ed0(void *this,int param_1)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  longlong lVar8;
  char *pcVar9;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  void *local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38 [4];
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
  
  local_58 = 0;
  iVar5 = *(int *)((int)this + param_1 * 0x168 + 0x70);
  local_44 = *(int *)((int)this + param_1 * 0x168 + 0x134);
  pvVar4 = (void *)((int)this + param_1 * 0x168);
  iVar1 = *(int *)(iVar5 + 0x15c);
  if (0x13 < iVar1) {
    return 1;
  }
  local_48 = pvVar4;
  local_3c = iVar5;
  if (iVar1 < 1) {
    iVar6 = param_1;
LAB_004f7fcc:
    if (0 < local_50) {
      return 1;
    }
    if ((0 < iVar1) && (iVar6 < 0)) {
      return 1;
    }
  }
  else {
    Game_GetPlayerCity(iVar5);
    local_40 = FUN_004f7a50(*(int *)((int)pvVar4 + 0x40));
    iVar6 = *(int *)((int)pvVar4 + 0x134) - local_40;
    local_50 = 0;
    local_40 = local_40 / iVar1;
    local_54 = 0;
    if (0 < iVar1) {
      do {
        iVar3 = IDMap_Lookup((void *)(iVar5 + 0x148),local_54,(int *)0x0);
        if (iVar3 != 0) {
          if (*(int *)(*(int *)(iVar3 + 0x16f0) + 0x38) != 0) {
            local_50 = local_50 + 1;
          }
          iVar6 = iVar6 + (-1 - *(int *)(iVar3 + 0x38)) * 20000;
          FUN_004f7b90(iVar3,&local_4c,local_38,4);
          local_4c = local_4c - local_40;
          if (local_4c < 0) {
            local_58 = local_58 + 1;
          }
        }
        local_54 = local_54 + 1;
      } while (local_54 < iVar1);
      goto LAB_004f7fcc;
    }
  }
  if ((1 < iVar1) && (((iVar1 < 4 && (0 < local_58)) || (1 < local_58)))) {
    return 1;
  }
  if (9 < iVar1) {
    FUN_004f7920(this,param_1);
  }
  pvVar4 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0
                               );
  local_14 = FUN_004f8240(this,param_1,pvVar4,0,&local_10);
  if (local_14 != 0) {
    local_4 = FUN_004d5dd0(pvVar4,local_14,1,&local_c,&local_8,*(int *)((int)local_48 + 0x40),
                           (int *)0x0);
  }
  local_28 = FUN_004f8240(this,param_1,pvVar4,1,&local_24);
  if ((local_28 != 0) &&
     (local_18 = FUN_004d5dd0(pvVar4,local_28,1,&local_20,&local_1c,*(int *)((int)local_48 + 0x40),
                              (int *)0x0), local_44 < local_1c)) {
    local_28 = 0;
  }
  if (local_14 == 0) {
    if (local_28 == 0) {
      return 3;
    }
  }
  else {
    piVar7 = &local_14;
    bVar2 = false;
    if (((local_28 == 0) || (local_24 <= local_10 * 2)) || (local_44 <= local_20 * 2))
    goto LAB_004f8113;
  }
  piVar7 = &local_28;
  bVar2 = true;
LAB_004f8113:
  FUN_004f8bf0(this,param_1);
  iVar5 = IsSpecialIdRange(*piVar7);
  if (iVar5 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(*piVar7 + 0x20) + -0x84c >> 2;
  }
  iVar5 = FUN_004f7420(this,*(int *)((int)pvVar4 + 0xc1c),(void *)*piVar7,param_1,iVar5,(uint)!bVar2
                      );
  pvVar4 = (void *)IDMap_Lookup((void *)(local_3c + 0x148),iVar5,(int *)0x0);
  if (bVar2) {
    *(undefined1 *)((int)pvVar4 + 0x16f4) = 1;
    lVar8 = __ftol();
    *(int *)((int)pvVar4 + 0x14b0) = (int)lVar8;
    *(int *)(*piVar7 + 0x3c) = piVar7[3];
    FUN_00477e40(pvVar4,2,(float)piVar7[3],'\0',-1);
    pcVar9 = s_Filiale___s__gekauft__00571ed4;
  }
  else {
    *(undefined1 *)((int)pvVar4 + 0x16f4) = 0;
    *(int *)((int)pvVar4 + 0x14b0) = piVar7[2];
    FUN_00477e40(pvVar4,1,(float)piVar7[2],'\0',-1);
    pcVar9 = s_Filiale___s__gemietet__00571eec;
  }
  FUN_0054a660(DAT_0057c1e0,0xff,(byte *)pcVar9,(int)pvVar4 + 4);
  return 1;
}

