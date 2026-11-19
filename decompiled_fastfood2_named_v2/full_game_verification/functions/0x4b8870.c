// rea decompile_all
// name: OtherManagerPage_Update
// address: 0x4b8870
// body: available
// range: 0x4b8870-0x4b89b3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl OtherManagerPage_Update(void *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
                    /* Refreshes the other-manager page. */
  iVar1 = *(int *)((int)DAT_0057c670 + 0x9c);
  iVar2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(iVar1 + 0x30));
  Window_GadgetNotify_Slider_SetRange(param_1,0x441,0,100,0);
  if (*(int *)(iVar1 + 0x14c4) == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = *(undefined4 *)(iVar1 + 0x14cc);
  }
  Window_GadgetNotify_Slider_SetValue(param_1,0x441,uVar3,0);
  Window_GadgetNotify_Slider_SetRange(param_1,0x442,0,100,0);
  if (*(int *)(iVar1 + 0x14c4) == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = *(undefined4 *)(iVar1 + 0x14c8);
  }
  Window_GadgetNotify_Slider_SetValue(param_1,0x442,uVar3,0);
  Window_GadgetNotify_Slider_SetRange(param_1,0x443,-0x32,0x32,0);
  if (*(int *)(iVar1 + 0x14c4) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(iVar1 + 0x14d0);
  }
  Window_GadgetNotify_Slider_SetValue(param_1,0x443,uVar3,0);
  Window_GadgetNotify_Slider_SetRange(param_1,0x444,0,0x32,0);
  Window_GadgetNotify_Slider_SetValue(param_1,0x444,*(undefined4 *)(iVar1 + 0x14d4),0);
  Window_GadgetNotify_Slider_SetRange(param_1,3000,-0x32,0x32,0);
  if (*(int *)(iVar1 + 0x14c4) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(iVar1 + 0x14c0);
  }
  Window_GadgetNotify_Slider_SetValue(param_1,3000,uVar3,0);
  Window_GadgetNotify_Text_SetText(param_1,0x501,iVar2 + 8);
  Personnel_SetEmployeePhotoByKey(param_1,0x1f41,iVar2);
  CompanyProfile_UpdateRatingBars(param_1);
  return;
}

