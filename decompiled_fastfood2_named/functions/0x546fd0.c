// rea decompile_all
// name: FUN_00546fd0
// address: 0x546fd0
// body: available
// range: 0x546fd0-0x54702b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_00546fd0(void *this,int param_1,int param_2)

{
  DWORD DVar1;
  int iVar2;
  
  DVar1 = GetCurrentThreadId();
  if (*(DWORD *)this != DVar1) {
    DVar1 = timeGetTime();
    FUN_0054f0d5(DVar1);
    DVar1 = GetCurrentThreadId();
    *(DWORD *)this = DVar1;
  }
  iVar2 = _rand();
  iVar2 = iVar2 * ((param_2 - param_1) + 1);
  iVar2 = ((int)(iVar2 + (iVar2 >> 0x1f & 0x7fffU)) >> 0xf) + param_1;
  if (iVar2 < param_1) {
    return param_1;
  }
  if (param_2 < iVar2) {
    iVar2 = param_2;
  }
  return iVar2;
}

