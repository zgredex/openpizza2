// rea decompile_all
// name: Sound_StopThread
// address: 0x54c4f0
// body: available
// range: 0x54c4f0-0x54c5a0 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall Sound_StopThread(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  LPVOID pvVar3;
  undefined1 *puVar4;
  
  if ((HANDLE)param_1[4] != (HANDLE)0x0) {
    SetEvent((HANDLE)param_1[4]);
    if (param_1[6] != 0) {
      iVar1 = param_1[5];
      while (iVar1 == 0) {
        Sleep(10);
        iVar1 = param_1[5];
      }
    }
    CloseHandle((HANDLE)param_1[4]);
    param_1[4] = 0;
  }
  piVar2 = (int *)param_1[9];
  if (piVar2 != (int *)0x0) {
    List_FreeValuesAndObject(piVar2);
    Mem_Free(piVar2);
    param_1[9] = 0;
  }
  pvVar3 = (LPVOID)param_1[1];
  if (pvVar3 != (LPVOID)0x0) {
    Sound_DestroyObject((int)pvVar3);
    Mem_Free(pvVar3);
    param_1[1] = 0;
  }
  puVar4 = (undefined1 *)*param_1;
  if (puVar4 != (undefined1 *)0x0) {
    Sound_DestroyAllChannels(puVar4);
    Mem_Free(puVar4);
    *param_1 = 0;
  }
  if ((undefined4 *)param_1[7] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[7])(1);
    param_1[7] = 0;
  }
  if ((undefined4 *)param_1[8] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[8])(1);
    param_1[8] = 0;
  }
  return;
}

