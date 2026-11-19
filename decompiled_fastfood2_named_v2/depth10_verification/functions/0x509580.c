// rea decompile_all
// name: FUN_00509580
// address: 0x509580
// body: available
// range: 0x509580-0x509a16 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_00509580(void *this,int param_1)

{
  int *piVar1;
  void *pvVar2;
  void *this_00;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined4 extraout_EDX;
  int *piVar9;
  float10 fVar10;
  undefined8 uVar11;
  int local_330;
  int local_328;
  int *local_324;
  int local_320 [200];
  
  if (param_1 == 0) {
    param_1 = *(int *)((int)this + 0xf4);
  }
  iVar4 = *(int *)(param_1 + 8);
  iVar3 = *(int *)(param_1 + 0x2c);
  pvVar2 = (void *)FUN_00488be0(DAT_0057c670,iVar4);
  this_00 = (void *)FUN_00489820(DAT_0057c670,iVar4,iVar3);
  local_328 = 0;
  iVar3 = FUN_004ddde0((int)pvVar2);
  iVar4 = local_328;
  if (-1 < iVar3) {
    local_324 = local_320 + 1;
    do {
      iVar4 = FUN_004ddde0((int)pvVar2);
      if (local_328 == iVar4) {
        iVar3 = *(int *)((int)this_00 + 0x14dc);
        iVar4 = local_328;
        if (iVar3 == 0) break;
      }
      else {
        iVar3 = FUN_004dde30(pvVar2,local_328);
      }
      piVar5 = operator_new(0x30);
      *piVar5 = iVar3;
      fVar10 = Branch_ComputeRecipePrice(iVar3,(int)this_00,-999);
      piVar5[1] = (int)(float)fVar10;
      local_324[-1] = (int)piVar5;
      iVar4 = FUN_005092b0(this,param_1,piVar5,0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
      *local_324 = iVar4;
      local_328 = local_328 + 1;
      local_324 = local_324 + 2;
      iVar3 = FUN_004ddde0((int)pvVar2);
      iVar4 = local_328;
    } while (local_328 <= iVar3);
  }
  while (iVar4 = iVar4 + -1, 0 < iVar4) {
    piVar5 = local_320;
    local_330 = iVar4;
    do {
      if (piVar5[1] < piVar5[3]) {
        iVar3 = *piVar5;
        iVar7 = piVar5[1];
        *piVar5 = piVar5[2];
        piVar5[1] = piVar5[3];
        piVar5[2] = iVar3;
        piVar5[3] = iVar7;
      }
      piVar5 = piVar5 + 2;
      local_330 = local_330 + -1;
    } while (local_330 != 0);
  }
  uVar6 = 0xffffffff;
  if (local_328 < 4) {
    if (local_328 < 1) goto LAB_00509702;
  }
  else {
    uVar6 = FUN_004034d0(1,100);
    if (0x32 < (int)uVar6) {
      uVar6 = 0;
      goto LAB_00509702;
    }
    if (0x14 < (int)uVar6) {
      uVar6 = 1;
      goto LAB_00509702;
    }
    if (5 < (int)uVar6) {
      uVar6 = 2;
      goto LAB_00509702;
    }
  }
  uVar6 = FUN_004034d0(0,local_328 - 1);
LAB_00509702:
  piVar5 = (int *)0x0;
  local_324 = (int *)0x0;
  if (uVar6 == 0xffffffff) {
    *(short *)((int)this_00 + 0x16da) = *(short *)((int)this_00 + 0x16da) + 1;
  }
  else {
    piVar5 = (int *)local_320[uVar6 * 2];
    piVar5[3] = local_320[uVar6 * 2 + 1];
    piVar5[2] = *(int *)((int)this + 0x34);
    piVar5[4] = *(int *)((int)this + 0x164);
    local_324 = (int *)FUN_0047d4a0(this_00,piVar5,1);
    if (local_324 == (int *)0x0) {
      *(short *)((int)this_00 + 0x16d4) = *(short *)((int)this_00 + 0x16d4) + 1;
    }
    else {
      FUN_00513980((void *)*piVar5,*(int *)((int)this + 0x34));
      FUN_0047db10(this_00,*(int *)((int)this + 0x34),*(uint *)((int)this + 0x24) & 1);
      iVar4 = *(int *)((int)this + 0x34);
      uVar6 = FUN_00488d90((int)DAT_0057c670);
      iVar4 = uVar6 + iVar4 * 9;
      *(int *)((int)this_00 + iVar4 * 4 + 0x44) = *(int *)((int)this_00 + iVar4 * 4 + 0x44) + 1;
      iVar4 = *(int *)((int)this + 0x144);
      local_330 = 0;
      if (0 < iVar4) {
        do {
          iVar3 = FUN_004017f0((void *)((int)this + 0x130),local_330,(int *)0x0);
          if (*(int *)(iVar3 + 4) == 0xf) {
            iVar7 = *(int *)(iVar3 + 0x2c);
            iVar3 = FUN_00488be0(DAT_0057c670,*(int *)(iVar3 + 8));
            pvVar2 = (void *)FUN_004017f0((void *)(iVar3 + 0x148),iVar7,(int *)0x0);
            if (((pvVar2 != (void *)0x0) && (pvVar2 != this_00)) &&
               (*(int *)((int)pvVar2 + 0x30) != *(int *)((int)this_00 + 0x30))) {
              iVar3 = *(int *)((int)this_00 + 0x30) + (*(int *)((int)this + 0x34) * 3 + 0x31b) * 2;
              *(int *)((int)pvVar2 + iVar3 * 4) = *(int *)((int)pvVar2 + iVar3 * 4) + 1;
              *(int *)((int)pvVar2 + *(int *)((int)this + 0x34) * 4 + 0x1364) =
                   *(int *)((int)pvVar2 + *(int *)((int)this + 0x34) * 4 + 0x1364) + 1;
              iVar3 = *(int *)((int)this_00 + 0x30);
              iVar7 = FUN_00482820((int)DAT_0057c670);
              if (iVar3 == iVar7) {
                FUN_00503250(*(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8),0x22,1);
                FUN_00502f10(*(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8),0x22,-1,-1);
              }
            }
          }
          local_330 = local_330 + 1;
        } while (local_330 < iVar4);
      }
      FUN_00401440((int)this + 0x130);
      uVar11 = FUN_005092b0(this,param_1,piVar5,1,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
      piVar5[3] = (int)uVar11;
      iVar4 = FUN_00478be0(this_00,(int)((ulonglong)uVar11 >> 0x20),*(int *)((int)this + 0x34));
      iVar3 = FUN_004787f0(this_00,*(int *)((int)this + 0x34));
      iVar7 = FUN_00478320(this_00,*(int *)((int)this + 0x34));
      iVar8 = FUN_0047a000(this_00,*(int *)((int)this + 0x34));
      iVar4 = iVar3 + iVar7 + iVar4 + piVar5[3];
      iVar8 = ((int)(iVar4 + (iVar4 >> 0x1f & 3U)) >> 2) + iVar8;
      iVar4 = *(int *)((int)this_00 + 0x30);
      iVar3 = FUN_00482820((int)DAT_0057c670);
      if (((iVar4 == iVar3) && (0x4f < iVar8)) && (*(int *)((int)this + 0x30) == 7)) {
        FUN_004f5fa0(*(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xac),6);
      }
      iVar4 = *(int *)((int)this + 0x30);
      if (((iVar4 != 0xb) && (iVar4 != 0xf)) && (iVar4 != 0x21)) {
        *(int *)((int)this + *(int *)((int)this_00 + 0x30) * 4 + 0x14c) =
             *(int *)((int)this + *(int *)((int)this_00 + 0x30) * 4 + 0x14c) + 1;
        *(int *)((int)this + *(int *)((int)this_00 + 0x30) * 4 + 0xac) = iVar8;
        iVar4 = *(int *)((int)this_00 + 0x30);
        iVar3 = FUN_00482820((int)DAT_0057c670);
        if (iVar4 == iVar3) {
          FUN_00503250(*(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8),0x16,
                       *(int *)((int)this + 0x164));
          FUN_00502f10(*(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8),0x16,-1,-1);
        }
      }
      FUN_005094a0(this,(int)this_00,iVar8);
      FUN_00478be0(this_00,*(undefined4 *)((int)this + 0x34),*(undefined4 *)((int)this + 0x34));
      FUN_00509a20((int)this,extraout_EDX,this_00,(void *)*piVar5,iVar8);
      *piVar5 = 0;
      FUN_0047eba0(this_00,piVar5);
    }
  }
  if (0 < local_328) {
    piVar9 = local_320;
    do {
      piVar1 = (int *)*piVar9;
      if ((piVar1 != (int *)0x0) && (piVar1 != piVar5)) {
        FUN_0054dd78(piVar1);
      }
      piVar9 = piVar9 + 2;
      local_328 = local_328 + -1;
    } while (local_328 != 0);
  }
  return (int)local_324;
}

