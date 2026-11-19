// rea decompile_all
// name: FUN_00429fb0
// address: 0x429fb0
// body: available
// range: 0x429fb0-0x42ad27 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_00429fb0(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004a4b60);
  *param_1 = iVar1;
  this = (void *)UI_FindWindowByID(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  iVar1 = UI_AddText(this,0x479,0x2a,5,s_TIMESFONT_fnt_00563ea8,DAT_00582300);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x479,0);
    FUN_0052f9d0(this,0x479,2,0xbe,0,0);
  }
  UI_AddImage(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  iVar1 = FUN_0052f690(this,0x1f4d,0x8e,0x111,s_VERDANA8_fnt_00563e98,DAT_00581518,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x1f4d,0,0,0);
    FUN_0052f7a0(this,0x1f4d,2,0x54,0,0,0xfffe);
  }
  iVar1 = UI_AddText(this,0x1f54,0xb5,0x167,s_VERDANA8_fnt_00563e98,&DAT_005644f4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f54,0);
    FUN_0052f9d0(this,0x1f54,2,0x2d,0,0);
  }
  iVar1 = UI_AddText(this,0x1f58,0x32,0xfe,s_VERDANA7_fnt_00563ec8,DAT_00581ac8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f58,0);
    FUN_0052f9d0(this,0x1f58,0,0x3c,0,0);
  }
  iVar1 = UI_AddText(this,0x1f59,0x71,0xfd,s_VERDANA8_fnt_00563e98,&DAT_00564538);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f59,0xff);
    FUN_0052f9d0(this,0x1f59,1,0x14,0,0);
  }
  iVar1 = UI_AddText(this,0x1f67,0x74,0x168,s_VERDANA8_fnt_00563e98,&DAT_00564508);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f67,0);
    FUN_0052f9d0(this,0x1f67,2,0x2d,0,0);
  }
  iVar1 = UI_AddText(this,0x1f68,0x36,0x168,s_VERDANA8_fnt_00563e98,&DAT_00564538);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f68,0);
    FUN_0052f9d0(this,0x1f68,2,0x2d,0,0);
  }
  iVar1 = UI_AddText(this,0x1f73,0x33,0xc4,s_VERDANA7_fnt_00563ec8,DAT_005828f8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f73,0);
    FUN_0052f9d0(this,0x1f73,0,0xffff,0,0);
  }
  iVar1 = UI_AddText(this,0x1f74,0x82,0xc4,s_VERDANA7_fnt_00563ec8,s__2000__00565158);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f74,0);
    FUN_0052f9d0(this,0x1f74,1,100,0,0);
  }
  iVar1 = UI_AddText(this,0x1f77,0x33,0xcf,s_VERDANA7_fnt_00563ec8,DAT_005829f8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f77,0);
    FUN_0052f9d0(this,0x1f77,0,100,0,0);
  }
  iVar1 = UI_AddText(this,0x1f78,0x82,0xcf,s_VERDANA7_fnt_00563ec8,s__100_000__00565098);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f78,0);
    FUN_0052f9d0(this,0x1f78,1,100,0,0);
  }
  iVar1 = UI_AddText(this,0x1f79,0x33,0xda,s_VERDANA7_fnt_00563ec8,DAT_005818f0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f79,0);
    FUN_0052f9d0(this,0x1f79,0,0x82,0,0);
  }
  iVar1 = UI_AddText(this,0x1f7a,0x81,0xda,s_VERDANA7_fnt_00563ec8,&DAT_00565154);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f7a,0);
    FUN_0052f9d0(this,0x1f7a,1,100,0,0);
  }
  iVar1 = UI_AddText(this,0x1f7b,0x30,0x112,s_VERDANA7_fnt_00563ec8,DAT_00582300);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f7b,0);
    FUN_0052f9d0(this,0x1f7b,0,0x2d,0,0);
  }
  iVar1 = UI_AddText(this,0x1f7c,0x31,0x11c,s_VERDANA8_fnt_00563e98,s__100_000__00565098);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f7c,0);
    FUN_0052f9d0(this,0x1f7c,0,0x50,0,0);
  }
  UI_AddSprite(this,0x1f7f,0x28,0x10b,s_TRENNZEILE_spr_00563eb8);
  UI_AddSprite(this,0x1f80,0x28,0x12a,s_TRENNZEILE_spr_00563eb8);
  iVar1 = UI_AddText(this,0x1f81,0x33,0x134,s_VERDANA8_fnt_00563e98,DAT_00580fec);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f81,0);
    FUN_0052f9d0(this,0x1f81,0,0x82,0,0);
  }
  iVar1 = UI_AddText(this,0x1f82,0x83,0x134,s_VERDANA8_fnt_00563e98,s__Stufe_1_0056452c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f82,0);
    FUN_0052f9d0(this,0x1f82,1,100,0,0);
  }
  iVar1 = FUN_0052f690(this,0x1f83,0x30,0xe7,s_VERDANA8_fnt_00563e98,DAT_0058202c,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x1f83,0,0,0);
    FUN_0052f7a0(this,0x1f83,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f690(this,0x1f84,0x8e,0xe7,s_VERDANA8_fnt_00563e98,DAT_0058229c,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x1f84,0,0,0);
    FUN_0052f7a0(this,0x1f84,2,0x54,0,0,0xfffe);
  }
  UI_AddSprite(this,0x1fa1,0x32,0x27,s_RAHMEN06_spr_00565144);
  UI_AddSprite(this,0x1fa2,0x32,0x3a,s_RAHMEN06_spr_00565144);
  UI_AddSprite(this,0x1fa3,0x32,0x4d,s_RAHMEN06_spr_00565144);
  UI_AddSprite(this,0x1fa4,0x32,0x60,s_RAHMEN06_spr_00565144);
  UI_AddSprite(this,0x1fa5,0x32,0x73,s_RAHMEN06_spr_00565144);
  UI_AddSprite(this,0x1fa6,0x32,0x86,s_RAHMEN06_spr_00565144);
  UI_AddSprite(this,0x1fa7,0x32,0x99,s_RAHMEN06_spr_00565144);
  UI_AddSprite(this,0x1fa8,0x32,0xac,s_RAHMEN06_spr_00565144);
  iVar1 = FUN_0052fc00(this,0x1fa9,0xde,0x30,0x92,s_SL01_00_spr_0056448c,0,1);
  if (iVar1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    FUN_0052fcc0(this,0x1fa9,&local_10);
  }
  iVar1 = UI_AddText(this,0x1fab,0x34,0x2b,s_VERDANA8_fnt_00563e98,s__Filialname_005644d4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fab,0);
    FUN_0052f9d0(this,0x1fab,0,100,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x1fbb,0x8e,0xfe,s_VERDANA7_fnt_00563ec8,DAT_00581cc8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fbb,0);
    FUN_0052f9d0(this,0x1fbb,0,0x4b,0,0);
  }
  iVar1 = UI_AddText(this,0x1fbc,0xd2,0xfd,s_VERDANA8_fnt_00563e98,&DAT_00564538);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fbc,0xff);
    FUN_0052f9d0(this,0x1fbc,1,0x14,0,0);
  }
  UI_AddImage(this,0x1fbd,0x90,0x26,s_PB26_00_spr_00564610,0,0);
  UI_AddImage(this,0x1fbe,0xba,0x26,s_PB27_00_spr_005645fc,0,0);
  iVar1 = UI_AddText(this,0x1fbf,0xa8,0x2b,s_VERDANA8_fnt_00563e98,&DAT_00564538);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fbf,0xff);
    FUN_0052f9d0(this,0x1fbf,2,0x14,0,0);
  }
  iVar1 = UI_AddText(this,0x1fc0,0x34,0x3e,s_VERDANA8_fnt_00563e98,s__Filialname_005644d4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fc0,0);
    FUN_0052f9d0(this,0x1fc0,0,100,0xffff,0);
  }
  UI_AddImage(this,0x1fc1,0x90,0x39,s_PB26_00_spr_00564610,0,0);
  iVar1 = UI_AddText(this,0x1fc2,0xa8,0x3e,s_VERDANA8_fnt_00563e98,&DAT_00564538);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fc2,0xff);
    FUN_0052f9d0(this,0x1fc2,2,0x14,0,0);
  }
  UI_AddImage(this,0x1fc3,0xba,0x39,s_PB27_00_spr_005645fc,0,0);
  iVar1 = UI_AddText(this,0x1fc4,0x34,0x50,s_VERDANA8_fnt_00563e98,s__Filialname_005644d4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fc4,0);
    FUN_0052f9d0(this,0x1fc4,0,100,0xffff,0);
  }
  UI_AddImage(this,0x1fc5,0x90,0x4b,s_PB26_00_spr_00564610,0,0);
  iVar1 = UI_AddText(this,0x1fc6,0xa8,0x50,s_VERDANA8_fnt_00563e98,&DAT_00564538);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fc6,0xff);
    FUN_0052f9d0(this,0x1fc6,2,0x14,0,0);
  }
  UI_AddImage(this,0x1fc7,0xba,0x4b,s_PB27_00_spr_005645fc,0,0);
  iVar1 = UI_AddText(this,0x1fc8,0x34,100,s_VERDANA8_fnt_00563e98,s__Filialname_005644d4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fc8,0);
    FUN_0052f9d0(this,0x1fc8,0,100,0xffff,0);
  }
  UI_AddImage(this,0x1fc9,0x90,0x5f,s_PB26_00_spr_00564610,0,0);
  iVar1 = UI_AddText(this,0x1fca,0xa8,100,s_VERDANA8_fnt_00563e98,&DAT_00564538);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fca,0xff);
    FUN_0052f9d0(this,0x1fca,2,0x14,0,0);
  }
  UI_AddImage(this,0x1fcb,0xba,0x5f,s_PB27_00_spr_005645fc,0,0);
  iVar1 = UI_AddText(this,0x1fcc,0x34,0x77,s_VERDANA8_fnt_00563e98,s__Filialname_005644d4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fcc,0);
    FUN_0052f9d0(this,0x1fcc,0,100,0xffff,0);
  }
  UI_AddImage(this,0x1fcd,0x90,0x72,s_PB26_00_spr_00564610,0,0);
  iVar1 = UI_AddText(this,0x1fce,0xa8,0x77,s_VERDANA8_fnt_00563e98,&DAT_00564538);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fce,0xff);
    FUN_0052f9d0(this,0x1fce,2,0x14,0,0);
  }
  UI_AddImage(this,0x1fcf,0xba,0x72,s_PB27_00_spr_005645fc,0,0);
  iVar1 = UI_AddText(this,0x1fd0,0x34,0x89,s_VERDANA8_fnt_00563e98,s__Filialname_005644d4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fd0,0);
    FUN_0052f9d0(this,0x1fd0,0,100,0xffff,0);
  }
  UI_AddImage(this,0x1fd1,0x90,0x84,s_PB26_00_spr_00564610,0,0);
  iVar1 = UI_AddText(this,0x1fd2,0xa8,0x89,s_VERDANA8_fnt_00563e98,&DAT_00564538);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fd2,0xff);
    FUN_0052f9d0(this,0x1fd2,2,0x14,0,0);
  }
  UI_AddImage(this,0x1fd3,0xba,0x84,s_PB27_00_spr_005645fc,0,0);
  iVar1 = UI_AddText(this,0x1fd4,0x34,0x9d,s_VERDANA8_fnt_00563e98,s__Filialname_005644d4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fd4,0);
    FUN_0052f9d0(this,0x1fd4,0,100,0xffff,0);
  }
  UI_AddImage(this,0x1fd5,0x90,0x98,s_PB26_00_spr_00564610,0,0);
  iVar1 = UI_AddText(this,0x1fd6,0xa8,0x9d,s_VERDANA8_fnt_00563e98,&DAT_00564538);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fd6,0xff);
    FUN_0052f9d0(this,0x1fd6,2,0x14,0,0);
  }
  UI_AddImage(this,0x1fd7,0xba,0x98,s_PB27_00_spr_005645fc,0,0);
  iVar1 = UI_AddText(this,0x1fd8,0x34,0xb0,s_VERDANA8_fnt_00563e98,s__Filialname_005644d4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fd8,0);
    FUN_0052f9d0(this,0x1fd8,0,100,0xffff,0);
  }
  UI_AddImage(this,0x1fd9,0x90,0xab,s_PB26_00_spr_00564610,0,0);
  iVar1 = UI_AddText(this,0x1fda,0xa8,0xb0,s_VERDANA8_fnt_00563e98,&DAT_00564538);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fda,0xff);
    FUN_0052f9d0(this,0x1fda,2,0x14,0,0);
  }
  UI_AddImage(this,0x1fdb,0xba,0xab,s_PB27_00_spr_005645fc,0,0);
  UI_AddSprite(this,0x1fdc,0x80,0x14f,&DAT_0056450c);
  UI_AddSprite(this,0x1fdd,0x42,0x14f,s_SCHLAGKRAFT_spr_0056451c);
  UI_AddSprite(this,0x1fde,0xc1,0x14f,s_PANZERUNG_spr_005644f8);
  iVar1 = UI_AddText(this,0x1fdf,0x5c,0x112,s_VERDANA7_fnt_00563ec8,s__Stufe_2_00565138);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fdf,0);
    FUN_0052f9d0(this,0x1fdf,0,0x32,0,0);
  }
  return this;
}

