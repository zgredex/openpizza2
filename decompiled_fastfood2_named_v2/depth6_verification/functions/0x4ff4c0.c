// rea decompile_all
// name: FUN_004ff4c0
// address: 0x4ff4c0
// body: available
// range: 0x4ff4c0-0x4ff52a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_004ff4c0(void *param_1,int param_2)

{
  int *piVar1;
  void *this;
  undefined4 uVar2;
  
  piVar1 = FUN_004e1e40(param_1,0x1d);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  this = (void *)FUN_004017f0((void *)(DAT_0057c670 + 0x3c),*piVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return 0;
  }
  uVar2 = Game_CanAffordWithCurrency(param_1,0x17,5000.0,'\x01',0xffffffff);
  if ((char)uVar2 == '\0') {
    return 0;
  }
  FUN_0050bed0(this,param_2,0x10);
  return 1;
}

