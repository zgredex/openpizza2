// rea decompile_all
// name: Grid_CollectType351
// address: 0x4f55e0
// body: available
// range: 0x4f55e0-0x4f5654 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Grid_CollectType351(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_4;
  
                    /* Leaf reversal proposal batch 2. */
  iVar2 = 0;
  iVar4 = 0;
  local_4 = 0;
  if (0 < *(int *)((int)this + 0x20)) {
    do {
      iVar5 = 0;
      if (0 < *(int *)((int)this + 0x1c)) {
        iVar6 = iVar4 * 0xc;
        piVar3 = (int *)(param_1 + iVar2 * 8);
        do {
          iVar1 = *(int *)(iVar6 + 8 + *(int *)((int)this + 0x4c));
          if ((iVar1 != 0) && (*(int *)(iVar1 + 4) == 0x351)) {
            *piVar3 = iVar5;
            piVar3[1] = local_4;
            iVar2 = iVar2 + 1;
            piVar3 = piVar3 + 2;
            if (0x50 < iVar2) {
              return;
            }
          }
          iVar4 = iVar4 + 1;
          iVar6 = iVar6 + 0xc;
          iVar5 = iVar5 + 1;
        } while (iVar5 < *(int *)((int)this + 0x1c));
      }
      local_4 = local_4 + 1;
    } while (local_4 < *(int *)((int)this + 0x20));
  }
  return;
}

