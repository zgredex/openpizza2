// rea decompile_all
// name: HighScore_BuildCityListWindow
// address: 0x476100
// body: available
// range: 0x476100-0x476917 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl HighScore_BuildCityListWindow(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
                    /* Builds the high-score city list window. */
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0,0,s_PE_SUB_FREIES_SPIEL_spr_005674f0,&LAB_004ce810);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  FUN_0052f5b0(this,2000,0x262,0x52,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x7d1,0x262,0x67,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x7d2,0x262,0x7c,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x7d3,0x262,0x91,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x7d4,0x262,0xa6,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x7d5,0x262,0xbb,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x7d6,0x262,0xd0,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x7d7,0x262,0xe5,s_TABPB01__00_spr_00564670,1,0);
  iVar1 = FUN_0052f850(this,0x441,0x261,0x30,s_TIMES14_fnt_00564788,&DAT_00567544);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x441,0);
    FUN_0052f9d0(this,0x441,0,0xb4,0,0);
  }
  FUN_0052f5b0(this,0x7d8,0x262,0xfa,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x7d9,0x262,0x10f,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x7da,0x262,0x124,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x7db,0x262,0x139,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x7dc,0x262,0x14e,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x7dd,0x262,0x163,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x7de,0x262,0x178,s_TABPB01__00_spr_00564670,1,0);
  iVar1 = FUN_0052f850(this,3000,0x267,0x57,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,3000,0);
    FUN_0052f9d0(this,3000,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0xbb9,0x267,0x6b,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0xbb9,0);
    FUN_0052f9d0(this,0xbb9,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0xbba,0x267,0x80,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0xbba,0);
    FUN_0052f9d0(this,0xbba,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0xbbb,0x267,0x95,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0xbbb,0);
    FUN_0052f9d0(this,0xbbb,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0xbbc,0x267,0xaa,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0xbbc,0);
    FUN_0052f9d0(this,0xbbc,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0xbbd,0x267,0xbf,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0xbbd,0);
    FUN_0052f9d0(this,0xbbd,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0xbbe,0x267,0xd4,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0xbbe,0);
    FUN_0052f9d0(this,0xbbe,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0xbbf,0x267,0xe9,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0xbbf,0);
    FUN_0052f9d0(this,0xbbf,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0xbc0,0x267,0xfe,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0xbc0,0);
    FUN_0052f9d0(this,0xbc0,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0xbc1,0x267,0x113,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0xbc1,0);
    FUN_0052f9d0(this,0xbc1,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0xbc2,0x267,0x128,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0xbc2,0);
    FUN_0052f9d0(this,0xbc2,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0xbc3,0x267,0x13d,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0xbc3,0);
    FUN_0052f9d0(this,0xbc3,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0xbc4,0x267,0x152,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0xbc4,0);
    FUN_0052f9d0(this,0xbc4,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0xbc5,0x267,0x167,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0xbc5,0);
    FUN_0052f9d0(this,0xbc5,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0xbc6,0x267,0x17c,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0xbc6,0);
    FUN_0052f9d0(this,0xbc6,0,0x96,0,0);
  }
  iVar1 = UI_CreateSlider(this,0x462,0x30c,0x58,0x18a,s_SL01_00_spr_0056448c,0,1);
  if (iVar1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    FUN_0052fcc0(this,0x462,&local_10);
  }
  FUN_0052f5b0(this,0x7df,0x262,0x18d,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x7e0,0x262,0x1a2,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x7e1,0x262,0x1b7,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x7e2,0x262,0x1cc,s_TABPB01__00_spr_00564670,1,0);
  iVar1 = FUN_0052f850(this,0xbc7,0x267,0x191,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0xbc7,0);
    FUN_0052f9d0(this,0xbc7,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0xbc8,0x267,0x1a6,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0xbc8,0);
    FUN_0052f9d0(this,0xbc8,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0xbc9,0x267,0x1bb,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0xbc9,0);
    FUN_0052f9d0(this,0xbc9,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0xbca,0x267,0x1d0,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0xbca,0);
    FUN_0052f9d0(this,0xbca,0,0x96,0,0);
  }
  return this;
}

