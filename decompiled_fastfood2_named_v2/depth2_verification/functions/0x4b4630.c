// rea decompile_all
// name: FUN_004b4630
// address: 0x4b4630
// body: available
// range: 0x4b4630-0x4b4c0f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004b4630(void *param_1)

{
  uint *puVar1;
  uint *puVar2;
  ushort uVar3;
  void *pvVar4;
  void *pvVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  float fVar10;
  undefined4 unaff_EDI;
  int iVar11;
  float10 fVar12;
  longlong lVar13;
  longlong lVar14;
  float local_8c;
  int local_88;
  float local_84;
  float local_80;
  int local_7c;
  float local_78;
  float local_74;
  int local_70;
  int local_6c;
  int local_68;
  void *local_64;
  int local_60;
  int local_5c;
  float local_58;
  int local_54;
  void *local_50;
  float local_4c;
  int *local_48;
  void *local_44;
  undefined1 local_40 [64];
  
  uVar3 = *(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  fVar10 = (float)(uint)uVar3;
  local_68 = 0;
  local_4c = fVar10;
  pvVar4 = (void *)FUN_00531cf0(param_1,0x41d);
  local_64 = pvVar4;
  FUN_00521380((int)pvVar4);
  if (fVar10 == 0.0) {
    FUN_00521ae0(pvVar4,&local_7c,&local_88);
    pvVar5 = (void *)FUN_00521b10((int)pvVar4);
    FUN_00535520(DAT_0057d698,local_7c / 2,local_88 / 2,2);
    FUN_00535500(DAT_0057d698,0);
    FUN_00535740(DAT_0057d698,pvVar5,DAT_00581444);
    FUN_00521b30((int)pvVar4);
    return;
  }
  if (DAT_0057d6a4 == (void *)0x0) {
    FUN_00521b30((int)pvVar4);
    return;
  }
  if (uVar3 < 0x29) {
    local_54 = 0;
    local_84 = fVar10;
  }
  else {
    local_54 = (int)fVar10 + -0x28;
    local_84 = 5.60519e-44;
  }
  iVar11 = local_54;
  local_6c = *(int *)((int)DAT_0057d6a4 + 0x14);
  pvVar5 = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  local_50 = pvVar5;
  if (local_6c == 0) {
    FUN_00521b30((int)pvVar4);
    return;
  }
  if (DAT_0056a7d4 != -1) {
    local_68 = FUN_004017f0((void *)((int)pvVar5 + 0x148),DAT_0056a7d4,(int *)0x0);
  }
  FUN_00521ae0(pvVar4,&local_7c,&local_88);
  local_48 = FUN_00521bc0(pvVar4,0,5);
  local_88 = local_88 + -5;
  local_7c = local_7c + -5;
  if (DAT_0057d69c == 0) {
    pvVar4 = FUN_004ddfb0(pvVar5,0x56a734,local_68);
    if (pvVar4 == (void *)0x0) {
LAB_004b4825:
      local_8c = 0.0;
    }
    else {
      local_60 = Stats_GetMaxTimelineCount(pvVar4,0x56a734);
      local_8c = (float)local_60;
    }
LAB_004b482d:
    local_84 = (float)local_7c / (float)(int)local_84;
LAB_004b4839:
    if (local_8c <= 0.0) {
      FUN_0054dd83(local_40,DAT_00582e4c,unaff_EDI);
      goto LAB_004b487c;
    }
  }
  else {
    if (DAT_0057d69c == 1) {
      iVar7 = FUN_004de030(pvVar5,0x56a734,local_68);
      if (iVar7 == 0) goto LAB_004b4825;
      fVar12 = Stats_GetMaxTimelineCategoryValue(iVar7,0x56a734);
      local_8c = (float)fVar12;
      goto LAB_004b482d;
    }
    if (DAT_0057d69c != 2) goto LAB_004b4839;
    local_8c = 100.0;
    local_84 = (float)local_7c / (float)local_6c;
  }
  FUN_0054dd83(local_40,(byte *)s__0_2f_005685f4,SUB84((double)local_8c,0));
LAB_004b487c:
  FUN_0052f9b0(param_1,0x41f,local_40);
  FUN_0054dd83(local_40,(byte *)s__d__d_00568ef8,*(byte *)(*(int *)(DAT_0057c670 + 0x94) + 8) + 1);
  FUN_0052f9b0(param_1,0x41e,local_40);
  if (local_8c <= 0.0) {
    local_74 = 0.0;
  }
  else {
    local_74 = (float)local_88 / local_8c;
  }
  if (DAT_0057d69c < 2) {
    local_60 = 0;
    if (0 < local_6c) {
      do {
        iVar7 = local_60;
        local_78 = 0.0;
        pvVar4 = (void *)FUN_004017f0(DAT_0057d6a4,*(int *)(DAT_0057d6a0 + local_60 * 4),(int *)0x0)
        ;
        local_44 = pvVar4;
        if (*(int *)(&DAT_0056a760 + *(int *)(DAT_0057d6a0 + iVar7 * 4) * 4) != 0) {
          if (iVar11 == 0) {
            fVar12 = (float10)local_88;
          }
          else {
            local_80 = (float)local_88;
            if (DAT_0057d69c == 0) {
              local_70 = FUN_005101d0(pvVar4,iVar11 + -1,0x56a734,DAT_0056a7d4);
              fVar12 = (float10)local_70;
            }
            else {
              fVar12 = FUN_005100b0((int)pvVar4,iVar11 + -1,0x56a734,DAT_0056a7d4);
            }
            fVar12 = (float10)local_80 - fVar12 * (float10)local_74;
          }
          local_80 = (float)fVar12;
          local_5c = iVar11;
          if (iVar11 < (int)fVar10) {
            while( true ) {
              if (DAT_0057d69c == 0) {
                local_70 = FUN_005101d0(pvVar4,local_5c,0x56a734,DAT_0056a7d4);
              }
              else {
                FUN_005100b0((int)pvVar4,local_5c,0x56a734,DAT_0056a7d4);
              }
              lVar13 = __ftol();
              fVar10 = (float)(local_88 - (int)lVar13);
              local_58 = fVar10;
              if ((local_68 == 0) || (*(void **)(local_68 + 0x14dc) != pvVar4)) {
                local_70 = FUN_004ddeb0(local_50,(int)pvVar4);
              }
              else {
                local_70 = 0x14;
              }
              lVar13 = __ftol();
              puVar1 = (uint *)((int)lVar13 + 2);
              lVar13 = __ftol();
              lVar14 = __ftol();
              puVar2 = (uint *)((int)lVar14 + 2);
              FUN_00521740(local_64,puVar2,(int)lVar13 + 3,puVar1,(int)fVar10 + 3,0);
              uVar6 = FUN_00482710(local_70);
              FUN_00521740(local_64,puVar2,(int)lVar13 + 2,puVar1,(int)fVar10 + 2,uVar6);
              local_78 = local_78 + local_84;
              local_5c = local_5c + 1;
              local_80 = (float)(int)local_58;
              if ((int)local_4c <= local_5c) break;
              pvVar4 = local_44;
            }
            fVar10 = local_4c;
            iVar11 = local_54;
            iVar7 = local_60;
          }
        }
        local_60 = iVar7 + 1;
      } while (local_60 < local_6c);
    }
  }
  else {
    local_80 = (float)local_88;
    iVar11 = 0;
    local_78 = 0.0;
    if (0 < local_6c) {
      do {
        pvVar4 = (void *)FUN_004017f0(DAT_0057d6a4,*(int *)(DAT_0057d6a0 + iVar11 * 4),(int *)0x0);
        if (*(int *)(&DAT_0056a760 + *(int *)(DAT_0057d6a0 + iVar11 * 4) * 4) != 0) {
          fVar12 = Stats_AverageActiveCategories(pvVar4,0x56a734);
          local_58 = (float)(fVar12 * (float10)local_74);
          if ((local_68 == 0) || (*(void **)(local_68 + 0x14dc) != pvVar4)) {
            iVar7 = FUN_004ddeb0(local_50,(int)pvVar4);
          }
          else {
            iVar7 = 0x14;
          }
          uVar6 = FUN_00482710(iVar7);
          lVar13 = __ftol();
          iVar7 = (int)lVar13;
          lVar13 = __ftol();
          iVar8 = (int)lVar13;
          lVar13 = __ftol();
          iVar9 = local_88 - (int)lVar13;
          lVar13 = __ftol();
          Sprite_FillRectColor(local_64,(int)lVar13,iVar9,iVar8,iVar7,uVar6);
          local_78 = local_78 + local_84;
        }
        iVar11 = iVar11 + 1;
      } while (iVar11 < local_6c);
    }
  }
  FUN_00521b30((int)local_64);
  FUN_00521da0(local_48);
  return;
}

