// rea decompile_all
// name: FreePlaySubMenu_BuildLoadSavegame
// address: 0x4756e0
// body: available
// range: 0x4756e0-0x475f83 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FreePlaySubMenu_BuildLoadSavegame(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
                    /* Builds the free-play load-savegame list page. */
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0,0,s_PE_SUB_FREIES_SPIEL_spr_005674f0,&LAB_004ce610);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  FUN_0052f5b0(this,0x834,0x265,0x39,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x835,0x265,0x4e,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x836,0x265,99,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x837,0x265,0x78,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x838,0x265,0x8d,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x839,0x265,0xa2,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x83a,0x265,0xb7,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x83b,0x265,0xcc,s_TABPB01__00_spr_00564670,1,0);
  iVar1 = FUN_0052f850(this,0x440,0x25d,5,s_TIMESFONT_fnt_00563ea8,DAT_00582470);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x440,0);
    FUN_0052f9d0(this,0x440,2,0xbe,0,0);
  }
  iVar1 = FUN_0052f850(this,0x441,0x264,0x28,s_VERDANA8_fnt_00563e98,DAT_00581db8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x441,0);
    FUN_0052f9d0(this,0x441,0,0xb4,0,0);
  }
  FUN_0052f5b0(this,0x83c,0x265,0xe1,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x83d,0x265,0xf6,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x83e,0x265,0x10b,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x83f,0x265,0x120,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x840,0x265,0x135,s_TABPB01__00_spr_00564670,1,0);
  iVar1 = FUN_0052f850(this,2000,0x26a,0x3d,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,2000,0);
    FUN_0052f9d0(this,2000,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x7d1,0x26a,0x52,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x7d1,0);
    FUN_0052f9d0(this,0x7d1,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x7d2,0x26a,0x67,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x7d2,0);
    FUN_0052f9d0(this,0x7d2,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x7d3,0x26a,0x7c,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x7d3,0);
    FUN_0052f9d0(this,0x7d3,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x7d4,0x26a,0x91,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x7d4,0);
    FUN_0052f9d0(this,0x7d4,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x7d5,0x26a,0xa6,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x7d5,0);
    FUN_0052f9d0(this,0x7d5,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x7d6,0x26a,0xbb,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x7d6,0);
    FUN_0052f9d0(this,0x7d6,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x7d7,0x26a,0xd0,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x7d7,0);
    FUN_0052f9d0(this,0x7d7,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x7d8,0x26a,0xe5,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x7d8,0);
    FUN_0052f9d0(this,0x7d8,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x7d9,0x26a,0xfa,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x7d9,0);
    FUN_0052f9d0(this,0x7d9,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x7da,0x26a,0x10f,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x7da,0);
    FUN_0052f9d0(this,0x7da,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x7db,0x26a,0x124,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x7db,0);
    FUN_0052f9d0(this,0x7db,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x7dc,0x26a,0x139,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x7dc,0);
    FUN_0052f9d0(this,0x7dc,0,0x96,0,0);
  }
  iVar1 = UI_CreateSlider(this,0x462,0x30f,0x3f,0x18b,s_SL01_00_spr_0056448c,0,1);
  if (iVar1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    FUN_0052fcc0(this,0x462,&local_10);
  }
  FUN_0052f5b0(this,0x841,0x265,0x149,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x842,0x265,0x15e,s_TABPB01__00_spr_00564670,1,0);
  iVar1 = FUN_0052f850(this,0x7dd,0x26a,0x14d,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x7dd,0);
    FUN_0052f9d0(this,0x7dd,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x7de,0x26a,0x162,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x7de,0);
    FUN_0052f9d0(this,0x7de,0,0x96,0,0);
  }
  iVar1 = UI_AddTextButton(this,0x463,0x2bd,0x1d5,s_VERDANA8_fnt_00563e98,DAT_00582ae4,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x463,0,0,0);
    FUN_0052f7a0(this,0x463,2,0x54,0,0,0xfffe);
  }
  FUN_0052f5b0(this,0x843,0x265,0x173,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x844,0x265,0x188,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x845,0x265,0x19d,s_TABPB01__00_spr_00564670,1,0);
  iVar1 = FUN_0052f850(this,0x7df,0x26a,0x177,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x7df,0);
    FUN_0052f9d0(this,0x7df,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x7e0,0x26a,0x18c,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x7e0,0);
    FUN_0052f9d0(this,0x7e0,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x7e1,0x26a,0x1a1,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x7e1,0);
    FUN_0052f9d0(this,0x7e1,0,0x96,0,0);
  }
  FUN_0052f5b0(this,0x846,0x265,0x1b1,s_TABPB01__00_spr_00564670,1,0);
  iVar1 = FUN_0052f850(this,0x7e2,0x26a,0x1b5,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x7e2,0);
    FUN_0052f9d0(this,0x7e2,0,0x96,0,0);
  }
  return this;
}

