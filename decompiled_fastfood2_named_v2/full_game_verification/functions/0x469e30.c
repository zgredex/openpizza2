// rea decompile_all
// name: PestMenu_CreateWindow
// address: 0x469e30
// body: available
// range: 0x469e30-0x46a380 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl PestMenu_CreateWindow(int *param_1)

{
  int iVar1;
  void *this;
  
                    /* Creates the pest-control submenu window. */
  iVar1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004c5340);
  *param_1 = iVar1;
  this = (void *)UI_FindWindowByID(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(this,0x409,0x28,0x5d,s_TRENNZEILE_spr_00563eb8);
  iVar1 = UI_AddText(this,0x44f,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_005827cc);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x44f,0);
    Window_GadgetNotify_Text_SetLayout(this,0x44f,2,0xbe,0,0);
  }
  iVar1 = UI_AddText(this,0x458,0x42,0xc1,s_VERDANA10_fnt_00563e64,DAT_005829b8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x458,0);
    Window_GadgetNotify_Text_SetLayout(this,0x458,2,0x96,0xffff,0);
  }
  UI_AddImage(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  iVar1 = UI_AddText(this,0x1f43,0x34,0x25,s_VERDANA8_fnt_00563e98,DAT_005826b8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f43,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f43,0,0xb4,0x37,0);
  }
  iVar1 = UI_AddText(this,0x1f4e,0x55,0xfd,s_VERDANA8_fnt_00563e98,DAT_005814d8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f4e,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f4e,0,0x3c,0,0);
  }
  iVar1 = UI_AddText(this,0x1f4f,0x6c,0xfd,s_VERDANA8_fnt_00563e98,s__10000__00566300);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f4f,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f4f,1,0x5a,0,0);
  }
  UI_AddSprite(this,0x1f50,0x28,0x12a,s_TRENNZEILE_spr_00563eb8);
  iVar1 = UI_AddTextButton(this,0x1f51,0x61,0x110,s_VERDANA8_fnt_00563e98,s__Anfordern_00566b74,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x1f51,0,0,0);
    Gadget_SetButtonTextLayout(this,0x1f51,2,0x54,0,0,0xfffe);
  }
  UI_AddSprite(this,0x1f52,0xa5,0x14c,s_KAKERLAKE_spr_00566b64);
  UI_AddSprite(this,0x1f53,0x2b,0x14d,s_RATTE_spr_00566b58);
  UI_AddSprite(this,0x1f54,0x69,0x14b,s_WURM_spr_00566b4c);
  iVar1 = UI_AddText(this,0x1f55,0x48,0x167,s_VERDANA8_fnt_00563e98,&DAT_00566b44);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f55,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f55,1,0x23,0,0);
  }
  iVar1 = UI_AddText(this,0x1f5c,0x82,0x167,s_VERDANA8_fnt_00563e98,&DAT_00566b44);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f5c,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f5c,1,0x23,0,0);
  }
  iVar1 = UI_AddText(this,0x1f5d,0xc2,0x167,s_VERDANA8_fnt_00563e98,&DAT_00566b44);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f5d,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f5d,1,0x23,0,0);
  }
  UI_AddSprite(this,0x1f68,0x28,0xb7,s_TRENNZEILE_spr_00563eb8);
  iVar1 = UI_AddText(this,0x1f72,0x42,0xdd,s_VERDANA8_fnt_00563e98,DAT_00582f90);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f72,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f72,2,0x96,0x23,0);
  }
  iVar1 = UI_AddText(this,0x1f73,0x42,0x66,s_VERDANA10_fnt_00563e64,DAT_005829b8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f73,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f73,2,0x96,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x1f74,0x55,0x8c,s_VERDANA8_fnt_00563e98,DAT_005814d8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f74,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f74,0,0x3c,0,0);
  }
  iVar1 = UI_AddText(this,0x1f75,0x6c,0x8c,s_VERDANA8_fnt_00563e98,s__1000__00566320);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f75,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f75,1,0x5a,0,0);
  }
  iVar1 = UI_AddTextButton(this,0x1f76,0x61,0x9e,s_VERDANA8_fnt_00563e98,s__Anfordern_00566b74,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x1f76,0,0,0);
    Gadget_SetButtonTextLayout(this,0x1f76,2,0x54,0,0,0xfffe);
  }
  iVar1 = UI_AddText(this,0x1f77,0x42,0x7c,s_VERDANA8_fnt_00563e98,DAT_00582dec);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f77,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f77,2,0x96,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x1f78,0x31,0x134,s_VERDANA8_fnt_00563e98,DAT_00580ef0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f78,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f78,2,0xb4,0x1e,0);
  }
  return this;
}

