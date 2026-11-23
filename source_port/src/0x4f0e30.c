// Object_AppendBufferRecord: ported from Pizza Connection 2 at 0x4f0e30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f0e30
#include "pc2_port.h"

int __thiscall Object_AppendBufferRecord(void *self,int *arg1,int arg2,int arg3)

{
  int value1;
  uint16_t uvalue2;
  void *pvVar3;
  int value4;
  uint32_t uvalue5;
  int value6;
  uint32_t *uptr7;
  uint32_t *uptr8;
  int *local_8;
  uint32_t *local_4;
  
  Object_GetBufferPair
            (self,(intptr_t)arg1,(int *)&arg1,(int *)&local_8,(uint32_t *)0x0,(uint32_t *)0x0);
  if (*arg1 == 0) {
    pvVar3 = operator_new(0x28);
    *arg1 = (intptr_t)pvVar3;
  }
  else {
    local_4 = operator_new((*local_8 + 1) * 0x28);
    uptr7 = (uint32_t *)*arg1;
    uptr8 = local_4;
    for (uvalue5 = (uint32_t)(*local_8 * 0x28) >> 2; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
      *uptr8 = *uptr7;
      uptr7 = uptr7 + 1;
      uptr8 = uptr8 + 1;
    }
    for (value6 = 0; value6 != 0; value6 = value6 + -1) {
      *(uint8_t *)uptr8 = *(uint8_t *)uptr7;
      uptr7 = (uint32_t *)((intptr_t)uptr7 + 1);
      uptr8 = (uint32_t *)((intptr_t)uptr8 + 1);
    }
    Mem_Free((LPVOID)*arg1);
    *arg1 = (intptr_t)local_4;
  }
  value1 = arg3;
  value6 = arg2;
  value4 = Map_ComputeBlitRect(self,arg2,arg3,(int *)0x0,0);
  if (value4 == 0) {
    NoOp_Stub();
  }
  else {
    *(uint32_t *)(*arg1 + 8 + *local_8 * 0x28) = **(uint32_t **)(value4 + 8);
  }
  *(uint8_t *)(*arg1 + *local_8 * 0x28) = 0;
  uvalue2 = Counter_IncrementShortBA((intptr_t)self);
  *(uint16_t *)(*arg1 + 2 + *local_8 * 0x28) = uvalue2;
  *(short *)(*arg1 + 4 + *local_8 * 0x28) = (short)*local_8;
  *(uint8_t *)(*arg1 + 6 + *local_8 * 0x28) = 0;
  *(int *)(*arg1 + 0xc + *local_8 * 0x28) = *(int *)((intptr_t)self + 0x24) + value6;
  *(int *)(*arg1 + 0x10 + *local_8 * 0x28) = *(int *)((intptr_t)self + 0x28) + value1;
  *(uint16_t *)(*arg1 + 0x14 + *local_8 * 0x28) = 0xffff;
  *(uint16_t *)(*arg1 + 0x16 + *local_8 * 0x28) = 0xffff;
  *(uint16_t *)(*arg1 + 0x18 + *local_8 * 0x28) = 0xffff;
  *(uint16_t *)(*arg1 + 0x1a + *local_8 * 0x28) = 0xffff;
  *(uint16_t *)(*arg1 + 0x1c + *local_8 * 0x28) = 0xffff;
  *(uint16_t *)(*arg1 + 0x1e + *local_8 * 0x28) = 0xffff;
  *(uint16_t *)(*arg1 + 0x20 + *local_8 * 0x28) = 0xffff;
  *(uint16_t *)(*arg1 + 0x22 + *local_8 * 0x28) = 0xffff;
  *(uint8_t *)(*arg1 + 0x24 + *local_8 * 0x28) = 0;
  *local_8 = *local_8 + 1;
  return *arg1 + -0x28 + *local_8 * 0x28;
}
