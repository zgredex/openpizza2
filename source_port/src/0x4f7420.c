// Player_CreateBranch: ported from Pizza Connection 2 at 0x4f7420.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f7420
#include "pc2_port.h"


int __thiscall
Player_CreateBranch(void *self,int arg1,void *arg2,int arg3,int arg4,int arg5)

{
  void *this_00;
  int value1;
  void *this_01;
  void *this_02;
  int value2;
  int value3;
  uint32_t unaff_EDI;
  uint32_t *this_03;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Creates a branch object for a player and starts its opening action. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a0cb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),arg1,(int *)0x0);
  value3 = *(int *)((intptr_t)self + arg3 * 0x168 + 0x40);
  Game_AcquireStateLock(DAT_0057c670,0);
  if ((*(int *)((intptr_t)arg2 + 8) == -1) || (*(int *)((intptr_t)arg2 + 8) == value3)) {
    *(uint32_t *)((intptr_t)arg2 + 0x4c) = 0;
    *(uint32_t *)((intptr_t)arg2 + 0x50) = 0;
    Game_PlaceObjectInPlayerCity(this_00,arg2,value3);
    Window_UnlockState((intptr_t)DAT_0057c670);
    this_01 = (void *)Game_GetPlayerBySlot(DAT_0057c670,value3);
    Game_GetPlayerCity((intptr_t)this_01);
    Thread_SetGlobalFlag(self,1);
    this_02 = operator_new(0x1a3c);
    this_03 = (uint32_t *)0x0;
    local_4 = 0;
    if (this_02 != (void *)0x0) {
      this_03 = Branch_Construct(this_02,arg4,value3,arg1);
    }
    local_4 = 0xffffffff;
    Thread_SetGlobalFlag(self,0);
    Game_AcquireStateLock(DAT_0057c670,0);
    Branch_GenerateUniqueName((intptr_t)this_03);
    this_03[9] = 0;
    Object_AttachBuildingValue(this_03,(intptr_t)arg2);
    value1 = Player_AddBranchPlan(this_01,this_03);
    this_03[0xf] = value1;
    *(int *)((intptr_t)arg2 + 0x2c) = value1;
    value2 = *(int *)((intptr_t)arg2 + 0x48);
    if ((-1 < value2) && (value2 < 4)) {
      value2 = *(int *)(&DAT_00568188 + value2 * 4);
    }
    value2 = value2 + 0x858 + arg4 * 4;
    if (arg5 == 0) {
      MapObject_SpawnByKind(this_00,arg2,1,value3,(void *)0xf,value2);
    }
    else {
      MapObject_SpawnByKind(this_00,arg2,6,value3,(void *)0xf,value2);
      *(uint32_t *)((intptr_t)arg2 + 0x4c) = 0;
      *(uint32_t *)((intptr_t)arg2 + 0x50) = 0;
    }
    Branch_RefreshConstructionButtons(this_03);
    Window_UnlockState((intptr_t)DAT_0057c670);
    if (*(int *)((intptr_t)self + arg3 * 0x168 + 0x114) != 0) {
      Game_TryBuyCompletedHouse(self,this_03,0);
    }
    *(uint32_t *)(*(int *)((intptr_t)this_00 + 0xfa8) + 0xf4) = 1;
    if (*(void **)((intptr_t)DAT_0057c670 + 0x25c) != (void *)0x0) {
      UI_QueueControlCommand(*(void **)((intptr_t)DAT_0057c670 + 0x25c),-0x18689,0x23,1);
      value2 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
      if ((value3 == value2) && (*(int *)((intptr_t)DAT_0057c670 + 0x9c) == 0)) {
        *(uint32_t **)((intptr_t)DAT_0057c670 + 0x9c) = this_03;
        Sound_SelectCurrentTrack(DAT_0057ba0c);
      }
    }
    if (*(void **)((intptr_t)DAT_0057c670 + 0x264) != (void *)0x0) {
      UI_QueueControlCommand(*(void **)((intptr_t)DAT_0057c670 + 0x264),-0x18689,0x23,1);
    }
    if (*(int *)((intptr_t)self + arg3 * 0x168 + 0x118) != 0) {
      Company_PushRecentEntry(self,arg3,0xc,value1,-1);
      Company_PushRecentEntry(self,arg3,7,value1,-1);
      Company_PushRecentEntry(self,arg3,8,value1,-1);
      Company_PushRecentEntry(self,arg3,10,value1,-1);
    }
    if ((((*(int *)((intptr_t)self + arg3 * 0x168 + 0x114) == 0) &&
         (*(int *)((intptr_t)this_01 + 0x15c) == 2)) && (*(int *)((intptr_t)this_01 + 0x194) == 0)) &&
       (value3 = Game_HasQueuedEventType(DAT_0057c670,6), value3 == 0)) {
      value3 = UI_Briefing_Printf((intptr_t)DAT_0057c670,-1,5,1,0xb,0,DAT_00582d88,DAT_00582c4c,unaff_EDI)
      ;
      Game_SetMessageField34(DAT_0057c670,value3,6);
    }
  }
  else {
    Window_UnlockState((intptr_t)DAT_0057c670);
    value1 = -1;
  }
  ExceptionList = local_c;
  return value1;
}
