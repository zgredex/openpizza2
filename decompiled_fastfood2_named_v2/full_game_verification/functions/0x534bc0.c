// rea decompile_all
// name: Record_AssignVariant
// address: 0x534bc0
// body: available
// range: 0x534bc0-0x534c26 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Record_AssignVariant(void *this,int param_1,int param_2)

{
  char cVar1;
  
                    /* Assigns a valid variant to a render record and re-applies it. */
  if (((-1 < param_2) && (param_2 < *(int *)((int)this + 100))) &&
     (*(char *)(*(int *)((int)this + 0x50) + 0x80 + param_2 * 0x98) != '\0')) {
    cVar1 = *(char *)(*(int *)((int)this + 0x4c) + 0x3e + param_1 * 0x48);
    if (cVar1 != '\0') {
      Record_ClearFlags48(this,param_1);
    }
    *(int *)(*(int *)((int)this + 0x4c) + param_1 * 0x48) = param_2;
    if (cVar1 != '\0') {
      Record_SelectVariant(this,param_1,-1);
    }
  }
  return;
}

