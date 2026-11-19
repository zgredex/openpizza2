// rea decompile_all
// name: FUN_00530060
// address: 0x530060
// body: available
// range: 0x530060-0x5300d0 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_00530060(void *this,int *param_1,void *param_2)

{
  int iVar1;
  void *this_00;
  int iVar2;
  undefined4 uVar3;
  
  if (param_2 != (void *)0x0) {
    iVar1 = *(int *)((int)this + 0xf0);
    do {
      iVar1 = iVar1 + -1;
      if ((iVar1 < 0) ||
         (this_00 = *(void **)(*(int *)((int)this + 0xec) + iVar1 * 8), this_00 == param_2)) {
        uVar3 = FUN_00520bc0(param_2,*param_1 - *(int *)((int)this + 0x18),
                             param_1[1] - *(int *)((int)this + 0x1c));
        return uVar3;
      }
    } while ((this_00 == (void *)0x0) ||
            (iVar2 = FUN_00520b60(this_00,*param_1 - *(int *)((int)this + 0x18),
                                  param_1[1] - *(int *)((int)this + 0x1c)), iVar2 == 0));
  }
  return 0;
}

