// rea decompile_all
// name: FUN_00409bb0
// address: 0x409bb0
// body: available
// range: 0x409bb0-0x409c50 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_00409bb0(void *param_1,void *param_2)

{
  void *this;
  int iVar1;
  int *piVar2;
  
  this = *(void **)((int)param_2 + 0xc4);
  if (*(int *)((int)param_2 + 0x128) < *(int *)((int)param_2 + 0x98)) {
    iVar1 = FUN_00409b10(param_1,param_2);
    if (iVar1 != 0) {
      return 1;
    }
  }
  UI_DetachChildRecord((int)param_2);
  piVar2 = FUN_004f3ce0(this,param_1);
  iVar1 = FUN_004f0cc0(this,1,(int)*(short *)(*(int *)(*(int *)((int)this + 0x4c) + 8 +
                                                      *piVar2 * 0xc) + 0x24));
  if (iVar1 == 0) {
    FUN_0048e0a0();
    return 0;
  }
  *(int *)((int)param_2 + 0x88) = *piVar2;
  FUN_0050e890(param_2,8);
  FUN_00507d90(param_2,iVar1);
  return 0;
}

