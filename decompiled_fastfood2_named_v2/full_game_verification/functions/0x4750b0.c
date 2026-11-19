// rea decompile_all
// name: Screen_SubStartMenu_A
// address: 0x4750b0
// body: available
// range: 0x4750b0-0x4756d3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl Screen_SubStartMenu_A(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = UI_CreateWindow(DAT_0057c5e0,0,0,s_PE_SUB_STARTSCREEN_spr_00567288,&LAB_004ce090);
  *param_1 = iVar1;
  this = (void *)UI_FindWindowByID(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddImage(this,0x444,0x265,0x113,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(this,0x445,0x265,0x128,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(this,0x446,0x265,0x13d,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(this,0x447,0x265,0x152,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(this,0x448,0x265,0x167,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(this,0x449,0x265,0x17c,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(this,0x44a,0x265,0x191,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(this,1099,0x265,0x1a6,s_TABPB01__00_spr_00564670,1,0);
  iVar1 = UI_AddText(this,0x440,0x25d,0xe0,s_TIMESFONT_fnt_00563ea8,DAT_00582470);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x440,0);
    Window_GadgetNotify_Text_SetLayout(this,0x440,2,0xbe,0,0);
  }
  iVar1 = UI_AddText(this,0x441,0x264,0x102,s_VERDANA8_fnt_00563e98,DAT_00581db8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x441,0);
    Window_GadgetNotify_Text_SetLayout(this,0x441,0,0xb4,0,0);
  }
  UI_AddImage(this,0x44c,0x265,0x1bb,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(this,0x44d,0x265,0x1d0,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(this,0x44e,0x265,0x1e5,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(this,0x44f,0x265,0x1fa,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(this,0x450,0x265,0x20f,s_TABPB01__00_spr_00564670,1,0);
  iVar1 = UI_AddText(this,0x453,0x26a,0x117,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x453,0);
    Window_GadgetNotify_Text_SetLayout(this,0x453,0,0x96,0,0);
  }
  iVar1 = UI_AddText(this,0x454,0x26a,300,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x454,0);
    Window_GadgetNotify_Text_SetLayout(this,0x454,0,0x96,0,0);
  }
  iVar1 = UI_AddText(this,0x455,0x26a,0x141,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x455,0);
    Window_GadgetNotify_Text_SetLayout(this,0x455,0,0x96,0,0);
  }
  iVar1 = UI_AddText(this,0x456,0x26a,0x156,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x456,0);
    Window_GadgetNotify_Text_SetLayout(this,0x456,0,0x96,0,0);
  }
  iVar1 = UI_AddText(this,0x457,0x26a,0x16b,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x457,0);
    Window_GadgetNotify_Text_SetLayout(this,0x457,0,0x96,0,0);
  }
  iVar1 = UI_AddText(this,0x458,0x26a,0x180,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x458,0);
    Window_GadgetNotify_Text_SetLayout(this,0x458,0,0x96,0,0);
  }
  iVar1 = UI_AddText(this,0x459,0x26a,0x195,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x459,0);
    Window_GadgetNotify_Text_SetLayout(this,0x459,0,0x96,0,0);
  }
  iVar1 = UI_AddText(this,0x45a,0x26a,0x1aa,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x45a,0);
    Window_GadgetNotify_Text_SetLayout(this,0x45a,0,0x96,0,0);
  }
  iVar1 = UI_AddText(this,0x45b,0x26a,0x1bf,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x45b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x45b,0,0x96,0,0);
  }
  iVar1 = UI_AddText(this,0x45c,0x26a,0x1d4,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x45c,0);
    Window_GadgetNotify_Text_SetLayout(this,0x45c,0,0x96,0,0);
  }
  iVar1 = UI_AddText(this,0x45d,0x26a,0x1e9,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x45d,0);
    Window_GadgetNotify_Text_SetLayout(this,0x45d,0,0x96,0,0);
  }
  iVar1 = UI_AddText(this,0x45e,0x26a,0x1fe,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x45e,0);
    Window_GadgetNotify_Text_SetLayout(this,0x45e,0,0x96,0,0);
  }
  iVar1 = UI_AddText(this,0x45f,0x26a,0x213,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x45f,0);
    Window_GadgetNotify_Text_SetLayout(this,0x45f,0,0x96,0,0);
  }
  iVar1 = UI_CreateSlider(this,0x462,0x30f,0x119,0x10e,s_SL01_00_spr_0056448c,0,1);
  if (iVar1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x462,&local_10);
  }
  return this;
}

