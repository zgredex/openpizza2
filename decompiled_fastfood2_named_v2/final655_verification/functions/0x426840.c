// rea decompile_all
// name: SoundOptionsPage_Create
// address: 0x426840
// body: available
// range: 0x426840-0x426c2d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl SoundOptionsPage_Create(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
                    /* Creates the sound settings page. */
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004a1250);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  iVar1 = FUN_0052f850(this,0x44f,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00581060);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x44f,0);
    FUN_0052f9d0(this,0x44f,2,0xbe,0,0);
  }
  iVar1 = FUN_0052f850(this,0x450,0x41,0x47,s_VERDANA8_fnt_00563e98,DAT_00581df0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x450,0);
    FUN_0052f9d0(this,0x450,2,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x451,0x41,0x84,s_VERDANA8_fnt_00563e98,DAT_00582ee0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x451,0);
    FUN_0052f9d0(this,0x451,2,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x452,0x41,0xa7,s_VERDANA8_fnt_00563e98,DAT_00580e94);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x452,0);
    FUN_0052f9d0(this,0x452,2,0x96,0,0);
  }
  iVar1 = UI_CreateSlider(this,0x43a,0x4a,0x5d,0x8c,s_SL02_00_spr_005642d0,0,0);
  if (iVar1 != 0) {
    local_10 = 0xffff;
    local_c = 0xf300;
    local_8 = 0xff;
    local_4 = 0;
    FUN_0052fcc0(this,0x43a,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x43b,0x4a,0x9a,0x8c,s_SL02_00_spr_005642d0,0,0);
  if (iVar1 != 0) {
    local_10 = 0xffff;
    local_c = 0xf300;
    local_8 = 0xff;
    local_4 = 0;
    FUN_0052fcc0(this,0x43b,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x43c,0x4a,0xbd,0x8c,s_SL02_00_spr_005642d0,0,0);
  if (iVar1 != 0) {
    local_10 = 0xffff;
    local_c = 0xf300;
    local_8 = 0xff;
    local_4 = 0;
    FUN_0052fcc0(this,0x43c,&local_10);
  }
  FUN_0052f5b0(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  iVar1 = FUN_0052f850(this,0x1f41,0x2b,0x25,s_VERDANA14_fnt_00564d8c,DAT_0058128c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f41,0);
    FUN_0052f9d0(this,0x1f41,2,0xbe,0,0);
  }
  FUN_00531850(this,0x1f50,0x27,0x14c,s_TRENNZEILE_spr_00563eb8);
  iVar1 = UI_AddTextButton(this,0x1f51,0x30,0x15b,s_VERDANA8_fnt_00563e98,DAT_00582748,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x1f51,0,0,0);
    FUN_0052f7a0(this,0x1f51,2,0xb4,0,0,0xfffe);
  }
  FUN_00531850(this,0x1f52,0x27,0xf2,s_TRENNZEILE_spr_00563eb8);
  FUN_0052f5b0(this,0x1f53,0x3c,0x125,s_PB14_00_spr_005642c4,1,0);
  iVar1 = FUN_0052f850(this,0x1f54,0x56,0x123,s_VERDANA8_fnt_00563e98,DAT_00581c08);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f54,0);
    FUN_0052f9d0(this,0x1f54,0,0x8c,0x1e,0);
  }
  iVar1 = FUN_0052f850(this,0x1f55,0x2b,0xff,s_VERDANA14_fnt_00564d8c,DAT_00581878);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f55,0);
    FUN_0052f9d0(this,0x1f55,2,0xbe,0,0);
  }
  return this;
}

