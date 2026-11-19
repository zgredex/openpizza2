// rea decompile_all
// name: FUN_0040b400
// address: 0x40b400
// body: available
// range: 0x40b400-0x40b895 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_0040b400(void *this,void *param_1)

{
  int iVar1;
  undefined1 uVar2;
  undefined3 extraout_var;
  undefined4 *puVar3;
  void *pvVar4;
  int iVar5;
  uint extraout_EDX;
  uint uVar6;
  uint extraout_EDX_00;
  uint extraout_EDX_01;
  void *pvVar7;
  undefined4 uVar8;
  int iVar9;
  
  uVar2 = FUN_00505e00((int)param_1);
  iVar9 = *(int *)((int)param_1 + 0x90);
  iVar1 = *(int *)((int)param_1 + 0x78);
  FUN_00507170((int)param_1);
  iVar5 = *(int *)((int)param_1 + 0x30);
  if (iVar5 != 0x2e) {
    if (CONCAT31(extraout_var,uVar2) != 0) goto LAB_0040b821;
    uVar6 = extraout_EDX;
    if (iVar5 - 0xcU < 0x17) {
      uVar6 = (uint)*(byte *)((int)&PTR_caseD_1e_0040b8a4 + iVar5);
      switch(iVar5) {
      case 0xc:
        if ((*(int *)((int)param_1 + 0x38) == 0x34) &&
           (iVar5 = *(int *)((int)param_1 + 0x98) + -1, *(int *)((int)param_1 + 0x98) = iVar5,
           iVar5 == 0)) {
          iVar5 = *(int *)((int)param_1 + 0x100);
          uVar8 = 9;
LAB_0040b67d:
          FUN_00507e20(param_1,uVar8,iVar5);
          *(undefined4 *)((int)param_1 + 0x98) = 0xffffffff;
          uVar6 = extraout_EDX_01;
        }
        break;
      case 0xd:
        iVar5 = *(int *)((int)param_1 + 0x38);
        if (iVar5 != 0x18) goto LAB_0040b61c;
        iVar5 = *(int *)((int)param_1 + 0x98) + -1;
        *(int *)((int)param_1 + 0x98) = iVar5;
        if (iVar5 == 0) {
          iVar5 = *(int *)((int)param_1 + 0x100);
          uVar8 = 0xb;
          goto LAB_0040b67d;
        }
        break;
      case 0x17:
      case 0x1d:
        iVar5 = *(int *)((int)param_1 + 0x38);
        if (iVar5 != 0x3a) goto LAB_0040b61c;
LAB_0040b621:
        FUN_0050dd10(param_1);
        uVar6 = extraout_EDX_00;
        break;
      case 0x1e:
        iVar5 = *(int *)((int)param_1 + 0x38);
LAB_0040b61c:
        if (iVar5 == 0x3b) goto LAB_0040b621;
        break;
      case 0x22:
        if (*(int *)((int)param_1 + 0x38) == 8) {
          iVar9 = *(int *)((int)param_1 + 0x88);
          *(undefined4 *)((int)param_1 + 0x98) = 3;
          FUN_0050e890(param_1,0x35);
          FUN_00509060(param_1,iVar9 + 0x10);
          return;
        }
      }
    }
    if (iVar1 != 0) {
      FUN_00508d90(param_1,0,*(int *)((int)param_1 + 0x78));
      return;
    }
    if (iVar9 != 0) {
      if (*(int *)((int)param_1 + 200) == 0) {
        iVar9 = 0;
      }
      else {
        iVar9 = *(int *)(*(int *)((int)param_1 + 200) + 0x20);
      }
      if (*(int *)((int)param_1 + 0xf8) == iVar9) {
        uVar8 = *(undefined4 *)((int)param_1 + 0x90);
        *(undefined4 *)((int)param_1 + 0x90) = 0;
        switch(uVar8) {
        case 1:
          goto switchD_0040b707_caseD_1;
        case 2:
          FUN_0050a3c0(param_1,uVar6);
          return;
        case 3:
          FUN_0050a950(param_1);
          return;
        case 4:
          FUN_0050a280(param_1);
          return;
        default:
          if (*(int *)((int)param_1 + 0xfc) == 0) {
            FUN_00403510();
          }
          FUN_0050ab30(param_1,*(void **)((int)param_1 + 0xfc));
          return;
        case 8:
          FUN_0050a110(param_1);
          return;
        case 9:
          FUN_0050a7e0(param_1);
          return;
        case 10:
          FUN_0050a920(param_1);
          return;
        case 0xb:
          if (*(int *)(*(int *)((int)param_1 + 0xfc) + 4) != 0xf) {
            return;
          }
switchD_0040b707_caseD_1:
          FUN_00508300(param_1,uVar6);
          return;
        case 0xc:
          FUN_0050a580(param_1);
          return;
        }
      }
    }
    iVar9 = *(int *)((int)param_1 + 0x38);
    if (iVar9 == 2) {
      FUN_0050ab30(param_1,*(void **)((int)param_1 + 0xfc));
      FUN_00506c00(param_1);
    }
    else if (iVar9 == 3) {
      FUN_00507b40(param_1);
    }
    else if (iVar9 == 0x1d) {
      if (*(int *)((int)param_1 + 0xfc) == 0) {
        FUN_00403510();
      }
      FUN_0050ab70(param_1,*(void **)((int)param_1 + 0xfc));
      FUN_0050e890(param_1,3);
    }
LAB_0040b821:
    if ((CONCAT31(extraout_var,uVar2) != 0) && (*(int *)((int)param_1 + 0x30) == 0x22)) {
      if (*(int *)((int)param_1 + 0x38) == 8) {
        if (*(int *)((int)param_1 + 200) == 0) {
          *(undefined4 *)((int)param_1 + 0x88) = 0xffffffff;
          return;
        }
        *(undefined4 *)((int)param_1 + 0x88) = *(undefined4 *)(*(int *)((int)param_1 + 200) + 0xc);
        return;
      }
      if ((*(int *)((int)param_1 + 0x38) == 0x35) &&
         (iVar9 = *(int *)((int)param_1 + 0x98) + -1, *(int *)((int)param_1 + 0x98) = iVar9,
         iVar9 == 0)) {
        UI_DetachChildRecord((int)param_1);
        FUN_00507c90(param_1);
        FUN_0050e890(param_1,8);
      }
    }
    return;
  }
  if (0 < *(int *)((int)param_1 + 0x98)) {
    *(int *)((int)param_1 + 0x98) = *(int *)((int)param_1 + 0x98) + -1;
  }
  if (*(int *)((int)param_1 + 0x38) == 0x18) {
    if (*(int *)((int)param_1 + 0x98) == 0) {
      FUN_00509060(param_1,0);
      Sound_PlayEffectByIndex(DAT_0057ba0c,0x1b);
      *(undefined4 *)((int)param_1 + 0x98) = 6;
      FUN_0050e890(param_1,0x3c);
      return;
    }
    return;
  }
  if (*(int *)((int)param_1 + 0x38) != 0x3c) {
    return;
  }
  if (*(int *)((int)param_1 + 0x98) != 4) goto LAB_0040b570;
  iVar9 = *(int *)((int)param_1 + 0x8c);
  if (iVar9 == 1) {
    pvVar7 = *(void **)((int)param_1 + 0xcc);
    pvVar4 = (void *)FUN_004017f0((void *)((int)this + 4),*(int *)((int)this + 0x2f4),(int *)0x0);
    FUN_004d77b0(pvVar4,pvVar7,7,-1,(void *)0x23,-1);
    *(undefined4 *)((int)pvVar7 + 0x50) = 1;
    *(undefined4 *)((int)pvVar7 + 0x4c) = 0;
LAB_0040b55d:
    *(undefined4 *)((int)pvVar7 + 0xc) = 0xffffffff;
  }
  else {
    if (iVar9 == 2) {
      pvVar7 = *(void **)((int)param_1 + 0xcc);
      iVar9 = 1;
      pvVar4 = (void *)FUN_00488be0(this,*(int *)((int)pvVar7 + 8));
      FUN_004e3900(pvVar4,iVar9);
      if (*(void **)(DAT_0057c670 + 0x264) != (void *)0x0) {
        FUN_005301c0(*(void **)(DAT_0057c670 + 0x264),-0x18629,0x23,0);
      }
      goto LAB_0040b55d;
    }
    if (iVar9 == 3) {
      pvVar7 = *(void **)((int)param_1 + 0xcc);
      puVar3 = (undefined4 *)
               Game_GetPlayerMapValue(this,*(int *)((int)pvVar7 + 8),*(int *)((int)pvVar7 + 0x2c));
      if (puVar3 != (undefined4 *)0x0) {
        FUN_004871a0(this,puVar3);
      }
      pvVar4 = (void *)FUN_004017f0((void *)((int)this + 4),*(int *)((int)this + 0x2f4),(int *)0x0);
      FUN_004d77b0(pvVar4,pvVar7,7,-1,(void *)0x23,-1);
      *(undefined4 *)((int)pvVar7 + 0x50) = 1;
      *(undefined4 *)((int)pvVar7 + 0x4c) = 0;
      if (*(void **)((int)this + 0x264) != (void *)0x0) {
        FUN_005301c0(*(void **)((int)this + 0x264),-0x18613,0x23,0);
      }
      goto LAB_0040b55d;
    }
  }
  *(undefined4 *)(*(int *)((int)param_1 + 0xcc) + 0x94) = 0;
LAB_0040b570:
  if (0 < *(int *)((int)param_1 + 0x98)) {
    return;
  }
  if (*(int *)((int)param_1 + 0x38) == 0x2e) {
    return;
  }
  FUN_0050e890(param_1,0x2e);
  *(undefined4 *)((int)this + 0x368) = 1;
  FUN_0050e710(param_1,1);
  return;
}

