// rea decompile_all
// name: FUN_005301f0
// address: 0x5301f0
// body: available
// range: 0x5301f0-0x530a54 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_005301f0(int param_1)

{
  short sVar1;
  short *psVar2;
  undefined1 uVar3;
  undefined3 extraout_var;
  int iVar4;
  short *psVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  void *pvVar11;
  int iVar12;
  uint uVar13;
  char *pcVar14;
  uint *puVar15;
  int iStack_50;
  char *pcStack_4c;
  uint local_48;
  uint *local_44;
  uint local_40;
  uint local_3c;
  int iStack_38;
  uint local_34;
  uint local_30;
  int local_2c;
  int local_28;
  char *pcStack_24;
  char *local_20;
  tagRECT local_1c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0055ab56;
  local_c = ExceptionList;
  if ((*(int *)(param_1 + 0x138) != 0) && (*(int *)(param_1 + 0x168) == 0)) {
    return;
  }
  pvVar11 = *(void **)(param_1 + 0x50);
  if (pvVar11 == (void *)0x0) {
    if (*(int *)(param_1 + 0x168) == 0) {
      return;
    }
  }
  else if ((*(int *)(param_1 + 0x94) != 0) && (*(int *)(param_1 + 0x168) == 0)) {
    ExceptionList = &local_c;
    uVar3 = FUN_0053d420(*(int *)(param_1 + 0x94));
    if (CONCAT31(extraout_var,uVar3) != 0) {
      iVar4 = FUN_0053d430(*(int *)(param_1 + 0x94));
      FUN_0053d440(*(void **)(param_1 + 0x50),iVar4);
      FUN_0053d6c0(*(void **)(param_1 + 0x50),iVar4);
    }
    FUN_0053d570(*(void **)(param_1 + 0x94),*(int *)(param_1 + 0xdc),(uint *)0x0,0);
    ExceptionList = local_c;
    return;
  }
  if (*(int *)(param_1 + 0x168) == 0) {
    if ((*(int *)(param_1 + 0x10c) != 1) && (*(int *)(param_1 + 0xe4) != 0)) {
      ExceptionList = &local_c;
      FUN_00530a60(param_1);
      goto LAB_005308a8;
    }
    ExceptionList = &local_c;
    if (pvVar11 == (void *)0x0) goto LAB_005308a8;
    ExceptionList = &local_c;
    iVar4 = FUN_00539840(DAT_0057c5c8,*(uint *)(param_1 + 0xfc));
    pvVar11 = *(void **)(param_1 + 0x50);
  }
  else {
    if ((0 < *(int *)(param_1 + 0x170)) && (0 < *(int *)(param_1 + 0x174))) {
      local_1c.left = (LONG)**(short **)(param_1 + 0x15c);
      local_1c.top = (LONG)(*(short **)(param_1 + 0x15c))[1];
      ExceptionList = &local_c;
      FUN_0053d040(*(void **)(*(int *)(param_1 + 0x160) + 0x148),&local_40,&local_3c);
      iVar4 = local_40 + local_1c.left;
      iVar12 = local_3c + local_1c.top;
      iVar8 = local_1c.top;
      local_1c.right = iVar4;
      local_1c.bottom = iVar12;
      if (1 < *(int *)(param_1 + 0x170)) {
        local_20 = (char *)(*(int *)(param_1 + 0x170) + -1);
        psVar2 = *(short **)(param_1 + 0x15c);
        do {
          psVar5 = psVar2 + 3;
          if (*psVar5 < local_1c.left) {
            local_1c.left = (int)*psVar5;
          }
          iVar9 = (int)psVar2[4];
          if (iVar9 < iVar8) {
            iVar8 = iVar9;
            local_1c.top = iVar9;
          }
          iVar9 = (int)*psVar5 + local_40;
          if (iVar4 < iVar9) {
            iVar4 = iVar9;
            local_1c.right = iVar9;
          }
          iVar9 = (int)psVar2[4] + local_3c;
          if (iVar12 < iVar9) {
            iVar12 = iVar9;
            local_1c.bottom = iVar9;
          }
          local_20 = (char *)((int)local_20 + -1);
          psVar2 = psVar5;
        } while (local_20 != (char *)0x0);
        local_20 = (char *)0x0;
      }
      local_48 = iVar12 - iVar8;
      local_44 = (uint *)(iVar4 - local_1c.left);
      if ((0 < (int)local_44) && (0 < (int)local_48)) {
        if ((*(void **)(param_1 + 0x94) != (void *)0x0) &&
           (FUN_0053d040(*(void **)(param_1 + 0x94),&local_34,&local_30),
           (local_34 != (int)local_44 << ((byte)local_30 & 0x1f)) != local_48)) {
          if (*(char *)(param_1 + 0x54) == '\0') {
            if (*(undefined4 **)(param_1 + 0x94) != (undefined4 *)0x0) {
              (**(code **)**(undefined4 **)(param_1 + 0x94))(1);
            }
          }
          else {
            FUN_005277d0(*(void **)(param_1 + 0x134),(byte *)(param_1 + 0x54));
          }
          if (*(undefined4 **)(param_1 + 0x50) != (undefined4 *)0x0) {
            (**(code **)**(undefined4 **)(param_1 + 0x50))(1);
          }
          *(undefined4 *)(param_1 + 0x50) = 0;
          *(undefined4 *)(param_1 + 0x94) = 0;
          *(byte *)(param_1 + 0x54) = 0;
        }
        if (*(int *)(param_1 + 0x94) == 0) {
          local_20 = operator_new(0x50);
          uStack_4 = 0;
          if (local_20 == (void *)0x0) {
            puVar6 = (undefined4 *)0x0;
          }
          else {
            puVar6 = FUN_0053c710(local_20,(uint)local_44,local_48,2,0x10,0);
          }
          uStack_4 = 0xffffffff;
          *(undefined4 **)(param_1 + 0x94) = puVar6;
          *(undefined1 *)(param_1 + 0x54) = 0;
          local_20 = operator_new(0x50);
          uStack_4 = 1;
          if (local_20 == (char *)0x0) {
            puVar6 = (undefined4 *)0x0;
          }
          else {
            puVar6 = FUN_0053c710(local_20,(uint)local_44,local_48,2,0x10,0);
          }
          pvVar11 = *(void **)(param_1 + 0xdc);
          *(undefined4 **)(param_1 + 0x50) = puVar6;
          uStack_4 = 0xffffffff;
          if (*(char *)((int)puVar6 + 0x39) == '\0') {
            FUN_0053cea0(puVar6);
          }
          FUN_00539280(pvVar11,puVar6[0xb],(ushort)((int)*(short *)((int)puVar6 + 6) >> 1),
                       *(ushort *)(puVar6 + 2),(int)*(short *)((int)puVar6 + 6));
        }
        uVar7 = FUN_00539840(DAT_0057c5c8,0xff00);
        FUN_0053d440(*(void **)(param_1 + 0x94),uVar7);
        uVar7 = FUN_00539840(DAT_0057c5c8,0xff00);
        FUN_0053d440(*(void **)(param_1 + 0x50),uVar7);
        if (*(int *)(param_1 + 0xe4) == 0) {
          FUN_0053d6c0(*(void **)(param_1 + 0x50),-1);
        }
        else if (*(int *)(param_1 + 0x10c) == 1) {
          iVar4 = FUN_00539840(DAT_0057c5c8,*(uint *)(param_1 + 0xfc));
          FUN_0053d6c0(*(void **)(param_1 + 0x50),iVar4);
        }
        else {
          FUN_00530a60(param_1);
        }
        FUN_0053d6c0(*(void **)(param_1 + 0x94),-1);
        iVar4 = (int)local_44 / (int)local_40;
        iStack_38 = (int)local_48 / (int)local_3c;
        if (*(int *)(param_1 + 0xe4) == 0) {
          pcStack_4c = (char *)0x0;
        }
        else {
          uVar13 = iStack_38 * iVar4;
          pcStack_4c = operator_new(uVar13);
          pcVar14 = pcStack_4c;
          for (uVar10 = uVar13 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
            pcVar14[0] = '\0';
            pcVar14[1] = '\0';
            pcVar14[2] = '\0';
            pcVar14[3] = '\0';
            pcVar14 = pcVar14 + 4;
          }
          for (uVar13 = uVar13 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
            *pcVar14 = '\0';
            pcVar14 = pcVar14 + 1;
          }
        }
        iStack_50 = 0;
        if (0 < *(int *)(param_1 + 0x170)) {
          local_20 = (char *)0x0;
          do {
            iVar12 = *(int *)(param_1 + 0x15c);
            sVar1 = *(short *)(local_20 + iVar12 + 2);
            puVar15 = (uint *)(*(short *)(local_20 + iVar12) - local_1c.left);
            pcStack_24 = (char *)((int)puVar15 / (int)local_40);
            iVar8 = (sVar1 - local_1c.top) / (int)local_3c;
            if ((((pcStack_4c != (char *)0x0) && (-1 < (int)pcStack_24)) && (-1 < iVar8)) &&
               (((int)pcStack_24 < iVar4 && (iVar8 < iStack_38)))) {
              (pcStack_24 + iVar8 * iVar4)[(int)pcStack_4c] = '\x02';
            }
            FUN_0053d570(*(void **)(*(int *)(param_1 + 0x160) + 0x148 +
                                   (uint)*(byte *)((int)(local_20 + iVar12) + 4) * 0x14c),
                         *(int *)(param_1 + 0xdc),puVar15,sVar1 - local_1c.top);
            iStack_50 = iStack_50 + 1;
            local_20 = local_20 + 6;
          } while (iStack_50 < *(int *)(param_1 + 0x170));
        }
        if (*(void **)(param_1 + 0xd8) != (void *)0x0) {
          FUN_0053d570(*(void **)(param_1 + 0xd8),*(int *)(param_1 + 0xdc),(uint *)0x0,0);
        }
        iVar12 = iStack_38;
        if (*(int *)(param_1 + 0x13c) == 0) {
          *(int *)(param_1 + 8) = *(int *)(param_1 + 0x28);
          *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0x2c);
          *(int *)(param_1 + 0x10) = (*(int *)(param_1 + 0x28) - local_1c.left) + local_1c.right;
          *(int *)(param_1 + 0x14) = (*(int *)(param_1 + 0x2c) - local_1c.top) + local_1c.bottom;
        }
        else {
          *(undefined4 *)(param_1 + 8) = 0;
          *(undefined4 *)(param_1 + 0xc) = 0;
          *(undefined4 *)(param_1 + 0x10) = 800;
          *(undefined4 *)(param_1 + 0x14) = 600;
        }
        *(LONG *)(param_1 + 0x140) = local_1c.left;
        *(LONG *)(param_1 + 0x144) = local_1c.top;
        *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 8);
        *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0xc);
        *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x10);
        *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x14);
        if (*(int *)(param_1 + 0xe4) != 0) {
          iStack_50 = 0;
          if (0 < iVar4) {
            local_20 = pcStack_4c + (iStack_38 + -1) * iVar4;
            do {
              if (pcStack_4c[iStack_50] == '\0') {
                FUN_00531e10((int)pcStack_4c,iStack_50,0,iVar4,iVar12);
              }
              if (local_20[iStack_50] == '\0') {
                FUN_00531e10((int)pcStack_4c,iStack_50,iVar12 + -1,iVar4,iVar12);
              }
              iStack_50 = iStack_50 + 1;
            } while (iStack_50 < iVar4);
          }
          iStack_50 = 0;
          if (0 < iVar12) {
            pcStack_24 = pcStack_4c;
            do {
              if (*pcStack_24 == '\0') {
                FUN_00531e10((int)pcStack_4c,0,iStack_50,iVar4,iVar12);
              }
              if (pcStack_24[iVar4 + -1] == '\0') {
                FUN_00531e10((int)pcStack_4c,iVar4 + -1,iStack_50,iVar4,iVar12);
              }
              iStack_50 = iStack_50 + 1;
              pcStack_24 = pcStack_24 + iVar4;
            } while (iStack_50 < iVar12);
          }
          iVar12 = 0;
          if (0 < iVar4) {
            do {
              iVar8 = 0;
              if (0 < iStack_38) {
                local_20 = pcStack_4c + iVar12;
                do {
                  if (*local_20 == '\x01') {
                    SetRect(&local_1c,iVar12 * local_40,iVar8 * local_3c,(iVar12 + 1) * local_40,
                            (iVar8 + 1) * local_40);
                    Surface_FillClippedRect(*(void **)(param_1 + 0xdc),&local_1c.left,0xff00,1);
                  }
                  iVar8 = iVar8 + 1;
                  local_20 = local_20 + iVar4;
                } while (iVar8 < iStack_38);
              }
              iVar12 = iVar12 + 1;
            } while (iVar12 < iVar4);
          }
          if (pcStack_4c != (char *)0x0) {
            FUN_0054dd78(pcStack_4c);
          }
        }
      }
      goto LAB_005308a8;
    }
    ExceptionList = &local_c;
    if (pvVar11 != (void *)0x0) {
      ExceptionList = &local_c;
      FUN_0053d6c0(pvVar11,-1);
    }
    pvVar11 = *(void **)(param_1 + 0x94);
    if (pvVar11 == (void *)0x0) goto LAB_005308a8;
    iVar4 = -1;
  }
  FUN_0053d6c0(pvVar11,iVar4);
LAB_005308a8:
  if (*(void **)(param_1 + 0x50) != (void *)0x0) {
    FUN_0053d090(*(void **)(param_1 + 0x50),&local_28,&local_2c);
    if (*(void **)(param_1 + 0x114) != (void *)0x0) {
      FUN_0053d040(*(void **)(param_1 + 0x114),(uint *)&local_44,&local_48);
      FUN_0053d040(*(void **)(param_1 + 0x118),&local_34,&local_30);
      puVar15 = local_44;
      if ((int)local_44 < (int)(local_28 + local_34 * -2)) {
        do {
          FUN_0053d570(*(void **)(param_1 + 0x118),*(int *)(param_1 + 0xdc),puVar15,0);
          FUN_0053d570(*(void **)(param_1 + 0x128),*(int *)(param_1 + 0xdc),puVar15,
                       local_2c - local_30);
          puVar15 = (uint *)((int)puVar15 + local_34);
        } while ((int)puVar15 < (int)(local_28 + local_34 * -2));
      }
      uVar10 = local_48;
      if ((int)local_48 < (int)(local_2c + local_30 * -2)) {
        do {
          FUN_0053d570(*(void **)(param_1 + 0x130),*(int *)(param_1 + 0xdc),(uint *)0x0,uVar10);
          FUN_0053d570(*(void **)(param_1 + 0x120),*(int *)(param_1 + 0xdc),
                       (uint *)(local_28 - local_34),uVar10);
          uVar10 = uVar10 + local_30;
        } while ((int)uVar10 < (int)(local_2c + local_30 * -2));
      }
      FUN_0053d570(*(void **)(param_1 + 0x114),*(int *)(param_1 + 0xdc),(uint *)0x0,0);
      FUN_0053d570(*(void **)(param_1 + 0x11c),*(int *)(param_1 + 0xdc),
                   (uint *)(local_28 - (int)local_44),0);
      FUN_0053d570(*(void **)(param_1 + 300),*(int *)(param_1 + 0xdc),(uint *)0x0,
                   local_2c - local_48);
      FUN_0053d570(*(void **)(param_1 + 0x124),*(int *)(param_1 + 0xdc),
                   (uint *)(local_28 - (int)local_44),local_2c - local_48);
      uVar10 = FUN_005397e0(*(void **)(param_1 + 0xdc),0,0xff,0);
      FUN_0053d440(*(void **)(param_1 + 0x50),uVar10);
    }
  }
  ExceptionList = local_c;
  return;
}

