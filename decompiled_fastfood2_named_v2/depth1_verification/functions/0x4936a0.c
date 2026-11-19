// rea decompile_all
// name: FUN_004936a0
// address: 0x4936a0
// body: available
// range: 0x4936a0-0x494788 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004936a0(void *param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  void *pvVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_104;
  undefined1 local_100 [256];
  
  switch(param_3) {
  case 1:
    if ((DAT_0056872c == -1) && (param_2 < 8000)) {
      return;
    }
    if (*(int *)((int)DAT_0057c670 + 0x268) != 0) {
      FUN_00482890((int)DAT_0057c670);
    }
    if (param_2 < 0x485) {
      if (param_2 != 0x484) {
        switch(param_2) {
        case 0x44f:
          pvVar5 = (void *)FUN_004017f0((void *)((int)DAT_0057c6d0 + 0x148),DAT_00568728,(int *)0x0)
          ;
          iVar1 = Game_CountObjectsByType(pvVar5,0xffffffff);
          DAT_0056872c = DAT_0056872c + -1;
          if (DAT_0056872c == -1) {
            DAT_0056872c = iVar1 + -1;
          }
          FUN_004b1a50(param_1,(int)DAT_0057c6d0,DAT_00568728,'\0',DAT_0056872c);
          if ((7 < iVar1) && (DAT_0057c6d4 = DAT_0056872c, iVar1 < DAT_0056872c + 7)) {
            DAT_0057c6d4 = iVar1 + -7;
          }
          FUN_0052fd70(param_1,0x451,DAT_0057c6d4 * 100,0);
          FUN_004b1f40(param_1,DAT_0057c6d4,(int)DAT_0057c6d0,DAT_00568728,DAT_0056872c);
          return;
        case 0x450:
          pvVar5 = (void *)FUN_004017f0((void *)((int)DAT_0057c6d0 + 0x148),DAT_00568728,(int *)0x0)
          ;
          iVar1 = Game_CountObjectsByType(pvVar5,0xffffffff);
          DAT_0056872c = DAT_0056872c + 1;
          if (DAT_0056872c == iVar1) {
            DAT_0056872c = 0;
          }
          FUN_004b1a50(param_1,(int)DAT_0057c6d0,DAT_00568728,'\0',DAT_0056872c);
          if ((7 < iVar1) && (DAT_0057c6d4 = DAT_0056872c, iVar1 < DAT_0056872c + 7)) {
            DAT_0057c6d4 = iVar1 + -7;
          }
          FUN_0052fd70(param_1,0x451,DAT_0057c6d4 * 100,0);
          FUN_004b1f40(param_1,DAT_0057c6d4,(int)DAT_0057c6d0,DAT_00568728,DAT_0056872c);
          return;
        default:
          return;
        case 0x47f:
          iVar1 = FUN_004017f0((void *)((int)DAT_0057c6d0 + 0x148),DAT_00568728,(int *)0x0);
          piVar2 = (int *)FUN_004017f0((void *)(iVar1 + 0x1500),DAT_0056872c,(int *)0x0);
          iVar1 = FUN_004d3930(*piVar2);
          FUN_0054dd83(local_100,DAT_00581334,iVar1);
          FUN_00482c40(DAT_0057c670,0xfffe79ba,DAT_00581fe4,local_100,0xffffffff,0,-1,'\0');
          return;
        case 0x480:
          goto switchD_0049378c_caseD_480;
        case 0x483:
          iVar1 = FUN_004017f0((void *)((int)DAT_0057c6d0 + 0x148),DAT_00568728,(int *)0x0);
          piVar2 = (int *)FUN_004017f0((void *)(iVar1 + 0x1500),DAT_0056872c,(int *)0x0);
          iVar1 = FUN_004d3fc0(*piVar2);
          if (99 < iVar1) {
            return;
          }
          iVar6 = FUN_004d4330((void *)*piVar2,3);
          iVar1 = *(int *)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8);
          if (*(int *)(iVar1 + 0xdc) == 0) {
            if (*(int *)(iVar1 + 0x1c0) != 0) {
              iVar6 = (iVar6 * 0xf) / 10;
            }
          }
          else {
            iVar6 = 0;
          }
          FUN_0054dd83(local_100,DAT_005829a4,iVar6);
          FUN_00482c40(DAT_0057c670,0xfffe796b,DAT_00581fe4,local_100,0xffffffff,0,-1,'\0');
          return;
        }
      }
      iVar1 = FUN_004017f0((void *)((int)DAT_0057c6d0 + 0x148),DAT_00568728,(int *)0x0);
      piVar2 = (int *)FUN_004017f0((void *)(iVar1 + 0x1500),DAT_0056872c,(int *)0x0);
      pvVar5 = (void *)*piVar2;
      if (99 < *(int *)((int)pvVar5 + 0xc)) {
        return;
      }
      switch(*(undefined1 *)((int)pvVar5 + 0x824)) {
      case 0:
        local_104 = 6;
        break;
      case 1:
        local_104 = 8;
        break;
      case 2:
        local_104 = 7;
        break;
      case 3:
        local_104 = 0xd;
        break;
      default:
      }
      iVar1 = FUN_004d4330(pvVar5,1);
      uVar3 = FUN_004e0b60(DAT_0057c6d0,local_104,(float)iVar1,'\x01',0xffffffff);
      if ((char)uVar3 != '\0') {
        FUN_004d43a0((void *)*piVar2,1);
        FUN_0054dd83(local_100,&DAT_005686f4,*(undefined4 *)(*piVar2 + 0x3c));
        FUN_0052f9b0(param_1,0x529,local_100);
        FUN_004b1a50(param_1,(int)DAT_0057c6d0,DAT_00568728,'\0',DAT_0056872c);
        return;
      }
      uVar3 = DAT_005828c0;
    }
    else {
      if (param_2 < 0x1f41) {
        if (param_2 == 8000) {
          FUN_00482d70(-0x51);
          return;
        }
        if (param_2 == 0x485) {
          iVar1 = FUN_004017f0((void *)((int)DAT_0057c6d0 + 0x148),DAT_00568728,(int *)0x0);
          piVar2 = (int *)FUN_004017f0((void *)(iVar1 + 0x1500),DAT_0056872c,(int *)0x0);
          iVar1 = FUN_004d3fe0(*piVar2);
          if (99 < iVar1) {
            return;
          }
          iVar6 = FUN_004d4330((void *)*piVar2,2);
          iVar1 = *(int *)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8);
          if (*(int *)(iVar1 + 0xe0) == 0) {
            if (*(int *)(iVar1 + 0x1c4) != 0) {
              iVar6 = (iVar6 * 0xf) / 10;
            }
          }
          else {
            iVar6 = 0;
          }
          FUN_0054dd83(local_100,DAT_00582dd8,iVar6);
          FUN_00482c40(DAT_0057c670,0xfffe796c,DAT_00581fe4,local_100,0xffffffff,0,-1,'\0');
          return;
        }
        if (param_2 != 5000) {
          return;
        }
        iVar1 = FUN_004017f0((void *)((int)DAT_0057c6d0 + 0x148),DAT_00568728,(int *)0x0);
        puVar4 = (undefined4 *)FUN_004017f0((void *)(iVar1 + 0x1500),DAT_0056872c,(int *)0x0);
        if (param_4 == 0) {
          FUN_004d4070((void *)*puVar4,2);
          return;
        }
        FUN_004d4070((void *)*puVar4,1);
        return;
      }
      if (param_2 != 0x2333) {
        return;
      }
      pvVar5 = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),
                                    *(int *)((int)DAT_0057c670 + 0x2f4),(int *)0x0);
      iVar1 = Game_CountObjectsByType2(pvVar5,0xffffffff);
      if (0 < iVar1) {
        FUN_00482880((int)DAT_0057c670);
        pvVar5 = DAT_0057c670;
        *(undefined4 *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x290) * 4 + 0x2b8) =
             *(undefined4 *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x290) * 4 + 0x298);
        *(undefined4 *)((int)pvVar5 + *(int *)((int)pvVar5 + 0x290) * 4 + 0x298) = 0xb;
        pvVar5 = FUN_00484270(DAT_0057c670);
        FUN_00523d60(DAT_0057c5e0,(int)pvVar5);
        return;
      }
      uVar3 = DAT_00580bf4;
    }
    goto LAB_004940a5;
  case 0x18:
    if (*(int *)((int)DAT_0057c670 + 0x268) != 0) {
      FUN_00482890((int)DAT_0057c670);
    }
    if (param_2 == 0x451) {
      DAT_0057c6d4 = param_4 / 100;
      return;
    }
    if ((5999 < param_2) && (param_2 < 0x178c)) {
      pvVar5 = (void *)FUN_004017f0((void *)((int)DAT_0057c6d0 + 0x148),DAT_00568728,(int *)0x0);
      iVar1 = FUN_004017f0((void *)((int)pvVar5 + 0x1500),(param_2 + -6000 >> 2) + DAT_0057c6d4,
                           (int *)0x0);
      iVar6 = FUN_0052fd90(param_1,param_2,0);
      *(uint *)(iVar1 + 4) = iVar6 - 1U & 7;
      FUN_004805d0(pvVar5);
      return;
    }
    break;
  case 0x19:
    if (*(int *)((int)DAT_0057c670 + 0x268) != 0) {
      FUN_00482890((int)DAT_0057c670);
    }
    if (param_2 < 0x177e) {
      if (param_2 == 0x177d) goto switchD_004946c9_caseD_1779;
      if (0x1776 < param_2) {
        switch(param_2) {
        case 0x1777:
        case 0x177b:
          goto switchD_004946c9_caseD_1777;
        case 0x1778:
        case 0x177c:
          goto switchD_004946c9_caseD_1778;
        case 0x1779:
          goto switchD_004946c9_caseD_1779;
        case 0x177a:
          goto switchD_004946c9_caseD_177a;
        default:
          goto switchD_004936c0_caseD_2;
        }
      }
      if (param_2 != 0x1776) {
        if (param_2 < 0x1773) {
          if (param_2 == 0x1772) goto switchD_004946c9_caseD_177a;
          if (param_2 == 0x451) {
            FUN_004b1f40(param_1,param_4 / 100,(int)DAT_0057c6d0,DAT_00568728,DAT_0056872c);
            return;
          }
          if (param_2 != 6000) {
            if (param_2 != 0x1771) {
              return;
            }
            goto switchD_004946c9_caseD_1779;
          }
        }
        else {
          if (param_2 == 0x1773) goto switchD_004946c9_caseD_1777;
          if (param_2 != 0x1774) {
            if (param_2 != 0x1775) {
              return;
            }
            goto switchD_004946c9_caseD_1779;
          }
        }
switchD_004946c9_caseD_1778:
        iVar1 = param_2 + -6000;
        goto LAB_00494704;
      }
switchD_004946c9_caseD_177a:
      iVar1 = param_2 + -0x1772;
    }
    else {
      switch(param_2) {
      case 0x177e:
      case 0x1782:
      case 0x1786:
      case 0x178a:
        goto switchD_004946c9_caseD_177a;
      case 0x177f:
      case 0x1783:
      case 0x1787:
      case 0x178b:
switchD_004946c9_caseD_1777:
        iVar1 = param_2 + -0x1773;
        break;
      case 0x1780:
      case 0x1784:
      case 0x1788:
        goto switchD_004946c9_caseD_1778;
      case 0x1781:
      case 0x1785:
      case 0x1789:
switchD_004946c9_caseD_1779:
        iVar1 = param_2 + -0x1771;
        break;
      default:
        goto switchD_004936c0_caseD_2;
      }
    }
LAB_00494704:
    iVar9 = (int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2;
    iVar6 = iVar9 * 10 + 0xe1;
    iVar7 = FUN_0052fd90(param_1,param_2,0);
    iVar1 = iVar7 * 0x14;
    if (iVar7 < 1) {
      iVar8 = iVar1 + 0xbd;
    }
    else {
      iVar8 = iVar1 + 0x1d;
    }
    FUN_00531400(param_1,iVar9 + 50000,iVar8,iVar6);
    if (iVar7 < 7) {
      iVar1 = iVar1 + 0x45;
    }
    else {
      iVar1 = iVar1 + -0x5b;
    }
    FUN_00531400(param_1,iVar9 + 51000,iVar1,iVar6);
    break;
  case 0x1a:
    if (*(int *)((int)DAT_0057c670 + 0x268) != 0) {
      FUN_00482890((int)DAT_0057c670);
    }
    iVar1 = param_2 + -6000;
    switch(iVar1) {
    case 0:
    case 4:
    case 8:
    case 0xc:
    case 0x10:
    case 0x14:
    case 0x18:
      iVar6 = (int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2;
      iVar1 = 0;
      do {
        FUN_00531740(param_1,iVar1 + 0x1794);
        iVar1 = iVar1 + 1;
      } while (iVar1 < 7);
      FUN_005316b0(param_1,iVar6 + 0x1794);
      DAT_0056872c = iVar6 + DAT_0057c6d4;
      break;
    case 1:
    case 5:
    case 9:
    case 0xd:
    case 0x11:
    case 0x15:
    case 0x19:
      iVar6 = (int)(param_2 + -0x1771 + (param_2 + -0x1771 >> 0x1f & 3U)) >> 2;
      iVar1 = 0;
      do {
        FUN_00531740(param_1,iVar1 + 0x1794);
        iVar1 = iVar1 + 1;
      } while (iVar1 < 7);
      FUN_005316b0(param_1,iVar6 + 0x1794);
      DAT_0056872c = iVar6 + DAT_0057c6d4;
      break;
    case 2:
    case 6:
    case 10:
    case 0xe:
    case 0x12:
    case 0x16:
    case 0x1a:
      iVar1 = param_2 + -0x1772 + (param_2 + -0x1772 >> 0x1f & 3U);
      iVar6 = 0;
      do {
        FUN_00531740(param_1,iVar6 + 0x1794);
        iVar6 = iVar6 + 1;
      } while (iVar6 < 7);
      goto LAB_0049455e;
    case 3:
    case 7:
    case 0xb:
    case 0xf:
    case 0x13:
    case 0x17:
    case 0x1b:
      iVar1 = param_2 + -0x1773 + (param_2 + -0x1773 >> 0x1f & 3U);
      iVar6 = 0;
      do {
        FUN_00531740(param_1,iVar6 + 0x1794);
        iVar6 = iVar6 + 1;
      } while (iVar6 < 7);
LAB_0049455e:
      FUN_005316b0(param_1,(iVar1 >> 2) + 0x1794);
      DAT_0056872c = (iVar1 >> 2) + DAT_0057c6d4;
      break;
    default:
      goto switchD_00494441_default;
    }
    FUN_004b1a50(param_1,(int)DAT_0057c6d0,DAT_00568728,'\0',DAT_0056872c);
switchD_00494441_default:
    if (((5999 < param_2) && (param_2 < 0x178c)) &&
       (piVar2 = (int *)FUN_004017f0((void *)(*(int *)((int)DAT_0057c670 + 0x9c) + 0x1500),
                                     DAT_0056872c,(int *)0x0), piVar2 != (int *)0x0)) {
      Game_GetRecordByField814(*piVar2);
      return;
    }
    break;
  case 0x1b:
    if (param_2 == 0x2332) {
      iVar1 = FUN_004017f0((void *)((int)DAT_0057c6d0 + 0x148),DAT_00568728,(int *)0x0);
      piVar2 = (int *)FUN_004017f0((void *)(iVar1 + 0x1500),DAT_0056872c,(int *)0x0);
      if (piVar2 != (int *)0x0) {
        iVar1 = Game_GetRecordByField814(*piVar2);
        FUN_0048bef0(DAT_0057c670,iVar1);
        return;
      }
    }
    break;
  case 0x23:
    switch(param_2) {
    case -0x18696:
      pvVar5 = (void *)FUN_004017f0((void *)((int)DAT_0057c6d0 + 0x148),DAT_00568728,(int *)0x0);
      puVar4 = (undefined4 *)FUN_004017f0((void *)((int)pvVar5 + 0x1500),DAT_0056872c,(int *)0x0);
      local_104 = FUN_004d4330((void *)*puVar4,0);
      iVar1 = *(int *)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8);
      if (*(int *)(iVar1 + 0xdc) == 0) {
        if (*(int *)(iVar1 + 0x1c0) != 0) {
          local_104 = (local_104 * 0xf) / 10;
        }
      }
      else {
        local_104 = 0;
      }
      uVar3 = FUN_00477e40(pvVar5,0xb,(float)local_104,'\x01',-1);
      if ((char)uVar3 != '\0') {
        FUN_004d43a0((void *)*puVar4,0);
        FUN_004b1a50(param_1,(int)DAT_0057c6d0,DAT_00568728,'\0',DAT_0056872c);
        iVar1 = *(int *)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8);
        iVar6 = *(int *)(iVar1 + 0xdc);
joined_r0x0049408a:
        if (iVar6 != 0) {
          *(int *)(iVar1 + 0xdc) = *(int *)(iVar1 + 0xdc) + -1;
          return;
        }
        if (*(int *)(iVar1 + 0x1c0) == 0) {
          return;
        }
        *(int *)(iVar1 + 0x1c0) = *(int *)(iVar1 + 0x1c0) + -1;
        return;
      }
      break;
    case -0x18695:
      pvVar5 = (void *)FUN_004017f0((void *)((int)DAT_0057c6d0 + 0x148),DAT_00568728,(int *)0x0);
      puVar4 = (undefined4 *)FUN_004017f0((void *)((int)pvVar5 + 0x1500),DAT_0056872c,(int *)0x0);
      local_104 = FUN_004d4330((void *)*puVar4,3);
      iVar1 = *(int *)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8);
      if (*(int *)(iVar1 + 0xdc) == 0) {
        if (*(int *)(iVar1 + 0x1c0) != 0) {
          local_104 = (local_104 * 0xf) / 10;
        }
      }
      else {
        local_104 = 0;
      }
      uVar3 = FUN_00477e40(pvVar5,0xb,(float)local_104,'\x01',-1);
      if ((char)uVar3 != '\0') {
        FUN_004d43a0((void *)*puVar4,3);
        FUN_004b1a50(param_1,(int)DAT_0057c6d0,DAT_00568728,'\0',DAT_0056872c);
        iVar1 = *(int *)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8);
        iVar6 = *(int *)(iVar1 + 0xdc);
        goto joined_r0x0049408a;
      }
      break;
    case -0x18694:
      iVar1 = FUN_004017f0((void *)((int)DAT_0057c6d0 + 0x148),DAT_00568728,(int *)0x0);
      puVar4 = (undefined4 *)FUN_004017f0((void *)(iVar1 + 0x1500),DAT_0056872c,(int *)0x0);
      local_104 = FUN_004d4330((void *)*puVar4,2);
      iVar1 = *(int *)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8);
      if (*(int *)(iVar1 + 0xe0) == 0) {
        if (*(int *)(iVar1 + 0x1c4) != 0) {
          local_104 = (local_104 * 0xf) / 10;
        }
      }
      else {
        local_104 = 0;
      }
      pvVar5 = (void *)FUN_004017f0((void *)((int)DAT_0057c6d0 + 0x148),DAT_00568728,(int *)0x0);
      uVar3 = FUN_00477e40(pvVar5,0xb,(float)local_104,'\x01',-1);
      if ((char)uVar3 != '\0') {
        FUN_004d43a0((void *)*puVar4,2);
        iVar1 = *(int *)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8);
        if (*(int *)(iVar1 + 0xe0) == 0) {
          if (*(int *)(iVar1 + 0x1c4) != 0) {
            *(int *)(iVar1 + 0x1c4) = *(int *)(iVar1 + 0x1c4) + -1;
          }
        }
        else {
          *(int *)(iVar1 + 0xe0) = *(int *)(iVar1 + 0xe0) + -1;
        }
        FUN_004b1a50(param_1,(int)DAT_0057c6d0,DAT_00568728,'\0',DAT_0056872c);
        uVar3 = 500;
        iVar1 = *(int *)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8);
        if (*(int *)(iVar1 + 0xe0) == 0) {
          if (*(int *)(iVar1 + 0x1c4) != 0) {
            uVar3 = 0x2ee;
          }
        }
        else {
          uVar3 = 0;
        }
        FUN_0054dd83(local_100,DAT_00581eb8,uVar3);
        FUN_0052f830(param_1,0x485,local_100);
        return;
      }
      break;
    case -0x18693:
      if (*(int *)((int)DAT_0057c670 + 0x9c) == 0) {
        return;
      }
      FUN_00493110(param_1,*(int *)((int)DAT_0057c670 + 0x2d8) == 0x1d,'\0');
      return;
    default:
      goto switchD_004936c0_caseD_2;
    case -0x1864e:
      if (param_4 == -1) {
        return;
      }
      iVar1 = FUN_004017f0((void *)((int)DAT_0057c6d0 + 0x148),param_4,(int *)0x0);
      if (iVar1 == 0) {
        return;
      }
      DAT_00568728 = *(int *)(iVar1 + 0x3c);
    case -0x1863b:
      FUN_00493110(param_1,*(int *)((int)DAT_0057c670 + 0x2d8) == 0x1d,'\0');
      return;
    case -0x18646:
      pvVar5 = (void *)FUN_004017f0((void *)((int)DAT_0057c6d0 + 0x148),DAT_00568728,(int *)0x0);
      piVar2 = (int *)FUN_004017f0((void *)((int)pvVar5 + 0x1500),DAT_0056872c,(int *)0x0);
      FUN_0047a9d0(pvVar5,piVar2,1);
      FUN_00493110(param_1,*(int *)((int)DAT_0057c670 + 0x2d8) == 0x1d,'\0');
      return;
    }
    uVar3 = DAT_005828c0;
LAB_004940a5:
    FUN_00482b70(DAT_0057c670,0xfffe79af,DAT_005825a4,uVar3,0);
    return;
  }
switchD_004936c0_caseD_2:
  return;
switchD_0049378c_caseD_480:
  iVar1 = FUN_004017f0((void *)((int)DAT_0057c6d0 + 0x148),DAT_00568728,(int *)0x0);
  piVar2 = (int *)FUN_004017f0((void *)(iVar1 + 0x1500),DAT_0056872c,(int *)0x0);
  iVar1 = FUN_004d3f90(*piVar2);
  if (99 < iVar1) {
    return;
  }
  iVar6 = FUN_004d4330((void *)*piVar2,0);
  iVar1 = *(int *)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(iVar1 + 0xdc) == 0) {
    if (*(int *)(iVar1 + 0x1c0) != 0) {
      iVar6 = (iVar6 * 0xf) / 10;
    }
  }
  else {
    iVar6 = 0;
  }
  FUN_0054dd83(local_100,DAT_005829a4,iVar6);
  FUN_00482c40(DAT_0057c670,0xfffe796a,DAT_00581fe4,local_100,0xffffffff,0,-1,'\0');
  return;
}

