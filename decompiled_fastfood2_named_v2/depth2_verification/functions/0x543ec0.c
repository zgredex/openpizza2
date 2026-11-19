// rea decompile_all
// name: SoundStream_ScheduleRefill
// address: 0x543ec0
// body: available
// range: 0x543ec0-0x54402c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int SoundStream_ScheduleRefill(int param_1,int *param_2,undefined4 param_3,char param_4)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LPCRITICAL_SECTION lpCriticalSection_00;
  uint uVar1;
  DWORD DVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  ulonglong uVar6;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Depth-2 proposal batch 2/4. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b2d0;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xa0);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  iVar5 = *(int *)(param_1 + 0x98);
  local_4 = 0;
  if (iVar5 < 0) {
    LeaveCriticalSection(lpCriticalSection);
    ExceptionList = local_c;
    return iVar5;
  }
  if (param_2 == (int *)0x0) {
    LeaveCriticalSection(lpCriticalSection);
    ExceptionList = local_c;
    return -0x7ff8fffa;
  }
  iVar5 = *param_2;
  lpCriticalSection_00 = *(LPCRITICAL_SECTION *)(iVar5 + 0x38);
  EnterCriticalSection(lpCriticalSection_00);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (param_4 != '\0') {
    if (*(char *)(iVar5 + 0x53) != '\0') {
      FUN_005410b0(*(void **)(iVar5 + 0x28),0);
    }
    *(undefined4 *)(iVar5 + 0x9c) = 0;
  }
  pcVar4 = LeaveCriticalSection_exref;
  if (*(uint *)(iVar5 + 0x9c) < *(uint *)(iVar5 + 0x78)) {
    uVar1 = *(uint *)(iVar5 + 0x78) - *(uint *)(iVar5 + 0x9c);
    *(undefined4 *)(iVar5 + 0x8c) = 1;
    uVar3 = (int)uVar1 >> 0x1f;
    uVar1 = (int)((uVar1 ^ uVar3) - uVar3) / 100;
    if (uVar1 == 0) {
      *(undefined4 *)(iVar5 + 0x98) = 1;
    }
    else {
      uVar6 = __ftol();
      *(int *)(iVar5 + 0x98) = (int)((uVar6 & 0xffffffff) / (ulonglong)uVar1);
    }
    DVar2 = timeGetTime();
    *(DWORD *)(iVar5 + 0x90) = DVar2;
    *(DWORD *)(iVar5 + 0x94) = DVar2;
    pcVar4 = LeaveCriticalSection_exref;
    LeaveCriticalSection(lpCriticalSection_00);
    iVar5 = 0;
  }
  else {
    LeaveCriticalSection(lpCriticalSection_00);
    iVar5 = 1;
  }
  SetEvent(*(HANDLE *)(param_1 + 0x48));
  (*pcVar4)(lpCriticalSection);
  ExceptionList = lpCriticalSection;
  return iVar5;
}

