// rea decompile_all
// name: Mission_CheckGamePlanCategoryGoal
// address: 0x498090
// body: available
// range: 0x498090-0x4980fe inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void Mission_CheckGamePlanCategoryGoal(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
                    /* Completes a mission goal when a game-plan category effect exceeds 70. */
  iVar3 = 0;
  iVar1 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  do {
    iVar2 = GamePlan_ComputeCategoryEffect(DAT_0057c9ec,*(int *)(iVar1 + 0x48),iVar3);
    if (0x46 < iVar2) {
      UI_AppendCommandIfActive(*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8),0x1a,-1);
      MissionGoal_HandleEvent(*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8),0x1a,-1,-1);
      return;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 7);
  return;
}

