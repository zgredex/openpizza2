// rea decompile_all
// name: CRT_SetOsfHandle
// address: 0x5544b2
// body: available
// range: 0x5544b2-0x55452d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __cdecl CRT_SetOsfHandle(uint param_1,HANDLE param_2)

{
  DWORD *pDVar1;
  int iVar2;
  DWORD nStdHandle;
  
                    /* Stores an OS handle into a free CRT file slot. */
  if (param_1 < DAT_00586d20) {
    iVar2 = (param_1 & 0x1f) * 0x24;
    if (*(int *)((&DAT_00586c20)[(int)param_1 >> 5] + iVar2) == -1) {
      if (DAT_00576744 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_0055450b;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,param_2);
      }
LAB_0055450b:
      *(HANDLE *)((&DAT_00586c20)[(int)param_1 >> 5] + iVar2) = param_2;
      return 0;
    }
  }
  pDVar1 = FUN_00553606();
  *pDVar1 = 9;
  pDVar1 = FUN_0055360f();
  *pDVar1 = 0;
  return 0xffffffff;
}

