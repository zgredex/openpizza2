// AI_StartAdvertisingCampaign: ported from Pizza Connection 2 at 0x4fee30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fee30
#include "pc2_port.h"

uint32_t AI_StartAdvertisingCampaign(void *arg1,int arg2)

{
  char cVar1;
  int value2;
  int value3;
  int value4;
  int value5;
  int *ptr6;
  int64_t lvalue7;
  int64_t lvalue8;
  
                    /* Starts or stops an AI advertising campaign. */
  value2 = *(int *)(arg2 + 0x30);
  value4 = Game_GetPlayerBySlot(DAT_0057c670,value2);
  cVar1 = *(char *)(value2 + 0xac + (intptr_t)arg1);
  Player_ComputeNetStatTotal(value4);
  lvalue7 = __ftol();
  Player_ComputeNetStatTotal((intptr_t)arg1);
  lvalue8 = __ftol();
  if ((intptr_t)lvalue8 < 0) {
    value5 = _rand();
    if (((uint8_t)value5 & 3) != 3) {
      return 1;
    }
    value5 = (intptr_t)lvalue7 / 0x19;
  }
  else {
    value5 = (intptr_t)lvalue8 / 0x14;
  }
  value3 = (intptr_t)lvalue7 / 0x14;
  if (value3 <= value5) {
    value5 = value3;
  }
  if (999 < value5) {
    if (cVar1 != '\0') {
      if (value5 * 2 < *(int *)((intptr_t)arg1 + value2 * 4 + 0x94) * 3) {
        return 1;
      }
      Advertising_StopCampaign(arg1,value2,*(int *)((intptr_t)arg1 + 0x48),1);
      if (value4 == *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200)) {
        UI_Briefing_Printf((intptr_t)DAT_0057c670,-1,4,-1,-1,0,DAT_00580f04,DAT_00581d3c,value4 + 8);
      }
    }
    ptr6 = Game_FindFreeStaffRecord(arg1,0x1d);
    if ((ptr6 != (int *)0x0) &&
       (Advertising_StartCampaignAgainstPlayer(arg1,arg2,value5,ptr6),
       value4 == *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200))) {
      UI_Briefing_Printf((intptr_t)DAT_0057c670,-1,4,-1,-1,0,DAT_005825a8,DAT_005817bc,(intptr_t)arg1 + 8);
    }
  }
  return 1;
}
