// rea decompile_all
// name: Stats_ComputeOccupancyPercent
// address: 0x4793b0
// body: available
// range: 0x4793b0-0x479450 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall Stats_ComputeOccupancyPercent(void *this,int param_1)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  
                    /* Depth-1 proposal batch 1. */
  iVar4 = 0;
  iVar3 = 0;
  psVar2 = (short *)(param_1 + 4);
  iVar6 = 0x50;
  do {
    iVar5 = 0x50;
    do {
      sVar1 = *psVar2;
      if ((sVar1 < -3) || ((-1 < sVar1 && (sVar1 != 9)))) {
        if (sVar1 == 0) {
          iVar3 = iVar3 + 1;
        }
        iVar4 = iVar4 + 1;
      }
      psVar2 = psVar2 + 4;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  if (iVar3 < 1) {
    *(undefined4 *)((int)this + 0x1858) = 100;
  }
  else {
    lVar7 = __ftol();
    *(int *)((int)this + 0x1858) = (int)lVar7;
  }
  FUN_00477100((int *)((int)this + 0x1858));
  return iVar4;
}

