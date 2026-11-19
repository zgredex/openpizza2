// rea decompile_all
// name: FUN_004e0200
// address: 0x4e0200
// body: available
// range: 0x4e0200-0x4e0827 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004e0200(void *this,int param_1)

{
  double dVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  byte *pbVar8;
  void *pvVar9;
  int iVar10;
  undefined4 unaff_EDI;
  bool bVar11;
  longlong lVar12;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_14;
  
  iVar2 = FUN_004ddcc0((int)this);
  *(int *)(*(int *)(iVar2 + 4) + 0x40) = *(int *)(*(int *)(iVar2 + 4) + 0x40) + 1;
  FUN_005003e0(*(void **)((int)DAT_0057c670 + 0x90),(int)this);
  if (*(double *)((int)this + 0x108) < 0.0) {
    *(int *)((int)this + 0x1e8) = *(int *)((int)this + 0x1e8) + 1;
    FUN_004e0b60(this,0x16,
                 (float)-((float10)*(double *)((int)this + 0x108) * (float10)0.004000000189989805),
                 '\0',0xffffffff);
    bVar11 = this == *(void **)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200)
    ;
    iVar2 = *(int *)((int)this + 0x1e8);
    if (iVar2 < 0x31) {
      if (iVar2 == 0x24) {
        if (!bVar11) goto LAB_004e02f6;
        pbVar8 = DAT_00582d80;
      }
      else {
        if ((iVar2 != 0x18) || (!bVar11)) goto LAB_004e02f6;
        pbVar8 = DAT_00582de4;
      }
      UI_Briefing_Printf((int)DAT_0057c670,-1,5,-1,-1,0,DAT_00581fd8,pbVar8,unaff_EDI);
    }
    else if (bVar11) {
      FUN_00528190(DAT_0057c5e0,-0x18683,0);
    }
    else {
      FUN_004fca30(*(void **)((int)DAT_0057c670 + 0x90),this);
    }
  }
LAB_004e02f6:
  iVar2 = FUN_00482820((int)DAT_0057c670);
  if ((iVar2 == *(int *)((int)this + 0x48)) && (*(int *)((int)DAT_0057c670 + 0x290) != 5)) {
    if ((*(byte *)((int)this + 0x5c) & 0x10) != 0) {
      FUN_004fc290(*(void **)((int)DAT_0057c670 + 0x90),*(int *)((int)this + 0x4c));
    }
    if ((*(byte *)((int)this + 0x5c) & 0x20) != 0) {
      Game_AutoFillCompanyMenu(*(void **)((int)DAT_0057c670 + 0x90),*(int *)((int)this + 0x4c));
    }
  }
  piVar6 = (int *)((int)this + 0xcc);
  local_30 = 0;
  do {
    if (*(char *)((int)this + local_30 + 0xac) != '\0') {
      pvVar3 = (void *)FUN_00488be0(DAT_0057c670,local_30);
      iVar2 = piVar6[-0xe];
      FUN_004e0b60(pvVar3,0x17,(float)iVar2 * 0.041666668,'\0',0xffffffff);
      FUN_004e0c40(this,0x19,(float)iVar2 * 0.041666668,0xffffffff,'\0');
      *piVar6 = *piVar6 + 1;
      lVar12 = __ftol();
      piVar6[-6] = piVar6[-6] + (int)lVar12;
      iVar2 = FUN_00482820((int)DAT_0057c670);
      if (*(int *)((int)this + 0x48) == iVar2) {
        pvVar3 = *(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xac);
        FUN_004f5f70(pvVar3,0x1a,*(int *)((int)pvVar3 + 0x78) + (int)lVar12);
      }
    }
    local_30 = local_30 + 1;
    piVar6 = piVar6 + 1;
  } while (local_30 < 6);
  bVar11 = false;
  iVar2 = *(int *)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8);
  local_2c = *(int *)(iVar2 + 0xec);
  local_28 = *(int *)(iVar2 + 0x1d0);
  iVar2 = *(int *)((int)this + 0x140);
  local_30 = 0;
  if (0 < iVar2) {
    do {
      pvVar3 = (void *)FUN_004017f0((void *)((int)this + 300),local_30,(int *)0x0);
      if (*(int *)((int)pvVar3 + 4) != 0) {
        FUN_0050fb70(pvVar3,1,*(int *)((int)this + 0x48));
        iVar10 = *(int *)((int)pvVar3 + 8);
        pvVar9 = (void *)0x0;
        if (iVar10 == 1) {
          FUN_004e0b60(this,0xf,(float)*(int *)((int)pvVar3 + 0x20) * 0.041666668,'\0',0xffffffff);
          local_24 = *(int *)((int)this + 0x15c);
        }
        else if (iVar10 == 2) {
          local_24 = *(int *)((int)pvVar3 + 0x20);
          iVar10 = FUN_00482820((int)DAT_0057c670);
          if (*(int *)((int)this + 0x48) == iVar10) {
            if (local_2c < 1) {
              if (0 < local_28) {
                local_24 = (local_24 * 0xf) / 10;
                local_28 = local_28 + -1;
              }
            }
            else {
              local_2c = local_2c + -1;
              local_24 = 0;
            }
          }
          pvVar9 = (void *)FUN_004017f0((void *)((int)this + 0x148),*(int *)((int)pvVar3 + 0xc),
                                        (int *)0x0);
          FUN_00477e40(pvVar9,0x10,(float)local_24 * 0.041666668,'\0',-1);
          local_24 = 1;
        }
        else if (iVar10 == 3) {
          pvVar9 = (void *)FUN_004017f0((void *)((int)this + 0x148),*(int *)((int)pvVar3 + 0xc),
                                        (int *)0x0);
          FUN_00477e40(pvVar9,0x11,(float)*(int *)((int)pvVar3 + 0x20) * 0.041666668,'\0',-1);
          local_24 = 2;
        }
        if (*(int *)((int)pvVar3 + 8) == 2) {
          dVar1 = (double)*(int *)((int)pvVar3 + 0x28);
          if (dVar1 < -10.0) {
            bVar11 = true;
          }
          FUN_004e4670(*(void **)(*(int *)((int)pvVar9 + 0x16f0) + 0x74),
                       dVar1 * 0.027777777777777776,dVar1);
        }
        else if (*(int *)((int)pvVar3 + 8) == 1) {
          iVar10 = *(int *)((int)this + 0x15c);
          iVar7 = 0;
          if (0 < iVar10) {
            do {
              iVar4 = FUN_004017f0((void *)((int)this + 0x148),iVar7,(int *)0x0);
              dVar1 = (double)*(int *)((int)pvVar3 + 0x28);
              if (dVar1 < -10.0) {
                bVar11 = true;
              }
              FUN_004e4670(*(void **)(*(int *)(iVar4 + 0x16f0) + 0x74),dVar1 * 0.027777777777777776,
                           dVar1);
              iVar7 = iVar7 + 1;
            } while (iVar7 < iVar10);
          }
          if ((param_1 % 3 == 0) && (0 < *(int *)((int)pvVar3 + 0x18))) {
            local_20 = 0;
            do {
              iVar10 = FUN_0050f870(pvVar3,*(int *)((int)this + 0x48),local_20);
              if ((0x3c < iVar10) && (0 < local_24)) {
                local_14 = local_24;
                do {
                  uVar5 = FUN_004034d0(1,100);
                  if ((int)uVar5 < ((iVar10 * 5 + -300) * 5) / 10) {
                    iVar7 = *(int *)((int)pvVar3 + 0x18);
                    pvVar9 = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),
                                                  *(int *)((int)DAT_0057c670 + 0x2f4),(int *)0x0);
                    FUN_004da810(pvVar9,local_20,iVar7 + -1);
                  }
                  local_14 = local_14 + -1;
                } while (local_14 != 0);
              }
              local_20 = local_20 + 1;
            } while (local_20 < 8);
          }
        }
      }
      local_30 = local_30 + 1;
    } while (local_30 < iVar2);
    if (((bVar11) && (iVar2 = FUN_00482820((int)DAT_0057c670), *(int *)((int)this + 0x48) == iVar2))
       && (iVar2 = FUN_0048c000(DAT_0057c670,2), iVar2 == 0)) {
      iVar2 = UI_Briefing_Printf((int)DAT_0057c670,-1,5,-1,-1,0,DAT_005825b8,DAT_00582860,unaff_EDI)
      ;
      FUN_0048c040(DAT_0057c670,iVar2,2);
    }
  }
  iVar2 = *(int *)((int)this + 0x15c);
  iVar10 = 0;
  if (0 < iVar2) {
    do {
      pvVar3 = (void *)FUN_004017f0((void *)((int)this + 0x148),iVar10,(int *)0x0);
      FUN_004773a0(pvVar3,param_1);
      FUN_004e46f0(*(int *)(*(int *)((int)pvVar3 + 0x16f0) + 0x74));
      iVar10 = iVar10 + 1;
    } while (iVar10 < iVar2);
  }
  iVar2 = *(int *)((int)this + 0x194);
  iVar10 = 0;
  if (0 < iVar2) {
    do {
      pvVar3 = (void *)FUN_004017f0((void *)((int)this + 0x180),iVar10,(int *)0x0);
      FUN_00513f50(pvVar3,param_1);
      iVar10 = iVar10 + 1;
    } while (iVar10 < iVar2);
  }
  iVar2 = *(int *)((int)this + 0x1cc);
  iVar10 = 0;
  if (0 < iVar2) {
    do {
      piVar6 = (int *)FUN_004017f0((void *)((int)this + 0x1b8),iVar10,(int *)0x0);
      if (piVar6[1] == 0x17) {
        iVar7 = FUN_004017f0((void *)((int)DAT_0057c670 + 0x3c),*piVar6,(int *)0x0);
        *(int *)(iVar7 + 0xa8) = *(int *)(iVar7 + 0xa8) + 5;
        if (100 < *(int *)(iVar7 + 0xa8)) {
          *(undefined4 *)(iVar7 + 0xa8) = 100;
        }
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < iVar2);
  }
  return;
}

