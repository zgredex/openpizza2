// rea decompile_all
// name: FUN_004058d0
// address: 0x4058d0
// body: available
// range: 0x4058d0-0x406616 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004058d0(int param_1,undefined4 param_2,int param_3,uint *param_4)

{
  int iVar1;
  void *this;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  undefined4 *puVar5;
  FILE *pFVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  undefined2 *puVar10;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  float10 fVar11;
  int iVar12;
  char cVar13;
  undefined1 local_13f [3];
  int in_stack_fffffec4;
  int in_stack_fffffec8;
  int in_stack_fffffed0;
  int in_stack_fffffed4;
  int local_128 [6];
  CHAR aCStack_110 [260];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00557cfc;
  local_c = ExceptionList;
  cVar13 = '\x10';
  if (param_3 < -0x18608) {
    if (param_3 != -0x18609) {
      switch(param_3) {
      case -0x18684:
        if (DAT_0057c670 == (void *)0x0) {
          return;
        }
        uVar7 = DAT_00581678;
        if (*(int *)(*(int *)(*(int *)((int)DAT_0057c670 + 0x224) + 0xac) + 0xc0) != 0) {
          uVar7 = DAT_00581798;
        }
        ExceptionList = &local_c;
        FUN_0048d420(DAT_0057c670,DAT_00582e4c,uVar7);
        FUN_00548e00(DAT_0057ba0c,0x28);
        ExceptionList = local_c;
        return;
      case -0x18683:
        if (DAT_0057c670 == (void *)0x0) {
          return;
        }
        ExceptionList = &local_c;
        FUN_0048d420(DAT_0057c670,DAT_00582d68,DAT_00582e4c);
        FUN_00548e00(DAT_0057ba0c,0x2b);
        ExceptionList = local_c;
        return;
      default:
        return;
      case -0x1862c:
        goto switchD_0040593b_caseD_fffe79d4;
      case -0x18623:
        if (DAT_0057c670 == (void *)0x0) {
          return;
        }
        ExceptionList = &local_c;
        FUN_0048b570(DAT_0057c670);
        ExceptionList = local_c;
        return;
      case -0x18622:
        ExceptionList = &local_c;
        if (DAT_0057c670 != (void *)0x0) {
          ExceptionList = &local_c;
          FUN_00486590(DAT_0057c670);
        }
        FUN_00548ed0(DAT_0057ba0c);
        ExceptionList = local_c;
        return;
      case -0x1861a:
        if (DAT_0057c670 == (void *)0x0) {
          return;
        }
        ExceptionList = &local_c;
        FUN_0048bb70(DAT_0057c670,param_4);
        ExceptionList = local_c;
        return;
      case -0x18619:
        if (DAT_0057c670 == (void *)0x0) {
          return;
        }
        ExceptionList = &local_c;
        FUN_0048bda0(DAT_0057c670);
        ExceptionList = local_c;
        return;
      case -0x18618:
        if (DAT_0057c670 == (void *)0x0) {
          return;
        }
        ExceptionList = &local_c;
        FUN_0048c160(DAT_0057c670,-1);
        ExceptionList = local_c;
        return;
      case -0x1860a:
        if (DAT_0057c670 == (void *)0x0) {
          return;
        }
        ExceptionList = &local_c;
        FUN_00488d20(DAT_0057c670);
        ExceptionList = local_c;
        return;
      }
    }
    local_128[1] = 0x415;
    local_128[2] = 0x414;
    local_128[3] = 0x413;
    local_128[4] = 0x412;
    local_128[5] = 0x411;
    ExceptionList = &local_c;
    uVar2 = FUN_004034d0(0,100);
    if ((int)uVar2 < 0x4c) {
      ExceptionList = local_c;
      return;
    }
    if (DAT_0057c670 == (void *)0x0) {
      ExceptionList = local_c;
      return;
    }
    pvVar4 = *(void **)((int)DAT_0057c670 + 0x25c);
    if (pvVar4 == (void *)0x0) {
      ExceptionList = local_c;
      return;
    }
    uVar2 = FUN_004034b0(5);
    iVar8 = local_128[uVar2 + 1];
    iVar3 = FUN_0052ff20(pvVar4,iVar8);
    if (iVar3 == 0) {
      ExceptionList = local_c;
      return;
    }
    FUN_00531b70(pvVar4,iVar8,1);
    ExceptionList = local_c;
    return;
  }
  if (0x12 < param_3) {
    if (param_3 != 0x15) {
      if (param_3 == 0x17) {
        ExceptionList = &local_c;
        SetEvent(DAT_0057c0d8);
        ExceptionList = local_c;
        return;
      }
      if (param_3 != 0x20) {
        return;
      }
      if (DAT_0056b40c == 0) {
        ExceptionList = &local_c;
        FUN_00547e70(DAT_0057ba0c);
        ExceptionList = local_c;
        return;
      }
      return;
    }
    if (DAT_0057c670 == (void *)0x0) {
      return;
    }
    if (*(int *)((int)DAT_0057c670 + 0x290) != 5) {
      return;
    }
    if (DAT_00563870 != '\x01') {
      DAT_00563870 = 1;
      return;
    }
    pvVar4 = *(void **)((int)DAT_0057c5e0 + 0x8314);
    if (pvVar4 == (void *)0x0) {
      return;
    }
    ExceptionList = &local_c;
    iVar8 = FUN_00527aa0((int)DAT_0057c5e0);
    puVar10 = (undefined2 *)(iVar8 + 1U & 7);
    iVar8 = FUN_00527ab0((int)DAT_0057c5e0);
    FUN_00527a80(DAT_0057c5e0,puVar10,iVar8);
    FUN_00527ad0(DAT_0057c5e0,(undefined4 *)(local_13f + 7),local_128 + -2);
    iVar3 = FUN_0053d720(pvVar4,in_stack_fffffec8,in_stack_fffffed0,
                         *(int *)(*(int *)((int)DAT_0057c670 + 0xa0) + 0x18));
    if (iVar3 == 0) {
      if (iVar8 == 0) {
        FUN_00527a80(DAT_0057c5e0,puVar10,1);
        ExceptionList = local_c;
        return;
      }
      ExceptionList = local_c;
      return;
    }
    if (iVar8 == 1) {
      FUN_00527a80(DAT_0057c5e0,puVar10,0);
      ExceptionList = local_c;
      return;
    }
    ExceptionList = local_c;
    return;
  }
  if (param_3 == 0x12) {
    if (DAT_0057c670 == (void *)0x0) {
      return;
    }
    if (*(int *)((int)DAT_0057c670 + 0x290) == 4) {
      if ((*(int *)((int)DAT_0057c670 + 0x2a8) != 3) && (*(int *)((int)DAT_0057c670 + 0x2d8) != 0xb)
         ) {
        return;
      }
      ExceptionList = &local_c;
      FUN_00401320(*(int *)((int)DAT_0057c670 + 0x240));
      iVar8 = FUN_00489180(DAT_0057c670,*param_4,param_4[1],0,0,-1,-1);
      if ((iVar8 != 0) &&
         ((FUN_004f4e90(*(void **)((int)DAT_0057c670 + 0x2fc),*param_4,param_4[1],local_128,
                        local_128 + -1,(int *)0x0),
          *(int *)((int)DAT_0057c670 + 0x348) != local_128[0] ||
          (*(int *)((int)DAT_0057c670 + 0x34c) != in_stack_fffffed4)))) {
        *(int *)((int)DAT_0057c670 + 0x348) = local_128[0];
        *(int *)((int)DAT_0057c670 + 0x34c) = in_stack_fffffed4;
      }
      FUN_00401340(*(int *)((int)DAT_0057c670 + 0x240));
      SetEvent(DAT_0057c5ac);
      ExceptionList = local_c;
      return;
    }
    if (*(int *)((int)DAT_0057c670 + 0x290) != 5) {
      return;
    }
    ExceptionList = &local_c;
    if (*(int *)((int)DAT_0057c5e0 + 0x8314) != 0) {
      if (((int)*param_4 < 0x244) && ((int)param_4[1] < 0xb4)) {
        iVar8 = 0;
      }
      else {
        iVar8 = 1;
      }
      ExceptionList = &local_c;
      FUN_0048cae0(DAT_0057c670,iVar8);
    }
    pvVar4 = *(void **)((int)DAT_0057c5e0 + 0x8314);
    if (pvVar4 != (void *)0x0) {
      FUN_00527ad0(DAT_0057c5e0,(undefined4 *)(local_13f + 7),local_128 + -2);
      iVar8 = FUN_00527ab0((int)DAT_0057c5e0);
      if (*(int *)((int)DAT_0057c670 + 0x290) == 5) {
        iVar3 = FUN_0053d720(pvVar4,in_stack_fffffec8,in_stack_fffffed0,
                             *(int *)(*(int *)((int)DAT_0057c670 + 0xa0) + 0x18));
        if (iVar3 == 0) {
          if (iVar8 == 0) {
            puVar10 = (undefined2 *)FUN_00527aa0((int)DAT_0057c5e0);
            FUN_00527a80(DAT_0057c5e0,puVar10,1);
          }
          DAT_0057c5e6 = '\0';
        }
        else {
          if (iVar8 == 1) {
            puVar10 = (undefined2 *)FUN_00527aa0((int)DAT_0057c5e0);
            FUN_00527a80(DAT_0057c5e0,puVar10,0);
          }
          DAT_0057c5e6 = '\x01';
        }
      }
    }
    if (DAT_0057c5e4 == '\x01') {
      if ((int)*param_4 < 0x254) {
        ExceptionList = local_c;
        return;
      }
      FUN_00527a10(DAT_0057c5e0,0,-9999,-9999);
      DAT_0057c5e4 = 0;
      ExceptionList = local_c;
      return;
    }
    if (0x252 < (int)*param_4) {
      ExceptionList = local_c;
      return;
    }
    if (DAT_0057c5e5 == '\0') {
      FUN_00527a10(DAT_0057c5e0,1,-9999,-9999);
      DAT_0057c5e4 = 1;
      ExceptionList = local_c;
      return;
    }
    ExceptionList = local_c;
    return;
  }
  if (0xe < param_3) {
    if (param_3 != 0xf) {
      return;
    }
    iVar8 = 0;
    if (DAT_0057c670 == (void *)0x0) {
      return;
    }
    ExceptionList = &local_c;
    if ((*(int *)((int)DAT_0057c670 + 0x290) == 5) &&
       ((*(int *)((int)DAT_0057c670 + 0x2ac) == 2 ||
        (ExceptionList = &local_c, *(int *)((int)DAT_0057c670 + 0x2ac) == 7)))) {
      ExceptionList = &local_c;
      if ((*(void **)((int)DAT_0057c670 + 0x264) != (void *)0x0) &&
         (ExceptionList = &local_c, DAT_0057c5e6 != '\0')) {
        ExceptionList = &local_c;
        FUN_005301c0(*(void **)((int)DAT_0057c670 + 0x264),-0x1866c,0x23,(int)param_4);
      }
    }
    if (*(int *)((int)DAT_0057c670 + 0x290) != 4) {
      ExceptionList = local_c;
      return;
    }
    if ((*(int *)((int)DAT_0057c670 + 0x2a8) != 3) && (*(int *)((int)DAT_0057c670 + 0x2d8) != 0xb))
    {
      ExceptionList = local_c;
      return;
    }
    if (*(int *)((int)DAT_0057c670 + 0x35c) != 0) {
      *(undefined4 *)((int)DAT_0057c670 + 0x35c) = 0;
      ExceptionList = local_c;
      return;
    }
    iVar3 = *(int *)((int)DAT_0057c670 + 0x34c);
    iVar1 = *(int *)((int)DAT_0057c670 + 0x348);
    iVar9 = FUN_00489180(DAT_0057c670,iVar1,iVar3,1,1,*param_4,param_4[1]);
    if (iVar9 == 0) {
      ExceptionList = local_c;
      return;
    }
    pvVar4 = operator_new(0x24);
    local_4 = 0;
    if (pvVar4 != (void *)0x0) {
      iVar8 = FUN_004e5d60(pvVar4,*(undefined4 *)((int)DAT_0057c670 + 0x344),
                           *(undefined4 *)((int)DAT_0057c670 + 0x354));
    }
    local_4 = 0xffffffff;
    pvVar4 = *(void **)((int)DAT_0057c670 + 0x2fc);
    this = *(void **)((int)DAT_0057c670 + 0x9c);
    if (*(int *)((int)DAT_0057c670 + 0x2d8) != 0xb) {
      iVar12 = -1;
      cVar13 = '\0';
      iVar9 = FUN_004ddcc0(*(int *)((int)DAT_0057c670 +
                                   *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200));
      fVar11 = FUN_004e63f0(iVar8,iVar9);
      FUN_00477e40(this,4,(float)fVar11,cVar13,iVar12);
    }
    FUN_0047e0e0(this,iVar8,iVar1,iVar3);
    iVar3 = FUN_004ef4b0(pvVar4,iVar1,iVar3);
    FUN_004ed330(pvVar4,iVar3,*(int *)((int)pvVar4 + 0x68),1);
    FUN_004f2e50(pvVar4,(int)this);
    FUN_00489bc0(DAT_0057c670,(int)this,iVar8);
    if (*(int *)((int)DAT_0057c670 + 0x2d8) == 0xb) {
      *(undefined4 *)((int)DAT_0057c670 + 0x344) = 0xffffffff;
      *(undefined4 *)((int)pvVar4 + 0x60) = 0;
      *(int *)((int)DAT_0057c670 + 0x220) = iVar8;
      ExceptionList = local_c;
      return;
    }
    ExceptionList = local_c;
    return;
  }
  if (param_3 != 0xe) {
    if (param_3 == -0x18608) {
      if (DAT_0057c670 == (void *)0x0) {
        return;
      }
      ExceptionList = &local_c;
      FUN_004850a0(DAT_0057c670,4,1);
      ExceptionList = local_c;
      return;
    }
    if (param_3 != -0x18607) {
      return;
    }
    if (DAT_0057c670 == (void *)0x0) {
      return;
    }
    ExceptionList = &local_c;
    FUN_004850a0(DAT_0057c670,1,1);
    ExceptionList = local_c;
    return;
  }
  if ((DAT_0057c670 == (void *)0x0) || (iVar8 = *(int *)((int)DAT_0057c670 + 0x268), iVar8 == 0)) {
    ExceptionList = &local_c;
  }
  else {
    iVar3 = 0;
    ExceptionList = &local_c;
    (**(code **)(iVar8 + 0x48))(iVar8,param_4,0xfffe79a9,local_13f + 3);
    if (iVar3 != 0) {
      ExceptionList = local_c;
      return;
    }
    in_stack_fffffec4 = 0;
    param_1 = iVar8;
  }
  if (param_4 == (uint *)(int)(char)local_13f[DAT_0057c608 + -5]) {
    if (local_13f[DAT_0057c608 + -4] == -1) {
      DAT_0057c5b4 = 1;
      DAT_0057c608 = 0;
      ExceptionList = local_c;
      return;
    }
    DAT_0057c608 = DAT_0057c608 + 1;
    ExceptionList = local_c;
    return;
  }
  if (param_1 != 0) {
    (**(code **)(param_1 + 0x48))(param_1,param_4,0xfffe79a9,local_13f + 3);
    if (in_stack_fffffec4 != 0) {
      ExceptionList = local_c;
      return;
    }
    in_stack_fffffec4 = 0;
  }
  if (DAT_0057df90 != 0) {
    (**(code **)(DAT_0057df90 + 0x48))(param_1,param_4,0xe,0);
    ExceptionList = local_c;
    return;
  }
  if (param_4 == (uint *)0x10) {
    if (DAT_0057c5e0 != (void *)0x0) {
      pvVar4 = operator_new(0x11c);
      local_4 = 1;
      if (pvVar4 == (void *)0x0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        puVar5 = FUN_00537230(pvVar4,800,600,2);
      }
      local_4 = 0xffffffff;
      FUN_00523de0(DAT_0057c5e0,puVar5);
      while( true ) {
        iVar8 = DAT_0057c60c;
        DAT_0057c60c = DAT_0057c60c + 1;
        FUN_0054dd83(aCStack_110,(byte *)s_pizza_shot_d_tga_00563c20,iVar8);
        pFVar6 = (FILE *)FUN_0054dfe0(aCStack_110,&DAT_00563184);
        if (pFVar6 == (FILE *)0x0) break;
        FUN_0054dee4(pFVar6);
      }
      FUN_005377f0(DAT_0057c5c8,1,(uint)aCStack_110,unaff_EDI,(char)unaff_ESI,unaff_EBP,
                   (short)unaff_EBX,0x1413,cVar13,in_stack_fffffec4,in_stack_fffffec8,(uint)pvVar4,
                   (char)in_stack_fffffed0,(char)in_stack_fffffed4);
      MessageBeep(0);
      if (puVar5 != (undefined4 *)0x0) {
        (**(code **)*puVar5)(1);
      }
    }
  }
  else if ((param_4 == (uint *)0x13f) && (DAT_0057c5b4 != 0)) {
    FUN_005475a0(DAT_0057ba0c,(uint)(*(char *)((int)DAT_0057ba0c + 0xfc) == '\0'));
  }
  if (DAT_0057c670 == (void *)0x0) {
    ExceptionList = local_c;
    return;
  }
  if ((int)param_4 < 0x132) {
    if (param_4 != (uint *)0x131) {
      switch(param_4) {
      case (uint *)0x2:
        FUN_0048a4c0(DAT_0057c670);
        ExceptionList = local_c;
        return;
      default:
        ExceptionList = local_c;
        return;
      case (uint *)0x6:
        FUN_0048bae0(DAT_0057c670);
        ExceptionList = local_c;
        return;
      case (uint *)0xb:
        if (DAT_0057c5b4 == 0) {
          ExceptionList = local_c;
          return;
        }
        FUN_00482b30((int)DAT_0057c670);
        ExceptionList = local_c;
        return;
      case (uint *)0xd:
        if (DAT_0057c5b4 == 0) {
          ExceptionList = local_c;
          return;
        }
        FUN_004f5fd0(*(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xac),0,'\x01');
        ExceptionList = local_c;
        return;
      case (uint *)0x11:
        FUN_004a21a0();
        ExceptionList = local_c;
        return;
      case (uint *)0x20:
        goto switchD_00405dc8_caseD_20;
      case (uint *)0x67:
        if (DAT_0057c5b4 == 0) {
          ExceptionList = local_c;
          return;
        }
        FUN_00502f10(*(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8),-1,-1,0);
        ExceptionList = local_c;
        return;
      case (uint *)0x6d:
        if (DAT_0057c5b4 == 0) {
          ExceptionList = local_c;
          return;
        }
        pvVar4 = *(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8);
        if (*(char *)((int)pvVar4 + 4) != '\0') {
          ExceptionList = local_c;
          return;
        }
        FUN_00502ce0(pvVar4,0xffffffff,0xffffffff,-1,-1,-1,-1,-1);
        DAT_0057c5fc = DAT_0057c5fc + 1;
        if (0x23 < DAT_0057c5fc) {
          DAT_0057c5fc = 0;
        }
        iVar8 = *(int *)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8);
        uVar7 = FUN_0054aa10((void *)((int)DAT_0057c670 + 0x304),0x21,1,-1,-1,0,DAT_00580d60,
                             DAT_00582e4c,unaff_EDI);
        *(undefined4 *)(iVar8 + 100) = uVar7;
        *(undefined1 *)(*(int *)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8) + 4) = 1;
        ExceptionList = local_c;
        return;
      }
    }
switchD_00405f1d_caseD_133:
    iVar8 = *(int *)((int)DAT_0057c670 + 0x290);
    if (((iVar8 == 1) || (iVar8 == 3)) || (iVar8 == 2)) {
      iVar8 = *(int *)((int)DAT_0057c670 + 0x9c);
      if ((iVar8 == 0) &&
         (iVar8 = FUN_004017f0((void *)(*(int *)((int)DAT_0057c670 +
                                                *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200) +
                                       0x148),0,(int *)0x0), iVar8 == 0)) {
        ExceptionList = local_c;
        return;
      }
      iVar8 = *(int *)(iVar8 + 0x16f0);
      if (iVar8 != 0) {
        *(undefined4 *)((int)DAT_0057c670 + 0x218) = 0;
        FUN_004a9320(iVar8,0);
        *(int *)((int)DAT_0057c670 + 0x218) = iVar8;
        FUN_004d23b0(iVar8);
      }
    }
  }
  else {
    switch(param_4) {
    case (uint *)0x133:
      goto switchD_00405f1d_caseD_133;
    case (uint *)0x139:
      if ((*(int *)((int)DAT_0057c670 + 0x290) < 8) && (*(int *)((int)DAT_0057c670 + 0x290) != 1)) {
        FUN_004850a0(DAT_0057c670,1,0);
      }
      break;
    case (uint *)0x13a:
      if (((*(int *)((int)DAT_0057c670 + 0x290) < 8) &&
          (0 < *(int *)(*(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200
                                ) + 0x15c))) && (*(int *)((int)DAT_0057c670 + 0x290) != 4)) {
        FUN_004850a0(DAT_0057c670,4,0);
      }
      break;
    case (uint *)0x13b:
      if ((*(int *)((int)DAT_0057c670 + 0x290) < 8) && (*(int *)((int)DAT_0057c670 + 0x290) != 5)) {
        FUN_004850a0(DAT_0057c670,5,0);
      }
      break;
    case (uint *)0x13c:
      if ((*(int *)((int)DAT_0057c670 + 0x290) < 8) && (*(int *)((int)DAT_0057c670 + 0x290) != 6)) {
        FUN_004850a0(DAT_0057c670,6,0);
      }
      break;
    case (uint *)0x13d:
      if ((*(int *)((int)DAT_0057c670 + 0x290) < 8) && (*(int *)((int)DAT_0057c670 + 0x290) != 7)) {
        FUN_004850a0(DAT_0057c670,7,0);
      }
      break;
    case (uint *)0x141:
      if (DAT_0057c5b4 != 0) {
        *(uint *)(*(int *)((int)DAT_0057c670 + 0x94) + 0x14) =
             (-(uint)(*(int *)(*(int *)((int)DAT_0057c670 + 0x94) + 0x14) != 0xc35) & 0xbd1) + 100;
      }
      break;
    case (uint *)0x191:
      if (DAT_0057c5b4 == 0) {
        if (*(int *)((int)DAT_0057c670 + 0x1508) == 0) {
          FUN_00488cc0(DAT_0057c670);
          DAT_0057c5c0 = 8;
          FUN_0048d4c0(DAT_00582e4c,DAT_005827e8);
        }
      }
      else if (*(int *)((int)DAT_0057c670 + 0x1508) == 0) {
        FUN_00488cc0(DAT_0057c670);
      }
      else {
        FUN_00488d20(DAT_0057c670);
      }
    }
  }
  ExceptionList = local_c;
  return;
switchD_0040593b_caseD_fffe79d4:
  if (DAT_0057c670 == (void *)0x0) {
    return;
  }
  iVar8 = *(int *)((int)DAT_0057c670 + 0x288);
  if (iVar8 == 0) {
    return;
  }
  iVar3 = *(int *)((int)DAT_0057c670 + 0x290);
  if (((iVar3 == 1) || (iVar3 == 2)) || (iVar3 == 3)) {
    ExceptionList = &local_c;
    *(undefined4 *)((int)DAT_0057c670 + 0x218) = 0;
    FUN_004a9320(iVar8,0);
    *(int *)((int)DAT_0057c670 + 0x218) = iVar8;
    FUN_004d23b0(iVar8);
    ExceptionList = local_c;
    return;
  }
  ExceptionList = &local_c;
  *(int *)((int)DAT_0057c670 + 0x218) = iVar8;
  FUN_004d23b0(iVar8);
  FUN_004850a0(DAT_0057c670,1,1);
  ExceptionList = local_c;
  return;
switchD_00405dc8_caseD_20:
  if (*(int *)((int)DAT_0057c670 + 0x290) != 4) {
    ExceptionList = local_c;
    return;
  }
  if (*(int *)((int)DAT_0057c670 + 0x2a8) == 3) {
    FUN_0048cfa0(DAT_0057c670,1);
    ExceptionList = local_c;
    return;
  }
  ExceptionList = local_c;
  return;
}

