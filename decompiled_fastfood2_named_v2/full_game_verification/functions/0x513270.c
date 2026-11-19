// rea decompile_all
// name: Rating_StoreClampedScores
// address: 0x513270
// body: available
// range: 0x513270-0x5133b5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall Rating_StoreClampedScores(int param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  piVar1 = (int *)(param_1 + 0x264);
  lVar3 = __ftol();
  *piVar1 = (int)lVar3;
  lVar3 = __ftol();
  *(int *)(param_1 + 0x268) = (int)lVar3;
  lVar3 = __ftol();
  *(int *)(param_1 + 0x26c) = (int)lVar3;
  lVar3 = __ftol();
  *(int *)(param_1 + 0x270) = (int)lVar3;
  lVar3 = __ftol();
  *(int *)(param_1 + 0x274) = (int)lVar3;
  lVar3 = __ftol();
  *(int *)(param_1 + 0x278) = (int)lVar3;
  lVar3 = __ftol();
  *(int *)(param_1 + 0x27c) = (int)lVar3;
  lVar3 = __ftol();
  *(int *)(param_1 + 0x280) = (int)lVar3;
  iVar2 = 8;
  do {
    if (*piVar1 < 0) {
      *piVar1 = 0;
    }
    if (100 < *piVar1) {
      *piVar1 = 100;
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

