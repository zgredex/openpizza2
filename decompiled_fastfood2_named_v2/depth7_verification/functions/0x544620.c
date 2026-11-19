// rea decompile_all
// name: FUN_00544620
// address: 0x544620
// body: available
// range: 0x544620-0x5446f2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint __fastcall FUN_00544620(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b378;
  local_c = ExceptionList;
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x38);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  *(undefined1 *)(param_1 + 0x54) = 0;
  local_4 = 0;
  if (*(char *)(param_1 + 0x53) == '\0') {
    LeaveCriticalSection(lpCriticalSection);
    ExceptionList = local_c;
    return 1;
  }
  *(undefined1 *)(param_1 + 0x53) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined1 *)(param_1 + 0x88) = 1;
  if (*(char *)(param_1 + 0x58) != '\0') {
    *(undefined1 *)(param_1 + 0x57) = 1;
  }
  iVar3 = *(int *)(param_1 + 0x28);
  piVar1 = *(int **)(iVar3 + 0x48);
  if (piVar1 == (int *)0x0) {
    uVar4 = 0x80070006;
  }
  else {
    iVar2 = (**(code **)(*piVar1 + 0x48))(piVar1);
    if (iVar2 < 0) {
      uVar4 = 0x80004005;
    }
    else {
      if (*(char *)(iVar3 + 0x34) != '\0') {
        FUN_00540f60(iVar3);
      }
      iVar3 = (**(code **)(**(int **)(iVar3 + 0x48) + 0x34))(*(int **)(iVar3 + 0x48),0);
      uVar4 = (-1 < iVar3) - 1 & 0x80004005;
    }
  }
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = local_c;
  return uVar4;
}

