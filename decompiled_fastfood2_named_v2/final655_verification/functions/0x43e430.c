// rea decompile_all
// name: FUN_0043e430
// address: 0x43e430
// body: available
// range: 0x43e430-0x43edac inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_0043e430(int *param_1)

{
  int iVar1;
  void *this;
  
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0,0,s_STATISTIKBACKSPRITE_spr_00566188,&LAB_004b0920);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  iVar1 = FUN_0052f850(this,1000,0x25d,0xe1,s_TIMES14_fnt_00564788,DAT_00580ba4);
  if (iVar1 != 0) {
    FUN_0052f910(this,1000,0);
    FUN_0052f9d0(this,1000,0,0xbe,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x3e9,0x25d,0xfe,s_VERDANA8_fnt_00563e98,DAT_00581234);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x3e9,0);
    FUN_0052f9d0(this,0x3e9,0,0xbe,0xffff,0);
  }
  FUN_0052f5b0(this,0x3ea,0x2ea,0x139,s_SKBEWERTUNG_00_spr_00566174,1,0);
  FUN_0052f5b0(this,0x3eb,0x2ea,0x10e,s_SKBILANZ_00_spr_00565ad4,1,0);
  FUN_0052f5b0(this,0x3ec,0x266,0x10e,s_SKFILIALE_00_spr_005654fc,1,0);
  FUN_0052f5b0(this,0x3ed,0x292,0x10e,s_SKSTERN_00_spr_00566164,1,0);
  FUN_0052f5b0(this,0x3ee,0x2be,0x10e,s_SKPERSO_00_spr_00566154,1,0);
  FUN_0052f5b0(this,0x3ef,0x2be,0x139,s_SKSYNDICATE_00_spr_00566140,1,0);
  FUN_0052f5b0(this,0x3f0,0x266,0x13a,s_SKWERBUNG_00_spr_0056612c,1,0);
  FUN_0052f5b0(this,0x3f1,0x292,0x139,s_SKREZEPT_00_spr_0056611c,1,0);
  FUN_00531850(this,0x3f2,0x300,0x22f,s_LOGOS__08_spr_00564ed0);
  FUN_00531850(this,0x3f3,0x2ff,0x1a0,s_LOGOS__01_spr_00564f10);
  FUN_00531850(this,0x3f4,0x2ff,0x1c3,s_LOGOS__02_spr_00564f00);
  FUN_00531850(this,0x3f7,0x2ff,0x1e6,s_LOGOS__05_spr_00564ef0);
  FUN_00531850(this,0x3f8,0x2ff,0x20d,s_LOGOS__06_spr_00564ee0);
  FUN_00531850(this,0x3f9,0x2ff,0x17f,s_LOGOS__07_spr_00564f20);
  FUN_0052f5b0(this,0x3fa,0x260,0x182,s_PB14_00_spr_005642c4,1,0);
  FUN_0052f5b0(this,0x3fb,0x260,0x1a5,s_PB14_00_spr_005642c4,1,0);
  FUN_0052f5b0(this,0x3fc,0x260,0x1c8,s_PB14_00_spr_005642c4,1,0);
  FUN_0052f5b0(this,0x3fd,0x260,0x1eb,s_PB14_00_spr_005642c4,1,0);
  FUN_0052f5b0(this,0x3fe,0x260,0x20e,s_PB14_00_spr_005642c4,1,0);
  FUN_0052f5b0(this,0x3ff,0x260,0x231,s_PB14_00_spr_005642c4,1,0);
  iVar1 = FUN_0052f850(this,0x401,0x277,0x181,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x401,0xff);
    FUN_0052f9d0(this,0x401,0,0x8c,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x402,0x277,0x18d,s_VERDANA8_fnt_00563e98,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x402,0xff);
    FUN_0052f9d0(this,0x402,0,0x37,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x403,0x2ae,0x18d,s_VERDANA8_fnt_00563e98,s__16_000_000_00566110);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x403,0xff);
    FUN_0052f9d0(this,0x403,1,0x55,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x404,0x277,0x1a4,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x404,0xff00a2);
    FUN_0052f9d0(this,0x404,0,0x8c,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x405,0x277,0x1b0,s_VERDANA8_fnt_00563e98,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x405,0xff00a2);
    FUN_0052f9d0(this,0x405,0,0x37,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x406,0x2ae,0x1b0,s_VERDANA8_fnt_00563e98,s__16_000_000_00566110);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x406,0xff00a2);
    FUN_0052f9d0(this,0x406,1,0x55,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x407,0x277,0x1c7,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x407,0xb29e);
    FUN_0052f9d0(this,0x407,0,0x8c,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x408,0x277,0x1d3,s_VERDANA8_fnt_00563e98,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x408,0xb29e);
    FUN_0052f9d0(this,0x408,0,0x37,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x409,0x2ae,0x1d3,s_VERDANA8_fnt_00563e98,s__16_000_000_00566110);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x409,0xb29e);
    FUN_0052f9d0(this,0x409,1,0x55,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x40a,0x277,0x1ea,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x40a,0x9a00);
    FUN_0052f9d0(this,0x40a,0,0x8c,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x40b,0x277,0x1f6,s_VERDANA8_fnt_00563e98,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x40b,0x9a00);
    FUN_0052f9d0(this,0x40b,0,0x37,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x40c,0x2ae,0x1f6,s_VERDANA8_fnt_00563e98,s__16_000_000_00566110);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x40c,0x9a00);
    FUN_0052f9d0(this,0x40c,1,0x55,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x40d,0x277,0x20d,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x40d,0xce00df);
    FUN_0052f9d0(this,0x40d,0,0x8c,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x40e,0x277,0x219,s_VERDANA8_fnt_00563e98,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x40e,0xce00df);
    FUN_0052f9d0(this,0x40e,0,0x37,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x40f,0x2ae,0x219,s_VERDANA8_fnt_00563e98,s__16_000_000_00566110);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x40f,0xce00df);
    FUN_0052f9d0(this,0x40f,1,0x55,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x410,0x277,0x230,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x410,0x787800);
    FUN_0052f9d0(this,0x410,0,0x8c,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x411,0x277,0x23c,s_VERDANA8_fnt_00563e98,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x411,0x787800);
    FUN_0052f9d0(this,0x411,0,0x37,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x412,0x2ae,0x23c,s_VERDANA8_fnt_00563e98,s__16_000_000_00566110);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x412,0x787800);
    FUN_0052f9d0(this,0x412,1,0x55,0xffff,0);
  }
  UI_CreateBitmapGadget(this,0x413,0x35,0x5b,0x1ea,0x1a4,0x10);
  iVar1 = FUN_0052f850(this,0x414,0x20,0x42,s_VERDANA8_fnt_00563e98,s__23000__00566108);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x414,0);
    FUN_0052f9d0(this,0x414,0,0x78,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x415,0x193,0x204,s_VERDANA8_fnt_00563e98,s__Aktuelles_Quartal_005660f4)
  ;
  if (iVar1 != 0) {
    FUN_0052f910(this,0x415,0);
    FUN_0052f9d0(this,0x415,1,0x96,0xffff,0);
  }
  FUN_0052f5b0(this,8000,0x23c,0xd9,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  iVar1 = UI_AddTextButton(this,0x1f41,0x267,0x164,s_VERDANA8_fnt_00563e98,DAT_00580bcc,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x1f41,0,0,0);
    FUN_0052f7a0(this,0x1f41,2,0xa9,0,0,0xfffe);
  }
  return this;
}

