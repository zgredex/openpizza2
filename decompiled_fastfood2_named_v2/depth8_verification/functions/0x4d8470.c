// rea decompile_all
// name: City_FindFreePlotsNearPoint
// address: 0x4d8470
// body: available
// range: 0x4d8470-0x4d860b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall
City_FindFreePlotsNearPoint
          (void *this,undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  void *this_00;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *local_20;
  int local_1c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar2 = param_3;
                    /* Finds unowned city plots near a point, optionally type- and
                       visibility-filtered. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055910b;
  local_c = ExceptionList;
  local_1c = 9999999;
  ExceptionList = &local_c;
  this_00 = operator_new(0x1c);
  local_4 = 0;
  if (this_00 == (void *)0x0) {
    local_20 = (undefined4 *)0x0;
  }
  else {
    local_20 = FUN_004013a0(this_00,0);
  }
  local_4 = 0xffffffff;
  if (param_4 != 0) {
    local_1c = param_4 * param_4 * 4;
  }
  param_3 = 0;
  iVar1 = *(int *)(iVar2 + 0xc);
  iVar2 = *(int *)(iVar2 + 0x10);
  if (*(int *)((int)this + 0xfc0) < 1) {
    ExceptionList = local_c;
    return local_20;
  }
  do {
    iVar3 = FUN_004017f0((void *)((int)this + 0xfac),param_3,(int *)0x0);
    if (((*(int *)(iVar3 + 0x48) != -1) &&
        ((param_5 == 0 ||
         ((iVar4 = FUN_004d2fd0(iVar3), iVar4 != 0 && (*(int *)(iVar3 + 0x38) < 1)))))) &&
       ((*(int *)(iVar3 + 4) == param_2 || (param_2 == -1)))) {
      iVar4 = FUN_004d2320(iVar3);
      iVar4 = iVar4 - iVar1;
      iVar5 = FUN_004d2360(iVar3);
      iVar5 = iVar5 - iVar2;
      if (param_4 == 0) {
        if (*(int *)(iVar3 + 0x74) == 0) {
          iVar7 = -1;
        }
        else {
          iVar7 = FUN_004e4490(*(int *)(iVar3 + 0x74));
        }
        if (*(int *)(iVar3 + 0x74) == 0) {
          iVar6 = -1;
        }
        else {
          iVar6 = FUN_004e4490(*(int *)(iVar3 + 0x74));
        }
        local_1c = iVar6 * iVar7 * 4;
      }
      if (iVar4 * iVar4 + iVar5 * iVar5 * 4 < local_1c) {
        FUN_004014b0(local_20,iVar3);
      }
    }
    param_3 = param_3 + 1;
  } while (param_3 < *(int *)((int)this + 0xfc0));
  ExceptionList = local_c;
  return local_20;
}

