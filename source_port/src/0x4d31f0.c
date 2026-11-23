// Car_Construct: ported from Pizza Connection 2 at 0x4d31f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d31f0
#include "pc2_port.h"

uint32_t * __thiscall Car_Construct(void *self,int arg1)

{
  int value1;
  uint32_t uvalue2;
  
  *(uint8_t ***)self = &PTR_Car_Delete_0055c4f8;
  value1 = IDMap_Lookup((void *)(DAT_0057c670 + 4),arg1,(int *)0x0);
  *(uint32_t *)((intptr_t)self + 4) = *(uint32_t *)(value1 + 0xfa8);
  uvalue2 = Random_RangeFast(0,0x2c);
  *(uint32_t *)((intptr_t)self + 0xc) = uvalue2;
  MapSprite_InitializeRecord((intptr_t)self);
  return self;
}
