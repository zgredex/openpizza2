// rea decompile_all
// name: FUN_00545100
// address: 0x545100
// body: available
// range: 0x545100-0x545280 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_00545100(int param_1,char *param_2,undefined4 param_3,undefined4 *param_4)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  void *this;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  iVar1 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b593;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xa0);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  iVar4 = *(int *)(iVar1 + 0x98);
  local_4 = 0;
  param_1 = 0;
  if (iVar4 < 0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    *param_4 = 0;
    (**(code **)**(undefined4 **)(iVar1 + 0x9c))(*(undefined4 **)(iVar1 + 0x9c));
    this = operator_new(0xa0);
    local_4._0_1_ = 1;
    if (this == (void *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      iVar4 = *(int *)(iVar1 + 0x94);
      if ((iVar4 == 0) || ((iVar4 != 1 && (iVar4 != 2)))) {
        uVar6 = 8;
      }
      else {
        uVar6 = 4;
      }
      piVar3 = *(int **)(iVar1 + 0xc);
      if (piVar3 == (int *)0x0) {
        uVar2 = 0;
      }
      else {
        (**(code **)(*piVar3 + 4))(piVar3);
        uVar2 = *(undefined4 *)(iVar1 + 0xc);
      }
      piVar3 = FUN_00541d50(this,uVar2,uVar6,*(undefined4 *)(iVar1 + 0x9c),param_2,(char)param_3,
                            iVar1 + 0x30,&param_1);
    }
    local_4 = (uint)local_4._1_3_ << 8;
    if (piVar3 == (int *)0x0) {
      LeaveCriticalSection(lpCriticalSection);
      iVar4 = -0x7ff8fff2;
    }
    else {
      if (param_1 < 0) {
        (**(code **)(*piVar3 + 4))(piVar3);
      }
      else {
        puVar5 = operator_new(0xc);
        if (puVar5 == (undefined4 *)0x0) {
          (**(code **)(*piVar3 + 4))(piVar3);
          LeaveCriticalSection(lpCriticalSection);
          ExceptionList = local_c;
          return -0x7ff8fff2;
        }
        *puVar5 = piVar3;
        puVar5[2] = 0;
        puVar5[1] = *(undefined4 *)(iVar1 + 100);
        if (*(int *)(iVar1 + 100) != 0) {
          *(undefined4 **)(*(int *)(iVar1 + 100) + 8) = puVar5;
        }
        if (*(int *)(iVar1 + 0x6c) == *(int *)(iVar1 + 100)) {
          *(undefined4 **)(iVar1 + 0x6c) = puVar5;
        }
        *(undefined4 **)(iVar1 + 100) = puVar5;
        if (*(int *)(iVar1 + 0x68) == 0) {
          *(undefined4 **)(iVar1 + 0x68) = puVar5;
        }
        *(int *)(iVar1 + 0x70) = *(int *)(iVar1 + 0x70) + 1;
        *param_4 = puVar5;
      }
      iVar4 = param_1;
      LeaveCriticalSection(lpCriticalSection);
    }
  }
  ExceptionList = local_c;
  return iVar4;
}

