// rea decompile_all
// name: FUN_004773a0
// address: 0x4773a0
// body: available
// range: 0x4773a0-0x477839 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004773a0(void *this,int param_1)

{
  char cVar1;
  int *piVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  undefined3 extraout_var;
  void *pvVar6;
  undefined3 extraout_var_00;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  uint extraout_EDX;
  uint extraout_EDX_00;
  uint extraout_EDX_01;
  uint extraout_EDX_02;
  uint uVar10;
  undefined4 unaff_ESI;
  undefined8 uVar11;
  int local_8;
  
  uVar4 = FUN_00488d90((int)DAT_0057c670);
  if (param_1 % 3 == 0) {
    FUN_0047ef30(this,param_1);
  }
  if (*(char *)((int)this + 0x16f5) == '\0') {
    cVar1 = *(char *)((int)this + 0x1a1f);
    iVar5 = 0x17;
    for (iVar9 = 0x1e; (cVar1 != '\0' && (0 < iVar9)); iVar9 = iVar9 + -1) {
      iVar5 = iVar5 + 1;
      if (0x17 < iVar5) {
        iVar5 = 0;
      }
      cVar1 = *(char *)(iVar5 + 0x1a08 + (int)this);
    }
    cVar1 = *(char *)(iVar5 + 0x1a08 + (int)this);
    while (cVar1 == '\0') {
      if (iVar9 < 1) goto LAB_00477452;
      iVar5 = iVar5 + 1;
      if (0x17 < iVar5) {
        iVar5 = 0;
      }
      iVar9 = iVar9 + -1;
      cVar1 = *(char *)(iVar5 + 0x1a08 + (int)this);
    }
    if ((0 < iVar9) && (iVar5 == param_1)) {
      puVar7 = (undefined4 *)((int)this + 0x1898);
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
      }
      puVar7 = (undefined4 *)((int)this + 0x18d8);
      for (iVar5 = 0x30; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
      }
    }
LAB_00477452:
    if (*(char *)(param_1 + 0x1a08 + (int)this) == '\0') {
      iVar5 = param_1 + 1;
      if (0x17 < iVar5) {
        iVar5 = 0;
      }
      if (*(char *)(iVar5 + 0x1a08 + (int)this) == '\0') {
        iVar5 = iVar5 + 1;
        if (0x17 < iVar5) {
          iVar5 = 0;
        }
        if (*(char *)(iVar5 + 0x1a08 + (int)this) == '\0') {
          FUN_004fe420(*(void **)((int)DAT_0057c670 + 0x90),this);
        }
      }
    }
    FUN_00477190(this);
    FUN_0047f210(this);
    uVar3 = FUN_0047e470(this,0);
    if (CONCAT31(extraout_var,uVar3) == 0) {
      iVar5 = FUN_00477360((int)this);
      if ((iVar5 == 0) && (iVar5 = FUN_00480050((int)this), 0 < iVar5)) {
        pvVar6 = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),
                                      *(int *)((int)DAT_0057c670 + 0x2f4),(int *)0x0);
        FUN_004d5360(pvVar6,(int)this);
      }
    }
    else {
      uVar3 = FUN_0047e470(this,0);
      if ((CONCAT31(extraout_var_00,uVar3) != 0) && (iVar5 = FUN_00477360((int)this), iVar5 != 0)) {
        *(undefined1 *)(iVar5 + 0x81) = 1;
      }
    }
    iVar5 = *(int *)((int)this + 0x1514);
    local_8 = 0;
    if (0 < iVar5) {
      do {
        puVar7 = (undefined4 *)FUN_004017f0((void *)((int)this + 0x1500),local_8,(int *)0x0);
        piVar2 = (int *)*puVar7;
        if (piVar2 != (int *)0x0) {
          uVar11 = Game_GetRecordByField814((int)piVar2);
          uVar10 = (uint)((ulonglong)uVar11 >> 0x20);
          pvVar6 = (void *)uVar11;
          iVar9 = puVar7[1];
          if (iVar9 != -1) {
            if (*(char *)((int)pvVar6 + 0x80) == '\0') {
              if ((*(char *)((int)pvVar6 + 0x104) != '\0') && (*(int *)((int)pvVar6 + 0x7c) == 0xff)
                 ) {
                FUN_0050e2a0((int)pvVar6,uVar10,0,'\x01');
                uVar10 = extraout_EDX;
              }
              if (*(char *)((int)pvVar6 + 0x80) != '\0') goto LAB_0047758b;
LAB_0047768e:
              if (*(int *)((int)pvVar6 + 0x74) != 0) goto LAB_00477695;
            }
            else {
LAB_0047758b:
              if (*(int *)((int)pvVar6 + 0x7c) != 0xff) goto LAB_0047768e;
              if (*(int *)((int)pvVar6 + 0x74) == 0) {
                iVar8 = AI_IsDirectionOnRoute(this,piVar2,(param_1 + 2) / 3 & 7);
                uVar10 = extraout_EDX_00;
                if (iVar8 != 0) {
                  if (*(int *)((int)pvVar6 + 0x108) != 1) {
                    FUN_0050e2a0((int)pvVar6,extraout_EDX_00,(int)this,'\0');
                    FUN_00507e20(pvVar6,1,*(int *)((int)this + 0x16f0));
                    FUN_0054a660(DAT_0057c1e0,0xa000,(byte *)s__s_geht_zur_Arbeit_00567bac,
                                 (int)pvVar6 + 4);
                    *(uint *)((int)pvVar6 + 0x7c) = iVar9 + 3U & 7;
                    switch((char)piVar2[0x209]) {
                    case '\0':
                      FUN_00477e40(this,6,(float)piVar2[0xf],'\0',-1);
                      break;
                    case '\x01':
                      FUN_00477e40(this,8,(float)piVar2[0xf],'\0',-1);
                      break;
                    case '\x02':
                      FUN_00477e40(this,7,(float)piVar2[0xf],'\0',-1);
                      break;
                    case '\x03':
                      FUN_00477e40(this,0xd,(float)piVar2[0xf],'\0',-1);
                    }
                  }
                  goto switchD_00477623_default;
                }
                goto LAB_0047768e;
              }
LAB_00477695:
              iVar9 = AI_IsDirectionOnRoute(this,piVar2,uVar4 & 7);
              uVar10 = extraout_EDX_01;
              if (iVar9 == 0) {
                iVar9 = AI_IsDirectionOnRoute(this,piVar2,uVar4 + 1 & 7);
                uVar10 = extraout_EDX_02;
                if (iVar9 == 0) {
                  FUN_0050e2a0((int)pvVar6,extraout_EDX_02,(int)this,'\x01');
                  uVar10 = uVar4 + 1 & 0x80000007;
                  if ((int)uVar10 < 0) {
                    uVar10 = (uVar10 - 1 | 0xfffffff8) + 1;
                  }
                  *(uint *)((int)pvVar6 + 0x7c) = uVar10;
                  FUN_00549970(DAT_0057ba0c,(int)this,*(int *)((int)pvVar6 + 0x30),5,
                               *(int *)((int)pvVar6 + 0x24) == 0);
                  goto switchD_00477623_default;
                }
              }
            }
            if (*(uint *)((int)pvVar6 + 0x7c) == uVar4) {
              if (*(char *)((int)pvVar6 + 0x80) == '\0') {
                FUN_0050e2a0((int)pvVar6,uVar10,(int)this,'\x01');
              }
              else if (*(uint *)((int)pvVar6 + 0x7c) != uVar4) goto switchD_00477623_default;
              *(undefined4 *)((int)pvVar6 + 0x7c) = 0xff;
            }
          }
        }
switchD_00477623_default:
        local_8 = local_8 + 1;
      } while (local_8 < iVar5);
    }
  }
  if (*(int *)((int)this + 0x187c) == 0) {
    *(undefined4 *)((int)this + 0x14bc) = 0;
  }
  else {
    *(int *)((int)this + 0x14bc) = *(int *)((int)this + 0x14bc) + 1;
  }
  iVar5 = FUN_0047fed0((int)this);
  if (iVar5 == 0) {
    *(undefined4 *)((int)this + 0x14b8) = 0;
  }
  else {
    *(int *)((int)this + 0x14b8) = *(int *)((int)this + 0x14b8) + 1;
  }
  iVar5 = FUN_00482820((int)DAT_0057c670);
  if (*(int *)((int)this + 0x30) == iVar5) {
    if ((*(int *)((int)this + 0x14bc) == 0x18) && (iVar5 = FUN_0048c000(DAT_0057c670,3), iVar5 == 0)
       ) {
      iVar5 = FUN_0048bf90((int)DAT_0057c670,-1,5,4,10,*(int *)((int)this + 0x16f0),DAT_00582944,
                           DAT_00581ff0,unaff_ESI);
      FUN_0048c040(DAT_0057c670,iVar5,3);
    }
    if ((*(int *)((int)this + 0x14b8) == 0x18) && (iVar5 = FUN_0048c000(DAT_0057c670,4), iVar5 == 0)
       ) {
      iVar5 = FUN_0048bf90((int)DAT_0057c670,-1,5,4,10,*(int *)((int)this + 0x16f0),DAT_0058112c,
                           DAT_00580ee8,unaff_ESI);
      FUN_0048c040(DAT_0057c670,iVar5,4);
    }
  }
  FUN_004805d0(this);
  return;
}

