// rea decompile_all
// name: FUN_00521a50
// address: 0x521a50
// body: available
// range: 0x521a50-0x521ad3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
FUN_00521a50(void *this,uint *param_1,int param_2,uint *param_3,int param_4,uint param_5)

{
  int local_c [2];
  undefined4 local_4;
  
  local_c[0] = 0;
  local_4 = FUN_00539840(*(void **)((int)this + 0x68),param_5);
  FUN_00521790(this,param_1,param_2,param_3,param_2,local_c);
  FUN_00521790(this,param_3,param_2,param_3,param_4,local_c);
  FUN_00521790(this,param_3,param_4,param_1,param_4,local_c);
  FUN_00521790(this,param_1,param_4,param_1,param_2,local_c);
  return;
}

