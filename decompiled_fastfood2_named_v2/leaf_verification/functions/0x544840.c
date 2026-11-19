// rea decompile_all
// name: SoundBuffer_GetFrequency
// address: 0x544840
// body: available
// range: 0x544840-0x5448be inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int SoundBuffer_GetFrequency(int param_1,int *param_2,undefined4 *param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  
                    /* Leaf reversal proposal batch 1. */
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xa0);
  EnterCriticalSection(lpCriticalSection);
  *param_3 = 0;
  iVar1 = *(int *)(param_1 + 0x98);
  if (iVar1 < 0) {
    LeaveCriticalSection(lpCriticalSection);
    return iVar1;
  }
  if (param_2 == (int *)0x0) {
    LeaveCriticalSection(lpCriticalSection);
    return -0x7ff8fffa;
  }
  if (*(char *)(*param_2 + 0x53) == '\0') {
    *param_3 = 0;
    LeaveCriticalSection(lpCriticalSection);
    return 0;
  }
  *param_3 = *(undefined4 *)(*param_2 + 0x84);
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}

