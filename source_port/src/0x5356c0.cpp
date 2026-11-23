// Font_MeasureRange: ported from Pizza Connection 2 at 0x5356c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5356c0
#include "pc2_port.h"

int __thiscall Font_MeasureRange(void *self,int arg1,int arg2,int arg3)

{
  char cVar1;
  uint8_t flag2;
  char *cptr3;
  int value4;
  uint32_t local_4;
  
  value4 = 0;
  cVar1 = *(char *)(arg2 + arg1);
  while ((cVar1 != '\0' && (cptr3 = (char *)(arg2 + arg1), arg2 < arg3))) {
    arg2 = arg2 + 1;
    local_4 = (uint32_t)(uint8_t)(*cptr3 - 0x20);
    if ((local_4 < 0xe0) && (*(int *)((intptr_t)self + local_4 * 4 + 0x460) != 0)) {
      flag2 = *(uint8_t *)(local_4 + 0x1c0 + (intptr_t)self);
    }
    else {
      flag2 = *(uint8_t *)((intptr_t)self + 0x1c0);
    }
    value4 = value4 + (uint32_t)flag2;
    cVar1 = *(char *)(arg2 + arg1);
  }
  return value4;
}
