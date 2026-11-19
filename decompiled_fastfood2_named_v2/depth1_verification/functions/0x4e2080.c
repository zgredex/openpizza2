// rea decompile_all
// name: FUN_004e2080
// address: 0x4e2080
// body: available
// range: 0x4e2080-0x4e2103 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004e2080(void *this,int param_1,int param_2)

{
  void *this_00;
  int *piVar1;
  
  this_00 = (void *)FUN_004017f0((void *)(DAT_0057c670 + 0x3c),param_1,(int *)0x0);
  if (this_00 != (void *)0x0) {
    *(undefined4 *)((int)this_00 + 0x110) = *(undefined4 *)((int)this + 0x48);
    if (param_2 != 0x1f) {
      Object_GetPlayerValue(this_00,-1);
    }
    if (*(int *)((int)this_00 + 0x74) == 0) {
      FUN_0050a080(this_00,*(int *)((int)this + 0x1d8));
    }
    else {
      FUN_0050a0b0(this_00,0x1c,*(int *)((int)this + 0x1d8));
    }
    piVar1 = operator_new(8);
    *piVar1 = param_1;
    piVar1[1] = param_2;
    FUN_004014b0((void *)((int)this + 0x1b8),piVar1);
  }
  return;
}

