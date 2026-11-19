// rea decompile_all
// name: FUN_00511ff0
// address: 0x511ff0
// body: available
// range: 0x511ff0-0x5123b3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
FUN_00511ff0(void *this,void *param_1,uint param_2,undefined4 param_3,uint param_4,byte param_5,
            int param_6)

{
  float fVar1;
  byte bVar2;
  undefined4 *this_00;
  uint uVar3;
  int iVar4;
  float *pfVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  float10 fVar10;
  longlong lVar11;
  byte bVar12;
  int *piVar13;
  int iVar14;
  float local_20 [3];
  int aiStack_14 [5];
  
  bVar2 = param_5;
  this_00 = FUN_00511e60(param_1,param_2,param_5);
  lVar11 = FUN_00511fa0();
  uVar7 = (uint)lVar11;
  if (param_6 == -1) {
    uVar3 = Random_Range(1,param_4);
    uVar6 = (uint)param_5;
    fVar1 = *(float *)((int)this + uVar6 * 4 + 0x314) / (float)(int)uVar3;
    _param_5 = uVar3;
    while (fVar1 < 10.0) {
      _param_5 = _param_5 - 1;
      if (_param_5 == 0) {
        _param_5 = 1;
        break;
      }
      fVar1 = *(float *)((int)this + uVar6 * 4 + 0x314) / (float)(int)_param_5;
    }
    if ((int)uVar7 < (int)_param_5) {
      _param_5 = uVar7;
    }
  }
  else {
    _param_5 = 1;
  }
  param_1 = (void *)0x0;
  uVar6 = _param_5;
  if (0 < (int)_param_5) {
    iVar4 = DAT_0057c670;
    iVar14 = 0;
    do {
      if (param_6 == 1) {
        if (bVar2 == 1) {
switchD_00512107_caseD_1:
          iVar9 = *(int *)(iVar4 + 0xa8);
          goto LAB_0051215a;
        }
        if (bVar2 == 2) goto switchD_00512107_caseD_2;
        if (bVar2 == 6) goto switchD_00512107_caseD_6;
      }
      else if (param_6 == 2) {
        switch(bVar2) {
        case 1:
          goto switchD_00512107_caseD_1;
        case 2:
switchD_00512107_caseD_2:
          iVar9 = *(int *)(iVar4 + 0x1cc);
          break;
        case 3:
          iVar9 = *(int *)(iVar4 + 0x100);
          break;
        default:
          goto switchD_00512107_caseD_4;
        case 6:
switchD_00512107_caseD_6:
          iVar9 = *(int *)(iVar4 + 0x1e8);
        }
LAB_0051215a:
        aiStack_14[iVar14] = iVar9;
      }
      else if (param_6 == 3) {
        switch(bVar2) {
        case 1:
          goto switchD_00512107_caseD_1;
        case 2:
          goto switchD_00512107_caseD_2;
        case 3:
          iVar9 = *(int *)(iVar4 + 0x108);
          goto LAB_0051215a;
        case 6:
          goto switchD_00512107_caseD_6;
        }
      }
      else {
        piVar13 = (int *)0x0;
        uVar3 = Random_Range(0,uVar7 - 1);
        iVar4 = IDMap_Lookup(this_00,uVar3,piVar13);
        aiStack_14[iVar14] = iVar4;
        iVar4 = DAT_0057c670;
      }
switchD_00512107_caseD_4:
      iVar9 = iVar14 + 1;
      param_1 = (void *)((float)*(double *)(aiStack_14[iVar14] + 0xc0) + (float)param_1);
      local_20[iVar14] = (float)*(double *)(aiStack_14[iVar14] + 0xc0);
      iVar14 = iVar9;
    } while (iVar9 < (int)_param_5);
    if (0 < (int)_param_5) {
      pfVar5 = local_20;
      uVar7 = _param_5;
      do {
        uVar7 = uVar7 - 1;
        *pfVar5 = (*pfVar5 * 100.0) / (float)param_1;
        pfVar5 = pfVar5 + 1;
      } while (uVar7 != 0);
    }
  }
  while (uVar6 = uVar6 - 1, 0 < (int)uVar6) {
    iVar4 = 0;
    if (0 < (int)uVar6) {
      do {
        if (local_20[iVar4] < local_20[iVar4 + 1]) {
          fVar1 = local_20[iVar4];
          local_20[iVar4] = local_20[iVar4 + 1];
          local_20[iVar4 + 1] = fVar1;
        }
        iVar14 = aiStack_14[iVar4];
        if (*(double *)(aiStack_14[iVar4 + 1] + 0xc0) < *(double *)(iVar14 + 0xc0)) {
          aiStack_14[iVar4] = aiStack_14[iVar4 + 1];
          aiStack_14[iVar4 + 1] = iVar14;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)uVar6);
    }
  }
  param_6 = 0;
  if (0 < (int)_param_5) {
    pfVar5 = (float *)((int)this + (uint)bVar2 * 4 + 0x314);
    do {
      if ((param_2 == 2) || ((3 < (int)param_2 && ((int)param_2 < 7)))) {
        iVar4 = aiStack_14[param_6];
        bVar2 = FUN_004e47e0(iVar4);
      }
      else {
        iVar4 = aiStack_14[param_6];
        bVar2 = FUN_004e4810(iVar4);
      }
      do {
        while( true ) {
          lVar11 = __ftol();
          iVar14 = (int)lVar11;
          if (iVar14 == 0) break;
          if (iVar14 < 4) {
            if (iVar14 == 1) {
              iVar14 = 1;
              uVar7 = 1;
              uVar6 = 0xd;
              uVar8 = *(undefined4 *)(*(int *)(DAT_0057c670 + 0xa0) + 0x18);
            }
            else {
              if (iVar14 == 2) {
                uVar8 = *(undefined4 *)(*(int *)(DAT_0057c670 + 0xa0) + 0x18);
              }
              else {
                if (iVar14 != 3) goto LAB_00512387;
                fVar10 = FUN_00511be0(this,*(undefined4 *)(*(int *)(DAT_0057c670 + 0xa0) + 0x18),0xd
                                      ,iVar4,1,bVar2,1);
                *pfVar5 = (float)((float10)*pfVar5 - fVar10);
                uVar8 = *(undefined4 *)(*(int *)(DAT_0057c670 + 0xa0) + 0x18);
              }
              iVar14 = 2;
              uVar7 = Random_Range(1,0x20);
              uVar6 = Random_Range(5,0xc);
            }
            fVar10 = FUN_00511be0(this,uVar8,uVar6,iVar4,uVar7,bVar2,iVar14);
            *pfVar5 = (float)((float10)*pfVar5 - fVar10);
            goto LAB_00512387;
          }
          iVar9 = 4;
          uVar8 = *(undefined4 *)(*(int *)(DAT_0057c670 + 0xa0) + 0x18);
          bVar12 = bVar2;
          uVar7 = Random_Range(1,0x20);
          iVar14 = iVar4;
          uVar6 = Random_Range(4,10);
          fVar10 = FUN_00511be0(this,uVar8,uVar6,iVar14,uVar7,bVar12,iVar9);
          *pfVar5 = (float)((float10)*pfVar5 - fVar10);
        }
        bVar2 = bVar2 + 1;
      } while (bVar2 < 4);
LAB_00512387:
      param_6 = param_6 + 1;
    } while (param_6 < (int)_param_5);
  }
  if (this_00 != (undefined4 *)0x0) {
    (**(code **)*this_00)(1);
  }
  return;
}

