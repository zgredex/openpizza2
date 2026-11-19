// rea decompile_all
// name: FUN_0044d8c0
// address: 0x44d8c0
// body: available
// range: 0x44d8c0-0x44e387 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_0044d8c0(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004bb0c0);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  iVar1 = FUN_0052f850(this,0x44f,0x2b,5,s_TIMESFONT_fnt_00563ea8,DAT_00580e28);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x44f,0);
    FUN_0052f9d0(this,0x44f,2,0xbe,0,0);
  }
  FUN_0052f5b0(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  iVar1 = FUN_0052fc00(this,0x1fa8,0x3e,0x3c,0xa0,s_SC_00_spr_00564324,1,0);
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
  iVar1 = FUN_0052f850(this,0x1fb7,0x31,0x90,s_VERDANA10_fnt_00563e64,DAT_00581ddc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fb7,0);
    FUN_0052f9d0(this,0x1fb7,0,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fbc,0x78,0x90,s_VERDANA10_fnt_00563e64,s__Filialname_005644d4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fbc,0);
    FUN_0052f9d0(this,0x1fbc,1,0x6e,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fc0,0x32,0x69,s_VERDANA10_fnt_00563e64,DAT_005825f4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fc0,0);
    FUN_0052f9d0(this,0x1fc0,0,0x69,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fd4,0x32,0xc1,s_VERDANA10_fnt_00563e64,DAT_00581350);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fd4,0);
    FUN_0052f9d0(this,0x1fd4,0,0x69,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fd5,0x32,0xde,s_VERDANA10_fnt_00563e64,DAT_00580f3c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fd5,0);
    FUN_0052f9d0(this,0x1fd5,0,0x7d,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fd6,0x32,0x11f,s_VERDANA10_fnt_00563e64,DAT_00581abc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fd6,0);
    FUN_0052f9d0(this,0x1fd6,0,0x7d,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fd7,0x32,0x151,s_VERDANA10_fnt_00563e64,DAT_00582b14);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fd7,0);
    FUN_0052f9d0(this,0x1fd7,0,0x7d,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fd8,0x40,0xf1,s_VERDANA7_fnt_00563ec8,DAT_0058168c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fd8,0);
    FUN_0052f9d0(this,0x1fd8,0,0x6e,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fd9,0xb5,0xf1,s_VERDANA7_fnt_00563ec8,&DAT_005650bc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fd9,0);
    FUN_0052f9d0(this,0x1fd9,1,0x14,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fda,0xd1,0xf1,s_VERDANA7_fnt_00563ec8,&DAT_005650b8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fda,0);
    FUN_0052f9d0(this,0x1fda,1,0x14,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fdb,0x40,0xfe,s_VERDANA7_fnt_00563ec8,DAT_005827cc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fdb,0);
    FUN_0052f9d0(this,0x1fdb,0,0x6e,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fdc,0xb5,0xfe,s_VERDANA7_fnt_00563ec8,&DAT_005650bc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fdc,0);
    FUN_0052f9d0(this,0x1fdc,1,0x14,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fdd,0xd1,0xfe,s_VERDANA7_fnt_00563ec8,&DAT_005650b8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fdd,0);
    FUN_0052f9d0(this,0x1fdd,1,0x14,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fde,0x40,0x10b,s_VERDANA7_fnt_00563ec8,DAT_0058294c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fde,0);
    FUN_0052f9d0(this,0x1fde,0,0x6e,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fdf,0xb5,0x10b,s_VERDANA7_fnt_00563ec8,&DAT_005650bc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fdf,0);
    FUN_0052f9d0(this,0x1fdf,1,0x14,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fe0,0xd1,0x10b,s_VERDANA7_fnt_00563ec8,&DAT_005650b8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fe0,0);
    FUN_0052f9d0(this,0x1fe0,1,0x14,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fe1,0x40,0x131,s_VERDANA7_fnt_00563ec8,DAT_00581784);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fe1,0);
    FUN_0052f9d0(this,0x1fe1,0,0x6e,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fe2,0xb5,0x131,s_VERDANA7_fnt_00563ec8,&DAT_005650bc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fe2,0);
    FUN_0052f9d0(this,0x1fe2,1,0x14,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fe3,0xd1,0x131,s_VERDANA7_fnt_00563ec8,&DAT_005650b8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fe3,0);
    FUN_0052f9d0(this,0x1fe3,1,0x14,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fe4,0x40,0x13e,s_VERDANA7_fnt_00563ec8,DAT_005818c4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fe4,0);
    FUN_0052f9d0(this,0x1fe4,0,0x6e,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fe5,0xb5,0x13e,s_VERDANA7_fnt_00563ec8,&DAT_005650bc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fe5,0);
    FUN_0052f9d0(this,0x1fe5,1,0x14,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fe6,0xd1,0x13e,s_VERDANA7_fnt_00563ec8,&DAT_005650b8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fe6,0);
    FUN_0052f9d0(this,0x1fe6,1,0x14,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fe7,0x40,0x164,s_VERDANA7_fnt_00563ec8,DAT_00581018);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fe7,0);
    FUN_0052f9d0(this,0x1fe7,0,0x78,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fe8,0xb5,0x164,s_VERDANA7_fnt_00563ec8,&DAT_005650bc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fe8,0);
    FUN_0052f9d0(this,0x1fe8,1,0x14,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fe9,0xd1,0x164,s_VERDANA7_fnt_00563ec8,&DAT_005650b8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fe9,0);
    FUN_0052f9d0(this,0x1fe9,1,0x14,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fea,0x8d,0xc3,s_VERDANA7_fnt_00563ec8,DAT_00580e74);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fea,0);
    FUN_0052f9d0(this,0x1fea,1,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1feb,0xc5,0xc3,s_VERDANA7_fnt_00563ec8,DAT_00582acc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1feb,0);
    FUN_0052f9d0(this,0x1feb,1,0x1e,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fec,0x31,0xa0,s_VERDANA10_fnt_00563e64,DAT_00580bd0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fec,0);
    FUN_0052f9d0(this,0x1fec,0,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fed,0x6f,0xa0,s_VERDANA10_fnt_00563e64,&DAT_0056650c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fed,0);
    FUN_0052f9d0(this,0x1fed,1,0x78,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fee,0x31,0x80,s_VERDANA10_fnt_00563e64,DAT_005823dc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fee,0);
    FUN_0052f9d0(this,0x1fee,0,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fef,99,0x80,s_VERDANA10_fnt_00563e64,s__Gesundheitsamt_005664fc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fef,0);
    FUN_0052f9d0(this,0x1fef,1,0x82,0,0);
  }
  return this;
}

