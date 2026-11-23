// Game_ApplyAreaObjectEvent: ported from Pizza Connection 2 at 0x50b460.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50b460
#include "pc2_port.h"

void __thiscall Game_ApplyAreaObjectEvent(void *self,int arg1)

{
  void *this_00;
  bool flag1;
  void *this_01;
  void *this_02;
  int *ptr2;
  int value3;
  int value4;
  int local_1c;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  ptr2 = *(int **)((intptr_t)self + 200);
  flag1 = false;
  if (ptr2 != (int *)0x0) {
    value4 = *(int *)((intptr_t)self + 0x30);
    this_00 = *(void **)((intptr_t)self + 0xf4);
    Record_GetTwoFloats48((void *)ptr2[0x16],*ptr2,&local_c,&local_4);
    local_1c = 0;
    if (0 < *(int *)((intptr_t)this_00 + 0x8c)) {
      do {
        this_01 = (void *)Game_MapRecordToGlobal(this_00,local_1c);
        if ((-1 < *(int *)((intptr_t)this_01 + 0x30)) && (*(int *)((intptr_t)this_01 + 0x30) < 8)) {
          ptr2 = *(int **)((intptr_t)this_01 + 200);
          if (ptr2 == (int *)0x0) {
            value3 = -1;
            this_02 = (void *)0x0;
          }
          else {
            value3 = *ptr2;
            this_02 = (void *)ptr2[0x16];
          }
          Record_GetTwoFloats48(this_02,value3,&local_10,&local_8);
          if ((local_10 - local_c) * (local_10 - local_c) +
              (local_8 - local_4) * (local_8 - local_4) * 4 <
              (intptr_t)((-(uint32_t)(value4 != 0x2d) & 0xffff3224) + 0xe100)) {
            if ((*(short *)((intptr_t)this_01 + 0x40) == 9) &&
               (ptr2 = (int *)Game_ApplyObjectEvent((intptr_t)this_01), ptr2 != (int *)0x0)) {
              UI_DrawCenteredSelectionRect(*(void **)((intptr_t)self + 0xc4),ptr2);
            }
            *(uint8_t *)((intptr_t)this_01 + 0x81) = 1;
            UI_SetChildState(this_01,0x14);
            Game_GetTimeByMode(this_01,7);
            Object_SyncChildState(this_01,arg1,0);
            flag1 = true;
            *(uint32_t *)((intptr_t)self + *(int *)(arg1 + 0x30) * 4 + 0xac) = 0;
          }
        }
        local_1c = local_1c + 1;
      } while (local_1c < *(int *)((intptr_t)this_00 + 0x8c));
      if (flag1) {
        if (*(int *)((intptr_t)self + 0x30) == 0x2d) {
          value4 = 0x26;
        }
        else {
          value4 = 0x27;
        }
        Sound_HandleEvent(DAT_0057ba0c,arg1,value4);
      }
    }
  }
  return;
}
