// rea decompile_all
// name: StatisticsScreen_ChangeTab
// address: 0x4ab830
// body: available
// range: 0x4ab830-0x4ab957 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl StatisticsScreen_ChangeTab(void *param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  uint *puVar3;
  uint local_18 [4];
  undefined4 local_8;
  uint local_4;
  
                    /* Switches and refreshes the statistics screen tabs. */
  local_8 = 1;
  puVar3 = local_18;
  local_4 = (uint)(*(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 4) != DAT_0057dfbc);
  uVar1 = *(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  iVar2 = 0;
  do {
    *puVar3 = (uint)(iVar2 < (int)(uVar1 + 1));
    iVar2 = iVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (iVar2 < 4);
  if (param_2 != 0) {
    do {
      DAT_0057d5cc = DAT_0057d5cc + param_2;
      if (5 < (int)DAT_0057d5cc) {
        DAT_0057d5cc = 0;
        goto switchD_004ab8be_switchD;
      }
      if ((int)DAT_0057d5cc < 0) {
        DAT_0057d5cc = 5;
      }
    } while (local_18[DAT_0057d5cc] == 0);
  }
  if (5 < DAT_0057d5cc) {
    return;
  }
switchD_004ab8be_switchD:
  switch(DAT_0057d5cc) {
  default:
    DAT_00569354 = (uint)*(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 4);
    DAT_0057d5c8 = *(byte *)(*(int *)(DAT_0057c670 + 0x94) + 8) + 1;
    StatisticsBalance_MovePeriod(param_1,-DAT_0057d5cc);
    return;
  case 4:
  case 5:
    break;
  }
  DAT_00569354 = (uint)*(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 4);
  if (DAT_0057d5cc == 5) {
    DAT_00569354 = DAT_00569354 - 1;
  }
  if ((int)DAT_00569354 < (int)DAT_0057dfbc) {
    DAT_00569354 = DAT_0057dfbc;
  }
  DAT_0057d5c8 = 0;
  StatisticsBalance_UpdateHeader(param_1);
  StatisticsBalance_UpdateBranchList(param_1,DAT_0057d5d4);
  StatisticsBalance_UpdateReport(param_1);
  return;
}

