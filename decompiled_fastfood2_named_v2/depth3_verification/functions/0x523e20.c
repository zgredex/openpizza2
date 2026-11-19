// rea decompile_all
// name: FUN_00523e20
// address: 0x523e20
// body: available
// range: 0x523e20-0x523f0c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __fastcall FUN_00523e20(int param_1)

{
  int iVar1;
  int local_4;
  
  local_4 = param_1;
  if ((*(void **)(param_1 + 0x83ac) != (void *)0x0) && (*(int *)(param_1 + 0x83b8) != 0)) {
    UI_EnsureBackBufferWindow(*(void **)(param_1 + 0x83ac),*(void **)(param_1 + 0xc));
    return 1;
  }
  if (*(int *)(param_1 + 0x1b4) != 0) {
    iVar1 = FUN_00538f60(*(void **)(param_1 + 0xc));
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = *(int *)(*(int *)(param_1 + 0xc) + 0x40);
    if (iVar1 == 0) {
      FUN_00539180((int *)0x0);
      return 1;
    }
    FUN_00539180(*(int **)(iVar1 + 8));
    return 1;
  }
  if (*(void **)(param_1 + 0x1bc) != (void *)0x0) {
    FUN_005377d0(*(void **)(param_1 + 0x1bc),*(void **)(param_1 + 0xc));
    return 1;
  }
  if (*(int *)(param_1 + 0x1c0) == 0) {
    FUN_0048e0a0();
  }
  iVar1 = FUN_005390b0(*(void **)(param_1 + 0xc),*(int **)(param_1 + 0x1c0),&local_4);
  if (iVar1 == 0) {
    return 0;
  }
  FUN_005392e0(*(void **)(param_1 + 0xc),iVar1,(ushort)*(undefined4 *)(param_1 + 0x270),
               (ushort)*(undefined4 *)(param_1 + 0x274),local_4);
  FUN_00539180(*(int **)(param_1 + 0x1c0));
  return 1;
}

