// rea decompile_all
// name: StatisticsBranchBalance_InitPage
// address: 0x4ad9a0
// body: available
// range: 0x4ad9a0-0x4adc7e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl StatisticsBranchBalance_InitPage(void *param_1,char param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  int local_44 [17];
  
                    /* Initializes the branch-balance statistics page. */
  iVar5 = 1;
  FUN_00532310(param_1,&LAB_004ac440,0);
  FUN_0052fd00(param_1,0x4be,0,100,1);
  if (DAT_0057d638 != 0) {
    FUN_005271d0(DAT_0057c5e0,DAT_0057d638);
  }
  DAT_0057d638 = UI_LoadFontByName(DAT_0057c5e0,s_VERDANA10_fnt_00563e64);
  iVar1 = DAT_0057c670;
  iVar8 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  iVar2 = *(int *)(iVar8 + 0x15c);
  puVar7 = &DAT_0057d5d8;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  if (iVar2 == 0) {
    DAT_0056951c = 0xffffffff;
    iVar5 = 0;
  }
  else if (-1 < (int)DAT_0056951c) {
    if (*(int *)(iVar1 + 0x9c) == 0) {
      DAT_0056951c = 0xffffffff;
    }
    else {
      DAT_0056951c = FUN_00401900((void *)(iVar8 + 0x148),*(int *)(iVar1 + 0x9c));
    }
  }
  iVar8 = 0;
  do {
    UI_SetChildVisibleByID(param_1,*(int *)((int)&DAT_00569570 + iVar8),iVar5);
    UI_SetChildVisibleByID(param_1,*(int *)((int)&DAT_00569584 + iVar8),iVar5);
    UI_SetChildVisibleByID(param_1,*(int *)((int)&DAT_00569598 + iVar8),iVar5);
    iVar8 = iVar8 + 4;
  } while (iVar8 < 0x14);
  UI_SetChildVisibleByID(param_1,0x3f2,iVar5);
  UI_SetChildVisibleByID(param_1,0x4b2,(uint)(DAT_0056951c != 0xffffffff));
  if (0 < iVar2) {
    if (iVar2 < 6) {
      FUN_00531740(param_1,0x3f2);
      iVar2 = 5 - iVar2;
      if (0 < iVar2) {
        iVar5 = 0;
        do {
          FUN_00531740(param_1,*(int *)((int)&DAT_00569580 + iVar5));
          FUN_00531740(param_1,*(int *)((int)&DAT_00569594 + iVar5));
          FUN_00531740(param_1,*(int *)((int)&DAT_005695a8 + iVar5));
          iVar5 = iVar5 + -4;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
    }
    else {
      DAT_0057d630 = DAT_0056951c & ((int)DAT_0056951c < 0) - 1;
      if (iVar2 < (int)(DAT_0057d630 + 5)) {
        DAT_0057d630 = iVar2 - 5;
      }
      DAT_0057d634 = DAT_0057d630;
      FUN_0052fd00(param_1,0x3f2,0,(iVar2 * 5 + -0x19) * 0x14,0);
      FUN_0052fd70(param_1,0x3f2,DAT_0057d630 * 100,0);
      FUN_0052fce0(param_1,0x3f2,1);
    }
  }
  if (param_2 != '\0') {
    piVar6 = &DAT_00569520;
    do {
      iVar5 = 0;
      do {
        piVar4 = local_44;
        iVar8 = iVar5 + -0x10 + *piVar6;
        iVar2 = 0x11;
        do {
          *piVar4 = iVar8;
          iVar8 = iVar8 + 1;
          piVar4 = piVar4 + 1;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
        UI_AddSelectionGroup(param_1,2,0x11,local_44);
        iVar5 = iVar5 + 0x11;
      } while (iVar5 < 0x55);
      piVar6 = piVar6 + 1;
    } while ((int)piVar6 < 0x569548);
    UI_Group_Create(param_1,0,6,0x4b3);
  }
  FUN_0052ff50(param_1,*(int *)(&DAT_00569618 + DAT_0057d62c * 4),1);
  FUN_0052f9b0(param_1,0x40c,DAT_00580d3c);
  FUN_0052f9b0(param_1,0x88a,DAT_00580b70);
  FUN_004ac5e0(param_1,DAT_0057d634);
  StatisticsBranchBalance_InitBranchTabs(param_1,DAT_0057d630);
  StatisticsBranchBalance_InitCategoryRows(param_1);
  StatisticsBranchBalance_InitMetricSliders(param_1);
  StatisticsBranchBalance_UpdateWeeklyRows(param_1,'\x01');
  return;
}

