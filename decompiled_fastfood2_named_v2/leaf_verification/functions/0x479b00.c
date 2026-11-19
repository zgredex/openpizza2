// rea decompile_all
// name: Grid_ScoreRuns
// address: 0x479b00
// body: available
// range: 0x479b00-0x479c13 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int Grid_ScoreRuns(int param_1)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int local_500 [80];
  int local_3c0 [80];
  int local_280 [80];
  int local_140 [80];
  
  piVar7 = local_280;
                    /* Leaf reversal proposal batch 2. */
  for (iVar3 = 0x50; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar7 = 0;
    piVar7 = piVar7 + 1;
  }
  piVar7 = local_3c0;
  for (iVar3 = 0x50; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar7 = 0;
    piVar7 = piVar7 + 1;
  }
  piVar7 = local_140;
  for (iVar3 = 0x50; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar7 = 0;
    piVar7 = piVar7 + 1;
  }
  piVar7 = local_500;
  for (iVar3 = 0x50; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar7 = 0;
    piVar7 = piVar7 + 1;
  }
  iVar6 = 0;
  psVar1 = (short *)(param_1 + 4);
  iVar3 = 0;
  do {
    iVar2 = 0;
    do {
      if (*psVar1 == 1) {
        iVar4 = *(int *)((int)local_3c0 + iVar3) + 1;
        *(int *)((int)local_3c0 + iVar3) = iVar4;
        iVar5 = *(int *)((int)local_280 + iVar2) + 1;
        *(int *)((int)local_280 + iVar2) = iVar5;
        if (2 < iVar4) {
          iVar6 = iVar6 + 4;
        }
        if (2 < iVar5) {
          iVar6 = iVar6 + 4;
        }
LAB_00479bd8:
        *(undefined4 *)((int)local_500 + iVar3) = 0;
        *(undefined4 *)((int)local_140 + iVar2) = 0;
      }
      else {
        if (*psVar1 != 2) {
          *(undefined4 *)((int)local_3c0 + iVar3) = 0;
          *(undefined4 *)((int)local_280 + iVar2) = 0;
          goto LAB_00479bd8;
        }
        iVar4 = *(int *)((int)local_500 + iVar3) + 1;
        *(int *)((int)local_500 + iVar3) = iVar4;
        iVar5 = *(int *)((int)local_140 + iVar2) + 1;
        *(int *)((int)local_140 + iVar2) = iVar5;
        if (4 < iVar4) {
          iVar6 = iVar6 + 2;
        }
        if (4 < iVar5) {
          iVar6 = iVar6 + 2;
        }
        *(undefined4 *)((int)local_3c0 + iVar3) = 0;
        *(undefined4 *)((int)local_280 + iVar2) = 0;
      }
      iVar2 = iVar2 + 4;
      psVar1 = psVar1 + 4;
    } while (iVar2 < 0x140);
    iVar3 = iVar3 + 4;
    if (0x13f < iVar3) {
      return iVar6;
    }
  } while( true );
}

