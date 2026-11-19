// rea decompile_all
// name: SoundStream_CreateEntry
// address: 0x545d70
// body: available
// range: 0x545d70-0x545ebb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Removing unreachable block (ram,0x00545e30) */

int SoundStream_CreateEntry(int param_1,int *param_2,undefined4 *param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  void *this;
  int *piVar2;
  undefined4 *puVar3;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  iVar1 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b6a3;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xa0);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  param_1 = *(int *)(param_1 + 0x98);
  local_4 = 0;
  if (param_1 < 0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else if (param_2 == (int *)0x0) {
    LeaveCriticalSection(lpCriticalSection);
    param_1 = -0x7ff8fffa;
  }
  else {
    param_1 = 0;
    *param_3 = 0;
    this = operator_new(0x4c);
    local_4._0_1_ = 1;
    if (this == (void *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = *(int **)(iVar1 + 0xc);
      if (piVar2 == (int *)0x0) {
        piVar2 = (int *)0x0;
      }
      else {
        (**(code **)(*piVar2 + 4))(piVar2);
        piVar2 = *(int **)(iVar1 + 0xc);
      }
      piVar2 = SoundBuffer_Init(this,piVar2,*param_2);
    }
    local_4 = (uint)local_4._1_3_ << 8;
    puVar3 = operator_new(0xc);
    if (puVar3 == (undefined4 *)0x0) {
      (**(code **)(*piVar2 + 4))(piVar2);
      LeaveCriticalSection(lpCriticalSection);
      param_1 = -0x7ff8fff2;
    }
    else {
      *puVar3 = piVar2;
      puVar3[2] = 0;
      puVar3[1] = *(undefined4 *)(iVar1 + 0x54);
      if (*(int *)(iVar1 + 0x54) != 0) {
        *(undefined4 **)(*(int *)(iVar1 + 0x54) + 8) = puVar3;
      }
      if (*(int *)(iVar1 + 0x5c) == *(int *)(iVar1 + 0x54)) {
        *(undefined4 **)(iVar1 + 0x5c) = puVar3;
      }
      *(undefined4 **)(iVar1 + 0x54) = puVar3;
      if (*(int *)(iVar1 + 0x58) == 0) {
        *(undefined4 **)(iVar1 + 0x58) = puVar3;
      }
      *(int *)(iVar1 + 0x60) = *(int *)(iVar1 + 0x60) + 1;
      *param_3 = puVar3;
      LeaveCriticalSection(lpCriticalSection);
    }
  }
  ExceptionList = local_c;
  return param_1;
}

