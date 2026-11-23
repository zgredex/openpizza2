// City_SettleAdvertisingCampaign: ported from Pizza Connection 2 at 0x4dce70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dce70
#include "pc2_port.h"


void __fastcall City_SettleAdvertisingCampaign(int arg1)

{
  int value1;
  int value2;
  void *self;
  void *this_00;
  uint32_t *uptr3;
  int value4;
  int value5;
  uint8_t *bptr6;
  int local_110;
  uint8_t local_10c [256];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Scores and settles a finished city advertising campaign. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055924e;
  local_c = ExceptionList;
  value5 = 0;
  local_110 = 0;
  value4 = 0;
  ExceptionList = &local_c;
  do {
    value1 = Game_GetPlayerBySlot(DAT_0057c670,value5);
    if ((value1 != 0) &&
       ((*(int *)(value1 + 0x50) == 0 ||
        (value1 == *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200)))))
    {
      if (*(void **)(value1 + 0x1d4) == (void *)0x0) {
        value2 = 0;
      }
      else {
        Recipe_RecomputeAllStats(*(void **)(value1 + 0x1d4),*(int *)(value1 + 0x48));
        value2 = Game_MapInputIndex(*(void **)(value1 + 0x1d4),*(int *)(arg1 + 0x1148));
      }
      if (local_110 < value2) {
        value4 = *(int *)(value1 + 0x48);
        local_110 = value2;
      }
    }
    value5 = value5 + 1;
  } while (value5 < 6);
  self = (void *)Game_GetPlayerBySlot(DAT_0057c670,value4);
  *(int *)((intptr_t)self + 0x54) = *(int *)((intptr_t)self + 0x54) + 1;
  Company_AddLedgerAmount(self,0x18,(float)*(int *)(arg1 + 0x1150),0xffffffff,'\0');
  value4 = Game_GetPlayerCity((intptr_t)self);
  if (self == *(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200)) {
    UI_AppendCommandIfActive(*(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8),0x13,-1);
    MissionGoal_HandleEvent(*(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8),0x13,-1,-1);
  }
  this_00 = operator_new(0xc);
  local_4 = 0;
  if (this_00 == (void *)0x0) {
    uptr3 = (uint32_t *)0x0;
  }
  else {
    uptr3 = Player_Event_StreamConstruct(this_00,(void *)0x0);
  }
  local_4 = 0xffffffff;
  uptr3[1] = 0;
  List_Add((void *)(value4 + 0x8c),uptr3);
  bptr6 = local_10c;
  String_Format(bptr6,DAT_005828b0,(intptr_t)self + 8);
  UI_Briefing_Printf((intptr_t)DAT_0057c670,-1,3,1,2,0,DAT_00581744,local_10c,bptr6);
  *(uint32_t *)(arg1 + 0x1148) = 0;
  *(uint32_t *)(arg1 + 0x114c) = 0;
  *(uint32_t *)(arg1 + 0x1150) = 0;
  *(uint32_t *)(arg1 + 0x1154) = 0;
  value4 = 0;
  do {
    value5 = Game_GetPlayerBySlot(DAT_0057c670,value4);
    if (value5 != 0) {
      *(uint32_t *)(value5 + 0x50) = 0xffffffff;
    }
    value4 = value4 + 1;
  } while (value4 < 6);
  ExceptionList = local_c;
  return;
}
