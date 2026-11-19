// rea decompile_all
// name: FUN_00409d80
// address: 0x409d80
// body: available
// range: 0x409d80-0x40a2fb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00409d80(void *this,void *param_1,void *param_2)

{
  void *this_00;
  void *pvVar1;
  undefined1 uVar2;
  int iVar3;
  undefined3 extraout_var;
  int *piVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  uint extraout_EDX;
  float10 fVar8;
  
  pvVar1 = param_1;
  *(short *)((int)param_1 + 0x16e8) = *(short *)((int)param_1 + 0x16e8) + 1;
  iVar3 = IDMap_Lookup((void *)((int)this + 0x20),*(int *)((int)param_2 + 0x50),(int *)0x0);
  uVar2 = FUN_00505e00((int)param_2);
  pvVar7 = *(void **)((int)param_2 + 0xc4);
  if (CONCAT31(extraout_var,uVar2) != 0) {
    switch(*(undefined4 *)((int)param_2 + 0x38)) {
    case 8:
      FUN_0050adf0(param_2);
      return;
    default:
      return;
    case 10:
      iVar3 = FUN_0050adf0(param_2);
      if (iVar3 != 0) {
        return;
      }
      pvVar7 = *(void **)((int)param_1 + 0x1758);
      if (0 < (int)pvVar7) {
        if ((int)*(void **)((int)param_2 + 0x98) < (int)pvVar7) {
          pvVar7 = *(void **)((int)param_2 + 0x98);
        }
        if (0 < (int)pvVar7) {
          this_00 = (void *)((int)param_1 + 0x1744);
          param_1 = pvVar7;
          do {
            iVar3 = IDMap_Lookup(this_00,0,(int *)0x0);
            iVar3 = IDMap_Lookup((void *)((int)this + 0x3c),iVar3,(int *)0x0);
            if (iVar3 != 0) {
              FUN_00509290(param_2,iVar3);
            }
            FUN_004016b0(this_00,0);
            param_1 = (void *)((int)param_1 + -1);
          } while (param_1 != (void *)0x0);
        }
      }
      iVar3 = FUN_00409c60(this,(int)pvVar1,param_2);
      if (iVar3 != 0) {
        return;
      }
      iVar3 = FUN_00409b10(pvVar1,param_2);
      if (iVar3 == 0) {
        *(short *)((int)pvVar1 + 0x16e0) = *(short *)((int)pvVar1 + 0x16e0) + 1;
        return;
      }
      return;
    case 0xc:
      if (*(int *)((int)param_2 + 0x94) != -1) {
        iVar3 = *(int *)((int)param_2 + 0x94) + -1;
        *(int *)((int)param_2 + 0x94) = iVar3;
        if (iVar3 == 0) {
          pvVar7 = (void *)IDMap_Lookup((void *)((int)this + 0x3c),*(int *)((int)param_2 + 0x10c),
                                        (int *)0x0);
          FUN_00507550(pvVar7,5);
          FUN_00504a90(pvVar7,4);
          FUN_0050d200(param_2,-1);
          FUN_00509290(param_2,(int)pvVar7);
          FUN_00409bb0(param_1,param_2);
          return;
        }
        return;
      }
      iVar3 = IDMap_Lookup((void *)((int)this + 0x3c),*(int *)((int)param_2 + 0x10c),(int *)0x0);
      if (*(int *)(iVar3 + 0x38) == 0xb) {
        return;
      }
      break;
    case 0xf:
      iVar3 = IDMap_Lookup((void *)((int)this + 0x3c),*(int *)((int)param_2 + 0x10c),(int *)0x0);
      if (*(int *)(iVar3 + 0x38) == 0xb) {
        return;
      }
      FUN_00409d40(this,param_1,param_2);
      return;
    case 0x10:
      iVar3 = *(int *)((int)param_2 + 0x94) + -1;
      *(int *)((int)param_2 + 0x94) = iVar3;
      if (iVar3 != 0) {
        return;
      }
      IDMap_Lookup((void *)((int)this + 0x3c),*(int *)((int)param_2 + 0x10c),(int *)0x0);
      iVar3 = FUN_0047ebc0(param_1,*(int *)((int)param_2 + 0x10c));
      if (iVar3 != 0) {
        FUN_00477c80(param_1,*(int *)(iVar3 + 0x2c),*(float *)(iVar3 + 0x1c),-1);
      }
      pvVar7 = (void *)IDMap_Lookup((void *)((int)this + 0x3c),*(int *)((int)param_2 + 0x10c),
                                    (int *)0x0);
      FUN_00507550(pvVar7,0xffff);
      FUN_0050e890(pvVar7,0x11);
      FUN_00509060(pvVar7,*(int *)((int)pvVar7 + 0x84) + 0x14);
      FUN_00507550(pvVar7,9);
      FUN_00504a90(pvVar7,6);
      iVar3 = *(int *)((int)param_1 + 0x30);
      iVar5 = FUN_00482820(DAT_0057c670);
      if (iVar3 == iVar5) {
        if (*(int *)((int)pvVar7 + 0x30) == 0xf) {
          FUN_00502f10(*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8),7,-1,-1);
          FUN_00502f10(*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8),0x12,-1,-1);
        }
        FUN_00503250(*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8),0x15,1);
        FUN_00502f10(*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8),0x15,-1,-1);
      }
      FUN_0050d200(param_2,-1);
      FUN_00507550(param_2,0xffff);
      FUN_00409d40(this,param_1,param_2);
      return;
    case 0x25:
      FUN_00507a80((int)param_2);
      return;
    }
    goto LAB_0040a11f;
  }
  switch(*(undefined4 *)((int)param_2 + 0x38)) {
  case 5:
    piVar4 = FUN_004f3ce0(pvVar7,param_1);
    iVar5 = FUN_004f0cc0(pvVar7,1,(int)*(short *)(*(int *)(*(int *)((int)pvVar7 + 0x4c) + 8 +
                                                          *piVar4 * 0xc) + 0x24));
    if (iVar5 == 0) {
      FUN_0050e890(param_2,6);
      return;
    }
    iVar6 = FUN_004d3fc0(iVar3);
    fVar8 = FUN_0047ac10((int)param_1);
    FUN_00509130(param_2,(double)(fVar8 * (float10)iVar6));
    iVar3 = FUN_004d4000(iVar3);
    *(int *)((int)param_2 + 0x98) = (iVar3 >> 4) + 1;
    _DAT_0057c610 = FUN_0050e6b0(param_2,iVar5);
    if (_DAT_0057c610 != 0) {
      *(int *)((int)param_2 + 0x88) = *piVar4;
      FUN_0050e890(param_2,8);
      return;
    }
    break;
  case 6:
    iVar3 = FUN_004f3ad0((int)pvVar7);
    if (iVar3 != 0) {
      FUN_00507d90(param_2,iVar3);
      FUN_0050e890(param_2,7);
      return;
    }
    break;
  case 7:
    FUN_00401440((int)param_2 + 0x114);
    FUN_005087c0(param_2);
    FUN_0050e2a0((int)param_2,extraout_EDX,(int)param_1,'\x01');
    return;
  case 8:
    FUN_00509060(param_2,0x32);
    FUN_0050e890(param_2,10);
    FUN_0050ad80(param_2,param_1);
    return;
  default:
    FUN_0050e7d0(param_2);
    return;
  case 0xc:
    pvVar7 = (void *)IDMap_Lookup((void *)((int)this + 0x3c),*(int *)((int)param_2 + 0x10c),
                                  (int *)0x0);
    if (*(int *)((int)pvVar7 + 0x38) == 0xb) {
      iVar3 = FUN_00508fb0(*(undefined4 *)((int)pvVar7 + 0x84));
      FUN_00509060(param_2,iVar3 + 0x18);
      FUN_00507550(pvVar7,0xffff);
      FUN_0050d200(param_2,5);
      return;
    }
    goto LAB_0040a11f;
  case 0xf:
    pvVar7 = (void *)IDMap_Lookup((void *)((int)this + 0x3c),*(int *)((int)param_2 + 0x10c),
                                  (int *)0x0);
    if (*(int *)((int)pvVar7 + 0x38) == 0xb) {
      FUN_0050e890(param_2,0x10);
      FUN_00507550(pvVar7,7);
      FUN_00507550(param_2,7);
      FUN_0050d200(param_2,2);
      FUN_00548210(DAT_0057ba0c,(int)param_1,0x31);
      if (*(int *)((int)param_2 + 0x128) < 1) {
        iVar3 = FUN_00508fb0(*(undefined4 *)((int)pvVar7 + 0x84));
        FUN_00509060(param_2,iVar3 + 0x28);
        return;
      }
      iVar3 = FUN_00508fb0(*(undefined4 *)((int)pvVar7 + 0x84));
      FUN_00509060(param_2,iVar3 + 0x20);
      return;
    }
LAB_0040a11f:
    FUN_00409bb0(param_1,param_2);
    return;
  case 0x25:
    FUN_0050e890(param_2,6);
    FUN_00507550(param_2,0x1d);
    return;
  }
  return;
}

