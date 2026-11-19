// rea decompile_all
// name: List_ContainerDestruct
// address: 0x545b20
// body: available
// range: 0x545b20-0x545bc8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall List_ContainerDestruct(undefined4 *param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *puVar1;
  LPVOID pvVar2;
  LPVOID pvVar3;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0055b686;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_LAB_0055cb04;
  local_4 = 0;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 6);
  EnterCriticalSection(lpCriticalSection);
  local_4._0_1_ = 3;
  param_1[4] = param_1[2];
  while (puVar1 = (undefined4 *)param_1[4], puVar1 != (undefined4 *)0x0) {
    param_1[4] = puVar1[1];
    (**(code **)(*(int *)*puVar1 + 4))((int *)*puVar1);
  }
  LeaveCriticalSection(lpCriticalSection);
  DeleteCriticalSection(lpCriticalSection);
  local_4 = (uint)local_4._1_3_ << 8;
  pvVar3 = (LPVOID)param_1[2];
  while (pvVar3 != (LPVOID)0x0) {
    pvVar2 = *(LPVOID *)((int)pvVar3 + 4);
    Mem_Free(pvVar3);
    pvVar3 = pvVar2;
  }
  param_1[2] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  *param_1 = &PTR_LAB_0055c840;
  ExceptionList = pvStack_c;
  return;
}

