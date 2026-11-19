// rea decompile_all
// name: UI_UpdateHoveredRow
// address: 0x528820
// body: available
// range: 0x528820-0x5288a1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall UI_UpdateHoveredRow(void *this,int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
                    /* Leaf reversal proposal batch 3. */
  iVar1 = *(int *)((int)this + 0x3c);
  iVar2 = param_1[1];
  iVar3 = *(int *)((int)this + 0x34);
  if ((iVar3 + iVar1 <= iVar2) &&
     (iVar4 = *(int *)(*(int *)((int)this + 0x4c) + 0x9b0),
     iVar2 <= *(int *)((int)this + 0x40) * iVar4 + iVar3 + iVar1)) {
    iVar5 = *(int *)((int)this + 0x38) + *(int *)((int)this + 0x30);
    if ((iVar5 <= *param_1) && (*param_1 <= *(int *)((int)this + 0x28) + iVar5)) {
      iVar4 = ((iVar2 - iVar3) - iVar1) / iVar4;
      goto LAB_0052887f;
    }
  }
  iVar4 = -1;
LAB_0052887f:
  if (*(int *)((int)this + 0x40) <= iVar4) {
    iVar4 = -1;
  }
  if (iVar4 == *(int *)((int)this + 0x48)) {
    return 0;
  }
  *(int *)((int)this + 0x48) = iVar4;
  return 1;
}

