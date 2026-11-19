// rea decompile_all
// name: Object_Deactivate
// address: 0x50ab70
// body: available
// range: 0x50ab70-0x50abb0 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Object_Deactivate(void *this,void *param_1)

{
  byte *pbVar1;
  
                    /* Deactivates an object and detaches it. */
  if (*(char *)((int)this + 0x104) != '\0') {
    if (param_1 != (void *)0x0) {
      FUN_004d2960(param_1,this,0);
    }
    FUN_0050e710(this,0);
    FUN_0050e720(this,0);
    if (*(int *)((int)this + 200) != 0) {
      pbVar1 = (byte *)(*(int *)((int)this + 200) + 0x10);
      *pbVar1 = *pbVar1 & 0xfe;
    }
  }
  return;
}

