// rea decompile_all
// name: Stream_BeginRead
// address: 0x54d612
// body: available
// range: 0x54d612-0x54d685 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __fastcall Stream_BeginRead(int *param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  
                    /* Depth-2 proposal batch 2/4. */
  if (*(int *)((int)param_1 + *(int *)(*param_1 + 4) + 0x34) < 0) {
    FUN_0054d35c((LPCRITICAL_SECTION)((int)param_1 + *(int *)(*param_1 + 4) + 0x38));
  }
  iVar1 = *(int *)(*param_1 + 4);
  uVar2 = *(uint *)(iVar1 + 8 + (int)param_1);
  if (uVar2 != 0) {
    *(uint *)((int)param_1 + iVar1 + 8) = uVar2 | 2;
    if (*(int *)((int)param_1 + *(int *)(*param_1 + 4) + 0x34) < 0) {
      FUN_0054d367((LPCRITICAL_SECTION)((int)param_1 + *(int *)(*param_1 + 4) + 0x38));
    }
    return 0;
  }
  piVar3 = *(int **)((int)param_1 + iVar1 + 0x20);
  if (piVar3 != (int *)0x0) {
    FUN_0054d736(piVar3);
  }
  iVar1 = *(int *)(*(int *)(*param_1 + 4) + 4 + (int)param_1);
  if (*(int *)(iVar1 + 0x30) < 0) {
    FUN_0054d35c((LPCRITICAL_SECTION)(iVar1 + 0x34));
  }
  return 1;
}

