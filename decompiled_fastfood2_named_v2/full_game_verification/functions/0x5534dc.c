// rea decompile_all
// name: CRT_Terminate
// address: 0x5534dc
// body: available
// range: 0x5534dc-0x553523 inclusive
// range: 0x55352f-0x55353c inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Ghidra Listing reports a terminal call at 0x553538 to 0x555fd6 FUN_00555fd6 (external=false, thunk=false, hasNoReturn=false); fallthrough is excluded by Ghidra's flow model. The reason for the terminal flow is not established by this observation.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void CRT_Terminate(void)

{
  DWORD *pDVar1;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_0055ce60;
  puStack_10 = &LAB_00553be0;
  pvStack_14 = ExceptionList;
  local_8 = 0;
  ExceptionList = &pvStack_14;
  pDVar1 = CRT_GetThreadData();
  if (pDVar1[0x18] != 0) {
    local_8 = 1;
    pDVar1 = CRT_GetThreadData();
    (*(code *)pDVar1[0x18])();
  }
  local_8 = 0xffffffff;
  FUN_00555fd6();
  return;
}

