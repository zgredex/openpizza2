// rea decompile_all
// name: UI_DestroyPanel
// address: 0x504a20
// body: available
// range: 0x504a20-0x504a82 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall UI_DestroyPanel(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0055a27c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_LAB_0055c668;
  local_4 = 1;
  UI_DestroyChildObject((int)param_1);
  local_4 = local_4 & 0xffffff00;
  List_Node_Destroy(param_1 + 0x4c);
  local_4 = 0xffffffff;
  List_Node_Destroy(param_1 + 0x45);
  ExceptionList = local_c;
  return;
}

