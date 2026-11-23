// UI_HitTestChildAtPoint: ported from Pizza Connection 2 at 0x5300e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5300e0
#include "pc2_port.h"

void * __thiscall UI_HitTestChildAtPoint(void *self,int *arg1,uint32_t *arg2)

{
  int value1;
  void *pvVar2;
  int value3;
  int value4;
  bool flag5;
  int value6;
  uint32_t extraout_var;
  uint32_t extraout_var_00;
  
  *arg2 = 1;
  value1 = *(int *)((intptr_t)self + 0xf0);
  while (value1 = value1 + -1, -1 < value1) {
    pvVar2 = *(void **)(*(int *)((intptr_t)self + 0xec) + value1 * 8);
    if ((pvVar2 != (void *)0x0) &&
       (value6 = UI_IsValidSize(pvVar2,*arg1 - *(int *)((intptr_t)self + 0x18),
                               arg1[1] - *(int *)((intptr_t)self + 0x1c)), value6 != 0)) {
      return pvVar2;
    }
  }
  pvVar2 = *(void **)((intptr_t)self + 0x50);
  if (pvVar2 == (void *)0x0) {
    pvVar2 = *(void **)((intptr_t)self + 0x94);
    if (pvVar2 != (void *)0x0) {
      value1 = arg1[1];
      value6 = *(int *)((intptr_t)self + 0x1c);
      value3 = *arg1;
      value4 = *(int *)((intptr_t)self + 0x18);
      if (*(char *)((intptr_t)pvVar2 + 0x39) == '\0') {
        Sprite_RealizeLazy(pvVar2);
      }
      flag5 = Sprite_BlitClipped(pvVar2,*(uint16_t **)((intptr_t)pvVar2 + 0x2c),value3 - value4,value1 - value6
                                 ,(uint32_t *)0x0);
      if (CONCAT31(extraout_var_00,flag5) == 0) {
        *arg2 = 0;
      }
    }
  }
  else {
    value1 = arg1[1];
    value6 = *(int *)((intptr_t)self + 0x1c);
    value3 = *arg1;
    value4 = *(int *)((intptr_t)self + 0x18);
    if (*(char *)((intptr_t)pvVar2 + 0x39) == '\0') {
      Sprite_RealizeLazy(pvVar2);
    }
    flag5 = Sprite_BlitClipped(pvVar2,*(uint16_t **)((intptr_t)pvVar2 + 0x2c),value3 - value4,value1 - value6,
                               (uint32_t *)0x0);
    if (CONCAT31(extraout_var,flag5) == 0) {
      *arg2 = 0;
      return (void *)0x0;
    }
  }
  return (void *)0x0;
}
