// rea decompile_all
// name: CRT_Write
// address: 0x54ff6b
// body: available
// range: 0x54ff6b-0x54ffcf inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __cdecl CRT_Write(uint param_1,char *param_2,DWORD param_3)

{
  int iVar1;
  DWORD *pDVar2;
  
                    /* Writes bytes to a CRT file descriptor under the handle lock. */
  if ((param_1 < DAT_00586d20) &&
     ((*(byte *)((&DAT_00586c20)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    CRT_LockFileHandle(param_1);
    iVar1 = FUN_0054ffd0(param_1,param_2,param_3);
    FUN_0055464e(param_1);
    return iVar1;
  }
  pDVar2 = CRT_GetErrnoPtr();
  *pDVar2 = 9;
  pDVar2 = CRT_GetDosErrnoPtr();
  *pDVar2 = 0;
  return -1;
}

