// rea decompile_all
// name: FUN_00538a80
// address: 0x538a80
// body: available
// range: 0x538a80-0x538ae0 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00538a80(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  
  *param_1 = &PTR_Renderer_Delete_0055c818;
  *(undefined1 *)(param_1 + 0xc) = 0;
  piVar2 = (int *)param_1[0x14];
  while (piVar2 != (int *)0x0) {
    FUN_00539e90(*piVar2);
    piVar1 = (int *)piVar2[1];
    FUN_0054dd78(piVar2);
    piVar2 = piVar1;
  }
  param_1[0x14] = 0;
  FUN_005387d0(param_1);
  if ((void *)param_1[0x15] != (void *)0x0) {
    FUN_00539e20((void *)param_1[0x15],(int)param_1);
  }
  FUN_0054dd78((LPVOID)param_1[0x10]);
  param_1[0x10] = 0;
  return;
}

