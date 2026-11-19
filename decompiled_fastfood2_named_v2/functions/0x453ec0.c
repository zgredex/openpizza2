// rea decompile_all
// name: FUN_00453ec0
// address: 0x453ec0
// body: available
// range: 0x453ec0-0x454ed6 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_00453ec0(int *param_1)

{
  int iVar1;
  void *this;
  
  iVar1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004bde20);
  *param_1 = iVar1;
  this = (void *)UI_FindWindowByID(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(this,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  iVar1 = UI_AddText(this,0x501,0x2b,5,s_TIMESFONT_fnt_00563ea8,DAT_00582be0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x501,0);
    FUN_0052f9d0(this,0x501,2,0xbe,0,0);
  }
  iVar1 = UI_AddText(this,0x515,0x7d,0x25,s_VERDANA8_fnt_00563e98,s__Carlos_Estarda_00564468);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x515,0);
    FUN_0052f9d0(this,0x515,0,0x6c,0,0);
  }
  UI_AddSprite(this,0x519,0x27,0xf3,s_TRENNZEILE_spr_00563eb8);
  iVar1 = UI_AddText(this,0x51a,0x30,0xfd,s_VERDANA8_fnt_00563e98,DAT_00582e50);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x51a,0);
    FUN_0052f9d0(this,0x51a,0,100,0,0);
  }
  iVar1 = UI_AddText(this,0x51b,0x30,0x116,s_VERDANA8_fnt_00563e98,s__Pizza_Tingeltangel_0056510c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x51b,0);
    FUN_0052f9d0(this,0x51b,0,0x87,0,0);
  }
  UI_AddSprite(this,0x51c,0xb5,0x104,s_LOGORAHMEN_00_spr_005650f8);
  FUN_00531c60(this,0x51f,0xb7,0x106,0x2c,0x1d,0x10);
  UI_AddImage(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  iVar1 = UI_AddText(this,0x2332,0x34,0x6b,s_VERDANA7_fnt_00563ec8,DAT_00581fa0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x2332,0);
    FUN_0052f9d0(this,0x2332,0,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x2333,0x9b,0x6b,s_VERDANA7_fnt_00563ec8,DAT_00582474);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x2333,0);
    FUN_0052f9d0(this,0x2333,0,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x2334,0x34,0x77,s_VERDANA7_fnt_00563ec8,DAT_00581070);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x2334,0);
    FUN_0052f9d0(this,0x2334,0,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x2335,0x9b,0x77,s_VERDANA7_fnt_00563ec8,DAT_00581138);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x2335,0);
    FUN_0052f9d0(this,0x2335,0,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x2336,0x34,0x83,s_VERDANA7_fnt_00563ec8,DAT_005826d0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x2336,0);
    FUN_0052f9d0(this,0x2336,0,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x2337,0x9b,0x83,s_VERDANA7_fnt_00563ec8,DAT_00582ebc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x2337,0);
    FUN_0052f9d0(this,0x2337,0,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x2348,0x62,0x6b,s_VERDANA7_fnt_00563ec8,&DAT_0056528c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x2348,0x6e00);
    FUN_0052f9d0(this,0x2348,1,0x1e,0,0);
  }
  iVar1 = UI_AddText(this,0x2349,200,0x6b,s_VERDANA7_fnt_00563ec8,&DAT_00565284);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x2349,0x6e00);
    FUN_0052f9d0(this,0x2349,1,0x1e,0,0);
  }
  iVar1 = UI_AddText(this,0x234a,0x62,0x77,s_VERDANA7_fnt_00563ec8,&DAT_00565288);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x234a,0xff);
    FUN_0052f9d0(this,0x234a,1,0x1e,0,0);
  }
  iVar1 = UI_AddText(this,0x234b,200,0x77,s_VERDANA7_fnt_00563ec8,&DAT_005650b8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x234b,0);
    FUN_0052f9d0(this,0x234b,1,0x1e,0,0);
  }
  iVar1 = UI_AddText(this,0x234c,0x62,0x83,s_VERDANA7_fnt_00563ec8,&DAT_005650b8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x234c,0);
    FUN_0052f9d0(this,0x234c,1,0x1e,0,0);
  }
  iVar1 = UI_AddText(this,0x234d,200,0x83,s_VERDANA7_fnt_00563ec8,&DAT_005650b8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x234d,0);
    FUN_0052f9d0(this,0x234d,1,0x1e,0,0);
  }
  UI_AddSprite(this,0x2355,0x27,0x93,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f690(this,0x2357,0x30,0x133,s_VERDANA8_fnt_00563e98,DAT_00582bf8,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x2357,0,0,0);
    FUN_0052f7a0(this,0x2357,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f690(this,0x2358,0x8e,0x133,s_VERDANA8_fnt_00563e98,DAT_00581a60,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x2358,0,0,0);
    FUN_0052f7a0(this,0x2358,2,0x54,0,0,0xfffe);
  }
  iVar1 = UI_AddText(this,0x2359,0x32,0x155,s_VERDANA7_fnt_00563ec8,DAT_00581fc0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x2359,0);
    FUN_0052f9d0(this,0x2359,0,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x235a,0x5f,0x155,s_VERDANA7_fnt_00563ec8,s__5000__00566308);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x235a,0);
    FUN_0052f9d0(this,0x235a,1,0x28,0,0);
  }
  iVar1 = UI_AddText(this,0x235b,0x32,0x160,s_VERDANA7_fnt_00563ec8,DAT_00582a40);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x235b,0);
    FUN_0052f9d0(this,0x235b,0,0x3c,0,0);
  }
  iVar1 = UI_AddText(this,0x235c,0x5f,0x160,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x235c,0);
    FUN_0052f9d0(this,0x235c,1,0x28,0,0);
  }
  iVar1 = UI_AddText(this,0x235d,0x8f,0x155,s_VERDANA7_fnt_00563ec8,DAT_00581fc0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x235d,0);
    FUN_0052f9d0(this,0x235d,0,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x235e,0xb4,0x155,s_VERDANA7_fnt_00563ec8,s__300000__00566688);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x235e,0);
    FUN_0052f9d0(this,0x235e,1,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x235f,0x32,0x16a,s_VERDANA7_fnt_00563ec8,DAT_00581ecc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x235f,0);
    FUN_0052f9d0(this,0x235f,0,0x46,0,0);
  }
  iVar1 = UI_AddText(this,0x2360,0x5f,0x16a,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x2360,0);
    FUN_0052f9d0(this,0x2360,1,0x28,0,0);
  }
  iVar1 = UI_AddText(this,0x2361,0x8f,0x160,s_VERDANA7_fnt_00563ec8,DAT_00582a40);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x2361,0);
    FUN_0052f9d0(this,0x2361,0,0x3c,0,0);
  }
  iVar1 = UI_AddText(this,0x2362,0xbe,0x160,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x2362,0);
    FUN_0052f9d0(this,0x2362,1,0x28,0,0);
  }
  iVar1 = UI_AddText(this,0x2363,0x8f,0x16a,s_VERDANA7_fnt_00563ec8,DAT_00581ecc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x2363,0);
    FUN_0052f9d0(this,0x2363,0,0x46,0,0);
  }
  iVar1 = UI_AddText(this,0x2364,0xbe,0x16a,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x2364,0);
    FUN_0052f9d0(this,0x2364,1,0x28,0,0);
  }
  iVar1 = UI_AddText(this,0x2368,0x7d,0x3c,s_VERDANA8_fnt_00563e98,DAT_00582048);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x2368,0);
    FUN_0052f9d0(this,0x2368,0,0x385,0,0);
  }
  iVar1 = UI_AddText(this,0x2369,0x7d,0x48,s_VERDANA8_fnt_00563e98,DAT_00582728);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x2369,0);
    FUN_0052f9d0(this,0x2369,0,0x50,0,0);
  }
  iVar1 = UI_AddText(this,0x236a,0x7d,0x55,s_VERDANA8_fnt_00563e98,DAT_00582798);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x236a,0);
    FUN_0052f9d0(this,0x236a,0,0x50,0,0);
  }
  iVar1 = UI_AddText(this,0x236b,0xbf,0x3c,s_VERDANA8_fnt_00563e98,&DAT_00564538);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x236b,0);
    FUN_0052f9d0(this,0x236b,1,0x28,0,0);
  }
  iVar1 = UI_AddText(this,0x236c,0xbf,0x48,s_VERDANA8_fnt_00563e98,&DAT_005650ac);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x236c,0);
    FUN_0052f9d0(this,0x236c,1,0x28,0,0);
  }
  iVar1 = UI_AddText(this,0x236d,0xbf,0x55,s_VERDANA8_fnt_00563e98,&DAT_005650b0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x236d,0);
    FUN_0052f9d0(this,0x236d,1,0x28,0,0);
  }
  iVar1 = UI_AddText(this,0x236e,0x32,0x14a,s_VERDANA7_fnt_00563ec8,DAT_005813c8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x236e,0);
    FUN_0052f9d0(this,0x236e,0,0x4b,0,0);
  }
  iVar1 = UI_AddText(this,0x236f,0x73,0x14a,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x236f,0xff);
    FUN_0052f9d0(this,0x236f,1,0x14,0,0);
  }
  iVar1 = UI_AddText(this,0x2371,0x8f,0x14a,s_VERDANA7_fnt_00563ec8,DAT_00581484);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x2371,0);
    FUN_0052f9d0(this,0x2371,0,0x4b,0,0);
  }
  iVar1 = UI_AddText(this,0x2372,0xd2,0x14a,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x2372,0xff);
    FUN_0052f9d0(this,0x2372,1,0x14,0,0);
  }
  iVar1 = UI_AddText(this,0x2373,0x31,0xc0,s_VERDANA7_fnt_00563ec8,DAT_00582df8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x2373,0);
    FUN_0052f9d0(this,0x2373,0,0x96,0,0);
  }
  iVar1 = UI_AddText(this,0x2374,0xbd,0xc0,s_VERDANA7_fnt_00563ec8,&DAT_005650ac);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x2374,0);
    FUN_0052f9d0(this,0x2374,1,0x28,0,0);
  }
  iVar1 = UI_AddText(this,0x2376,0x31,0x9a,s_VERDANA7_fnt_00563ec8,DAT_00582600);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x2376,0);
    FUN_0052f9d0(this,0x2376,0,0x96,0,0);
  }
  iVar1 = UI_AddText(this,0x2377,0x31,0xaf,s_VERDANA7_fnt_00563ec8,DAT_00580cdc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x2377,0);
    FUN_0052f9d0(this,0x2377,0,0x96,0,0);
  }
  iVar1 = UI_AddText(this,0x2379,0xbd,0x9a,s_VERDANA7_fnt_00563ec8,&DAT_005650ac);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x2379,0);
    FUN_0052f9d0(this,0x2379,1,0x28,0,0);
  }
  iVar1 = UI_AddText(this,0x237a,0x82,0xaf,s_VERDANA7_fnt_00563ec8,s__1_000_000__005650ec);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x237a,0);
    FUN_0052f9d0(this,0x237a,1,100,0,0);
  }
  iVar1 = UI_AddText(this,0x237b,0x31,0xcb,s_VERDANA7_fnt_00563ec8,DAT_00582224);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x237b,0);
    FUN_0052f9d0(this,0x237b,0,0x96,0,0);
  }
  iVar1 = UI_AddText(this,0x237c,0x9a,0xcc,s_VERDANA7_fnt_00563ec8,DAT_00582300);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x237c,0);
    FUN_0052f9d0(this,0x237c,0,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x237e,0x9a,0xd9,s_VERDANA7_fnt_00563ec8,DAT_00582544);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x237e,0);
    FUN_0052f9d0(this,0x237e,0,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x237f,0x9a,0xe5,s_VERDANA7_fnt_00563ec8,DAT_00582474);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x237f,0);
    FUN_0052f9d0(this,0x237f,0,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x2380,199,0xcc,s_VERDANA7_fnt_00563ec8,&DAT_005650b4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x2380,0);
    FUN_0052f9d0(this,0x2380,1,0x1e,0,0);
  }
  iVar1 = UI_AddText(this,0x2382,199,0xd9,s_VERDANA7_fnt_00563ec8,&DAT_005650b8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x2382,0);
    FUN_0052f9d0(this,0x2382,1,0x1e,0,0);
  }
  iVar1 = UI_AddText(this,0x2383,199,0xe5,s_VERDANA7_fnt_00563ec8,&DAT_005650b8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x2383,0);
    FUN_0052f9d0(this,0x2383,1,0x1e,0,0);
  }
  UI_AddSprite(this,0x2384,0x34,0x25,s_FOTORAHMEN00_spr_00564310);
  UI_AddSprite(this,0x2386,0x39,0x2a,s_FOTODUMMY00_spr_00564300);
  UI_AddSprite(this,0x2387,0xb7,0x106,s_PLAYLOG_8_01_02_spr_00564744);
  iVar1 = UI_AddText(this,0x2388,0x31,0xa5,s_VERDANA7_fnt_00563ec8,DAT_00582c44);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x2388,0);
    FUN_0052f9d0(this,0x2388,0,0x96,0,0);
  }
  iVar1 = UI_AddText(this,0x2389,0xbd,0xa5,s_VERDANA7_fnt_00563ec8,&DAT_005650ac);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x2389,0);
    FUN_0052f9d0(this,0x2389,1,0x28,0,0);
  }
  return this;
}

