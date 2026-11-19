// rea decompile_all
// name: FUN_00443980
// address: 0x443980
// body: available
// range: 0x443980-0x443aac inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_00443980(int *param_1)

{
  int iVar1;
  void *this;
  
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x237,0xf8,s_DUMMYSPRITE_spr_00563e10,&LAB_004d12c0);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  FUN_0052f5b0(this,0x3f4,1,3,s_R_INFO__00_spr_00563e00,1,0);
  FUN_0052f5b0(this,0x3f5,1,0x21,s_R_PERSONAL__00_spr_00563dec,1,0);
  FUN_0052f5b0(this,0x3f6,1,0x3f,s_R_EINRICHTUNG__00_spr_00563dd4,1,0);
  FUN_0052f5b0(this,0x3f7,1,0x5d,s_R_SPEISEKARTE__00_spr_00563dbc,1,0);
  FUN_0052f5b0(this,0x3fd,1,0x111,s_R_LUPE__00_spr_00563d5c,1,0);
  FUN_0052f5b0(this,0x3fe,1,0x7b,s_R_WETTBEWERB__00_spr_005662cc,1,0);
  FUN_0052f5b0(this,0x3ff,1,0x99,s_R_AERGERN__00_spr_005662b8,1,0);
  FUN_0052f5b0(this,0x400,1,0xb7,s_R_ANGREIFEN__00_spr_005662a4,1,0);
  FUN_0052f5b0(this,0x401,1,0xd5,s_R_MANAGER__00_spr_00563d6c,1,0);
  return this;
}

