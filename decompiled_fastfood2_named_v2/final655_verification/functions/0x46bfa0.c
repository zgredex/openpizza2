// rea decompile_all
// name: AI_DebugStatusWindow_Create
// address: 0x46bfa0
// body: available
// range: 0x46bfa0-0x46c560 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl AI_DebugStatusWindow_Create(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
                    /* Creates the debug AI status window. */
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004c6000);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  FUN_00531850(this,0x429,0x27,0x14c,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x449,0x2c,5,s_TIMESFONT_fnt_00563ea8,s_KI_Status_00566d10);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x449,0);
    FUN_0052f9d0(this,0x449,2,0xbe,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f4c,0x45,0x4f,s_VERDANA8_fnt_00563e98,s_dffkmls_00566d08);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f4c,0);
    FUN_0052f9d0(this,0x1f4c,2,0x87,0,0);
  }
  FUN_00531850(this,0x1f4d,0x70,0x2b,s_LOGORAHMEN_00_spr_005650f8);
  FUN_00531850(this,0x1f4f,0x72,0x2d,s_PLAYLOG_8_01_02_spr_00564744);
  FUN_0052f5b0(this,0x1f50,0x54,0x2f,s_PB22_00_spr_00564174,0,0);
  FUN_0052f5b0(this,0x1f51,0xa0,0x2f,s_PB24_00_spr_00564144,0,0);
  iVar1 = FUN_0052f850(this,0x1f52,0x5d,0x8c,s_VERDANA8_fnt_00563e98,s_ki_active_00566cfc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f52,0);
    FUN_0052f9d0(this,0x1f52,0,0,0xffff,0);
  }
  FUN_0052f5b0(this,0x1f53,0x41,0x87,s_PB14_00_spr_005642c4,1,0);
  iVar1 = FUN_0052f850(this,0x1f54,0x3f,0xdf,s_VERDANA8_fnt_00563e98,s_aggressive_00566cf0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f54,0);
    FUN_0052f9d0(this,0x1f54,2,0x96,0,0);
  }
  iVar1 = UI_CreateSlider(this,0x1f55,0x4d,0xf3,0x8c,s_SL02_00_spr_005642d0,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    FUN_0052fcc0(this,0x1f55,&local_10);
  }
  iVar1 = UI_AddInputField(this,0x1f56,99,0xc1,s_VERDANA8_fnt_00563e98,s_1000000_00566ce8,0x4b);
  if (iVar1 != 0) {
    FUN_0052fb40(this,0x1f56,0x505050);
    FUN_0052fb60(this,0x1f56,0xff);
    FUN_0052fb80(this,0x1f56,0xffff);
    FUN_0052fba0(this,0x1f56,0x6d0000);
  }
  FUN_0052f5b0(this,0x1f57,0x44,0xbb,s_PB22_00_spr_00564174,0,0);
  FUN_0052f5b0(this,0x1f58,0xae,0xbc,s_PB24_00_spr_00564144,0,0);
  iVar1 = FUN_0052f850(this,0x1f59,0x45,0xaf,s_VERDANA8_fnt_00563e98,s_money_00566ce0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f59,0);
    FUN_0052f9d0(this,0x1f59,0,0xffff,0xffff,0);
  }
  iVar1 = UI_AddTextButton(this,0x1f5a,0x34,0x131,s_VERDANA8_fnt_00563e98,&DAT_00566cd8,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x1f5a,0,0,0);
    FUN_0052f7a0(this,0x1f5a,2,0x54,0,0,0xfffe);
  }
  iVar1 = UI_AddTextButton(this,0x1f5b,0x91,0x132,s_VERDANA8_fnt_00563e98,s_take_over_00566ccc,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x1f5b,0,0,0);
    FUN_0052f7a0(this,0x1f5b,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f850(this,0x1f5c,0x3c,0x62,s_VERDANA8_fnt_00563e98,s_player_number_00566cbc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f5c,0);
    FUN_0052f9d0(this,0x1f5c,0,0,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x1f5d,0x3c,0x72,s_VERDANA8_fnt_00563e98,s_company_number_00566cac);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f5d,0);
    FUN_0052f9d0(this,0x1f5d,0,0,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x1f5e,0xb3,99,s_VERDANA8_fnt_00563e98,&DAT_00564214);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f5e,0xff);
    FUN_0052f9d0(this,0x1f5e,0,0x14,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x1f5f,0xb3,0x72,s_VERDANA8_fnt_00563e98,&DAT_00564214);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f5f,0xff);
    FUN_0052f9d0(this,0x1f5f,0,0x14,0xffff,0);
  }
  iVar1 = UI_AddTextButton(this,0x1f60,99,0x15a,s_VERDANA8_fnt_00563e98,s_close_00566ca4,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x1f60,0,0,0);
    FUN_0052f7a0(this,0x1f60,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f850(this,0x1f61,0x42,0x104,s_VERDANA8_fnt_00563e98,s_rage_level_00566c98);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f61,0);
    FUN_0052f9d0(this,0x1f61,2,0x96,0,0);
  }
  iVar1 = UI_CreateSlider(this,0x1f62,0x50,0x118,0x8c,s_SL02_00_spr_005642d0,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    FUN_0052fcc0(this,0x1f62,&local_10);
  }
  return this;
}

