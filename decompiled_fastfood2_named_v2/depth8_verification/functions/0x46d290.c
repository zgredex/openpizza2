// rea decompile_all
// name: FUN_0046d290
// address: 0x46d290
// body: available
// range: 0x46d290-0x46d3f6 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_0046d290(int *param_1)

{
  int iVar1;
  void *this;
  
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0,0,s_RQ_MISSION_spr_00566eb4,&LAB_004c6ab0);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  iVar1 = FUN_0052f690(this,0x433,0x1ec,0x8d,s_VERDANA8_fnt_00563e98,s__Gehe_zu_00566ea8,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x433,0,0,0);
    FUN_0052f7a0(this,0x433,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f850(this,0x439,0x3e,0x25,s_VERDANA8_fnt_00563e98,s__Dummy_00566ea0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x439,0);
    FUN_0052f9d0(this,0x439,0,0x203,0x79,0);
  }
  iVar1 = FUN_0052f850(this,0x43a,0x3d,0xe,s_VEDANA12_fnt_00566d60,s__Eine_Filiale_mieten_00566e88);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x43a,0);
    FUN_0052f9d0(this,0x43a,0,500,0xffff,0);
  }
  FUN_00531850(this,0x458,0x16,0x38,s_NEWSCHUTZ_spr_00564f6c);
  FUN_00531850(this,0x461,0x16,0x5a,s_NEWSCHUTZ_spr_00564f6c);
  FUN_00531850(this,0x468,0x16,0x7c,s_NEWSCHUTZ_spr_00564f6c);
  FUN_00531850(this,0x46a,0x10,0xb,s_RB02X_FILIALE_spr_00566e74);
  return this;
}

