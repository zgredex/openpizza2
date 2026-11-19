// rea decompile_all
// name: FUN_004fc720
// address: 0x4fc720
// body: available
// range: 0x4fc720-0x4fc794 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_004fc720(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = 400;
  *param_1 = &PTR_FUN_0055c618;
  param_1[2] = 0;
  param_1[6] = 1;
  if (param_1[1] == 0) {
    do {
      if (iVar1 < 1) break;
      Sleep(10);
      iVar1 = iVar1 + -1;
      param_1[2] = 0;
    } while (param_1[1] == 0);
    if (param_1[1] == 0) {
      FUN_00403510();
    }
  }
  if ((undefined4 *)param_1[7] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[7])(1);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  return;
}

