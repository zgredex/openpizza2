// rea decompile_all
// name: FUN_0042d560
// address: 0x42d560
// body: available
// range: 0x42d560-0x42d98b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_0042d560(int *param_1)

{
  int iVar1;
  void *this;
  
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004a7510);
  *param_1 = iVar1;
  this = (void *)UI_FindWindowByID(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  FUN_00531850(this,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x441,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00581270);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x441,0);
    FUN_0052f9d0(this,0x441,2,0xbe,0,0);
  }
  iVar1 = FUN_0052f690(this,0x44f,0x8e,0x112,s_VERDANA8_fnt_00563e98,DAT_0058292c,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x44f,0,0,0);
    FUN_0052f7a0(this,0x44f,2,0x54,0,0,0xfffe);
  }
  FUN_0052f5b0(this,0x4ef,99,0x7e,s_SKFILIALE_00_spr_005654fc,1,0);
  FUN_0052f5b0(this,0x4f0,0x8d,0x7e,s_SKLAGER_00_spr_005654ec,1,0);
  FUN_00531850(this,0x4f3,0x27,0xf2,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x4f4,0x31,0x7e,s_VERDANA8_fnt_00563e98,DAT_005829e4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4f4,0);
    FUN_0052f9d0(this,0x4f4,0,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4f5,0xb4,0x7e,s_VERDANA8_fnt_00563e98,DAT_0058106c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4f5,0);
    FUN_0052f9d0(this,0x4f5,0,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4f6,0x31,0x95,s_VERDANA8_fnt_00563e98,s__Mittel_005654e4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4f6,0);
    FUN_0052f9d0(this,0x4f6,0,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4f8,0x31,0xfd,s_VERDANA8_fnt_00563e98,DAT_00582b30);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4f8,0);
    FUN_0052f9d0(this,0x4f8,0,0x8c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4f9,0xa7,0xfd,s_VERDANA8_fnt_00563e98,s__34555__005654dc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4f9,0);
    FUN_0052f9d0(this,0x4f9,1,0x41,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4fa,0x4e,0x112,s_TIMESFONT_fnt_00563ea8,&DAT_00564774);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4fa,0);
    FUN_0052f9d0(this,0x4fa,2,0x19,0,0);
  }
  FUN_0052f5b0(this,0x4fb,0x32,0x111,s_PB26_00_spr_00564610,0,0);
  FUN_0052f5b0(this,0x4fc,0x69,0x111,s_PB27_00_spr_005645fc,0,0);
  FUN_0052f5b0(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  iVar1 = FUN_0052f850(this,0x1f41,0xb4,0x95,s_VERDANA8_fnt_00563e98,s__Mittel_005654e4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f41,0);
    FUN_0052f9d0(this,0x1f41,0,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f42,0x2c,0x12f,s_VERDANA7_fnt_00563ec8,DAT_00581898);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f42,0);
    FUN_0052f9d0(this,0x1f42,2,0xbe,0,0);
  }
  FUN_00531850(this,0x1f43,0x2f,0x13a,s_TAB01xxx_spr_00565234);
  iVar1 = FUN_0052f850(this,0x1f4d,0x33,0xa9,s_VERDANA7_fnt_00563ec8,DAT_00580ff4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f4d,0);
    FUN_0052f9d0(this,0x1f4d,0,0xb4,0x4b,0);
  }
  FUN_00531850(this,0x1f57,0x5d,0x2b,s_MG_H_LAGER_C7_spr_005654c8);
  return this;
}

