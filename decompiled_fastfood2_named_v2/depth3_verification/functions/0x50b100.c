// rea decompile_all
// name: FUN_0050b100
// address: 0x50b100
// body: available
// range: 0x50b100-0x50b1f8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint __thiscall FUN_0050b100(void *this,float param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  float local_8;
  int local_4;
  
  piVar1 = *(int **)((int)this + 200);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  FUN_00534370((void *)piVar1[0x16],*piVar1,&local_8,&local_4);
  iVar2 = (int)param_1 - ((int)local_8 + *(int *)(*(int *)((int)this + 0xc4) + 0xf8));
  local_8 = (float)iVar2;
  param_1 = (float)(param_2 - (local_4 + *(int *)(*(int *)((int)this + 0xc4) + 0xfc)));
  if (param_1 == 0.0) {
    param_1 = 1.0;
  }
  fpatan((float10)iVar2 / (float10)param_1,(float10)1);
  lVar3 = __ftol();
  return -(-(int)lVar3 - 1U & 7) & 7;
}

