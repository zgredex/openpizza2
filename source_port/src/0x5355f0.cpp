// Font_MeasureText: ported from Pizza Connection 2 at 0x5355f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5355f0
#include "pc2_port.h"

int __thiscall Font_MeasureText(void *self,char *arg1)

{
  char cVar1;
  uint8_t flag2;
  int value3;
  uint32_t local_4;
  
  value3 = 0;
  cVar1 = *arg1;
  while (cVar1 != '\0') {
    cVar1 = *arg1;
    arg1 = arg1 + 1;
    local_4 = (uint32_t)(uint8_t)(cVar1 - 0x20);
    if ((local_4 < 0xe0) && (*(int *)((intptr_t)self + local_4 * 4 + 0x460) != 0)) {
      flag2 = *(uint8_t *)(local_4 + 0x1c0 + (intptr_t)self);
    }
    else {
      flag2 = *(uint8_t *)((intptr_t)self + 0x1c0);
    }
    value3 = value3 + (uint32_t)flag2;
    cVar1 = *arg1;
  }
  return value3;
}
