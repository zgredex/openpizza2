// rea decompile_all
// name: SoundBuffer_StopPlayback
// address: 0x5445a0
// body: available
// range: 0x5445a0-0x5445ec inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint __fastcall SoundBuffer_StopPlayback(int param_1)

{
  int *piVar1;
  int iVar2;
  
                    /* Depth-2 proposal batch 2/4. */
  piVar1 = *(int **)(param_1 + 0x48);
  if (piVar1 == (int *)0x0) {
    return 0x80070006;
  }
  iVar2 = (**(code **)(*piVar1 + 0x48))(piVar1);
  if (iVar2 < 0) {
    return 0x80004005;
  }
  if (*(char *)(param_1 + 0x34) != '\0') {
    FUN_00540f60(param_1);
  }
  iVar2 = (**(code **)(**(int **)(param_1 + 0x48) + 0x34))(*(int **)(param_1 + 0x48),0);
  return (-1 < iVar2) - 1 & 0x80004005;
}

