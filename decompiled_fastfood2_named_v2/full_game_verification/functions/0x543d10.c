// rea decompile_all
// name: SoundBuffer_CommitVolume
// address: 0x543d10
// body: available
// range: 0x543d10-0x543e89 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int SoundBuffer_CommitVolume(int param_1,int *param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LPCRITICAL_SECTION lpCriticalSection_00;
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  code *pcVar5;
  undefined4 unaff_EBP;
  code *pcVar6;
  longlong lVar7;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  pcVar5 = EnterCriticalSection_exref;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b2a8;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xa0);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  iVar4 = *(int *)(param_1 + 0x98);
  local_4 = 0;
  if (iVar4 < 0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    if (param_2 == (int *)0x0) {
      LeaveCriticalSection(lpCriticalSection);
      ExceptionList = local_c;
      return -0x7ff8fffa;
    }
    iVar4 = *param_2;
    lpCriticalSection_00 = *(LPCRITICAL_SECTION *)(iVar4 + 0x38);
    EnterCriticalSection(lpCriticalSection_00);
    pcVar6 = LeaveCriticalSection_exref;
    local_4 = CONCAT31(local_4._1_3_,1);
    if (*(char *)(iVar4 + 0x53) == '\0') {
      LeaveCriticalSection(lpCriticalSection_00);
    }
    else {
      iVar2 = Sound_QueryFormatType(*(int *)(iVar4 + 0x28));
      pcVar6 = LeaveCriticalSection_exref;
      local_4 = local_4 & 0xffffff00;
      LeaveCriticalSection(lpCriticalSection_00);
      lVar7 = __ftol();
      uVar3 = (uint)lVar7;
      if (iVar2 == 4) {
        if (uVar3 < *(uint *)(param_1 + 0x8c)) {
LAB_00543e13:
          LeaveCriticalSection(lpCriticalSection);
          ExceptionList = local_c;
          return -0x7ff8ffa9;
        }
        if (*(uint *)(param_1 + 0x90) < uVar3) {
          LeaveCriticalSection(lpCriticalSection);
          ExceptionList = local_c;
          return -0x7ff8ffa9;
        }
      }
      else if ((uVar3 < 100) || (100000 < uVar3)) goto LAB_00543e13;
      pcVar5 = EnterCriticalSection_exref;
    }
    uVar1 = *(undefined4 *)(iVar4 + 0x38);
    (*pcVar5)(uVar1);
    puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,2);
    *(undefined4 *)(iVar4 + 0x80) = uVar1;
    if (*(char *)(iVar4 + 0x53) == '\0') {
      (*pcVar6)(uVar1);
      iVar4 = 0;
    }
    else {
      iVar4 = SoundBuffer_SetVolume(*(int *)(iVar4 + 0x28));
      (*pcVar6)(uVar1);
    }
    SetEvent(*(HANDLE *)(local_4 + 0x48));
    (*pcVar6)(unaff_EBP);
  }
  ExceptionList = local_c;
  return iVar4;
}

