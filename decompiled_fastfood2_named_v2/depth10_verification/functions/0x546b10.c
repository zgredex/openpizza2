// rea decompile_all
// name: FUN_00546b10
// address: 0x546b10
// body: available
// range: 0x546b10-0x546cce inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_00546b10(int param_1,int *param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar1;
  LPCRITICAL_SECTION lpCriticalSection_00;
  int iVar2;
  int *piVar3;
  int iVar4;
  byte bVar5;
  code *pcVar6;
  code *pcVar7;
  undefined4 unaff_EDI;
  int unaff_retaddr;
  int *piVar8;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  pcVar6 = EnterCriticalSection_exref;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b828;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xa0);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  iVar2 = *(int *)(param_1 + 0x98);
  local_4 = 0;
  if (iVar2 < 0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else if (param_2 == (int *)0x0) {
    LeaveCriticalSection(lpCriticalSection);
    iVar2 = -0x7ff8fffa;
  }
  else {
    piVar1 = (int *)*param_2;
    lpCriticalSection_00 = (LPCRITICAL_SECTION)piVar1[0xe];
    EnterCriticalSection(lpCriticalSection_00);
    pcVar7 = LeaveCriticalSection_exref;
    local_4._0_1_ = 1;
    if (*(char *)((int)piVar1 + 0x53) == '\0') {
      local_4 = (uint)local_4._1_3_ << 8;
      LeaveCriticalSection(lpCriticalSection_00);
    }
    else {
      piVar8 = *(int **)(piVar1[10] + 0x48);
      if (piVar8 == (int *)0x0) {
        bVar5 = 0;
      }
      else {
        param_2 = (int *)0x0;
        iVar2 = (**(code **)(*piVar8 + 0x24))(piVar8,&param_2);
        if (iVar2 < 0) {
          bVar5 = 0;
        }
        else {
          bVar5 = (byte)param_2 & 1;
        }
      }
      pcVar7 = LeaveCriticalSection_exref;
      local_4 = (uint)local_4._1_3_ << 8;
      LeaveCriticalSection(lpCriticalSection_00);
      if (bVar5 != 0) {
        LeaveCriticalSection(lpCriticalSection);
        ExceptionList = local_c;
        return 1;
      }
      pcVar6 = EnterCriticalSection_exref;
    }
    piVar8 = piVar1;
    (**(code **)*piVar1)(piVar1);
    iVar2 = unaff_retaddr + 0x30;
    (*pcVar6)(iVar2);
    piVar3 = operator_new(0xc);
    if (piVar3 != (int *)0x0) {
      *piVar3 = (int)piVar1;
      iVar4 = FUN_00546f00((void *)(local_4 + 0x20),(int)piVar3,'\0');
      if (iVar4 != 0) {
        (*pcVar7)(iVar2);
        *(undefined1 *)(piVar1 + 0x14) = 1;
        iVar2 = piVar1[0xe];
        local_4 = iVar2;
        (*pcVar6)(iVar2);
        *(undefined1 *)(piVar1 + 0x15) = 1;
        if ((char)local_4 == '\0') {
          *(undefined1 *)((int)piVar1 + 0x52) = 0;
        }
        else {
          *(undefined1 *)((int)piVar1 + 0x52) = 1;
        }
        if (*(char *)((int)piVar1 + 0x53) == '\0') {
          if (*(char *)((int)piVar1 + 0x51) == '\0') {
            (*pcVar7)(iVar2);
            iVar4 = -0x7fffbffb;
          }
          else {
            (*pcVar7)(iVar2);
            iVar4 = 0;
          }
        }
        else {
          *(char *)(piVar1[0xb] + 0x34) = (char)local_4;
          iVar4 = FUN_00541210(*(int **)(piVar1[10] + 0x48),'\x01');
          (*pcVar7)(iVar2);
        }
        SetEvent(lpCriticalSection_00[3].DebugInfo);
        (*pcVar7)(piVar8);
        ExceptionList = local_c;
        return iVar4;
      }
    }
    (*pcVar7)(iVar2);
    (**(code **)(*piVar1 + 4))(piVar1);
    (*pcVar7)(unaff_EDI);
    iVar2 = -0x7ff8fff2;
  }
  ExceptionList = local_c;
  return iVar2;
}

