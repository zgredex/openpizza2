// rea decompile_all
// name: FUN_00406ff0
// address: 0x406ff0
// body: available
// range: 0x406ff0-0x407d0a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_00406ff0(void *this,void *param_1,void *param_2)

{
  int *piVar1;
  void *this_00;
  undefined1 uVar2;
  char cVar3;
  undefined3 extraout_var;
  void *pvVar4;
  int iVar5;
  float fVar6;
  void *pvVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  undefined3 extraout_var_00;
  undefined1 unaff_SI;
  undefined4 unaff_EDI;
  bool bVar12;
  undefined8 uVar13;
  undefined4 local_28;
  int local_24 [9];
  
  this_00 = param_2;
  local_24[1] = 0x10;
  local_24[2] = 0x12;
  local_24[3] = 0x14;
  local_24[4] = 0x16;
  local_24[5] = 0x11;
  local_24[6] = 0x13;
  local_24[7] = 0x15;
  local_24[8] = 0x17;
  uVar2 = FUN_00505e00((int)param_2);
  local_24[0] = CONCAT31(extraout_var,uVar2);
  pvVar7 = *(void **)((int)this_00 + 0xc4);
  bVar12 = local_24[0] == 0;
  if (((*(int *)((int)this_00 + 0x30) == 0x1d) && (*(int *)((int)this_00 + 0xa4) == 0x10)) ||
     (*(int *)((int)this_00 + 0x30) == 0x1e)) {
    pvVar4 = (void *)IDMap_Lookup((void *)((int)this + 4),*(int *)((int)this + 0x2f4),(int *)0x0);
    FUN_004d9de0(pvVar4,param_1);
  }
  pvVar4 = param_1;
  if (*(int *)((int)this_00 + 0x38) == 0x2d) {
    if (bVar12) {
      iVar5 = FUN_0050e890(this_00,0x2e);
      *(undefined4 *)((int)this + 0x368) = 1;
      return iVar5;
    }
    iVar5 = *(int *)((int)this_00 + 0x30);
    if ((iVar5 != 0x17) && (iVar5 != 0xd)) {
      return iVar5;
    }
    piVar1 = *(int **)((int)this_00 + 200);
    if (piVar1 == (int *)0x0) {
      iVar5 = -1;
      pvVar7 = (void *)0x0;
    }
    else {
      iVar5 = *piVar1;
      pvVar7 = (void *)piVar1[0x16];
    }
    uVar13 = FUN_00534370(pvVar7,iVar5,local_24,&param_1);
    if ((int)param_1 < 0x15e) {
      FUN_005090e0((int)this_00);
      FUN_0050e890(this_00,0x2e);
      *(undefined4 *)((int)this + 0x368) = 1;
      return (int)this;
    }
    return (int)uVar13;
  }
  if (!bVar12) goto LAB_004078a4;
  switch(*(int *)((int)this_00 + 0x38)) {
  case 5:
    iVar5 = *(int *)((int)this_00 + 0xa4);
    switch(iVar5) {
    default:
      goto switchD_00407151_caseD_9;
    case 0xe:
      iVar5 = FUN_004f4f20(pvVar7,1);
      if (iVar5 == 0) {
        FUN_0050e890(this_00,6);
      }
      else {
LAB_00407216:
        FUN_00507d90(this_00,iVar5);
        FUN_0050e890(this_00,8);
      }
      break;
    case 0xf:
      iVar5 = FUN_0050adf0(this_00);
      if (iVar5 != 0) {
        return iVar5;
      }
      iVar5 = FUN_004f5310(pvVar7,(int)this_00,param_1,&local_28,&param_2);
      if (iVar5 == 0) goto LAB_004077e2;
      _DAT_0057c610 = FUN_0050e6b0(this_00,iVar5);
      if (_DAT_0057c610 != 0) {
        *(undefined4 *)((int)this_00 + 0x8c) = local_28;
        *(int *)((int)this_00 + 0x88) = local_24[(int)param_2 + 1];
      }
      break;
    case 0x10:
    case 0x19:
    case 0x1a:
      if ((iVar5 == 0x1a) && (uVar8 = FUN_004034d0(1,100), (int)uVar8 < 5)) {
        FUN_004f4f20(pvVar7,1);
      }
      else {
        FUN_004f50d0(0,0,0,unaff_EDI,unaff_SI);
      }
LAB_004072d7:
      iVar5 = FUN_004f50d0(0,0,0,unaff_EDI,unaff_SI);
      if (iVar5 == 0) {
        FUN_0050bc40(this_00);
        FUN_0050e890(this_00,6);
      }
      else {
LAB_00407499:
        _DAT_0057c610 = FUN_0050e6b0(this_00,iVar5);
      }
      break;
    case 0x12:
      *(undefined4 *)((int)this_00 + 0x84) = 0xffffffff;
      *(undefined4 *)((int)this_00 + 0x8c) = 0xffffffff;
      uVar8 = FUN_004034d0(1,100);
      if ((int)uVar8 < 5) {
        iVar5 = FUN_004f4f20(pvVar7,1);
      }
      else {
        iVar5 = FUN_004f50d0(0,0,0,unaff_EDI,unaff_SI);
      }
      if (iVar5 != 0) goto LAB_00407499;
      FUN_0050bc40(this_00);
      FUN_0050e890(this_00,6);
      break;
    case 0x16:
    case 0x17:
      iVar5 = FUN_00480130(param_1,iVar5);
      if (iVar5 != 0) {
        *(undefined4 *)((int)this_00 + 0x84) = 0xffffffff;
        *(undefined4 *)((int)this_00 + 0x8c) = 0xffffffff;
        goto LAB_004072d7;
      }
LAB_004072a7:
      iVar5 = FUN_00509ff0((int)this_00);
      FUN_00507d90(this_00,iVar5);
      FUN_0050e890(this_00,0x36);
      FUN_0050e230((int)this_00);
      break;
    case 0x1b:
      iVar5 = FUN_00480130(param_1,iVar5);
      if ((iVar5 == 0) && (iVar5 = FUN_004781e0((int)pvVar4), iVar5 == 0)) goto LAB_004072a7;
LAB_00407280:
      *(undefined4 *)((int)this_00 + 0x84) = 0xffffffff;
      *(undefined4 *)((int)this_00 + 0x8c) = 0xffffffff;
      FUN_0050e600(this_00,pvVar4);
      break;
    case 0x1c:
      iVar5 = FUN_0050adf0(this_00);
      if (iVar5 != 0) {
        return iVar5;
      }
      iVar5 = IDMap_Lookup((void *)((int)this + 0x3c),*(int *)((int)this_00 + 0xac),(int *)0x0);
      if ((((iVar5 == 0) || (*(int *)(iVar5 + 0x74) == 0)) ||
          (*(int *)(iVar5 + 0xf4) != *(int *)((int)param_1 + 0x16f0))) ||
         (iVar5 = FUN_0050bf50(this_00,param_1,*(int *)((int)this_00 + 0xac),&param_2), iVar5 == 0))
      {
LAB_00407201:
        FUN_0050bc40(this_00);
        goto switchD_00407151_caseD_36;
      }
      FUN_00507d90(this_00,iVar5);
      _DAT_0057c610 = FUN_0050e6b0(this_00,iVar5);
      if (_DAT_0057c610 != 0) {
        *(int *)((int)this_00 + 0x88) = local_24[(int)param_2 + 1];
      }
      break;
    case -1:
      if (*(int *)((int)this_00 + 0x30) != 0x17) goto switchD_00407151_caseD_9;
      FUN_0050e850(this_00,0x12);
    }
    break;
  case 6:
    iVar5 = FUN_004f3ad0((int)pvVar7);
    if (iVar5 != 0) {
      FUN_00507d90(this_00,iVar5);
      FUN_0050e890(this_00,7);
    }
    break;
  case 7:
    iVar5 = *(int *)((int)this_00 + 0x164);
    iVar11 = *(int *)((int)this_00 + 0x110);
    iVar9 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
    if (iVar11 == iVar9) {
      FUN_00502f10(*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8),8,iVar5,-1);
    }
    FUN_005087c0(this_00);
    FUN_0050e850(this_00,0xffffffff);
    break;
  case 8:
    switch(*(undefined4 *)((int)this_00 + 0xa4)) {
    default:
      goto switchD_00407151_caseD_9;
    case 0xe:
      iVar5 = FUN_0050b9c0(this_00,param_1);
      if (iVar5 == 0) {
        iVar5 = Object_GetChildField2C((int)this_00);
        FUN_00509060(this_00,iVar5 + 0x18);
        FUN_0050e890(this_00,10);
        Object_SetFrame5(this_00,10);
      }
      else {
        FUN_0050e890(this_00,6);
      }
      break;
    case 0xf:
      iVar5 = FUN_0047e180(param_1,*(int *)((int)this_00 + 0x8c));
      if ((iVar5 == 0) || (*(int *)(iVar5 + 0xc) < 1)) {
LAB_0040716c:
        FUN_0050e890(this_00,5);
      }
      else {
        FUN_00509060(this_00,*(int *)((int)this_00 + 0x88));
        FUN_0050e890(this_00,0x27);
      }
      break;
    case 0x10:
      iVar5 = FUN_00480060((int)param_1);
      if (iVar5 != 0) goto LAB_0040716c;
      uVar8 = FUN_004034d0(0x30,0x37);
      iVar5 = Object_GetChildField2C((int)this_00);
      FUN_0050e890(this_00,0x26);
      FUN_00509060(this_00,uVar8 + iVar5);
      break;
    case 0x19:
    case 0x1a:
      iVar5 = Object_GetChildField2C((int)this_00);
      FUN_00509060(this_00,iVar5 + 0x18);
      iVar5 = 0x3e;
      goto LAB_00407681;
    case 0x1b:
      iVar5 = FUN_00480130(param_1,0x1b);
      if ((iVar5 == 0) && (*(int *)((int)this_00 + 0x8c) != -1)) {
        FUN_0047eb30(pvVar4,*(int *)((int)this_00 + 0x8c));
      }
    case 0x16:
    case 0x17:
      iVar5 = Object_GetChildField2C((int)this_00);
LAB_00407678:
      FUN_00509060(this_00,iVar5 + 0x18);
      iVar5 = 0x29;
LAB_00407681:
      FUN_0050e890(this_00,iVar5);
      Object_SetFrame5(this_00,1);
      break;
    case 0x1c:
      iVar5 = FUN_0050adf0(this_00);
      if (iVar5 != 0) {
        return iVar5;
      }
      fVar6 = (float)IDMap_Lookup((void *)((int)this + 0x3c),*(int *)((int)this_00 + 0xac),
                                  (int *)0x0);
      if (((fVar6 == 0.0) || (*(int *)((int)fVar6 + 0x74) == 0)) ||
         (*(int *)((int)param_1 + 0x16f0) != *(int *)((int)fVar6 + 0xf4))) goto LAB_0040775c;
      pvVar7 = (void *)IDMap_Lookup((void *)((int)this + 0x20),*(int *)((int)fVar6 + 0x50),
                                    (int *)0x0);
      iVar5 = *(int *)((int)pvVar7 + 0x10) / 2;
      if (iVar5 < 1) {
        iVar5 = 1;
      }
      FUN_004d4150(pvVar7,iVar5);
      fVar6 = FUN_0050d310(this_00,fVar6);
      FUN_00509060(this_00,(int)fVar6);
      FUN_0050e890(this_00,0x3f);
      break;
    case 0xffffffff:
    case 0x12:
      iVar5 = *(int *)((int)this_00 + 0x88);
      goto LAB_00407678;
    }
    break;
  case 0x26:
    FUN_00480200(param_1,0x1e);
LAB_004077e2:
    FUN_0050e890(this_00,6);
    FUN_0050bc40(this_00);
    break;
  case 0x27:
    iVar5 = FUN_0050adf0(this_00);
    pvVar7 = param_1;
    if (iVar5 != 0) {
      return iVar5;
    }
    FUN_00480200(param_1,0x1e);
    iVar5 = FUN_0050bf30((int)this_00);
    pvVar4 = (void *)FUN_0047e180(pvVar7,*(int *)((int)this_00 + 0x8c));
    if (pvVar4 != (void *)0x0) {
      iVar11 = *(int *)((int)pvVar4 + 0xc);
      if (iVar5 < iVar11) {
        FUN_004e6300(pvVar4,CONCAT31((int3)((uint)iVar11 >> 8),(char)iVar11 - (char)iVar5));
        FUN_00509060(this_00,*(int *)((int)this_00 + 0x88));
        iVar5 = FUN_00548210(DAT_0057ba0c,(int)pvVar7,0x24);
        return iVar5;
      }
      FUN_004e6300(pvVar4,0);
      FUN_00480d80(pvVar7,(int)pvVar4);
      FUN_004e6170(pvVar4,pvVar7);
      cVar3 = FUN_004e5df0((int)pvVar4);
      if (cVar3 == '\x01') {
        iVar5 = 0x1d;
      }
      else {
        iVar5 = 0x1e;
      }
      FUN_00548210(DAT_0057ba0c,(int)pvVar7,iVar5);
    }
    FUN_0050e890(this_00,5);
    break;
  case 0x28:
    iVar5 = *(int *)((int)this_00 + 0x30);
    if (iVar5 == 0xd) {
      iVar5 = FUN_0050cdc0(this_00,param_1);
    }
    else {
      if ((iVar5 != 0x17) && (iVar5 != 0x1d)) break;
      iVar5 = FUN_0050c9a0(this_00,param_1);
    }
    if (iVar5 == -1) {
      FUN_0050e890(this_00,0x2f);
    }
    break;
  case 0x2a:
    if (*(int *)((int)this_00 + 0x30) == 0x1e) {
      FUN_00509060(this_00,*(int *)((int)this_00 + 0x88) + 0x20);
      Object_SetFrame5(this_00,1);
      FUN_0050e890(this_00,0x2b);
    }
    break;
  case 0x2c:
    iVar5 = FUN_0050adf0(this_00);
    if (iVar5 != 0) {
      return iVar5;
    }
    FUN_0050df30(this_00,(int)param_1);
    break;
  case 0x2f:
    if (*(int *)((int)this_00 + 0x30) != 0xd) goto LAB_0040716c;
    FUN_0050e890(this_00,0x37);
    break;
  case 0x36:
switchD_00407151_caseD_36:
    FUN_0050e890(this_00,6);
    break;
  case 0x37:
    iVar5 = *(int *)((int)this_00 + 0xa4);
    if (0x15 < iVar5) {
      if (iVar5 < 0x18) {
        iVar5 = FUN_00480130(param_1,iVar5);
        if (iVar5 == 0) {
LAB_004071ca:
          FUN_0050e890(this_00,6);
          iVar5 = FUN_0050e230((int)this_00);
          return iVar5;
        }
        *(undefined4 *)((int)this_00 + 0x84) = 0xffffffff;
        *(undefined4 *)((int)this_00 + 0x8c) = 0xffffffff;
        iVar5 = FUN_004f50d0(0,0,0,unaff_EDI,unaff_SI);
        if (iVar5 == 0) goto LAB_00407201;
        goto LAB_00407216;
      }
      if (iVar5 == 0x1b) {
        iVar5 = FUN_00480130(param_1,0x1b);
        if ((iVar5 == 0) && (iVar5 = FUN_004781e0((int)pvVar4), iVar5 == 0)) goto LAB_004071ca;
        goto LAB_00407280;
      }
    }
  default:
switchD_00407151_caseD_9:
    FUN_0050e7d0(this_00);
    break;
  case 0x38:
    FUN_00509060(this_00,*(int *)((int)this_00 + 0x88) + 0x20);
    break;
  case 0x3f:
    iVar5 = FUN_0050adf0(this_00);
    if (iVar5 != 0) {
      return iVar5;
    }
LAB_0040775c:
    FUN_0050bc40(this_00);
    *(undefined1 *)((int)this_00 + 0x81) = 1;
  }
LAB_004078a4:
  if (local_24[0] == 0) {
    return 0;
  }
  iVar5 = *(int *)((int)this_00 + 0x38) + -8;
  switch(*(int *)((int)this_00 + 0x38)) {
  case 8:
    iVar5 = FUN_0050adf0(this_00);
    if (iVar5 == 0) {
      iVar5 = *(int *)((int)this_00 + 0x30) + -0xd;
      switch(*(int *)((int)this_00 + 0x30)) {
      case 0xd:
        if (*(int *)((int)this_00 + 200) == 0) {
          uVar10 = 0xffffffff;
        }
        else {
          uVar10 = *(undefined4 *)(*(int *)((int)this_00 + 200) + 0xc);
        }
        *(undefined4 *)((int)this_00 + 0x88) = uVar10;
LAB_00407b87:
        iVar5 = FUN_0050cdc0(this_00,param_1);
        return iVar5;
      case 0x17:
        if (*(int *)((int)this_00 + 200) == 0) {
          uVar10 = 0xffffffff;
        }
        else {
          uVar10 = *(undefined4 *)(*(int *)((int)this_00 + 200) + 0xc);
        }
        *(undefined4 *)((int)this_00 + 0x88) = uVar10;
        iVar5 = FUN_0050c9a0(this_00,param_1);
        return iVar5;
      case 0x1d:
        iVar11 = *(int *)((int)this_00 + 0xa4);
        if (iVar11 == 0xe) {
          if (*(int *)((int)this_00 + 200) == 0) {
            uVar10 = 0xffffffff;
          }
          else {
            uVar10 = *(undefined4 *)(*(int *)((int)this_00 + 200) + 0xc);
          }
          *(undefined4 *)((int)this_00 + 0x88) = uVar10;
          iVar11 = FUN_0050b9c0(this_00,param_1);
          iVar5 = 0;
          if (iVar11 != 0) {
            FUN_00507a80((int)this_00);
            iVar5 = FUN_0050e890(this_00,6);
            return iVar5;
          }
        }
        else {
          if (iVar11 == 0x19) {
            if (*(int *)((int)this_00 + 200) == 0) {
              uVar10 = 0xffffffff;
            }
            else {
              uVar10 = *(undefined4 *)(*(int *)((int)this_00 + 200) + 0xc);
            }
            *(undefined4 *)((int)this_00 + 0x88) = uVar10;
            iVar5 = FUN_0050c9a0(this_00,param_1);
            return iVar5;
          }
          iVar5 = 0;
          if (iVar11 != 0x1a) {
            iVar5 = FUN_0050c8a0(this_00,param_1);
            return iVar5;
          }
        }
        break;
      case 0x1e:
        if (*(int *)((int)this_00 + 0xa4) == 0x1c) {
          iVar5 = IDMap_Lookup((void *)((int)this + 0x3c),*(int *)((int)this_00 + 0xac),(int *)0x0);
          pvVar7 = param_1;
          if (((iVar5 != 0) && (*(int *)(iVar5 + 0x74) != 0)) &&
             (*(int *)(iVar5 + 0xf4) == *(int *)((int)param_1 + 0x16f0))) {
            iVar5 = FUN_0050d220(this_00,param_1,*(int *)((int)this_00 + 0xac));
            if (iVar5 != 0) {
              iVar5 = FUN_00507a80((int)this_00);
              return iVar5;
            }
            iVar5 = FUN_0050bf50(this_00,pvVar7,*(int *)((int)this_00 + 0xac),&param_2);
            if (iVar5 != 0) {
              *(int *)((int)this_00 + 0x88) = local_24[(int)param_2 + 1];
              iVar5 = FUN_00507d90(this_00,iVar5);
              return iVar5;
            }
          }
          FUN_0050bc40(this_00);
          iVar5 = FUN_0050e890(this_00,6);
          return iVar5;
        }
      }
    }
    break;
  case 10:
    iVar5 = FUN_0050adf0(this_00);
    pvVar7 = param_1;
    if (iVar5 != 0) {
      return iVar5;
    }
    bVar12 = FUN_0050b930(this_00,(int)param_1);
    if (CONCAT31(extraout_var_00,bVar12) != 0) {
      iVar5 = FUN_0050bc40(this_00);
      *(undefined1 *)((int)this_00 + 0x81) = 1;
      return iVar5;
    }
    iVar5 = FUN_0050b9c0(this_00,pvVar7);
    if (iVar5 != 0) {
      FUN_005090e0((int)this_00);
      iVar5 = FUN_0050e890(this_00,6);
      return iVar5;
    }
    goto LAB_00407c1b;
  case 0x28:
    iVar5 = FUN_0050adf0(this_00);
    if (iVar5 == 0) {
      iVar5 = *(int *)((int)this_00 + 0x30);
      if (iVar5 == 0xd) goto LAB_00407b87;
      if ((iVar5 == 0x17) || (iVar5 == 0x1d)) {
        iVar5 = FUN_0050c9a0(this_00,param_1);
        return iVar5;
      }
    }
    break;
  case 0x29:
    iVar5 = FUN_0050adf0(this_00);
    if (iVar5 != 0) {
      return iVar5;
    }
    iVar5 = *(int *)((int)this_00 + 0x30);
    if (iVar5 == 0xd) {
      iVar5 = FUN_0050cdc0(this_00,param_1);
      if (iVar5 == -1) {
        iVar5 = *(int *)((int)this_00 + 0x94) + -1;
        *(int *)((int)this_00 + 0x94) = iVar5;
        if (iVar5 == 0) {
          Object_SetFrame5(this_00,-1);
          FUN_005090e0((int)this_00);
          iVar5 = FUN_0050e890(this_00,0x37);
          return iVar5;
        }
        return iVar5;
      }
    }
    else {
      if (iVar5 != 0x17) {
        return iVar5;
      }
LAB_00407c7c:
      iVar5 = FUN_0050c9a0(this_00,param_1);
      if (iVar5 == -1) {
        iVar5 = *(int *)((int)this_00 + 0x94) + -1;
        *(int *)((int)this_00 + 0x94) = iVar5;
        if (iVar5 == 0) {
          Object_SetFrame5(this_00,-1);
          FUN_005090e0((int)this_00);
          iVar5 = FUN_0050e890(this_00,5);
          return iVar5;
        }
        return iVar5;
      }
    }
    iVar5 = Object_SetFrame5(this_00,-1);
    break;
  case 0x2b:
    iVar5 = FUN_0050adf0(this_00);
    if (iVar5 == 0) {
      iVar5 = *(int *)((int)this_00 + 0x94) + -1;
      *(int *)((int)this_00 + 0x94) = iVar5;
      if (iVar5 == 0) {
        FUN_005090e0((int)this_00);
        Object_SetFrame5(this_00,-1);
        *(undefined1 *)((int)this_00 + 0x81) = 1;
        iVar5 = FUN_0050adf0(this_00);
        return iVar5;
      }
    }
    break;
  case 0x2c:
    iVar5 = FUN_0050adf0(this_00);
    if (iVar5 == 0) {
      iVar5 = FUN_0050df30(this_00,(int)param_1);
      return iVar5;
    }
    break;
  case 0x2f:
    FUN_00507a80((int)this_00);
    if (*(int *)((int)this_00 + 0x30) == 0xd) {
      iVar5 = FUN_0050e890(this_00,0x37);
      return iVar5;
    }
    goto LAB_00407c3d;
  case 0x39:
    FUN_005090e0((int)this_00);
    Object_SetChildField2C(this_00,0x28);
    iVar5 = FUN_0050e890(this_00,6);
    return iVar5;
  case 0x3e:
    iVar5 = FUN_0050adf0(this_00);
    if (iVar5 != 0) {
      return iVar5;
    }
    if (*(int *)((int)this_00 + 0xa4) == 0x19) goto LAB_00407c7c;
    iVar5 = *(int *)((int)this_00 + 0xa4) + -0x1a;
    if (iVar5 != 0) {
      return iVar5;
    }
LAB_00407c1b:
    iVar5 = *(int *)((int)this_00 + 0x94) + -1;
    *(int *)((int)this_00 + 0x94) = iVar5;
    if (iVar5 == 0) {
      Object_SetFrame5(this_00,-1);
      FUN_005090e0((int)this_00);
LAB_00407c3d:
      iVar5 = FUN_0050e890(this_00,5);
      return iVar5;
    }
  }
  return iVar5;
}

