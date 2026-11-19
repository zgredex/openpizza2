// rea decompile_all
// name: Surface_FillFF
// address: 0x534df0
// body: available
// range: 0x534df0-0x534e11 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall Surface_FillFF(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  
                    /* Fills a surface with 0xff bytes. */
  uVar1 = *(int *)(param_1 + 0x10) * *(int *)(param_1 + 8);
  puVar3 = *(undefined4 **)(param_1 + 0x14);
  for (uVar2 = (uVar1 & 0x7fffffff) >> 1; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar3 = 0xffffffff;
    puVar3 = puVar3 + 1;
  }
  for (uVar1 = uVar1 * 2 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *(undefined1 *)puVar3 = 0xff;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  }
  return;
}

