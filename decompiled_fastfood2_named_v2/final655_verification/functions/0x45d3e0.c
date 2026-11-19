// rea decompile_all
// name: Screen_Warehouse
// address: 0x45d3e0
// body: available
// range: 0x45d3e0-0x45ebc9 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl Screen_Warehouse(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
                    /* Builds the city warehouse screen. */
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004c20c0);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  iVar1 = FUN_0052f850(this,0x42d,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00582030);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x42d,0);
    FUN_0052f9d0(this,0x42d,2,0xbe,0,0);
  }
  iVar1 = FUN_0052f850(this,0x432,0x2f,0x23,s_VERDANA8_fnt_00563e98,DAT_005827ec);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x432,0);
    FUN_0052f9d0(this,0x432,0,0xa0,0,0);
  }
  FUN_00531850(this,0x433,0x2e,0x30,s_RAHMEN05_spr_005668d0);
  iVar1 = UI_CreateSlider(this,0x435,0xdd,0x39,0x91,s_SL01_00_spr_0056448c,0,1);
  if (iVar1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    FUN_0052fcc0(this,0x435,&local_10);
  }
  FUN_0052f5b0(this,0x436,0x30,0x32,s_PB14_00_spr_005642c4,1,0);
  FUN_0052f5b0(this,0x437,0x30,0x45,s_PB14_00_spr_005642c4,1,0);
  FUN_0052f5b0(this,0x438,0x30,0x58,s_PB14_00_spr_005642c4,1,0);
  FUN_0052f5b0(this,0x439,0x30,0x6b,s_PB14_00_spr_005642c4,1,0);
  FUN_0052f5b0(this,0x43a,0x30,0x7e,s_PB14_00_spr_005642c4,1,0);
  FUN_0052f5b0(this,0x43b,0x30,0x91,s_PB14_00_spr_005642c4,1,0);
  FUN_0052f5b0(this,0x43c,0x30,0xa4,s_PB14_00_spr_005642c4,1,0);
  FUN_0052f5b0(this,0x43d,0x30,0xb7,s_PB14_00_spr_005642c4,1,0);
  iVar1 = FUN_0052f850(this,0x4b0,0x48,0x37,s_VERDANA7_fnt_00563ec8,s__Filialname_005644d4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4b0,0);
    FUN_0052f9d0(this,0x4b0,0,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x514,0xa1,0x37,s_VERDANA7_fnt_00563ec8,s__100__0056683c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x514,0);
    FUN_0052f9d0(this,0x514,1,0x2d,0,0);
  }
  iVar1 = FUN_0052f850(this,0x515,0xa1,0x4a,s_VERDANA7_fnt_00563ec8,s__100__0056683c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x515,0);
    FUN_0052f9d0(this,0x515,1,0x2d,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4b1,0x48,0x4a,s_VERDANA7_fnt_00563ec8,s__Filialname_005644d4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4b1,0);
    FUN_0052f9d0(this,0x4b1,0,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4b2,0x48,0x5d,s_VERDANA7_fnt_00563ec8,s__Filialname_005644d4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4b2,0);
    FUN_0052f9d0(this,0x4b2,0,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x516,0xa1,0x5d,s_VERDANA7_fnt_00563ec8,s__100__0056683c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x516,0);
    FUN_0052f9d0(this,0x516,1,0x2d,0,0);
  }
  iVar1 = FUN_0052f850(this,0x517,0xa1,0x70,s_VERDANA7_fnt_00563ec8,s__100__0056683c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x517,0);
    FUN_0052f9d0(this,0x517,1,0x2d,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4b3,0x48,0x70,s_VERDANA7_fnt_00563ec8,s__Filialname_005644d4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4b3,0);
    FUN_0052f9d0(this,0x4b3,0,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4b6,0x48,0xa9,s_VERDANA7_fnt_00563ec8,s__Filialname_005644d4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4b6,0);
    FUN_0052f9d0(this,0x4b6,0,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x51a,0xa1,0xa9,s_VERDANA7_fnt_00563ec8,s__100__0056683c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x51a,0);
    FUN_0052f9d0(this,0x51a,1,0x2d,0,0);
  }
  iVar1 = FUN_0052f850(this,0x51b,0xa1,0xbc,s_VERDANA7_fnt_00563ec8,s__100__0056683c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x51b,0);
    FUN_0052f9d0(this,0x51b,1,0x2d,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4b7,0x48,0xbc,s_VERDANA7_fnt_00563ec8,s__Filialname_005644d4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4b7,0);
    FUN_0052f9d0(this,0x4b7,0,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4b5,0x48,0x96,s_VERDANA7_fnt_00563ec8,s__Filialname_005644d4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4b5,0);
    FUN_0052f9d0(this,0x4b5,0,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x519,0xa1,0x96,s_VERDANA7_fnt_00563ec8,s__100__0056683c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x519,0);
    FUN_0052f9d0(this,0x519,1,0x2d,0,0);
  }
  iVar1 = FUN_0052f850(this,0x518,0xa1,0x83,s_VERDANA7_fnt_00563ec8,s__100__0056683c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x518,0);
    FUN_0052f9d0(this,0x518,1,0x2d,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4b4,0x48,0x83,s_VERDANA7_fnt_00563ec8,s__Filialname_005644d4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4b4,0);
    FUN_0052f9d0(this,0x4b4,0,0x5a,0,0);
  }
  FUN_0052f5b0(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  FUN_00531850(this,0x1f41,99,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x1f42,99,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x1f43,99,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x1f44,99,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x1f45,99,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x1f46,99,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x1f47,99,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x1f48,99,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x1f49,99,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x1f4a,99,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x1f4b,99,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x1f4c,99,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x1f4d,99,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x1f4e,99,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x1f4f,99,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x1f50,99,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x1f51,99,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x1f52,0x95,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x1f53,0x95,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x1f54,0x95,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x1f55,0x95,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x1f56,0x95,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x1f57,0x95,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x1f58,0x95,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x1f59,0x95,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x1f5a,0x95,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x1f5b,0x95,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x1f5c,0x95,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x1f5d,0x95,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x1f5e,0x95,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x1f5f,0x95,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x1f60,0x95,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x1f61,0x95,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x1f62,0x95,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x1f63,199,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x1f64,199,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x1f65,199,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x1f66,199,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x1f67,199,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x1f68,199,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x1f69,199,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x1f6a,199,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x1f6b,199,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x1f6c,199,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x1f6d,199,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x1f6e,199,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x1f6f,199,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x1f70,199,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x1f71,199,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x1f72,199,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x1f73,199,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x1f74,0x31,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x1f75,0x31,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x1f76,0x31,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x1f77,0x31,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x1f78,0x31,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x1f79,0x31,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x1f7a,0x31,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x1f7b,0x31,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x1f7c,0x31,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x1f7d,0x31,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x1f7e,0x31,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x1f7f,0x31,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x1f80,0x31,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x1f81,0x31,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x1f82,0x31,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x1f83,0x31,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x1f84,0x31,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x1f85,99,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x1f86,99,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x1f87,99,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x1f88,99,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x1f89,99,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x1f8a,99,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x1f8b,99,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x1f8c,99,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x1f8d,99,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x1f8e,99,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x1f8f,99,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x1f90,99,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x1f91,99,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x1f92,99,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x1f93,99,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x1f94,99,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x1f95,99,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x1f96,0x95,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x1f97,0x95,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x1f98,0x95,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x1f99,0x95,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x1f9a,0x95,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x1f9b,0x95,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x1f9c,0x95,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x1f9d,0x95,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x1f9e,0x95,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x1f9f,0x95,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x1fa0,0x95,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x1fa1,0x95,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x1fa2,0x95,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x1fa3,0x95,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x1fa4,0x95,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x1fa5,0x95,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x1fa6,0x95,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x1fa7,199,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x1fa8,199,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x1fa9,199,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x1faa,199,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x1fab,199,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x1fac,199,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x1fad,199,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x1fae,199,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x1faf,199,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x1fb0,199,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x1fb1,199,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x1fb2,199,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x1fb3,199,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x1fb4,199,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x1fb5,199,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x1fb6,199,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x1fb7,199,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x1fb8,0x31,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x1fb9,0x31,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x1fba,0x31,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x1fbb,0x31,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x1fbc,0x31,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x1fbd,0x31,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x1fbe,0x31,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x1fbf,0x31,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x1fc0,0x31,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x1fc1,0x31,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x1fc2,0x31,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x1fc3,0x31,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x1fc4,0x31,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x1fc5,0x31,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x1fc6,0x31,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x1fc7,0x31,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x1fc8,0x31,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x1fc9,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x1fca,0x27,0x130,s_VERDANA7_fnt_00563ec8,DAT_00580bec);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fca,0);
    FUN_0052f9d0(this,0x1fca,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fcb,0x58,0x130,s_VERDANA7_fnt_00563ec8,DAT_005816d4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fcb,0);
    FUN_0052f9d0(this,0x1fcb,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fcc,0x8a,0x130,s_VERDANA7_fnt_00563ec8,DAT_00582974);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fcc,0);
    FUN_0052f9d0(this,0x1fcc,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fcd,0xbc,0x130,s_VERDANA7_fnt_00563ec8,DAT_0058234c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fcd,0);
    FUN_0052f9d0(this,0x1fcd,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fce,0x27,0x154,s_VERDANA7_fnt_00563ec8,DAT_00580e64);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fce,0);
    FUN_0052f9d0(this,0x1fce,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fcf,0x58,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582e08);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fcf,0);
    FUN_0052f9d0(this,0x1fcf,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fd0,0x89,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582770);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fd0,0);
    FUN_0052f9d0(this,0x1fd0,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fd1,0xba,0x154,s_VERDANA7_fnt_00563ec8,DAT_005810a4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fd1,0);
    FUN_0052f9d0(this,0x1fd1,2,0x32,0,0);
  }
  FUN_00531850(this,0x1feb,0x27,0xf2,s_TRENNZEILE_spr_00563eb8);
  FUN_0052f5b0(this,0x1fec,0x2c,0xf9,s_PB22_00_spr_00564174,0,0);
  iVar1 = UI_AddTextButton(this,0x1fed,0x40,0xfa,s_VERDANA8_fnt_00563e98,s__Lagername_00566880,0,
                           s_TEXTPB05__00_spr_00564160);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x1fed,0,0,0);
    FUN_0052f7a0(this,0x1fed,2,0x93,0,0,0xfffe);
  }
  FUN_0052f5b0(this,0x1fee,0xcd,0xf9,s_PB24_00_spr_00564144,0,0);
  iVar1 = FUN_0052f850(this,0x1fef,0x2e,0x117,s_VERDANA7_fnt_00563ec8,DAT_005828c4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1fef,0);
    FUN_0052f9d0(this,0x1fef,0,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1ff0,0x49,0x117,s_VERDANA7_fnt_00563ec8,s__1_000_00__00566874);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1ff0,0);
    FUN_0052f9d0(this,0x1ff0,1,0x46,0,0);
  }
  iVar1 = UI_AddTextButton(this,0x1ff1,0x8e,0x112,s_VERDANA8_fnt_00563e98,DAT_00581f44,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x1ff1,0,0,0);
    FUN_0052f7a0(this,0x1ff1,2,0x54,0,0,0xfffe);
  }
  FUN_0052f5b0(this,0x2004,0x30,0xd5,s_PB05x__00_spr_00564630,1,0);
  FUN_0052f5b0(this,0x2005,0x86,0xd5,s_PB05x__00_spr_00564630,1,0);
  iVar1 = FUN_0052f850(this,0x2006,0x49,0xd9,s_VERDANA7_fnt_00563ec8,DAT_00580ae0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x2006,0);
    FUN_0052f9d0(this,0x2006,0,0x41,0,0);
  }
  iVar1 = FUN_0052f850(this,0x2007,0x9f,0xd9,s_VERDANA7_fnt_00563ec8,DAT_0058109c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x2007,0);
    FUN_0052f9d0(this,0x2007,0,0x4b,0,0);
  }
  return this;
}

