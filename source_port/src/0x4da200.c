// Game_SetCompanyAdvancementScore: ported from Pizza Connection 2 at 0x4da200.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4da200
#include "pc2_port.h"

void __thiscall Game_SetCompanyAdvancementScore(void *self,int arg1,uint32_t arg2)

{
  int *ptr1;
  int value2;
  int value3;
  uint32_t *uptr4;
  
  *(uint32_t *)((intptr_t)self + arg1 * 4 + 0xdac) = arg2;
  if (*(int *)(*(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8) + 0xf8) != 0) {
    value3 = 0;
    uptr4 = (uint32_t *)((intptr_t)self + 0xdac);
    do {
      value2 = Game_GetPlayerBySlot(DAT_0057c670,value3);
      if ((value2 != 0) && (*uptr4 < arg2)) {
        ptr1 = (int *)(*(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8) + 0xf8);
        *ptr1 = *ptr1 + -1;
        break;
      }
      value3 = value3 + 1;
      uptr4 = uptr4 + 1;
    } while (value3 < 6);
  }
  Game_AdjustPlayerRankingScores((intptr_t)self);
  if (*(void **)((intptr_t)DAT_0057c670 + 0x264) != (void *)0x0) {
    UI_QueueControlCommand(*(void **)((intptr_t)DAT_0057c670 + 0x264),-0x18612,0x23,0);
  }
  return;
}
