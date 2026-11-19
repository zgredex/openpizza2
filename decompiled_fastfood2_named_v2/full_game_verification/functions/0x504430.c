// rea decompile_all
// name: MissionGoal_Evaluate
// address: 0x504430
// body: available
// range: 0x504430-0x5045cc inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall MissionGoal_Evaluate(void *this,int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
                    /* Evaluates the active mission goal and advances it when satisfied. */
  switch(*(undefined4 *)((int)this + 0x48)) {
  case 0x15:
    if (param_1 % 3 == 0) {
      List_Node_Reset((int)this + 0x68);
    }
  default:
    goto switchD_00504442_caseD_16;
  case 0x18:
    UI_AppendCommandIfActive(this,0x18,-1);
    uVar2 = Game_IsInputIndexUsed(0x50);
    if ((char)uVar2 == '\0') goto switchD_00504442_caseD_16;
    iVar3 = 0x18;
    break;
  case 0x1b:
    UI_AppendCommandIfActive(this,0x1b,-1);
    uVar2 = Game_AnyBuildingRatingAbove(0x50);
    if ((char)uVar2 == '\0') goto switchD_00504442_caseD_16;
    iVar3 = 0x1b;
    break;
  case 0x1c:
    UI_AppendCommandIfActive(this,0x1c,-1);
    uVar2 = Game_AnyBuildingCategoryRatingAbove(0x50);
    if ((char)uVar2 == '\0') goto switchD_00504442_caseD_16;
    iVar3 = 0x1c;
    break;
  case 0x1e:
    UI_AppendCommandIfActive(this,0x1e,-1);
    uVar2 = Game_IsObjectStatAbove(0x50);
    if ((char)uVar2 == '\0') goto switchD_00504442_caseD_16;
    iVar3 = 0x1e;
    break;
  case 0x20:
    UI_AppendCommandIfActive(this,0x20,-1);
    uVar2 = Game_IsInputIndexUsed(0x32);
    if (((((char)uVar2 == '\0') || (uVar2 = Game_AnyBuildingRatingAbove(0x32), (char)uVar2 == '\0'))
        || (uVar2 = Game_AnyBuildingCategoryRatingAbove(0x32), (char)uVar2 == '\0')) ||
       ((uVar2 = Game_IsObjectStatAbove(0x32), (char)uVar2 == '\0' ||
        (uVar1 = Game_AllBuildingCategoryRatingsAbove(0x32), (char)uVar1 == '\0'))))
    goto switchD_00504442_caseD_16;
    iVar3 = 0x20;
    break;
  case 0x21:
    UI_AppendCommandIfActive(this,0x21,-1);
    uVar1 = Game_AllBuildingCategoryRatingsAbove(0x32);
    if ((char)uVar1 == '\0') goto switchD_00504442_caseD_16;
    iVar3 = 0x21;
  }
  MissionGoal_HandleEvent(this,iVar3,-1,-1);
switchD_00504442_caseD_16:
  UI_DecrementTimer(this,0x30,'\x01');
  UI_DecrementTimer(this,0xf,'\x01');
  UI_DecrementTimer(this,4,'\x01');
  UI_DecrementTimer(this,0x2c,'\x01');
  UI_DecrementTimer(this,0x30,'\0');
  UI_DecrementTimer(this,0x10,'\0');
  UI_DecrementTimer(this,4,'\0');
  return;
}

