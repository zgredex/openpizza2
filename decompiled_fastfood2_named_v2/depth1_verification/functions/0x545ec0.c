// rea decompile_all
// name: Sound_CreateAndRegisterBuffer
// address: 0x545ec0
// body: available
// range: 0x545ec0-0x54608f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int Sound_CreateAndRegisterBuffer(int param_1,int *param_2,int *param_3)

{
  int *piVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  int *this;
  DWORD DVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  undefined1 uStack00000000;
  int local_18;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
                    /* Depth-1 proposal batch 2. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b6cb;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xa0);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  local_18 = *(int *)(param_1 + 0x98);
  local_4 = 0;
  if (-1 < local_18) {
    if (param_2 == (int *)0x0) {
      LeaveCriticalSection(lpCriticalSection);
      ExceptionList = local_c;
      return -0x7ff8fffa;
    }
    local_18 = 0;
    *param_3 = 0;
    this = operator_new(0xac);
    local_4._0_1_ = 1;
    if (this == (int *)0x0) {
      this = (int *)0x0;
    }
    else {
      piVar5 = *(int **)(param_1 + 0xc);
      if (piVar5 == (int *)0x0) {
        piVar5 = (int *)0x0;
      }
      else {
        (**(code **)(*piVar5 + 4))(piVar5);
        piVar5 = *(int **)(param_1 + 0xc);
      }
      FUN_00540960(this,piVar5,*param_2);
      piVar5 = this + 0x17;
      this[0x13] = 0;
      this[0x14] = 0;
      this[0x15] = 0;
      this[0x16] = 0;
      local_4._0_1_ = 2;
      *piVar5 = 0;
      *(undefined1 *)(this + 0x28) = 0;
      *(undefined1 *)((int)this + 0xa1) = 0;
      DVar2 = timeGetTime();
      this[0x29] = DVar2;
      this[0x2a] = DVar2;
      *this = (int)&PTR_LAB_0055c8c8;
      iVar3 = (*(code *)**(undefined4 **)this[0x12])((undefined4 *)this[0x12],&DAT_0055cb88,piVar5);
      if (iVar3 < 0) {
        *piVar5 = 0;
      }
      else {
        piVar1 = this + 0x18;
        piVar7 = piVar1;
        for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
          *piVar7 = 0;
          piVar7 = piVar7 + 1;
        }
        *piVar1 = 0x40;
        (**(code **)(*(int *)*piVar5 + 0xc))((int *)*piVar5,piVar1);
      }
      this[0x14] = this[0x14] | 3;
      if (&uStack00000000 != (undefined1 *)0x18) {
        local_18 = iVar3;
      }
    }
    local_4 = (uint)local_4._1_3_ << 8;
    if (-1 < local_18) {
      puVar4 = operator_new(0xc);
      if (puVar4 != (undefined4 *)0x0) {
        *puVar4 = this;
        iVar3 = FUN_00546f00((void *)(param_1 + 0x54),(int)puVar4,'\0');
        if (iVar3 != 0) {
          *param_3 = iVar3;
          goto LAB_00546073;
        }
      }
      (**(code **)(*this + 4))(this);
      LeaveCriticalSection(lpCriticalSection);
      ExceptionList = local_c;
      return -0x7ff8fff2;
    }
    (**(code **)(*this + 4))(this);
  }
LAB_00546073:
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = local_c;
  return local_18;
}

