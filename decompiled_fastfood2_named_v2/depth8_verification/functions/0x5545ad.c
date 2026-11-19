// rea decompile_all
// name: CRT_GetOsHandle
// address: 0x5545ad
// body: available
// range: 0x5545ad-0x5545ee inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __cdecl CRT_GetOsHandle(uint param_1)

{
  DWORD *pDVar1;
  
                    /* Returns the Win32 handle for a valid CRT file descriptor. */
  if ((param_1 < DAT_00586d20) &&
     ((*(byte *)((&DAT_00586c20)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    return *(undefined4 *)((&DAT_00586c20)[(int)param_1 >> 5] + (param_1 & 0x1f) * 0x24);
  }
  pDVar1 = CRT_GetErrnoPtr();
  *pDVar1 = 9;
  pDVar1 = CRT_GetDosErrnoPtr();
  *pDVar1 = 0;
  return 0xffffffff;
}

