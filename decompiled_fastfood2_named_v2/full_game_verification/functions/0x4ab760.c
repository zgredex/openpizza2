// rea decompile_all
// name: StatisticsBalance_MovePeriod
// address: 0x4ab760
// body: available
// range: 0x4ab760-0x4ab829 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl StatisticsBalance_MovePeriod(void *param_1,int param_2)

{
  int iVar1;
  
                    /* Moves the balance-sheet period cursor and refreshes the page. */
  DAT_0057d5c8 = DAT_0057d5c8 + param_2;
  if (DAT_0057d5c8 < 1) {
    do {
      DAT_0057d5c8 = DAT_0057d5c8 + 4;
      DAT_00569354 = DAT_00569354 - 1;
      if ((int)DAT_00569354 < (int)DAT_0057dfbc) {
        DAT_0057d5c8 = 1;
        DAT_00569354 = DAT_0057dfbc;
        break;
      }
    } while (DAT_0057d5c8 < 1);
  }
  if (DAT_00569354 == *(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 4)) {
    iVar1 = *(byte *)(*(int *)(DAT_0057c670 + 0x94) + 8) + 1;
  }
  else {
    iVar1 = 4;
  }
  do {
    if (DAT_0057d5c8 <= iVar1) {
LAB_004ab807:
      StatisticsBalance_UpdateHeader(param_1);
      StatisticsBalance_UpdateBranchList(param_1,DAT_0057d5d4);
      StatisticsBalance_UpdateReport(param_1);
      return;
    }
    if (DAT_00569354 == *(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 4)) {
      DAT_0057d5c8 = iVar1;
      goto LAB_004ab807;
    }
    DAT_0057d5c8 = DAT_0057d5c8 + -4;
    DAT_00569354 = DAT_00569354 + 1;
  } while( true );
}

