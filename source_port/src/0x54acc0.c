// Sound_GetChannelObject: ported from Pizza Connection 2 at 0x54acc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54acc0
#include "pc2_port.h"

uint32_t __thiscall Sound_GetChannelObject(void *self,int arg1,int arg2)

{
  void *this_00;
  int value1;
  int value2;
  LPVOID pvVar3;
  int value4;
  int value5;
  int value6;
  
  this_00 = (void *)((intptr_t)self + 4);
  pvVar3 = (LPVOID)IDMap_Lookup(this_00,arg1,(int *)0x0);
  if (pvVar3 == (LPVOID)0x0) {
    return 0;
  }
  if ((*(int *)((intptr_t)pvVar3 + 0x14) != 0) && (arg2 == 0)) {
    return 0;
  }
  if (*(int *)((intptr_t)pvVar3 + 8) != -1) {
    UI_RemoveObject(*(void **)((intptr_t)self + 0x34),*(int *)((intptr_t)pvVar3 + 8));
    value1 = *(int *)((intptr_t)self + 0x18);
    value2 = *(int *)((intptr_t)pvVar3 + 0xc);
    value6 = 0;
    if (0 < value1) {
      do {
        value4 = IDMap_Lookup(this_00,value6,(int *)0x0);
        if ((value4 != 0) && (value2 < *(int *)(value4 + 0xc))) {
          value5 = *(int *)(value4 + 0xc) - *(int *)((intptr_t)self + 0x28);
          *(int *)(value4 + 0xc) = value5;
          *(float *)(value4 + 0x20) = -(*(float *)(value4 + 0x1c) - (float)value5);
        }
        value6 = value6 + 1;
      } while (value6 < value1);
    }
  }
  IDMap_RemoveByKey(this_00,(intptr_t)pvVar3);
  Mem_Free(pvVar3);
  return 1;
}
