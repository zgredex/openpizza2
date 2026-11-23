// UI_SelectObjectRecord: ported from Pizza Connection 2 at 0x524fd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x524fd0
#include "pc2_port.h"

void __thiscall UI_SelectObjectRecord(void *self,void *arg1,int arg2)

{
  int *ptr1;
  int *ptr2;
  int value3;
  
  if (((arg1 != (void *)0x0) && (*(int *)((intptr_t)arg1 + 0x4c) != 0)) &&
     ((*(void **)((intptr_t)self + 0x228) == (void *)0x0 || (*(void **)((intptr_t)self + 0x228) == arg1))))
  {
    UI_RefreshChildRect(self);
    ptr2 = (int *)Array_GetRecordByKey(arg1,arg2);
    ptr1 = *(int **)((intptr_t)self + 0x22c);
    if ((ptr1 != (int *)0x0) && (ptr1 != ptr2)) {
      (**(code **)(*ptr1 + 0xc))(10,0,0);
      *(uint32_t *)((intptr_t)self + 0x224) = 0;
      *(uint32_t *)((intptr_t)self + 0x22c) = 0;
    }
    *(int **)((intptr_t)self + 0x82d4) = ptr2;
    *(void **)((intptr_t)self + 0x82c8) = arg1;
    value3 = (**(code **)(*ptr2 + 0xc))(0xb,0,0);
    if (value3 != 0) {
      *(uint32_t *)((intptr_t)self + 0x224) = *(uint32_t *)((intptr_t)self + 0x82c8);
      *(uint32_t *)((intptr_t)self + 0x22c) = *(uint32_t *)((intptr_t)self + 0x82d4);
      return;
    }
    *(uint32_t *)((intptr_t)self + 0x224) = 0;
    *(uint32_t *)((intptr_t)self + 0x22c) = 0;
  }
  return;
}
