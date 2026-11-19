// rea decompile_all
// name: FUN_005427e0
// address: 0x5427e0
// body: available
// range: 0x5427e0-0x5428b2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_005427e0(undefined4 *param_1)

{
  LPVOID pvVar1;
  LPVOID pvVar2;
  undefined4 *puVar3;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0055b036;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_0055c8f0;
  local_4 = 1;
  *(undefined1 *)(param_1 + 0xd) = 1;
  if ((HANDLE)param_1[0xb] != (HANDLE)0x0) {
    SetEvent((HANDLE)param_1[0xb]);
    if ((HANDLE)param_1[0xc] != (HANDLE)0xffffffff) {
      WaitForSingleObject((HANDLE)param_1[0xc],0xffffffff);
    }
    CloseHandle((HANDLE)param_1[0xb]);
  }
  puVar3 = (undefined4 *)param_1[1];
  param_1[3] = puVar3;
  if (puVar3 != (undefined4 *)0x0) {
    param_1[3] = puVar3[1];
    while( true ) {
      (**(code **)(*(int *)*puVar3 + 4))((int *)*puVar3);
      puVar3 = (undefined4 *)param_1[3];
      if (puVar3 == (undefined4 *)0x0) break;
      param_1[3] = puVar3[1];
    }
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 5));
  local_4 = 0xffffffff;
  pvVar2 = (LPVOID)param_1[1];
  while (pvVar2 != (LPVOID)0x0) {
    pvVar1 = *(LPVOID *)((int)pvVar2 + 4);
    FUN_0054dd78(pvVar2);
    pvVar2 = pvVar1;
  }
  param_1[1] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  ExceptionList = pvStack_c;
  return;
}

