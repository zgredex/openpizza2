// rea decompile_all
// name: FUN_00443ab0
// address: 0x443ab0
// body: available
// range: 0x443ab0-0x444eda inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_00443ab0(int *param_1)

{
  int iVar1;
  void *this;
  
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004b6400);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  iVar1 = FUN_0052f850(this,0x429,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00582a14);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x429,0);
    Window_GadgetNotify_Text_SetLayout(this,0x429,2,0xbe,0,0);
  }
  FUN_0052f5b0(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  iVar1 = FUN_0052f690(this,0x1f41,0x30,0x35,s_VERDANA8_fnt_00563e98,DAT_00581fbc,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x1f41,0,0,0);
    Gadget_SetButtonTextLayout(this,0x1f41,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f690(this,0x1f42,0x8e,0x35,s_VERDANA8_fnt_00563e98,DAT_005818c4,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x1f42,0,0,0);
    Gadget_SetButtonTextLayout(this,0x1f42,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f850(this,0x1f43,0x31,0x24,s_VERDANA10_fnt_00563e64,DAT_00581ae4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f43,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f43,0,0xb4,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f44,0x34,0x4a,s_VERDANA7_fnt_00563ec8,DAT_00581fc0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f44,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f44,0,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f45,0x5f,0x4a,s_VERDANA7_fnt_00563ec8,s__1000__00566320);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f45,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f45,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f46,0x34,0x54,s_VERDANA7_fnt_00563ec8,DAT_00582af4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f46,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f46,0,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f47,0x5f,0x54,s_VERDANA7_fnt_00563ec8,&DAT_00566318);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f47,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f47,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f4c,0x90,0x4a,s_VERDANA7_fnt_00563ec8,DAT_00581fc0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f4c,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f4c,0,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f4d,0xbb,0x4a,s_VERDANA7_fnt_00563ec8,s__1000__00566320);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f4d,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f4d,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f4e,0x90,0x54,s_VERDANA7_fnt_00563ec8,DAT_00582af4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f4e,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f4e,0,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f4f,0xbb,0x54,s_VERDANA7_fnt_00563ec8,&DAT_00566318);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f4f,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f4f,1,0x28,0,0);
  }
  iVar1 = FUN_0052f690(this,0x1f58,0x30,0x65,s_VERDANA8_fnt_00563e98,DAT_00582dbc,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x1f58,0,0,0);
    Gadget_SetButtonTextLayout(this,0x1f58,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f690(this,0x1f59,0x8e,0x65,s_VERDANA8_fnt_00563e98,DAT_00582ae0,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x1f59,0,0,0);
    Gadget_SetButtonTextLayout(this,0x1f59,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f850(this,0x1f5a,0x34,0x7a,s_VERDANA7_fnt_00563ec8,DAT_00581fc0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f5a,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f5a,0,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f5b,0x5f,0x7a,s_VERDANA7_fnt_00563ec8,s__1000__00566320);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f5b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f5b,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f5c,0x34,0x84,s_VERDANA7_fnt_00563ec8,DAT_00582af4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f5c,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f5c,0,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f5d,0x5f,0x84,s_VERDANA7_fnt_00563ec8,&DAT_00566318);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f5d,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f5d,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f5e,0x90,0x7a,s_VERDANA7_fnt_00563ec8,DAT_00581fc0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f5e,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f5e,0,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f5f,0xbb,0x7a,s_VERDANA7_fnt_00563ec8,s__1000__00566320);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f5f,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f5f,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f60,0x90,0x84,s_VERDANA7_fnt_00563ec8,DAT_00582af4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f60,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f60,0,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f61,0xbb,0x84,s_VERDANA7_fnt_00563ec8,&DAT_00566318);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f61,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f61,1,0x28,0,0);
  }
  FUN_00531850(this,0x1f62,0x27,0xf2,s_TRENNZEILE_spr_00563eb8);
  FUN_00531850(this,0x1f64,0x27,0x93,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x1f65,0x31,0x9b,s_VERDANA10_fnt_00563e64,DAT_00582e0c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f65,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f65,0,0xb4,0,0);
  }
  iVar1 = FUN_0052f690(this,0x1f66,0x30,0xac,s_VERDANA8_fnt_00563e98,DAT_00582b38,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x1f66,0,0,0);
    Gadget_SetButtonTextLayout(this,0x1f66,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f690(this,0x1f67,0x8e,0xac,s_VERDANA8_fnt_00563e98,DAT_00581e4c,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x1f67,0,0,0);
    Gadget_SetButtonTextLayout(this,0x1f67,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f850(this,0x1f69,0x34,0xc1,s_VERDANA7_fnt_00563ec8,DAT_00581fc0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f69,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f69,0,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f6a,0x5f,0xc1,s_VERDANA7_fnt_00563ec8,s__2000__00565158);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f6a,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f6a,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f6b,0x34,0xcb,s_VERDANA7_fnt_00563ec8,DAT_00582a40);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f6b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f6b,0,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f6c,0x5f,0xcb,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f6c,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f6c,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f6d,0x90,0xc1,s_VERDANA7_fnt_00563ec8,DAT_00581fc0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f6d,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f6d,0,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f6e,0xbb,0xc1,s_VERDANA7_fnt_00563ec8,s__4000__00566310);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f6e,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f6e,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f71,0x34,0xd5,s_VERDANA7_fnt_00563ec8,DAT_005811ec);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f71,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f71,0,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f72,0x5f,0xd5,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f72,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f72,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f75,0x90,0xcb,s_VERDANA7_fnt_00563ec8,DAT_00582a40);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f75,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f75,0,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f76,0xbb,0xcb,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f76,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f76,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f77,0x90,0xd5,s_VERDANA7_fnt_00563ec8,DAT_005811ec);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f77,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f77,0,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f78,0xbb,0xd5,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f78,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f78,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f79,0x34,0xe5,s_VERDANA7_fnt_00563ec8,DAT_005828e4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f79,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f79,0,0xa0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f7a,0xbb,0xe5,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f7a,0xff);
    Window_GadgetNotify_Text_SetLayout(this,0x1f7a,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f7b,0x31,0xfb,s_VERDANA10_fnt_00563e64,DAT_00582ba0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f7b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f7b,0,0x78,0,0);
  }
  iVar1 = FUN_0052f690(this,0x1f7c,0x30,0x10c,s_VERDANA8_fnt_00563e98,DAT_00582b60,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x1f7c,0,0,0);
    Gadget_SetButtonTextLayout(this,0x1f7c,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f690(this,0x1f7d,0x8e,0x10c,s_VERDANA8_fnt_00563e98,DAT_00582a80,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x1f7d,0,0,0);
    Gadget_SetButtonTextLayout(this,0x1f7d,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f850(this,0x1f7e,0x34,0x121,s_VERDANA7_fnt_00563ec8,DAT_00581fc0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f7e,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f7e,0,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f7f,0x5f,0x121,s_VERDANA7_fnt_00563ec8,s__5000__00566308);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f7f,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f7f,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f80,0x34,299,s_VERDANA7_fnt_00563ec8,DAT_00582a40);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f80,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f80,0,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f81,0x5f,299,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f81,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f81,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f82,0x90,0x121,s_VERDANA7_fnt_00563ec8,DAT_00581fc0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f82,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f82,0,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f83,0xbb,0x121,s_VERDANA7_fnt_00563ec8,s__5000__00566308);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f83,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f83,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f84,0x34,0x135,s_VERDANA7_fnt_00563ec8,DAT_005811ec);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f84,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f84,0,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f85,0x5f,0x135,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f85,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f85,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f86,0x90,299,s_VERDANA7_fnt_00563ec8,DAT_00582a40);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f86,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f86,0,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f87,0xbb,299,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f87,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f87,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f88,0x90,0x135,s_VERDANA7_fnt_00563ec8,DAT_005811ec);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f88,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f88,0,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f89,0xbb,0x135,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f89,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f89,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f8a,0xab,0xfd,s_VERDANA7_fnt_00563ec8,DAT_0058258c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f8a,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f8a,0,0x2d,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f8b,0xcf,0xfd,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f8b,0xff);
    Window_GadgetNotify_Text_SetLayout(this,0x1f8b,1,0x14,0,0);
  }
  iVar1 = FUN_0052f690(this,0x1f9a,0x30,0x143,s_VERDANA8_fnt_00563e98,DAT_00582610,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x1f9a,0,0,0);
    Gadget_SetButtonTextLayout(this,0x1f9a,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f690(this,0x1f9b,0x8e,0x143,s_VERDANA8_fnt_00563e98,DAT_00582ba4,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x1f9b,0,0,0);
    Gadget_SetButtonTextLayout(this,0x1f9b,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f850(this,0x1f9c,0x34,0x158,s_VERDANA7_fnt_00563ec8,DAT_00581fc0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f9c,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f9c,0,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f9d,0x5f,0x158,s_VERDANA7_fnt_00563ec8,s__10000__00566300);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f9d,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f9d,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f9e,0x34,0x162,s_VERDANA7_fnt_00563ec8,DAT_00582a40);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f9e,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f9e,0,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f9f,0x5f,0x162,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f9f,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f9f,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fa0,0x90,0x158,s_VERDANA7_fnt_00563ec8,DAT_00581fc0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fa0,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fa0,0,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fa1,0xbb,0x158,s_VERDANA7_fnt_00563ec8,s__10000__00566300);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fa1,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fa1,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fa2,0x34,0x16c,s_VERDANA7_fnt_00563ec8,DAT_005811ec);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fa2,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fa2,0,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fa3,0x5f,0x16c,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fa3,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fa3,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fa4,0x90,0x162,s_VERDANA7_fnt_00563ec8,DAT_00582a40);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fa4,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fa4,0,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fa5,0xbb,0x162,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fa5,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fa5,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fa6,0x90,0x16c,s_VERDANA7_fnt_00563ec8,DAT_005811ec);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fa6,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fa6,0,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fa7,0xbb,0x16c,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fa7,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fa7,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fa8,0xe3,0xfd,s_VERDANA7_fnt_00563ec8,&DAT_005662fc);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fa8,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fa8,1,5,0,0);
  }
  return this;
}

