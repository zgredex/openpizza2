// Game_ApplyOwnerWideObjectEvent: ported from Pizza Connection 2 at 0x480d80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x480d80
#include "pc2_port.h"

void __thiscall Game_ApplyOwnerWideObjectEvent(void *self,int arg1)

{
  void *this_00;
  void *this_01;
  int *ptr1;
  int value2;
  
  value2 = 0;
  this_00 = *(void **)((intptr_t)self + 0x16f0);
  if (0 < *(int *)((intptr_t)this_00 + 0x8c)) {
    do {
      this_01 = (void *)Game_MapRecordToGlobal(this_00,value2);
      if (((-1 < *(int *)((intptr_t)this_01 + 0x30)) && (*(int *)((intptr_t)this_01 + 0x30) < 8)) &&
         (*(int *)((intptr_t)this_01 + 0x88) == *(int *)(arg1 + 0x20))) {
        if ((*(short *)((intptr_t)this_01 + 0x40) == 9) &&
           (ptr1 = (int *)Game_ApplyObjectEvent((intptr_t)this_01), ptr1 != (int *)0x0)) {
          UI_DrawCenteredSelectionRect(*(void **)((intptr_t)self + 0x14e0),ptr1);
        }
        *(uint8_t *)((intptr_t)this_01 + 0x81) = 1;
        UI_SetChildState(this_01,0x14);
        Game_GetTimeByMode(this_01,7);
        Object_SyncChildState(this_01,(intptr_t)self,0);
        *(uint32_t *)((intptr_t)this_01 + *(int *)((intptr_t)self + 0x30) * 4 + 0xac) = 0x14;
      }
      value2 = value2 + 1;
    } while (value2 < *(int *)((intptr_t)this_00 + 0x8c));
  }
  return;
}
