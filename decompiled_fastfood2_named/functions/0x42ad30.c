// rea decompile_all
// name: FUN_0042ad30
// address: 0x42ad30
// body: available
// range: 0x42ad30-0x42b217 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_0042ad30(int *param_1)

{
  int iVar1;
  void *this;
  
  iVar1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004a54c0);
  *param_1 = iVar1;
  this = (void *)UI_FindWindowByID(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(this,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  iVar1 = UI_AddText(this,0x430,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00581058);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x430,0);
    FUN_0052f9d0(this,0x430,2,0xbe,0,0);
  }
  iVar1 = UI_AddText(this,0x431,0x2c,0x12e,s_VERDANA7_fnt_00563ec8,DAT_00581098);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x431,0);
    FUN_0052f9d0(this,0x431,2,0xbe,0,0);
  }
  iVar1 = UI_AddText(this,0x433,0x33,0xf8,s_VERDANA7_fnt_00563ec8,DAT_00580ffc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x433,0);
    FUN_0052f9d0(this,0x433,0,0x23,0,0);
  }
  iVar1 = FUN_0052f690(this,0x437,0x8e,0x112,s_VERDANA8_fnt_00563e98,DAT_00582ae4,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x437,0,0,0);
    FUN_0052f7a0(this,0x437,2,0x54,0,0,0xfffe);
  }
  iVar1 = UI_AddText(this,0x439,0x94,0xe8,s_VERDANA8_fnt_00563e98,s__21321__0056524c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x439,0);
    FUN_0052f9d0(this,0x439,1,0x50,0,0);
  }
  iVar1 = UI_AddText(this,0x43a,0x46,0xf8,s_VERDANA7_fnt_00563ec8,s__21Tage_00565244);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x43a,0);
    FUN_0052f9d0(this,0x43a,1,0x37,0,0);
  }
  UI_AddSprite(this,0x43f,0x2f,0x13a,s_TAB01xxx_spr_00565234);
  UI_AddImage(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  UI_AddImage(this,0x1f68,0x31,0x26,s_BAUENPB__00_spr_00565224,0,0);
  UI_AddImage(this,0x1f69,0x8b,0x26,s_BAUENPB__00_spr_00565224,0,0);
  UI_AddImage(this,0x1f6a,0x31,0x70,s_BAUENPB__00_spr_00565224,0,0);
  UI_AddImage(this,0x1f6b,0x8b,0x70,s_BAUENPB__00_spr_00565224,0,0);
  iVar1 = UI_AddText(this,0x1f61,0x96,0xf8,s_VERDANA7_fnt_00563ec8,DAT_00581c54);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f61,0);
    FUN_0052f9d0(this,0x1f61,0,0x23,0,0);
  }
  iVar1 = UI_AddText(this,0x1f62,0x33,0x103,s_VERDANA7_fnt_00563ec8,DAT_005824b8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f62,0);
    FUN_0052f9d0(this,0x1f62,0,0x82,0,0);
  }
  iVar1 = UI_AddText(this,0x1f63,0xad,0xf8,s_VERDANA7_fnt_00563ec8,s__21321__0056524c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f63,0);
    FUN_0052f9d0(this,0x1f63,1,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x1f64,0xad,0x103,s_VERDANA7_fnt_00563ec8,s__20000__0056521c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f64,0);
    FUN_0052f9d0(this,0x1f64,1,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x1f65,0x33,0xe8,s_VERDANA8_fnt_00563e98,DAT_005816a8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f65,0);
    FUN_0052f9d0(this,0x1f65,0,0x6e,0,0);
  }
  iVar1 = UI_AddText(this,0x1f66,0x33,0xec,s_VERDANA7_fnt_00563ec8,
                     s__________________________________005651dc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f66,0);
    FUN_0052f9d0(this,0x1f66,0,0xb1,0,0);
  }
  iVar1 = UI_AddText(this,0x1f67,0x33,0xba,s_VERDANA7_fnt_00563ec8,&DAT_005651c4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f67,0);
    FUN_0052f9d0(this,0x1f67,0,0xb4,0x28,0);
  }
  UI_AddSprite(this,0x1f79,0x8b,0x71,s_MG_H_POLIZEI_spr_005651b0);
  UI_AddSprite(this,0x1f7a,0x31,0x26,s_MG_H_PIZZ_A7_spr_0056519c);
  UI_AddSprite(this,0x1f7b,0x8b,0x25,s_MG_H_LAGER_A7_spr_00565188);
  UI_AddSprite(this,0x1f7c,0x32,0x71,s_MG_H_HQ_A7_spr_00565178);
  return this;
}

