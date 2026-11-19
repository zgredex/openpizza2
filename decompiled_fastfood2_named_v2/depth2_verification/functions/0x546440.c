// rea decompile_all
// name: Sound_UnlinkAndFreeBuffer
// address: 0x546440
// body: available
// range: 0x546440-0x54659f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int Sound_UnlinkAndFreeBuffer(int param_1,int *param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar1;
  LPCRITICAL_SECTION lpCriticalSection_00;
  void *this;
  int *piVar2;
  int iVar3;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
                    /* Depth-2 proposal batch 2/4. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b760;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xa0);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  iVar3 = *(int *)(param_1 + 0x98);
  local_4 = 0;
  if (iVar3 < 0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else if (param_2 == (int *)0x0) {
    LeaveCriticalSection(lpCriticalSection);
    iVar3 = -0x7ff8fffa;
  }
  else {
    piVar1 = (int *)*param_2;
    lpCriticalSection_00 = (LPCRITICAL_SECTION)piVar1[0xe];
    EnterCriticalSection(lpCriticalSection_00);
    *(undefined1 *)(piVar1 + 0x15) = 0;
    local_4._0_1_ = 1;
    if (*(char *)((int)piVar1 + 0x53) != '\0') {
      *(undefined1 *)((int)piVar1 + 0x53) = 0;
      piVar1[0x21] = 0;
      *(undefined1 *)(piVar1 + 0x22) = 1;
      if ((char)piVar1[0x16] != '\0') {
        *(undefined1 *)((int)piVar1 + 0x57) = 1;
      }
      this = (void *)piVar1[10];
      piVar2 = *(int **)((int)this + 0x48);
      if (piVar2 != (int *)0x0) {
        iVar3 = (**(code **)(*piVar2 + 0x48))(piVar2);
        if (-1 < iVar3) {
          if (*(char *)((int)this + 0x34) != '\0') {
            FUN_00540f60((int)this);
          }
          FUN_005445f0(this,0);
        }
      }
    }
    local_4 = (uint)local_4._1_3_ << 8;
    LeaveCriticalSection(lpCriticalSection_00);
    (**(code **)(*piVar1 + 4))(piVar1);
    SetEvent(*(HANDLE *)(param_1 + 0x48));
    if (*(int **)(param_1 + 0x6c) == param_2) {
      *(int *)(param_1 + 0x6c) = (*(int **)(param_1 + 0x6c))[1];
    }
    if (param_2[2] == 0) {
      *(int *)(param_1 + 100) = param_2[1];
    }
    else {
      *(int *)(param_2[2] + 4) = param_2[1];
    }
    if (param_2 == *(int **)(param_1 + 0x68)) {
      *(int *)(param_1 + 0x68) = param_2[2];
    }
    if (param_2[1] != 0) {
      *(int *)(param_2[1] + 8) = param_2[2];
    }
    *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + -1;
    FUN_0054dd78(param_2);
    LeaveCriticalSection(lpCriticalSection);
    iVar3 = 0;
  }
  ExceptionList = local_c;
  return iVar3;
}

