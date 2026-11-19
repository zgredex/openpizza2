// rea decompile_all
// name: FUN_00485bb0
// address: 0x485bb0
// body: available
// range: 0x485bb0-0x48652a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
FUN_00485bb0(void *this,char *param_1,undefined4 param_2,int param_3,undefined4 param_4,
            char *param_5,undefined4 param_6,int param_7,undefined4 param_8,char *param_9,
            undefined4 param_10,int param_11,undefined4 param_12,char *param_13,undefined4 param_14,
            int param_15,undefined4 param_16,char *param_17,undefined4 param_18,int param_19,
            undefined4 param_20,undefined *param_21,undefined4 param_22,int param_23,
            undefined4 param_24,char *param_25,undefined4 param_26,int param_27,undefined4 param_28,
            undefined *param_29,undefined4 param_30,int param_31,undefined4 param_32,char *param_33,
            undefined4 param_34,int param_35,undefined4 param_36,char *param_37,undefined4 param_38,
            int param_39,undefined4 param_40,char *param_41,undefined4 param_42,int param_43,
            undefined4 param_44,char *param_45,undefined4 param_46,int param_47,undefined4 param_48,
            char *param_49,undefined4 param_50,int param_51,undefined4 param_52,char *param_53,
            undefined4 param_54,int param_55,undefined4 param_56,char *param_57,undefined4 param_58,
            int param_59,undefined4 param_60,char *param_61,undefined4 param_62,int param_63,
            undefined4 param_64,char *param_65,undefined4 param_66,int param_67,undefined4 param_68,
            char *param_69,undefined4 param_70,int param_71,undefined4 param_72,char *param_73,
            undefined4 param_74,int param_75,undefined4 param_76,char *param_77,undefined4 param_78,
            int param_79,undefined4 param_80,char *param_81,undefined4 param_82,int param_83,
            undefined4 param_84,char *param_85,undefined4 param_86,int param_87)

{
  undefined4 uVar1;
  bool bVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  void *pvVar6;
  undefined4 *puVar7;
  char *pcVar8;
  void *pvVar9;
  DWORD DVar10;
  undefined4 unaff_EBX;
  char *unaff_EBP;
  undefined4 unaff_ESI;
  int unaff_EDI;
  undefined4 unaff_retaddr;
  int aiStack_234 [128];
  int *piVar11;
  int in_stack_ffffffec;
  int in_stack_fffffff0;
  char *in_stack_fffffff4;
  undefined4 in_stack_fffffff8;
  int in_stack_fffffffc;
  int iVar12;
  
  if (*(int *)((int)this + 0x2dc) == 0) goto LAB_0048651d;
  if (*(int *)((int)this + 0x268) != 0) {
    FUN_00482890((int)this);
  }
  if ((*(char *)((int)this + 0x294) != '\x01') ||
     ((*(int *)((int)this + 0x2dc) != 2 && (*(int *)((int)this + 0x2dc) != 3)))) {
    FUN_00403d30((int)this + 0x2d1c);
    *(undefined4 *)((int)this + 0x2fc) = 0;
    if (*(undefined4 **)((int)this + 0x300) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)((int)this + 0x300))(1);
      *(undefined4 *)((int)this + 0x300) = 0;
    }
    FUN_00403d40((int)this + 0x2d1c);
    FUN_00482860((undefined4 *)((int)this + 0x25c));
  }
  puVar7 = (undefined4 *)((int)this + 0x260);
  FUN_00482860(puVar7);
  uVar1 = *(undefined4 *)((int)this + 0x21c);
  FUN_00482860((undefined4 *)((int)this + 0x264));
  *(undefined4 *)((int)this + 0x21c) = uVar1;
  *(undefined4 *)((int)this + 0x2da8) = 1;
  UI_ClearTransientEntries(DAT_0057c5e0,1,1);
  *(undefined4 *)((int)this + 0x2e4) = 0;
  *(undefined4 *)((int)this + 0x290) = *(undefined4 *)((int)this + 0x2dc);
  switch(*(undefined4 *)((int)this + 0x2dc)) {
  case 1:
    pvVar9 = FUN_00430a80(aiStack_234 + 0x88);
    FUN_004a90a0(pvVar9);
    iVar5 = *(int *)((int)this + 0x21c);
    *(void **)((int)this + 0x25c) = pvVar9;
    if (iVar5 == 0) {
      iVar12 = *(int *)((int)this + 0x218);
    }
    else {
      iVar12 = 0;
    }
    iVar3 = *(int *)((int)this + *(int *)((int)this + 0x290) * 4 + 0x298);
    if ((iVar3 == 10) || (iVar3 == 3)) {
      *(undefined4 *)((int)this + 700) = *(undefined4 *)((int)this + 0x29c);
      *(undefined4 *)((int)this + 0x29c) = 1;
      *(undefined4 *)((int)this + 0x218) = 0;
      *(undefined4 *)((int)this + 0x21c) = 0;
      *(undefined4 *)((int)this + 0x2da8) = 1;
      *(undefined4 *)((int)this + 0x220) = 0;
    }
    FUN_004859c0(this,pvVar9);
    iVar3 = IDMap_Lookup((void *)((int)this + 4),*(int *)((int)this + 0x2f4),(int *)0x0);
    FUN_00488db0(this,*(void **)(iVar3 + 0xfa8));
    pvVar9 = FUN_00484650(this,(int *)0x0);
    pvVar6 = FUN_00427a80(aiStack_234 + 0x89);
    FUN_004cec60(pvVar6);
    *puVar7 = pvVar6;
    FUN_00523d60(DAT_0057c5e0,in_stack_ffffffec);
    FUN_00523d60(DAT_0057c5e0,(int)pvVar9);
    FUN_00523d60(DAT_0057c5e0,in_stack_fffffff0);
    *(undefined1 *)((int)this + 0x294) = 1;
    if (*(int *)((int)this + 0x2e0) != 0) {
      if (iVar12 == 0) {
        FUN_00483fd0(this,0,iVar5,0,1);
      }
      else {
        *(undefined4 *)((int)this + 0x218) = 0;
        FUN_004a9320(iVar12,0);
      }
    }
    break;
  case 2:
    if (*(char *)((int)this + 0x294) == '\0') {
      pvVar9 = FUN_00430a80(aiStack_234 + 0x88);
      FUN_004a90a0(pvVar9);
      *(void **)((int)this + 0x25c) = pvVar9;
      FUN_004859c0(this,pvVar9);
      iVar5 = IDMap_Lookup((void *)((int)this + 4),*(int *)((int)this + 0x2f4),(int *)0x0);
      FUN_00488db0(this,*(void **)(iVar5 + 0xfa8));
    }
    *(undefined4 *)((int)this + 0x2e4) = 10;
    iVar5 = FUN_004848b0((int)this);
    pvVar9 = FUN_00427930(aiStack_234 + 0x89);
    FUN_004cefe0(pvVar9);
    *puVar7 = pvVar9;
    if (*(char *)((int)this + 0x294) == '\0') {
      FUN_00523d60(DAT_0057c5e0,in_stack_ffffffec);
    }
    FUN_00523d60(DAT_0057c5e0,iVar5);
    goto LAB_00485f22;
  case 3:
    if (*(char *)((int)this + 0x294) == '\0') {
      pvVar9 = FUN_00430a80(aiStack_234 + 0x88);
      FUN_004a90a0(pvVar9);
      *(void **)((int)this + 0x25c) = pvVar9;
      FUN_004859c0(this,pvVar9);
      iVar5 = IDMap_Lookup((void *)((int)this + 4),*(int *)((int)this + 0x2f4),(int *)0x0);
      FUN_00488db0(this,*(void **)(iVar5 + 0xfa8));
    }
    iVar5 = FUN_00484a90((int)this);
    *(undefined4 *)((int)this + 0x2e4) = 0xc;
    pvVar9 = FUN_00430950(aiStack_234 + 0x89);
    FUN_004cf380(pvVar9);
    *puVar7 = pvVar9;
    if (*(char *)((int)this + 0x294) == '\0') {
      FUN_00523d60(DAT_0057c5e0,in_stack_ffffffec);
    }
    FUN_00523d60(DAT_0057c5e0,iVar5);
LAB_00485f22:
    FUN_00523d60(DAT_0057c5e0,in_stack_fffffff0);
    *(undefined1 *)((int)this + 0x294) = 1;
    break;
  case 4:
    iVar5 = *(int *)((int)this + 0x21c);
    *(undefined4 *)((int)this + 0x218) = 0;
    *(undefined4 *)((int)this + 0x21c) = 0;
    *(undefined4 *)((int)this + 0x2da8) = 1;
    *(undefined4 *)((int)this + 0x220) = 0;
    if ((*(int *)((int)this + 0x9c) == 0) ||
       (bVar2 = FUN_0047fd70(*(int *)((int)this + 0x9c)), !bVar2)) {
      pvVar6 = FUN_0044d4a0(aiStack_234 + 0x88);
      pvVar9 = pvVar6;
      FUN_004ba0d0(pvVar6);
      *(void **)((int)this + 0x25c) = pvVar6;
      if (*(int *)((int)this + *(int *)((int)this + 0x290) * 4 + 0x298) == 10) {
        *(undefined4 *)((int)this + 0x2c8) = *(undefined4 *)((int)this + 0x2a8);
        *(undefined4 *)((int)this + 0x2a8) = 1;
      }
      if (*(int *)((int)this + *(int *)((int)this + 0x290) * 4 + 0x298) == 10) {
        *(undefined4 *)((int)this + 0x2c8) = *(undefined4 *)((int)this + 0x2a8);
        *(undefined4 *)((int)this + 0x2a8) = 1;
      }
      if (*(int *)((int)this + *(int *)((int)this + 0x290) * 4 + 0x298) == 9) {
        *(undefined4 *)((int)this + 0x2c8) = *(undefined4 *)((int)this + 0x2a8);
        *(undefined4 *)((int)this + 0x2a8) = 1;
      }
      pvVar6 = (void *)FUN_004844c0((int)this);
      pvVar4 = FUN_00443980(aiStack_234 + 0x89);
      FUN_004cfa20(pvVar4);
    }
    else {
      pvVar6 = FUN_0041a2b0(aiStack_234 + 0x88);
      pvVar9 = pvVar6;
      FUN_0048e800(pvVar6);
      *(void **)((int)this + 0x25c) = pvVar6;
      if (*(int *)((int)this + *(int *)((int)this + 0x290) * 4 + 0x298) == 10) {
        *(undefined4 *)((int)this + 0x2c8) = *(undefined4 *)((int)this + 0x2a8);
        *(undefined4 *)((int)this + 0x2a8) = 1;
      }
      if (*(int *)((int)this + *(int *)((int)this + 0x290) * 4 + 0x298) == 10) {
        *(undefined4 *)((int)this + 0x2c8) = *(undefined4 *)((int)this + 0x2a8);
        *(undefined4 *)((int)this + 0x2a8) = 1;
      }
      pvVar6 = FUN_00484270(this);
      pvVar4 = FUN_0040bb00(aiStack_234 + 0x89);
      FUN_004cf690(pvVar4);
    }
    *puVar7 = pvVar4;
    FUN_004859c0(this,pvVar9);
    FUN_00488de0(this,*(int *)((int)this + 0x9c));
    FUN_00523d60(DAT_0057c5e0,in_stack_ffffffec);
    FUN_00523d60(DAT_0057c5e0,(int)pvVar6);
    FUN_00523d60(DAT_0057c5e0,in_stack_fffffff0);
    *(undefined1 *)((int)this + 0x294) = 0;
    if (*(int *)((int)this + 0x2e0) != 0) {
      FUN_00483fd0(this,0,iVar5,0,1);
    }
    break;
  case 5:
    *(undefined4 *)((int)this + 0x218) = 0;
    *(undefined4 *)((int)this + 0x21c) = 0;
    *(undefined4 *)((int)this + 0x2da8) = 1;
    *(undefined4 *)((int)this + 0x220) = 0;
    pvVar9 = FUN_004258c0(aiStack_234 + 0x88);
    FUN_0049f6e0(pvVar9);
    *(void **)((int)this + 0x25c) = pvVar9;
    iVar5 = FUN_00484c50((int)this);
    pvVar9 = FUN_0041a6d0(aiStack_234 + 0x89);
    FUN_004cfc80(pvVar9);
    *puVar7 = pvVar9;
    FUN_00523d60(DAT_0057c5e0,in_stack_ffffffec);
    FUN_00523d60(DAT_0057c5e0,iVar5);
    goto LAB_004862a4;
  case 6:
    *(undefined4 *)((int)this + 0x218) = 0;
    *(undefined4 *)((int)this + 0x21c) = 0;
    *(undefined4 *)((int)this + 0x2da8) = 1;
    *(undefined4 *)((int)this + 0x220) = 0;
    pvVar9 = FUN_00443520(aiStack_234 + 0x88);
    *(void **)((int)this + 0x25c) = pvVar9;
    pvVar6 = FUN_00484de0(this);
    FUN_004b5110(pvVar9);
    pvVar9 = FUN_00430ed0(aiStack_234 + 0x89);
    FUN_004d0040(pvVar9);
    *puVar7 = pvVar9;
    FUN_00523d60(DAT_0057c5e0,in_stack_ffffffec);
    FUN_00523d60(DAT_0057c5e0,(int)pvVar6);
    goto LAB_004862a4;
  case 7:
    *(undefined4 *)((int)this + 0x218) = 0;
    *(undefined4 *)((int)this + 0x21c) = 0;
    *(undefined4 *)((int)this + 0x2da8) = 1;
    *(undefined4 *)((int)this + 0x220) = 0;
    pvVar9 = FUN_004275a0(aiStack_234 + 0x88);
    FUN_004a24a0(pvVar9);
    *(void **)((int)this + 0x25c) = pvVar9;
    pvVar9 = FUN_00484f60(this);
    pvVar6 = FUN_00425e70(aiStack_234 + 0x89);
    FUN_004d01c0(pvVar6);
    *puVar7 = pvVar6;
    FUN_00523d60(DAT_0057c5e0,in_stack_ffffffec);
    FUN_00523d60(DAT_0057c5e0,(int)pvVar9);
LAB_004862a4:
    FUN_00523d60(DAT_0057c5e0,in_stack_fffffff0);
    *(undefined1 *)((int)this + 0x294) = 0;
    break;
  case 9:
  case 10:
    if (*(int *)((int)this + 0x1508) == 0) {
      FUN_00488cc0(this);
    }
    FUN_00523f10(DAT_0057c5e0,*(int *)((int)this + 0x2dac));
    puVar7 = (undefined4 *)UI_FindWindowByID(DAT_0057c5e0,*(int *)((int)this + 0x2dac),(int *)0x0);
    FUN_00526700(DAT_0057c5e0,puVar7);
    pcVar8 = FUN_0046f9c0(aiStack_234 + 0x88);
    FUN_004ca880(pcVar8);
    goto LAB_00486408;
  case 0xb:
    if (*(int *)((int)this + 0x1508) == 0) {
      FUN_00488cc0(this);
    }
    FUN_00523f10(DAT_0057c5e0,*(int *)((int)this + 0x2dac));
    puVar7 = (undefined4 *)UI_FindWindowByID(DAT_0057c5e0,*(int *)((int)this + 0x2dac),(int *)0x0);
    FUN_00526700(DAT_0057c5e0,puVar7);
    pcVar8 = FUN_0046ee80(aiStack_234 + 0x88);
    FUN_004c86f0(pcVar8);
    goto LAB_00486408;
  case 0xc:
    FUN_00523f10(DAT_0057c5e0,*(int *)((int)this + 0x2dac));
    puVar7 = (undefined4 *)UI_FindWindowByID(DAT_0057c5e0,*(int *)((int)this + 0x2dac),(int *)0x0);
    FUN_00526700(DAT_0057c5e0,puVar7);
    pvVar9 = FUN_00475f90(aiStack_234 + 0x88);
    FUN_004ce720(pvVar9);
    FUN_00523d60(DAT_0057c5e0,in_stack_ffffffec);
    *(void **)((int)this + 0x25c) = pvVar9;
    if (DAT_0056b40c == 0) {
      return;
    }
    do {
      FUN_00525a10(DAT_0057c5e0,0);
      Sleep(1);
      DVar10 = WaitForSingleObject(DAT_0057c0d8,0);
      if (DVar10 == 0) {
        return;
      }
    } while (DAT_0056b40c != 0);
    return;
  case 0x16:
    if (*(int *)((int)this + 0x1508) == 0) {
      FUN_00488cc0(this);
    }
    FUN_00523f10(DAT_0057c5e0,*(int *)((int)this + 0x2dac));
    puVar7 = (undefined4 *)UI_FindWindowByID(DAT_0057c5e0,*(int *)((int)this + 0x2dac),(int *)0x0);
    FUN_00526700(DAT_0057c5e0,puVar7);
    if ((DAT_0057c5c0 == 2) && (9 < DAT_0057bb40)) {
      FUN_00548db0(DAT_0057ba0c);
      FUN_004ce9d0(0,s_won_s_bik_00568120);
      FUN_004ce9d0(0,s_credits_s_bik_00568110);
      *(undefined1 *)((int)this + 0x2d94) = 0;
      DAT_0056386c = 0x15;
      return;
    }
    piVar11 = aiStack_234 + 0x88;
    pcVar8 = FUN_00474df0(piVar11);
    FUN_004cdac0(pcVar8,piVar11,unaff_EDI,unaff_ESI,unaff_EBP,unaff_EBX,in_stack_ffffffec,
                 in_stack_fffffff0,in_stack_fffffff4,in_stack_fffffff8,in_stack_fffffffc,
                 unaff_retaddr,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                 param_9,param_10,param_11,param_12,param_13,param_14,param_15,param_16,param_17,
                 param_18,param_19,param_20,param_21,param_22,param_23,param_24,param_25,param_26,
                 param_27,param_28,param_29,param_30,param_31,param_32,param_33,param_34,param_35,
                 param_36,param_37,param_38,param_39,param_40,param_41,param_42,param_43,param_44,
                 param_45,param_46,param_47,param_48,param_49,param_50,param_51,param_52,param_53,
                 param_54,param_55,param_56,param_57,param_58,param_59,param_60,param_61,param_62,
                 param_63,param_64,param_65,param_66,param_67,param_68,param_69,param_70,param_71,
                 param_72,param_73,param_74,param_75,param_76,param_77,param_78,param_79,param_80,
                 param_81,param_82,param_83,param_84,param_85,param_86,param_87);
LAB_00486408:
    FUN_00523d60(DAT_0057c5e0,in_stack_ffffffec);
    *(char **)((int)this + 0x25c) = pcVar8;
    break;
  case 0x19:
    DAT_0057c688 = FUN_004756e0(aiStack_234 + 0x88);
    FUN_004ce450(DAT_0057c688);
    FUN_00523d60(DAT_0057c5e0,in_stack_ffffffec);
    *(void **)((int)this + 0x25c) = DAT_0057c688;
    break;
  case 0x1d:
    *(undefined1 *)((int)this + 0x2d94) = 0;
  }
  *(undefined4 *)((int)this + 0x2dc) = 0;
  FUN_00527f80(DAT_0057c5e0,*(int *)((int)this + 0x2dac));
LAB_0048651d:
  *(undefined4 *)((int)this + 0x2e0) = 0;
  return;
}

