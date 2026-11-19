// rea decompile_all
// name: Sound_AlignBufferSize
// address: 0x541cf0
// body: available
// range: 0x541cf0-0x541d46 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint __cdecl Sound_AlignBufferSize(undefined4 param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  
  uVar3 = __ftol();
  uVar1 = (uint)uVar3;
  if (*(ushort *)(param_3 + 0xc) < 2) {
    if ((uVar3 & 1) != 0) {
      uVar1 = uVar1 - (uVar1 & 1);
    }
  }
  else {
    iVar2 = (int)((uVar3 & 0xffffffff) % (ulonglong)*(ushort *)(param_3 + 0xc));
    if (iVar2 != 0) {
      return uVar1 - iVar2;
    }
  }
  return uVar1;
}

