// rea decompile_all
// name: SubMenu_BuildMayor
// address: 0x44e390
// body: available
// range: 0x44e390-0x44ee1b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl SubMenu_BuildMayor(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
                    /* Builds the mayor page. */
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004bb4e0);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  iVar1 = FUN_0052f850(this,0x44f,0x2b,5,s_TIMESFONT_fnt_00563ea8,DAT_00581d20);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x44f,0);
    FUN_0052f9d0(this,0x44f,2,0xbe,0,0);
  }
  FUN_0052f5b0(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  iVar1 = UI_CreateSlider(this,0x1fa8,0x3e,0x3c,0xa0,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xf700;
    local_4 = 0;
    FUN_0052fcc0(this,0x1fa8,&local_10);
  }
  iVar1 = FUN_0052f850(this,0x1fa9,0x34,0x28,s_VERDANA8_fnt_00563e98,DAT_00580fe8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fa9,0);
    FUN_0052f9d0(this,0x1fa9,2,0xaa,0,0);
  }
  FUN_00531850(this,0x1faa,0x27,0xb6,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x1fab,0x32,0x48,s_VERDANA7_fnt_00563ec8,DAT_00580b60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fab,0);
    FUN_0052f9d0(this,0x1fab,0,0x8c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fac,0xaf,0x48,s_VERDANA7_fnt_00563ec8,&DAT_00565650);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fac,0);
    FUN_0052f9d0(this,0x1fac,1,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1faf,0x32,0x53,s_VERDANA7_fnt_00563ec8,DAT_0058283c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1faf,0);
    FUN_0052f9d0(this,0x1faf,0,0xa0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fb0,0xaf,0x53,s_VERDANA7_fnt_00563ec8,&DAT_00566548);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fb0,0);
    FUN_0052f9d0(this,0x1fb0,1,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fc8,0x31,0x117,s_VERDANA8_fnt_00563e98,DAT_00580d6c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fc8,0);
    FUN_0052f9d0(this,0x1fc8,0,0x82,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x1fc9,0x31,0x125,s_VERDANA8_fnt_00563e98,s__Pizza_Tingeltangel_0056510c
                      );
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fc9,0);
    FUN_0052f9d0(this,0x1fc9,0,0x87,0,0);
  }
  FUN_00531850(this,0x1fca,0xb5,0x115,s_LOGORAHMEN_00_spr_005650f8);
  UI_CreateBitmapGadget(this,0x1fcb,0xb7,0x117,0x2c,0x1d,0x10);
  iVar1 = UI_AddTextButton(this,0x1fce,0x30,0x13d,s_VERDANA8_fnt_00563e98,DAT_00580e6c,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x1fce,0,0,0);
    FUN_0052f7a0(this,0x1fce,2,0x54,0,0,0xfffe);
  }
  iVar1 = UI_AddTextButton(this,0x1fcf,0x8e,0x13d,s_VERDANA8_fnt_00563e98,s___5000__00565634,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x1fcf,0,0,0);
    FUN_0052f7a0(this,0x1fcf,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f850(this,0x1fd2,0x31,0x158,s_VERDANA8_fnt_00563e98,DAT_005818a0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fd2,0);
    FUN_0052f9d0(this,0x1fd2,0,0x87,0x1e,0);
  }
  iVar1 = FUN_0052f850(this,0x1fd3,0x88,0x165,s_VERDANA8_fnt_00563e98,s__100_000__00565098);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fd3,0);
    FUN_0052f9d0(this,0x1fd3,1,0x5a,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x1fd6,0x31,0x80,s_VERDANA10_fnt_00563e64,DAT_00581c64);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fd6,0);
    FUN_0052f9d0(this,0x1fd6,0,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fd7,0x81,0x80,s_VERDANA10_fnt_00563e64,s__Filialname_005644d4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fd7,0);
    FUN_0052f9d0(this,0x1fd7,1,100,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fd8,0x32,0x69,s_VERDANA10_fnt_00563e64,DAT_005825f4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fd8,0);
    FUN_0052f9d0(this,0x1fd8,0,0x69,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fd9,0x31,0x90,s_VERDANA10_fnt_00563e64,DAT_00580bd0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fd9,0);
    FUN_0052f9d0(this,0x1fd9,0,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fda,99,0x90,s_VERDANA10_fnt_00563e64,s__Sternvergabe_00566538);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fda,0);
    FUN_0052f9d0(this,0x1fda,1,0x82,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fdd,0x31,0xa1,s_VERDANA10_fnt_00563e64,DAT_00582ef8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fdd,0);
    FUN_0052f9d0(this,0x1fdd,0,0x8c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fde,0xbd,0xa1,s_VERDANA10_fnt_00563e64,&DAT_00566534);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fde,0);
    FUN_0052f9d0(this,0x1fde,1,0x28,0,0);
  }
  FUN_00531850(this,0x1fdf,0x27,0x10b,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x1fe0,0x32,0xc1,s_VERDANA10_fnt_00563e64,DAT_00581350);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fe0,0);
    FUN_0052f9d0(this,0x1fe0,0,0x69,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fe2,0x40,0xe1,s_VERDANA7_fnt_00563ec8,DAT_00582f9c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fe2,0);
    FUN_0052f9d0(this,0x1fe2,0,0x6e,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fe3,0xb6,0xe1,s_VERDANA7_fnt_00563ec8,&DAT_005650bc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fe3,0);
    FUN_0052f9d0(this,0x1fe3,1,0x14,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fe4,0xd1,0xe1,s_VERDANA7_fnt_00563ec8,&DAT_005650b8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fe4,0);
    FUN_0052f9d0(this,0x1fe4,1,0x14,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fe5,0x40,0xee,s_VERDANA7_fnt_00563ec8,DAT_00582824);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fe5,0);
    FUN_0052f9d0(this,0x1fe5,0,0x6e,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fe6,0xb6,0xee,s_VERDANA7_fnt_00563ec8,&DAT_005650bc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fe6,0);
    FUN_0052f9d0(this,0x1fe6,1,0x14,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fe7,0xd1,0xee,s_VERDANA7_fnt_00563ec8,&DAT_005650b8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fe7,0);
    FUN_0052f9d0(this,0x1fe7,1,0x14,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fe8,0x40,0xfb,s_VERDANA7_fnt_00563ec8,DAT_005820a8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fe8,0);
    FUN_0052f9d0(this,0x1fe8,0,0x78,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fe9,0xb6,0xfb,s_VERDANA7_fnt_00563ec8,&DAT_005650bc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fe9,0);
    FUN_0052f9d0(this,0x1fe9,1,0x14,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fea,0xd1,0xfb,s_VERDANA7_fnt_00563ec8,&DAT_005650b8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fea,0);
    FUN_0052f9d0(this,0x1fea,1,0x14,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1feb,0x8d,0xc3,s_VERDANA7_fnt_00563ec8,DAT_00580e74);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1feb,0);
    FUN_0052f9d0(this,0x1feb,1,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fec,0xc5,0xc3,s_VERDANA7_fnt_00563ec8,DAT_00582acc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fec,0);
    FUN_0052f9d0(this,0x1fec,1,0x1e,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1ff0,0x40,0xd4,s_VERDANA7_fnt_00563ec8,DAT_0058205c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1ff0,0);
    FUN_0052f9d0(this,0x1ff0,0,0x78,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1ff1,0xb6,0xd4,s_VERDANA7_fnt_00563ec8,&DAT_005650bc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1ff1,0);
    FUN_0052f9d0(this,0x1ff1,1,0x14,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1ff2,0xd1,0xd4,s_VERDANA7_fnt_00563ec8,&DAT_005650b8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1ff2,0);
    FUN_0052f9d0(this,0x1ff2,1,0x14,0,0);
  }
  FUN_00531850(this,0x1ff3,0xb7,0x117,s_PLAYLOG_8_01_02_spr_00564744);
  return this;
}

