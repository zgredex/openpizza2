// rea decompile_all
// name: FUN_00547de0
// address: 0x547de0
// body: available
// range: 0x547de0-0x547e69 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00547de0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x104);
  *(undefined4 *)(param_1 + 0x104) = 0;
  if (*(char *)(param_1 + 0xfc) == '\0') {
    return;
  }
  CS_Enter(param_1 + 0x178);
  if (iVar1 == 1) {
    (**(code **)(**(int **)(param_1 + 8) + 0x68))
              (*(int **)(param_1 + 8),*(undefined4 *)(param_1 + 0x80));
  }
  else if (iVar1 != 2) {
    if (iVar1 != 3) goto LAB_00547e5f;
    if (*(char *)(param_1 + 0xff) != '\0') {
      (**(code **)(**(int **)(param_1 + 8) + 0x54))
                (*(int **)(param_1 + 8),*(undefined4 *)(param_1 + 0x20));
      *(undefined1 *)(param_1 + 0xff) = 0;
    }
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  if (*(int *)(param_1 + 0x1d4) == 0) {
    SoundBuffer_Release(param_1);
  }
LAB_00547e5f:
  CS_Leave(param_1 + 0x178);
  return;
}

