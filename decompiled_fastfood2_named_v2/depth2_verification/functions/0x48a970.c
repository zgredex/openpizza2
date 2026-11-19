// rea decompile_all
// name: FUN_0048a970
// address: 0x48a970
// body: available
// range: 0x48a970-0x48abf2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_0048a970(void *param_1,int param_2,int *param_3)

{
  char cVar1;
  void *this;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  void *this_00;
  int iVar8;
  byte *pbVar9;
  char *pcVar10;
  byte *pbVar11;
  longlong lVar12;
  int local_78;
  int local_74;
  float local_70;
  int local_6c;
  int *local_68;
  int local_64;
  int local_60;
  undefined4 local_5c;
  byte *local_58;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  byte local_40 [64];
  
  this = (void *)FUN_00531980(param_1,param_2);
  if (this == (void *)0x0) {
    return 0;
  }
  FUN_0053d090(this,&local_78,&local_48);
  FUN_005314a0(param_1,param_2,&local_5c,&local_60);
  FUN_00531570(param_1,param_2,&local_44,&local_64);
  local_6c = (local_64 + -0x12 >> 1) + local_60;
  iVar5 = 0;
  iVar8 = 0x24;
  piVar2 = param_3;
  do {
    iVar4 = *piVar2;
    piVar2 = piVar2 + 1;
    iVar5 = iVar5 + iVar4;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  if (iVar5 < 2) {
    local_70 = 0.0;
  }
  else if ((float)local_78 <= (float)iVar5 * 18.0) {
    local_70 = ((float)local_78 - 18.0) / (float)(iVar5 + -1);
  }
  else {
    local_70 = 18.0;
  }
  iVar5 = (int)&PTR_s_M_X_KID_M01_spr_005729dc - (int)param_3;
  iVar8 = 0x31128;
  local_74 = 0;
  local_68 = param_3;
  local_4c = iVar5;
  do {
    local_50 = *local_68;
    if (local_50 != 0) {
      local_58 = local_40;
      if (*(char **)(iVar5 + (int)local_68) == (char *)0x0) {
        uVar6 = 0xffffffff;
        pcVar3 = DAT_00572a68;
        do {
          pcVar10 = pcVar3;
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          pcVar10 = pcVar3 + 1;
          cVar1 = *pcVar3;
          pcVar3 = pcVar10;
        } while (cVar1 != '\0');
        uVar6 = ~uVar6;
        pbVar9 = (byte *)(pcVar10 + -uVar6);
      }
      else {
        uVar6 = 0xffffffff;
        pcVar3 = *(char **)(iVar5 + (int)local_68);
        do {
          pcVar10 = pcVar3;
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          pcVar10 = pcVar3 + 1;
          cVar1 = *pcVar3;
          pcVar3 = pcVar10;
        } while (cVar1 != '\0');
        uVar6 = ~uVar6;
        pbVar9 = (byte *)(pcVar10 + -uVar6);
      }
      pbVar11 = local_58;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pbVar11 = *(undefined4 *)pbVar9;
        pbVar9 = pbVar9 + 4;
        pbVar11 = pbVar11 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pbVar11 = *pbVar9;
        pbVar9 = pbVar9 + 1;
        pbVar11 = pbVar11 + 1;
      }
      pcVar3 = FUN_0048d110(local_74);
      if (0 < local_50) {
        iVar5 = local_50;
        do {
          iVar4 = FUN_0052ff20(param_1,iVar8);
          if (iVar4 == 0) {
            pbVar9 = local_40;
            iVar4 = local_6c;
            lVar12 = __ftol();
            FUN_00531850(param_1,iVar8,(int)lVar12,iVar4,(char *)pbVar9);
joined_r0x0048ab8d:
            if (pcVar3 != (char *)0x0) {
              UI_SetObjectTextByKey(param_1,iVar8,pcVar3);
            }
          }
          else {
            iVar4 = local_6c;
            lVar12 = __ftol();
            UI_SetObjectRangeByKey(param_1,iVar8,(int)lVar12,iVar4);
            pbVar9 = (byte *)FUN_005319a0(param_1,iVar8);
            uVar6 = FUN_005570c0(this_00,pbVar9,local_40);
            if (uVar6 != 0) {
              FUN_00531910(param_1,iVar8,(char *)local_40);
              goto joined_r0x0048ab8d;
            }
          }
          iVar8 = iVar8 + 1;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      iVar5 = local_4c;
    }
    local_74 = local_74 + 1;
    local_68 = local_68 + 1;
    if (0x23 < local_74) {
      while (iVar5 = FUN_0052ff20(param_1,iVar8), iVar5 != 0) {
        FUN_005311a0(param_1,iVar8);
        iVar8 = iVar8 + 1;
      }
      return 1;
    }
  } while( true );
}

