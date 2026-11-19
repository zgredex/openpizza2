// rea decompile_all
// name: Screen_MissionGoals
// address: 0x42d990
// body: available
// range: 0x42d990-0x42dde0 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl Screen_MissionGoals(int *param_1)

{
  int iVar1;
  void *this;
  
                    /* Builds the mission-goals screen. */
  iVar1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004a7f80);
  *param_1 = iVar1;
  this = (void *)UI_FindWindowByID(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  iVar1 = UI_AddText(this,0x429,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00580e70);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x429,0);
    Window_GadgetNotify_Text_SetLayout(this,0x429,2,0xbe,0,0);
  }
  iVar1 = UI_AddText(this,0x42b,0x2f,0x25,s_VERDANA7_fnt_00563ec8,&DAT_005655bc);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x42b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x42b,0,0xb9,0xa0,0);
  }
  UI_AddImage(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  UI_AddSprite(this,0x1f41,0x27,0x14c,s_TRENNZEILE_spr_00563eb8);
  iVar1 = UI_AddTextButton(this,0x1f42,0x30,0x15b,s_VERDANA8_fnt_00563e98,DAT_00582ef4,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x1f42,0,0,0);
    Gadget_SetButtonTextLayout(this,0x1f42,2,0xb4,0,0,0xfffe);
  }
  iVar1 = UI_AddText(this,0x1f43,0x2f,200,s_VERDANA7_fnt_00563ec8,DAT_00582c58);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f43,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f43,0,0xb9,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x1f44,0x48,0xd6,s_VERDANA7_fnt_00563ec8,s__Retten_Sie_die_Welt__005655a4)
  ;
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f44,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f44,0,0xa0,0x19,0);
  }
  iVar1 = UI_AddText(this,0x1f45,0x48,0xf0,s_VERDANA7_fnt_00563ec8,&DAT_00565574);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f45,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f45,0,0xa0,0x19,0);
  }
  iVar1 = UI_AddText(this,0x1f46,0x48,0x10b,s_VERDANA7_fnt_00563ec8,
                     s__Achten_Sie_auf_eine_gesunde_Umw_0056554c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f46,0xaa00);
    Window_GadgetNotify_Text_SetLayout(this,0x1f46,0,0xa0,0x19,0);
  }
  iVar1 = UI_AddText(this,0x1f47,0x3b,0xd6,s_VERDANA7_fnt_00563ec8,&DAT_00565548);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f47,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f47,0,0xf,0x19,0);
  }
  iVar1 = UI_AddText(this,0x1f48,0x3b,0xf0,s_VERDANA7_fnt_00563ec8,&DAT_00565544);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f48,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f48,0,0xf,0x19,0);
  }
  iVar1 = UI_AddText(this,0x1f49,0x3b,0x10b,s_VERDANA7_fnt_00563ec8,&DAT_00565540);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f49,0xaa00);
    Window_GadgetNotify_Text_SetLayout(this,0x1f49,0,0xf,0x19,0);
  }
  iVar1 = UI_AddText(this,0x1f4a,0x2f,0x131,s_VERDANA7_fnt_00563ec8,DAT_00581578);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f4a,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f4a,0,0xb9,0x19,0);
  }
  iVar1 = UI_AddText(this,0x1f4b,0x8c,0x13d,s_VERDANA7_fnt_00563ec8,s__2_Jahre_00565534);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f4b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f4b,1,0x5a,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x1f4c,0x2f,0x125,s_VERDANA7_fnt_00563ec8,DAT_00582dac);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f4c,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f4c,0,0x78,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x1f4d,0x8c,0x125,s_VERDANA7_fnt_00563ec8,s__1000000___00565528);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f4d,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f4d,1,0x5a,0xffff,0);
  }
  return this;
}

