// rea decompile_all
// name: Game_AdjustPlayerRankingScores
// address: 0x4da390
// body: available
// range: 0x4da390-0x4da472 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall Game_AdjustPlayerRankingScores(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  iVar3 = Game_GetMostAdvancedCompany(param_1);
  iVar5 = 0;
  piVar6 = (int *)(param_1 + 0xcc8);
  do {
    iVar4 = Game_GetPlayerBySlot(DAT_0057c670,iVar5);
    if (iVar4 != 0) {
      if (iVar3 == iVar5) {
        iVar4 = *piVar6 + 8;
LAB_004da42a:
        *piVar6 = iVar4;
      }
      else {
        uVar1 = piVar6[0x39];
        if (uVar1 == 0) {
          iVar4 = *piVar6 + -0xc;
          goto LAB_004da42a;
        }
        uVar2 = *(uint *)(param_1 + 0xdac + iVar3 * 4);
        if (uVar1 < uVar2 >> 2) {
          iVar4 = *piVar6 + -8;
          goto LAB_004da42a;
        }
        if (uVar1 < uVar2 >> 1) {
          iVar4 = *piVar6 + -5;
          goto LAB_004da42a;
        }
        if (uVar1 < (uVar2 * 2) / 3) {
          iVar4 = *piVar6 + -3;
          goto LAB_004da42a;
        }
        if (uVar2 * 3 >> 2 < uVar1) {
          iVar4 = *piVar6 + 2;
          goto LAB_004da42a;
        }
      }
      iVar4 = Game_GetPlayerBySlot(DAT_0057c670,iVar5);
      iVar4 = Game_GetPlayerCity(iVar4);
      iVar4 = *piVar6 + *(int *)(iVar4 + 0x60) + *(int *)(iVar4 + 0x48);
      *piVar6 = iVar4;
      if (iVar4 < 0) {
        *piVar6 = 0;
      }
      if (100 < *piVar6) {
        *piVar6 = 100;
      }
    }
    iVar5 = iVar5 + 1;
    piVar6 = piVar6 + 1;
    if (5 < iVar5) {
      return;
    }
  } while( true );
}

