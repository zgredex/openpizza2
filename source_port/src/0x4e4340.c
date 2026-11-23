// BuildingValue_ConstructDefault: ported from Pizza Connection 2 at 0x4e4340.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e4340
#include "pc2_port.h"

uint32_t * __thiscall BuildingValue_ConstructDefault(void *self,uint32_t arg1)

{
  *(uint8_t ***)self = &PTR_BuildingValue_Delete_0055c5a4;
  Game_SetHQLevel(self,arg1);
  *(uint32_t *)((intptr_t)self + 0xc) = 0xffffffff;
  *(uint32_t *)((intptr_t)self + 0x10) = 0;
  *(uint32_t *)((intptr_t)self + 0x14) = 0;
  *(uint32_t *)((intptr_t)self + 0x18) = 0;
  *(uint8_t *)((intptr_t)self + 0x1c) = 0;
  return self;
}
