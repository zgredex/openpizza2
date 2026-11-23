// Object_ClearRecordFirstBytes: ported from Pizza Connection 2 at 0x4edb70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4edb70
#include "pc2_port.h"

void __thiscall Object_ClearRecordFirstBytes(void *self,int *arg1)

{
  int value1;
  int value2;
  int *local_4;
  
  local_4 = self;
  Object_GetBufferPair
            (self,(intptr_t)arg1,(int *)&local_4,(int *)&arg1,(uint32_t *)0x0,(uint32_t *)0x0);
  value1 = 0;
  if (0 < *arg1) {
    value2 = 0;
    do {
      value1 = value1 + 1;
      value2 = value2 + 0x28;
      *(uint8_t *)(*local_4 + -0x28 + value2) = 0;
    } while (value1 < *arg1);
  }
  return;
}
