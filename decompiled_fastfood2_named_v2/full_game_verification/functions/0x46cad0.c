// rea decompile_all
// name: HelpTopicDialog_Create
// address: 0x46cad0
// body: available
// range: 0x46cad0-0x46cc66 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl HelpTopicDialog_Create(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
                    /* Creates the help-topic dialog. */
  iVar1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004c6730);
  *param_1 = iVar1;
  this = (void *)UI_FindWindowByID(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(this,0x429,0x27,0x14c,s_TRENNZEILE_spr_00563eb8);
  iVar1 = UI_AddText(this,0x42b,0x2b,5,s_TIMESFONT_fnt_00563ea8,s__Hilfethema_00566e24);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x42b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x42b,2,0xbe,0,0);
  }
  iVar1 = UI_AddText(this,0x42c,0x32,0x26,s_VERDANA7_fnt_00563ec8,
                     s__Hilfetext__26_Zeichen_je_Zeile__00566df8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x42c,0);
    Window_GadgetNotify_Text_SetLayout(this,0x42c,0,0xa0,0x122,3);
  }
  iVar1 = UI_AddTextButton(this,0x42e,0x8e,0x15b,s_VERDANA8_fnt_00563e98,DAT_00581adc,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x42e,0,0,0);
    Gadget_SetButtonTextLayout(this,0x42e,2,0x54,0,0,0xfffe);
  }
  UI_AddImage(this,0x1f41,0xb,-1,s_HILFEBUTTONOFFSNIP_00_spr_00566ddc,1,0);
  iVar1 = UI_CreateSlider(this,0x1f42,0xdc,0x40,0x109,s_SL01_00_spr_0056448c,0,1);
  if (iVar1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1f42,&local_10);
  }
  return this;
}

