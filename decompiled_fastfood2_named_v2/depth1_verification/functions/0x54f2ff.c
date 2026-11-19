// rea decompile_all
// name: FUN_0054f2ff
// address: 0x54f2ff
// body: available
// range: 0x54f2ff-0x54f3a1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Ghidra Listing reports a terminal call at 0x54f39c to EXTERNAL:0x40 KERNEL32.DLL::ExitProcess (external=true, thunk=false, hasNoReturn=true); fallthrough is excluded by Ghidra's flow model. This records Ghidra's FunctionManager flag, not an independent verification that the callee cannot return.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0054f2ff(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;
  
  FUN_0054f3a4();
  if (DAT_00585650 == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_0058564c = 1;
  DAT_00585648 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_00586d34 != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_00586d30 - 4), DAT_00586d34 <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_00586d34 <= puVar1);
    }
    FUN_0054f3b6((undefined4 *)&DAT_00563048,(undefined4 *)&DAT_00563050);
  }
  FUN_0054f3b6((undefined4 *)&DAT_00563054,(undefined4 *)&DAT_0056305c);
  if (param_3 == 0) {
    DAT_00585650 = 1;
                    /* WARNING: Subroutine does not return */
    ExitProcess(param_1);
  }
  CRT_UnlockExit();
  return;
}

