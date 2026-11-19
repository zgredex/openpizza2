// rea decompile_all
// name: Game_GetNestedArrayEntry
// address: 0x4eac30
// body: available
// range: 0x4eac30-0x4eac75 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall Game_GetNestedArrayEntry(void *this,int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* Depth-1 proposal batch 3/4. */
  if (param_1 < 0) {
    return 0;
  }
  if (*(int *)((int)this + param_1 * 0x48 + 0x68) == 0) {
    return 0;
  }
  iVar1 = FUN_004eac00(this,param_1);
  if (param_2 < iVar1) {
    uVar2 = FUN_004017f0(*(void **)((int)this + param_1 * 0x48 + 0x68),param_2,(int *)0x0);
    return uVar2;
  }
  return 0;
}

