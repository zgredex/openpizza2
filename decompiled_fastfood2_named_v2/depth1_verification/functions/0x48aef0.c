// rea decompile_all
// name: FUN_0048aef0
// address: 0x48aef0
// body: available
// range: 0x48aef0-0x48b1a6 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_0048aef0(void *param_1,int param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  char *pcVar10;
  char *pcVar11;
  int iVar12;
  int local_2b0;
  int local_2ac;
  int local_2a8;
  int local_2a4;
  int local_2a0;
  int *local_29c;
  int local_298;
  int local_294;
  int local_290;
  int local_28c;
  int local_288;
  int local_284;
  char local_280 [64];
  char local_240 [64];
  char local_200 [512];
  
  Array_GetPairByKey(param_1,param_2,&local_2a0,&local_28c);
  Array_GetRectByKey(param_1,param_2,&local_288,&local_298);
  local_200[0] = '\0';
  iVar7 = 0;
  piVar2 = param_3;
  do {
    if (*piVar2 != 0) {
      FUN_0048d110(iVar7);
      FUN_0054dd83(local_240,(byte *)s__d__s_00568324,*piVar2);
      if (local_200[0] != '\0') {
        uVar4 = 0xffffffff;
        pcVar8 = &DAT_0056832c;
        do {
          pcVar11 = pcVar8;
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          pcVar11 = pcVar8 + 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar11;
        } while (cVar1 != '\0');
        uVar4 = ~uVar4;
        iVar5 = -1;
        pcVar8 = local_200;
        do {
          pcVar10 = pcVar8;
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          pcVar10 = pcVar8 + 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar10;
        } while (cVar1 != '\0');
        pcVar8 = pcVar11 + -uVar4;
        pcVar11 = pcVar10 + -1;
        for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pcVar11 = *(undefined4 *)pcVar8;
          pcVar8 = pcVar8 + 4;
          pcVar11 = pcVar11 + 4;
        }
        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *pcVar11 = *pcVar8;
          pcVar8 = pcVar8 + 1;
          pcVar11 = pcVar11 + 1;
        }
      }
      uVar4 = 0xffffffff;
      pcVar8 = local_240;
      do {
        pcVar11 = pcVar8;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar11 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar11;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      iVar5 = -1;
      pcVar8 = local_200;
      do {
        pcVar10 = pcVar8;
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        pcVar10 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar10;
      } while (cVar1 != '\0');
      pcVar8 = pcVar11 + -uVar4;
      pcVar11 = pcVar10 + -1;
      for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar11 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar11 = pcVar11 + 1;
      }
    }
    iVar7 = iVar7 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar7 < 8);
  iVar9 = 0x318f8;
  iVar7 = 0;
  iVar5 = 8;
  piVar2 = param_3;
  do {
    iVar12 = *piVar2;
    piVar2 = piVar2 + 1;
    iVar7 = iVar7 + iVar12;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  local_2ac = 0xc;
  do {
    local_284 = (local_288 + -0x12) / local_2ac;
    if (iVar7 < local_284 * 5) break;
    local_2ac = local_2ac + -1;
  } while (0 < local_2ac);
  if (local_2ac == 0) {
    local_2ac = 1;
  }
  local_294 = local_298 / 5;
  iVar7 = (int)&PTR_s_M_KIDS_00567ed4 - (int)param_3;
  local_2b0 = 0;
  local_2a8 = 8;
  local_29c = param_3;
  iVar5 = local_28c;
  iVar12 = local_2a0;
  local_290 = iVar7;
  do {
    local_2a4 = *local_29c;
    if (local_2a4 != 0) {
      FUN_0054dd83(local_280,(byte *)s__s_spr_005680ec,*(undefined4 *)(iVar7 + (int)local_29c));
      if (0 < local_2a4) {
        do {
          iVar7 = Array_GetRecordByKeyPtr(param_1,iVar9);
          if (iVar7 == 0) {
            FUN_00531850(param_1,iVar9,iVar12,iVar5,local_280);
          }
          else {
            FUN_00531400(param_1,iVar9,iVar12,iVar5);
            pbVar3 = (byte *)FUN_005319a0(param_1,iVar9);
            uVar4 = FUN_005570c0(local_280,pbVar3,(byte *)local_280);
            if (uVar4 != 0) {
              FUN_00531910(param_1,iVar9,local_280);
            }
          }
          FUN_00531f50(param_1,iVar9,local_200);
          iVar9 = iVar9 + 1;
          local_2b0 = local_2b0 + 1;
          if (local_2b0 < local_284) {
            iVar12 = iVar12 + local_2ac;
          }
          else {
            iVar5 = iVar5 + local_294;
            local_2b0 = 0;
            iVar12 = local_2a0;
          }
          local_2a4 = local_2a4 + -1;
        } while (local_2a4 != 0);
      }
      iVar7 = local_290;
    }
    local_29c = local_29c + 1;
    local_2a8 = local_2a8 + -1;
  } while (local_2a8 != 0);
  while (iVar7 = Array_GetRecordByKeyPtr(param_1,iVar9), iVar7 != 0) {
    FUN_005311a0(param_1,iVar9);
    iVar9 = iVar9 + 1;
  }
  return 1;
}

