// rea decompile_all
// name: FUN_0044cc90
// address: 0x44cc90
// body: available
// range: 0x44cc90-0x44d493 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_0044cc90(int *param_1)

{
  int iVar1;
  void *this;
  
  iVar1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004b9ea0);
  *param_1 = iVar1;
  this = (void *)UI_FindWindowByID(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  iVar1 = UI_AddText(this,1000,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_005816b8);
  if (iVar1 != 0) {
    FUN_0052f910(this,1000,0);
    FUN_0052f9d0(this,1000,2,0xbe,0xffff,0);
  }
  UI_AddSprite(this,0x3e9,0x27,0x5c,s_TRENNZEILE_spr_00563eb8);
  iVar1 = UI_AddText(this,0x3ea,0x2d,0x23,s_VERDANA7_fnt_00563ec8,DAT_00581524);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x3ea,0);
    FUN_0052f9d0(this,0x3ea,0,0xbe,0x37,0);
  }
  iVar1 = UI_AddText(this,0x3eb,0x2c,0x65,s_VERDANA8_fnt_00563e98,DAT_00582438);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x3eb,0);
    FUN_0052f9d0(this,0x3eb,0,0xbe,0xffff,0);
  }
  UI_AddSprite(this,0x3ec,0x27,0x14c,s_TRENNZEILE_spr_00563eb8);
  UI_AddImage(this,0x3ed,0x2d,0x7c,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(this,0x3ee,0x2d,0x9f,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(this,0x3ef,0x2d,0xc2,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(this,0x3f0,0x2d,0xe5,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(this,0x3f1,0x2d,0x108,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(this,0x3f2,0x2d,299,s_PB14_00_spr_005642c4,1,0);
  UI_AddSprite(this,0x3f3,0xcd,0x76,s_LOGOS__01_spr_00564f10);
  UI_AddSprite(this,0x3f4,0xcd,0x99,s_LOGOS__02_spr_00564f00);
  UI_AddSprite(this,0x3f5,0xcd,0xbc,s_LOGOS__06_spr_00564ee0);
  UI_AddSprite(this,0x3f6,0xce,0xdf,s_LOGOS__05_spr_00564ef0);
  UI_AddSprite(this,0x3f7,0xce,0x103,s_LOGOS__04_spr_005664bc);
  UI_AddSprite(this,0x3f8,0xcd,0x126,s_LOGOS__07_spr_00564f20);
  iVar1 = FUN_0052f690(this,0x3f9,0x30,0x159,s_VERDANA8_fnt_00563e98,DAT_00581ba0,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x3f9,0,0,0);
    FUN_0052f7a0(this,0x3f9,2,0xb4,0,0,0xfffe);
  }
  iVar1 = UI_AddText(this,0x3fa,0x46,0x7a,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x3fa,0xff);
    FUN_0052f9d0(this,0x3fa,0,0x8c,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x400,0x46,0x87,s_VERDANA8_fnt_00563e98,DAT_00582080);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x400,0xff);
    FUN_0052f9d0(this,0x400,0,100,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x401,0x9f,0x87,s_VERDANA8_fnt_00563e98,&DAT_005664b8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x401,0xff);
    FUN_0052f9d0(this,0x401,1,0x32,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x402,0x46,0x9d,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x402,0xff0055);
    FUN_0052f9d0(this,0x402,0,0x8c,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x403,0x46,0xaa,s_VERDANA8_fnt_00563e98,DAT_00582080);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x403,0xff0055);
    FUN_0052f9d0(this,0x403,0,100,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x404,0x9f,0xaa,s_VERDANA8_fnt_00563e98,&DAT_005664b8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x404,0xff0055);
    FUN_0052f9d0(this,0x404,1,0x32,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x405,0x46,0xc0,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x405,0xa0a0);
    FUN_0052f9d0(this,0x405,0,0x8c,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x406,0x46,0xcd,s_VERDANA8_fnt_00563e98,DAT_00582080);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x406,0xa0a0);
    FUN_0052f9d0(this,0x406,0,100,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x407,0x9f,0xcd,s_VERDANA8_fnt_00563e98,&DAT_005664b8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x407,0xa0a0);
    FUN_0052f9d0(this,0x407,1,0x32,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x408,0x46,0xe3,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x408,0xae00);
    FUN_0052f9d0(this,0x408,0,0x8c,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x409,0x46,0xf0,s_VERDANA8_fnt_00563e98,DAT_00582080);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x409,0xae00);
    FUN_0052f9d0(this,0x409,0,100,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x40a,0x9f,0xf0,s_VERDANA8_fnt_00563e98,&DAT_005664b8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x40a,0xae00);
    FUN_0052f9d0(this,0x40a,1,0x32,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x40b,0x46,0x106,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x40b,0xff00ff);
    FUN_0052f9d0(this,0x40b,0,0x8c,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x40c,0x46,0x113,s_VERDANA8_fnt_00563e98,DAT_00582080);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x40c,0xff00ff);
    FUN_0052f9d0(this,0x40c,0,100,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x40d,0x9f,0x113,s_VERDANA8_fnt_00563e98,&DAT_005664b8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x40d,0xff00ff);
    FUN_0052f9d0(this,0x40d,1,0x32,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x40e,0x46,0x129,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x40e,0xffaa00);
    FUN_0052f9d0(this,0x40e,0,0x8c,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x40f,0x46,0x136,s_VERDANA8_fnt_00563e98,DAT_00582080);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x40f,0xffaa00);
    FUN_0052f9d0(this,0x40f,0,100,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x410,0x9f,0x136,s_VERDANA8_fnt_00563e98,&DAT_005664b8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x410,0xffaa00);
    FUN_0052f9d0(this,0x410,1,0x32,0xffff,0);
  }
  UI_AddImage(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  return this;
}

