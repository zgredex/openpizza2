// rea decompile_all
// name: FUN_00544300
// address: 0x544300
// body: available
// range: 0x544300-0x544472 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint FUN_00544300(uint param_1,int *param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  LPCRITICAL_SECTION lpCriticalSection_00;
  uint uVar5;
  uint uVar6;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b338;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xa0);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  uVar5 = *(uint *)(param_1 + 0x98);
  local_4 = 0;
  if ((int)uVar5 < 0) {
    LeaveCriticalSection(lpCriticalSection);
    param_1 = uVar5;
  }
  else if (param_2 == (int *)0x0) {
    LeaveCriticalSection(lpCriticalSection);
    param_1 = 0x80070006;
  }
  else {
    iVar1 = *param_2;
    uVar5 = (uint)(param_3 * 10000) / *(uint *)(param_1 + 0x84);
    EnterCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x18));
    local_4._0_1_ = 1;
    param_1 = 0;
    *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar1 + 8);
LAB_005443a6:
    piVar2 = *(int **)(iVar1 + 0x10);
    if (piVar2 != (int *)0x0) {
      *(int *)(iVar1 + 0x10) = piVar2[1];
      iVar3 = *piVar2;
      iVar4 = *(int *)(iVar3 + 0xc);
      if ((iVar4 != 0) && (iVar4 != 1)) goto code_r0x005443c4;
      uVar6 = Sound_SetBufferVolume(*(void **)(iVar3 + 8),uVar5);
      goto LAB_00544429;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x18));
    LeaveCriticalSection(lpCriticalSection);
  }
  ExceptionList = local_c;
  return param_1;
code_r0x005443c4:
  if (iVar4 == 2) {
    iVar3 = *(int *)(iVar3 + 8);
    lpCriticalSection_00 = *(LPCRITICAL_SECTION *)(iVar3 + 0x38);
    EnterCriticalSection(lpCriticalSection_00);
    local_4._0_1_ = 2;
    *(uint *)(iVar3 + 0x78) = uVar5;
    if (*(int *)(iVar3 + 0x8c) == 0) {
      *(uint *)(iVar3 + 0x9c) = uVar5;
    }
    if (*(char *)(iVar3 + 0x53) == '\0') {
      local_4._0_1_ = 1;
      LeaveCriticalSection(lpCriticalSection_00);
    }
    else {
      uVar6 = Sound_SetBufferVolume(*(void **)(iVar3 + 0x28),uVar5);
      local_4._0_1_ = 1;
      LeaveCriticalSection(lpCriticalSection_00);
LAB_00544429:
      if (((int)uVar6 < 0) && (-1 < (int)param_1)) {
        param_1 = uVar6;
      }
    }
  }
  goto LAB_005443a6;
}

