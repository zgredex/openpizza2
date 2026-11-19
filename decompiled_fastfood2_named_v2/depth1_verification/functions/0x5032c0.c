// rea decompile_all
// name: FUN_005032c0
// address: 0x5032c0
// body: available
// range: 0x5032c0-0x503a39 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_005032c0(int param_1)

{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_4;
  
  iVar5 = *(int *)(param_1 + 0x50);
  switch(iVar5) {
  case 1:
  case 2:
  case 3:
  case 5:
  case 6:
  case 7:
  case 8:
  case 0xd:
  case 0xe:
  case 0x10:
  case 0x13:
  case 0x17:
  case 0x19:
  case 0x1c:
  case 0x1d:
  case 0x21:
  case 0x25:
  case 0x26:
  case 0x31:
  case 0x32:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
    iVar6 = *(int *)(param_1 + 0x88 + iVar5 * 4);
    goto LAB_005039d0;
  case 4:
  case 0x30:
    *(undefined4 *)(param_1 + 0x88 + iVar5 * 4) = 0x30;
    break;
  case 9:
    FUN_004e0c40(*(void **)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200),
                 0x18,10000.0,0xffffffff,'\x01');
    break;
  case 10:
    FUN_004e0c40(*(void **)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200),
                 0x18,50000.0,0xffffffff,'\x01');
    break;
  case 0xb:
    FUN_004e0c40(*(void **)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200),
                 0x18,99999.0,1,'\0');
    break;
  case 0xc:
    *(undefined4 *)(param_1 + 0x88 + iVar5 * 4) = 4;
    break;
  case 0xf:
    iVar6 = *(int *)(param_1 + 0x88 + iVar5 * 4) + 0x30;
    goto LAB_005039d1;
  case 0x11:
    local_4 = 0;
    iVar5 = *(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200);
    iVar6 = *(int *)(iVar5 + 0x15c);
    if (0 < iVar6) {
      do {
        pvVar2 = (void *)FUN_004017f0((void *)(iVar5 + 0x148),local_4,(int *)0x0);
        iVar8 = Game_CountObjectsByType(pvVar2,0xffffffff);
        iVar3 = 0;
        if (0 < iVar8) {
          do {
            puVar4 = (undefined4 *)FUN_004017f0((void *)((int)pvVar2 + 0x1500),iVar3,(int *)0x0);
            pvVar1 = (void *)*puVar4;
            if (*(char *)((int)pvVar1 + 0x824) == '\x02') {
              iVar9 = (*(int *)((int)pvVar1 + 4) * 0xb) / 10;
              if (100 < iVar9) {
                iVar9 = 100;
              }
              FUN_004d4130(pvVar1,iVar9);
              iVar9 = (*(int *)((int)*puVar4 + 8) * 0xb) / 10;
              if (100 < iVar9) {
                iVar9 = 100;
              }
              FUN_004d4140((void *)*puVar4,iVar9);
              iVar9 = (*(int *)((int)*puVar4 + 0xc) * 0xb) / 10;
              if (100 < iVar9) {
                iVar9 = 100;
              }
              FUN_004d4120((void *)*puVar4,iVar9);
              iVar9 = (*(int *)((int)*puVar4 + 0x10) * 0xb) / 10;
              if (100 < iVar9) {
                iVar9 = 100;
              }
              FUN_004d4150((void *)*puVar4,iVar9);
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 < iVar8);
        }
        local_4 = local_4 + 1;
      } while (local_4 < iVar6);
    }
    break;
  case 0x12:
    local_4 = 0;
    iVar5 = *(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200);
    iVar6 = *(int *)(iVar5 + 0x15c);
    if (0 < iVar6) {
      do {
        pvVar2 = (void *)FUN_004017f0((void *)(iVar5 + 0x148),local_4,(int *)0x0);
        iVar8 = Game_CountObjectsByType(pvVar2,0xffffffff);
        iVar3 = 0;
        if (0 < iVar8) {
          do {
            puVar4 = (undefined4 *)FUN_004017f0((void *)((int)pvVar2 + 0x1500),iVar3,(int *)0x0);
            pvVar1 = (void *)*puVar4;
            if (*(char *)((int)pvVar1 + 0x824) == '\0') {
              iVar9 = (*(int *)((int)pvVar1 + 4) * 0xb) / 10;
              if (100 < iVar9) {
                iVar9 = 100;
              }
              FUN_004d4130(pvVar1,iVar9);
              iVar9 = (*(int *)((int)*puVar4 + 8) * 0xb) / 10;
              if (100 < iVar9) {
                iVar9 = 100;
              }
              FUN_004d4140((void *)*puVar4,iVar9);
              iVar9 = (*(int *)((int)*puVar4 + 0xc) * 0xb) / 10;
              if (100 < iVar9) {
                iVar9 = 100;
              }
              FUN_004d4120((void *)*puVar4,iVar9);
              iVar9 = (*(int *)((int)*puVar4 + 0x10) * 0xb) / 10;
              if (100 < iVar9) {
                iVar9 = 100;
              }
              FUN_004d4150((void *)*puVar4,iVar9);
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 < iVar8);
        }
        local_4 = local_4 + 1;
      } while (local_4 < iVar6);
    }
    break;
  case 0x14:
    iVar8 = 0;
    iVar5 = *(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200);
    iVar6 = *(int *)(iVar5 + 0x15c);
    if (0 < iVar6) {
      do {
        pvVar2 = (void *)FUN_004017f0((void *)(iVar5 + 0x148),iVar8,(int *)0x0);
        iVar3 = Game_CountObjectsByType(pvVar2,0xffffffff);
        iVar9 = 0;
        if (0 < iVar3) {
          do {
            puVar4 = (undefined4 *)FUN_004017f0((void *)((int)pvVar2 + 0x1500),iVar9,(int *)0x0);
            FUN_004d4160((void *)*puVar4,(*(int *)((int)*puVar4 + 0x3c) << 3) / 10);
            iVar9 = iVar9 + 1;
          } while (iVar9 < iVar3);
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < iVar6);
    }
    break;
  case 0x15:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2d:
  case 0x2e:
    iVar6 = *(int *)(param_1 + 0x88 + iVar5 * 4) + 5;
    goto LAB_005039d1;
  case 0x16:
    iVar6 = *(int *)(param_1 + 0x88 + iVar5 * 4) + 10;
    goto LAB_005039d1;
  case 0x18:
    *(int *)(param_1 + 0x88 + iVar5 * 4) = *(int *)(param_1 + 0x88 + iVar5 * 4) + 1;
    FUN_004ddd20(*(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200));
    break;
  case 0x1a:
    iVar5 = FUN_004017f0((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                         (int *)0x0);
    iVar6 = FUN_00482820((int)DAT_0057c670);
    *(undefined4 *)(iVar5 + 0xd40 + iVar6 * 4) = 100;
    break;
  case 0x1b:
    iVar5 = FUN_004017f0((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                         (int *)0x0);
    iVar6 = FUN_00482820((int)DAT_0057c670);
    *(undefined4 *)(iVar5 + 0xc98 + iVar6 * 4) = 100;
    break;
  case 0x1e:
    pvVar2 = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),
                                  *(int *)((int)DAT_0057c670 + 0x2f4),(int *)0x0);
    iVar6 = 1;
    iVar5 = FUN_00482820((int)DAT_0057c670);
    FUN_004daaf0(pvVar2,iVar5,iVar6);
    break;
  case 0x1f:
    iVar8 = 0;
    iVar5 = *(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200);
    iVar6 = *(int *)(iVar5 + 0x15c);
    if (0 < iVar6) {
      do {
        iVar3 = FUN_004017f0((void *)(iVar5 + 0x148),iVar8,(int *)0x0);
        if (*(int *)(iVar3 + 0x14b4) < 5) {
          *(int *)(iVar3 + 0x14b4) = *(int *)(iVar3 + 0x14b4) + 1;
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < iVar6);
    }
    if (*(void **)((int)DAT_0057c670 + 0x25c) != (void *)0x0) {
      FUN_005301c0(*(void **)((int)DAT_0057c670 + 0x25c),-0x18614,0x23,0);
    }
    break;
  case 0x20:
    pvVar2 = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),
                                  *(int *)((int)DAT_0057c670 + 0x2f4),(int *)0x0);
    iVar5 = 0;
    puVar4 = (undefined4 *)((int)pvVar2 + 0xcc8);
    do {
      FUN_004da200(pvVar2,iVar5,0);
      *puVar4 = 0x3c;
      iVar5 = iVar5 + 1;
      puVar4 = puVar4 + 1;
    } while (iVar5 < 6);
    break;
  case 0x22:
    pvVar2 = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),
                                  *(int *)((int)DAT_0057c670 + 0x2f4),(int *)0x0);
    iVar5 = FUN_00482820((int)DAT_0057c670);
    FUN_004da7c0(pvVar2,iVar5);
    break;
  case 0x23:
    iVar6 = *(int *)(param_1 + 0x88 + iVar5 * 4);
    if (iVar6 == 0) {
      iVar5 = Game_GetMostCommonTypeIndex
                        (*(int *)((int)DAT_0057c670 +
                                 *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200));
      if (-1 < iVar5) {
        *(int *)(param_1 + 0x88 + *(int *)(param_1 + 0x50) * 4) = (iVar5 * 5 + 5) * 20000;
      }
      break;
    }
LAB_005039d0:
    iVar6 = iVar6 + 1;
LAB_005039d1:
    *(int *)(param_1 + 0x88 + iVar5 * 4) = iVar6;
    break;
  case 0x24:
    iVar8 = -1;
    iVar6 = 0x14;
    iVar5 = FUN_00482820((int)DAT_0057c670);
    Game_ApplyPercentChange(DAT_0057c670,iVar5,iVar6,iVar8);
    break;
  case 0x27:
    pvVar2 = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),
                                  *(int *)((int)DAT_0057c670 + 0x2f4),(int *)0x0);
    iVar5 = FUN_00482820((int)DAT_0057c670);
    FUN_004db1d0(pvVar2,iVar5);
    break;
  case 0x28:
    iVar6 = 1;
    iVar5 = FUN_00482820((int)DAT_0057c670);
    FUN_0048c400(DAT_0057c670,(undefined4 *)0xa,iVar5,iVar6);
    break;
  case 0x2c:
    *(undefined4 *)(param_1 + 0x88 + iVar5 * 4) = 0x60;
    break;
  case 0x2f:
    iVar8 = 0;
    iVar5 = *(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200);
    iVar6 = *(int *)(iVar5 + 0x15c);
    if (0 < iVar6) {
      do {
        pvVar2 = (void *)FUN_004017f0((void *)(iVar5 + 0x148),iVar8,(int *)0x0);
        iVar3 = Game_CountObjectsByType(pvVar2,0xffffffff);
        iVar9 = 0;
        if (0 < iVar3) {
          do {
            puVar4 = (undefined4 *)FUN_004017f0((void *)((int)pvVar2 + 0x1500),iVar9,(int *)0x0);
            iVar7 = (*(int *)((int)*puVar4 + 0xc) * 0xc) / 10;
            if (100 < iVar7) {
              iVar7 = 100;
            }
            FUN_004d4120((void *)*puVar4,iVar7);
            iVar9 = iVar9 + 1;
          } while (iVar9 < iVar3);
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < iVar6);
    }
  }
  iVar5 = *(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  *(int *)(iVar5 + 0xfc) = *(int *)(iVar5 + 0xfc) + 1;
  iVar5 = FUN_004ddcc0(*(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200)
                      );
  *(int *)(iVar5 + 0x2c) = *(int *)(iVar5 + 0x2c) + 1;
  if (*(void **)((int)DAT_0057c670 + 0x264) != (void *)0x0) {
    FUN_005301c0(*(void **)((int)DAT_0057c670 + 0x264),-0x18616,0x23,0);
  }
  return;
}

