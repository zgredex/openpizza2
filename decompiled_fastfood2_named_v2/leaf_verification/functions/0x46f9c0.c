// rea decompile_all
// name: FUN_0046f9c0
// address: 0x46f9c0
// body: available
// range: 0x46f9c0-0x472d94 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_0046f9c0(int *param_1)

{
  int iVar1;
  void *this;
  
  iVar1 = FUN_00523c90(DAT_0057c5e0,s_Pe_Endergebnis_Punkte_tga_00567370,&LAB_004cad80);
  *param_1 = iVar1;
  this = (void *)UI_FindWindowByID(DAT_0057c5e0,iVar1,(int *)0x0);
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
  FUN_0052f5b0(this,0x5a7,0x292,0xa2,s_SKSTERN_00_spr_00566164,1,0);
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
  iVar1 = FUN_0052f850(this,0x4d1,0x22,0x2c,s_VERDANA8_fnt_00563e98,&DAT_00567364);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4d1,0);
    FUN_0052f9d0(this,0x4d1,0,0x66,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4d2,0x6e,0x2c,s_VERDANA8_fnt_00563e98,s__Filiale__00567358);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4d2,0);
    FUN_0052f9d0(this,0x4d2,2,0x69,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4d3,0xdc,0x2c,s_VERDANA8_fnt_00563e98,s__Lager__00567350);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4d3,0);
    FUN_0052f9d0(this,0x4d3,2,0x70,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4d4,0x150,0x2c,s_VERDANA8_fnt_00563e98,s__Polizei__00567344);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4d4,0);
    FUN_0052f9d0(this,0x4d4,2,0x69,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4d5,0x1c0,0x2c,s_VERDANA8_fnt_00563e98,s__Hauptquartier__00567334);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4d5,0);
    FUN_0052f9d0(this,0x4d5,2,0x69,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4d6,0x6e,0x4c,s_VERDANA7_fnt_00563ec8,s__gemietet__00567328);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4d6,0);
    FUN_0052f9d0(this,0x4d6,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4d7,0x6e,0x5b,s_VERDANA7_fnt_00563ec8,s__gebaut__0056731c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4d7,0);
    FUN_0052f9d0(this,0x4d7,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4d8,0x6e,0x6f,s_VERDANA7_fnt_00563ec8,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4d8,0);
    FUN_0052f9d0(this,0x4d8,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4d9,0xa0,0x6f,s_VERDANA7_fnt_00563ec8,s__20_000_00567314);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4d9,0);
    FUN_0052f9d0(this,0x4d9,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4da,0xa0,0x5b,s_VERDANA7_fnt_00563ec8,&DAT_00565078);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4da,0);
    FUN_0052f9d0(this,0x4da,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4db,0xa0,0x4c,s_VERDANA7_fnt_00563ec8,&DAT_0056508c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4db,0);
    FUN_0052f9d0(this,0x4db,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4dc,0x6e,0x94,s_VERDANA7_fnt_00563ec8,s__gemietet__00567328);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4dc,0);
    FUN_0052f9d0(this,0x4dc,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4dd,0x6e,0xa3,s_VERDANA7_fnt_00563ec8,s__gebaut__0056731c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4dd,0);
    FUN_0052f9d0(this,0x4dd,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4de,0x6e,0xb7,s_VERDANA7_fnt_00563ec8,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4de,0);
    FUN_0052f9d0(this,0x4de,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4df,0xa0,0xb7,s_VERDANA7_fnt_00563ec8,s__20_000_00567314);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4df,0);
    FUN_0052f9d0(this,0x4df,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4e0,0xa0,0xa3,s_VERDANA7_fnt_00563ec8,&DAT_00565078);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4e0,0);
    FUN_0052f9d0(this,0x4e0,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4e1,0xa0,0x94,s_VERDANA7_fnt_00563ec8,&DAT_0056508c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4e1,0);
    FUN_0052f9d0(this,0x4e1,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4e2,0x6e,0xda,s_VERDANA7_fnt_00563ec8,s__gemietet__00567328);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4e2,0);
    FUN_0052f9d0(this,0x4e2,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4e3,0x6e,0xe9,s_VERDANA7_fnt_00563ec8,s__gebaut__0056731c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4e3,0);
    FUN_0052f9d0(this,0x4e3,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4e4,0x6e,0xfd,s_VERDANA7_fnt_00563ec8,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4e4,0);
    FUN_0052f9d0(this,0x4e4,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4e5,0xa0,0xfd,s_VERDANA7_fnt_00563ec8,s__20_000_00567314);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4e5,0);
    FUN_0052f9d0(this,0x4e5,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4e6,0xa0,0xe9,s_VERDANA7_fnt_00563ec8,&DAT_00565078);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4e6,0);
    FUN_0052f9d0(this,0x4e6,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4e7,0xa0,0xda,s_VERDANA7_fnt_00563ec8,&DAT_0056508c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4e7,0);
    FUN_0052f9d0(this,0x4e7,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4e8,0x6e,0x122,s_VERDANA7_fnt_00563ec8,s__gemietet__00567328);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4e8,0);
    FUN_0052f9d0(this,0x4e8,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4e9,0x6e,0x131,s_VERDANA7_fnt_00563ec8,s__gebaut__0056731c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4e9,0);
    FUN_0052f9d0(this,0x4e9,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4ea,0x6e,0x145,s_VERDANA7_fnt_00563ec8,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4ea,0);
    FUN_0052f9d0(this,0x4ea,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4eb,0xa0,0x145,s_VERDANA7_fnt_00563ec8,s__20_000_00567314);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4eb,0);
    FUN_0052f9d0(this,0x4eb,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4ec,0xa0,0x131,s_VERDANA7_fnt_00563ec8,&DAT_00565078);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4ec,0);
    FUN_0052f9d0(this,0x4ec,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4ed,0xa0,0x122,s_VERDANA7_fnt_00563ec8,&DAT_0056508c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4ed,0);
    FUN_0052f9d0(this,0x4ed,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4ee,0x6e,0x16a,s_VERDANA7_fnt_00563ec8,s__gemietet__00567328);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4ee,0);
    FUN_0052f9d0(this,0x4ee,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4ef,0x6e,0x179,s_VERDANA7_fnt_00563ec8,s__gebaut__0056731c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4ef,0);
    FUN_0052f9d0(this,0x4ef,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4f0,0x6e,0x18d,s_VERDANA7_fnt_00563ec8,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4f0,0);
    FUN_0052f9d0(this,0x4f0,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4f1,0xa0,0x18d,s_VERDANA7_fnt_00563ec8,s__20_000_00567314);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4f1,0);
    FUN_0052f9d0(this,0x4f1,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4f2,0xa0,0x179,s_VERDANA7_fnt_00563ec8,&DAT_00565078);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4f2,0);
    FUN_0052f9d0(this,0x4f2,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4f3,0xa0,0x16a,s_VERDANA7_fnt_00563ec8,&DAT_0056508c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4f3,0);
    FUN_0052f9d0(this,0x4f3,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4f4,0x6e,0x1b0,s_VERDANA7_fnt_00563ec8,s__gemietet__00567328);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4f4,0);
    FUN_0052f9d0(this,0x4f4,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4f5,0x6e,0x1bf,s_VERDANA7_fnt_00563ec8,s__gebaut__0056731c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4f5,0);
    FUN_0052f9d0(this,0x4f5,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4f6,0x6e,0x1d3,s_VERDANA7_fnt_00563ec8,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4f6,0);
    FUN_0052f9d0(this,0x4f6,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4f7,0xa0,0x1d3,s_VERDANA7_fnt_00563ec8,s__20_000_00567314);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4f7,0);
    FUN_0052f9d0(this,0x4f7,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4f8,0xa0,0x1bf,s_VERDANA7_fnt_00563ec8,&DAT_00565078);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4f8,0);
    FUN_0052f9d0(this,0x4f8,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4f9,0xa0,0x1b0,s_VERDANA7_fnt_00563ec8,&DAT_0056508c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4f9,0);
    FUN_0052f9d0(this,0x4f9,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4fa,0xe0,0x4c,s_VERDANA7_fnt_00563ec8,s__gemietet__00567328);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4fa,0);
    FUN_0052f9d0(this,0x4fa,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4fb,0xe0,0x5b,s_VERDANA7_fnt_00563ec8,s__gebaut__0056731c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4fb,0);
    FUN_0052f9d0(this,0x4fb,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4fc,0xe0,0x6f,s_VERDANA7_fnt_00563ec8,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4fc,0);
    FUN_0052f9d0(this,0x4fc,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4fd,0x112,0x6f,s_VERDANA7_fnt_00563ec8,s__20_000_00567314);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4fd,0);
    FUN_0052f9d0(this,0x4fd,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4fe,0x112,0x5b,s_VERDANA7_fnt_00563ec8,&DAT_00565078);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4fe,0);
    FUN_0052f9d0(this,0x4fe,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x4ff,0x112,0x4c,s_VERDANA7_fnt_00563ec8,&DAT_0056508c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4ff,0);
    FUN_0052f9d0(this,0x4ff,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x500,0xe0,0x94,s_VERDANA7_fnt_00563ec8,s__gemietet__00567328);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x500,0);
    FUN_0052f9d0(this,0x500,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x501,0xe0,0xa3,s_VERDANA7_fnt_00563ec8,s__gebaut__0056731c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x501,0);
    FUN_0052f9d0(this,0x501,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x502,0xe0,0xb7,s_VERDANA7_fnt_00563ec8,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x502,0);
    FUN_0052f9d0(this,0x502,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x503,0x112,0xb7,s_VERDANA7_fnt_00563ec8,s__20_000_00567314);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x503,0);
    FUN_0052f9d0(this,0x503,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x504,0x112,0xa3,s_VERDANA7_fnt_00563ec8,&DAT_00565078);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x504,0);
    FUN_0052f9d0(this,0x504,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x505,0x112,0x94,s_VERDANA7_fnt_00563ec8,&DAT_0056508c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x505,0);
    FUN_0052f9d0(this,0x505,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x506,0xe0,0xda,s_VERDANA7_fnt_00563ec8,s__gemietet__00567328);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x506,0);
    FUN_0052f9d0(this,0x506,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x507,0xe0,0xe9,s_VERDANA7_fnt_00563ec8,s__gebaut__0056731c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x507,0);
    FUN_0052f9d0(this,0x507,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x508,0xe0,0xfd,s_VERDANA7_fnt_00563ec8,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x508,0);
    FUN_0052f9d0(this,0x508,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x509,0x112,0xfd,s_VERDANA7_fnt_00563ec8,s__20_000_00567314);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x509,0);
    FUN_0052f9d0(this,0x509,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x50a,0x112,0xe9,s_VERDANA7_fnt_00563ec8,&DAT_00565078);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x50a,0);
    FUN_0052f9d0(this,0x50a,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x50b,0x112,0xda,s_VERDANA7_fnt_00563ec8,&DAT_0056508c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x50b,0);
    FUN_0052f9d0(this,0x50b,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x50c,0xe0,0x122,s_VERDANA7_fnt_00563ec8,s__gemietet__00567328);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x50c,0);
    FUN_0052f9d0(this,0x50c,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x50d,0xe0,0x131,s_VERDANA7_fnt_00563ec8,s__gebaut__0056731c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x50d,0);
    FUN_0052f9d0(this,0x50d,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x50e,0xe0,0x145,s_VERDANA7_fnt_00563ec8,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x50e,0);
    FUN_0052f9d0(this,0x50e,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x50f,0x112,0x145,s_VERDANA7_fnt_00563ec8,s__20_000_00567314);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x50f,0);
    FUN_0052f9d0(this,0x50f,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x510,0x112,0x131,s_VERDANA7_fnt_00563ec8,&DAT_00565078);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x510,0);
    FUN_0052f9d0(this,0x510,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x511,0x112,0x122,s_VERDANA7_fnt_00563ec8,&DAT_0056508c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x511,0);
    FUN_0052f9d0(this,0x511,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x512,0xe0,0x16a,s_VERDANA7_fnt_00563ec8,s__gemietet__00567328);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x512,0);
    FUN_0052f9d0(this,0x512,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x513,0xe0,0x179,s_VERDANA7_fnt_00563ec8,s__gebaut__0056731c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x513,0);
    FUN_0052f9d0(this,0x513,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x514,0xe0,0x18d,s_VERDANA7_fnt_00563ec8,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x514,0);
    FUN_0052f9d0(this,0x514,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x515,0x112,0x18d,s_VERDANA7_fnt_00563ec8,s__20_000_00567314);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x515,0);
    FUN_0052f9d0(this,0x515,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x516,0x112,0x179,s_VERDANA7_fnt_00563ec8,&DAT_00565078);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x516,0);
    FUN_0052f9d0(this,0x516,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x517,0x112,0x16a,s_VERDANA7_fnt_00563ec8,&DAT_0056508c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x517,0);
    FUN_0052f9d0(this,0x517,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x518,0xe0,0x1b0,s_VERDANA7_fnt_00563ec8,s__gemietet__00567328);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x518,0);
    FUN_0052f9d0(this,0x518,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x519,0xe0,0x1bf,s_VERDANA7_fnt_00563ec8,s__gebaut__0056731c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x519,0);
    FUN_0052f9d0(this,0x519,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x51a,0xe0,0x1d3,s_VERDANA7_fnt_00563ec8,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x51a,0);
    FUN_0052f9d0(this,0x51a,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x51b,0x112,0x1d3,s_VERDANA7_fnt_00563ec8,s__20_000_00567314);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x51b,0);
    FUN_0052f9d0(this,0x51b,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x51c,0x112,0x1bf,s_VERDANA7_fnt_00563ec8,&DAT_00565078);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x51c,0);
    FUN_0052f9d0(this,0x51c,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x51d,0x112,0x1b0,s_VERDANA7_fnt_00563ec8,&DAT_0056508c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x51d,0);
    FUN_0052f9d0(this,0x51d,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x51e,0x152,0x4c,s_VERDANA7_fnt_00563ec8,s__gemietet__00567328);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x51e,0);
    FUN_0052f9d0(this,0x51e,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x51f,0x152,0x5b,s_VERDANA7_fnt_00563ec8,s__gebaut__0056731c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x51f,0);
    FUN_0052f9d0(this,0x51f,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x520,0x152,0x6f,s_VERDANA7_fnt_00563ec8,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x520,0);
    FUN_0052f9d0(this,0x520,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x521,0x184,0x6f,s_VERDANA7_fnt_00563ec8,s__20_000_00567314);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x521,0);
    FUN_0052f9d0(this,0x521,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x522,0x184,0x5b,s_VERDANA7_fnt_00563ec8,&DAT_00565078);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x522,0);
    FUN_0052f9d0(this,0x522,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x523,0x184,0x4c,s_VERDANA7_fnt_00563ec8,&DAT_0056508c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x523,0);
    FUN_0052f9d0(this,0x523,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x524,0x152,0x94,s_VERDANA7_fnt_00563ec8,s__gemietet__00567328);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x524,0);
    FUN_0052f9d0(this,0x524,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x525,0x152,0xa3,s_VERDANA7_fnt_00563ec8,s__gebaut__0056731c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x525,0);
    FUN_0052f9d0(this,0x525,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x526,0x152,0xb7,s_VERDANA7_fnt_00563ec8,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x526,0);
    FUN_0052f9d0(this,0x526,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x527,0x184,0xb7,s_VERDANA7_fnt_00563ec8,s__20_000_00567314);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x527,0);
    FUN_0052f9d0(this,0x527,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x528,0x184,0xa3,s_VERDANA7_fnt_00563ec8,&DAT_00565078);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x528,0);
    FUN_0052f9d0(this,0x528,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x529,0x184,0x94,s_VERDANA7_fnt_00563ec8,&DAT_0056508c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x529,0);
    FUN_0052f9d0(this,0x529,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x52a,0x152,0xda,s_VERDANA7_fnt_00563ec8,s__gemietet__00567328);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x52a,0);
    FUN_0052f9d0(this,0x52a,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x52b,0x152,0xe9,s_VERDANA7_fnt_00563ec8,s__gebaut__0056731c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x52b,0);
    FUN_0052f9d0(this,0x52b,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x52c,0x152,0xfd,s_VERDANA7_fnt_00563ec8,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x52c,0);
    FUN_0052f9d0(this,0x52c,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x52d,0x184,0xfd,s_VERDANA7_fnt_00563ec8,s__20_000_00567314);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x52d,0);
    FUN_0052f9d0(this,0x52d,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x52e,0x184,0xe9,s_VERDANA7_fnt_00563ec8,&DAT_00565078);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x52e,0);
    FUN_0052f9d0(this,0x52e,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x52f,0x184,0xda,s_VERDANA7_fnt_00563ec8,&DAT_0056508c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x52f,0);
    FUN_0052f9d0(this,0x52f,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x530,0x152,0x122,s_VERDANA7_fnt_00563ec8,s__gemietet__00567328);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x530,0);
    FUN_0052f9d0(this,0x530,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x531,0x152,0x131,s_VERDANA7_fnt_00563ec8,s__gebaut__0056731c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x531,0);
    FUN_0052f9d0(this,0x531,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x532,0x152,0x145,s_VERDANA7_fnt_00563ec8,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x532,0);
    FUN_0052f9d0(this,0x532,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x533,0x184,0x145,s_VERDANA7_fnt_00563ec8,s__20_000_00567314);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x533,0);
    FUN_0052f9d0(this,0x533,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x534,0x184,0x131,s_VERDANA7_fnt_00563ec8,&DAT_00565078);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x534,0);
    FUN_0052f9d0(this,0x534,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x535,0x184,0x122,s_VERDANA7_fnt_00563ec8,&DAT_0056508c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x535,0);
    FUN_0052f9d0(this,0x535,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x536,0x152,0x16a,s_VERDANA7_fnt_00563ec8,s__gemietet__00567328);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x536,0);
    FUN_0052f9d0(this,0x536,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x537,0x152,0x179,s_VERDANA7_fnt_00563ec8,s__gebaut__0056731c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x537,0);
    FUN_0052f9d0(this,0x537,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x538,0x152,0x18d,s_VERDANA7_fnt_00563ec8,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x538,0);
    FUN_0052f9d0(this,0x538,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x539,0x184,0x18d,s_VERDANA7_fnt_00563ec8,s__20_000_00567314);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x539,0);
    FUN_0052f9d0(this,0x539,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x53a,0x184,0x179,s_VERDANA7_fnt_00563ec8,&DAT_00565078);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x53a,0);
    FUN_0052f9d0(this,0x53a,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x53b,0x184,0x16a,s_VERDANA7_fnt_00563ec8,&DAT_0056508c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x53b,0);
    FUN_0052f9d0(this,0x53b,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x53c,0x152,0x1b0,s_VERDANA7_fnt_00563ec8,s__gemietet__00567328);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x53c,0);
    FUN_0052f9d0(this,0x53c,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x53d,0x152,0x1bf,s_VERDANA7_fnt_00563ec8,s__gebaut__0056731c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x53d,0);
    FUN_0052f9d0(this,0x53d,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x53e,0x152,0x1d3,s_VERDANA7_fnt_00563ec8,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x53e,0);
    FUN_0052f9d0(this,0x53e,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x53f,0x184,0x1d3,s_VERDANA7_fnt_00563ec8,s__20_000_00567314);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x53f,0);
    FUN_0052f9d0(this,0x53f,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x540,0x184,0x1bf,s_VERDANA7_fnt_00563ec8,&DAT_00565078);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x540,0);
    FUN_0052f9d0(this,0x540,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x541,0x184,0x1b0,s_VERDANA7_fnt_00563ec8,&DAT_0056508c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x541,0);
    FUN_0052f9d0(this,0x541,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x542,0x1c7,0x4c,s_VERDANA7_fnt_00563ec8,s__gemietet__00567328);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x542,0);
    FUN_0052f9d0(this,0x542,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x543,0x1c7,0x5b,s_VERDANA7_fnt_00563ec8,s__gebaut__0056731c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x543,0);
    FUN_0052f9d0(this,0x543,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x544,0x1c7,0x6f,s_VERDANA7_fnt_00563ec8,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x544,0);
    FUN_0052f9d0(this,0x544,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x545,0x1f9,0x6f,s_VERDANA7_fnt_00563ec8,s__20_000_00567314);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x545,0);
    FUN_0052f9d0(this,0x545,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x546,0x1f9,0x5b,s_VERDANA7_fnt_00563ec8,&DAT_00565078);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x546,0);
    FUN_0052f9d0(this,0x546,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x547,0x1f9,0x4c,s_VERDANA7_fnt_00563ec8,&DAT_0056508c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x547,0);
    FUN_0052f9d0(this,0x547,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x548,0x1c7,0x94,s_VERDANA7_fnt_00563ec8,s__gemietet__00567328);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x548,0);
    FUN_0052f9d0(this,0x548,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x549,0x1c7,0xa3,s_VERDANA7_fnt_00563ec8,s__gebaut__0056731c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x549,0);
    FUN_0052f9d0(this,0x549,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x54a,0x1c7,0xb7,s_VERDANA7_fnt_00563ec8,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x54a,0);
    FUN_0052f9d0(this,0x54a,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x54b,0x1f9,0xb7,s_VERDANA7_fnt_00563ec8,s__20_000_00567314);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x54b,0);
    FUN_0052f9d0(this,0x54b,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x54c,0x1f9,0xa3,s_VERDANA7_fnt_00563ec8,&DAT_00565078);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x54c,0);
    FUN_0052f9d0(this,0x54c,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x54d,0x1f9,0x94,s_VERDANA7_fnt_00563ec8,&DAT_0056508c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x54d,0);
    FUN_0052f9d0(this,0x54d,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x54e,0x1c7,0xda,s_VERDANA7_fnt_00563ec8,s__gemietet__00567328);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x54e,0);
    FUN_0052f9d0(this,0x54e,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x54f,0x1c7,0xe9,s_VERDANA7_fnt_00563ec8,s__gebaut__0056731c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x54f,0);
    FUN_0052f9d0(this,0x54f,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x550,0x1c7,0xfd,s_VERDANA7_fnt_00563ec8,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x550,0);
    FUN_0052f9d0(this,0x550,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x551,0x1f9,0xfd,s_VERDANA7_fnt_00563ec8,s__20_000_00567314);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x551,0);
    FUN_0052f9d0(this,0x551,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x552,0x1f9,0xe9,s_VERDANA7_fnt_00563ec8,&DAT_00565078);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x552,0);
    FUN_0052f9d0(this,0x552,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x553,0x1f9,0xda,s_VERDANA7_fnt_00563ec8,&DAT_0056508c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x553,0);
    FUN_0052f9d0(this,0x553,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x554,0x1c7,0x122,s_VERDANA7_fnt_00563ec8,s__gemietet__00567328);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x554,0);
    FUN_0052f9d0(this,0x554,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x555,0x1c7,0x131,s_VERDANA7_fnt_00563ec8,s__gebaut__0056731c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x555,0);
    FUN_0052f9d0(this,0x555,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x556,0x1c7,0x145,s_VERDANA7_fnt_00563ec8,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x556,0);
    FUN_0052f9d0(this,0x556,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x557,0x1f9,0x145,s_VERDANA7_fnt_00563ec8,s__20_000_00567314);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x557,0);
    FUN_0052f9d0(this,0x557,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x558,0x1f9,0x131,s_VERDANA7_fnt_00563ec8,&DAT_00565078);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x558,0);
    FUN_0052f9d0(this,0x558,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x559,0x1f9,0x122,s_VERDANA7_fnt_00563ec8,&DAT_0056508c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x559,0);
    FUN_0052f9d0(this,0x559,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x55a,0x1c7,0x16a,s_VERDANA7_fnt_00563ec8,s__gemietet__00567328);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x55a,0);
    FUN_0052f9d0(this,0x55a,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x55b,0x1c7,0x179,s_VERDANA7_fnt_00563ec8,s__gebaut__0056731c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x55b,0);
    FUN_0052f9d0(this,0x55b,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x55c,0x1c7,0x18d,s_VERDANA7_fnt_00563ec8,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x55c,0);
    FUN_0052f9d0(this,0x55c,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x55d,0x1f9,0x18d,s_VERDANA7_fnt_00563ec8,s__20_000_00567314);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x55d,0);
    FUN_0052f9d0(this,0x55d,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x55e,0x1f9,0x179,s_VERDANA7_fnt_00563ec8,&DAT_00565078);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x55e,0);
    FUN_0052f9d0(this,0x55e,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x55f,0x1f9,0x16a,s_VERDANA7_fnt_00563ec8,&DAT_0056508c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x55f,0);
    FUN_0052f9d0(this,0x55f,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x560,0x1c7,0x1b0,s_VERDANA7_fnt_00563ec8,s__gemietet__00567328);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x560,0);
    FUN_0052f9d0(this,0x560,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x561,0x1c7,0x1bf,s_VERDANA7_fnt_00563ec8,s__gebaut__0056731c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x561,0);
    FUN_0052f9d0(this,0x561,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x562,0x1c7,0x1d3,s_VERDANA7_fnt_00563ec8,DAT_00582edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x562,0);
    FUN_0052f9d0(this,0x562,0,0x46,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x563,0x1f9,0x1d3,s_VERDANA7_fnt_00563ec8,s__20_000_00567314);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x563,0);
    FUN_0052f9d0(this,0x563,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x564,0x1f9,0x1bf,s_VERDANA7_fnt_00563ec8,&DAT_00565078);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x564,0);
    FUN_0052f9d0(this,0x564,1,0x32,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x565,0x1f9,0x1b0,s_VERDANA7_fnt_00563ec8,&DAT_0056508c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x565,0);
    FUN_0052f9d0(this,0x565,1,0x32,0xffff,0);
  }
  FUN_00531850(this,0x589,0x2ff,0x11d,s_LOGOS__07_spr_00564f20);
  FUN_00531850(this,0x58a,0x2ff,0x141,s_LOGOS__01_spr_00564f10);
  FUN_00531850(this,0x58b,0x2ff,0x164,s_LOGOS__02_spr_00564f00);
  FUN_00531850(this,0x58c,0x2ff,0x185,s_LOGOS__05_spr_00564ef0);
  FUN_00531850(this,0x58d,0x2ff,0x1ab,s_LOGOS__06_spr_00564ee0);
  FUN_00531850(this,0x58e,0x300,0x1ce,s_LOGOS__08_spr_00564ed0);
  FUN_00531850(this,0x591,0x1e,0x48,s_FOTORAHMEN00_spr_00564310);
  FUN_00531850(this,0x594,0x1e,0x8f,s_FOTORAHMEN00_spr_00564310);
  FUN_00531850(this,0x596,0x1e,0xd6,s_FOTORAHMEN00_spr_00564310);
  FUN_00531850(this,0x598,0x1e,0x11d,s_FOTORAHMEN00_spr_00564310);
  FUN_00531850(this,0x59a,0x1e,0x164,s_FOTORAHMEN00_spr_00564310);
  FUN_00531850(this,0x59c,0x1e,0x1aa,s_FOTORAHMEN00_spr_00564310);
  FUN_00531850(this,0x59d,0x23,0x4d,s_FOTODUMMY00_spr_00564300);
  FUN_00531850(this,0x59e,0x23,0x94,s_FOTODUMMY00_spr_00564300);
  FUN_00531850(this,0x59f,0x23,0xdb,s_FOTODUMMY00_spr_00564300);
  FUN_00531850(this,0x5a0,0x23,0x122,s_FOTODUMMY00_spr_00564300);
  FUN_00531850(this,0x5a1,0x23,0x169,s_FOTODUMMY00_spr_00564300);
  FUN_00531850(this,0x5a2,0x23,0x1af,s_FOTODUMMY00_spr_00564300);
  iVar1 = FUN_0052f690(this,0x5a3,0x253,0x1fd,s_TIMESFONT_fnt_00563ea8,DAT_00582a88,0,
                       s_TEXTPBTRANSPGELB_00_spr_00567208);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x5a3,0,0,0);
    FUN_0052f7a0(this,0x5a3,2,0xcc,0,0,0);
  }
  iVar1 = FUN_0052f690(this,0x5a4,0x253,0x227,s_TIMES14_fnt_00564788,DAT_00581b2c,0,
                       s_TEXTPBTRANSPGRUEN_00_spr_005671ec);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x5a4,0,0,0);
    FUN_0052f7a0(this,0x5a4,2,0xcc,0,0,0);
  }
  iVar1 = FUN_0052f690(this,0x5a5,0x253,0x4e,s_TIMESFONT_fnt_00563ea8,DAT_00581750,0,
                       s_TEXTPBTRANSPGELB_00_spr_00567208);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x5a5,0,0,0);
    FUN_0052f7a0(this,0x5a5,2,0xcc,0,0,0);
  }
  iVar1 = FUN_0052f690(this,0x5a6,0x253,0x24,s_TIMESFONT_fnt_00563ea8,DAT_00580b38,0,
                       s_TEXTPBTRANSPGELB_00_spr_00567208);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x5a6,0,0,0);
    FUN_0052f7a0(this,0x5a6,2,0xcc,0,0,0);
  }
  FUN_00531850(this,0x5a8,0x23,0x4d,s_PLAYLOG_3_02_01_spr_00567300);
  FUN_00531850(this,0x5a9,0x23,0x94,s_PLAYLOG_3_02_01_spr_00567300);
  FUN_00531850(this,0x5aa,0x23,0xdb,s_PLAYLOG_3_02_01_spr_00567300);
  FUN_00531850(this,0x5ab,0x23,0x122,s_PLAYLOG_3_02_01_spr_00567300);
  FUN_00531850(this,0x5ac,0x23,0x169,s_PLAYLOG_3_02_01_spr_00567300);
  FUN_00531850(this,0x5ad,0x23,0x1af,s_PLAYLOG_3_02_01_spr_00567300);
  return this;
}

