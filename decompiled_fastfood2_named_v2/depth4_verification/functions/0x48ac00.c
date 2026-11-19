// rea decompile_all
// name: FUN_0048ac00
// address: 0x48ac00
// body: available
// range: 0x48ac00-0x48aeee inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_0048ac00(void *param_1,int param_2,int *param_3)

{
  char cVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  undefined **ppuVar12;
  longlong lVar13;
  int *local_2b8;
  int *local_2ac;
  int local_2a8;
  int local_2a0;
  int local_294 [2];
  undefined4 local_28c;
  undefined4 local_288;
  int local_284;
  char local_280 [64];
  char local_240 [64];
  char local_200 [512];
  
  FUN_005314a0(param_1,param_2,&local_28c,&local_288);
  FUN_00531570(param_1,param_2,&local_284,local_294);
  iVar8 = 0x31510;
  local_2b8 = param_3;
  local_2a0 = 8;
  do {
    iVar4 = 8;
    piVar7 = local_2b8;
    do {
      piVar7 = piVar7 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    local_200[0] = '\0';
    local_2a8 = 0;
    local_2ac = local_2b8;
    do {
      if (*local_2ac != 0) {
        FUN_0048d110(local_2a8);
        FUN_0054dd83(local_240,(byte *)s__d__s_00568324,*local_2ac);
        if (local_200[0] != '\0') {
          uVar5 = 0xffffffff;
          pcVar9 = &DAT_0056832c;
          do {
            pcVar11 = pcVar9;
            if (uVar5 == 0) break;
            uVar5 = uVar5 - 1;
            pcVar11 = pcVar9 + 1;
            cVar1 = *pcVar9;
            pcVar9 = pcVar11;
          } while (cVar1 != '\0');
          uVar5 = ~uVar5;
          iVar4 = -1;
          pcVar9 = local_200;
          do {
            pcVar10 = pcVar9;
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            pcVar10 = pcVar9 + 1;
            cVar1 = *pcVar9;
            pcVar9 = pcVar10;
          } while (cVar1 != '\0');
          pcVar9 = pcVar11 + -uVar5;
          pcVar11 = pcVar10 + -1;
          for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
            *(undefined4 *)pcVar11 = *(undefined4 *)pcVar9;
            pcVar9 = pcVar9 + 4;
            pcVar11 = pcVar11 + 4;
          }
          for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *pcVar11 = *pcVar9;
            pcVar9 = pcVar9 + 1;
            pcVar11 = pcVar11 + 1;
          }
        }
        uVar5 = 0xffffffff;
        pcVar9 = local_240;
        do {
          pcVar11 = pcVar9;
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          pcVar11 = pcVar9 + 1;
          cVar1 = *pcVar9;
          pcVar9 = pcVar11;
        } while (cVar1 != '\0');
        uVar5 = ~uVar5;
        iVar4 = -1;
        pcVar9 = local_200;
        do {
          pcVar10 = pcVar9;
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          pcVar10 = pcVar9 + 1;
          cVar1 = *pcVar9;
          pcVar9 = pcVar10;
        } while (cVar1 != '\0');
        pcVar9 = pcVar11 + -uVar5;
        pcVar11 = pcVar10 + -1;
        for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pcVar11 = *(undefined4 *)pcVar9;
          pcVar9 = pcVar9 + 4;
          pcVar11 = pcVar11 + 4;
        }
        for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *pcVar11 = *pcVar9;
          pcVar9 = pcVar9 + 1;
          pcVar11 = pcVar11 + 1;
        }
      }
      local_2a8 = local_2a8 + 1;
      local_2ac = local_2ac + 1;
    } while (local_2a8 < 8);
    ppuVar12 = &PTR_s_M_KIDS_00567eb4;
    do {
      iVar4 = *local_2b8;
      if ((iVar4 != 0) && (FUN_0054dd83(local_280,(byte *)s__s_spr_005680ec,*ppuVar12), 0 < iVar4))
      {
        do {
          iVar2 = FUN_0052ff20(param_1,iVar8);
          if (iVar2 == 0) {
            pcVar9 = local_280;
            lVar13 = __ftol();
            iVar2 = (int)lVar13;
            lVar13 = __ftol();
            FUN_00531850(param_1,iVar8,(int)lVar13,iVar2,pcVar9);
          }
          else {
            lVar13 = __ftol();
            iVar2 = (int)lVar13;
            lVar13 = __ftol();
            FUN_00531400(param_1,iVar8,(int)lVar13,iVar2);
            pbVar3 = (byte *)FUN_005319a0(param_1,iVar8);
            uVar5 = FUN_005570c0(local_280,pbVar3,(byte *)local_280);
            if (uVar5 != 0) {
              FUN_00531910(param_1,iVar8,local_280);
            }
          }
          FUN_00531f50(param_1,iVar8,local_200);
          iVar8 = iVar8 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      ppuVar12 = ppuVar12 + 1;
      local_2b8 = local_2b8 + 1;
    } while ((int)ppuVar12 < 0x567ed4);
    local_2a0 = local_2a0 + -1;
    local_2b8 = piVar7;
    if (local_2a0 == 0) {
      while (iVar4 = FUN_0052ff20(param_1,iVar8), iVar4 != 0) {
        UI_RemoveObject(param_1,iVar8);
        iVar8 = iVar8 + 1;
      }
      return 1;
    }
  } while( true );
}

