// rea decompile_all
// name: FUN_004ed480
// address: 0x4ed480
// body: available
// range: 0x4ed480-0x4ed4f4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_004ed480(void *this,int param_1,int param_2,int param_3,int param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_5 < 0) {
    return 1000000;
  }
  if (*(int *)((int)this + 0x20) * *(int *)((int)this + 0x1c) < param_5) {
    return 1000000;
  }
  uVar1 = ((((*(int *)((int)this + 0x10) >> 1) +
            *(int *)(*(int *)((int)this + 0x4c) + 4 + param_5 * 0xc)) - param_2) - param_4) +
          *(int *)((int)this + 0x10);
  uVar3 = (int)uVar1 >> 0x1f;
  uVar2 = (((*(int *)((int)this + 0xc) >> 1) - param_1) - param_3) +
          *(int *)(*(int *)((int)this + 0x4c) + param_5 * 0xc);
  uVar4 = (int)uVar2 >> 0x1f;
  return ((uVar2 ^ uVar4) - uVar4) * 3 + ((uVar1 ^ uVar3) - uVar3) * 4;
}

