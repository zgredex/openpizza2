// rea decompile_all
// name: Ingredient_Construct
// address: 0x4e4770
// body: available
// range: 0x4e4770-0x4e47bf inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall Ingredient_Construct(void *this,undefined4 param_1)

{
                    /* Constructs an ingredient market record with default bounds and its ingredient
                       id. */
  *(undefined ***)this = &PTR_FUN_0055c5b8;
  FUN_004e4860(this,s_default_00570c48,1,1000,0xfa,0x14,10,0x3d70a3d7,0x3fffd70a,0,0,0,0,0,0);
  *(undefined1 *)((int)this + 0xa8) = 0;
  *(undefined4 *)((int)this + 0xd0) = param_1;
  return this;
}

