// rea decompile_all
// name: FUN_00455be0
// address: 0x455be0
// body: available
// range: 0x455be0-0x456447 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_00455be0(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004bf000);
  *param_1 = iVar1;
  this = (void *)UI_FindWindowByID(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(this,0x45f,0x27,0xb7,s_TRENNZEILE_spr_00563eb8);
  UI_AddSprite(this,0x46d,0x29,0x2c,s_MASCHINENGEWEHRICON_spr_005665b0);
  UI_AddSprite(this,0x470,0x30,0x2b,s_SCHLAEGERICON_spr_0056659c);
  iVar1 = UI_AddText(this,0x472,0x2a,5,s_TIMESFONT_fnt_00563ea8,DAT_00582808);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x472,0);
    FUN_0052f9d0(this,0x472,2,0xbe,0,0);
  }
  iVar1 = UI_AddText(this,0x476,0x2f,0x82,s_VERDANA10_fnt_00563e64,DAT_005825f4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x476,0);
    FUN_0052f9d0(this,0x476,0,0x46,0,0);
  }
  iVar1 = UI_AddText(this,0x477,0x2c,0x102,s_VERDANA8_fnt_00563e98,DAT_00581e70);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x477,0);
    FUN_0052f9d0(this,0x477,2,0xbe,0,0);
  }
  iVar1 = FUN_0052f690(this,0x483,0x30,0x112,s_VERDANA8_fnt_00563e98,DAT_0058276c,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x483,0,0,0);
    FUN_0052f7a0(this,0x483,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f690(this,0x484,0x8e,0x112,s_VERDANA8_fnt_00563e98,DAT_00581d08,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x484,0,0,0);
    FUN_0052f7a0(this,0x484,2,0x54,0,0,0xfffe);
  }
  iVar1 = UI_AddText(this,0x48f,0x4d,0x33,s_VEDANA11_fnt_00564090,&DAT_00566728);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x48f,0);
    FUN_0052f9d0(this,0x48f,2,0x78,0,0);
  }
  UI_AddImage(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  iVar1 = FUN_0052fc00(this,0x1f41,0x3e,0x69,0xa0,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xf700;
    local_4 = 0;
    FUN_0052fcc0(this,0x1f41,&local_10);
  }
  iVar1 = UI_AddText(this,0x1f42,0x34,0x56,s_VERDANA8_fnt_00563e98,DAT_00582b0c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f42,0);
    FUN_0052f9d0(this,0x1f42,2,0xaa,0,0);
  }
  UI_AddSprite(this,0x1f43,0x27,0x79,s_TRENNZEILE_spr_00563eb8);
  iVar1 = UI_AddText(this,0x1f44,0x2f,0x95,s_VERDANA10_fnt_00563e64,&DAT_0056670c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f44,0);
    FUN_0052f9d0(this,0x1f44,0,0xb4,0x23,0);
  }
  iVar1 = UI_AddText(this,0x1f46,0x74,0x168,s_VERDANA8_fnt_00563e98,&DAT_00565088);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f46,0);
    FUN_0052f9d0(this,0x1f46,2,0x2d,0,0);
  }
  iVar1 = UI_AddText(this,0x1f47,0x36,0x168,s_VERDANA8_fnt_00563e98,&DAT_00565094);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f47,0);
    FUN_0052f9d0(this,0x1f47,2,0x2d,0,0);
  }
  iVar1 = UI_AddText(this,0x1f48,0xb5,0x167,s_VERDANA8_fnt_00563e98,&DAT_00565088);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f48,0);
    FUN_0052f9d0(this,0x1f48,2,0x2d,0,0);
  }
  UI_AddSprite(this,0x1f4b,0x27,0x12a,s_TRENNZEILE_spr_00563eb8);
  iVar1 = UI_AddText(this,0x1f4c,0x33,0x134,s_VERDANA8_fnt_00563e98,DAT_00580fec);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f4c,0);
    FUN_0052f9d0(this,0x1f4c,0,0x82,0,0);
  }
  iVar1 = UI_AddText(this,0x1f4d,0x83,0x134,s_VERDANA8_fnt_00563e98,s__Stufe_1_0056452c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f4d,0);
    FUN_0052f9d0(this,0x1f4d,1,100,0,0);
  }
  iVar1 = UI_AddText(this,0x1f4e,0x2f,0xc0,s_VERDANA10_fnt_00563e64,DAT_005817ac);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f4e,0);
    FUN_0052f9d0(this,0x1f4e,0,0xb4,0,0);
  }
  iVar1 = UI_AddText(this,0x1f4f,0x33,0xdc,s_VERDANA7_fnt_00563ec8,DAT_00582fb4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f4f,0);
    FUN_0052f9d0(this,0x1f4f,0,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x1f50,0xbb,0xdd,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f50,0);
    FUN_0052f9d0(this,0x1f50,1,0x28,0,0);
  }
  iVar1 = UI_AddText(this,0x1f51,0x33,0xe6,s_VERDANA7_fnt_00563ec8,DAT_00581ebc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f51,0);
    FUN_0052f9d0(this,0x1f51,0,0x3c,0,0);
  }
  iVar1 = UI_AddText(this,0x1f52,0xbb,0xe7,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f52,0);
    FUN_0052f9d0(this,0x1f52,1,0x28,0,0);
  }
  iVar1 = UI_AddText(this,0x1f53,0x33,0xf0,s_VERDANA7_fnt_00563ec8,DAT_00582e58);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f53,0);
    FUN_0052f9d0(this,0x1f53,0,0x3c,0,0);
  }
  iVar1 = UI_AddText(this,0x1f54,0xbb,0xf1,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f54,0);
    FUN_0052f9d0(this,0x1f54,1,0x28,0,0);
  }
  iVar1 = UI_AddText(this,0x1f55,0x70,0xd1,s_VERDANA7_fnt_00563ec8,DAT_00582a40);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f55,0);
    FUN_0052f9d0(this,0x1f55,1,0x3c,0,0);
  }
  iVar1 = UI_AddText(this,0x1f56,0xa7,0xd1,s_VERDANA7_fnt_00563ec8,DAT_005828d0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f56,0);
    FUN_0052f9d0(this,0x1f56,1,0x3c,0,0);
  }
  iVar1 = UI_AddText(this,0x1f57,0x84,0xdd,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f57,0);
    FUN_0052f9d0(this,0x1f57,1,0x28,0,0);
  }
  iVar1 = UI_AddText(this,0x1f58,0x84,0xe7,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f58,0);
    FUN_0052f9d0(this,0x1f58,1,0x28,0,0);
  }
  iVar1 = UI_AddText(this,0x1f59,0x84,0xf1,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f59,0);
    FUN_0052f9d0(this,0x1f59,1,0x28,0,0);
  }
  UI_AddSprite(this,0x1f5a,0x2b,0x2c,s_LIEFERANT_spr_0056658c);
  UI_AddSprite(this,0x1f5b,0x80,0x14f,&DAT_0056450c);
  UI_AddSprite(this,0x1f5c,0x42,0x14f,s_SCHLAGKRAFT_spr_0056451c);
  UI_AddSprite(this,0x1f5d,0xc1,0x14f,s_PANZERUNG_spr_005644f8);
  return this;
}

