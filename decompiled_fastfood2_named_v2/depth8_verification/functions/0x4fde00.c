// rea decompile_all
// name: FUN_004fde00
// address: 0x4fde00
// body: available
// range: 0x4fde00-0x4fdef0 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_004fde00(void *param_1,int param_2)

{
  void *this;
  int iVar1;
  uint uVar2;
  
  this = (void *)FUN_0048a270(DAT_0057c670,0x16);
  if (this == (void *)0x0) {
    return 3;
  }
  iVar1 = FUN_00480060(param_2);
  if (0 < iVar1) {
    uVar2 = FUN_004034d0(0,10);
    if ((int)uVar2 < DAT_0057bb24) {
      return 3;
    }
  }
  iVar1 = FUN_004d2ae0(*(void **)(param_2 + 0x16f0),0x16);
  if (iVar1 < 1) {
    iVar1 = FUN_004ddcc0((int)param_1);
    FUN_004e0b60(param_1,0x17,
                 (float)((((10 - *(int *)(iVar1 + 0x58)) - *(int *)(iVar1 + 0x40)) * 10000) / 100),
                 '\x01',0xffffffff);
    FUN_00507e20(this,1,*(int *)(param_2 + 0x16f0));
    FUN_0050e850(this,1);
    *(undefined4 *)((int)this + 0x110) = *(undefined4 *)((int)param_1 + 0x48);
    *(int *)((int)param_1 + 0x70) = *(int *)((int)param_1 + 0x70) + 1;
    return 1;
  }
  return 3;
}

