// rea decompile_all
// name: FUN_00426c30
// address: 0x426c30
// body: available
// range: 0x426c30-0x427265 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_00426c30(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004a1c50);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  iVar1 = FUN_0052f850(this,0x440,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_0058165c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x440,0);
    FUN_0052f9d0(this,0x440,2,0xbe,0,0);
  }
  iVar1 = FUN_0052f850(this,0x441,0x33,0x27,s_VERDANA8_fnt_00563e98,DAT_00581cf0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x441,0);
    FUN_0052f9d0(this,0x441,0,0xb4,0,0);
  }
  iVar1 = FUN_0052fc00(this,0x462,0xde,0x3f,0x109,s_SL01_00_spr_0056448c,0,1);
  if (iVar1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    FUN_0052fcc0(this,0x462,&local_10);
  }
  FUN_0052f5b0(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  FUN_00531850(this,0x1f41,0x27,0x14c,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f690(this,0x1f42,0x30,0x15b,s_VERDANA8_fnt_00563e98,DAT_00582748,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x1f42,0,0,0);
    FUN_0052f7a0(this,0x1f42,2,0xb4,0,0,0xfffe);
  }
  FUN_0052f5b0(this,0x1f5d,0x34,0x38,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x1f5e,0x34,0x4d,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x1f5f,0x34,0x62,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x1f60,0x34,0x77,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x1f61,0x34,0x8c,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x1f62,0x34,0xa1,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x1f63,0x34,0xb6,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x1f64,0x34,0xcb,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x1f65,0x34,0xe0,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x1f66,0x34,0xf5,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x1f67,0x34,0x10a,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x1f68,0x34,0x11f,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x1f69,0x34,0x134,s_TABPB01__00_spr_00564670,1,0);
  iVar1 = FUN_0052f850(this,0x1f6a,0x39,0x3c,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f6a,0);
    FUN_0052f9d0(this,0x1f6a,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f6b,0x39,0x51,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f6b,0);
    FUN_0052f9d0(this,0x1f6b,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f6c,0x39,0x66,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f6c,0);
    FUN_0052f9d0(this,0x1f6c,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f6d,0x39,0x7b,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f6d,0);
    FUN_0052f9d0(this,0x1f6d,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f6e,0x39,0x90,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f6e,0);
    FUN_0052f9d0(this,0x1f6e,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f6f,0x39,0xa5,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f6f,0);
    FUN_0052f9d0(this,0x1f6f,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f70,0x39,0xba,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f70,0);
    FUN_0052f9d0(this,0x1f70,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f71,0x39,0xcf,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f71,0);
    FUN_0052f9d0(this,0x1f71,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f72,0x39,0xe4,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f72,0);
    FUN_0052f9d0(this,0x1f72,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f73,0x39,0xf9,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f73,0);
    FUN_0052f9d0(this,0x1f73,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f74,0x39,0x10e,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f74,0);
    FUN_0052f9d0(this,0x1f74,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f75,0x39,0x123,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f75,0);
    FUN_0052f9d0(this,0x1f75,0,0x96,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f76,0x39,0x138,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f76,0);
    FUN_0052f9d0(this,0x1f76,0,0x96,0,0);
  }
  return this;
}

