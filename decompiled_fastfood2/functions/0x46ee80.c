// rea decompile_all
// name: FUN_0046ee80
// address: 0x46ee80
// body: available
// range: 0x46ee80-0x46f9b9 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_0046ee80(int *param_1)

{
  int iVar1;
  void *this;
  
  iVar1 = FUN_00523c90(DAT_0057c5e0,s_Pe_Endergebnis_Grafik_TGA_005672cc,&LAB_004c8ab0);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  iVar1 = FUN_0052f850(this,0x420,0xd,5,s_TIMESFONT_fnt_00563ea8,DAT_00580d88);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x420,0);
    FUN_0052f9d0(this,0x420,2,0x230,0,0);
  }
  iVar1 = FUN_0052f850(this,0x422,0x260,5,s_TIMESFONT_fnt_00563ea8,DAT_0058245c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x422,0);
    FUN_0052f9d0(this,0x422,2,0xb4,0,0);
  }
  iVar1 = FUN_0052f850(this,0x429,0xe0,0x1fe,s_VERDANA8_fnt_00563e98,s__Online_Hilfetext_005672b8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x429,0);
    FUN_0052f9d0(this,0x429,0,0x159,0x50,0);
  }
  iVar1 = FUN_0052f850(this,0x4a9,0x25f,0x7e,s_TIMES14_fnt_00564788,DAT_00582844);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4a9,0);
    FUN_0052f9d0(this,0x4a9,2,0xb4,0,0);
  }
  FUN_0052f5b0(this,0x4aa,0x2ea,0xce,s_SKBEWERTUNG_00_spr_00566174,1,0);
  FUN_0052f5b0(this,0x4ab,0x2ea,0xa2,s_SKBILANZ_00_spr_00565ad4,1,0);
  FUN_0052f5b0(this,0x4ac,0x266,0xa2,s_SKFILIALE_00_spr_005654fc,1,0);
  FUN_0052f5b0(this,0x4ae,0x2be,0xa2,s_SKPERSO_00_spr_00566154,1,0);
  FUN_0052f5b0(this,0x4af,0x2be,0xce,s_SKSYNDICATE_00_spr_00566140,1,0);
  FUN_0052f5b0(this,0x4b0,0x266,0xcf,s_SKWERBUNG_00_spr_0056612c,1,0);
  FUN_0052f5b0(this,0x4b1,0x292,0xce,s_SKREZEPT_00_spr_0056611c,1,0);
  FUN_0052f5b0(this,0x59b,0x292,0xa2,s_SKSTERN_00_spr_00566164,1,0);
  FUN_0052f5b0(this,0x4b8,0x260,0x123,s_PB14_00_spr_005642c4,1,0);
  FUN_0052f5b0(this,0x4b9,0x260,0x146,s_PB14_00_spr_005642c4,1,0);
  FUN_0052f5b0(this,0x4ba,0x260,0x169,s_PB14_00_spr_005642c4,1,0);
  FUN_0052f5b0(this,0x4bb,0x260,0x18c,s_PB14_00_spr_005642c4,1,0);
  FUN_0052f5b0(this,0x4bc,0x260,0x1af,s_PB14_00_spr_005642c4,1,0);
  FUN_0052f5b0(this,0x4bd,0x260,0x1d2,s_PB14_00_spr_005642c4,1,0);
  iVar1 = FUN_0052f850(this,0x4be,0x277,0x122,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4be,0xff);
    FUN_0052f9d0(this,0x4be,0,0x8c,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4bf,0x277,0x12e,s_VERDANA8_fnt_00563e98,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4bf,0xff);
    FUN_0052f9d0(this,0x4bf,0,0x37,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4c0,0x2ae,0x12e,s_VERDANA8_fnt_00563e98,s__16_000_000_00566110);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4c0,0xff);
    FUN_0052f9d0(this,0x4c0,1,0x55,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4c1,0x277,0x145,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4c1,0xff00a2);
    FUN_0052f9d0(this,0x4c1,0,0x8c,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4c2,0x277,0x151,s_VERDANA8_fnt_00563e98,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4c2,0xff00a2);
    FUN_0052f9d0(this,0x4c2,0,0x37,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4c3,0x2ae,0x151,s_VERDANA8_fnt_00563e98,s__16_000_000_00566110);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4c3,0xff00a2);
    FUN_0052f9d0(this,0x4c3,1,0x55,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4c4,0x277,0x168,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4c4,0xb29e);
    FUN_0052f9d0(this,0x4c4,0,0x8c,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4c5,0x277,0x174,s_VERDANA8_fnt_00563e98,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4c5,0xb29e);
    FUN_0052f9d0(this,0x4c5,0,0x37,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4c6,0x2ae,0x174,s_VERDANA8_fnt_00563e98,s__16_000_000_00566110);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4c6,0xb29e);
    FUN_0052f9d0(this,0x4c6,1,0x55,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4c7,0x277,0x18b,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4c7,0x9a00);
    FUN_0052f9d0(this,0x4c7,0,0x8c,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4c8,0x277,0x197,s_VERDANA8_fnt_00563e98,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4c8,0x9a00);
    FUN_0052f9d0(this,0x4c8,0,0x37,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4c9,0x2ae,0x197,s_VERDANA8_fnt_00563e98,s__16_000_000_00566110);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4c9,0x9a00);
    FUN_0052f9d0(this,0x4c9,1,0x55,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4ca,0x277,0x1ae,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4ca,0xce00df);
    FUN_0052f9d0(this,0x4ca,0,0x8c,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4cb,0x277,0x1ba,s_VERDANA8_fnt_00563e98,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4cb,0xce00df);
    FUN_0052f9d0(this,0x4cb,0,0x37,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4cc,0x2ae,0x1ba,s_VERDANA8_fnt_00563e98,s__16_000_000_00566110);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4cc,0xce00df);
    FUN_0052f9d0(this,0x4cc,1,0x55,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4cd,0x277,0x1d1,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4cd,0xe6e600);
    FUN_0052f9d0(this,0x4cd,0,0x8c,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4ce,0x277,0x1dd,s_VERDANA8_fnt_00563e98,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4ce,0xe6e600);
    FUN_0052f9d0(this,0x4ce,0,0x37,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4cf,0x2ae,0x1dd,s_VERDANA8_fnt_00563e98,s__16_000_000_00566110);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4cf,0xe6e600);
    FUN_0052f9d0(this,0x4cf,1,0x55,0xffff,0);
  }
  iVar1 = FUN_0052f690(this,0x4d0,0x265,0xfb,s_VERDANA8_fnt_00563e98,DAT_00580bcc,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x4d0,0,0,0);
    FUN_0052f7a0(this,0x4d0,2,0xa9,0,0,0xfffe);
  }
  FUN_00531c60(this,0x581,0x2a,0x47,0x1ec,400,0x10);
  iVar1 = FUN_0052f850(this,0x582,0x1b,0x2a,s_VERDANA8_fnt_00563e98,s__23000__00566108);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x582,0);
    FUN_0052f9d0(this,0x582,0,0x78,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x583,0x196,0x1e1,s_VERDANA8_fnt_00563e98,s__Aktuelles_Quartal_005660f4)
  ;
  if (iVar1 != 0) {
    FUN_0052f910(this,0x583,0);
    FUN_0052f9d0(this,0x583,1,0x96,0xffff,0);
  }
  FUN_00531850(this,0x58f,0x2ff,0x11d,s_LOGOS__07_spr_00564f20);
  FUN_00531850(this,0x590,0x2ff,0x141,s_LOGOS__01_spr_00564f10);
  FUN_00531850(this,0x591,0x2ff,0x164,s_LOGOS__02_spr_00564f00);
  FUN_00531850(this,0x592,0x2ff,0x185,s_LOGOS__05_spr_00564ef0);
  FUN_00531850(this,0x593,0x2ff,0x1ab,s_LOGOS__06_spr_00564ee0);
  FUN_00531850(this,0x594,0x300,0x1ce,s_LOGOS__08_spr_00564ed0);
  iVar1 = FUN_0052f690(this,0x597,0x253,0x1fd,s_TIMESFONT_fnt_00563ea8,DAT_00582a88,0,
                       s_TEXTPBTRANSPGELB_00_spr_00567208);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x597,0,0,0);
    FUN_0052f7a0(this,0x597,2,0xcc,0,0,0);
  }
  iVar1 = FUN_0052f690(this,0x598,0x253,0x227,s_TIMES14_fnt_00564788,DAT_00581b2c,0,
                       s_TEXTPBTRANSPGRUEN_00_spr_005671ec);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x598,0,0,0);
    FUN_0052f7a0(this,0x598,2,0xcc,0,0,0);
  }
  iVar1 = FUN_0052f690(this,0x599,0x253,0x4e,s_TIMESFONT_fnt_00563ea8,DAT_00581750,0,
                       s_TEXTPBTRANSPGELB_00_spr_00567208);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x599,0,0,0);
    FUN_0052f7a0(this,0x599,2,0xcc,0,0,0);
  }
  iVar1 = FUN_0052f690(this,0x59a,0x253,0x24,s_TIMESFONT_fnt_00563ea8,DAT_00580b38,0,
                       s_TEXTPBTRANSPGELB_00_spr_00567208);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x59a,0,0,0);
    FUN_0052f7a0(this,0x59a,2,0xcc,0,0,0);
  }
  return this;
}

