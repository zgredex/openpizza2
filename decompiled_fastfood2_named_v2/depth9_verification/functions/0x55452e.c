// rea decompile_all
// name: CRT_FreeOsfHandle
// address: 0x55452e
// body: available
// range: 0x55452e-0x5545ac inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __cdecl CRT_FreeOsfHandle(uint param_1)

{
  int *piVar1;
  DWORD *pDVar2;
  int iVar3;
  DWORD nStdHandle;
  
                    /* Releases a CRT file slot and clears its std handle. */
  if (param_1 < DAT_00586d20) {
    iVar3 = (param_1 & 0x1f) * 0x24;
    piVar1 = (int *)((&DAT_00586c20)[(int)param_1 >> 5] + iVar3);
    if (((*(byte *)(piVar1 + 1) & 1) != 0) && (*piVar1 != -1)) {
      if (DAT_00576744 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_0055458a;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_0055458a:
      *(undefined4 *)((&DAT_00586c20)[(int)param_1 >> 5] + iVar3) = 0xffffffff;
      return 0;
    }
  }
  pDVar2 = FUN_00553606();
  *pDVar2 = 9;
  pDVar2 = FUN_0055360f();
  *pDVar2 = 0;
  return 0xffffffff;
}

