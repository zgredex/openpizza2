// rea decompile_all
// name: FUN_004d2200
// address: 0x4d2200
// body: available
// range: 0x4d2200-0x4d2273 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_004d2200(undefined4 *param_1)

{
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00558d56;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_MapObject_Delete_0055c4ec;
  local_4 = 1;
  if ((param_1[1] == 0x1b) && ((undefined4 *)param_1[0x1d] != (undefined4 *)0x0)) {
    (*(code *)**(undefined4 **)param_1[0x1d])(1);
    param_1[0x1d] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00401480(param_1 + 0x1e);
  local_4 = 0xffffffff;
  FUN_00401480(param_1 + 0x16);
  ExceptionList = pvStack_c;
  return;
}

