// rea decompile_all
// name: FUN_00525bc0
// address: 0x525bc0
// body: available
// range: 0x525bc0-0x525ce8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00525bc0(void *this,int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = (int)this + 0x1cc;
  FUN_00401320(iVar1);
  uVar2 = *(uint *)((int)this + 0x82c0);
  uVar3 = *(uint *)((int)this + 0x82bc);
  if ((uVar2 + 1 & 0x3ff) != uVar3) {
    if ((0x22 < param_4) || (param_4 < 0)) {
      for (; uVar3 != uVar2; uVar3 = uVar3 + 1 & 0x3ff) {
        if ((((*(int *)((int)this + (uVar3 * 5 + 0xcb2) * 4) == param_4) &&
             (*(int *)((int)this + uVar3 * 0x14 + 0x32bc) == param_1)) &&
            (*(int *)((int)this + uVar3 * 0x14 + 0x32c0) == param_2)) &&
           ((*(int *)((int)this + uVar3 * 0x14 + 0x32c4) == param_3 &&
            (*(int *)((int)this + uVar3 * 0x14 + 0x32cc) == param_5)))) {
          FUN_00401340(iVar1);
          return;
        }
      }
    }
    *(int *)((int)this + uVar2 * 0x14 + 0x32bc) = param_1;
    *(int *)((int)this + *(int *)((int)this + 0x82c0) * 0x14 + 0x32c0) = param_2;
    *(int *)((int)this + *(int *)((int)this + 0x82c0) * 0x14 + 0x32c4) = param_3;
    *(int *)((int)this + (*(int *)((int)this + 0x82c0) + 0x28a) * 0x14) = param_4;
    *(int *)((int)this + *(int *)((int)this + 0x82c0) * 0x14 + 0x32cc) = param_5;
    *(uint *)((int)this + 0x82c0) = *(int *)((int)this + 0x82c0) + 1U & 0x3ff;
  }
  FUN_00401340(iVar1);
  return;
}

