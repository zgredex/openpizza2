// rea decompile_all
// name: Screen_SubStartMenu_B
// address: 0x46e960
// body: available
// range: 0x46e960-0x46ee75 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl Screen_SubStartMenu_B(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = UI_CreateWindow(DAT_0057c5e0,0,0,s_PE_SUB_STARTSCREEN_spr_00567288,&LAB_004c7f30);
  *param_1 = iVar1;
  this = (void *)UI_FindWindowByID(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  iVar1 = UI_AddText(this,0x440,0x25d,0xe0,s_TIMESFONT_fnt_00563ea8,DAT_00581878);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x440,0);
    Window_GadgetNotify_Text_SetLayout(this,0x440,2,0xbe,0,0);
  }
  iVar1 = UI_AddText(this,0x46e,0x272,0x113,s_VERDANA8_fnt_00563e98,DAT_00581df0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x46e,0);
    Window_GadgetNotify_Text_SetLayout(this,0x46e,2,0x96,0,0);
  }
  iVar1 = UI_AddText(this,0x514,0x272,0x133,s_VERDANA8_fnt_00563e98,DAT_00582ee0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x514,0);
    Window_GadgetNotify_Text_SetLayout(this,0x514,2,0x96,0,0);
  }
  iVar1 = UI_AddText(this,0x470,0x272,0x152,s_VERDANA8_fnt_00563e98,DAT_00580e94);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x470,0);
    Window_GadgetNotify_Text_SetLayout(this,0x470,2,0x96,0,0);
  }
  iVar1 = UI_CreateSlider(this,8000,0x27b,0x129,0x8c,s_SL02_00_spr_005642d0,0,0);
  if (iVar1 != 0) {
    local_10 = 0xffff;
    local_c = 0xf300;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,8000,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x1f41,0x27b,0x147,0x8c,s_SL02_00_spr_005642d0,0,0);
  if (iVar1 != 0) {
    local_10 = 0xffff;
    local_c = 0xf300;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1f41,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x1f42,0x27b,0x166,0x8c,s_SL02_00_spr_005642d0,0,0);
  if (iVar1 != 0) {
    local_10 = 0xffff;
    local_c = 0xf300;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1f42,&local_10);
  }
  iVar1 = UI_AddText(this,0x474,0x25c,0xff,s_VERDANA10_fnt_00563e64,DAT_0058128c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x474,0);
    Window_GadgetNotify_Text_SetLayout(this,0x474,2,0xbe,0,0);
  }
  UI_AddSprite(this,0x475,600,0x178,s_TRENNZEILE_spr_00563eb8);
  UI_AddImage(this,0x1f44,0x26d,0x19c,s_PB14_00_spr_005642c4,1,0);
  iVar1 = UI_AddText(this,0x477,0x287,0x19a,s_VERDANA8_fnt_00563e98,DAT_005824d8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x477,0);
    Window_GadgetNotify_Text_SetLayout(this,0x477,0,0x8c,0x1e,0);
  }
  iVar1 = UI_AddText(this,0x478,0x25c,0x183,s_VERDANA10_fnt_00563e64,DAT_00581878);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x478,0);
    Window_GadgetNotify_Text_SetLayout(this,0x478,2,0xbe,0,0);
  }
  iVar1 = UI_AddText(this,0x479,0x273,0x1c4,s_VERDANA8_fnt_00563e98,DAT_00581a30);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x479,0);
    Window_GadgetNotify_Text_SetLayout(this,0x479,2,0x96,0,0);
  }
  iVar1 = UI_CreateSlider(this,0x1f45,0x27e,0x1d9,0x8c,s_SL02_00_spr_005642d0,0,0);
  if (iVar1 != 0) {
    local_10 = 0xffff;
    local_c = 0xf300;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1f45,&local_10);
  }
  iVar1 = UI_AddText(this,0x1f46,0x274,0x1df,s_VERDANA8_fnt_00563e98,DAT_00580fb4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f46,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f46,2,0x96,0,0);
  }
  iVar1 = UI_AddText(this,0x47c,0x274,0x1fc,s_VERDANA8_fnt_00563e98,DAT_00580be8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x47c,0);
    Window_GadgetNotify_Text_SetLayout(this,0x47c,2,0x96,0,0);
  }
  iVar1 = UI_CreateSlider(this,0x1f47,0x27f,0x211,0x8c,s_SL02_00_spr_005642d0,0,0);
  if (iVar1 != 0) {
    local_10 = 0xffff;
    local_c = 0xf300;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1f47,&local_10);
  }
  iVar1 = UI_AddText(this,0x1f48,0x27e,0x216,s_VERDANA8_fnt_00563e98,DAT_00582e68);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f48,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f48,2,0x84,0,3);
  }
  return this;
}

