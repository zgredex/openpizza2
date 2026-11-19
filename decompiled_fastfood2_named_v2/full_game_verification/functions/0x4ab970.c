// rea decompile_all
// name: StatisticsBalance_InitPage
// address: 0x4ab970
// body: available
// range: 0x4ab970-0x4abb96 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl StatisticsBalance_InitPage(void *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  
                    /* Initializes the balance-sheet statistics page. */
  iVar4 = 1;
  if (DAT_00569354 == -9999) {
    DAT_00569354 = DAT_0057dfbc;
  }
  if (DAT_00569354 < DAT_0057dfbc) {
    DAT_00569354 = DAT_0057dfbc;
    DAT_0057d5c8 = 0;
  }
  UI_SetPosition(param_1,NoOp_Stub,0);
  iVar1 = DAT_0057c670;
  iVar6 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  iVar2 = *(int *)(iVar6 + 0x15c);
  puVar5 = &DAT_0057d574;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  if (iVar2 == 0) {
    DAT_00569358 = 0xffffffff;
    iVar4 = 0;
  }
  else if (-1 < (int)DAT_00569358) {
    if (*(int *)(iVar1 + 0x9c) == 0) {
      DAT_00569358 = 0xffffffff;
    }
    else {
      DAT_00569358 = Map_FindIndex((void *)(iVar6 + 0x148),*(int *)(iVar1 + 0x9c));
    }
  }
  UI_SetChildVisibleByID(param_1,0x3f2,iVar4);
  UI_SetChildVisibleByID(param_1,0x4b2,(uint)(DAT_00569358 != 0xffffffff));
  iVar6 = 0;
  do {
    UI_SetChildVisibleByID(param_1,*(int *)((int)&DAT_0056935c + iVar6),iVar4);
    UI_SetChildVisibleByID(param_1,*(int *)((int)&DAT_0056937c + iVar6),iVar4);
    UI_SetChildVisibleByID(param_1,*(int *)((int)&DAT_0056939c + iVar6),iVar4);
    iVar6 = iVar6 + 4;
  } while (iVar6 < 0x20);
  if (0 < iVar2) {
    if (iVar2 < 9) {
      UI_RemoveObjectByKey(param_1,0x3f2);
      iVar2 = 8 - iVar2;
      if (0 < iVar2) {
        iVar4 = 0x4c6;
        iVar6 = 0;
        do {
          UI_RemoveObjectByKey(param_1,*(int *)((int)&DAT_00569378 + iVar6));
          UI_RemoveObjectByKey(param_1,*(int *)((int)&DAT_00569398 + iVar6));
          UI_RemoveObjectByKey(param_1,*(int *)((int)&DAT_005693b8 + iVar6));
          UI_RemoveObjectByKey(param_1,iVar4);
          iVar6 = iVar6 + -4;
          iVar4 = iVar4 + -1;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
    }
    else {
      DAT_0057d5d0 = DAT_00569358 & ((int)DAT_00569358 < 0) - 1;
      if (iVar2 < (int)(DAT_0057d5d0 + 8)) {
        DAT_0057d5d0 = iVar2 - 8;
      }
      DAT_0057d5d4 = DAT_0057d5d0;
      Window_GadgetNotify_Slider_SetRange(param_1,0x3f2,0,(iVar2 * 5 + -0x28) * 0x14,0);
      Window_GadgetNotify_Slider_SetValue(param_1,0x3f2,DAT_0057d5d0 * 100,0);
      Window_GadgetNotify_Slider_SetChangeNotify(param_1,0x3f2,1);
    }
  }
  if (DAT_0057d5cc != -1) {
    StatisticsScreen_ChangeTab(param_1,0);
  }
  StatisticsBalance_UpdateBranchList(param_1,DAT_0057d5d0);
  StatisticsBalance_UpdateReport(param_1);
  StatisticsBalance_UpdateHeader(param_1);
  return;
}

