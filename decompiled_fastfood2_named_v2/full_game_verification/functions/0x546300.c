// rea decompile_all
// name: Sound_StopStreamVoice
// address: 0x546300
// body: available
// range: 0x546300-0x54643e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int Sound_StopStreamVoice(int param_1,int *param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LPCRITICAL_SECTION lpCriticalSection_00;
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  LPVOID pvVar4;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b740;
  local_c = ExceptionList;
  lpCriticalSection_00 = (LPCRITICAL_SECTION)(param_1 + 0xa0);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection_00);
  iVar3 = *(int *)(param_1 + 0x98);
  local_4 = 0;
  if (iVar3 < 0) {
    LeaveCriticalSection(lpCriticalSection_00);
  }
  else if (param_2 == (int *)0x0) {
    LeaveCriticalSection(lpCriticalSection_00);
    iVar3 = -0x7ff8fffa;
  }
  else {
    iVar3 = *param_2;
    if ((*(int *)(iVar3 + 8) != 0) &&
       (puVar1 = *(undefined4 **)(iVar3 + 0xc), puVar1 != (undefined4 *)0x0)) {
      iVar2 = *(int *)(iVar3 + 8);
      lpCriticalSection = (LPCRITICAL_SECTION)(iVar2 + 0x18);
      EnterCriticalSection(lpCriticalSection);
      local_4._0_1_ = 1;
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)(*(int *)*puVar1 + 4))((int *)*puVar1);
        pvVar4 = (LPVOID)List_Remove((void *)(iVar2 + 8),(int)puVar1);
        Mem_Free(pvVar4);
      }
      local_4 = (uint)local_4._1_3_ << 8;
      LeaveCriticalSection(lpCriticalSection);
      *(undefined4 *)(iVar3 + 8) = 0;
      *(undefined4 *)(iVar3 + 0xc) = 0;
    }
    (**(code **)(*(int *)*param_2 + 4))((int *)*param_2);
    if (*(int **)(param_1 + 0x5c) == param_2) {
      *(int *)(param_1 + 0x5c) = (*(int **)(param_1 + 0x5c))[1];
    }
    if (param_2[2] == 0) {
      *(int *)(param_1 + 0x54) = param_2[1];
    }
    else {
      *(int *)(param_2[2] + 4) = param_2[1];
    }
    if (param_2 == *(int **)(param_1 + 0x58)) {
      *(int *)(param_1 + 0x58) = param_2[2];
    }
    if (param_2[1] != 0) {
      *(int *)(param_2[1] + 8) = param_2[2];
    }
    *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + -1;
    Mem_Free(param_2);
    LeaveCriticalSection(lpCriticalSection_00);
    iVar3 = 0;
  }
  ExceptionList = local_c;
  return iVar3;
}

