// rea decompile_all
// name: SubMenu_BuildSupplierInfo
// address: 0x45ebd0
// body: available
// range: 0x45ebd0-0x4602c7 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl SubMenu_BuildSupplierInfo(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
                    /* Builds the supplier information page. */
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004c29b0);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  FUN_00531850(this,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x454,0x27,0x130,s_VERDANA7_fnt_00563ec8,DAT_00580bec);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x454,0);
    FUN_0052f9d0(this,0x454,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x455,0x58,0x130,s_VERDANA7_fnt_00563ec8,DAT_005816d4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x455,0);
    FUN_0052f9d0(this,0x455,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x456,0x8a,0x130,s_VERDANA7_fnt_00563ec8,DAT_00582974);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x456,0);
    FUN_0052f9d0(this,0x456,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x457,0xbc,0x130,s_VERDANA7_fnt_00563ec8,DAT_0058234c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x457,0);
    FUN_0052f9d0(this,0x457,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x458,0x27,0x154,s_VERDANA7_fnt_00563ec8,DAT_00580e64);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x458,0);
    FUN_0052f9d0(this,0x458,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x459,0x58,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582e08);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x459,0);
    FUN_0052f9d0(this,0x459,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x45a,0x89,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582770);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x45a,0);
    FUN_0052f9d0(this,0x45a,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x45b,0xba,0x154,s_VERDANA7_fnt_00563ec8,DAT_005810a4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x45b,0);
    FUN_0052f9d0(this,0x45b,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x523,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00581c98);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x523,0);
    FUN_0052f9d0(this,0x523,2,0xbe,0,0);
  }
  FUN_00531850(this,0x53a,0x27,0xb6,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x548,0x4b,0x3a,s_VERDANA8_fnt_00563e98,DAT_00582a18);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x548,0);
    FUN_0052f9d0(this,0x548,2,0x78,0,0);
  }
  iVar1 = UI_CreateSlider(this,0x549,0x47,0x4d,0x8c,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xaa00;
    local_4 = 0;
    FUN_0052fcc0(this,0x549,&local_10);
  }
  iVar1 = FUN_0052f850(this,0x54a,0x4b,0x57,s_VERDANA8_fnt_00563e98,DAT_00582a28);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x54a,0);
    FUN_0052f9d0(this,0x54a,2,0x78,0,0);
  }
  iVar1 = UI_CreateSlider(this,0x54b,0x47,0x6a,0x8c,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xaa00;
    local_4 = 0;
    FUN_0052fcc0(this,0x54b,&local_10);
  }
  iVar1 = FUN_0052f850(this,0x54c,0x4b,0x76,s_VERDANA8_fnt_00563e98,DAT_0058298c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x54c,0);
    FUN_0052f9d0(this,0x54c,2,0x78,0,0);
  }
  iVar1 = UI_CreateSlider(this,0x54d,0x47,0x89,0x8c,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xaa00;
    local_4 = 0;
    FUN_0052fcc0(this,0x54d,&local_10);
  }
  iVar1 = FUN_0052f850(this,0x54e,0x4c,0x95,s_VERDANA8_fnt_00563e98,DAT_00581580);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x54e,0);
    FUN_0052f9d0(this,0x54e,2,0x78,0,0);
  }
  iVar1 = UI_CreateSlider(this,0x54f,0x47,0xa8,0x8c,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xaa00;
    local_c = 0xffff;
    local_8 = 0xff;
    local_4 = 0;
    FUN_0052fcc0(this,0x54f,&local_10);
  }
  iVar1 = FUN_0052f850(this,0x550,0x2c,0xbf,s_VERDANA10_fnt_00563e64,DAT_00580b10);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x550,0);
    FUN_0052f9d0(this,0x550,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x551,0x2d,0xd5,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x551,0xff);
    FUN_0052f9d0(this,0x551,0,0x8c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x552,0xb8,0xd5,s_VERDANA8_fnt_00563e98,&DAT_00566908);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x552,0);
    FUN_0052f9d0(this,0x552,1,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x553,0x2d,0xe2,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x553,0xff0000);
    FUN_0052f9d0(this,0x553,0,0x8c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x554,0xb8,0xe2,s_VERDANA8_fnt_00563e98,&DAT_00566908);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x554,0);
    FUN_0052f9d0(this,0x554,1,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x557,0x2e,0xef,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x557,0x8c8c);
    FUN_0052f9d0(this,0x557,0,0x8c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x558,0xb9,0xef,s_VERDANA8_fnt_00563e98,&DAT_00566908);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x558,0);
    FUN_0052f9d0(this,0x558,1,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x559,0x2e,0xfc,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x559,0xbe00);
    FUN_0052f9d0(this,0x559,0,0x8c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x55a,0xb9,0xfc,s_VERDANA8_fnt_00563e98,&DAT_00566908);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x55a,0);
    FUN_0052f9d0(this,0x55a,1,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x55b,0x2e,0x109,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x55b,0xff00ff);
    FUN_0052f9d0(this,0x55b,0,0x8c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x55c,0xb9,0x109,s_VERDANA8_fnt_00563e98,&DAT_00566908);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x55c,0);
    FUN_0052f9d0(this,0x55c,1,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x55d,0x2e,0x116,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x55d,0xd2d200);
    FUN_0052f9d0(this,0x55d,0,0x8c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x55e,0xb9,0x116,s_VERDANA8_fnt_00563e98,&DAT_00566908);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x55e,0);
    FUN_0052f9d0(this,0x55e,1,0x32,0,0);
  }
  FUN_0052f5b0(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  FUN_00531850(this,9000,99,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x2329,99,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x232a,99,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x232b,99,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x232c,99,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x232d,99,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x232e,99,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x232f,99,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x2330,99,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x2331,99,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x2332,99,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x2333,99,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x2334,99,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x2335,99,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x2336,99,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x2337,99,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x2338,99,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x234a,199,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x234b,199,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x2339,0x95,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x233a,0x95,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x233b,0x95,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x233c,0x95,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x233d,0x95,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x233e,0x95,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x233f,0x95,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x2340,0x95,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x2341,0x95,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x2342,0x95,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x2343,0x95,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x2344,0x95,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x2345,0x95,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x2346,0x95,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x2347,0x95,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x2348,0x95,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x2349,0x95,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x234c,199,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x234d,199,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x234e,199,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x234f,199,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x2350,199,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x2351,199,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x2352,199,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x2353,199,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x2354,199,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x2355,199,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x2356,199,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x2357,199,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x2358,199,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x2359,199,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x235a,199,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x239f,0x31,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x23a0,0x31,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x23a1,0x31,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x23a2,0x31,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x23a3,0x31,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x23a4,0x31,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x23a5,0x31,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x23a6,0x31,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x23a7,0x31,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x23a8,0x31,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x23a9,0x31,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x23aa,0x31,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x23ab,0x31,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x23ac,0x31,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x23ad,0x31,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x23ae,0x31,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x23af,0x31,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x235b,0x31,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x235c,0x31,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x235d,0x31,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x235e,0x31,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x235f,0x31,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x2360,0x31,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x2361,0x31,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x2362,0x31,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x2363,0x31,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x2364,0x31,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x2365,0x31,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x2366,0x31,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x2367,0x31,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x2368,0x31,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x2369,0x31,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x236a,0x31,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x236b,0x31,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x236c,99,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x236d,99,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x236e,99,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x236f,99,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x2370,99,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x2371,99,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x2372,99,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x2373,99,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x2374,99,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x2375,99,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x2376,99,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x2377,99,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x2378,99,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x2379,99,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x237a,99,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x237b,99,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x237c,99,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x237d,0x95,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x237e,0x95,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x237f,0x95,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x2380,0x95,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x2381,0x95,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x2382,0x95,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x2383,0x95,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x2384,0x95,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x2385,0x95,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x2386,0x95,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x2387,0x95,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x2388,0x95,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x2389,0x95,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x238a,0x95,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x238b,0x95,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x238c,0x95,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x238d,0x95,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x238e,199,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x238f,199,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x2390,199,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x2391,199,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x2392,199,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x2393,199,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x2394,199,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x2395,199,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x2396,199,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x2397,199,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x2398,199,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x2399,199,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x239a,199,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x239b,199,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x239c,199,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x239d,199,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x239e,199,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_0052f5b0(this,0x23b2,0x2c,0x22,s_PB22_00_spr_00564174,0,0);
  iVar1 = UI_AddTextButton(this,0x23b3,0x40,0x23,s_VERDANA8_fnt_00563e98,s__Exlusiv_Import_005668f8,
                           0,s_TEXTPB05__00_spr_00564160);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x23b3,0,0,0);
    FUN_0052f7a0(this,0x23b3,2,0x93,0,0,0xfffe);
  }
  FUN_0052f5b0(this,0x23b4,0xcd,0x22,s_PB24_00_spr_00564144,0,0);
  return this;
}

