// rea decompile_all
// name: FUN_00556995
// address: 0x556995
// body: available
// range: 0x556995-0x556a1d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __cdecl FUN_00556995(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_00585970 == (FARPROC)0x0) {
    hModule = LoadLibraryA("user32.dll");
    if (hModule != (HMODULE)0x0) {
      DAT_00585970 = GetProcAddress(hModule,"MessageBoxA");
      if (DAT_00585970 != (FARPROC)0x0) {
        DAT_00585974 = GetProcAddress(hModule,"GetActiveWindow");
        DAT_00585978 = GetProcAddress(hModule,"GetLastActivePopup");
        goto LAB_005569e4;
      }
    }
    iVar1 = 0;
  }
  else {
LAB_005569e4:
    if (DAT_00585974 != (FARPROC)0x0) {
      iVar1 = (*DAT_00585974)();
      if ((iVar1 != 0) && (DAT_00585978 != (FARPROC)0x0)) {
        iVar1 = (*DAT_00585978)(iVar1);
      }
    }
    iVar1 = (*DAT_00585970)(iVar1,param_1,param_2,param_3);
  }
  return iVar1;
}

