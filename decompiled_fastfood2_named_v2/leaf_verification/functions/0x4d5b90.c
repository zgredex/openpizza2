// rea decompile_all
// name: FUN_004d5b90
// address: 0x4d5b90
// body: available
// range: 0x4d5b90-0x4d5c3c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __fastcall FUN_004d5b90(int param_1)

{
  void *this;
  undefined4 *this_00;
  int iVar1;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055901b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this = operator_new(0x1c);
  iVar2 = 0;
  local_4 = 0;
  if (this == (void *)0x0) {
    this_00 = (undefined4 *)0x0;
  }
  else {
    this_00 = FUN_004013a0(this,0);
  }
  local_4 = 0xffffffff;
  if (*(int *)(param_1 + 0xfc0) < 1) {
    ExceptionList = local_c;
    return this_00;
  }
  do {
    iVar1 = IDMap_Lookup((void *)(param_1 + 0xfac),iVar2,(int *)0x0);
    if ((0x13 < *(int *)(iVar1 + 4)) && (*(int *)(iVar1 + 4) < 0x17)) {
      FUN_004014b0(this_00,iVar1);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < *(int *)(param_1 + 0xfc0));
  ExceptionList = local_c;
  return this_00;
}

