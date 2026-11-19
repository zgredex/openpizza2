// rea decompile_all
// name: Game_UpdateMusicTheme
// address: 0x4fccb0
// body: available
// range: 0x4fccb0-0x4fce1a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void Game_UpdateMusicTheme(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  short *psVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  short *psVar10;
  int *piVar11;
  int local_44 [8];
  int local_24 [9];
  
                    /* Depth-2 proposal batch 2/4. */
  if (param_1 != 0) {
    iVar1 = FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(param_1 + 0x34),(int *)0x0);
    piVar3 = local_44;
    for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
      *piVar3 = 0;
      piVar3 = piVar3 + 1;
    }
    if (param_2 == 0) {
      iVar5 = *(int *)(param_1 + 0x34);
      iVar9 = 0;
      iVar7 = *(int *)(DAT_0057c670 + 0x50);
      if (0 < iVar7) {
        do {
          iVar2 = FUN_004017f0((void *)(DAT_0057c670 + 0x3c),iVar9,(int *)0x0);
          if ((((iVar2 != 0) && (*(int *)(iVar2 + 0x28) == iVar5)) &&
              (iVar2 = *(int *)(iVar2 + 0x34), -1 < iVar2)) && (iVar2 < 8)) {
            local_44[iVar2] = local_44[iVar2] + 1;
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 < iVar7);
      }
    }
    else {
      psVar10 = (short *)(param_2 + 6);
      iVar5 = 8;
      do {
        piVar3 = local_44;
        iVar7 = 8;
        psVar6 = psVar10;
        do {
          *piVar3 = *piVar3 + (int)*psVar6;
          psVar6 = psVar6 + 1;
          piVar3 = piVar3 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        psVar10 = psVar10 + 0x1a;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    iVar5 = 0;
    iVar9 = 8;
    piVar3 = local_24;
    for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {
      *piVar3 = 0;
      piVar3 = piVar3 + 1;
    }
    piVar3 = local_44;
    do {
      iVar7 = *piVar3;
      piVar3 = piVar3 + 1;
      iVar5 = iVar5 + iVar7;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    if (iVar5 == 0) {
      iVar5 = 8;
    }
    else {
      piVar11 = local_44;
      param_2 = 8;
      piVar3 = (int *)(iVar1 + 0xe0);
      do {
        iVar1 = *piVar11;
        piVar4 = local_24;
        iVar5 = 9;
        piVar8 = piVar3;
        do {
          iVar7 = *piVar8;
          piVar8 = piVar8 + 8;
          *piVar4 = *piVar4 + iVar7 * iVar1;
          piVar4 = piVar4 + 1;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        piVar11 = piVar11 + 1;
        piVar3 = piVar3 + 1;
        param_2 = param_2 + -1;
      } while (param_2 != 0);
      iVar7 = 0;
      piVar3 = local_24;
      iVar1 = param_1;
      iVar5 = param_1;
      do {
        if ((iVar7 == 0) || (iVar1 < *piVar3)) {
          iVar1 = *piVar3;
          iVar5 = iVar7;
        }
        iVar7 = iVar7 + 1;
        piVar3 = piVar3 + 1;
      } while (iVar7 < 9);
    }
    if (*(int *)(param_1 + 0x14d8) != iVar5) {
      *(int *)(param_1 + 0x14d8) = iVar5;
      FUN_00547e70(DAT_0057ba0c);
    }
  }
  return;
}

