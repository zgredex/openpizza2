// rea decompile_all
// name: MovieWindow_CreateForScreen
// address: 0x5319c0
// body: available
// range: 0x5319c0-0x531a48 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall
MovieWindow_CreateForScreen(void *this,int param_1,int param_2,int param_3,undefined4 *param_4)

{
  void *this_00;
  undefined4 *puVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055abab;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = operator_new(0xbc);
  local_4 = 0;
  if (this_00 == (void *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = MovieWindow_Construct
                       (this_00,param_1,param_2,param_3,1,param_4,&DAT_00579aec,0,(int)this);
  }
  local_4 = 0xffffffff;
  UI_EnsureObjectArray(this,(int)puVar1,param_1);
  ExceptionList = local_c;
  return 1;
}

