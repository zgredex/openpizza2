// TileDef_TestFlag: ported from Pizza Connection 2 at 0x4d2e10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d2e10
#include "pc2_port.h"

bool __thiscall TileDef_TestFlag(void *self,int arg1,uint32_t arg2)

{
  int value1;
  
  value1 = *(int *)(arg1 + 0x4c) + *(int *)((intptr_t)self + 0x24) * 0xc;
  if (value1 == 0) {
    return false;
  }
  return (*(uint32_t *)(*(int *)(value1 + 8) + 0x1c) & arg2) != 0;
}
