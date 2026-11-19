// rea decompile_all
// name: Media_QueryFlagLocked
// address: 0x5449a0
// body: available
// range: 0x5449a0-0x544aa5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int Media_QueryFlagLocked(int param_1,LPCRITICAL_SECTION param_2,byte *param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  PRTL_CRITICAL_SECTION_DEBUG p_Var1;
  LPCRITICAL_SECTION lpCriticalSection_00;
  _LIST_ENTRY *p_Var2;
  int iVar3;
  byte bVar4;
  code *pcVar5;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar3 = param_1;
                    /* Leaf reversal proposal batch 4. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b3e0;
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
  if (param_2 == (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(lpCriticalSection);
    ExceptionList = local_c;
    return -0x7ff8fffa;
  }
  p_Var1 = param_2->DebugInfo;
  lpCriticalSection_00 = (LPCRITICAL_SECTION)p_Var1[1].Flags;
  param_2 = lpCriticalSection_00;
  EnterCriticalSection(lpCriticalSection_00);
  pcVar5 = LeaveCriticalSection_exref;
  local_4 = CONCAT31(local_4._1_3_,1);
  if (*(char *)((int)&p_Var1[2].EntryCount + 3) == '\0') {
    LeaveCriticalSection(lpCriticalSection_00);
    bVar4 = 0;
  }
  else {
    p_Var2 = p_Var1[1].ProcessLocksList.Flink[9].Flink;
    if (p_Var2 == (_LIST_ENTRY *)0x0) {
      bVar4 = 0;
    }
    else {
      param_1 = 0;
      iVar3 = (*(code *)p_Var2->Flink[4].Blink)(p_Var2,&param_1);
      if (iVar3 < 0) {
        bVar4 = 0;
      }
      else {
        bVar4 = (byte)param_1 & 1;
      }
    }
    pcVar5 = LeaveCriticalSection_exref;
    LeaveCriticalSection(lpCriticalSection_00);
  }
  *param_3 = bVar4;
  (*pcVar5)(lpCriticalSection);
  ExceptionList = lpCriticalSection;
  return 0;
}

