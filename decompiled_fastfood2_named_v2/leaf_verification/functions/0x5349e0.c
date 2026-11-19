// rea decompile_all
// name: RecordList_ReadSlot98
// address: 0x5349e0
// body: available
// range: 0x5349e0-0x534a2f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall RecordList_ReadSlot98(void *this,int param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  
                    /* Leaf reversal proposal batch 4. */
  if ((param_1 < 0) || (*(int *)((int)this + 100) <= param_1)) {
    *param_3 = 0;
    *(undefined2 *)(param_3 + 1) = 0;
  }
  else if ((-1 < param_2) && (param_2 < 0x10)) {
    puVar1 = (undefined4 *)(*(int *)((int)this + 0x50) + param_1 * 0x98 + param_2 * 6);
    *param_3 = *puVar1;
    *(undefined2 *)(param_3 + 1) = *(undefined2 *)(puVar1 + 1);
    return;
  }
  return;
}

