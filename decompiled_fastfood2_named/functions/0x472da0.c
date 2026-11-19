// rea decompile_all
// name: Screen_FreePlaySetup
// address: 0x472da0
// body: available
// range: 0x472da0-0x474b8a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl Screen_FreePlaySetup(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
                    /* Builds the free-play/new-game setup screen from Pe_Freies_Spiel.tga. */
  iVar1 = FUN_00523c90(DAT_0057c5e0,s_Pe_Freies_Spiel_TGA_00567408,&LAB_004cc640);
  *param_1 = iVar1;
  this = (void *)UI_FindWindowByID(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddImage(this,0x3fa,0x7a,0x1ca,s_PB26_00_spr_00564610,0,0);
  UI_AddImage(this,0x3fb,0x9f,0x1ca,s_PB27_00_spr_005645fc,0,0);
  iVar1 = UI_AddText(this,0x406,0x261,0x1a9,s_TIMESFONT_fnt_00563ea8,DAT_00581e20);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x406,0);
    FUN_0052f9d0(this,0x406,2,0xb4,0,0);
  }
  iVar1 = FUN_0052fc00(this,0x407,0x269,0x1cd,0xaf,s_SL02_00_spr_005642d0,0,0);
  if (iVar1 != 0) {
    local_10 = 0xaa00;
    local_c = 0xffff;
    local_8 = 0xff;
    local_4 = 0;
    FUN_0052fcc0(this,0x407,&local_10);
  }
  iVar1 = UI_AddText(this,0x408,0x261,0x1de,s_VERDANA10_fnt_00563e64,DAT_00582bb8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x408,0);
    FUN_0052f9d0(this,0x408,2,0xb4,0,0);
  }
  iVar1 = UI_AddText(this,0x420,0xd,5,s_TIMESFONT_fnt_00563ea8,DAT_005815b8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x420,0);
    FUN_0052f9d0(this,0x420,2,0x230,0,0);
  }
  iVar1 = UI_AddText(this,0x422,0x260,5,s_TIMESFONT_fnt_00563ea8,DAT_00582e50);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x422,0);
    FUN_0052f9d0(this,0x422,2,0xb4,0,0);
  }
  iVar1 = UI_AddText(this,0x429,0xe0,0x1fe,s_VERDANA8_fnt_00563e98,s__Online_Hilfetext_005672b8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x429,0);
    FUN_0052f9d0(this,0x429,0,0x159,0x50,0);
  }
  UI_AddImage(this,0x431,0x9f,0x1dd,s_PB27_00_spr_005645fc,0,0);
  UI_AddImage(this,0x432,0x7a,0x1dd,s_PB26_00_spr_00564610,0,0);
  iVar1 = UI_AddText(this,0x433,0x181,0x1a9,s_TIMESFONT_fnt_00563ea8,DAT_00581a20);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x433,0);
    FUN_0052f9d0(this,0x433,2,0xb4,0,0);
  }
  iVar1 = FUN_0052fc00(this,0x434,0x189,0x1cd,0xaf,s_SL02_00_spr_005642d0,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xaa00;
    local_4 = 0;
    FUN_0052fcc0(this,0x434,&local_10);
  }
  iVar1 = UI_AddText(this,0x435,0x181,0x1de,s_VERDANA10_fnt_00563e64,DAT_005826e8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x435,0);
    FUN_0052f9d0(this,0x435,2,0xb4,0,0);
  }
  iVar1 = UI_AddText(this,0x436,0xc3,0x1a9,s_TIMESFONT_fnt_00563ea8,DAT_00580bac);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x436,0);
    FUN_0052f9d0(this,0x436,2,0xb4,0,0);
  }
  iVar1 = FUN_0052fc00(this,0x437,0xcb,0x1cd,0xaf,s_SL02_00_spr_005642d0,0,0);
  if (iVar1 != 0) {
    local_10 = 0xaa00;
    local_c = 0xffff;
    local_8 = 0xff;
    local_4 = 0;
    FUN_0052fcc0(this,0x437,&local_10);
  }
  iVar1 = UI_AddText(this,0x438,0xc3,0x1de,s_VERDANA10_fnt_00563e64,DAT_00582be8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x438,0);
    FUN_0052f9d0(this,0x438,2,0xb4,0,0);
  }
  iVar1 = UI_AddText(this,0x439,0x32,0x1a3,s_TIMES14_fnt_00564788,DAT_00581a44);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x439,0);
    FUN_0052f9d0(this,0x439,0,0x8c,0,0);
  }
  iVar1 = UI_AddText(this,0x43a,0x32,0x1b7,s_TIMES14_fnt_00564788,DAT_00581be8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x43a,0);
    FUN_0052f9d0(this,0x43a,0,0x8c,0,0);
  }
  iVar1 = UI_AddText(this,0x43b,0x32,0x1cb,s_TIMES14_fnt_00564788,DAT_005825fc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x43b,0);
    FUN_0052f9d0(this,0x43b,0,0x4c,0,0);
  }
  iVar1 = UI_AddText(this,0x43c,0x32,0x1df,s_TIMES14_fnt_00564788,DAT_00581bf0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x43c,0);
    FUN_0052f9d0(this,0x43c,0,0x4c,0,0);
  }
  iVar1 = UI_AddText(this,0x43d,0x91,0x1df,s_TIMES14_fnt_00564788,&DAT_00567404);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x43d,0);
    FUN_0052f9d0(this,0x43d,2,0xf,0,0);
  }
  iVar1 = UI_AddText(this,0x43e,0x91,0x1cb,s_TIMES14_fnt_00564788,&DAT_00564538);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x43e,0);
    FUN_0052f9d0(this,0x43e,2,0xf,0,0);
  }
  iVar1 = UI_AddText(this,0x43f,0x7c,0x2c,s_TIMESFONT_fnt_00563ea8,s__Spielername_00567178);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x43f,0);
    FUN_0052f9d0(this,0x43f,2,0xaa,0,0);
  }
  iVar1 = UI_AddText(this,0x440,0x7c,0x48,s_TIMES14_fnt_00564788,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x440,0);
    FUN_0052f9d0(this,0x440,2,0xaa,0,0);
  }
  iVar1 = UI_AddText(this,0x441,0x7c,0x68,s_TIMESFONT_fnt_00563ea8,s__Spielername_00567178);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x441,0);
    FUN_0052f9d0(this,0x441,2,0xaa,0,0);
  }
  iVar1 = UI_AddText(this,0x442,0x7c,0x84,s_TIMES14_fnt_00564788,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x442,0);
    FUN_0052f9d0(this,0x442,2,0xaa,0,0);
  }
  iVar1 = UI_AddText(this,0x443,0x7c,0xa4,s_TIMESFONT_fnt_00563ea8,s__Spielername_00567178);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x443,0);
    FUN_0052f9d0(this,0x443,2,0xaa,0,0);
  }
  iVar1 = UI_AddText(this,0x444,0x7c,0xc0,s_TIMES14_fnt_00564788,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x444,0);
    FUN_0052f9d0(this,0x444,2,0xaa,0,0);
  }
  iVar1 = UI_AddText(this,0x445,0x7c,0xe0,s_TIMESFONT_fnt_00563ea8,s__Spielername_00567178);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x445,0);
    FUN_0052f9d0(this,0x445,2,0xaa,0,0);
  }
  iVar1 = UI_AddText(this,0x446,0x7c,0xfc,s_TIMES14_fnt_00564788,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x446,0);
    FUN_0052f9d0(this,0x446,2,0xaa,0,0);
  }
  iVar1 = UI_AddText(this,0x447,0x7c,0x11c,s_TIMESFONT_fnt_00563ea8,s__Spielername_00567178);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x447,0);
    FUN_0052f9d0(this,0x447,2,0xaa,0,0);
  }
  iVar1 = UI_AddText(this,0x448,0x7c,0x138,s_TIMES14_fnt_00564788,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x448,0);
    FUN_0052f9d0(this,0x448,2,0xaa,0,0);
  }
  iVar1 = UI_AddText(this,0x449,0x7c,0x157,s_TIMESFONT_fnt_00563ea8,s__Spielername_00567178);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x449,0);
    FUN_0052f9d0(this,0x449,2,0xaa,0,0);
  }
  iVar1 = UI_AddText(this,0x44a,0x7c,0x173,s_TIMES14_fnt_00564788,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x44a,0);
    FUN_0052f9d0(this,0x44a,2,0xaa,0,0);
  }
  iVar1 = UI_AddText(this,1099,0x16e,0x2f,s_TIMES14_fnt_00564788,DAT_00581288);
  if (iVar1 != 0) {
    FUN_0052f910(this,1099,0);
    FUN_0052f9d0(this,1099,0,0x73,0,0);
  }
  iVar1 = UI_AddText(this,0x44d,0x16e,0x43,s_TIMES14_fnt_00564788,DAT_00582990);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x44d,0);
    FUN_0052f9d0(this,0x44d,0,0x73,0,0);
  }
  UI_AddImage(this,0x44e,0x1d9,0x2e,s_PB26_00_spr_00564610,0,0);
  UI_AddImage(this,0x44f,0x21e,0x2e,s_PB27_00_spr_005645fc,0,0);
  UI_AddImage(this,0x450,0x21e,0x41,s_PB27_00_spr_005645fc,0,0);
  UI_AddImage(this,0x451,0x1d9,0x41,s_PB26_00_spr_00564610,0,0);
  iVar1 = UI_AddText(this,0x452,0x1f2,0x43,s_TIMES14_fnt_00564788,&DAT_00567400);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x452,0);
    FUN_0052f9d0(this,0x452,2,0x2d,0,0);
  }
  iVar1 = UI_AddText(this,0x453,0x1f2,0x2f,s_TIMES14_fnt_00564788,&DAT_005673f8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x453,0);
    FUN_0052f9d0(this,0x453,2,0x2d,0,0);
  }
  iVar1 = UI_AddText(this,0x454,0x16e,0x6a,s_TIMES14_fnt_00564788,DAT_00581288);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x454,0);
    FUN_0052f9d0(this,0x454,0,0x73,0,0);
  }
  iVar1 = UI_AddText(this,0x455,0x16e,0x7e,s_TIMES14_fnt_00564788,DAT_00582990);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x455,0);
    FUN_0052f9d0(this,0x455,0,0x73,0,0);
  }
  UI_AddImage(this,0x456,0x1d9,0x69,s_PB26_00_spr_00564610,0,0);
  UI_AddImage(this,0x457,0x21e,0x69,s_PB27_00_spr_005645fc,0,0);
  UI_AddImage(this,0x458,0x21e,0x7c,s_PB27_00_spr_005645fc,0,0);
  UI_AddImage(this,0x459,0x1d9,0x7c,s_PB26_00_spr_00564610,0,0);
  iVar1 = UI_AddText(this,0x45a,0x1f2,0x7e,s_TIMES14_fnt_00564788,&DAT_00567400);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x45a,0);
    FUN_0052f9d0(this,0x45a,2,0x2d,0,0);
  }
  iVar1 = UI_AddText(this,0x45b,0x1f2,0x6a,s_TIMES14_fnt_00564788,&DAT_005673f8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x45b,0);
    FUN_0052f9d0(this,0x45b,2,0x2d,0,0);
  }
  iVar1 = UI_AddText(this,0x45c,0x16e,0xa6,s_TIMES14_fnt_00564788,DAT_00581288);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x45c,0);
    FUN_0052f9d0(this,0x45c,0,0x73,0,0);
  }
  iVar1 = UI_AddText(this,0x45d,0x16e,0xba,s_TIMES14_fnt_00564788,DAT_00582990);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x45d,0);
    FUN_0052f9d0(this,0x45d,0,0x73,0,0);
  }
  UI_AddImage(this,0x45e,0x1d9,0xa5,s_PB26_00_spr_00564610,0,0);
  UI_AddImage(this,0x45f,0x21e,0xa5,s_PB27_00_spr_005645fc,0,0);
  UI_AddImage(this,0x460,0x21e,0xb8,s_PB27_00_spr_005645fc,0,0);
  UI_AddImage(this,0x461,0x1d9,0xb8,s_PB26_00_spr_00564610,0,0);
  iVar1 = UI_AddText(this,0x462,0x1f2,0xba,s_TIMES14_fnt_00564788,&DAT_00567400);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x462,0);
    FUN_0052f9d0(this,0x462,2,0x2d,0,0);
  }
  iVar1 = UI_AddText(this,0x463,0x1f2,0xa6,s_TIMES14_fnt_00564788,&DAT_005673f8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x463,0);
    FUN_0052f9d0(this,0x463,2,0x2d,0,0);
  }
  iVar1 = UI_AddText(this,0x464,0x16e,0xe3,s_TIMES14_fnt_00564788,DAT_00581288);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x464,0);
    FUN_0052f9d0(this,0x464,0,0x73,0,0);
  }
  iVar1 = UI_AddText(this,0x465,0x16e,0xf7,s_TIMES14_fnt_00564788,DAT_00582990);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x465,0);
    FUN_0052f9d0(this,0x465,0,0x73,0,0);
  }
  UI_AddImage(this,0x466,0x1d9,0xe2,s_PB26_00_spr_00564610,0,0);
  UI_AddImage(this,0x467,0x21e,0xe2,s_PB27_00_spr_005645fc,0,0);
  UI_AddImage(this,0x468,0x21e,0xf5,s_PB27_00_spr_005645fc,0,0);
  UI_AddImage(this,0x469,0x1d9,0xf5,s_PB26_00_spr_00564610,0,0);
  iVar1 = UI_AddText(this,0x46a,0x1f2,0xf7,s_TIMES14_fnt_00564788,&DAT_00567400);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x46a,0);
    FUN_0052f9d0(this,0x46a,2,0x2d,0,0);
  }
  iVar1 = UI_AddText(this,0x46b,0x1f2,0xe3,s_TIMES14_fnt_00564788,&DAT_005673f8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x46b,0);
    FUN_0052f9d0(this,0x46b,2,0x2d,0,0);
  }
  iVar1 = UI_AddText(this,0x46c,0x16e,0x11f,s_TIMES14_fnt_00564788,DAT_00581288);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x46c,0);
    FUN_0052f9d0(this,0x46c,0,0x73,0,0);
  }
  iVar1 = UI_AddText(this,0x46d,0x16e,0x133,s_TIMES14_fnt_00564788,DAT_00582990);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x46d,0);
    FUN_0052f9d0(this,0x46d,0,0x73,0,0);
  }
  UI_AddImage(this,0x46e,0x1d9,0x11e,s_PB26_00_spr_00564610,0,0);
  UI_AddImage(this,0x46f,0x21e,0x11e,s_PB27_00_spr_005645fc,0,0);
  UI_AddImage(this,0x470,0x21e,0x131,s_PB27_00_spr_005645fc,0,0);
  UI_AddImage(this,0x471,0x1d9,0x131,s_PB26_00_spr_00564610,0,0);
  iVar1 = UI_AddText(this,0x472,0x1f2,0x133,s_TIMES14_fnt_00564788,&DAT_00567400);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x472,0);
    FUN_0052f9d0(this,0x472,2,0x2d,0,0);
  }
  iVar1 = UI_AddText(this,0x473,0x1f2,0x11f,s_TIMES14_fnt_00564788,&DAT_005673f8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x473,0);
    FUN_0052f9d0(this,0x473,2,0x2d,0,0);
  }
  iVar1 = UI_AddText(this,0x474,0x16e,0x15b,s_TIMES14_fnt_00564788,DAT_00581288);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x474,0);
    FUN_0052f9d0(this,0x474,0,0x73,0,0);
  }
  iVar1 = UI_AddText(this,0x475,0x16e,0x16f,s_TIMES14_fnt_00564788,DAT_00582990);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x475,0);
    FUN_0052f9d0(this,0x475,0,0x73,0,0);
  }
  UI_AddImage(this,0x476,0x1d9,0x15a,s_PB26_00_spr_00564610,0,0);
  UI_AddImage(this,0x477,0x21e,0x15a,s_PB27_00_spr_005645fc,0,0);
  UI_AddImage(this,0x478,0x21e,0x16d,s_PB27_00_spr_005645fc,0,0);
  UI_AddImage(this,0x479,0x1d9,0x16d,s_PB26_00_spr_00564610,0,0);
  iVar1 = UI_AddText(this,0x47a,0x1f2,0x16f,s_TIMES14_fnt_00564788,&DAT_00567400);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x47a,0);
    FUN_0052f9d0(this,0x47a,2,0x2d,0,0);
  }
  iVar1 = UI_AddText(this,0x47b,0x1f2,0x15b,s_TIMES14_fnt_00564788,&DAT_005673f8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x47b,0);
    FUN_0052f9d0(this,0x47b,2,0x2d,0,0);
  }
  UI_AddImage(this,0x47f,0x25c,0x22,s_PB22_00_spr_00564174,0,0);
  iVar1 = FUN_0052f690(this,0x480,0x270,0x23,s_VERDANA8_fnt_00563e98,s__Paris_00565798,0,
                       s_TEXTPB05__00_spr_00564160);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x480,0,0,0);
    FUN_0052f7a0(this,0x480,2,0x93,0,0,0xfffe);
  }
  UI_AddImage(this,0x481,0x2fd,0x22,s_PB24_00_spr_00564144,0,0);
  UI_AddImage(this,0x482,0x25c,0x119,s_PB22_00_spr_00564174,0,0);
  iVar1 = FUN_0052f690(this,0x483,0x270,0x11a,s_VERDANA8_fnt_00563e98,s__1__Spielziel_005673e8,0,
                       s_TEXTPB05__00_spr_00564160);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x483,0,0,0);
    FUN_0052f7a0(this,0x483,2,0x93,0,0,0xfffe);
  }
  UI_AddImage(this,0x484,0x2fd,0x119,s_PB24_00_spr_00564144,0,0);
  UI_AddImage(this,0x485,0x25c,0x147,s_PB22_00_spr_00564174,0,0);
  iVar1 = FUN_0052f690(this,0x486,0x270,0x148,s_VERDANA8_fnt_00563e98,s__2__Spielziel_005673d8,0,
                       s_TEXTPB05__00_spr_00564160);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x486,0,0,0);
    FUN_0052f7a0(this,0x486,2,0x93,0,0,0xfffe);
  }
  UI_AddImage(this,0x487,0x2fd,0x147,s_PB24_00_spr_00564144,0,0);
  UI_AddImage(this,0x488,0x25c,0x175,s_PB22_00_spr_00564174,0,0);
  iVar1 = FUN_0052f690(this,0x489,0x270,0x176,s_VERDANA8_fnt_00563e98,s__3__Spielziel_005673c8,0,
                       s_TEXTPB05__00_spr_00564160);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x489,0,0,0);
    FUN_0052f7a0(this,0x489,2,0x93,0,0,0xfffe);
  }
  UI_AddImage(this,0x48a,0x2fd,0x175,s_PB24_00_spr_00564144,0,0);
  iVar1 = UI_AddText(this,0x48b,0x25f,0x105,s_VERDANA10_fnt_00563e64,DAT_00582288);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x48b,0);
    FUN_0052f9d0(this,0x48b,2,0xb4,0,0);
  }
  iVar1 = UI_AddText(this,0x48c,0x25f,0x134,s_VERDANA10_fnt_00563e64,DAT_005826f8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x48c,0);
    FUN_0052f9d0(this,0x48c,2,0xb4,0,0);
  }
  iVar1 = UI_AddText(this,0x48d,0x25f,0x162,s_VERDANA10_fnt_00563e64,DAT_00582c64);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x48d,0);
    FUN_0052f9d0(this,0x48d,2,0xb4,0,0);
  }
  iVar1 = UI_AddText(this,0x48e,0x262,0xc3,s_VERDANA8_fnt_00563e98,DAT_00580be4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x48e,0);
    FUN_0052f9d0(this,0x48e,0,0xb4,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x48f,0x262,0xd1,s_VERDANA7_fnt_00563ec8,&DAT_005673c4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x48f,0);
    FUN_0052f9d0(this,0x48f,0,0xf,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x490,0x262,0xdc,s_VERDANA7_fnt_00563ec8,&DAT_00565544);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x490,0);
    FUN_0052f9d0(this,0x490,0,0xf,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x491,0x262,0xe8,s_VERDANA7_fnt_00563ec8,&DAT_00565540);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x491,0);
    FUN_0052f9d0(this,0x491,0,0xf,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x492,0x270,0xd1,s_VERDANA7_fnt_00563ec8,DAT_00582c20);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x492,0);
    FUN_0052f9d0(this,0x492,0,100,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x493,0x270,0xdc,s_VERDANA7_fnt_00563ec8,DAT_00582c20);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x493,0);
    FUN_0052f9d0(this,0x493,0,100,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x494,0x270,0xe8,s_VERDANA7_fnt_00563ec8,DAT_00582c20);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x494,0);
    FUN_0052f9d0(this,0x494,0,100,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x495,0x2c5,0xd1,s_VERDANA7_fnt_00563ec8,s_1_000_000_005673b8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x495,0);
    FUN_0052f9d0(this,0x495,1,0x50,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x496,0x2c5,0xdc,s_VERDANA7_fnt_00563ec8,s_1_000_000_005673b8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x496,0);
    FUN_0052f9d0(this,0x496,1,0x50,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x497,0x2c5,0xe8,s_VERDANA7_fnt_00563ec8,s_1_000_000_005673b8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x497,0);
    FUN_0052f9d0(this,0x497,1,0x50,0xffff,0);
  }
  UI_AddImage(this,0x49f,0x19,0xc5,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(this,0x4a0,0x19,0x101,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(this,0x4a1,0x19,0x13d,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(this,0x4a2,0x19,0x179,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(this,0x4a3,0x19,0x1a4,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(this,0x4a4,0x19,0x1b7,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(this,0x4a5,0x19,0x1ca,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(this,0x4a6,0x19,0x1de,s_PB14_00_spr_005642c4,1,0);
  UI_AddSprite(this,0x4bc,0x35,0x26,s_FOTORAHMEN00_spr_00564310);
  UI_AddSprite(this,0x4be,0x126,0x26,s_FOTORAHMEN00_spr_00564310);
  UI_AddSprite(this,0x4c0,0x35,0x62,s_FOTORAHMEN00_spr_00564310);
  UI_AddSprite(this,0x4c2,0x126,0x62,s_FOTORAHMEN00_spr_00564310);
  UI_AddSprite(this,0x4c4,0x35,0x9e,s_FOTORAHMEN00_spr_00564310);
  UI_AddSprite(this,0x4c6,0x126,0x9e,s_FOTORAHMEN00_spr_00564310);
  UI_AddSprite(this,0x4c8,0x35,0xda,s_FOTORAHMEN00_spr_00564310);
  UI_AddSprite(this,0x4ca,0x126,0xda,s_FOTORAHMEN00_spr_00564310);
  UI_AddSprite(this,0x4cc,0x35,0x116,s_FOTORAHMEN00_spr_00564310);
  UI_AddSprite(this,0x4ce,0x126,0x116,s_FOTORAHMEN00_spr_00564310);
  UI_AddSprite(this,0x4d0,0x35,0x152,s_FOTORAHMEN00_spr_00564310);
  UI_AddSprite(this,0x4d2,0x126,0x152,s_FOTORAHMEN00_spr_00564310);
  UI_AddSprite(this,0x4d3,0x3a,0x2b,s_FOTODUMMY00_spr_00564300);
  UI_AddSprite(this,0x4d4,0x3a,0x67,s_FOTODUMMY00_spr_00564300);
  UI_AddSprite(this,0x4d5,0x3a,0xdf,s_FOTODUMMY00_spr_00564300);
  UI_AddSprite(this,0x4d6,0x3a,0xa3,s_FOTODUMMY00_spr_00564300);
  UI_AddSprite(this,0x4d9,0x3a,0x11b,s_FOTODUMMY00_spr_00564300);
  UI_AddSprite(this,0x4da,0x3a,0x157,s_FOTODUMMY00_spr_00564300);
  UI_AddSprite(this,0x4db,299,0x2b,s_FOTODUMMY00_spr_00564300);
  UI_AddSprite(this,0x4dc,299,0x67,s_FOTODUMMY00_spr_00564300);
  UI_AddSprite(this,0x4dd,299,0xa3,s_FOTODUMMY00_spr_00564300);
  UI_AddSprite(this,0x4de,299,0xdf,s_FOTODUMMY00_spr_00564300);
  UI_AddSprite(this,0x4df,299,0x11b,s_FOTODUMMY00_spr_00564300);
  UI_AddSprite(this,0x4e0,299,0x157,s_FOTODUMMY00_spr_00564300);
  FUN_00531c60(this,0x4e1,0x279,0x3e,0x80,0x7f,0x10);
  iVar1 = FUN_0052f690(this,0x4e2,0x253,0x1fd,s_TIMESFONT_fnt_00563ea8,DAT_00582d40,0,
                       s_TEXTPBTRANSPGELB_00_spr_00567208);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x4e2,0,0,0);
    FUN_0052f7a0(this,0x4e2,2,0xcc,0,0,0);
  }
  iVar1 = FUN_0052f690(this,0x4e3,0x253,0x226,s_TIMESFONT_fnt_00563ea8,DAT_00581338,0,
                       s_TEXTPBTRANSPGRUEN_00_spr_005671ec);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x4e3,0,0,0);
    FUN_0052f7a0(this,0x4e3,2,0xcc,0,0,0);
  }
  UI_AddSprite(this,0x4e4,0x279,0x3d,s_PLAYLOG_2_01_00_spr_005671b0);
  UI_AddSprite(this,0x4e5,0x3a,0x2b,s_PLAYLOG_3_02_01_spr_00567300);
  UI_AddSprite(this,0x4e6,299,0x2b,s_PLAYLOG_3_03_01_spr_005673a4);
  UI_AddSprite(this,0x4e7,0x3a,0x67,s_PLAYLOG_3_02_01_spr_00567300);
  UI_AddSprite(this,0x4e8,299,0x67,s_PLAYLOG_3_03_01_spr_005673a4);
  UI_AddSprite(this,0x4e9,0x3a,0xdf,s_PLAYLOG_3_02_01_spr_00567300);
  UI_AddSprite(this,0x4ea,299,0xdf,s_PLAYLOG_3_03_01_spr_005673a4);
  UI_AddSprite(this,0x4eb,0x3a,0xa3,s_PLAYLOG_3_02_01_spr_00567300);
  UI_AddSprite(this,0x4ec,299,0xa3,s_PLAYLOG_3_03_01_spr_005673a4);
  UI_AddSprite(this,0x4ed,0x3a,0x11b,s_PLAYLOG_3_02_01_spr_00567300);
  UI_AddSprite(this,0x4ee,299,0x11b,s_PLAYLOG_3_03_01_spr_005673a4);
  UI_AddSprite(this,0x4ef,299,0x157,s_PLAYLOG_3_03_01_spr_005673a4);
  UI_AddSprite(this,0x4f0,0x3a,0x157,s_PLAYLOG_3_02_01_spr_00567300);
  UI_AddSprite(this,0x4f1,0x272,0x36,s_LOGOFENSTER_spr_005671a0);
  UI_AddImage(this,0x49e,0x19,0x87,s_PB14_00_spr_005642c4,1,0);
  return this;
}

