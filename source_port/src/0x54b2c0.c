// MessageList_SetField34: ported from Pizza Connection 2 at 0x54b2c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54b2c0
#include "pc2_port.h"

void __thiscall MessageList_SetField34(void *self,int arg1,uint32_t arg2)

{
  int value1;
  
  value1 = IDMap_Lookup((void *)((intptr_t)self + 4),arg1,(int *)0x0);
  if (value1 != 0) {
    *(uint32_t *)(value1 + 0x34) = arg2;
  }
  return;
}
