// rea decompile_all
// name: StatisticsBranchBalance_UpdateWeeklyRows
// address: 0x4acdc0
// body: available
// range: 0x4acdc0-0x4ad2c5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl StatisticsBranchBalance_UpdateWeeklyRows(void *param_1,char param_2)

{
  void *pvVar1;
  void *pvVar2;
  void *this;
  int iVar3;
  int *piVar4;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  int iVar5;
  int iVar6;
  undefined4 unaff_EDI;
  int iVar7;
  float10 fVar8;
  longlong lVar9;
  float local_f8;
  float local_f4;
  int local_f0 [7];
  int local_d4;
  int local_d0;
  void *local_cc;
  int local_c8 [7];
  int local_ac [9];
  int local_88 [9];
  int local_64 [9];
  undefined1 local_40 [64];
  
  local_f4 = 0.0;
  piVar4 = local_c8;
                    /* Recomputes the weekly branch-balance KPI rows. */
  for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
  }
  piVar4 = local_88;
  for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
  }
  piVar4 = local_ac;
  for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
  }
  piVar4 = local_64;
  for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
  }
  pvVar2 = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  local_cc = pvVar2;
  local_d0 = *(int *)((int)pvVar2 + 0x15c);
  if (*(int *)((int)pvVar2 + 0x15c) == 0) {
    String_Format(local_40,DAT_00582e4c,unaff_EDI);
    iVar3 = 0x845;
    iVar7 = 0;
    do {
      iVar6 = 0;
      do {
        UI_ShowChildByID(param_1,*(int *)((int)&DAT_00569520 + iVar7) + -0x10 + iVar6);
        iVar6 = iVar6 + 0x11;
      } while (iVar6 < 0x55);
      Window_GadgetNotify_Text_SetText(param_1,*(int *)((int)&DAT_00569548 + iVar7),local_40);
      Window_GadgetNotify_Text_SetText(param_1,*(int *)((int)&DAT_00569548 + iVar7) + 1,local_40);
      Window_GadgetNotify_Text_SetText(param_1,iVar3,local_40);
      iVar3 = iVar3 + 3;
      iVar7 = iVar7 + 4;
    } while (iVar3 < 0x863);
    return;
  }
  if (DAT_0056951c == -1) {
    iVar3 = 0;
    do {
      iVar7 = local_d0;
      iVar5 = 0;
      piVar4 = local_f0;
      for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
        *piVar4 = 0;
        piVar4 = piVar4 + 1;
      }
      local_f8 = 0.0;
      local_d4 = 0;
      if (0 < iVar7) {
        do {
          pvVar1 = (void *)IDMap_Lookup((void *)((int)pvVar2 + 0x148),iVar5,(int *)0x0);
          iVar7 = Stats_GetAverage8(pvVar1,iVar3);
          local_f0[0] = local_f0[0] + iVar7;
          iVar7 = Branch_ComputeBuildingRating(pvVar1,extraout_EDX,iVar3);
          local_f0[1] = local_f0[1] + iVar7;
          iVar7 = Branch_GetMenuRating(pvVar1,iVar3);
          local_f0[2] = local_f0[2] + iVar7;
          pvVar2 = (void *)Player_FindRecordType2ByKey(pvVar2,iVar5);
          if ((pvVar2 == (void *)0x0) || (*(int *)((int)pvVar2 + 4) == 0)) {
            iVar7 = 0;
          }
          else {
            iVar7 = iVar3;
            iVar6 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
            iVar7 = GamePlan_ComputeCategoryEffect(pvVar2,iVar6,iVar7);
            iVar7 = Math_PiecewiseLinear(iVar7);
            local_d4 = local_d4 + 1;
          }
          local_f0[3] = local_f0[3] + iVar7;
          iVar7 = Branch_GetCustomerGroupRating(pvVar1,iVar3,1);
          local_f0[4] = local_f0[4] + iVar7;
          iVar7 = Game_SumStatGrid2(pvVar1,iVar3,-1);
          local_f0[5] = local_f0[5] + iVar7;
          iVar7 = Game_SumStatRow8(pvVar1,iVar3);
          local_f0[6] = local_f0[6] + iVar7;
          fVar8 = Stats_SumFilteredFloats
                            ((int)pvVar1,iVar3,(uint)*(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 4),
                             (uint)*(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 10));
          iVar5 = iVar5 + 1;
          local_f8 = (float)(fVar8 + (float10)local_f8);
          pvVar2 = local_cc;
        } while (iVar5 < local_d0);
      }
      iVar7 = local_d4;
      iVar6 = 0;
      piVar4 = local_f0;
      do {
        if (iVar6 != 3) {
          *piVar4 = *piVar4 / local_d0;
        }
        iVar6 = iVar6 + 1;
        piVar4 = piVar4 + 1;
      } while (iVar6 < 5);
      if (iVar7 != 0) {
        local_f0[3] = local_f0[3] / iVar7;
      }
      local_88[iVar3] = local_88[iVar3] + local_f0[5];
      local_ac[iVar3] = local_ac[iVar3] + local_f0[6];
      lVar9 = __ftol();
      local_64[iVar3] = local_64[iVar3] + (int)lVar9;
      StatisticsBranchBalance_DrawColumn(param_1,local_f0,local_f8,iVar3,param_2);
      iVar7 = 0;
      do {
        *(int *)((int)local_c8 + iVar7) =
             *(int *)((int)local_c8 + iVar7) + *(int *)((int)local_f0 + iVar7);
        iVar7 = iVar7 + 4;
      } while (iVar7 < 0x1c);
      local_f4 = local_f8 + local_f4;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 9);
    iVar3 = 5;
    piVar4 = local_c8;
    do {
      iVar3 = iVar3 + -1;
      *piVar4 = *piVar4 / 9;
      piVar4 = piVar4 + 1;
    } while (iVar3 != 0);
  }
  else {
    pvVar1 = (void *)IDMap_Lookup((void *)((int)pvVar2 + 0x148),DAT_0056951c,(int *)0x0);
    iVar3 = 0;
    do {
      piVar4 = local_f0;
      for (iVar7 = 7; iVar7 != 0; iVar7 = iVar7 + -1) {
        *piVar4 = 0;
        piVar4 = piVar4 + 1;
      }
      local_f0[0] = Stats_GetAverage8(pvVar1,iVar3);
      local_f0[1] = Branch_ComputeBuildingRating(pvVar1,extraout_EDX_00,iVar3);
      local_f0[2] = Branch_GetMenuRating(pvVar1,iVar3);
      this = (void *)Player_FindRecordType2ByKey(pvVar2,*(int *)((int)pvVar1 + 0x3c));
      if ((this == (void *)0x0) || (*(int *)((int)this + 4) == 0)) {
        iVar7 = 0;
      }
      else {
        iVar7 = iVar3;
        iVar6 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
        iVar7 = GamePlan_ComputeCategoryEffect(this,iVar6,iVar7);
        iVar7 = Math_PiecewiseLinear(iVar7);
      }
      local_f0[3] = local_f0[3] + iVar7;
      local_f0[4] = Branch_GetCustomerGroupRating(pvVar1,iVar3,1);
      local_f0[5] = Game_SumStatGrid2(pvVar1,iVar3,-1);
      local_f0[6] = Game_SumStatRow8(pvVar1,iVar3);
      fVar8 = Stats_SumFilteredFloats
                        ((int)pvVar1,iVar3,(uint)*(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 4),
                         (uint)*(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 10));
      local_88[iVar3] = local_88[iVar3] + local_f0[5];
      local_ac[iVar3] = local_ac[iVar3] + local_f0[6];
      lVar9 = __ftol();
      local_64[iVar3] = local_64[iVar3] + (int)lVar9;
      StatisticsBranchBalance_DrawColumn(param_1,local_f0,(float)fVar8,iVar3,param_2);
      iVar7 = 0;
      do {
        *(int *)((int)local_c8 + iVar7) =
             *(int *)((int)local_c8 + iVar7) + *(int *)((int)local_f0 + iVar7);
        iVar7 = iVar7 + 4;
      } while (iVar7 < 0x1c);
      local_f4 = (float)fVar8 + local_f4;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 9);
    iVar3 = 5;
    piVar4 = local_c8;
    do {
      iVar3 = iVar3 + -1;
      *piVar4 = *piVar4 / 9;
      piVar4 = piVar4 + 1;
    } while (iVar3 != 0);
  }
  StatisticsBranchBalance_DrawColumn(param_1,local_c8,local_f4,9,param_2);
  StatisticsBranchBalance_DrawProfitBars(param_1,local_88,local_ac,(int)local_64);
  return;
}

