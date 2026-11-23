// Memory_Fill16: ported from Pizza Connection 2 at 0x539770.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x539770
#include "pc2_port.h"

void Memory_Fill16(uint32_t *arg1,uint32_t *arg2,uint32_t arg3,int arg4)

{
  uint32_t uvalue1;
  uint32_t *uptr2;
  uint32_t uvalue3;
  int value4;
  int value5;
  
  uvalue1 = arg3;
  if (0 < (intptr_t)arg3) {
    uptr2 = arg2;
    if (arg4 == 0) {
      uptr2 = arg1;
    }
    uvalue3 = -((uint32_t)uptr2 & 3) & 3;
    if ((intptr_t)arg3 < (intptr_t)uvalue3) {
      uvalue3 = arg3;
    }
    arg3 = uvalue3;
    value4 = (intptr_t)(uvalue1 - arg3) >> 2;
    value5 = (uvalue1 - arg3) + value4 * -4;
    if (arg3 != 0) {
      for (; arg3 != 0; arg3 = arg3 - 1) {
        *(uint8_t *)arg1 = *(uint8_t *)arg2;
        arg2 = (uint32_t *)((intptr_t)arg2 + 1);
        arg1 = (uint32_t *)((intptr_t)arg1 + 1);
      }
    }
    if (value4 != 0) {
      for (; value4 != 0; value4 = value4 + -1) {
        *arg1 = *arg2;
        arg2 = arg2 + 1;
        arg1 = arg1 + 1;
      }
    }
    if (value5 != 0) {
      for (; value5 != 0; value5 = value5 + -1) {
        *(uint8_t *)arg1 = *(uint8_t *)arg2;
        arg2 = (uint32_t *)((intptr_t)arg2 + 1);
        arg1 = (uint32_t *)((intptr_t)arg1 + 1);
      }
    }
  }
  return;
}
