// rea decompile_all
// name: GameOptionsPage_Create
// address: 0x427270
// body: available
// range: 0x427270-0x427595 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl GameOptionsPage_Create(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
                    /* Creates the game settings page. */
  iVar1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004a22b0);
  *param_1 = iVar1;
  this = (void *)UI_FindWindowByID(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  iVar1 = UI_AddText(this,0x44f,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00581470);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x44f,0);
    Window_GadgetNotify_Text_SetLayout(this,0x44f,2,0xbe,0,0);
  }
  UI_AddImage(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  UI_AddSprite(this,0x1f50,0x27,0x14c,s_TRENNZEILE_spr_00563eb8);
  iVar1 = UI_AddTextButton(this,0x1f51,0x30,0x15b,s_VERDANA8_fnt_00563e98,DAT_00582748,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x1f51,0,0,0);
    Gadget_SetButtonTextLayout(this,0x1f51,2,0xb4,0,0,0xfffe);
  }
  iVar1 = UI_AddText(this,0x1f55,0x41,0x2b,s_VERDANA8_fnt_00563e98,DAT_00580be8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f55,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f55,2,0x96,0,0);
  }
  iVar1 = UI_AddText(this,0x1f56,0x40,0x67,s_VERDANA8_fnt_00563e98,DAT_00582040);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f56,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f56,2,0x96,0,0);
  }
  iVar1 = UI_CreateSlider(this,0x1f57,0x4c,0x41,0x8c,s_SL02_00_spr_005642d0,0,0);
  if (iVar1 != 0) {
    local_10 = 0xffff;
    local_c = 0xf300;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1f57,&local_10);
  }
  UI_AddImage(this,0x1f5a,0x5d,0x75,s_PB26_00_spr_00564610,0,0);
  iVar1 = UI_AddText(this,0x1f5b,0x76,0x76,s_TIMES14_fnt_00564788,&DAT_00564dcc);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f5b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f5b,2,0x2d,0,3);
  }
  UI_AddImage(this,0x1f5c,0xa2,0x75,s_PB27_00_spr_005645fc,0,0);
  UI_AddImage(this,0x1f5d,0x3d,0xad,s_PB14_00_spr_005642c4,1,0);
  iVar1 = UI_AddText(this,0x1f5e,0x56,0xaa,s_VERDANA8_fnt_00563e98,DAT_0058225c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f5e,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f5e,0,0x8c,0x1f,0);
  }
  UI_AddSprite(this,0x1f5f,0x27,0x94,s_TRENNZEILE_spr_00563eb8);
  iVar1 = UI_AddText(this,0x1f60,0x4b,0x47,s_VERDANA8_fnt_00563e98,DAT_00582e68);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f60,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f60,2,0x84,0,3);
  }
  return this;
}

