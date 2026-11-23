// Object_UpdateBufferRecord: ported from Pizza Connection 2 at 0x4f1070.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f1070
#include "pc2_port.h"

int __thiscall Object_UpdateBufferRecord(void *self,int *arg1,int arg2,int arg3)

{
  int value1;
  int value2;
  uint16_t uvalue3;
  int value4;
  int *local_4;
  
  local_4 = self;
  Object_GetBufferPair
            (self,(intptr_t)arg1,(int *)&local_4,(int *)&arg1,(uint32_t *)0x0,(uint32_t *)0x0);
  if (*local_4 == 0) {
    NoOp_Stub();
  }
  value2 = arg3;
  value1 = arg2;
  value4 = Map_ComputeBlitRect(self,arg2,arg3,(int *)0x0,0);
  if (value4 == 0) {
    NoOp_Stub();
  }
  else {
    *(uint32_t *)(*local_4 + 8 + *arg1 * 0x28) = **(uint32_t **)(value4 + 8);
  }
  *(uint8_t *)(*local_4 + *arg1 * 0x28) = 0;
  uvalue3 = Counter_IncrementShortBA((intptr_t)self);
  *(uint16_t *)(*local_4 + 2 + *arg1 * 0x28) = uvalue3;
  *(short *)(*local_4 + 4 + *arg1 * 0x28) = (short)*arg1;
  *(uint8_t *)(*local_4 + 6 + *arg1 * 0x28) = 0;
  *(int *)(*local_4 + 0xc + *arg1 * 0x28) = *(int *)((intptr_t)self + 0x24) + value1;
  *(int *)(*local_4 + 0x10 + *arg1 * 0x28) = *(int *)((intptr_t)self + 0x28) + value2;
  *(uint16_t *)(*local_4 + 0x14 + *arg1 * 0x28) = 0xffff;
  *(uint16_t *)(*local_4 + 0x16 + *arg1 * 0x28) = 0xffff;
  *(uint16_t *)(*local_4 + 0x18 + *arg1 * 0x28) = 0xffff;
  *(uint16_t *)(*local_4 + 0x1a + *arg1 * 0x28) = 0xffff;
  *(uint16_t *)(*local_4 + 0x1c + *arg1 * 0x28) = 0xffff;
  *(uint16_t *)(*local_4 + 0x1e + *arg1 * 0x28) = 0xffff;
  *(uint16_t *)(*local_4 + 0x20 + *arg1 * 0x28) = 0xffff;
  *(uint16_t *)(*local_4 + 0x22 + *arg1 * 0x28) = 0xffff;
  *(uint8_t *)(*local_4 + 0x24 + *arg1 * 0x28) = 0;
  *arg1 = *arg1 + 1;
  return *local_4 + -0x28 + *arg1 * 0x28;
}
