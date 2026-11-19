// rea decompile_all
// name: CityMapView_CreateWindow
// address: 0x430a80
// body: available
// range: 0x430a80-0x430ecb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl CityMapView_CreateWindow(int *param_1)

{
  int iVar1;
  void *this;
  
                    /* Creates the main city-map window and rating bars. */
  iVar1 = UI_CreateWindow(DAT_0057c5e0,0,0,s_BG001_spr_00564840,&LAB_004a9690);
  *param_1 = iVar1;
  this = (void *)UI_FindWindowByID(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(this,0x1f42,0x216,-2,s_MAUERBOGEN_spr_00564830);
  UI_AddSprite(this,0x3ff,600,0xb2,s_HPB__00_spr_00564824);
  UI_AddSprite(this,0x400,0x280,0xb2,s_HPB__01_spr_00564818);
  UI_AddSprite(this,0x401,0x2a8,0xb2,s_HPB__02_spr_0056480c);
  UI_AddSprite(this,0x402,0x2d0,0xb2,s_HPB__03_spr_00564800);
  UI_AddSprite(this,0x403,0x2f8,0xb2,s_HPB__04_spr_005647f4);
  UI_AddImage(this,0x3fa,599,0xb1,s_RB01_00_spr_005647e8,1,0);
  UI_AddImage(this,0x3fb,0x27f,0xb1,s_RB02_00_spr_005647dc,1,0);
  UI_AddImage(this,0x3fc,0x2a7,0xb1,s_RB03_00_spr_005647d0,1,0);
  UI_AddImage(this,0x3fd,0x2cf,0xb1,s_RB04_00_spr_005647c4,1,0);
  UI_AddImage(this,0x3fe,0x2f7,0xb1,s_RB05_00_spr_005647b8,1,0);
  UI_CreateBitmapGadget(this,0x431,0xec,0x232,0x2c,0x1d,0x10);
  iVar1 = UI_AddText(this,0x40f,0x27f,4,s_TIMESFONT_fnt_00563ea8,s_Paris_0056479c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x40f,0);
    Window_GadgetNotify_Text_SetLayout(this,0x40f,2,0x78,0,0);
  }
  iVar1 = UI_AddText(this,0x410,10,0x238,s_TIMES14_fnt_00564788,s_17_32_00564794);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x410,0);
    Window_GadgetNotify_Text_SetLayout(this,0x410,2,0x32,0,0);
  }
  UI_CreateAnimationWindow(this,0x415,0x268,3,s_SPIDERANIM_ani_00564778);
  UI_AddImage(this,8000,0x23c,0xd9,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  iVar1 = UI_AddText(this,0x42b,0xca,0x240,s_VERDANA10_fnt_00563e64,&DAT_00564774);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x42b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x42b,2,0,0xffff,0);
  }
  UI_CreateBitmapGadget(this,0x430,0x58,0x240,0x6c,0x10,0x10);
  iVar1 = UI_AddText(this,0x1f41,0x68,0x230,s_VERDANA8_fnt_00563e98,s__32_11_2003_00564768);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f41,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f41,2,0x5b,0xffff,0);
  }
  UI_CreateAnimationWindow(this,0x411,0x1b,0x227,s_KAKANIM2_ani_00564758);
  UI_AddSprite(this,0x1f48,0xec,0x232,s_PLAYLOG_8_01_02_spr_00564744);
  UI_AddSprite(this,0x1f4c,0x300,0x3c,s_ZOOMUEBER_P_spr_005657e0);
  UI_AddSprite(this,0x1f4d,0x300,0x5f,s_ZOOMUEBER_N_spr_005657d0);
  UI_AddImage(this,0x1f49,0x300,0x5b,s_ZOOM_N_00_spr_005657c0,0,0);
  UI_AddImage(this,0x1f4b,0x300,0x38,s_ZOOM_P_00_spr_005657b0,0,0);
  UI_AddSprite(this,0x1f4e,0,0,s_HSCREENZOOM_spr_005657a0);
  iVar1 = UI_AddText(this,0x1f4f,1,0x209,s_VERDANA16_fnt_00565788,s__Paris_00565798);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f4f,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f4f,2,0x253,0xffff,0);
  }
  UI_AddImage(this,0x1f50,0x300,0x7e,s_KARTE_ON_OFF_00_spr_00565774,1,0);
  UI_CreateAnimationWindow(this,0x414,0x2f4,0xbe,s_KAKANIM1_ani_0056471c);
  UI_CreateAnimationWindow(this,0x413,0x2fb,0x1b,s_TOMATENANIM_ani_0056470c);
  UI_CreateAnimationWindow(this,0x412,0x2fb,0x7c,s_KAKANIM_ani_0056472c);
  return this;
}

