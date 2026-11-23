// AI_UpdateAdvertisingCampaigns: ported from Pizza Connection 2 at 0x4fecc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fecc0
#include "pc2_port.h"

uint32_t __thiscall AI_UpdateAdvertisingCampaigns(void *self,int arg1)

{
  int value1;
  int value2;
  bool flag3;
  int value4;
  void *this_00;
  char *cptr5;
  int value6;
  int64_t lvalue7;
  int64_t lvalue8;
  uint8_t *bptr9;
  
                    /* Starts or stops AI advertising campaigns based on player totals. */
  value1 = *(int *)((intptr_t)self + arg1 * 0x168 + 0x70);
  value2 = *(int *)((intptr_t)self + arg1 * 0x168 + 0x40);
  value4 = Game_GetPlayerCount((intptr_t)DAT_0057c670);
  arg1 = 0;
  if (value4 < 1) {
    return 1;
  }
  do {
    this_00 = (void *)Game_GetPlayerBySlot(DAT_0057c670,arg1);
    if (*(int *)((intptr_t)this_00 + value2 * 4 + 0x94) != 0) {
      Player_ComputeNetStatTotal(value1);
      lvalue7 = __ftol();
      Player_ComputeNetStatTotal((intptr_t)this_00);
      lvalue8 = __ftol();
      flag3 = (0x14 - DAT_0057bb24) * (intptr_t)lvalue8 * 10 < (intptr_t)lvalue7 * 100;
      value6 = (intptr_t)lvalue7 >> 3;
      if (*(char *)((intptr_t)this_00 + value2 + 0xac) == '\0') {
        if (((!flag3) && (*(int *)((intptr_t)this_00 + value2 * 4 + 0x94) <= value6)) &&
           (Player_InitSlotFlags(this_00,value2),
           this_00 ==
           *(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200))) {
          cptr5 = DAT_00582984;
          bptr9 = DAT_00581ab8;
          goto LAB_004fede8;
        }
      }
      else if (((flag3) || (value6 < *(int *)((intptr_t)this_00 + value2 * 4 + 0x94))) &&
              (Advertising_StopCampaign(this_00,value2,*(int *)(value1 + 0x48),1),
              this_00 ==
              *(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200))) {
        cptr5 = DAT_00580f04;
        bptr9 = DAT_005816b4;
LAB_004fede8:
        UI_Briefing_Printf((intptr_t)DAT_0057c670,-1,4,-1,-1,0,cptr5,bptr9,value1 + 8);
      }
    }
    arg1 = arg1 + 1;
    if (value4 <= arg1) {
      return 1;
    }
  } while( true );
}
