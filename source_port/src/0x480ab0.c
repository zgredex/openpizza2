// MapObject_RemoveAndRefund: ported from Pizza Connection 2 at 0x480ab0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x480ab0
#include "pc2_port.h"

void __thiscall MapObject_RemoveAndRefund(void *self,uint32_t *arg1)

{
  int value1;
  uint32_t *uptr2;
  
                    /* Removes a map object, cancels orders, and refunds its city share. */
  uptr2 = arg1;
  value1 = *(int *)((intptr_t)*(void **)((intptr_t)self + 0x14e0) + 0x4c) + arg1[8] * 0xc;
  if ((value1 != 0) && (*(int *)(value1 + 8) != 0)) {
    Game_DrawMapObjectSprite(arg1,*(void **)((intptr_t)self + 0x14e0));
    Object_ClearState(value1);
    Map_SetTileFieldWithDefault(*(void **)((intptr_t)self + 0x14e0),value1,-1,1);
  }
  Branch_RemoveConstructionOrder(self,(intptr_t)uptr2);
  Game_ComputeCityPriceShare((intptr_t)self,(intptr_t)uptr2,(float *)&arg1);
  Stats_AddRecordValue(self,0x15,(float)(intptr_t)(arg1),-1);
  if (uptr2 != (uint32_t *)0x0) {
    (**(code **)*uptr2)(1);
  }
  return;
}
