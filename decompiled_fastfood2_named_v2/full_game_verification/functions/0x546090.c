// rea decompile_all
// name: Sound_CreateAndEnqueueBuffer
// address: 0x546090
// body: available
// range: 0x546090-0x54621f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int Sound_CreateAndEnqueueBuffer(int param_1,int *param_2,undefined4 *param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined1 uStack00000000;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  iVar6 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b6fb;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xa0);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  piVar1 = param_2;
  local_4 = 0;
  if (*(int *)(iVar6 + 0x98) < 0) {
    iVar6 = *(int *)(iVar6 + 0x98);
  }
  else {
    if (param_2 == (int *)0x0) {
      LeaveCriticalSection(lpCriticalSection);
      ExceptionList = local_c;
      return -0x7ff8fffa;
    }
    param_1 = 0;
    *param_3 = 0;
    piVar2 = operator_new(0xb4);
    local_4._0_1_ = 1;
    param_2 = piVar2;
    if (piVar2 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar3 = *(int **)(iVar6 + 0xc);
      if (piVar3 == (int *)0x0) {
        piVar3 = (int *)0x0;
      }
      else {
        (**(code **)(*piVar3 + 4))(piVar3);
        piVar3 = *(int **)(iVar6 + 0xc);
      }
      iVar4 = *piVar1;
      SoundBuffer_Construct(piVar2,piVar3,iVar4,&param_1);
      local_4._0_1_ = 2;
      piVar2[0x2b] = 0;
      piVar2[0x2c] = *(int *)(iVar4 + 0xb0);
      *piVar2 = (int)&PTR_LAB_0055c8b0;
      if (((-1 < param_1) &&
          (iVar4 = (*(code *)**(undefined4 **)piVar2[0x17])
                             ((undefined4 *)piVar2[0x17],&DAT_0055cb78,piVar2 + 0x2b), iVar4 < 0))
         && (&uStack00000000 != (undefined1 *)0xfffffffc)) {
        param_1 = iVar4;
      }
    }
    local_4 = (uint)local_4._1_3_ << 8;
    if (param_1 < 0) {
      (**(code **)(*piVar2 + 4))(piVar2);
    }
    else {
      puVar5 = operator_new(0xc);
      if (puVar5 == (undefined4 *)0x0) {
        (**(code **)(*piVar2 + 4))(piVar2);
        LeaveCriticalSection(lpCriticalSection);
        ExceptionList = local_c;
        return -0x7ff8fff2;
      }
      *puVar5 = piVar2;
      puVar5[2] = 0;
      puVar5[1] = *(undefined4 *)(iVar6 + 0x54);
      if (*(int *)(iVar6 + 0x54) != 0) {
        *(undefined4 **)(*(int *)(iVar6 + 0x54) + 8) = puVar5;
      }
      if (*(int *)(iVar6 + 0x5c) == *(int *)(iVar6 + 0x54)) {
        *(undefined4 **)(iVar6 + 0x5c) = puVar5;
      }
      *(undefined4 **)(iVar6 + 0x54) = puVar5;
      if (*(int *)(iVar6 + 0x58) == 0) {
        *(undefined4 **)(iVar6 + 0x58) = puVar5;
      }
      *(int *)(iVar6 + 0x60) = *(int *)(iVar6 + 0x60) + 1;
      *param_3 = puVar5;
    }
    iVar6 = param_1;
  }
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = local_c;
  return iVar6;
}

