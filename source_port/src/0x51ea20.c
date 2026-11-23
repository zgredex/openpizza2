// UI_SetElementSprite: ported from Pizza Connection 2 at 0x51ea20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x51ea20
#include "pc2_port.h"

uint32_t __thiscall UI_SetElementSprite(void *self,void *arg1,int arg2,int arg3)

{
  int value1;
  int value2;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  CS_Enter(*(int *)(*(int *)((intptr_t)self + 8) + 0x1c8));
  *(void **)self = arg1;
  Sprite_GetSize(arg1,&local_c,&local_10);
  if (arg2 != -9999) {
    *(int *)((intptr_t)self + 0x1c) = arg2;
  }
  if (arg3 != -9999) {
    *(int *)((intptr_t)self + 0x20) = arg3;
  }
  *(uint32_t *)((intptr_t)self + 0x14) = 1;
  value2 = *(int *)(*(int *)((intptr_t)self + 8) + 0x248);
  value1 = *(int *)(*(int *)((intptr_t)self + 8) + 0x24c);
  Sprite_GetHotspot(*(void **)self,&local_4,&local_8);
  value1 = value1 + *(int *)((intptr_t)self + 0x20);
  value2 = value2 + *(int *)((intptr_t)self + 0x1c);
  Rect_Union(*(void **)((intptr_t)self + 8),value2,value1,value2 + local_c,value1 + local_10);
  if (*(int *)((intptr_t)self + 0x18) == 0) {
    *(int *)((intptr_t)self + 0xc) = value2;
    *(int *)((intptr_t)self + 0x10) = value1;
  }
  CS_Leave(*(int *)(*(int *)((intptr_t)self + 8) + 0x1c8));
  return 1;
}
