// rea decompile_all
// name: FUN_0052a440
// address: 0x52a440
// body: available
// range: 0x52a440-0x52aaf4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_0052a440(int param_1)

{
  void *pvVar1;
  double dVar2;
  int iVar3;
  undefined4 *this;
  FILE *pFVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  int iVar9;
  uint uVar10;
  longlong lVar11;
  uint **ppuVar12;
  uint **ppuVar13;
  uint uStack_b8;
  uint *local_b4;
  uint *local_b0;
  uint local_ac;
  uint local_a8;
  int local_a4;
  int local_a0;
  char local_9c [16];
  int local_8c;
  int local_88;
  int iStack_84;
  double dStack_80;
  double dStack_78;
  double dStack_70;
  int local_68;
  uint uStack_64;
  int iStack_60;
  int iStack_5c;
  int iStack_58;
  int iStack_54;
  uint uStack_50;
  undefined4 uStack_4c;
  uint uStack_48;
  undefined4 uStack_44;
  double dStack_40;
  uint uStack_38;
  undefined4 uStack_34;
  double dStack_30;
  uint uStack_28;
  undefined4 uStack_24;
  double dStack_20;
  uint uStack_18;
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 uStack_c;
  
  local_9c[1] = 0xfe;
  local_9c[4] = 0xfe;
  local_9c[5] = 2;
  local_9c[8] = 2;
  local_9c[0] = '\0';
  local_9c[2] = 1;
  local_9c[3] = 0xff;
  local_9c[6] = 0xfd;
  local_9c[7] = 3;
  local_9c[9] = 0;
  local_9c[10] = 1;
  local_9c[0xb] = 0xff;
  local_9c[0xc] = 0xfc;
  local_9c[0xd] = 4;
  local_9c[0xe] = 0xfd;
  local_9c[0xf] = 3;
  local_ac = 0;
  local_a8 = 999999;
  local_68 = param_1;
  this = FUN_00539ea0(DAT_0057c5c8);
  pvVar1 = *(void **)(param_1 + 0x344);
  if (*(char *)((int)pvVar1 + 0x39) == '\0') {
    FUN_0053cea0(pvVar1);
  }
  FUN_00539280(this,*(undefined4 *)((int)pvVar1 + 0x2c),
               (ushort)((int)*(short *)((int)pvVar1 + 6) >> 1),*(ushort *)((int)pvVar1 + 8),
               (int)*(short *)((int)pvVar1 + 6));
  FUN_0053d6c0(*(void **)(param_1 + 0x344),-1);
  FUN_0053d570(*(void **)(param_1 + 0x120),(int)this,(uint *)0x0,0);
  Sprite_GetSize(*(void **)(param_1 + 0x120),(int *)&local_b0,(int *)&local_b4);
  Sprite_GetSize(*(void **)(param_1 + 0x164),&local_a4,&local_a0);
  Sprite_GetSize(*(void **)(param_1 + 0x1a8),&local_88,&local_8c);
  if (*(int *)(param_1 + 0xc0) == 0) {
    FUN_0053d570(*(void **)(param_1 + 0x1a8),(int)this,(uint *)(*(int *)(param_1 + 200) - local_a4),
                 0);
    Surface_SetBounds(this,(int)local_b0,0,*(int *)(param_1 + 200) - local_88,local_a0);
    if ((0 < local_a4) && (puVar8 = local_b0, (int)local_b0 < *(int *)(param_1 + 200) - local_88)) {
      do {
        FUN_0053d570(*(void **)(param_1 + 0x164),(int)this,puVar8,0);
        puVar8 = (uint *)((int)puVar8 + local_a4);
      } while ((int)puVar8 < *(int *)(param_1 + 200) - local_88);
    }
  }
  else {
    FUN_0053d570(*(void **)(param_1 + 0x1a8),(int)this,(uint *)0x0,
                 *(int *)(param_1 + 200) - local_a0);
    Surface_SetBounds(this,0,(int)local_b4,local_a4,*(int *)(param_1 + 200) - local_8c);
    if ((0 < local_a0) && (puVar8 = local_b4, (int)local_b4 < *(int *)(param_1 + 200) - local_8c)) {
      do {
        FUN_0053d570(*(void **)(param_1 + 0x164),(int)this,(uint *)0x0,(int)puVar8);
        puVar8 = (uint *)((int)puVar8 + local_a0);
      } while ((int)puVar8 < *(int *)(param_1 + 200) - local_8c);
    }
  }
  if (this != (undefined4 *)0x0) {
    (**(code **)*this)(1);
  }
  if (*(int *)(param_1 + 0xc0) == 0) {
    ppuVar13 = &local_b0;
    ppuVar12 = &local_b4;
  }
  else {
    ppuVar13 = &local_b4;
    ppuVar12 = &local_b0;
  }
  Sprite_GetSize(*(void **)(param_1 + 0x344),(int *)ppuVar12,(int *)ppuVar13);
  if (*(int *)(param_1 + 0xd8) == -0x1000000) {
    uVar10 = *(uint *)(param_1 + 0xdc);
    uVar6 = *(uint *)(param_1 + 0xd4);
    *(uint *)(param_1 + 0xd8) =
         ((uVar6 & 0xff) + (uVar10 & 0xff) >> 1) +
         ((uVar6 & 0xff0000) + (uVar10 & 0xff0000) >> 1 & 0xff0000) +
         ((uVar6 & 0xff00) + (uVar10 & 0xff00) >> 1 & 0xff00);
  }
  iStack_84 = FUN_0053d480(*(void **)(param_1 + 0x344));
  Color_RGBTo16(DAT_0057c5c8,0xff,0,0xff);
  uStack_64 = Sprite_GetColorKey(*(int *)(param_1 + 0x344));
  pFVar4 = (FILE *)FUN_0054dfe0(s_C__test_spr_00574318,&DAT_00563114);
  FUN_0053d160(*(void **)(param_1 + 0x344),(int)DAT_0057c5c8,(int *)pFVar4,(void *)0x0);
  FUN_0054dee4(pFVar4);
  uVar10 = 0;
  puVar8 = local_b4;
  if ((int)local_b4 < 1) {
LAB_0052aad6:
    *(uint *)(param_1 + 0xa8) = local_a8;
    *(uint *)(param_1 + 0xa4) = (local_ac - local_a8) + 1;
    return;
  }
LAB_0052a762:
  if (uVar10 == 0) {
    uStack_28 = *(uint *)(param_1 + 0xd4);
    uStack_34 = 0;
    uStack_c = 0;
    uStack_38 = uStack_28 >> 0x10 & 0xff;
    uStack_24 = 0;
    dStack_80 = (double)uStack_38;
    uStack_10 = uStack_28 >> 8 & 0xff;
    uStack_28 = uStack_28 & 0xff;
    dStack_70 = (double)uStack_10;
    uVar6 = *(uint *)(param_1 + 0xd8);
    dVar2 = (double)(uVar6 >> 0x10 & 0xff) - dStack_80;
    dStack_40 = (dVar2 + dVar2) / (double)(int)local_b4;
    dVar2 = (double)(uVar6 >> 8 & 0xff) - dStack_70;
    dStack_30 = (dVar2 + dVar2) / (double)(int)local_b4;
    uVar5 = uStack_28;
LAB_0052a903:
    dStack_78 = (double)uVar5;
    dVar2 = (double)(uVar6 & 0xff) - dStack_78;
    dStack_20 = (dVar2 + dVar2) / (double)(int)local_b4;
  }
  else if (uVar10 == (int)puVar8 / 2) {
    uStack_48 = *(uint *)(param_1 + 0xd8);
    uStack_4c = 0;
    uStack_14 = 0;
    uStack_50 = uStack_48 >> 0x10 & 0xff;
    uStack_44 = 0;
    dStack_80 = (double)uStack_50;
    uStack_18 = uStack_48 >> 8 & 0xff;
    uStack_48 = uStack_48 & 0xff;
    dStack_70 = (double)uStack_18;
    uVar6 = *(uint *)(param_1 + 0xdc);
    dVar2 = (double)(uVar6 >> 0x10 & 0xff) - dStack_80;
    dStack_40 = (dVar2 + dVar2) / (double)(int)local_b4;
    dVar2 = (double)(uVar6 >> 8 & 0xff) - dStack_70;
    dStack_30 = (dVar2 + dVar2) / (double)(int)local_b4;
    uVar5 = uStack_48;
    goto LAB_0052a903;
  }
  uStack_b8 = 0;
  if (0 < (int)local_b0) {
    lVar11 = __ftol();
    iStack_58 = (int)lVar11;
    lVar11 = __ftol();
    iStack_60 = (int)lVar11;
    iVar9 = (uVar10 & 3) << 2;
    iStack_54 = iVar9;
    lVar11 = __ftol();
    iStack_5c = (int)lVar11;
    do {
      iVar3 = iStack_84;
      iVar9 = (int)local_9c[(uStack_b8 & 3) + iVar9];
      uVar6 = iStack_58 + iVar9;
      if ((int)uVar6 < 0) {
        uVar6 = 0;
      }
      else if (0xff < (int)uVar6) {
        uVar6 = 0xff;
      }
      iVar7 = iStack_60 + iVar9;
      if (iVar7 < 0) {
        iVar7 = 0;
      }
      else if (0xff < iVar7) {
        iVar7 = 0xff;
      }
      iVar9 = iVar9 + iStack_5c;
      if (iVar9 < 0) {
        iVar9 = 0;
      }
      else if (0xff < iVar9) {
        iVar9 = 0xff;
      }
      if (*(int *)(param_1 + 0xc0) == 0) {
        if (*(ushort *)(iStack_84 + (uStack_b8 * (int)local_b4 + uVar10) * 2) == uStack_64)
        goto LAB_0052aa83;
        uVar6 = Color_RGBTo16(DAT_0057c5c8,(byte)iVar9,(byte)iVar7,uVar6);
        *(short *)(iVar3 + (uStack_b8 * (int)local_b4 + uVar10) * 2) = (short)uVar6;
        if ((int)uVar10 < (int)local_a8) {
          local_a8 = uVar10;
        }
        if ((int)local_ac < (int)uVar10) {
          local_ac = uVar10;
        }
      }
      else if (*(ushort *)
                (iStack_84 + (((int)local_b4 + (-1 - uVar10)) * (int)local_b0 + uStack_b8) * 2) ==
               uStack_64) {
LAB_0052aa83:
      }
      else {
        uVar6 = Color_RGBTo16(DAT_0057c5c8,(byte)iVar9,(byte)iVar7,uVar6);
        *(short *)(iVar3 + (((int)local_b4 + (-1 - uVar10)) * (int)local_b0 + uStack_b8) * 2) =
             (short)uVar6;
        uVar6 = (int)local_b4 + (-1 - uVar10);
        if ((int)uVar6 < (int)local_a8) {
          local_a8 = uVar6;
        }
        if ((int)local_ac < (int)uVar6) {
          local_ac = uVar6;
        }
      }
      uStack_b8 = uStack_b8 + 1;
      param_1 = local_68;
      if ((int)local_b0 <= (int)uStack_b8) goto code_r0x0052aa98;
      iVar9 = iStack_54;
    } while( true );
  }
  goto LAB_0052aaa0;
code_r0x0052aa98:
  puVar8 = local_b4;
LAB_0052aaa0:
  dStack_80 = dStack_40 + dStack_80;
  uVar10 = uVar10 + 1;
  dStack_70 = dStack_30 + dStack_70;
  dStack_78 = dStack_20 + dStack_78;
  if ((int)puVar8 <= (int)uVar10) goto LAB_0052aad6;
  goto LAB_0052a762;
}

