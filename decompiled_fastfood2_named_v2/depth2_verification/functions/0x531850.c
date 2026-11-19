// rea decompile_all
// name: FUN_00531850
// address: 0x531850
// body: available
// range: 0x531850-0x531904 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_00531850(void *this,int param_1,int param_2,int param_3,char *param_4)

{
  int iVar1;
  void *this_00;
  undefined4 *puVar2;
  undefined4 local_50 [17];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055ab8b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar1 = FUN_00527580(*(void **)((int)this + 0x134),param_4,(undefined4 *)0x0,local_50);
  if (iVar1 == 0) {
    ExceptionList = local_c;
    return 0;
  }
  this_00 = operator_new(0xbc);
  local_4 = 0;
  if (this_00 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = FUN_0052ae20(this_00,param_1,param_2,param_3,0,local_50,(char *)0x0,1,(int)this);
  }
  local_4 = 0xffffffff;
  UI_EnsureObjectArray(this,(int)puVar2,param_1);
  ExceptionList = local_c;
  return 1;
}

