// rea decompile_all
// name: FUN_005530f8
// address: 0x5530f8
// body: available
// range: 0x5530f8-0x55319c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __cdecl
FUN_005530f8(DWORD param_1,undefined4 param_2,DWORD param_3,undefined4 param_4,undefined4 param_5,
            int param_6,int param_7)

{
  DWORD *pDVar1;
  undefined4 uVar2;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_0055ce28;
  puStack_10 = &LAB_00553be0;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_00552398();
  FUN_00552398();
  pDVar1 = FUN_00552398();
  pDVar1[0x1b] = param_1;
  pDVar1 = FUN_00552398();
  pDVar1[0x1c] = param_3;
  local_8 = 1;
  uVar2 = FUN_0054e62c(param_2,param_4,param_5,param_6,param_7);
  local_8 = 0xffffffff;
  CRT_CallCatchBlockFinally();
  ExceptionList = local_14;
  return uVar2;
}

