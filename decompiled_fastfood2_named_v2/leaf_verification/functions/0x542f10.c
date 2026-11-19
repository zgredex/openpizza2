// rea decompile_all
// name: Sound_SetSampleFormat
// address: 0x542f10
// body: available
// range: 0x542f10-0x54305c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int Sound_SetSampleFormat(int param_1,undefined4 param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar1;
  int iVar2;
  undefined4 local_20;
  int local_1c;
  int local_18;
  undefined2 local_14;
  ushort uStack_12;
  undefined2 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Leaf reversal proposal batch 1. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b0f8;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xa0);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  iVar2 = *(int *)(param_1 + 0x98);
  local_4 = 0;
  if (iVar2 < 0) {
    LeaveCriticalSection(lpCriticalSection);
    ExceptionList = local_c;
    return iVar2;
  }
  piVar1 = *(int **)(param_1 + 0x18);
  if (piVar1 == (int *)0x0) {
    iVar2 = -0x7ff8fffa;
    goto LAB_00543040;
  }
  local_20 = 0x20001;
  local_10 = 0;
  switch(param_2) {
  default:
    local_1c = 0xac44;
    goto LAB_00542ffe;
  case 1:
    local_1c = 0x5622;
    goto LAB_00542ffe;
  case 2:
    local_1c = 0x2b11;
LAB_00542ffe:
    uStack_12 = 0x10;
    break;
  case 3:
    uStack_12 = 8;
    local_1c = 0xac44;
    break;
  case 4:
    uStack_12 = 8;
    local_1c = 0x5622;
    break;
  case 5:
    uStack_12 = 8;
    local_1c = 0x2b11;
  }
  local_18 = (int)((uint)uStack_12 * 2) >> 3;
  local_14 = (undefined2)local_18;
  local_18 = local_18 * local_1c;
  (**(code **)(*piVar1 + 0x38))(piVar1,&local_20);
  iVar2 = 0;
LAB_00543040:
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = local_c;
  return iVar2;
}

