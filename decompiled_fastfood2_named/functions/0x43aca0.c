// rea decompile_all
// name: FUN_0043aca0
// address: 0x43aca0
// body: available
// range: 0x43aca0-0x43b932 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_0043aca0(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = UI_CreateWindow(DAT_0057c5e0,0,0,s_STATISTIKBACKSPRITENEUTRAL_spr_00565d44,&LAB_004aeb30);
  *param_1 = iVar1;
  this = (void *)UI_FindWindowByID(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  iVar1 = UI_AddText(this,1000,0x25d,0xdf,s_TIMESFONT_fnt_00563ea8,DAT_00582db4);
  if (iVar1 != 0) {
    FUN_0052f910(this,1000,0);
    FUN_0052f9d0(this,1000,2,0xbe,0xffff,0);
  }
  UI_AddImage(this,0x3e9,0x263,0xff,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(this,0x3ea,0x263,0x114,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(this,0x3eb,0x263,0x129,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(this,0x3ec,0x263,0x13e,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(this,0x3ed,0x263,0x153,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(this,0x3ee,0x263,0x168,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(this,0x3ef,0x263,0x17d,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(this,0x3f0,0x263,0x192,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(this,0x3f1,0x263,0x1a7,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(this,0x3f2,0x263,0x1bc,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(this,0x3f3,0x263,0x1d1,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(this,0x3f4,0x263,0x1e6,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(this,0x3f5,0x263,0x1fb,s_TABPB01__00_spr_00564670,1,0);
  iVar1 = FUN_0052fc00(this,0x3f6,0x30f,0x105,0x109,s_SL01_00_spr_0056448c,0,1);
  if (iVar1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    FUN_0052fcc0(this,0x3f6,&local_10);
  }
  UI_AddImage(this,0x3f7,700,0x220,s_SKBAUEN_00_spr_00565d34,1,0);
  UI_AddImage(this,0x3f8,0x28f,0x220,s_SKFILIALE_00_spr_005654fc,1,0);
  UI_AddImage(this,0x3f9,0x262,0x220,s_SKPEOPLE_00_spr_00565d24,1,0);
  UI_AddImage(this,0x3fa,0x2e9,0x220,s_SKSMILEY_00_spr_00565d14,1,0);
  UI_AddSprite(this,0x3fb,0x37,0x5a,s_GLOSSAR_BAUWERKEDUMMY_spr_00565cf8);
  iVar1 = UI_AddText(this,0x3fc,0xe9,0x39,s_VERDANA16_fnt_00565788,DAT_00581a80);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x3fc,0);
    FUN_0052f9d0(this,0x3fc,2,0x78,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x3fd,0xa5,0x57,s_VEDANA11_fnt_00564090,s__Baustelle_00565cec);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x3fd,0);
    FUN_0052f9d0(this,0x3fd,0,0x96,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x3fe,0xa5,0x70,s_VERDANA8_fnt_00563e98,
                     s__Blablablablablablablabla_00565cd0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x3fe,0);
    FUN_0052f9d0(this,0x3fe,0,0x186,0xb4,0);
  }
  iVar1 = UI_AddText(this,0x401,0x2d,0x136,s_VEDANA11_fnt_00564090,DAT_00582d9c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x401,0);
    FUN_0052f9d0(this,0x401,0,0x96,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x402,0x2d,0x154,s_VERDANA8_fnt_00563e98,DAT_00581054);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x402,0);
    FUN_0052f9d0(this,0x402,0,0xa0,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x403,0x2d,0x16b,s_VERDANA8_fnt_00563e98,DAT_00582d1c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x403,0);
    FUN_0052f9d0(this,0x403,0,0xa0,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x404,0x2d,0x182,s_VERDANA8_fnt_00563e98,DAT_00582524);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x404,0);
    FUN_0052f9d0(this,0x404,0,0xa0,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x405,0x2d,0x199,s_VERDANA8_fnt_00563e98,DAT_00582cb4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x405,0);
    FUN_0052f9d0(this,0x405,0,0xa0,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x406,0x2d,0x1b0,s_VERDANA8_fnt_00563e98,DAT_00580c58);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x406,0);
    FUN_0052f9d0(this,0x406,0,0xa0,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x407,0x2d,0x1c7,s_VERDANA8_fnt_00563e98,DAT_00581034);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x407,0);
    FUN_0052f9d0(this,0x407,0,0xa0,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x408,0x2d,0x1de,s_VERDANA8_fnt_00563e98,DAT_0058247c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x408,0);
    FUN_0052f9d0(this,0x408,0,0xa0,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x409,0x2d,0x1f5,s_VERDANA8_fnt_00563e98,DAT_0058113c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x409,0);
    FUN_0052f9d0(this,0x409,0,0xa0,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x40a,0xca,0x154,s_VERDANA8_fnt_00563e98,s__234__00565cc8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x40a,0);
    FUN_0052f9d0(this,0x40a,1,0x49,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x40b,0xca,0x16b,s_VERDANA8_fnt_00563e98,s__24_000__00565cbc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x40b,0);
    FUN_0052f9d0(this,0x40b,1,0x49,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x40c,0xca,0x182,s_VERDANA8_fnt_00563e98,s__1_Tag_00565cb4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x40c,0);
    FUN_0052f9d0(this,0x40c,1,0x49,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x40d,0xca,0x199,s_VERDANA8_fnt_00563e98,s__500__00565cac);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x40d,0);
    FUN_0052f9d0(this,0x40d,1,0x49,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x40e,0xca,0x1b0,s_VERDANA8_fnt_00563e98,s__16_000__00565ca0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x40e,0);
    FUN_0052f9d0(this,0x40e,1,0x49,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x40f,0xca,0x1c7,s_VERDANA8_fnt_00563e98,s__1_Tag_00565cb4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x40f,0);
    FUN_0052f9d0(this,0x40f,1,0x49,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x410,0xca,0x1de,s_VERDANA8_fnt_00563e98,&DAT_00565c98);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x410,0);
    FUN_0052f9d0(this,0x410,1,0x49,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x411,0xca,0x1f5,s_VERDANA8_fnt_00563e98,s__1750_Kg_00565c8c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x411,0);
    FUN_0052f9d0(this,0x411,1,0x49,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x41f,0x266,0x103,s_VERDANA8_fnt_00563e98,s__Kleine_Filiale_00565c7c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x41f,0);
    FUN_0052f9d0(this,0x41f,0,0x9b,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x420,0x266,0x118,s_VERDANA8_fnt_00563e98,s__Mittlere_Filiale_00565c68);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x420,0);
    FUN_0052f9d0(this,0x420,0,0x9b,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x421,0x266,0x12d,s_VERDANA8_fnt_00563e98,&DAT_00565c58);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x421,0);
    FUN_0052f9d0(this,0x421,0,0x9b,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x422,0x266,0x142,s_VERDANA8_fnt_00563e98,s__Kleines_Lager_00565c48);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x422,0);
    FUN_0052f9d0(this,0x422,0,0x9b,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x423,0x266,0x157,s_VERDANA8_fnt_00563e98,s__Mittleres_Lager_00565c34);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x423,0);
    FUN_0052f9d0(this,0x423,0,0x9b,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x424,0x266,0x16c,s_VERDANA8_fnt_00563e98,&DAT_00565c24);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x424,0);
    FUN_0052f9d0(this,0x424,0,0x9b,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x425,0x266,0x181,s_VERDANA8_fnt_00563e98,
                     s__Hauptquartier_Stufe_1_00565c0c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x425,0);
    FUN_0052f9d0(this,0x425,0,0x9b,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x426,0x266,0x196,s_VERDANA8_fnt_00563e98,
                     s__Hauptquartier_Stufe_2_00565bf4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x426,0);
    FUN_0052f9d0(this,0x426,0,0x9b,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x427,0x266,0x1ab,s_VERDANA8_fnt_00563e98,
                     s__Hauptquartier_Stufe_3_00565bdc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x427,0);
    FUN_0052f9d0(this,0x427,0,0x9b,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x428,0x266,0x1c0,s_VERDANA8_fnt_00563e98,
                     s__Hauptquartier_Stufe_4_00565bc4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x428,0);
    FUN_0052f9d0(this,0x428,0,0x9b,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x429,0x266,0x1d5,s_VERDANA8_fnt_00563e98,
                     s__Hauptquartier_Stufe_5_00565bac);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x429,0);
    FUN_0052f9d0(this,0x429,0,0x9b,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x42a,0x266,0x1ea,s_VERDANA8_fnt_00563e98,
                     s__Hauptquartier_Stufe_6_00565b94);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x42a,0);
    FUN_0052f9d0(this,0x42a,0,0x9b,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x42b,0x266,0x1ff,s_VERDANA8_fnt_00563e98,s__Polizeirevier_00565b84);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x42b,0);
    FUN_0052f9d0(this,0x42b,0,0x9b,0xffff,0);
  }
  UI_AddImage(this,8000,0x23c,0xd9,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  UI_AddSprite(this,0x1f42,0x31,0x55,s_GLOSSARRAHMEN_00_spr_00565b6c);
  iVar1 = UI_AddText(this,0x1f43,0x11e,0x136,s_VEDANA11_fnt_00564090,DAT_00581ac4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f43,0);
    FUN_0052f9d0(this,0x1f43,0,0xfa,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x1f44,0x11e,0x155,s_VERDANA8_fnt_00563e98,s__blabla_00565b64);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f44,0);
    FUN_0052f9d0(this,0x1f44,0,0x104,0xb9,0);
  }
  return this;
}

