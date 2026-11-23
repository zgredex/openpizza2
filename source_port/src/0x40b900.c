// Game_UpdateWorldObjects: ported from Pizza Connection 2 at 0x40b900.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x40b900
#include "pc2_port.h"

void __thiscall Game_UpdateWorldObjects(void *self,int arg1)

{
  uint32_t uvalue1;
  int value2;
  int value3;
  int value4;
  void *this_00;
  int value5;
  int value6;
  int local_10;
  
                    /* Dispatches one world-object simulation phase. */
  uvalue1 = Game_GetTimeSegment((intptr_t)self);
  if (*(int *)((intptr_t)self + 0x150c) != 0) {
    value5 = 0;
    if (0 < *(int *)((intptr_t)self + 0x50)) {
      do {
        value2 = IDMap_Lookup((void *)((intptr_t)self + 0x3c),value5,(int *)0x0);
        if (value2 != 0) {
          UI_ResetChildRecord(value2);
        }
        value5 = value5 + 1;
      } while (value5 < *(int *)((intptr_t)self + 0x50));
    }
    *(uint32_t *)((intptr_t)self + 0x150c) = 0;
  }
  value5 = Game_GetPlayerCount((intptr_t)self);
  local_10 = 0;
  if (0 < value5) {
    do {
      value3 = Game_GetPlayerBySlot(self,local_10);
      value2 = *(int *)(value3 + 0x15c);
      value6 = 0;
      if (0 < value2) {
        do {
          value4 = IDMap_Lookup((void *)(value3 + 0x148),value6,(int *)0x0);
          if (value4 != 0) {
            Object_AccumulateIncome(value4);
          }
          value6 = value6 + 1;
        } while (value6 < value2);
      }
      local_10 = local_10 + 1;
    } while (local_10 < value5);
  }
  value5 = *(int *)((intptr_t)self + 0x50) + -1;
  if (-1 < value5) {
    do {
      this_00 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x3c),value5,(int *)0x0);
      if (((this_00 != (void *)0x0) && (*(int *)((intptr_t)this_00 + 200) != 0)) &&
         (*(int *)((intptr_t)this_00 + 0x38) != 0x2e)) {
        if (*(int *)((intptr_t)this_00 + 0x74) == 0) {
          if (arg1 == 0) {
            IDMap_Lookup((void *)((intptr_t)self + 4),*(int *)((intptr_t)this_00 + 0x28),(int *)0x0);
            if (*(int *)((intptr_t)this_00 + 0xa0) == 0) {
              Person_UpdateBehavior(self,this_00);
            }
            else {
              Person_UpdateStreetBehavior(self,this_00,uvalue1);
            }
          }
        }
        else {
          Branch_UpdateConstruction(this_00,arg1);
          Person_UpdateIndoorAction(self,this_00);
        }
      }
      value5 = value5 + -1;
    } while (-1 < value5);
  }
  if (arg1 == 0) {
    if ((DAT_0057bb20 == '\0') &&
       (value5 = *(int *)(*(int *)((intptr_t)self + 0x224) + 0xac), *(int *)(value5 + 0xd0) == 0)) {
      Sound_PlayTutorialSpeech(DAT_0057ba0c,*(int *)(value5 + 0xd4),'\x01',DAT_0057c5c0 == 0);
    }
    if ((*(int *)((intptr_t)self + 0x268) == 0) && (*(void **)((intptr_t)self + 0x264) != (void *)0x0)) {
      UI_QueueControlCommand(*(void **)((intptr_t)self + 0x264),-0x18639,0x23,0);
    }
  }
  return;
}
