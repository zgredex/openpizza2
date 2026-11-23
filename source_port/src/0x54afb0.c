// UI_RemoveAllById: ported from Pizza Connection 2 at 0x54afb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54afb0
#include "pc2_port.h"

void __thiscall UI_RemoveAllById(void *self,int arg1)

{
  int value1;
  int value2;
  int value3;
  int value4;
  
  value4 = 0;
  if ((arg1 == 0) || (*(int *)((intptr_t)self + 0x34) == 0)) {
    value3 = *(int *)((intptr_t)self + 0x18);
    if (0 < value3) {
      do {
        value1 = IDMap_Lookup((void *)((intptr_t)self + 4),value4,(int *)0x0);
        if (value1 != 0) {
          *(uint32_t *)(value1 + 8) = 0xffffffff;
        }
        value4 = value4 + 1;
      } while (value4 < value3);
      *(uint32_t *)((intptr_t)self + 0x30) = 0;
      *(uint32_t *)((intptr_t)self + 0x34) = 0;
      return;
    }
  }
  else {
    value4 = *(int *)((intptr_t)self + 0x18);
    value3 = 0;
    if (0 < value4) {
      do {
        value1 = IDMap_Lookup((void *)((intptr_t)self + 4),value3,(int *)0x0);
        if (*(int *)(value1 + 8) != -1) {
          value2 = Array_GetRecordByKeyPtr(*(void **)((intptr_t)self + 0x34),*(int *)(value1 + 8));
          if (value2 != 0) {
            UI_RemoveObject(*(void **)((intptr_t)self + 0x34),*(int *)(value1 + 8));
            *(uint32_t *)(value1 + 8) = 0xffffffff;
            *(uint32_t *)(value1 + 0x1c) = 0xbf800000;
          }
        }
        value3 = value3 + 1;
      } while (value3 < value4);
      *(uint32_t *)((intptr_t)self + 0x30) = 0;
      *(uint32_t *)((intptr_t)self + 0x34) = 0;
      return;
    }
  }
  *(uint32_t *)((intptr_t)self + 0x30) = 0;
  *(uint32_t *)((intptr_t)self + 0x34) = 0;
  return;
}
