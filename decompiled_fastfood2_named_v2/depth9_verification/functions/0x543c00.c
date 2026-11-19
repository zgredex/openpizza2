// rea decompile_all
// name: FUN_00543c00
// address: 0x543c00
// body: available
// range: 0x543c00-0x543d04 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_00543c00(int param_1,int *param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  undefined4 local_20;
  uint uStack_1c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b278;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xa0);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  iVar4 = *(int *)(param_1 + 0x98);
  local_4 = 0;
  if (-1 < iVar4) {
    if (param_2 == (int *)0x0) {
      LeaveCriticalSection(lpCriticalSection);
      ExceptionList = local_c;
      return -0x7ff8fffa;
    }
    iVar4 = *param_2;
    lVar5 = __ftol();
    uVar2 = (uint)lVar5;
    piVar1 = *(int **)(iVar4 + 0x48);
    local_20 = 0x14;
    iVar3 = (**(code **)(*piVar1 + 0xc))(piVar1,&local_20);
    if ((iVar3 < 0) || ((uStack_1c & 0xc) != 4)) {
      if ((uVar2 < 100) || (100000 < uVar2)) goto LAB_00543ccb;
    }
    else {
      if (uVar2 < *(uint *)(param_1 + 0x8c)) {
LAB_00543ccb:
        LeaveCriticalSection(lpCriticalSection);
        ExceptionList = local_c;
        return -0x7ff8ffa9;
      }
      if (*(uint *)(param_1 + 0x90) < uVar2) {
        LeaveCriticalSection(lpCriticalSection);
        ExceptionList = local_c;
        return -0x7ff8ffa9;
      }
    }
    iVar4 = FUN_005411c0(iVar4);
  }
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = local_c;
  return iVar4;
}

