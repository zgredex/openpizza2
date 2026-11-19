// rea decompile_all
// name: File_WriteBytes
// address: 0x54db85
// body: available
// range: 0x54db85-0x54dbda inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall File_WriteBytes(void *this,undefined1 *param_1,int param_2)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  if (param_2 != 0) {
    do {
      param_2 = param_2 + -1;
      if ((*(int *)((int)this + 8) == 0) &&
         (*(undefined1 **)((int)this + 0x1c) < *(undefined1 **)((int)this + 0x20))) {
        **(undefined1 **)((int)this + 0x1c) = *param_1;
        *(int *)((int)this + 0x1c) = *(int *)((int)this + 0x1c) + 1;
      }
      else {
        iVar1 = (**(code **)(*(int *)this + 0x1c))(*param_1);
        if (iVar1 == -1) {
          return local_8;
        }
      }
      param_1 = param_1 + 1;
      local_8 = local_8 + 1;
    } while (param_2 != 0);
  }
  return local_8;
}

