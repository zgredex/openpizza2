// rea decompile_all
// name: Game_UpdateAmbientLight
// address: 0x485820
// body: available
// range: 0x485820-0x485893 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall Game_UpdateAmbientLight(void *this,int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
                    /* Leaf reversal proposal batch 4. */
  uVar1 = (uint)*(byte *)(*(int *)((int)this + 0x94) + 7);
  uVar2 = (uint)*(byte *)(*(int *)((int)this + 0x94) + 6);
  if (*(int *)(param_1 + 0xc) == 0x10) {
    iVar3 = 0xf8;
  }
  else {
    iVar3 = (int)(*(int *)((int)this + uVar1 * 4 + 0x2db0) * (uVar2 * -5 + 0x3c) +
                 *(int *)((int)this + uVar1 * 4 + 0x2db4) * uVar2 * 5) / 0x3c;
  }
  if (DAT_00585518 == iVar3) {
    return 0;
  }
  DAT_00585518 = iVar3;
  return 1;
}

