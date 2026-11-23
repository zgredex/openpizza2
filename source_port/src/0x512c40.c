// Recipe_AccumulateQualityDelta: ported from Pizza Connection 2 at 0x512c40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x512c40
#include "pc2_port.h"

void __thiscall Recipe_AccumulateQualityDelta(void *self,char *arg1,int arg2)

{
  char *cptr1;
  uint32_t uvalue2;
  
  cptr1 = Product_MapCategory(arg1);
  if (cptr1 != (char *)0x0) {
    uvalue2 = (uint32_t)(uint8_t)arg1[0x10] - (uint32_t)*(uint8_t *)(arg2 + 0x10);
    if (4 < (intptr_t)uvalue2) {
      uvalue2 = uvalue2 - 8;
    }
    if ((intptr_t)uvalue2 < -4) {
      uvalue2 = uvalue2 + 8;
    }
    *(uint32_t *)((intptr_t)self + 600) =
         *(int *)((intptr_t)self + 600) + ((uvalue2 ^ (intptr_t)uvalue2 >> 0x1f) - ((intptr_t)uvalue2 >> 0x1f)) + -2;
    *(int *)((intptr_t)self + 0x260) = *(int *)((intptr_t)self + 0x260) + 1;
  }
  return;
}
