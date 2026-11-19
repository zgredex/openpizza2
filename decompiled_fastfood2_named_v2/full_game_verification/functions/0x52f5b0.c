// rea decompile_all
// name: UI_AddImage
// address: 0x52f5b0
// body: available
// range: 0x52f5b0-0x52f68d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall
UI_AddImage(void *this,int param_1,int param_2,int param_3,char *param_4,int param_5,int param_6)

{
  int *piVar1;
  void *unaff_EBX;
  int local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055aaab;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_10 = operator_new(0x174);
  local_4 = 0;
  if (local_10 == (void *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = UI_Image_Construct(local_10,param_1,param_5,param_2,param_3,(int)this,param_4,&local_14
                               );
  }
  local_4 = 0xffffffff;
  if (local_14 != 0) {
    if (piVar1 != (int *)0x0) {
      (**(code **)*piVar1)(1);
    }
    ExceptionList = local_c;
    return 0;
  }
  UI_EnsureObjectArray(this,(int)piVar1,param_1);
  if (param_6 == 0) {
    (**(code **)(*piVar1 + 0xc))(0,0,0);
  }
  else {
    (**(code **)(*piVar1 + 0xc))(0,1,0);
  }
  ExceptionList = unaff_EBX;
  return 1;
}

