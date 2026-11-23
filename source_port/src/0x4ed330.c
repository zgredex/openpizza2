// Map_SetTileFieldWithDefault: ported from Pizza Connection 2 at 0x4ed330.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ed330
#include "pc2_port.h"

void __thiscall Map_SetTileFieldWithDefault(void *self,int arg1,int arg2,uint32_t arg3)

{
  if (arg3 == 0xffffffff) {
    arg3 = (uint32_t)*(uint8_t *)(*(int *)((intptr_t)self + 4) + 0x24 + arg2 * 0x48);
  }
  Array_SetField4Stride12(arg1,arg3,arg2);
  return;
}
