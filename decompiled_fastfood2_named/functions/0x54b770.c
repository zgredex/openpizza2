// rea decompile_all
// name: FUN_0054b770
// address: 0x54b770
// body: available
// range: 0x54b770-0x54b858 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
FUN_0054b770(void *this,int param_1,int param_2,void *param_3,int param_4,int param_5,int param_6)

{
  void *this_00;
  void *this_01;
  void *pvVar1;
  
  if (param_2 == 0) {
    this_00 = (void *)IDMap_Lookup((void *)((int)this + 4),(int)param_3,(int *)0x0);
    this_01 = (void *)IDMap_Lookup((void *)((int)this + 0x3c),param_4,(int *)0x0);
    param_3 = (void *)IDMap_Lookup((void *)((int)this + 0x74),param_5,(int *)0x0);
    pvVar1 = (void *)((int)this + 0xac);
  }
  else {
    this_00 = (void *)IDMap_Lookup((void *)((int)this + 0x20),(int)param_3,(int *)0x0);
    this_01 = (void *)IDMap_Lookup((void *)((int)this + 0x58),param_4,(int *)0x0);
    param_3 = (void *)IDMap_Lookup((void *)((int)this + 0x90),param_5,(int *)0x0);
    pvVar1 = (void *)((int)this + 200);
  }
  pvVar1 = (void *)IDMap_Lookup(pvVar1,param_6,(int *)0x0);
  if (this_00 != (void *)0x0) {
    FUN_0053d570(this_00,param_1,(uint *)0x0,0);
  }
  if (pvVar1 != (void *)0x0) {
    FUN_0053d570(pvVar1,param_1,(uint *)0x0,0);
  }
  if (this_01 != (void *)0x0) {
    FUN_0053d570(this_01,param_1,(uint *)0x0,0);
  }
  if (param_3 != (void *)0x0) {
    FUN_0053d570(param_3,param_1,(uint *)0x0,0);
  }
  return;
}

