// rea decompile_all
// name: FUN_00475f90
// address: 0x475f90
// body: available
// range: 0x475f90-0x4760ff inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_00475f90(int *param_1)

{
  int iVar1;
  void *this;
  
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0,0,s_BG004_spr_00567520,&LAB_004ce770);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  iVar1 = FUN_0052f690(this,1000,0x73,0x212,s_TIMESFONT_fnt_00563ea8,DAT_00582748,0,
                       s_TEXTPBTRANSPGELB_00_spr_00567208);
  if (iVar1 != 0) {
    FUN_0052f750(this,1000,0,0,0);
    FUN_0052f7a0(this,1000,2,0xcc,0,0,0);
  }
  iVar1 = FUN_0052f690(this,0x3e9,0x1df,0x212,s_TIMESFONT_fnt_00563ea8,DAT_00581b24,0,
                       s_TEXTPBTRANSPGELB_00_spr_00567208);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x3e9,0,0,0);
    FUN_0052f7a0(this,0x3e9,2,0xcc,0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x3ec,0,0x14,s_VERDANA16_fnt_00565788,DAT_00582664);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x3ec,0);
    FUN_0052f9d0(this,0x3ec,2,800,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x3ed,0,0x37,s_TIMES14_fnt_00564788,DAT_00581d28);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x3ed,0);
    FUN_0052f9d0(this,0x3ed,2,800,0xffff,0);
  }
  return this;
}

