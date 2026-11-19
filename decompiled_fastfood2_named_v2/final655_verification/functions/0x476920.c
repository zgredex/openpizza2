// rea decompile_all
// name: FUN_00476920
// address: 0x476920
// body: available
// range: 0x476920-0x476b5a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_00476920(int *param_1)

{
  int iVar1;
  void *this;
  
  iVar1 = FUN_00523c90(DAT_0057c5e0,s_Pe_Startscreen_TGA_00567574,&LAB_004ceb80);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  iVar1 = UI_AddTextButton(this,0x3ee,0x253,6,s_TIMESFONT_fnt_00563ea8,DAT_00581740,0,
                           s_TEXTPBTRANSPGELB_00_spr_00567208);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x3ee,0,0,0);
    FUN_0052f7a0(this,0x3ee,2,0xcc,0,0,0);
  }
  iVar1 = UI_AddTextButton(this,0x3ef,0x253,0x30,s_TIMESFONT_fnt_00563ea8,DAT_00582468,0,
                           s_TEXTPBTRANSPGELB_00_spr_00567208);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x3ef,0,0,0);
    FUN_0052f7a0(this,0x3ef,2,0xcc,0,0,0);
  }
  iVar1 = UI_AddTextButton(this,0x3f0,0x253,0x5b,s_TIMESFONT_fnt_00563ea8,DAT_00582d5c,0,
                           s_TEXTPBTRANSPGELB_00_spr_00567208);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x3f0,0,0,0);
    FUN_0052f7a0(this,0x3f0,2,0xcc,0,0,0);
  }
  iVar1 = UI_AddTextButton(this,0x3f1,0x253,0x85,s_TIMESFONT_fnt_00563ea8,DAT_00581878,0,
                           s_TEXTPBTRANSPGELB_00_spr_00567208);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x3f1,0,0,0);
    FUN_0052f7a0(this,0x3f1,2,0xcc,0,0,0);
  }
  iVar1 = UI_AddTextButton(this,0x3f6,0x253,0x230,s_TIMESFONT_fnt_00563ea8,DAT_00581c70,0,
                           s_TEXTPBTRANSPGELB_00_spr_00567208);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x3f6,0,0,0);
    FUN_0052f7a0(this,0x3f6,2,0xcc,0,0,0);
  }
  iVar1 = UI_AddTextButton(this,0x3f7,0x253,0xaf,s_TIMESFONT_fnt_00563ea8,DAT_00581904,0,
                           s_TEXTPBTRANSPGELB_00_spr_00567208);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x3f7,0,0,0);
    FUN_0052f7a0(this,0x3f7,2,0xcc,0,0,0);
  }
  return this;
}

