// rea decompile_all
// name: Array_MoveActiveSlotToRandom
// address: 0x4db260
// body: available
// range: 0x4db260-0x4db2dd inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Array_MoveActiveSlotToRandom(void *this,int param_1)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
                    /* Depth-1 proposal batch 2. */
  iVar5 = 0;
  uVar1 = FUN_004034d0(0,5);
  iVar4 = 6;
  piVar3 = (int *)((int)this + param_1 * 4 + 0x280);
  piVar2 = piVar3;
  do {
    if (*piVar2 == 1) {
      iVar5 = iVar5 + 1;
    }
    piVar2 = piVar2 + 8;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  if (1 < iVar5) {
    iVar4 = 0;
    do {
      if (*piVar3 == 1) {
        *(undefined4 *)((int)this + (param_1 + 0xa0 + iVar4 * 8) * 4) = 0;
        *(undefined4 *)((int)this + (param_1 + 0xa0 + uVar1 * 8) * 4) = 1;
        return;
      }
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 8;
    } while (iVar4 < 6);
  }
  *(undefined4 *)((int)this + (param_1 + 0xa0 + uVar1 * 8) * 4) = 1;
  return;
}

