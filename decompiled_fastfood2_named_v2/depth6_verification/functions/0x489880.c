// rea decompile_all
// name: FUN_00489880
// address: 0x489880
// body: available
// range: 0x489880-0x489948 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __fastcall FUN_00489880(void *param_1)

{
  int iVar1;
  void *this;
  undefined4 *this_00;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int local_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055834b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this = operator_new(0x1c);
  local_4 = 0;
  if (this == (void *)0x0) {
    this_00 = (undefined4 *)0x0;
  }
  else {
    this_00 = FUN_004013a0(this,0);
  }
  local_4 = 0xffffffff;
  local_14 = 0;
  do {
    iVar2 = FUN_00488be0(param_1,local_14);
    if ((((iVar2 != 0) &&
         (iVar1 = *(int *)(iVar2 + 0x48), iVar3 = FUN_00482820((int)param_1), iVar1 != iVar3)) &&
        (iVar1 = *(int *)(iVar2 + 0x15c), iVar1 != 0)) && (iVar3 = 0, 0 < iVar1)) {
      do {
        uVar4 = FUN_004017f0((void *)(iVar2 + 0x148),iVar3,(int *)0x0);
        FUN_004014b0(this_00,uVar4);
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar1);
    }
    local_14 = local_14 + 1;
  } while (local_14 < 6);
  ExceptionList = local_c;
  return this_00;
}

