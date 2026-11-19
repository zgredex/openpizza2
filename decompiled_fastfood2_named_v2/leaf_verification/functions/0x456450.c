// rea decompile_all
// name: FUN_00456450
// address: 0x456450
// body: available
// range: 0x456450-0x456f60 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_00456450(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004bf0f0);
  *param_1 = iVar1;
  this = (void *)UI_FindWindowByID(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  iVar1 = FUN_0052f850(this,0x472,0x2a,5,s_TIMESFONT_fnt_00563ea8,DAT_00582bc8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x472,0);
    FUN_0052f9d0(this,0x472,2,0xbe,0,0);
  }
  iVar1 = FUN_0052f690(this,0x484,0x8e,0xf4,s_VERDANA8_fnt_00563e98,DAT_00581068,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x484,0,0,0);
    FUN_0052f7a0(this,0x484,2,0x54,0,0,0xfffe);
  }
  FUN_0052f5b0(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  iVar1 = FUN_0052f850(this,0x1f46,0xa3,0x149,s_VERDANA8_fnt_00563e98,&DAT_00565088);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f46,0);
    FUN_0052f9d0(this,0x1f46,2,0x1e,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f47,0x83,0x149,s_VERDANA8_fnt_00563e98,&DAT_00565094);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f47,0);
    FUN_0052f9d0(this,0x1f47,2,0x1e,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f48,0xc5,0x149,s_VERDANA8_fnt_00563e98,&DAT_00565088);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f48,0);
    FUN_0052f9d0(this,0x1f48,2,0x1e,0,0);
  }
  FUN_00531850(this,0x1f4b,0x27,0x10c,s_TRENNZEILE_spr_00563eb8);
  FUN_00531850(this,0x1f5a,0x2f,0x1e,s_RAHMEN03_spr_00564bf8);
  iVar1 = FUN_0052fc00(this,0x1f5c,0xdd,0x2d,0xc5,s_SL01_00_spr_0056448c,0,1);
  if (iVar1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    FUN_0052fcc0(this,0x1f5c,&local_10);
  }
  iVar1 = FUN_0052f850(this,0x1f5d,0x34,0x24,s_VERDANA10_fnt_00563e64,s__Gangster_00566040);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f5d,0);
    FUN_0052f9d0(this,0x1f5d,0,0x73,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f60,0x34,0x37,s_VERDANA10_fnt_00563e64,s__Gangster_00566040);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f60,0);
    FUN_0052f9d0(this,0x1f60,0,0x73,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f62,0x34,0x5d,s_VERDANA10_fnt_00563e64,&DAT_0056674c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f62,0);
    FUN_0052f9d0(this,0x1f62,0,0x73,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f63,0x34,0x4a,s_VERDANA10_fnt_00563e64,s__Gangster_00566040);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f63,0);
    FUN_0052f9d0(this,0x1f63,0,0x73,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f65,0x34,0xa9,s_VERDANA10_fnt_00563e64,&DAT_0056674c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f65,0);
    FUN_0052f9d0(this,0x1f65,0,0x73,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f68,0x34,0x96,s_VERDANA10_fnt_00563e64,&DAT_0056674c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f68,0);
    FUN_0052f9d0(this,0x1f68,0,0x73,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f69,0x34,0x83,s_VERDANA10_fnt_00563e64,&DAT_0056674c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f69,0);
    FUN_0052f9d0(this,0x1f69,0,0x73,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f6c,0x34,0x70,s_VERDANA10_fnt_00563e64,&DAT_0056674c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f6c,0);
    FUN_0052f9d0(this,0x1f6c,0,0x73,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f6d,0x34,0xbc,s_VERDANA10_fnt_00563e64,s__Kurier_005665e0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f6d,0);
    FUN_0052f9d0(this,0x1f6d,0,0x73,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f71,0x34,0xe2,s_VERDANA10_fnt_00563e64,s__Kurier_005665e0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f71,0);
    FUN_0052f9d0(this,0x1f71,0,0x73,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f72,0x34,0xcf,s_VERDANA10_fnt_00563e64,s__Kurier_005665e0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f72,0);
    FUN_0052f9d0(this,0x1f72,0,0x73,0,0);
  }
  iVar1 = FUN_0052fc00(this,0x1f8e,0x8c,0x2a,0x46,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    FUN_0052fcc0(this,0x1f8e,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x1f8f,0x8c,0x3d,0x46,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    FUN_0052fcc0(this,0x1f8f,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x1f90,0x8c,0x50,0x46,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    FUN_0052fcc0(this,0x1f90,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x1f91,0x8c,99,0x46,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    FUN_0052fcc0(this,0x1f91,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x1f92,0x8c,0x76,0x46,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    FUN_0052fcc0(this,0x1f92,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x1f93,0x8c,0x89,0x46,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    FUN_0052fcc0(this,0x1f93,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x1f94,0x8c,0x9c,0x46,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    FUN_0052fcc0(this,0x1f94,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x1f95,0x8c,0xaf,0x46,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    FUN_0052fcc0(this,0x1f95,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x1f96,0x8c,0xc2,0x46,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    FUN_0052fcc0(this,0x1f96,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x1f97,0x8c,0xd5,0x46,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    FUN_0052fcc0(this,0x1f97,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x1f98,0x8c,0xe8,0x46,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    FUN_0052fcc0(this,0x1f98,&local_10);
  }
  iVar1 = FUN_0052f850(this,0x1f9a,0x33,0x148,s_VERDANA8_fnt_00563e98,DAT_00581ebc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f9a,0);
    FUN_0052f9d0(this,0x1f9a,0,0x50,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f9b,0xa3,0x157,s_VERDANA8_fnt_00563e98,&DAT_00565088);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f9b,0);
    FUN_0052f9d0(this,0x1f9b,2,0x1e,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f9c,0x83,0x157,s_VERDANA8_fnt_00563e98,&DAT_00565094);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f9c,0);
    FUN_0052f9d0(this,0x1f9c,2,0x1e,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f9d,0xc5,0x157,s_VERDANA8_fnt_00563e98,&DAT_00565088);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f9d,0);
    FUN_0052f9d0(this,0x1f9d,2,0x1e,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f9e,0x33,0x156,s_VERDANA8_fnt_00563e98,DAT_00582e58);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f9e,0);
    FUN_0052f9d0(this,0x1f9e,0,0x50,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f9f,0xa3,0x165,s_VERDANA8_fnt_00563e98,&DAT_00565088);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f9f,0);
    FUN_0052f9d0(this,0x1f9f,2,0x1e,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fa0,0x83,0x165,s_VERDANA8_fnt_00563e98,&DAT_00565094);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fa0,0);
    FUN_0052f9d0(this,0x1fa0,2,0x1e,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fa1,0xc5,0x165,s_VERDANA8_fnt_00563e98,&DAT_00565088);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fa1,0);
    FUN_0052f9d0(this,0x1fa1,2,0x1e,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fa2,0x33,0x164,s_VERDANA8_fnt_00563e98,DAT_00582880);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fa2,0);
    FUN_0052f9d0(this,0x1fa2,0,0x50,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fa3,0x34,0x116,s_VERDANA10_fnt_00563e64,DAT_00581b48);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fa3,0);
    FUN_0052f9d0(this,0x1fa3,0,0x73,0,0);
  }
  FUN_00531850(this,0x1fa4,0xa9,0x130,&DAT_0056450c);
  FUN_00531850(this,0x1fa5,0x88,0x130,s_SCHLAGKRAFT_spr_0056451c);
  FUN_00531850(this,0x1fa6,0xca,0x130,s_PANZERUNG_spr_005644f8);
  return this;
}

