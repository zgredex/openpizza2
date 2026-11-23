// Object_FindRecordByKey28: ported from Pizza Connection 2 at 0x4f0c60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f0c60
#include "pc2_port.h"

int __thiscall Object_FindRecordByKey28(void *self,int *arg1,uint32_t arg2)

{
  int value1;
  uint16_t *uptr2;
  int *local_4;
  
  local_4 = self;
  Object_GetBufferPair
            (self,(intptr_t)arg1,(int *)&local_4,(int *)&arg1,(uint32_t *)0x0,(uint32_t *)0x0);
  value1 = 0;
  if (0 < *arg1) {
    uptr2 = (uint16_t *)(*local_4 + 2);
    do {
      if (*uptr2 == arg2) {
        return *local_4 + value1 * 0x28;
      }
      value1 = value1 + 1;
      uptr2 = uptr2 + 0x14;
    } while (value1 < *arg1);
  }
  return 0;
}
