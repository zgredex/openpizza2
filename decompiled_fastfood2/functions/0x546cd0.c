// rea decompile_all
// name: FUN_00546cd0
// address: 0x546cd0
// body: available
// range: 0x546cd0-0x546ef8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_00546cd0(int param_1,int *param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar1;
  LPCRITICAL_SECTION p_Var2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  iVar3 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b858;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xa0);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  piVar4 = param_2;
  iVar6 = *(int *)(param_1 + 0x98);
  local_4 = 0;
  if (iVar6 < 0) {
LAB_00546edc:
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    if (param_2 == (int *)0x0) {
      LeaveCriticalSection(lpCriticalSection);
      ExceptionList = local_c;
      return -0x7ff8fffa;
    }
    piVar1 = (int *)*param_2;
    p_Var2 = (LPCRITICAL_SECTION)piVar1[0xe];
    EnterCriticalSection(p_Var2);
    local_4._0_1_ = 1;
    if (*(char *)((int)piVar1 + 0x53) == '\0') {
      local_4 = (uint)local_4._1_3_ << 8;
      LeaveCriticalSection(p_Var2);
    }
    else {
      piVar5 = *(int **)(piVar1[10] + 0x48);
      if (piVar5 == (int *)0x0) {
        param_1._0_1_ = 0;
      }
      else {
        param_2 = (int *)0x0;
        iVar6 = (**(code **)(*piVar5 + 0x24))(piVar5,&param_2);
        if (iVar6 < 0) {
          param_1._0_1_ = 0;
        }
        else {
          param_1._0_1_ = (byte)param_2 & 1;
        }
      }
      local_4 = (uint)local_4._1_3_ << 8;
      LeaveCriticalSection(p_Var2);
      if ((byte)param_1 != 0) {
        LeaveCriticalSection(lpCriticalSection);
        ExceptionList = local_c;
        return 1;
      }
    }
    *(undefined1 *)(piVar1 + 0x16) = 1;
    (**(code **)*piVar1)(piVar1);
    p_Var2 = (LPCRITICAL_SECTION)(iVar3 + 0x30);
    EnterCriticalSection(p_Var2);
    piVar5 = operator_new(0xc);
    if (piVar5 != (int *)0x0) {
      *piVar5 = (int)piVar1;
      iVar6 = FUN_00546f00((void *)(iVar3 + 0x20),(int)piVar5,'\0');
      if (iVar6 != 0) {
        LeaveCriticalSection(p_Var2);
        *(undefined1 *)(piVar1 + 0x14) = 1;
        (**(code **)(*piVar1 + 4))(piVar1);
        if (*(int **)(iVar3 + 0x6c) == piVar4) {
          *(int *)(iVar3 + 0x6c) = (*(int **)(iVar3 + 0x6c))[1];
        }
        if (piVar4[2] == 0) {
          *(int *)(iVar3 + 100) = piVar4[1];
        }
        else {
          *(int *)(piVar4[2] + 4) = piVar4[1];
        }
        if (piVar4 == *(int **)(iVar3 + 0x68)) {
          *(int *)(iVar3 + 0x68) = piVar4[2];
        }
        if (piVar4[1] != 0) {
          *(int *)(piVar4[1] + 8) = piVar4[2];
        }
        *(int *)(iVar3 + 0x70) = *(int *)(iVar3 + 0x70) + -1;
        FUN_0054dd78(piVar4);
        p_Var2 = (LPCRITICAL_SECTION)piVar1[0xe];
        EnterCriticalSection(p_Var2);
        *(undefined1 *)(piVar1 + 0x15) = 1;
        *(undefined1 *)((int)piVar1 + 0x52) = 0;
        local_4 = CONCAT31(local_4._1_3_,2);
        if (*(char *)((int)piVar1 + 0x53) == '\0') {
          if (*(char *)((int)piVar1 + 0x51) == '\0') {
            LeaveCriticalSection(p_Var2);
            iVar6 = -0x7fffbffb;
          }
          else {
            LeaveCriticalSection(p_Var2);
            iVar6 = 0;
          }
        }
        else {
          *(undefined1 *)(piVar1[0xb] + 0x34) = 0;
          iVar6 = FUN_00541210(*(int **)(piVar1[10] + 0x48),'\x01');
          LeaveCriticalSection(p_Var2);
        }
        SetEvent(*(HANDLE *)(iVar3 + 0x48));
        goto LAB_00546edc;
      }
    }
    LeaveCriticalSection(p_Var2);
    (**(code **)(*piVar1 + 4))(piVar1);
    LeaveCriticalSection(lpCriticalSection);
    iVar6 = -0x7ff8fff2;
  }
  ExceptionList = local_c;
  return iVar6;
}

