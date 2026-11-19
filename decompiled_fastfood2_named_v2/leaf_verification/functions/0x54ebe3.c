// rea decompile_all
// name: FUN_0054ebe3
// address: 0x54ebe3
// body: available
// range: 0x54ebe3-0x54ec30 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_0054ebe3(undefined1 *param_1,undefined1 *param_2,int param_3,undefined *param_4)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  for (; param_1 < param_2; param_2 = param_2 + -param_3) {
    puVar2 = param_1;
    puVar3 = param_1;
    while (puVar3 = puVar3 + param_3, puVar3 <= param_2) {
      iVar1 = (*(code *)param_4)(puVar3,puVar2);
      if (0 < iVar1) {
        puVar2 = puVar3;
      }
    }
    Mem_Swap(puVar2,param_2,param_3);
  }
  return;
}

