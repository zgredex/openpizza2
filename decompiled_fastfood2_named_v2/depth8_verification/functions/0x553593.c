// rea decompile_all
// name: CRT_MapWin32Error
// address: 0x553593
// body: available
// range: 0x553593-0x553605 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl CRT_MapWin32Error(uint param_1)

{
  DWORD *pDVar1;
  uint *puVar2;
  int iVar3;
  
                    /* Maps a Win32 error code to the corresponding CRT errno value. */
  pDVar1 = CRT_GetDosErrnoPtr();
  iVar3 = 0;
  *pDVar1 = param_1;
  puVar2 = &DAT_00576d08;
  do {
    if (param_1 == *puVar2) {
      pDVar1 = CRT_GetErrnoPtr();
      *pDVar1 = *(DWORD *)(iVar3 * 8 + 0x576d0c);
      return;
    }
    puVar2 = puVar2 + 2;
    iVar3 = iVar3 + 1;
  } while ((int)puVar2 < 0x576e70);
  if ((0x12 < param_1) && (param_1 < 0x25)) {
    pDVar1 = CRT_GetErrnoPtr();
    *pDVar1 = 0xd;
    return;
  }
  if ((param_1 < 0xbc) || (0xca < param_1)) {
    pDVar1 = CRT_GetErrnoPtr();
    *pDVar1 = 0x16;
    return;
  }
  pDVar1 = CRT_GetErrnoPtr();
  *pDVar1 = 8;
  return;
}

