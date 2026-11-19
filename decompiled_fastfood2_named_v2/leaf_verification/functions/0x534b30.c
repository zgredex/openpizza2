// rea decompile_all
// name: Animation_SetPointPairs
// address: 0x534b30
// body: available
// range: 0x534b30-0x534bb4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
Animation_SetPointPairs
          (void *this,int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
          undefined4 *param_5)

{
  int iVar1;
  
                    /* Leaf reversal proposal batch 1. */
  if (param_2 != (undefined4 *)0x0) {
    iVar1 = *(int *)((int)this + 0x50);
    *(undefined4 *)(iVar1 + 0x70 + param_1 * 0x98) = *param_2;
    *(undefined4 *)(iVar1 + 0x74 + param_1 * 0x98) = param_2[1];
  }
  if (param_3 != (undefined4 *)0x0) {
    iVar1 = *(int *)((int)this + 0x50);
    *(undefined4 *)(iVar1 + 0x78 + param_1 * 0x98) = *param_3;
    *(undefined4 *)(iVar1 + 0x7c + param_1 * 0x98) = param_3[1];
  }
  if (param_4 != (undefined4 *)0x0) {
    iVar1 = *(int *)((int)this + 0x50);
    *(undefined4 *)(iVar1 + 0x60 + param_1 * 0x98) = *param_4;
    *(undefined4 *)(iVar1 + 100 + param_1 * 0x98) = param_4[1];
  }
  if (param_5 != (undefined4 *)0x0) {
    iVar1 = *(int *)((int)this + 0x50);
    *(undefined4 *)(iVar1 + 0x68 + param_1 * 0x98) = *param_5;
    *(undefined4 *)(iVar1 + 0x6c + param_1 * 0x98) = param_5[1];
  }
  return;
}

