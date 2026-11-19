// rea decompile_all
// name: SubMenu_CreatePolicePage
// address: 0x468090
// body: available
// range: 0x468090-0x468bc2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl SubMenu_CreatePolicePage(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
                    /* Builds the police submenu page. */
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,SubMenu_Police_HandleControl)
  ;
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  iVar1 = FUN_0052f850(this,0x44f,0x2b,5,s_TIMESFONT_fnt_00563ea8,DAT_00582ae0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x44f,0);
    FUN_0052f9d0(this,0x44f,2,0xbe,0,0);
  }
  FUN_0052f5b0(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  FUN_00531850(this,0x1fab,0x54,0x7a,s_POLIZEIHAUSLOCH_spr_00565704);
  FUN_00531850(this,0x1fac,0x55,0x7b,s_POLIZEIHAUSGRUEN_spr_005656ec);
  FUN_00531850(this,0x1fad,0x55,0x7b,s_POLIZEIHAUSROT_spr_005656d8);
  iVar1 = FUN_0052f850(this,0x1fb1,0x32,0x67,s_VERDANA10_fnt_00563e64,DAT_00581d2c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fb1,0);
    FUN_0052f9d0(this,0x1fb1,0,0x96,0,0);
  }
  FUN_00531850(this,0x1fb2,0x27,0x12a,s_TRENNZEILE_spr_00563eb8);
  FUN_00531850(this,0x1fb3,0x27,0x5c,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x1fb4,0x31,0x132,s_VERDANA10_fnt_00563e64,DAT_00581240);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fb4,0);
    FUN_0052f9d0(this,0x1fb4,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fb5,0x31,0x143,s_VERDANA8_fnt_00563e98,DAT_00580be0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fb5,0);
    FUN_0052f9d0(this,0x1fb5,0,0x9b,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fb6,0x31,0x150,s_VERDANA8_fnt_00563e98,DAT_00581014);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fb6,0);
    FUN_0052f9d0(this,0x1fb6,0,0x9b,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fb8,0x97,0x143,s_VERDANA8_fnt_00563e98,&DAT_0056508c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fb8,0);
    FUN_0052f9d0(this,0x1fb8,1,0x50,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fb9,0x97,0x150,s_VERDANA8_fnt_00563e98,&DAT_005656d4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fb9,0);
    FUN_0052f9d0(this,0x1fb9,1,0x50,0,0);
  }
  FUN_00531850(this,0x1fbc,0x32,0xd0,s_PISTOLE_spr_005656c8);
  FUN_00531850(this,0x1fbd,0x72,0xd0,s_SNIPER_spr_005656bc);
  FUN_00531850(this,0x1fbe,0x7a,0x7a,s_POLIZEIHAUSLOCH_spr_00565704);
  FUN_00531850(this,0x1fbf,0x7b,0x7b,s_POLIZEIHAUSGRUEN_spr_005656ec);
  FUN_00531850(this,0x1fc0,0x7b,0x7b,s_POLIZEIHAUSROT_spr_005656d8);
  FUN_00531850(this,0x1fc1,0xa0,0x7a,s_POLIZEIHAUSLOCH_spr_00565704);
  FUN_00531850(this,0x1fc2,0xa1,0x7b,s_POLIZEIHAUSGRUEN_spr_005656ec);
  FUN_00531850(this,0x1fc3,0xa1,0x7b,s_POLIZEIHAUSROT_spr_005656d8);
  FUN_00531850(this,0x1fc4,0xc6,0x7a,s_POLIZEIHAUSLOCH_spr_00565704);
  FUN_00531850(this,0x1fc5,199,0x7b,s_POLIZEIHAUSGRUEN_spr_005656ec);
  FUN_00531850(this,0x1fc6,199,0x7b,s_POLIZEIHAUSROT_spr_005656d8);
  FUN_00531850(this,0x1fc7,0x2e,0x7a,s_POLIZEIHAUSLOCH_spr_00565704);
  FUN_00531850(this,0x1fc8,0x2f,0x7b,s_POLIZEIHAUSGRUEN_spr_005656ec);
  FUN_00531850(this,0x1fc9,0x2f,0x7b,s_POLIZEIHAUSROT_spr_005656d8);
  FUN_00531850(this,0x1fca,0x29,0xaa,s_POLIZISTLOCH_spr_005656a8);
  FUN_00531850(this,0x1fcb,0x2b,0xac,s_POLIZIST_spr_00565698);
  iVar1 = FUN_0052f850(this,0x1fcc,0x31,0x97,s_VERDANA10_fnt_00563e64,DAT_00580fb8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fcc,0);
    FUN_0052f9d0(this,0x1fcc,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fcf,0x35,0xe4,s_VERDANA8_fnt_00563e98,&DAT_00565690);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fcf,0);
    FUN_0052f9d0(this,0x1fcf,2,0x2d,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fd0,0xb4,0xe3,s_VERDANA8_fnt_00563e98,&DAT_00565690);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fd0,0);
    FUN_0052f9d0(this,0x1fd0,2,0x2d,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fd1,0x73,0xe4,s_VERDANA8_fnt_00563e98,&DAT_00565690);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fd1,0);
    FUN_0052f9d0(this,0x1fd1,2,0x2d,0,0);
  }
  FUN_00531850(this,0x1fd2,0x3c,0xaa,s_POLIZISTLOCH_spr_005656a8);
  FUN_00531850(this,0x1fd3,0x3e,0xac,s_POLIZIST_spr_00565698);
  FUN_00531850(this,0x1fd4,0x4f,0xaa,s_POLIZISTLOCH_spr_005656a8);
  FUN_00531850(this,0x1fd5,0x51,0xac,s_POLIZIST_spr_00565698);
  FUN_00531850(this,0x1fd6,0x62,0xaa,s_POLIZISTLOCH_spr_005656a8);
  FUN_00531850(this,0x1fd7,100,0xac,s_POLIZIST_spr_00565698);
  FUN_00531850(this,0x1fd8,0x75,0xaa,s_POLIZISTLOCH_spr_005656a8);
  FUN_00531850(this,0x1fd9,0x77,0xac,s_POLIZIST_spr_00565698);
  FUN_00531850(this,0x1fda,0x88,0xaa,s_POLIZISTLOCH_spr_005656a8);
  FUN_00531850(this,0x1fdb,0x8a,0xac,s_POLIZIST_spr_00565698);
  FUN_00531850(this,0x1fdc,0x9b,0xaa,s_POLIZISTLOCH_spr_005656a8);
  FUN_00531850(this,0x1fdd,0x9d,0xac,s_POLIZIST_spr_00565698);
  FUN_00531850(this,0x1fde,0xae,0xaa,s_POLIZISTLOCH_spr_005656a8);
  FUN_00531850(this,0x1fdf,0xb0,0xac,s_POLIZIST_spr_00565698);
  FUN_00531850(this,0x1fe0,0xc1,0xaa,s_POLIZISTLOCH_spr_005656a8);
  FUN_00531850(this,0x1fe1,0xc3,0xac,s_POLIZIST_spr_00565698);
  FUN_00531850(this,0x1fe2,0xd4,0xaa,s_POLIZISTLOCH_spr_005656a8);
  FUN_00531850(this,0x1fe3,0xd6,0xac,s_POLIZIST_spr_00565698);
  FUN_00531850(this,0x1fe4,0xb4,0xd0,s_UZI_spr_00565688);
  iVar1 = UI_CreateSlider(this,0x1fe5,0x3e,0x3c,0xa0,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xf700;
    local_4 = 0;
    FUN_0052fcc0(this,0x1fe5,&local_10);
  }
  iVar1 = FUN_0052f850(this,0x1fe6,0x34,0x28,s_VERDANA8_fnt_00563e98,DAT_00580af4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fe6,0);
    FUN_0052f9d0(this,0x1fe6,2,0xaa,0,0);
  }
  FUN_00531850(this,0x1fe7,0x27,0xf2,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x1fe8,0x31,0x49,s_VERDANA8_fnt_00563e98,DAT_0058180c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fe8,0);
    FUN_0052f9d0(this,0x1fe8,0,0x8c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fe9,0xaf,0x49,s_VERDANA8_fnt_00563e98,&DAT_00565650);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fe9,0);
    FUN_0052f9d0(this,0x1fe9,1,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fec,0x32,0xf9,s_VERDANA8_fnt_00563e98,DAT_00582050);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fec,0);
    FUN_0052f9d0(this,0x1fec,0,0x78,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fed,0x92,0xf9,s_VERDANA8_fnt_00563e98,s__500000__00564254);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fed,0);
    FUN_0052f9d0(this,0x1fed,1,0x55,0,0);
  }
  iVar1 = UI_AddTextButton(this,0x1fee,0x30,0x107,s_VERDANA8_fnt_00563e98,s___5000___00566acc,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x1fee,0,0,0);
    FUN_0052f7a0(this,0x1fee,2,0x54,0,0,0xfffe);
  }
  iVar1 = UI_AddTextButton(this,0x1fef,0x8e,0x107,s_VERDANA8_fnt_00563e98,s___5000___00566acc,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x1fef,0,0,0);
    FUN_0052f7a0(this,0x1fef,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f850(this,0x1ff0,0x31,0x11d,s_VERDANA7_fnt_00563ec8,DAT_00581140);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1ff0,0);
    FUN_0052f9d0(this,0x1ff0,0,0x82,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1ff1,0x91,0x11d,s_VERDANA7_fnt_00563ec8,s__500000___00565670);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1ff1,0);
    FUN_0052f9d0(this,0x1ff1,1,0x55,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1ff2,0x31,0x15d,s_VERDANA8_fnt_00563e98,DAT_00582a1c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1ff2,0);
    FUN_0052f9d0(this,0x1ff2,0,0x9b,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1ff3,0x31,0x16a,s_VERDANA8_fnt_00563e98,DAT_00581ed0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1ff3,0);
    FUN_0052f9d0(this,0x1ff3,0,0x9b,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1ff4,0x97,0x15d,s_VERDANA8_fnt_00563e98,&DAT_0056508c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1ff4,0);
    FUN_0052f9d0(this,0x1ff4,1,0x50,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1ff5,0x97,0x16a,s_VERDANA8_fnt_00563e98,&DAT_005656d4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1ff5,0);
    FUN_0052f9d0(this,0x1ff5,1,0x50,0,0);
  }
  return this;
}

