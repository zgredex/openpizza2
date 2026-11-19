// rea decompile_all
// name: FUN_0044d4a0
// address: 0x44d4a0
// body: available
// range: 0x44d4a0-0x44d8bf inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_0044d4a0(int *param_1)

{
  int iVar1;
  void *this;
  
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0,0,s_BG001_spr_00564840,&LAB_004ba580);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  FUN_00531850(this,0x1f4e,0x216,-2,s_MAUERBOGEN_spr_00564830);
  FUN_0052f5b0(this,0x3f5,0x264,3,s_PB22_00_spr_00564174,0,0);
  FUN_0052f5b0(this,0x3f6,0x2f7,3,s_PB24_00_spr_00564144,0,0);
  FUN_00531850(this,0x3ff,600,0xb2,s_HPB__00_spr_00564824);
  FUN_00531850(this,0x400,0x280,0xb2,s_HPB__01_spr_00564818);
  FUN_00531850(this,0x401,0x2a8,0xb2,s_HPB__02_spr_0056480c);
  FUN_00531850(this,0x402,0x2d0,0xb2,s_HPB__03_spr_00564800);
  FUN_00531850(this,0x403,0x2f8,0xb2,s_HPB__04_spr_005647f4);
  FUN_0052f5b0(this,0x3fa,599,0xb1,s_RB01_00_spr_005647e8,1,0);
  FUN_0052f5b0(this,0x3fb,0x27f,0xb1,s_RB02_00_spr_005647dc,1,0);
  FUN_0052f5b0(this,0x3fc,0x2a7,0xb1,s_RB03_00_spr_005647d0,1,0);
  FUN_0052f5b0(this,0x3fd,0x2cf,0xb1,s_RB04_00_spr_005647c4,1,0);
  FUN_0052f5b0(this,0x3fe,0x2f7,0xb1,s_RB05_00_spr_005647b8,1,0);
  FUN_0052f5b0(this,0x40c,0x27f,6,s_CITYBUT01_00_spr_005647a4,0,0);
  iVar1 = FUN_0052f850(this,0x40f,0x280,4,s_TIMESFONT_fnt_00563ea8,s_Paris_0056479c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x40f,0);
    Window_GadgetNotify_Text_SetLayout(this,0x40f,2,0x78,0,0);
  }
  iVar1 = FUN_0052f850(this,0x410,10,0x238,s_TIMES14_fnt_00564788,s_17_32_00564794);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x410,0);
    Window_GadgetNotify_Text_SetLayout(this,0x410,2,0x32,0,0);
  }
  FUN_00531a50(this,0x415,0x268,3,s_SPIDERANIM_ani_00564778);
  FUN_0052f5b0(this,8000,0x23c,0xd9,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  iVar1 = FUN_0052f850(this,0x42b,0xca,0x240,s_VERDANA10_fnt_00563e64,&DAT_00564774);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x42b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x42b,2,0,0xffff,0);
  }
  FUN_00531c60(this,0x430,0x58,0x240,0x6c,0x10,0x10);
  iVar1 = FUN_0052f850(this,0x1f41,0x68,0x230,s_VERDANA8_fnt_00563e98,s__32_11_2003_00564768);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f41,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f41,2,0x5b,0xffff,0);
  }
  FUN_00531a50(this,0x411,0x1b,0x227,s_KAKANIM2_ani_00564758);
  FUN_00531850(this,0x1f48,0xec,0x232,s_PLAYLOG_8_01_02_spr_00564744);
  FUN_00531850(this,0x1f49,0x2ff,0x35,s_STAR_01_spr_00564738);
  FUN_00531850(this,0x1f4a,0x2ff,0x49,s_STAR_01_spr_00564738);
  FUN_00531850(this,0x1f4b,0x2ff,0x5d,s_STAR_01_spr_00564738);
  FUN_00531850(this,0x1f4c,0x2ff,0x71,s_STAR_01_spr_00564738);
  FUN_00531850(this,0x1f4d,0x2ff,0x85,s_STAR_01_spr_00564738);
  FUN_00531a50(this,0x412,0x2fb,0x7c,s_KAKANIM_ani_0056472c);
  FUN_00531a50(this,0x413,0x2f4,0xbe,s_KAKANIM1_ani_0056471c);
  FUN_00531a50(this,0x414,0x2fb,0x1b,s_TOMATENANIM_ani_0056470c);
  return this;
}

