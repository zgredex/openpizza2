// rea decompile_all
// name: Record_SelectVariant
// address: 0x533aa0
// body: available
// range: 0x533aa0-0x533aef inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


bool __thiscall Record_SelectVariant(void *this,int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
                    /* Selects and applies a sprite variant for a render record. */
  piVar1 = (int *)(*(int *)((int)this + 0x4c) + param_1 * 0x48);
  if ((*(char *)((int)piVar1 + 0x3e) == '\x01') && (param_2 == *piVar1)) {
    return true;
  }
  if (param_2 != -1) {
    Record_AssignVariant(this,param_1,param_2);
  }
  iVar2 = FUN_00533af0(this,param_1,0,0);
  return iVar2 != 0;
}

