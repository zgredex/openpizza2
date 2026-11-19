// rea decompile_all
// name: FUN_004d8d50
// address: 0x4d8d50
// body: available
// range: 0x4d8d50-0x4d9756 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_004d8d50(void *this,int param_1)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  void *pvVar5;
  int iVar6;
  int iVar7;
  void *pvVar8;
  uint uVar9;
  int *piVar10;
  uint uVar11;
  undefined4 *puVar12;
  undefined4 uVar13;
  int iVar14;
  int *piVar15;
  undefined4 unaff_EDI;
  longlong lVar16;
  void *local_1c;
  uint local_18;
  void *local_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005591cc;
  local_c = ExceptionList;
  iVar14 = 0;
  bVar1 = false;
  ExceptionList = &local_c;
  if ((0 < *(int *)((int)this + 0x114c)) &&
     (iVar3 = *(int *)((int)this + 0x114c) + -1, ExceptionList = &local_c,
     *(int *)((int)this + 0x114c) = iVar3, iVar3 == 0)) {
    FUN_004dce70((int)this);
    if (*(void **)((int)DAT_0057c670 + 0x25c) != (void *)0x0) {
      FUN_005301c0(*(void **)((int)DAT_0057c670 + 0x25c),-0x1860d,0x23,0);
    }
  }
  piVar10 = (int *)((int)this + 0xc98);
  piVar15 = (int *)((int)this + 0xc38);
  do {
    iVar3 = FUN_00488be0(DAT_0057c670,iVar14);
    if (iVar3 != 0) {
      iVar3 = 4;
      piVar4 = piVar15;
      do {
        iVar6 = *piVar4;
        *piVar4 = iVar6 + 1;
        if (100 < iVar6 + 1) {
          *piVar4 = 100;
        }
        piVar4 = piVar4 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      iVar3 = FUN_00488be0(DAT_0057c670,iVar14);
      iVar3 = FUN_004ddcc0(iVar3);
      iVar3 = *(int *)(iVar3 + 0x60) + *(int *)(iVar3 + 0x48);
      if (iVar3 < 0) {
        iVar3 = 0;
      }
      iVar6 = *piVar10;
      *piVar10 = iVar6 + iVar3;
      if (100 < iVar6 + iVar3) {
        *piVar10 = 100;
      }
      if (*piVar10 < 0) {
        *piVar10 = 0;
      }
    }
    iVar14 = iVar14 + 1;
    piVar10 = piVar10 + 1;
    piVar15 = piVar15 + 4;
  } while (iVar14 < 6);
  iVar14 = *(int *)((int)this + 0x10c0);
  if (iVar14 < 1) {
    *(int *)((int)this + 0x10c0) = iVar14 + 1;
    if (iVar14 + 1 == 0) {
      FUN_004dca00((int)this);
      iVar14 = 0;
      if (0 < *(int *)((int)DAT_0057c670 + 0x50)) {
        do {
          pvVar5 = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 0x3c),iVar14,(int *)0x0);
          iVar3 = FUN_0050dbd0((int)pvVar5);
          if ((iVar3 == 0) && (bVar2 = FUN_0050e540((int)pvVar5), bVar2)) {
            FUN_0050e520(pvVar5);
          }
          iVar14 = iVar14 + 1;
        } while (iVar14 < *(int *)((int)DAT_0057c670 + 0x50));
      }
    }
  }
  else {
    *(int *)((int)this + 0x10c0) = iVar14 + -1;
    if (iVar14 + -1 == 0) {
      *(undefined4 *)((int)this + 0x10c0) = 0xfffffffa;
      FUN_004dca80((int)this);
    }
  }
  iVar14 = *(int *)((int)this + 0xfa8);
  local_1c = (void *)0x0;
  if (0 < *(int *)((int)this + 0xfc0)) {
    do {
      pvVar5 = (void *)FUN_004017f0((void *)((int)this + 0xfac),(int)local_1c,(int *)0x0);
      iVar3 = *(int *)((int)pvVar5 + 8);
      if ((0 < *(int *)((int)pvVar5 + 0x38)) &&
         (iVar6 = *(int *)((int)pvVar5 + 0x38) + -1, *(int *)((int)pvVar5 + 0x38) = iVar6,
         iVar6 == 0)) {
        if ((*(int *)((int)DAT_0057c670 + 0x2d8) == 0x14) &&
           ((iVar6 = FUN_00482910((int)DAT_0057c670), iVar6 != 0 &&
            (*(void **)((int)DAT_0057c670 + 0x218) == pvVar5)))) {
          FUN_00482880((int)DAT_0057c670);
          *(undefined4 *)((int)DAT_0057c670 + 0x218) = 0;
          pvVar8 = DAT_0057c670;
          *(undefined4 *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x290) * 4 + 0x2b8) =
               *(undefined4 *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x290) * 4 + 0x298);
          *(undefined4 *)((int)pvVar8 + *(int *)((int)pvVar8 + 0x290) * 4 + 0x298) = 1;
          local_1c = FUN_00484650(DAT_0057c670,(int *)0x0);
          FUN_00523d60(DAT_0057c5e0,(int)local_1c);
          pvVar8 = *(void **)((int)DAT_0057c670 + 0x260);
          FUN_0052ff50(pvVar8,0x3fd,0);
          FUN_00531620(pvVar8,0x3fd,0);
          FUN_005316f0(pvVar8,0x3fd,0);
        }
        iVar6 = *(int *)((int)pvVar5 + 8);
        iVar7 = FUN_00482820((int)DAT_0057c670);
        if (iVar6 == iVar7) {
          FUN_00548e00(DAT_0057ba0c,0x16);
        }
        DebugConsole_Printf(DAT_0057c1e0,0xff,(byte *)s_Es_ist_ein_Haus_fertig_geworden__0056cda4,
                            unaff_EDI);
        switch(*(undefined4 *)((int)pvVar5 + 0x30)) {
        case 0xf:
          iVar6 = FUN_00488be0(DAT_0057c670,iVar3);
          if (*(int *)((int)pvVar5 + 0x2c) == -1) {
            iVar7 = FUN_004f7420(*(void **)((int)DAT_0057c670 + 0x90),*(int *)((int)this + 0xc1c),
                                 pvVar5,*(int *)(iVar6 + 0x4c),0,1);
            local_14 = (void *)FUN_004017f0((void *)(iVar6 + 0x148),iVar7,(int *)0x0);
            if (local_14 != (void *)0x0) {
              lVar16 = __ftol();
              *(int *)((int)local_14 + 0x14b0) = (int)lVar16;
              iVar6 = FUN_00482820((int)DAT_0057c670);
              if (iVar3 == iVar6) {
                FUN_00502f10(*(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8),0x11,-1,-1);
              }
            }
            goto LAB_004d9383;
          }
          iVar7 = FUN_00482820((int)DAT_0057c670);
          if (iVar3 == iVar7) {
            FUN_00502f10(*(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8),0xc,-1,-1);
          }
          local_14 = (void *)FUN_004017f0((void *)(iVar6 + 0x148),*(int *)((int)pvVar5 + 0x2c),
                                          (int *)0x0);
          FUN_0047fb40((int)local_14);
          FUN_0047fb70(local_14);
          if ((*(int *)((int)local_14 + 0x38) == 2) &&
             (iVar3 = *(int *)((int)local_14 + 0x30), iVar6 = FUN_00482820((int)DAT_0057c670),
             iVar3 == iVar6)) {
            FUN_00502f10(*(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8),0x10,-1,-1);
          }
          FUN_004fc7d0(*(void **)((int)DAT_0057c670 + 0x90),local_14,0);
          bVar1 = true;
          break;
        case 0x10:
          pvVar8 = (void *)FUN_00488be0(DAT_0057c670,iVar3);
          if (*(int *)((int)pvVar5 + 0x2c) == -1) {
            iVar6 = FUN_004f7710(*(int *)((int)this + 0xc1c),pvVar5,iVar3,0,1);
            iVar6 = FUN_004017f0((void *)((int)pvVar8 + 0x180),iVar6,(int *)0x0);
            *(undefined1 *)(iVar6 + 0x3c) = 1;
            iVar6 = FUN_00482820((int)DAT_0057c670);
            if (iVar3 == iVar6) {
              FUN_00502f10(*(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8),0xe,-1,-1);
            }
          }
          else {
            iVar6 = FUN_004e2330(pvVar8,(int)pvVar5);
            *(int *)(iVar6 + 0x2c) = *(int *)((int)pvVar5 + 0x34) + -0x834 >> 2;
            iVar6 = FUN_00482820((int)DAT_0057c670);
            if (iVar3 == iVar6) {
              FUN_00502f10(*(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8),0xd,-1,-1);
            }
          }
          break;
        case 0x11:
          *(undefined4 *)((int)pvVar5 + 0xc) = *(undefined4 *)((int)this + 0x10c4);
          FUN_004d8d30(this,*(int *)((int)this + 0x10c4));
          FUN_004dae90(this,(int)pvVar5);
          *(int *)((int)this + 0x10c4) = *(int *)((int)this + 0x10c4) + 1;
          iVar6 = FUN_00482820((int)DAT_0057c670);
          if (iVar3 == iVar6) {
            FUN_00502f10(*(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8),0,-1,-1);
          }
          break;
        default:
          Game_RedirectPersonDestination(DAT_0057c670,(int)pvVar5);
          break;
        case 0x1c:
          iVar6 = FUN_00488be0(DAT_0057c670,iVar3);
          *(void **)(iVar6 + 0x1d8) = pvVar5;
          iVar6 = FUN_004017f0((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                               (int *)0x0);
          iVar6 = *(int *)(iVar6 + 0xc20 + iVar3 * 4);
          iVar7 = FUN_00482820((int)DAT_0057c670);
          if (iVar3 == iVar7) {
            if (iVar6 == 0) {
              iVar6 = 2;
              pvVar8 = *(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8);
            }
            else {
              iVar6 = 1;
              pvVar8 = *(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8);
            }
            FUN_00502f10(pvVar8,iVar6,-1,-1);
          }
          pvVar8 = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),
                                        *(int *)((int)DAT_0057c670 + 0x2f4),(int *)0x0);
          FUN_004dcb30(pvVar8,iVar3);
          iVar6 = FUN_00482820((int)DAT_0057c670);
          if ((iVar3 == iVar6) && (*(void **)((int)DAT_0057c670 + 0x25c) != (void *)0x0)) {
            FUN_005301c0(*(void **)((int)DAT_0057c670 + 0x25c),-0x18617,0x23,0);
          }
        }
        FUN_004d2420(pvVar5,*(int *)((int)pvVar5 + 0x30),*(int *)((int)pvVar5 + 0x34));
        if (bVar1) {
          FUN_0047fb70(local_14);
        }
        *(undefined4 *)(iVar14 + 0xf4) = 1;
      }
LAB_004d9383:
      local_1c = (void *)((int)local_1c + 1);
    } while ((int)local_1c < *(int *)((int)this + 0xfc0));
  }
  FUN_004da550((int)this);
  iVar14 = *(int *)((int)this + 0x10cc) + -1;
  *(int *)((int)this + 0x10cc) = iVar14;
  *(int *)((int)this + 0x10c8) = *(int *)((int)this + 0x10c8) + -1;
  if (iVar14 < 1) {
    uVar9 = FUN_004034d0(0x18,0x60);
    *(uint *)((int)this + 0x10cc) = uVar9;
    FUN_004daaf0(this,-1,0);
    iVar3 = 1;
    iVar14 = FUN_004d8090((int)this);
    FUN_004daaf0(this,iVar14,iVar3);
    iVar3 = 1;
    iVar14 = FUN_004d80e0((int)this);
    FUN_004daaf0(this,iVar14,iVar3);
    uVar9 = FUN_004034d0(0,7);
    FUN_004db260(this,uVar9);
    FUN_004db1d0(this,-1);
    Person_RefreshShopChoices(this);
  }
  if (*(int *)((int)this + 0x10c8) < 1) {
    uVar9 = FUN_004034d0(0x30,0xc0);
    *(uint *)((int)this + 0x10c8) = uVar9;
    FUN_0048c400(DAT_0057c670,(undefined4 *)0xa,-1,0);
    FUN_004dcc20(this);
    FUN_0048e0a0();
  }
  local_18 = 0;
  do {
    iVar14 = FUN_004d6ba0(this,local_18);
    pvVar5 = (void *)(iVar14 + -10);
    local_1c = pvVar5;
    do {
      if ((int)pvVar5 < 1) break;
      iVar14 = *(int *)((int)this + 0xfdc);
      iVar3 = 0;
      if (0 < iVar14) {
        do {
          piVar10 = (int *)FUN_004017f0((void *)((int)this + 0xfc8),iVar3,(int *)0x0);
          iVar6 = *piVar10;
          if (*(byte *)(iVar6 + 0x824) == local_18) {
            FUN_004d6c10(this,iVar6);
            FUN_0054dd78(piVar10);
            FUN_004d3e30(iVar6);
            local_1c = (void *)((int)local_1c + -1);
            break;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar14);
        pvVar5 = local_1c;
      }
    } while (iVar3 != iVar14);
    local_18 = local_18 + 1;
  } while ((int)local_18 < 4);
  uVar9 = 0;
  do {
    iVar14 = FUN_004d6ba0(this,uVar9);
    if ((iVar14 < 10) && (uVar11 = _rand(), (uVar11 & 1) != 0)) {
      FUN_004d4940(this,uVar9);
    }
    uVar9 = uVar9 + 1;
  } while ((int)uVar9 < 4);
  iVar14 = param_1 / 3;
  if (param_1 % 3 == 0) {
    iVar3 = FUN_00482720((int)DAT_0057c670);
    iVar14 = FUN_0048a200(DAT_0057c670,0x17);
    if (0 < iVar3 * 2 - iVar14) {
      pvVar5 = operator_new(0x16c);
      local_4 = 0;
      if (pvVar5 == (void *)0x0) {
        puVar12 = (undefined4 *)0x0;
      }
      else {
        puVar12 = FUN_00504610(pvVar5,0x17,*(int *)((int)this + 0xc1c),0,0,-1);
      }
      local_4 = 0xffffffff;
      FUN_00403020(DAT_0057ba10,0,(char *)(puVar12 + 1));
      FUN_00482790(DAT_0057c670,puVar12);
    }
    iVar6 = 0;
    do {
      uVar9 = FUN_004034d0(0,2);
      iVar6 = iVar6 + 1;
      if (uVar9 == 0) {
        iVar14 = FUN_0048a200(DAT_0057c670,0x1d);
        if (0 < iVar3 * 3 - iVar14) {
          pvVar5 = operator_new(0x16c);
          local_4 = 1;
          if (pvVar5 == (void *)0x0) {
            puVar12 = (undefined4 *)0x0;
          }
          else {
            puVar12 = FUN_00504610(pvVar5,0x1d,*(int *)((int)this + 0xc1c),0,0,-1);
          }
          uVar13 = DAT_00582eec;
LAB_004d9722:
          iVar14 = puVar12[9];
LAB_004d972b:
          local_4 = 0xffffffff;
          FUN_004030f0(DAT_0057ba10,iVar14,(undefined1 *)(puVar12 + 1),uVar13);
          iVar14 = FUN_00482790(DAT_0057c670,puVar12);
          ExceptionList = local_c;
          return iVar14;
        }
      }
      else if (uVar9 == 1) {
        iVar14 = FUN_0048a200(DAT_0057c670,0x1e);
        if (0 < iVar3 * 4 - iVar14) {
          pvVar5 = operator_new(0x16c);
          local_4 = 2;
          if (pvVar5 == (void *)0x0) {
            puVar12 = (undefined4 *)0x0;
          }
          else {
            puVar12 = FUN_00504610(pvVar5,0x1e,*(int *)((int)this + 0xc1c),0,0,-1);
          }
          iVar14 = puVar12[9];
          uVar13 = DAT_00582dd0;
          goto LAB_004d972b;
        }
      }
      else {
        iVar14 = FUN_0048a200(DAT_0057c670,0x1f);
        if (0 < iVar3 * 5 - iVar14) {
          pvVar5 = operator_new(0x16c);
          local_4 = 3;
          if (pvVar5 == (void *)0x0) {
            puVar12 = (undefined4 *)0x0;
            uVar13 = DAT_00582418;
          }
          else {
            puVar12 = FUN_00504610(pvVar5,0x1f,*(int *)((int)this + 0xc1c),0,0,-1);
            uVar13 = DAT_00582418;
          }
          goto LAB_004d9722;
        }
      }
    } while (iVar6 < 9);
  }
  ExceptionList = local_c;
  return iVar14;
}

