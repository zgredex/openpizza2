// Sound_SetVolume: ported from Pizza Connection 2 at 0x547270.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x547270
#include "pc2_port.h"

uint32_t __thiscall Sound_SetVolume(void *self,uint32_t arg1)

{
  uint32_t in_EAX;
  uint32_t uvalue1;
  uint32_t uvalue2;
  uint32_t uStack_4;
  
  uvalue1 = in_EAX & 0xffffff00;
  uStack_4 = (uint32_t)self & 0xffffff;
  if (arg1 != 0) {
    uvalue2 = (**(code **)(**(int **)((intptr_t)self + 8) + 0xf8))
                      (*(int **)((intptr_t)self + 8),arg1,(intptr_t)&uStack_4 + 3);
    uvalue1 = CONCAT31((int3)((uint32_t)uvalue2 >> 8),(char)(arg1 >> 0x18));
  }
  return uvalue1;
}
