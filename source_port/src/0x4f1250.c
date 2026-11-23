// Object_GetBufferCount: ported from Pizza Connection 2 at 0x4f1250.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f1250
#include "pc2_port.h"

uint32_t __thiscall Object_GetBufferCount(void *self,uint32_t *arg1)

{
  void *local_4;
  
  local_4 = self;
  Object_GetBufferPair
            (self,(intptr_t)arg1,(int *)&local_4,(int *)&arg1,(uint32_t *)0x0,(uint32_t *)0x0);
  return *arg1;
}
