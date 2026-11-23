// UI_OpenBriefing: ported from Pizza Connection 2 at 0x54adc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54adc0
#include "pc2_port.h"

uint32_t __thiscall UI_OpenBriefing(void *self,void *arg1,int arg2)

{
  int value1;
  int value2;
  int value3;
  int value4;
  
  value4 = arg2;
  if (*(int *)((intptr_t)self + 0x34) != 0) {
    return 0;
  }
  value3 = *(int *)((intptr_t)self + 0x20);
  *(void **)((intptr_t)self + 0x34) = arg1;
  *(int *)((intptr_t)self + 0x2c) = arg2;
  arg2 = *(int *)((intptr_t)self + 0x18) + -10;
  if (arg2 < 0) {
    arg2 = 0;
  }
  else if (8 < arg2) goto LAB_0054ae50;
  do {
    value1 = IDMap_Lookup((void *)((intptr_t)self + 4),arg2,(int *)0x0);
    if ((value1 != 0) && (value2 = Array_GetRecordByKeyPtr(arg1,value4), value2 == 0)) {
      UI_AddBriefingButton(self,value1,value4,value3);
      *(int *)(value1 + 0xc) = value3;
      *(uint32_t *)(value1 + 0x20) = 0;
      *(void **)(value1 + 0x18) = self;
      value4 = value4 + 1;
      value3 = value3 + *(int *)((intptr_t)self + 0x28);
    }
    arg2 = arg2 + 1;
  } while (arg2 < 9);
LAB_0054ae50:
  *(uint32_t *)((intptr_t)self + 0x30) = 1;
  return 1;
}
