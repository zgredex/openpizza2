// rea decompile_all
// name: AI_SelectStrategyAction
// address: 0x502a90
// body: available
// range: 0x502a90-0x502b6d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __fastcall AI_SelectStrategyAction(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = 0;
  uVar5 = 2;
  switch(*(undefined4 *)(param_1 + 0x44)) {
  case 0:
    uVar2 = Game_IsInputIndexUsed(0x50);
    if ((char)uVar2 == '\0') goto switchD_00502aa4_default;
    goto LAB_00502b07;
  case 1:
    uVar2 = Game_AnyBuildingRatingAbove(0x50);
    uVar6 = (uint)((char)uVar2 != '\0');
    uVar2 = Game_AnyBuildingCategoryRatingAbove(0x50);
    if ((char)uVar2 != '\0') {
      if (uVar6 == 1) {
        uVar6 = 2;
      }
      else {
        uVar6 = 0;
        uVar5 = 0;
      }
    }
    goto switchD_00502aa4_default;
  case 2:
    uVar2 = Game_IsObjectStatAbove(0x50);
    cVar1 = (char)uVar2;
    break;
  case 3:
    uVar3 = Game_AllBuildingCategoryRatingsAbove(0x50);
    cVar1 = (char)uVar3;
    break;
  default:
    goto switchD_00502aa4_default;
  }
  if (cVar1 != '\0') {
LAB_00502b07:
    uVar6 = 1;
  }
switchD_00502aa4_default:
  uVar5 = Random_RangeFast(uVar6,uVar5);
  if (uVar5 == 2) {
    if (*(int *)(param_1 + 0x44) == 1) {
      *(undefined4 *)(param_1 + 0x84) = 0x14;
    }
  }
  else if (uVar5 == 1) {
    if (*(int *)(param_1 + 0x44) == 3) {
      *(undefined4 *)(param_1 + 0x84) = 0x14;
    }
    if (*(int *)(param_1 + 0x44) == 0) {
      *(undefined4 *)(param_1 + 0x84) = 5;
    }
  }
  iVar4 = (*(int *)(param_1 + 0x44) + uVar5 * 4) * 4;
  *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(&DAT_005727cc + iVar4);
  return *(undefined4 *)(&DAT_0057279c + iVar4);
}

