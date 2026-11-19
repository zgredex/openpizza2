// rea decompile_all
// name: Player_CreateBranch
// address: 0x4f7420
// body: available
// range: 0x4f7420-0x4f770e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall
Player_CreateBranch(void *this,int param_1,void *param_2,int param_3,int param_4,int param_5)

{
  void *this_00;
  int iVar1;
  void *this_01;
  void *this_02;
  int iVar2;
  int iVar3;
  undefined4 unaff_EDI;
  undefined4 *this_03;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Creates a branch object for a player and starts its opening action. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a0cb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = (void *)IDMap_Lookup((void *)((int)DAT_0057c670 + 4),param_1,(int *)0x0);
  iVar3 = *(int *)((int)this + param_3 * 0x168 + 0x40);
  Game_AcquireStateLock(DAT_0057c670,0);
  if ((*(int *)((int)param_2 + 8) == -1) || (*(int *)((int)param_2 + 8) == iVar3)) {
    *(undefined4 *)((int)param_2 + 0x4c) = 0;
    *(undefined4 *)((int)param_2 + 0x50) = 0;
    Game_PlaceObjectInPlayerCity(this_00,param_2,iVar3);
    Window_UnlockState((int)DAT_0057c670);
    this_01 = (void *)Game_GetPlayerBySlot(DAT_0057c670,iVar3);
    Game_GetPlayerCity((int)this_01);
    Thread_SetGlobalFlag(this,1);
    this_02 = operator_new(0x1a3c);
    this_03 = (undefined4 *)0x0;
    local_4 = 0;
    if (this_02 != (void *)0x0) {
      this_03 = Branch_Construct(this_02,param_4,iVar3,param_1);
    }
    local_4 = 0xffffffff;
    Thread_SetGlobalFlag(this,0);
    Game_AcquireStateLock(DAT_0057c670,0);
    Branch_GenerateUniqueName((int)this_03);
    this_03[9] = 0;
    Object_AttachBuildingValue(this_03,(int)param_2);
    iVar1 = Player_AddBranchPlan(this_01,this_03);
    this_03[0xf] = iVar1;
    *(int *)((int)param_2 + 0x2c) = iVar1;
    iVar2 = *(int *)((int)param_2 + 0x48);
    if ((-1 < iVar2) && (iVar2 < 4)) {
      iVar2 = *(int *)(&DAT_00568188 + iVar2 * 4);
    }
    iVar2 = iVar2 + 0x858 + param_4 * 4;
    if (param_5 == 0) {
      MapObject_SpawnByKind(this_00,param_2,1,iVar3,(void *)0xf,iVar2);
    }
    else {
      MapObject_SpawnByKind(this_00,param_2,6,iVar3,(void *)0xf,iVar2);
      *(undefined4 *)((int)param_2 + 0x4c) = 0;
      *(undefined4 *)((int)param_2 + 0x50) = 0;
    }
    Branch_RefreshConstructionButtons(this_03);
    Window_UnlockState((int)DAT_0057c670);
    if (*(int *)((int)this + param_3 * 0x168 + 0x114) != 0) {
      Game_TryBuyCompletedHouse(this,this_03,0);
    }
    *(undefined4 *)(*(int *)((int)this_00 + 0xfa8) + 0xf4) = 1;
    if (*(void **)((int)DAT_0057c670 + 0x25c) != (void *)0x0) {
      UI_QueueControlCommand(*(void **)((int)DAT_0057c670 + 0x25c),-0x18689,0x23,1);
      iVar2 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
      if ((iVar3 == iVar2) && (*(int *)((int)DAT_0057c670 + 0x9c) == 0)) {
        *(undefined4 **)((int)DAT_0057c670 + 0x9c) = this_03;
        Sound_SelectCurrentTrack(DAT_0057ba0c);
      }
    }
    if (*(void **)((int)DAT_0057c670 + 0x264) != (void *)0x0) {
      UI_QueueControlCommand(*(void **)((int)DAT_0057c670 + 0x264),-0x18689,0x23,1);
    }
    if (*(int *)((int)this + param_3 * 0x168 + 0x118) != 0) {
      Company_PushRecentEntry(this,param_3,0xc,iVar1,-1);
      Company_PushRecentEntry(this,param_3,7,iVar1,-1);
      Company_PushRecentEntry(this,param_3,8,iVar1,-1);
      Company_PushRecentEntry(this,param_3,10,iVar1,-1);
    }
    if ((((*(int *)((int)this + param_3 * 0x168 + 0x114) == 0) &&
         (*(int *)((int)this_01 + 0x15c) == 2)) && (*(int *)((int)this_01 + 0x194) == 0)) &&
       (iVar3 = Game_HasQueuedEventType(DAT_0057c670,6), iVar3 == 0)) {
      iVar3 = UI_Briefing_Printf((int)DAT_0057c670,-1,5,1,0xb,0,DAT_00582d88,DAT_00582c4c,unaff_EDI)
      ;
      Game_SetMessageField34(DAT_0057c670,iVar3,6);
    }
  }
  else {
    Window_UnlockState((int)DAT_0057c670);
    iVar1 = -1;
  }
  ExceptionList = local_c;
  return iVar1;
}

