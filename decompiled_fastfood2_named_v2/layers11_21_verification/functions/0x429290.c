// rea decompile_all
// name: FUN_00429290
// address: 0x429290
// body: available
// range: 0x429290-0x429fae inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_00429290(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004a41e0);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  FUN_00531850(this,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x501,0x2b,5,s_TIMESFONT_fnt_00563ea8,DAT_00582be0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x501,0);
    Window_GadgetNotify_Text_SetLayout(this,0x501,2,0xbe,0,0);
  }
  FUN_00531850(this,0x519,0x27,0xf3,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x51a,0x30,0xfd,s_VERDANA8_fnt_00563e98,DAT_00582e50);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x51a,0);
    Window_GadgetNotify_Text_SetLayout(this,0x51a,0,100,0,0);
  }
  iVar1 = FUN_0052f850(this,0x51b,0x30,0x116,s_VERDANA8_fnt_00563e98,s__Pizza_Tingeltangel_0056510c)
  ;
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x51b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x51b,0,0x87,0,0);
  }
  FUN_00531850(this,0x51c,0xb5,0x104,s_LOGORAHMEN_00_spr_005650f8);
  FUN_00531c60(this,0x51f,0xb7,0x106,0x2c,0x1d,0x10);
  FUN_0052f5b0(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  FUN_00531850(this,0x2355,0x27,0x93,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x2373,0x31,0xc0,s_VERDANA7_fnt_00563ec8,DAT_00582df8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x2373,0);
    Window_GadgetNotify_Text_SetLayout(this,0x2373,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x2374,0xbc,0xc0,s_VERDANA7_fnt_00563ec8,&DAT_005650ac);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x2374,0);
    Window_GadgetNotify_Text_SetLayout(this,0x2374,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x2376,0x31,0x9a,s_VERDANA7_fnt_00563ec8,DAT_00582600);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x2376,0);
    Window_GadgetNotify_Text_SetLayout(this,0x2376,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x2377,0x31,0xb0,s_VERDANA7_fnt_00563ec8,DAT_00580cdc);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x2377,0);
    Window_GadgetNotify_Text_SetLayout(this,0x2377,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x2379,0xbc,0x9a,s_VERDANA7_fnt_00563ec8,&DAT_005650ac);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x2379,0);
    Window_GadgetNotify_Text_SetLayout(this,0x2379,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x237a,0x81,0xb0,s_VERDANA7_fnt_00563ec8,s__1_000_000__005650ec);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x237a,0);
    Window_GadgetNotify_Text_SetLayout(this,0x237a,1,100,0,0);
  }
  iVar1 = FUN_0052f850(this,0x237b,0x31,0xcb,s_VERDANA7_fnt_00563ec8,DAT_00582224);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x237b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x237b,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x237c,0x9a,0xcc,s_VERDANA7_fnt_00563ec8,DAT_00582300);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x237c,0);
    Window_GadgetNotify_Text_SetLayout(this,0x237c,0,0x37,0,0);
  }
  iVar1 = FUN_0052f850(this,0x237e,0x9a,0xd9,s_VERDANA7_fnt_00563ec8,DAT_00582544);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x237e,0);
    Window_GadgetNotify_Text_SetLayout(this,0x237e,0,0x37,0,0);
  }
  iVar1 = FUN_0052f850(this,0x237f,0x9a,0xe5,s_VERDANA7_fnt_00563ec8,DAT_00582474);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x237f,0);
    Window_GadgetNotify_Text_SetLayout(this,0x237f,0,0x37,0,0);
  }
  iVar1 = FUN_0052f850(this,0x2380,0xc6,0xcc,s_VERDANA7_fnt_00563ec8,&DAT_005650b4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x2380,0);
    Window_GadgetNotify_Text_SetLayout(this,0x2380,1,0x1e,0,0);
  }
  iVar1 = FUN_0052f850(this,0x2382,0xc6,0xd9,s_VERDANA7_fnt_00563ec8,&DAT_005650b8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x2382,0);
    Window_GadgetNotify_Text_SetLayout(this,0x2382,1,0x1e,0,0);
  }
  iVar1 = FUN_0052f850(this,0x2383,0xc6,0xe5,s_VERDANA7_fnt_00563ec8,&DAT_005650b8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x2383,0);
    Window_GadgetNotify_Text_SetLayout(this,0x2383,1,0x1e,0,0);
  }
  iVar1 = FUN_0052f850(this,0x2384,0x30,0x21,s_VERDANA10_fnt_00563e64,DAT_00581b78);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x2384,0);
    Window_GadgetNotify_Text_SetLayout(this,0x2384,0,0xbe,0,0);
  }
  FUN_0052f5b0(this,0x238a,0x2c,0x32,s_PB14_00_spr_005642c4,1,0);
  iVar1 = FUN_0052f850(this,0x2396,0x47,0x32,s_VERDANA7_fnt_00563ec8,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x2396,0xff);
    Window_GadgetNotify_Text_SetLayout(this,0x2396,0,0x73,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x2397,0x47,0x3b,s_VERDANA7_fnt_00563ec8,DAT_005825e4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x2397,0);
    Window_GadgetNotify_Text_SetLayout(this,0x2397,0,100,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x2398,0x52,0x3c,s_VERDANA7_fnt_00563ec8,s__100_000__00565098);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x2398,0);
    Window_GadgetNotify_Text_SetLayout(this,0x2398,1,100,0xffff,0);
  }
  FUN_0052f5b0(this,0x23a8,0x2c,0x4b,s_PB14_00_spr_005642c4,1,0);
  iVar1 = FUN_0052f850(this,0x23a9,0x47,0x4b,s_VERDANA7_fnt_00563ec8,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x23a9,0x6e00);
    Window_GadgetNotify_Text_SetLayout(this,0x23a9,0,0x73,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x23aa,0x47,0x54,s_VERDANA7_fnt_00563ec8,DAT_005825e4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x23aa,0);
    Window_GadgetNotify_Text_SetLayout(this,0x23aa,0,100,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x23ab,0x52,0x55,s_VERDANA7_fnt_00563ec8,s__100_000__00565098);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x23ab,0);
    Window_GadgetNotify_Text_SetLayout(this,0x23ab,1,100,0xffff,0);
  }
  FUN_0052f5b0(this,0x23ac,0x2c,99,s_PB14_00_spr_005642c4,1,0);
  iVar1 = FUN_0052f850(this,0x23ad,0x47,99,s_VERDANA7_fnt_00563ec8,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x23ad,0xff0000);
    Window_GadgetNotify_Text_SetLayout(this,0x23ad,0,0x73,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x23ae,0x47,0x6c,s_VERDANA7_fnt_00563ec8,DAT_005825e4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x23ae,0);
    Window_GadgetNotify_Text_SetLayout(this,0x23ae,0,100,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x23af,0x52,0x6d,s_VERDANA7_fnt_00563ec8,s__100_000__00565098);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x23af,0);
    Window_GadgetNotify_Text_SetLayout(this,0x23af,1,100,0xffff,0);
  }
  FUN_0052f5b0(this,0x23b0,0x2c,0x7b,s_PB14_00_spr_005642c4,1,0);
  iVar1 = FUN_0052f850(this,0x23b1,0x47,0x7b,s_VERDANA7_fnt_00563ec8,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x23b1,0x5db2);
    Window_GadgetNotify_Text_SetLayout(this,0x23b1,0,0x73,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x23b2,0x47,0x84,s_VERDANA7_fnt_00563ec8,DAT_005825e4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x23b2,0);
    Window_GadgetNotify_Text_SetLayout(this,0x23b2,0,100,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x23b3,0x52,0x85,s_VERDANA7_fnt_00563ec8,s__100_000__00565098);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x23b3,0);
    Window_GadgetNotify_Text_SetLayout(this,0x23b3,1,100,0xffff,0);
  }
  iVar1 = FUN_0052fc00(this,0x23b4,0xdd,0x3c,0x55,s_SL01_00_spr_0056448c,0,1);
  if (iVar1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x23b4,&local_10);
  }
  iVar1 = FUN_0052f850(this,0x23e0,0x31,0x131,s_VERDANA7_fnt_00563ec8,DAT_00582f74);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x23e0,0);
    Window_GadgetNotify_Text_SetLayout(this,0x23e0,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x23e1,0x31,0x13d,s_VERDANA7_fnt_00563ec8,DAT_0058263c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x23e1,0);
    Window_GadgetNotify_Text_SetLayout(this,0x23e1,0,0xa0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x23e2,0xbc,0x131,s_VERDANA7_fnt_00563ec8,&DAT_005650ac);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x23e2,0);
    Window_GadgetNotify_Text_SetLayout(this,0x23e2,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x23e3,0x80,0x13d,s_VERDANA7_fnt_00563ec8,&DAT_005650ac);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x23e3,0);
    Window_GadgetNotify_Text_SetLayout(this,0x23e3,1,100,0,0);
  }
  iVar1 = FUN_0052f850(this,0x23e8,0x31,0x148,s_VERDANA7_fnt_00563ec8,DAT_00582e18);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x23e8,0);
    Window_GadgetNotify_Text_SetLayout(this,0x23e8,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x23e9,0x31,0x153,s_VERDANA7_fnt_00563ec8,DAT_005829e0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x23e9,0);
    Window_GadgetNotify_Text_SetLayout(this,0x23e9,0,0xa0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x23ea,0xbc,0x148,s_VERDANA7_fnt_00563ec8,&DAT_005650ac);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x23ea,0);
    Window_GadgetNotify_Text_SetLayout(this,0x23ea,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x23eb,0x81,0x153,s_VERDANA7_fnt_00563ec8,&DAT_005650e8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x23eb,0);
    Window_GadgetNotify_Text_SetLayout(this,0x23eb,1,100,0,0);
  }
  iVar1 = FUN_0052f850(this,0x23ec,0x31,0x15f,s_VERDANA7_fnt_00563ec8,DAT_00582898);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x23ec,0);
    Window_GadgetNotify_Text_SetLayout(this,0x23ec,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x23ed,0x31,0x16a,s_VERDANA7_fnt_00563ec8,DAT_00581a54);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x23ed,0);
    Window_GadgetNotify_Text_SetLayout(this,0x23ed,0,0xa0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x23ee,0xbc,0x15f,s_VERDANA7_fnt_00563ec8,&DAT_005650ac);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x23ee,0);
    Window_GadgetNotify_Text_SetLayout(this,0x23ee,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x23ef,0x81,0x16a,s_VERDANA7_fnt_00563ec8,&DAT_0056508c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x23ef,0);
    Window_GadgetNotify_Text_SetLayout(this,0x23ef,1,100,0,0);
  }
  FUN_00531850(this,0x23f0,0xb7,0x106,s_PLAYLOG_8_01_02_spr_00564744);
  FUN_00531850(this,0x23f1,0xb5,0x2e,s_LOGOS__05_spr_00564ef0);
  FUN_00531850(this,0x23f2,0xb5,0x46,s_LOGOS__01_spr_00564f10);
  FUN_00531850(this,0x23f3,0xb6,0x5e,s_LOGOS__02_spr_00564f00);
  FUN_00531850(this,0x23f4,0xb7,0x76,s_LOGOS__03_spr_005650d8);
  iVar1 = FUN_0052f850(this,0x23f5,0x31,0xa5,s_VERDANA7_fnt_00563ec8,DAT_00582c44);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x23f5,0);
    Window_GadgetNotify_Text_SetLayout(this,0x23f5,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x23f6,0xbc,0xa5,s_VERDANA7_fnt_00563ec8,&DAT_005650ac);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x23f6,0);
    Window_GadgetNotify_Text_SetLayout(this,0x23f6,1,0x28,0,0);
  }
  return this;
}

