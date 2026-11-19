// rea decompile_all
// name: Sound_DestroyAllChannels
// address: 0x54c910
// body: available
// range: 0x54c910-0x54c9e8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall Sound_DestroyAllChannels(undefined1 *param_1)

{
  LPVOID pvVar1;
  void *pvVar2;
  int iVar3;
  
  Sound_ShutdownThread(param_1);
  pvVar2 = *(void **)(param_1 + 0xc4);
  if (pvVar2 != (void *)0x0) {
    iVar3 = 0;
    if (0 < *(int *)((int)pvVar2 + 0x14)) {
      do {
        pvVar1 = (LPVOID)IDMap_Lookup(pvVar2,iVar3,(int *)0x0);
        Mem_Free(pvVar1);
        pvVar2 = *(void **)(param_1 + 0xc4);
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)((int)pvVar2 + 0x14));
    }
    if (*(undefined4 **)(param_1 + 0xc4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0xc4))(1);
    }
    *(undefined4 *)(param_1 + 0xc4) = 0;
  }
  pvVar2 = *(void **)(param_1 + 200);
  if (pvVar2 != (void *)0x0) {
    iVar3 = 0;
    if (0 < *(int *)((int)pvVar2 + 0x14)) {
      do {
        pvVar1 = (LPVOID)IDMap_Lookup(pvVar2,iVar3,(int *)0x0);
        Mem_Free(pvVar1);
        pvVar2 = *(void **)(param_1 + 200);
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)((int)pvVar2 + 0x14));
    }
    if (*(undefined4 **)(param_1 + 200) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 200))(1);
    }
    *(undefined4 *)(param_1 + 200) = 0;
  }
  if (*(HANDLE *)(param_1 + 0x98) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(param_1 + 0x98));
    *(undefined4 *)(param_1 + 0x98) = 0;
  }
  if (*(HANDLE *)(param_1 + 0x9c) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(param_1 + 0x9c));
    *(undefined4 *)(param_1 + 0x9c) = 0;
  }
  if (*(HANDLE *)(param_1 + 0x94) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(param_1 + 0x94));
    *(undefined4 *)(param_1 + 0x94) = 0;
  }
  return;
}

