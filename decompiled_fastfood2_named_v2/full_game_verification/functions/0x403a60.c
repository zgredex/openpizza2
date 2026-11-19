// rea decompile_all
// name: Timer_Destroy
// address: 0x403a60
// body: available
// range: 0x403a60-0x403ab7 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall Timer_Destroy(undefined4 *param_1)

{
  int iVar1;
  DWORD DVar2;
  DWORD DVar3;
  
                    /* Stops the timer worker and releases its handles and lock. */
  *param_1 = &PTR_TimerClass_ScalarDeletingDestructor_0055c308;
  param_1[1] = 1;
  DVar2 = timeGetTime();
  iVar1 = param_1[2];
  while ((iVar1 == 0 && (DVar3 = timeGetTime(), DVar3 < DVar2 + 5000))) {
    Sleep(2);
    iVar1 = param_1[2];
  }
  CloseHandle((HANDLE)param_1[0x1b]);
  NamedLockable_Destroy(param_1 + 4);
  return;
}

