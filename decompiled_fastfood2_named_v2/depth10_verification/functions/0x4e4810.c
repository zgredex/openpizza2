// rea decompile_all
// name: FUN_004e4810
// address: 0x4e4810
// body: available
// range: 0x4e4810-0x4e4856 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined1 __fastcall FUN_004e4810(int param_1)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint local_10 [4];
  
  puVar2 = local_10;
  uVar1 = 1;
  iVar3 = 0;
  do {
    if (-1 < *(char *)((uVar1 & 0xff) + 200 + param_1)) {
      *puVar2 = uVar1;
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 1;
    }
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 4);
  uVar1 = FUN_004034d0(0,iVar3 - 1);
  return (char)local_10[uVar1];
}

