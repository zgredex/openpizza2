// Ingredient_Construct: ported from Pizza Connection 2 at 0x4e4770.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e4770
#include "pc2_port.h"

uint32_t * __thiscall Ingredient_Construct(void *self,uint32_t arg1)

{
  *(uint8_t ***)self = &PTR_Ingredient_Delete_0055c5b8;
  Game_SetBuildingDesc
            (self,s_default_00570c48,1,1000,0xfa,0x14,10,0x3d70a3d7,0x3fffd70a,0,0,0,0,0,0);
  *(uint8_t *)((intptr_t)self + 0xa8) = 0;
  *(uint32_t *)((intptr_t)self + 0xd0) = arg1;
  return self;
}
