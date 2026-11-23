// Record_SetDoubles48B: ported from Pizza Connection 2 at 0x5335b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5335b0
#include "pc2_port.h"

uint32_t __thiscall Record_SetDoubles48B(int arg1,uint32_t arg2,uint64_t arg3,uint64_t arg4)

{
  int value1;
  
  if (((intptr_t)arg2 < 0) || (*(int *)(arg1 + 0x48) <= (intptr_t)arg2)) {
    return arg2 & 0xffffff00;
  }
  value1 = arg2 * 0x48;
  *(uint64_t *)(*(int *)(arg1 + 0x4c) + 0x18 + value1) = arg3;
  *(uint64_t *)(*(int *)(arg1 + 0x4c) + 0x20 + value1) = arg4;
  return CONCAT31((int3)((uint32_t)value1 >> 8),1);
}
