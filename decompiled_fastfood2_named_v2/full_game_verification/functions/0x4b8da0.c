// rea decompile_all
// name: PersonnelPanel_Update
// address: 0x4b8da0
// body: available
// range: 0x4b8da0-0x4b8fd1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl PersonnelPanel_Update(void *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
                    /* Updates the city personnel panel and selected person card. */
  DAT_0057d6c4 = *(void **)((int)DAT_0057c670 + 0x9c);
  DAT_0057d6c0 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((int)DAT_0057d6c4 + 0x30));
  iVar2 = Game_CountObjectsByType(DAT_0057d6c4,0xffffffff);
  Window_GadgetNotify_Text_SetText(param_1,0x51b,DAT_0057d6c0 + 8);
  Personnel_SetEmployeePhotoByKey(param_1,0x2333,DAT_0057d6c0);
  uVar1 = (uint)(iVar2 != 0);
  UI_SetChildVisibleByID(param_1,0x50a,uVar1);
  UI_SetChildVisibleByID(param_1,0x50b,uVar1);
  UI_SetChildVisibleByID(param_1,0x516,uVar1);
  UI_SetChildVisibleByID(param_1,0x518,uVar1);
  UI_SetChildVisibleByID(param_1,0x517,uVar1);
  UI_SetChildVisibleByID(param_1,0x511,uVar1);
  UI_SetChildVisibleByID(param_1,0x514,uVar1);
  UI_SetChildVisibleByID(param_1,0x512,uVar1);
  UI_SetChildVisibleByID(param_1,0x513,uVar1);
  UI_SetChildVisibleByID(param_1,0x50c,uVar1);
  UI_SetChildVisibleByID(param_1,0x2332,uVar1);
  if (iVar2 == 0) {
    Window_GadgetNotify_Text_SetText(param_1,0x515,DAT_00582680);
    Window_GadgetNotify_Text_SetText(param_1,0x502,DAT_00581b30);
    DAT_0057d6bc = 0xffffffff;
    Window_GadgetNotify_Slider_SetRange(param_1,0x2329,0,100,0);
    Window_GadgetNotify_Slider_SetRange(param_1,0x232b,0,100,0);
    Window_GadgetNotify_Slider_SetRange(param_1,0x232d,0,100,0);
    Window_GadgetNotify_Slider_SetRange(param_1,0x232f,0,100,0);
    Window_GadgetNotify_Slider_SetValue(param_1,0x2329,0,0);
    Window_GadgetNotify_Slider_SetValue(param_1,0x232b,0,0);
    Window_GadgetNotify_Slider_SetValue(param_1,0x232d,0,0);
    Window_GadgetNotify_Slider_SetValue(param_1,0x232f,0,0);
    iVar2 = 0;
    do {
      Rating_UpdateBarByKey(param_1,0x5a7,iVar2,0,0);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 8);
    return;
  }
  if (DAT_0057d6bc != -1) {
    iVar2 = IDMap_Lookup((void *)((int)DAT_0057d6c4 + 0x1500),DAT_0057d6bc,(int *)0x0);
    if (iVar2 != 0) goto LAB_004b8f9b;
  }
  DAT_0057d6bc = 0;
LAB_004b8f9b:
  StaffPage_FillEmployeeDetails(param_1);
  iVar2 = 0;
  do {
    iVar4 = DAT_005826d8;
    iVar3 = Stats_GetAverage8(DAT_0057d6c4,iVar2);
    Rating_UpdateBarByKey(param_1,0x5a7,iVar2,iVar3,iVar4);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 8);
  return;
}

