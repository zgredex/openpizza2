// Record_GetRect98: ported from Pizza Connection 2 at 0x534ac0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x534ac0
#include "pc2_port.h"

void __thiscall
Record_GetRect98(void *self,int arg1,uint32_t *arg2,uint32_t *arg3,uint32_t *arg4,
                uint32_t *arg5)

{
  int value1;
  int value2;
  
  value1 = *(int *)((intptr_t)self + 0x50);
  value2 = arg1 * 0x98;
  *arg2 = *(uint32_t *)(value1 + 0x70 + value2);
  arg2[1] = *(uint32_t *)(value1 + 0x74 + value2);
  value1 = *(int *)((intptr_t)self + 0x50);
  *arg3 = *(uint32_t *)(value1 + 0x78 + value2);
  arg3[1] = *(uint32_t *)(value1 + 0x7c + value2);
  value1 = *(int *)((intptr_t)self + 0x50);
  *arg4 = *(uint32_t *)(value1 + 0x60 + value2);
  arg4[1] = *(uint32_t *)(value1 + 100 + value2);
  value1 = *(int *)((intptr_t)self + 0x50);
  *arg5 = *(uint32_t *)(value1 + 0x68 + value2);
  arg5[1] = *(uint32_t *)(value1 + 0x6c + value2);
  return;
}
