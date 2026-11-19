// rea decompile_all
// name: SubMenu_BuildGuardHiring
// address: 0x453760
// body: available
// range: 0x453760-0x453eb3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl SubMenu_BuildGuardHiring(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
                    /* Builds the guard hiring page. */
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004bd4d0);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  iVar1 = FUN_0052f850(this,0x479,0x2a,5,s_TIMESFONT_fnt_00563ea8,DAT_00582ebc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x479,0);
    FUN_0052f9d0(this,0x479,2,0xbe,0,0);
  }
  FUN_0052f5b0(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  FUN_00531850(this,0x1f46,0x27,0xb6,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x1f4a,0x2f,0x82,s_VERDANA10_fnt_00563e64,DAT_005825f4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f4a,0);
    FUN_0052f9d0(this,0x1f4a,0,0x46,0,0);
  }
  iVar1 = UI_AddTextButton(this,0x1f4d,0x8e,0x112,s_VERDANA8_fnt_00563e98,DAT_0058229c,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x1f4d,0,0,0);
    FUN_0052f7a0(this,0x1f4d,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f850(this,0x1f4e,0x4e,0x33,s_VEDANA11_fnt_00564090,DAT_00582ebc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f4e,0);
    FUN_0052f9d0(this,0x1f4e,2,0x78,0,0);
  }
  iVar1 = UI_CreateSlider(this,0x1f4f,0x3e,0x69,0xa0,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xf700;
    local_4 = 0;
    FUN_0052fcc0(this,0x1f4f,&local_10);
  }
  iVar1 = FUN_0052f850(this,0x1f50,0x34,0x56,s_VERDANA8_fnt_00563e98,DAT_00582b0c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f50,0);
    FUN_0052f9d0(this,0x1f50,2,0xaa,0,0);
  }
  FUN_00531850(this,0x1f51,0x27,0x79,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x1f52,0x2f,0x95,s_VERDANA10_fnt_00563e64,DAT_00582608);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f52,0);
    FUN_0052f9d0(this,0x1f52,0,0xb4,0x23,0);
  }
  iVar1 = FUN_0052f850(this,0x1f54,0xb5,0x167,s_VERDANA8_fnt_00563e98,&DAT_005644f4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f54,0);
    FUN_0052f9d0(this,0x1f54,2,0x2d,0,0);
  }
  FUN_00531850(this,0x1f57,0x27,0x12a,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x1f58,0x33,0xe9,s_VERDANA8_fnt_00563e98,DAT_00582750);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f58,0);
    FUN_0052f9d0(this,0x1f58,0,100,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f59,0x83,0xe9,s_VERDANA8_fnt_00563e98,&DAT_005650ac);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f59,0);
    FUN_0052f9d0(this,0x1f59,1,100,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f67,0x74,0x168,s_VERDANA8_fnt_00563e98,&DAT_00564508);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f67,0);
    FUN_0052f9d0(this,0x1f67,2,0x2d,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f68,0x36,0x168,s_VERDANA8_fnt_00563e98,&DAT_00564538);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f68,0);
    FUN_0052f9d0(this,0x1f68,2,0x2d,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f73,0x33,0xcd,s_VERDANA8_fnt_00563e98,DAT_005828f8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f73,0);
    FUN_0052f9d0(this,0x1f73,0,100,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f74,0x83,0xcd,s_VERDANA8_fnt_00563e98,s__2000__00565158);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f74,0);
    FUN_0052f9d0(this,0x1f74,1,100,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f75,0x33,0x134,s_VERDANA8_fnt_00563e98,DAT_00580fec);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f75,0);
    FUN_0052f9d0(this,0x1f75,0,0x82,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f76,0x83,0x135,s_VERDANA8_fnt_00563e98,s__Stufe_1_0056452c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f76,0);
    FUN_0052f9d0(this,0x1f76,1,100,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f77,0x33,0xdb,s_VERDANA8_fnt_00563e98,DAT_005829f8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f77,0);
    FUN_0052f9d0(this,0x1f77,0,100,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f78,0x83,0xdb,s_VERDANA8_fnt_00563e98,s__100_000__00565098);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f78,0);
    FUN_0052f9d0(this,0x1f78,1,100,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f79,0x33,0xc0,s_VERDANA8_fnt_00563e98,DAT_00582574);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f79,0);
    FUN_0052f9d0(this,0x1f79,0,0x82,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f7a,0x83,0xc0,s_VERDANA8_fnt_00563e98,&DAT_00565154);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f7a,0);
    FUN_0052f9d0(this,0x1f7a,1,100,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f7b,0x33,0x103,s_VERDANA8_fnt_00563e98,DAT_00582db0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f7b,0);
    FUN_0052f9d0(this,0x1f7b,0,0xa0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f7c,0x83,0x103,s_VERDANA8_fnt_00563e98,&DAT_005650bc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f7c,0);
    FUN_0052f9d0(this,0x1f7c,1,100,0,0);
  }
  FUN_0052f5b0(this,0x1f7d,0x4c,0x31,s_PB22_00_spr_00564174,0,0);
  FUN_0052f5b0(this,0x1f7e,0xaf,0x31,s_PB24_00_spr_00564144,0,0);
  FUN_00531850(this,0x1f7f,0x80,0x14f,&DAT_0056450c);
  FUN_00531850(this,0x1f80,0x42,0x14f,s_SCHLAGKRAFT_spr_0056451c);
  FUN_00531850(this,0x1f81,0xc1,0x14f,s_PANZERUNG_spr_005644f8);
  FUN_00531850(this,0x1f82,0x2b,0x2c,s_WACHE_spr_00566664);
  return this;
}

