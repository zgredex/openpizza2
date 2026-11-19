// rea decompile_all
// name: CRT_LockFileHandle
// address: 0x5545ef
// body: available
// range: 0x5545ef-0x55464d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl CRT_LockFileHandle(uint param_1)

{
  int iVar1;
  int iVar2;
  
                    /* Acquires the per-file-handle CRT critical section, creating it lazily. */
  iVar2 = (param_1 & 0x1f) * 0x24;
  iVar1 = (&DAT_00586c20)[(int)param_1 >> 5] + iVar2;
  if (*(int *)(iVar1 + 8) == 0) {
    CRT_Lock(0x11);
    if (*(int *)(iVar1 + 8) == 0) {
      InitializeCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0xc));
      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
    }
    FUN_005539be(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)((&DAT_00586c20)[(int)param_1 >> 5] + 0xc + iVar2));
  return;
}

