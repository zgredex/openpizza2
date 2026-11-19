// rea decompile_all
// name: FUN_005448c0
// address: 0x5448c0
// body: available
// range: 0x5448c0-0x544991 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_005448c0(int param_1,int *param_2,byte *param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar1;
  byte bVar2;
  int iVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar3 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b3b8;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xa0);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  iVar3 = *(int *)(iVar3 + 0x98);
  local_4 = 0;
  if (iVar3 < 0) {
    LeaveCriticalSection(lpCriticalSection);
    ExceptionList = local_c;
    return iVar3;
  }
  if (param_2 == (int *)0x0) {
    LeaveCriticalSection(lpCriticalSection);
    ExceptionList = local_c;
    return -0x7ff8fffa;
  }
  piVar1 = *(int **)(*param_2 + 0x48);
  if (piVar1 == (int *)0x0) {
    bVar2 = 0;
  }
  else {
    param_1 = 0;
    iVar3 = (**(code **)(*piVar1 + 0x24))(piVar1,&param_1);
    if (iVar3 < 0) {
      bVar2 = 0;
    }
    else {
      bVar2 = (byte)param_1 & 1;
    }
  }
  *param_3 = bVar2;
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = local_c;
  return 0;
}

