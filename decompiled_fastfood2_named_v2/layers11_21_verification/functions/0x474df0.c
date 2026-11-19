// rea decompile_all
// name: FUN_00474df0
// address: 0x474df0
// body: available
// range: 0x474df0-0x4750a2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_00474df0(int *param_1)

{
  int iVar1;
  void *this;
  char *pcVar2;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  char local_40 [64];
  
  iVar1 = FUN_004017f0(&DAT_0057c590,DAT_0057bb40,(int *)0x0);
  if (iVar1 == 0) {
    iVar1 = 0;
    pcVar2 = s_PE_MISSIONSBRIEFING_LON_tga_00567488;
  }
  else {
    pcVar2 = s_PE_MISSIONSBRIEFING__s_tga_005674a4;
  }
  FUN_0054dd83(local_40,(byte *)pcVar2,iVar1);
  iVar1 = Window_CreatePictureWindow(DAT_0057c5e0,local_40,&LAB_004cdcb0);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  iVar1 = FUN_0052f850(this,0x422,0x260,5,s_TIMESFONT_fnt_00563ea8,DAT_00582b08);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x422,0);
    Window_GadgetNotify_Text_SetLayout(this,0x422,2,0xb4,0,0);
  }
  iVar1 = FUN_0052f850(this,0x429,0xe0,0x1fe,s_VERDANA8_fnt_00563e98,s__Online_Hilfetext_005672b8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x429,0);
    Window_GadgetNotify_Text_SetLayout(this,0x429,0,0x159,0x50,0);
  }
  iVar1 = FUN_0052f850(this,0x42c,0x263,0xcb,s_VERDANA8_fnt_00563e98,
                       s__Missionsbeschreibung_00567470);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x42c,0);
    Window_GadgetNotify_Text_SetLayout(this,0x42c,0,0x9b,0x124,0);
  }
  iVar1 = FUN_0052f850(this,0x42d,0x260,0x21,s_TIMESFONT_fnt_00563ea8,s__Paris_00565798);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x42d,0);
    Window_GadgetNotify_Text_SetLayout(this,0x42d,2,0xb4,0,0);
  }
  iVar1 = FUN_0052fc00(this,0x42e,0x30c,0xd4,0x11d,s_SL01_00_spr_0056448c,0,1);
  if (iVar1 != 0) {
    local_50 = 0;
    local_4c = 0;
    local_48 = 0;
    local_44 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x42e,&local_50);
  }
  iVar1 = FUN_0052f690(this,0x433,0x253,0x1fd,s_TIMESFONT_fnt_00563ea8,DAT_00581adc,0,
                       s_TEXTPBTRANSPGELB_00_spr_00567208);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x433,0,0,0x330000);
    Gadget_SetButtonTextLayout(this,0x433,2,0xcc,0,0,0);
  }
  iVar1 = FUN_0052f690(this,0x434,0x253,0x226,s_TIMESFONT_fnt_00563ea8,DAT_00580eb8,0,
                       s_TEXTPBTRANSPGRUEN_00_spr_005671ec);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x434,0,0,0);
    Gadget_SetButtonTextLayout(this,0x434,2,0xcc,0,0,0);
  }
  FUN_00531c60(this,0x435,0x279,0x3e,0x80,0x7f,0x10);
  FUN_00531850(this,0x436,0x272,0x36,s_LOGOFENSTER_spr_005671a0);
  return this;
}

