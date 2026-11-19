// rea decompile_all
// name: SubMenu_BuildTownAdministration
// address: 0x42f340
// body: available
// range: 0x42f340-0x42fe0b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl SubMenu_BuildTownAdministration(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
                    /* Builds the town administration page. */
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004aa540);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  iVar1 = FUN_0052f850(this,0x44f,0x2b,5,s_TIMESFONT_fnt_00563ea8,DAT_00581974);
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
  iVar1 = FUN_0052f850(this,0x1fa9,0x34,0x28,s_VERDANA8_fnt_00563e98,DAT_005812b4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fa9,0);
    FUN_0052f9d0(this,0x1fa9,2,0xaa,0,0);
  }
  FUN_00531850(this,0x1faa,0x27,0xb6,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x1fab,0x32,0x48,s_VERDANA7_fnt_00563ec8,DAT_00581284);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fab,0);
    FUN_0052f9d0(this,0x1fab,0,0x8c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fac,0xaf,0x48,s_VERDANA7_fnt_00563ec8,&DAT_00565650);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fac,0);
    FUN_0052f9d0(this,0x1fac,1,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1faf,0x32,0x53,s_VERDANA7_fnt_00563ec8,DAT_0058291c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1faf,0);
    FUN_0052f9d0(this,0x1faf,0,0x8c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fb0,0xaf,0x53,s_VERDANA7_fnt_00563ec8,s___10__00565648);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fb0,0);
    FUN_0052f9d0(this,0x1fb0,1,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fb1,0x67,0x82,s_VERDANA7_fnt_00563ec8,DAT_00582a5c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fb1,0);
    FUN_0052f9d0(this,0x1fb1,1,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fb2,0x96,0x8f,s_VERDANA7_fnt_00563ec8,&DAT_005650bc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fb2,0);
    FUN_0052f9d0(this,0x1fb2,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fb3,0x82,0x82,s_VERDANA7_fnt_00563ec8,DAT_00582928);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fb3,0);
    FUN_0052f9d0(this,0x1fb3,1,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fb4,0x96,0x9a,s_VERDANA7_fnt_00563ec8,&DAT_005650b8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fb4,0);
    FUN_0052f9d0(this,0x1fb4,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fb5,0xa9,0x82,s_VERDANA7_fnt_00563ec8,DAT_00581ca8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fb5,0);
    FUN_0052f9d0(this,0x1fb5,1,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fb6,0x96,0xa5,s_VERDANA7_fnt_00563ec8,&DAT_005650b4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fb6,0);
    FUN_0052f9d0(this,0x1fb6,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fb7,0x31,0x8f,s_VERDANA7_fnt_00563ec8,DAT_00581abc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fb7,0);
    FUN_0052f9d0(this,0x1fb7,0,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fb8,0x31,0x9a,s_VERDANA7_fnt_00563ec8,DAT_00580f3c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fb8,0);
    FUN_0052f9d0(this,0x1fb8,0,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fb9,0x71,0x8f,s_VERDANA7_fnt_00563ec8,&DAT_005650b0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fb9,0);
    FUN_0052f9d0(this,0x1fb9,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fba,0x71,0x9a,s_VERDANA7_fnt_00563ec8,&DAT_005650bc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fba,0);
    FUN_0052f9d0(this,0x1fba,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fbb,0x71,0xa5,s_VERDANA7_fnt_00563ec8,&DAT_005650ac);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fbb,0);
    FUN_0052f9d0(this,0x1fbb,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fbc,0xbb,0x8f,s_VERDANA7_fnt_00563ec8,&DAT_005650b8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fbc,0);
    FUN_0052f9d0(this,0x1fbc,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fbd,0xbb,0x9a,s_VERDANA7_fnt_00563ec8,&DAT_005650b8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fbd,0);
    FUN_0052f9d0(this,0x1fbd,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fbe,0xbb,0xa5,s_VERDANA7_fnt_00563ec8,&DAT_005650b4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fbe,0xff);
    FUN_0052f9d0(this,0x1fbe,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fbf,0x32,0xa5,s_VERDANA7_fnt_00563ec8,DAT_00582b14);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fbf,0);
    FUN_0052f9d0(this,0x1fbf,0,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fc0,0x32,0x6d,s_VERDANA10_fnt_00563e64,DAT_00580c98);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fc0,0);
    FUN_0052f9d0(this,0x1fc0,0,0x69,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fc1,0x32,0xc1,s_VERDANA10_fnt_00563e64,DAT_00580b0c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fc1,0);
    FUN_0052f9d0(this,0x1fc1,0,0xa0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fc2,0x34,0xd3,s_VERDANA8_fnt_00563e98,DAT_00580fe8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fc2,0);
    FUN_0052f9d0(this,0x1fc2,2,0xaa,0,0);
  }
  iVar1 = UI_CreateSlider(this,0x1fc3,0x3e,0xe7,0xa0,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xf700;
    local_4 = 0;
    FUN_0052fcc0(this,0x1fc3,&local_10);
  }
  iVar1 = FUN_0052f850(this,0x1fc4,0x33,0xf2,s_VERDANA7_fnt_00563ec8,DAT_00580b60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fc4,0);
    FUN_0052f9d0(this,0x1fc4,0,0x8c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fc5,0xaf,0xf2,s_VERDANA7_fnt_00563ec8,s___20__00565640);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fc5,0);
    FUN_0052f9d0(this,0x1fc5,1,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fc6,0x33,0xfd,s_VERDANA7_fnt_00563ec8,DAT_005828cc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fc6,0);
    FUN_0052f9d0(this,0x1fc6,0,0xa0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fc7,0xcd,0xfd,s_VERDANA7_fnt_00563ec8,&DAT_0056563c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fc7,0);
    FUN_0052f9d0(this,0x1fc7,1,0x14,0,0);
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
  FUN_00531850(this,0x1fd4,0xb7,0x117,s_PLAYLOG_8_01_02_spr_00564744);
  return this;
}

