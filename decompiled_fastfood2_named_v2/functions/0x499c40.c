// rea decompile_all
// name: FUN_00499c40
// address: 0x499c40
// body: available
// range: 0x499c40-0x499d1b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_00499c40(uint param_1)

{
  int iVar1;
  undefined4 *this;
  undefined2 *puVar2;
  uint local_44;
  CHAR local_40 [64];
  
  if ((int)param_1 < 0) {
    FUN_00527a50((int)DAT_0057c5e0);
    DAT_0057ca2c = 0;
    return;
  }
  iVar1 = IDMap_Lookup(DAT_0057ca20,param_1,(int *)0x0);
  String_Format(local_40,(byte *)s_zutaten_ZA_02dA__02d_spr_00568948,*(undefined4 *)(iVar1 + 0xd0));
  this = FUN_00527950(DAT_0057c5e0,local_40);
  FUN_0048cae0(DAT_0057c670,0);
  if (this != (undefined4 *)0x0) {
    FUN_0053d040(this,&param_1,&local_44);
    DAT_0057ca18 = -((int)local_44 / 2);
    DAT_0057ca14 = -((int)param_1 / 2);
    FUN_00527a10(DAT_0057c5e0,1,DAT_0057ca14,DAT_0057ca18);
    DAT_0057ca2c = 1;
    puVar2 = (undefined2 *)FUN_00527aa0((int)DAT_0057c5e0);
    FUN_00527a80(DAT_0057c5e0,puVar2,1);
  }
  return;
}

