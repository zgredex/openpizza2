// Employee_ApplySkillMultipliers: ported from Pizza Connection 2 at 0x4d3ef0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d3ef0
#include "pc2_port.h"

void __thiscall Employee_ApplySkillMultipliers(void *self,uint32_t arg1)

{
  *(uint32_t *)((intptr_t)self + 0x24) = arg1;
  *(int *)((intptr_t)self + 0x28) = ((DAT_0058557c + -1) * *(int *)((intptr_t)self + 0xc)) / 100;
  *(int *)((intptr_t)self + 0x2c) = ((DAT_00585580 + -1) * *(int *)((intptr_t)self + 4)) / 100;
  *(int *)((intptr_t)self + 0x30) = ((DAT_00585584 + -1) * *(int *)((intptr_t)self + 8)) / 100;
  *(int *)((intptr_t)self + 0x34) = ((DAT_00585588 + -1) * *(int *)((intptr_t)self + 0x10)) / 100;
  return;
}
