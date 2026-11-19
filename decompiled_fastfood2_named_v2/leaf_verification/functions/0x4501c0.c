// rea decompile_all
// name: FUN_004501c0
// address: 0x4501c0
// body: available
// range: 0x4501c0-0x45089a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_004501c0(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004bbdb0);
  *param_1 = iVar1;
  this = (void *)UI_FindWindowByID(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  iVar1 = FUN_0052f850(this,0x472,0x2a,5,s_TIMESFONT_fnt_00563ea8,DAT_00582808);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x472,0);
    FUN_0052f9d0(this,0x472,2,0xbe,0,0);
  }
  iVar1 = FUN_0052f850(this,0x476,0x2f,0x82,s_VERDANA10_fnt_00563e64,DAT_005825f4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x476,0);
    FUN_0052f9d0(this,0x476,0,0x46,0,0);
  }
  iVar1 = FUN_0052f850(this,0x48f,0x4e,0x33,s_VEDANA11_fnt_00564090,s__Kurier_005665e0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x48f,0);
    FUN_0052f9d0(this,0x48f,2,0x78,0,0);
  }
  FUN_0052f5b0(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  iVar1 = FUN_0052fc00(this,0x1f41,0x3e,0x69,0xa0,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xf700;
    local_4 = 0;
    FUN_0052fcc0(this,0x1f41,&local_10);
  }
  iVar1 = FUN_0052f850(this,0x1f42,0x34,0x56,s_VERDANA8_fnt_00563e98,DAT_00582b0c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f42,0);
    FUN_0052f9d0(this,0x1f42,2,0xaa,0,0);
  }
  FUN_00531850(this,0x1f43,0x27,0x79,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x1f44,0x2f,0x95,s_VERDANA10_fnt_00563e64,
                       s__Eine_Lieferung_Ratten_005665c8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f44,0);
    FUN_0052f9d0(this,0x1f44,0,0xb4,0x23,0);
  }
  iVar1 = FUN_0052f850(this,0x1f46,0x74,0x168,s_VERDANA8_fnt_00563e98,&DAT_00565088);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f46,0);
    FUN_0052f9d0(this,0x1f46,2,0x2d,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f47,0x36,0x168,s_VERDANA8_fnt_00563e98,&DAT_00565094);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f47,0);
    FUN_0052f9d0(this,0x1f47,2,0x2d,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f48,0xb5,0x167,s_VERDANA8_fnt_00563e98,&DAT_00565088);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f48,0);
    FUN_0052f9d0(this,0x1f48,2,0x2d,0,0);
  }
  FUN_00531850(this,0x1f4b,0x27,0x12a,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x1f5a,0x2d,0xfd,s_VERDANA8_fnt_00563e98,DAT_00582758);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f5a,0);
    FUN_0052f9d0(this,0x1f5a,0,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f5b,0x2d,0x116,s_VERDANA8_fnt_00563e98,s__Pizza_Tingeltangel_0056510c
                      );
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f5b,0);
    FUN_0052f9d0(this,0x1f5b,0,0x87,0,0);
  }
  FUN_00531850(this,0x1f5c,0xb5,0x104,s_LOGORAHMEN_00_spr_005650f8);
  FUN_00531c60(this,0x1f5d,0xb7,0x106,0x2c,0x1d,0x10);
  FUN_00531850(this,0x1f5f,0x27,0xf2,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x1f60,0x33,0x134,s_VERDANA8_fnt_00563e98,DAT_00580fec);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f60,0);
    FUN_0052f9d0(this,0x1f60,0,0x82,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f61,0x83,0x134,s_VERDANA8_fnt_00563e98,s__Stufe_1_0056452c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f61,0);
    FUN_0052f9d0(this,0x1f61,1,100,0,0);
  }
  FUN_00531850(this,0x1f62,0x80,0x14f,&DAT_0056450c);
  FUN_00531850(this,0x1f63,0x42,0x14f,s_SCHLAGKRAFT_spr_0056451c);
  FUN_00531850(this,0x1f64,0xc1,0x14f,s_PANZERUNG_spr_005644f8);
  FUN_00531850(this,0x1f65,0x29,0x2c,s_MASCHINENGEWEHRICON_spr_005665b0);
  FUN_00531850(this,0x1f66,0x30,0x2b,s_SCHLAEGERICON_spr_0056659c);
  FUN_00531850(this,0x1f67,0x2b,0x2c,s_LIEFERANT_spr_0056658c);
  iVar1 = FUN_0052f690(this,0x1f68,0x8e,0xc5,s_VERDANA8_fnt_00563e98,DAT_00582ae0,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x1f68,0,0,0);
    FUN_0052f7a0(this,0x1f68,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f850(this,0x1f69,0x90,0xda,s_VERDANA7_fnt_00563ec8,DAT_00581fc0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f69,0);
    FUN_0052f9d0(this,0x1f69,0,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f6a,0xbb,0xda,s_VERDANA7_fnt_00563ec8,s__1000__00566320);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f6a,0);
    FUN_0052f9d0(this,0x1f6a,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f6b,0xbb,0xe4,s_VERDANA7_fnt_00563ec8,&DAT_00566318);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f6b,0);
    FUN_0052f9d0(this,0x1f6b,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f6c,0x90,0xe4,s_VERDANA7_fnt_00563ec8,DAT_00582af4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f6c,0);
    FUN_0052f9d0(this,0x1f6c,0,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f6d,0x31,0xc9,s_VERDANA8_fnt_00563e98,DAT_00581bf8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f6d,0);
    FUN_0052f9d0(this,0x1f6d,0,0x5f,0,0);
  }
  FUN_00531850(this,0x1f6e,0xb7,0x106,s_PLAYLOG_8_01_02_spr_00564744);
  FUN_00531850(this,0x1f6f,0x29,0x2c,s_PUNKICON_spr_0056657c);
  return this;
}

