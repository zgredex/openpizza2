// rea decompile_all
// name: Calendar_InterpolateMonthlyValue
// address: 0x4dc6a0
// body: available
// range: 0x4dc6a0-0x4dc71c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __fastcall Calendar_InterpolateMonthlyValue(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
                    /* Leaf reversal proposal batch 1. */
  bVar1 = *(byte *)(*(int *)(DAT_0057c670 + 0x94) + 7);
  uVar2 = (uint)*(byte *)(*(int *)(DAT_0057c670 + 0x94) + 8);
  if (bVar1 < 0xc) {
    iVar4 = *(int *)(param_1 + 0xa4 + (uVar2 - 1 & 3) * 4) + -6;
    iVar3 = ((*(int *)(param_1 + 0xa4 + uVar2 * 4) - iVar4) + 6) * (uint)bVar1;
    iVar3 = iVar3 / 6 + (iVar3 >> 0x1f);
    return ((iVar3 >> 1) - (iVar3 >> 0x1f)) + iVar4;
  }
  iVar4 = *(int *)(param_1 + 0xa4 + uVar2 * 4);
  iVar3 = iVar4 + 6;
  iVar4 = ((iVar4 - iVar3) + -6) * (bVar1 - 0xc);
  iVar4 = iVar4 / 6 + (iVar4 >> 0x1f);
  return ((iVar4 >> 1) - (iVar4 >> 0x1f)) + iVar3;
}

