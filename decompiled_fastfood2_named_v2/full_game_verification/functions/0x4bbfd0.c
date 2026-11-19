// rea decompile_all
// name: BranchRatingPanel_Update
// address: 0x4bbfd0
// body: available
// range: 0x4bbfd0-0x4bc187 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl BranchRatingPanel_Update(void *param_1)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
                    /* Updates the branch rating panel and customer-group bars. */
  UI_SetPosition(param_1,&LAB_004bbfb0,0);
  UI_AddUniquePair(param_1,0x1f43,0x131);
  UI_AddUniquePair(param_1,0x1f45,0x133);
  if (DAT_0057d6f8 != (void *)0x0) {
    UI_ReleaseRefCount(DAT_0057c5e0,(int)DAT_0057d6f8);
  }
  DAT_0057d6f8 = (void *)UI_LoadFontByName(DAT_0057c5e0,s_VERDANA7_fnt_00563ec8);
  iVar2 = *(int *)((int)DAT_0057c670 + 0x218);
  pvVar1 = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)(iVar2 + 8));
  DAT_0057d6f0 = (void *)IDMap_Lookup((void *)((int)pvVar1 + 0x148),*(int *)(iVar2 + 0x2c),
                                      (int *)0x0);
  DAT_0057d6f4 = *(undefined4 *)((int)DAT_0057d6f0 + 0x3c);
  Gadget_SetText(param_1,0x1f44,DAT_005818d4);
  Window_GadgetNotify_Text_SetText(param_1,0x1f41,(int)DAT_0057d6f0 + 4);
  pvVar1 = Player_FindRecordByCityId(pvVar1,(int)DAT_0057d6f0);
  if (pvVar1 == (void *)0x0) {
    UI_RemoveObjectByKey(param_1,0x1f46);
    Window_GadgetNotify_Text_SetText(param_1,0x1f64,DAT_00582a7c);
  }
  else {
    UI_ShowChildByID(param_1,0x1f46);
    Get_Subobject4((int)pvVar1);
    Gadget_SetTextf(param_1,0x1f64,(byte *)s__s__s_00563314,DAT_00581a4c);
  }
  Chart_DrawRatingMatrix(param_1,0x1f5a,DAT_0057d6f8,DAT_0057d6f0,7.958983e-39);
  pvVar1 = DAT_0057d6f0;
  iVar2 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
  Chart_DrawGroupMatrix(param_1,0x1f49,iVar2,(int)pvVar1);
  iVar2 = 0;
  piVar4 = &DAT_0056aa68;
  do {
    Window_GadgetNotify_Button_SetState(param_1,iVar2 + 0x1f56,(uint)(*piVar4 == 1));
    piVar4 = piVar4 + 1;
    iVar2 = iVar2 + 1;
  } while ((int)piVar4 < 0x56aa78);
  iVar2 = 0;
  do {
    iVar5 = DAT_00582998;
    iVar3 = Branch_GetCustomerGroupRating(DAT_0057d6f0,iVar2,1);
    Rating_UpdateBarByKey(param_1,0x5be,iVar2,iVar3,iVar5);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 8);
  return;
}

