// rea decompile_all
// name: FUN_00482b70
// address: 0x482b70
// body: available
// range: 0x482b70-0x482c37 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
FUN_00482b70(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  void *this_00;
  void *local_4;
  
  if (*(int *)((int)this + 0x268) == 0) {
    local_4 = this;
    this_00 = FUN_0046d7d0((int *)&local_4);
    *(void **)((int)this + 0x268) = this_00;
    FUN_0052f9b0(this_00,0x42b,param_2);
    FUN_0052f9b0(*(void **)((int)this + 0x268),0x42c,param_3);
    FUN_0052fa20(*(void **)((int)this + 0x268),0x42c,2);
    *(undefined4 *)((int)this + 0x274) = param_1;
    *(undefined4 *)((int)this + 0x278) = 0xffffffff;
    *(undefined4 *)((int)this + 0x270) = param_4;
    *(undefined4 *)((int)this + 0x27c) = 0;
    *(undefined4 *)((int)this + 0x280) = 0;
    FUN_00523d60(DAT_0057c5e0,(int)local_4);
    UI_AddUniquePair(*(void **)((int)this + 0x268),0x42e,0xd);
    UI_AddUniquePair(*(void **)((int)this + 0x268),0x42e,0x1b);
  }
  return;
}

