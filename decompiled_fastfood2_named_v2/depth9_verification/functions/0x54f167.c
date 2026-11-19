// rea decompile_all
// name: FUN_0054f167
// address: 0x54f167
// body: available
// range: 0x54f167-0x54f1dd inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


HANDLE __cdecl FUN_0054f167(int param_1,SIZE_T param_2,int param_3)

{
  int *lpThreadId;
  HANDLE hThread;
  DWORD DVar1;
  
  DVar1 = 0;
  lpThreadId = CRT_Calloc(1,0x74);
  if (lpThreadId != (int *)0x0) {
    FUN_00552385((int)lpThreadId);
    lpThreadId[0x12] = param_1;
    lpThreadId[0x13] = param_3;
    hThread = CreateThread((LPSECURITY_ATTRIBUTES)0x0,param_2,FUN_0054f1de,lpThreadId,4,
                           (LPDWORD)lpThreadId);
    lpThreadId[1] = (int)hThread;
    if ((hThread != (HANDLE)0x0) && (DVar1 = ResumeThread(hThread), DVar1 != 0xffffffff)) {
      return hThread;
    }
    DVar1 = GetLastError();
  }
  FUN_00551005(lpThreadId);
  if (DVar1 != 0) {
    FUN_00553593(DVar1);
  }
  return (HANDLE)0xffffffff;
}

