// rea decompile_all
// name: FUN_00454ee0
// address: 0x454ee0
// body: available
// range: 0x454ee0-0x4556ea inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_00454ee0(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004be530);
  *param_1 = iVar1;
  this = (void *)UI_FindWindowByID(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  FUN_00531850(this,0x409,0x27,0xce,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x45c,0x3d,0x25,s_VERDANA10_fnt_00563e64,DAT_00582e20);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x45c,0);
    FUN_0052f9d0(this,0x45c,2,0x98,0,0);
  }
  iVar1 = FUN_0052f850(this,0x45d,0x41,0x36,s_VERDANA8_fnt_00563e98,DAT_00582ca0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x45d,0);
    FUN_0052f9d0(this,0x45d,2,0x98,0,0);
  }
  iVar1 = FUN_0052f850(this,0x45e,0x41,0x52,s_VERDANA8_fnt_00563e98,DAT_00582e28);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x45e,0);
    FUN_0052f9d0(this,0x45e,2,0x98,0,0);
  }
  iVar1 = FUN_0052f850(this,0x465,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00582088);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x465,0);
    FUN_0052f9d0(this,0x465,2,0xbe,0,0);
  }
  iVar1 = FUN_0052fc00(this,0x441,0x34,0xc3,0x5a,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    FUN_0052fcc0(this,0x441,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x442,0x8f,0xc3,0x5a,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    FUN_0052fcc0(this,0x442,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x443,0x4a,0x49,0x8c,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    FUN_0052fcc0(this,0x443,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x444,0x4a,0x65,0x8c,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    FUN_0052fcc0(this,0x444,&local_10);
  }
  iVar1 = FUN_0052f850(this,0x500,0x2d,0xde,s_VERDANA8_fnt_00563e98,DAT_0058281c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x500,0);
    FUN_0052f9d0(this,0x500,0,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x501,0x2d,0xf7,s_VERDANA8_fnt_00563e98,s__Pizza_Tingeltangel_0056510c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x501,0);
    FUN_0052f9d0(this,0x501,0,0x87,0,0);
  }
  FUN_00531850(this,0x502,0xb5,0xe5,s_LOGORAHMEN_00_spr_005650f8);
  FUN_00531c60(this,0x510,0xb7,0xe7,0x2c,0x1d,0x10);
  FUN_00531850(this,0x506,0x27,0x79,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x507,0x32,0xb0,s_VERDANA8_fnt_00563e98,DAT_00582a18);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x507,0);
    FUN_0052f9d0(this,0x507,2,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x508,0x8c,0xb0,s_VERDANA8_fnt_00563e98,DAT_00581580);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x508,0);
    FUN_0052f9d0(this,0x508,2,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x509,0x2f,0x83,s_VERDANA8_fnt_00563e98,DAT_00581bf4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x509,0);
    FUN_0052f9d0(this,0x509,0,100,0,0);
  }
  iVar1 = FUN_0052f850(this,0x50b,0x30,0x6d,s_VERDANA8_fnt_00563e98,DAT_00581a6c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x50b,0);
    FUN_0052f9d0(this,0x50b,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x50d,0xaa,0x6d,s_VERDANA7_fnt_00563ec8,&DAT_00565078);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x50d,0);
    FUN_0052f9d0(this,0x50d,1,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x50e,0x30,0x97,s_VEDANA11_fnt_00564090,&DAT_005666ac);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x50e,0);
    FUN_0052f9d0(this,0x50e,2,0xb4,0,0);
  }
  FUN_0052f5b0(this,0x50f,0xd1,0x7f,s_PB33_00_spr_00564ba0,0,0);
  FUN_0052f5b0(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  FUN_00531850(this,0x1f42,0x27,0x10b,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f690(this,0x1f44,0x8e,0x129,s_VERDANA8_fnt_00563e98,DAT_00581b08,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x1f44,0x9a,0,0);
    FUN_0052f7a0(this,0x1f44,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f850(this,0x1f4b,0xbd,0x169,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f4b,0xff);
    FUN_0052f9d0(this,0x1f4b,1,0x28,0,0);
  }
  FUN_00531850(this,0x1f4d,0xb7,0xe7,s_PLAYLOG_8_01_02_spr_00564744);
  iVar1 = FUN_0052f850(this,0x1f54,0x33,0x168,s_VERDANA7_fnt_00563ec8,DAT_00582c30);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f54,0);
    FUN_0052f9d0(this,0x1f54,0,0xa0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f55,0xbd,0x153,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f55,0);
    FUN_0052f9d0(this,0x1f55,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f58,0x8a,0x149,s_VERDANA7_fnt_00563ec8,DAT_00582a40);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f58,0);
    FUN_0052f9d0(this,0x1f58,0,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f59,0x8a,0x153,s_VERDANA7_fnt_00563ec8,DAT_00580f10);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f59,0);
    FUN_0052f9d0(this,0x1f59,0,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f5b,0xbd,0x149,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f5b,0);
    FUN_0052f9d0(this,0x1f5b,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f5d,0x8b,0x13f,s_VERDANA7_fnt_00563ec8,DAT_00581fc0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f5d,0);
    FUN_0052f9d0(this,0x1f5d,0,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f5e,0xb3,0x13f,s_VERDANA7_fnt_00563ec8,s__300000__00566688);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f5e,0);
    FUN_0052f9d0(this,0x1f5e,1,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f5f,0x31,0x114,s_VERDANA10_fnt_00563e64,DAT_005816fc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f5f,0);
    FUN_0052f9d0(this,0x1f5f,0,0xb4,0,0);
  }
  return this;
}

