// rea decompile_all
// name: CRT_Atof
// address: 0x54f71e
// body: available
// range: 0x54f71e-0x54f774 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


float10 __thiscall CRT_Atof(undefined *param_1,byte *param_2)

{
  uint uVar1;
  int iVar2;
  byte *this;
  undefined *puVar3;
  uint local_1c [6];
  
  while( true ) {
    if (DAT_00576cf0 < 2) {
      uVar1 = (byte)PTR_DAT_00576ae4[(uint)*param_2 * 2] & 8;
      param_1 = PTR_DAT_00576ae4;
    }
    else {
      puVar3 = (undefined *)0x8;
      uVar1 = CRT_Mbtowc(param_1,(uint)*param_2,8);
      param_1 = puVar3;
    }
    if (uVar1 == 0) break;
    param_2 = param_2 + 1;
  }
  this = param_2;
  _strlen((char *)param_2);
  iVar2 = CRT_StrToDouble(this,local_1c,param_2);
  return (float10)*(double *)(iVar2 + 0x10);
}

