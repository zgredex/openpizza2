// Array_GetRandomRecord28B: ported from Pizza Connection 2 at 0x4f1280.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f1280
#include "pc2_port.h"

int __thiscall Array_GetRandomRecord28B(void *self,int *arg1)

{
  uint32_t uvalue1;
  int *local_4;
  
  local_4 = self;
  Object_GetBufferPair
            (self,(intptr_t)arg1,(int *)&local_4,(int *)&arg1,(uint32_t *)0x0,(uint32_t *)0x0);
  uvalue1 = Random_RangeFast(0,*arg1 - 1);
  return *local_4 + uvalue1 * 0x28;
}
