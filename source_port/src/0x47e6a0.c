// Branch_ApplyBuildingStyleVariant: ported from Pizza Connection 2 at 0x47e6a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47e6a0
#include "pc2_port.h"

void __thiscall Branch_ApplyBuildingStyleVariant(void *self,int arg1)

{
  IsoMap_Load(*(void **)((intptr_t)self + 0x14e0),*(int *)((intptr_t)self + 0x38),arg1);
  *(uint32_t *)(*(int *)((intptr_t)self + 0x14e0) + 0xf4) = 1;
  *(int *)((intptr_t)self + 0x1a04) = arg1;
  return;
}
