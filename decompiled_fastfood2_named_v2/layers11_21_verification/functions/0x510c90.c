// rea decompile_all
// name: Recipe_CreateGenerated
// address: 0x510c90
// body: available
// range: 0x510c90-0x511bba inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


byte * __thiscall
Recipe_CreateGenerated(void *this,int param_1,uint param_2,int param_3,float param_4,int param_5)

{
  float fVar1;
  byte bVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char cVar9;
  char *pcVar10;
  char *pcVar11;
  char *pcVar12;
  float *pfVar13;
  undefined4 *puVar14;
  float10 fVar15;
  longlong lVar16;
  longlong lVar17;
  ulonglong uVar18;
  float *pfVar19;
  byte bVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  int iVar23;
  undefined4 local_5c;
  undefined4 local_58;
  void *local_54;
  uint local_50;
  float *local_4c;
  void *local_48;
  float local_44 [7];
  float local_28 [7];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Creates a generated recipe with category amounts and Ingredients.tab. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a47b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_48 = this;
  FUN_004013a0((void *)((int)this + 0x48),0);
  local_4 = 0;
  *(undefined ***)this = &PTR_FUN_0055c698;
  *(undefined4 *)((int)this + 0x304) = 0;
  *(undefined1 *)((int)this + 0x1dc) = 0;
  *(undefined1 *)((int)this + 0x1dd) = 0;
  *(uint *)((int)this + 0x308) = param_2;
  pcVar12 = this;
  if (param_5 == 1) {
    pcVar10 = DAT_00582788;
LAB_00510d4c:
    uVar4 = 0xffffffff;
    do {
      pcVar11 = pcVar10;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar11 = pcVar10 + 1;
      cVar9 = *pcVar10;
      pcVar10 = pcVar11;
    } while (cVar9 != '\0');
    uVar4 = ~uVar4;
    pcVar10 = pcVar11 + -uVar4;
    for (uVar5 = uVar4 >> 2; pcVar12 = pcVar12 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar12 = *(undefined4 *)pcVar10;
      pcVar10 = pcVar10 + 4;
    }
LAB_00510d64:
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar12 = *pcVar10;
      pcVar10 = pcVar10 + 1;
      pcVar12 = pcVar12 + 1;
    }
  }
  else {
    if (param_5 == 2) {
      uVar4 = 0xffffffff;
      pcVar10 = DAT_005828ec;
      do {
        pcVar11 = pcVar10;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar11 = pcVar10 + 1;
        cVar9 = *pcVar10;
        pcVar10 = pcVar11;
      } while (cVar9 != '\0');
      uVar4 = ~uVar4;
      pcVar10 = pcVar11 + -uVar4;
      for (uVar5 = uVar4 >> 2; pcVar12 = pcVar12 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar12 = *(undefined4 *)pcVar10;
        pcVar10 = pcVar10 + 4;
      }
      goto LAB_00510d64;
    }
    if (param_5 == 3) {
      pcVar10 = DAT_0058207c;
      goto LAB_00510d4c;
    }
    FUN_0054dd83((undefined1 *)((int)this + 4),(byte *)s__s__s_00563314,DAT_005827a0);
  }
  FUN_00499f30(param_1,this,(char *)((int)this + 4));
  puVar14 = (undefined4 *)((int)this + 100);
  for (iVar6 = 0x56; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar14 = 0;
    puVar14 = puVar14 + 1;
  }
  puVar14 = (undefined4 *)((int)this + 0x1e0);
  for (iVar6 = 0x18; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar14 = 0;
    puVar14 = puVar14 + 1;
  }
  puVar14 = (undefined4 *)((int)this + 0x1bc);
  for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar14 = 0;
    puVar14 = puVar14 + 1;
  }
  FUN_0050fdf0((int)this);
  local_54 = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),(int)param_4,(int *)0x0);
  FUN_00488be0(DAT_0057c670,param_1);
  if (param_3 == 0) {
    iVar6 = 0x14;
  }
  else if (param_3 == 1) {
    iVar6 = 0x32;
  }
  else {
    iVar6 = 100;
  }
  piVar3 = FUN_00402290(DAT_0057c5d8,s_Ingredients_tab_00573ae0,0);
  *(int **)((int)this + 0x310) = piVar3;
  pfVar13 = local_44;
  for (iVar7 = 7; iVar7 != 0; iVar7 = iVar7 + -1) {
    *pfVar13 = 0.0;
    pfVar13 = pfVar13 + 1;
  }
  pfVar13 = local_28;
  for (iVar7 = 7; iVar7 != 0; iVar7 = iVar7 + -1) {
    *pfVar13 = 0.0;
    pfVar13 = pfVar13 + 1;
  }
  if (param_5 != -1) {
    FUN_00510c70(&local_58,&local_5c,0x43160000,0x43480000);
    lVar16 = __ftol();
    uVar4 = (uint)lVar16;
    lVar16 = __ftol();
    uVar4 = FUN_004034d0((int)lVar16,uVar4);
    param_4 = (float)(int)uVar4;
    if (param_5 == 1) {
      FUN_00510c70(local_28 + 3,local_44 + 3,0,0);
      FUN_00510c70(local_28 + 2,local_44 + 2,0x42200000,0x425c0000);
      FUN_00510c70(local_28 + 6,local_44 + 6,0,0x41200000);
      FUN_00510c70(local_28 + 1,local_44 + 1,0x41c80000,0x42200000);
      uVar22 = 0;
      goto LAB_00511774;
    }
    if ((param_5 < 2) || (3 < param_5)) goto switchD_00510e54_default;
    FUN_00510c70(local_28 + 3,local_44 + 3,0x41f00000,0x42200000);
    FUN_00510c70(local_28 + 2,local_44 + 2,0x41a00000,0x41f00000);
    FUN_00510c70(local_28 + 6,local_44 + 6,0,0x41200000);
    FUN_00510c70(local_28 + 1,local_44 + 1,0x41a00000,0x41f00000);
    uVar22 = 0;
    uVar21 = 0;
    goto LAB_00511780;
  }
  uVar4 = FUN_004034d0(1,10);
  if ((int)uVar4 < 5) {
    cVar9 = ((int)uVar4 < 3) + '\x01';
  }
  else {
    cVar9 = '\0';
  }
  switch(param_2) {
  case 0:
    FUN_00510c70(&local_58,&local_5c,0x43490000,0x43fa0000);
    lVar16 = __ftol();
    uVar4 = (uint)lVar16;
    lVar16 = __ftol();
    uVar4 = FUN_004034d0((int)lVar16,uVar4);
    if (cVar9 == '\0') {
      uVar21 = 0x41f00000;
      pfVar13 = local_44 + 3;
      uVar22 = 0x41300000;
      pfVar19 = local_28 + 3;
LAB_0051106f:
      FUN_00510c70(pfVar19,pfVar13,uVar22,uVar21);
    }
    else {
      if (cVar9 == '\x01') {
        uVar21 = 0x41f00000;
        pfVar13 = local_44 + 4;
        uVar22 = 0x41300000;
        pfVar19 = local_28 + 4;
        goto LAB_0051106f;
      }
      if (cVar9 == '\x02') {
        FUN_00510c70(local_28 + 3,local_44 + 3,0x40c00000,0x41a00000);
        uVar21 = 0x41200000;
        pfVar13 = local_44 + 4;
        uVar22 = 0x40a00000;
        pfVar19 = local_28 + 4;
        goto LAB_0051106f;
      }
    }
    uVar21 = 0x425c0000;
    uVar22 = 0x41f80000;
    goto LAB_00511080;
  case 1:
    FUN_00510c70(&local_58,&local_5c,0x43490000,0x43fa0000);
    lVar16 = __ftol();
    uVar4 = (uint)lVar16;
    lVar16 = __ftol();
    uVar4 = FUN_004034d0((int)lVar16,uVar4);
    if (cVar9 == '\0') {
      uVar21 = 0x41f00000;
      pfVar13 = local_44 + 3;
      uVar22 = 0x41300000;
      pfVar19 = local_28 + 3;
LAB_00511164:
      FUN_00510c70(pfVar19,pfVar13,uVar22,uVar21);
    }
    else {
      if (cVar9 == '\x01') {
        uVar21 = 0x41f00000;
        pfVar13 = local_44 + 4;
        uVar22 = 0x41300000;
        pfVar19 = local_28 + 4;
        goto LAB_00511164;
      }
      if (cVar9 == '\x02') {
        FUN_00510c70(local_28 + 3,local_44 + 3,0x40c00000,0x41a00000);
        uVar21 = 0x41200000;
        pfVar13 = local_44 + 4;
        uVar22 = 0x40a00000;
        pfVar19 = local_28 + 4;
        goto LAB_00511164;
      }
    }
    FUN_00510c70(local_28 + 2,local_44 + 2,0x41f80000,0x420c0000);
    FUN_00510c70(local_28 + 6,local_44 + 6,0,0x40a00000);
    uVar21 = 0x41200000;
    uVar22 = 0x41000000;
    goto LAB_00511454;
  case 2:
    FUN_00510c70(&local_58,&local_5c,0x43160000,0x43fa0000);
    lVar16 = __ftol();
    uVar4 = (uint)lVar16;
    lVar16 = __ftol();
    uVar4 = FUN_004034d0((int)lVar16,uVar4);
    param_4 = (float)(int)uVar4;
    if (cVar9 == '\0') {
      uVar22 = 0x41200000;
      pfVar13 = local_44 + 3;
      pfVar19 = local_28 + 3;
LAB_0051124d:
      FUN_00510c70(pfVar19,pfVar13,0,uVar22);
    }
    else {
      if (cVar9 == '\x01') {
        uVar22 = 0x41200000;
        pfVar13 = local_44 + 4;
        pfVar19 = local_28 + 4;
        goto LAB_0051124d;
      }
      if (cVar9 == '\x02') {
        FUN_00510c70(local_28 + 3,local_44 + 3,0,0x40a00000);
        uVar22 = 0x40a00000;
        pfVar13 = local_44 + 4;
        pfVar19 = local_28 + 4;
        goto LAB_0051124d;
      }
    }
    FUN_00510c70(local_28 + 2,local_44 + 2,0x41300000,0x41700000);
    FUN_00510c70(local_28 + 6,local_44 + 6,0,0x40a00000);
    FUN_00510c70(local_28 + 1,local_44 + 1,0x41f80000,0x420c0000);
    uVar22 = 0x42340000;
    uVar21 = 0x41f80000;
    break;
  case 3:
    FUN_00510c70(&local_58,&local_5c,0x43968000,0x43fa0000);
    lVar16 = __ftol();
    uVar4 = (uint)lVar16;
    lVar16 = __ftol();
    uVar4 = FUN_004034d0((int)lVar16,uVar4);
    if (cVar9 == '\0') {
      uVar21 = 0x425c0000;
      pfVar13 = local_44 + 3;
      uVar22 = 0x41f80000;
      pfVar19 = local_28 + 3;
LAB_0051135d:
      FUN_00510c70(pfVar19,pfVar13,uVar22,uVar21);
    }
    else {
      if (cVar9 == '\x01') {
        uVar21 = 0x425c0000;
        pfVar13 = local_44 + 4;
        uVar22 = 0x41f80000;
        pfVar19 = local_28 + 4;
        goto LAB_0051135d;
      }
      if (cVar9 == '\x02') {
        FUN_00510c70(local_28 + 3,local_44 + 3,0x41a00000,0x41f00000);
        uVar21 = 0x41c80000;
        pfVar13 = local_44 + 4;
        uVar22 = 0x41300000;
        pfVar19 = local_28 + 4;
        goto LAB_0051135d;
      }
    }
    uVar21 = 0x41f00000;
    uVar22 = 0x41300000;
LAB_00511080:
    FUN_00510c70(local_28 + 2,local_44 + 2,uVar22,uVar21);
    FUN_00510c70(local_28 + 6,local_44 + 6,0,0x40a00000);
    uVar21 = 0x41200000;
    uVar22 = 0x41000000;
LAB_00511662:
    param_4 = (float)(int)uVar4;
    FUN_00510c70(local_28 + 1,local_44 + 1,uVar22,uVar21);
    uVar22 = 0x41200000;
LAB_00511774:
    uVar21 = 0;
    break;
  case 4:
    FUN_00510c70(&local_58,&local_5c,0x43160000,0x43960000);
    lVar16 = __ftol();
    uVar4 = (uint)lVar16;
    lVar16 = __ftol();
    uVar4 = FUN_004034d0((int)lVar16,uVar4);
    if (cVar9 == '\0') {
      uVar22 = 0x41700000;
      pfVar13 = local_44 + 3;
      pfVar19 = local_28 + 3;
LAB_00511413:
      FUN_00510c70(pfVar19,pfVar13,0,uVar22);
    }
    else {
      if (cVar9 == '\x01') {
        uVar22 = 0x41700000;
        pfVar13 = local_44 + 4;
        pfVar19 = local_28 + 4;
        goto LAB_00511413;
      }
      if (cVar9 == '\x02') {
        FUN_00510c70(local_28 + 3,local_44 + 3,0,0x41200000);
        uVar22 = 0x40a00000;
        pfVar13 = local_44 + 4;
        pfVar19 = local_28 + 4;
        goto LAB_00511413;
      }
    }
    FUN_00510c70(local_28 + 2,local_44 + 2,0,0x41200000);
    FUN_00510c70(local_28 + 6,local_44 + 6,0,0x40a00000);
    uVar21 = 0x42200000;
    uVar22 = 0x41f80000;
LAB_00511454:
    param_4 = (float)(int)uVar4;
    FUN_00510c70(local_28 + 1,local_44 + 1,uVar22,uVar21);
    uVar22 = 0x42200000;
    uVar21 = 0x41800000;
    break;
  case 5:
    FUN_00510c70(&local_58,&local_5c,0x43160000,0x43480000);
    lVar16 = __ftol();
    uVar4 = (uint)lVar16;
    lVar16 = __ftol();
    uVar4 = FUN_004034d0((int)lVar16,uVar4);
    param_4 = (float)(int)uVar4;
    if (cVar9 == '\0') {
      uVar22 = 0x41200000;
      pfVar13 = local_44 + 3;
      pfVar19 = local_28 + 3;
LAB_00511514:
      FUN_00510c70(pfVar19,pfVar13,0,uVar22);
    }
    else {
      if (cVar9 == '\x01') {
        uVar22 = 0x41200000;
        pfVar13 = local_44 + 4;
        pfVar19 = local_28 + 4;
        goto LAB_00511514;
      }
      if (cVar9 == '\x02') {
        FUN_00510c70(local_28 + 3,local_44 + 3,0,0x40a00000);
        uVar22 = 0x40a00000;
        pfVar13 = local_44 + 4;
        pfVar19 = local_28 + 4;
        goto LAB_00511514;
      }
    }
    FUN_00510c70(local_28 + 2,local_44 + 2,0,0x41200000);
    FUN_00510c70(local_28 + 6,local_44 + 6,0,0x40a00000);
    FUN_00510c70(local_28 + 1,local_44 + 1,0x41800000,0x420c0000);
    uVar22 = 0x425c0000;
    uVar21 = 0x41f80000;
    break;
  case 6:
    FUN_00510c70(&local_58,&local_5c,0x43160000,0x43960000);
    lVar16 = __ftol();
    uVar4 = (uint)lVar16;
    lVar16 = __ftol();
    uVar4 = FUN_004034d0((int)lVar16,uVar4);
    if (cVar9 == '\0') {
      uVar21 = 0x42700000;
      pfVar13 = local_44 + 3;
      uVar22 = 0x41f80000;
      pfVar19 = local_28 + 3;
LAB_00511621:
      FUN_00510c70(pfVar19,pfVar13,uVar22,uVar21);
    }
    else {
      if (cVar9 == '\x01') {
        uVar21 = 0x42700000;
        pfVar13 = local_44 + 4;
        uVar22 = 0x41f80000;
        pfVar19 = local_28 + 4;
        goto LAB_00511621;
      }
      if (cVar9 == '\x02') {
        FUN_00510c70(local_28 + 3,local_44 + 3,0x41a00000,0x41f00000);
        uVar21 = 0x41f00000;
        pfVar13 = local_44 + 4;
        uVar22 = 0x41300000;
        pfVar19 = local_28 + 4;
        goto LAB_00511621;
      }
    }
    FUN_00510c70(local_28 + 2,local_44 + 2,0,0x41200000);
    FUN_00510c70(local_28 + 6,local_44 + 6,0,0x40a00000);
    uVar21 = 0x41f00000;
    uVar22 = 0x41200000;
    goto LAB_00511662;
  case 7:
    FUN_00510c70(&local_58,&local_5c,0x43160000,0x43fa0000);
    lVar16 = __ftol();
    uVar4 = (uint)lVar16;
    lVar16 = __ftol();
    uVar4 = FUN_004034d0((int)lVar16,uVar4);
    param_4 = (float)(int)uVar4;
    if (cVar9 == '\0') {
      uVar22 = 0x420c0000;
      pfVar13 = local_44 + 3;
      pfVar19 = local_28 + 3;
LAB_0051171d:
      FUN_00510c70(pfVar19,pfVar13,0,uVar22);
    }
    else {
      if (cVar9 == '\x01') {
        uVar22 = 0x420c0000;
        pfVar13 = local_44 + 4;
        pfVar19 = local_28 + 4;
        goto LAB_0051171d;
      }
      if (cVar9 == '\x02') {
        FUN_00510c70(local_28 + 3,local_44 + 3,0,0x41a00000);
        uVar22 = 0x41700000;
        pfVar13 = local_44 + 4;
        pfVar19 = local_28 + 4;
        goto LAB_0051171d;
      }
    }
    FUN_00510c70(local_28 + 2,local_44 + 2,0,0x41f00000);
    FUN_00510c70(local_28 + 6,local_44 + 6,0,0x40a00000);
    FUN_00510c70(local_28 + 1,local_44 + 1,0x41200000,0x420c0000);
    uVar22 = 0x420c0000;
    goto LAB_00511774;
  default:
    goto switchD_00510e54_default;
  }
LAB_00511780:
  FUN_00510c70(local_28 + 5,local_44 + 5,uVar21,uVar22);
switchD_00510e54_default:
  local_4c = (float *)((100 - iVar6) * 2);
  local_50 = FUN_004034d0(0,(int)local_4c / 2);
  iVar7 = 0;
  fVar1 = ((float)(int)local_50 + param_4) - (float)(int)local_4c;
  puVar14 = (undefined4 *)((int)this + 0x314);
  for (iVar8 = 7; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar14 = 0;
    puVar14 = puVar14 + 1;
  }
  do {
    iVar8 = iVar7 + 4;
    *(float *)((int)local_28 + iVar7) = *(float *)((int)local_28 + iVar7) * 0.01 * fVar1;
    *(float *)((int)local_44 + iVar7) = *(float *)((int)local_44 + iVar7) * 0.01 * fVar1;
    iVar7 = iVar8;
  } while (iVar8 < 0x1c);
  iVar7 = 1;
  iVar8 = 0;
  while (iVar8 = iVar8 + 1, iVar8 < 0x3e9) {
    lVar16 = __ftol();
    uVar4 = (uint)lVar16;
    lVar16 = __ftol();
    local_4c = (float *)FUN_004034d0((int)lVar16,uVar4);
    fVar1 = (float)(int)local_4c + *(float *)((int)this + iVar7 * 4 + 0x314);
    *(float *)((int)this + iVar7 * 4 + 0x314) = fVar1;
    if (local_44[iVar7] < fVar1) {
      *(float *)((int)this + iVar7 * 4 + 0x314) = local_44[iVar7];
    }
    lVar16 = __ftol();
    lVar17 = __ftol();
    if ((int)lVar17 <= (int)lVar16) break;
    iVar7 = iVar7 + 1;
    if (6 < iVar7) {
      iVar7 = 1;
    }
  }
  iVar7 = *(int *)((int)DAT_0057c670 + 0xa8);
  bVar2 = FUN_004e47e0(iVar7);
  uVar18 = __ftol();
  uVar4 = (int)uVar18 >> 0x1f;
  iVar8 = (int)((longlong)((ulonglong)uVar4 << 0x20 | uVar18 & 0xffffffff) /
               (longlong)*(int *)(iVar7 + 0xac + (uint)bVar2 * 4));
  if (iVar8 < 0x18) {
    bVar2 = 3;
    iVar8 = (int)((longlong)((ulonglong)uVar4 << 0x20 | uVar18 & 0xffffffff) /
                 (longlong)*(int *)(iVar7 + 0xb8));
  }
  if (0xf < iVar8) {
    iVar23 = 0x10;
    local_4c = (float *)((int)this + (uint)*(byte *)(iVar7 + 0xa8) * 4 + 0x314);
    uVar22 = *(undefined4 *)(*(int *)((int)DAT_0057c670 + 0xa0) + 0x18);
    bVar20 = bVar2;
    uVar4 = FUN_004034d0(1,0x20);
    fVar15 = Recipe_StreamConstruct(this,uVar22,5,iVar7,uVar4,bVar20,iVar23);
    iVar8 = iVar8 + -0x10;
    *local_4c = (float)((float10)*local_4c - fVar15);
  }
  if (7 < iVar8) {
    iVar23 = 8;
    local_4c = (float *)((int)this + (uint)*(byte *)(iVar7 + 0xa8) * 4 + 0x314);
    uVar22 = *(undefined4 *)(*(int *)((int)DAT_0057c670 + 0xa0) + 0x18);
    bVar20 = bVar2;
    uVar4 = FUN_004034d0(1,0x20);
    fVar15 = Recipe_StreamConstruct(this,uVar22,8,iVar7,uVar4,bVar20,iVar23);
    iVar8 = iVar8 + -8;
    *local_4c = (float)((float10)*local_4c - fVar15);
  }
  if (3 < iVar8) {
    iVar23 = 4;
    local_4c = (float *)((int)this + (uint)*(byte *)(iVar7 + 0xa8) * 4 + 0x314);
    uVar22 = *(undefined4 *)(*(int *)((int)DAT_0057c670 + 0xa0) + 0x18);
    bVar20 = bVar2;
    uVar4 = FUN_004034d0(1,0x20);
    fVar15 = Recipe_StreamConstruct(this,uVar22,10,iVar7,uVar4,bVar20,iVar23);
    iVar8 = iVar8 + -4;
    *local_4c = (float)((float10)*local_4c - fVar15);
  }
  if (0 < iVar8) {
    pfVar13 = (float *)((int)this + (uint)*(byte *)(iVar7 + 0xa8) * 4 + 0x314);
    fVar15 = Recipe_StreamConstruct
                       (this,*(undefined4 *)(*(int *)((int)DAT_0057c670 + 0xa0) + 0x18),0xd,iVar7,1,
                        bVar2,1);
    *pfVar13 = (float)((float10)*pfVar13 - fVar15);
  }
  if (0.0 < *(float *)((int)this + 800)) {
    Recipe_AddCategoryIngredients(this,local_54,param_2,iVar6,3,3,param_5);
  }
  if (0.0 < *(float *)((int)this + 0x324)) {
    Recipe_AddCategoryIngredients(this,local_54,param_2,iVar6,3,4,param_5);
  }
  if (0.0 < *(float *)((int)this + 0x328)) {
    Recipe_AddCategoryIngredients(this,local_54,param_2,iVar6,3,5,param_5);
  }
  if (0.0 < *(float *)((int)this + 0x318)) {
    Recipe_AddCategoryIngredients(this,local_54,param_2,iVar6,2,1,param_5);
  }
  if (0.0 < *(float *)((int)this + 0x31c)) {
    Recipe_AddCategoryIngredients(this,local_54,param_2,iVar6,2,2,param_5);
  }
  if (0.0 < *(float *)((int)this + 0x32c)) {
    Recipe_AddCategoryIngredients(this,local_54,param_2,iVar6,2,6,param_5);
  }
  FUN_00512620(this,param_1);
  FUN_00402990(DAT_0057c5d8,*(int *)((int)this + 0x310));
  FUN_0050fec0((int)this);
  fVar15 = FUN_0050fe70((int)this);
  *(float *)((int)this + 0x44) = (float)fVar15;
  ExceptionList = local_c;
  return this;
}

