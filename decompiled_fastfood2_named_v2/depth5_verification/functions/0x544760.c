// rea decompile_all
// name: FUN_00544760
// address: 0x544760
// body: available
// range: 0x544760-0x54483e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_00544760(uint param_1,int *param_2,uint *param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  int *piVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  uVar5 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b398;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xa0);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  puVar3 = param_3;
  local_4 = 0;
  *param_3 = 0;
  iVar1 = *(int *)(uVar5 + 0x98);
  if (iVar1 < 0) {
    LeaveCriticalSection(lpCriticalSection);
    ExceptionList = local_c;
    return iVar1;
  }
  if (param_2 == (int *)0x0) {
    LeaveCriticalSection(lpCriticalSection);
    ExceptionList = local_c;
    return -0x7ff8fffa;
  }
  iVar1 = *param_2;
  piVar2 = *(int **)(iVar1 + 0x48);
  uVar5 = 0;
  if (piVar2 != (int *)0x0) {
    iVar4 = (**(code **)(*piVar2 + 0x10))(piVar2,&param_1,&param_3);
    uVar5 = param_1 & (iVar4 < 0) - 1;
  }
  *puVar3 = uVar5 / *(ushort *)(iVar1 + 0x24);
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = local_c;
  return 0;
}

