// rea decompile_all
// name: FUN_00533400
// address: 0x533400
// body: available
// range: 0x533400-0x5334c0 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00533400(int param_1)

{
  char *pcVar1;
  int *piVar2;
  int iVar3;
  
  if (*(char *)(param_1 + 0x34) != '\0') {
    FUN_00401320(0x584248);
    if (*(char *)(param_1 + 0x35) != '\0') {
      FUN_00401340(0x584248);
      return;
    }
    pcVar1 = operator_new(*(uint *)(param_1 + 0x40));
    piVar2 = FUN_00402290(*(void **)(param_1 + 0x44),*(char **)(param_1 + 0x38),0);
    if (piVar2 != (int *)0x0) {
      FUN_00540000(*(int *)(param_1 + 0x3c),(int)piVar2,0);
      FUN_00402750(*(void **)(param_1 + 0x44),pcVar1,*(uint *)(param_1 + 0x40),(int)piVar2);
      FUN_00402990(*(void **)(param_1 + 0x44),(int)piVar2);
    }
    iVar3 = 0;
    if (0 < *(int *)(param_1 + 0x68)) {
      do {
        if (*(int *)(*(int *)(param_1 + 0x30) + iVar3 * 4) == 0) {
          *(undefined4 *)(*(int *)(param_1 + 0x80) + iVar3 * 4) = 0;
        }
        else {
          *(char **)(*(int *)(param_1 + 0x80) + iVar3 * 4) = pcVar1;
        }
        pcVar1 = pcVar1 + *(int *)(*(int *)(param_1 + 0x30) + iVar3 * 4);
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(param_1 + 0x68));
    }
    *(undefined1 *)(param_1 + 0x35) = 1;
    FUN_00401340(0x584248);
  }
  return;
}

