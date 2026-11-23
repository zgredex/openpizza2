// Map_PickObjectsAtPoint: ported from Pizza Connection 2 at 0x4d64b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d64b0
#include "pc2_port.h"

void __thiscall Map_PickObjectsAtPoint(void *self,void *arg1,int arg2,int arg3)

{
  int value1;
  uint8_t *uptr2;
  int value3;
  int value4;
  
  value4 = arg2 << ((uint8_t)DAT_00580a50 & 0x1f);
  arg2 = 0;
  value4 = value4 + *(int *)(*(int *)((intptr_t)self + 0xfa8) + 0x24);
  value3 = (arg3 << ((uint8_t)DAT_00580a50 & 0x1f)) + *(int *)(*(int *)((intptr_t)self + 0xfa8) + 0x28);
  if (0 < *(int *)((intptr_t)self + 0xfc0)) {
    do {
      value1 = IDMap_Lookup((void *)((intptr_t)self + 0xfac),arg2,(int *)0x0);
      if (((value1 != 0) && (*(int *)(value1 + 4) != 0x20)) && (*(int *)(value1 + 0xc) != 0x12378d6)) {
        if (((*(int *)(value1 + 0x10) <= value4) && (value4 <= *(int *)(value1 + 0x18))) &&
           ((*(int *)(value1 + 0x14) <= value3 && (value3 <= *(int *)(value1 + 0x1c))))) {
          uptr2 = operator_new(8);
          *uptr2 = 2;
          *(int *)(uptr2 + 4) = value1;
          List_Add(arg1,uptr2);
        }
      }
      arg2 = arg2 + 1;
    } while (arg2 < *(int *)((intptr_t)self + 0xfc0));
  }
  return;
}
