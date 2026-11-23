// Record_GetBounds48: ported from Pizza Connection 2 at 0x534060.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x534060
#include "pc2_port.h"

void __thiscall
Record_GetBounds48(void *self,int arg1,int *arg2,int *arg3,uint32_t *arg4,uint32_t *arg5)

{
  int value1;
  
  value1 = arg1 * 0x48;
  *arg2 = (intptr_t)*(short *)(*(int *)((intptr_t)self + 0x20) +
                            *(short *)(*(int *)((intptr_t)self + 0x4c) + 0x32 + value1) * 2);
  *arg3 = (intptr_t)*(short *)(*(int *)((intptr_t)self + 0x24) +
                            *(short *)(*(int *)((intptr_t)self + 0x4c) + 0x32 + value1) * 2);
  *arg4 = (uint32_t)*(uint16_t *)
                    (*(int *)((intptr_t)self + 0x28) +
                    *(short *)(*(int *)((intptr_t)self + 0x4c) + 0x32 + value1) * 2);
  *arg5 = (uint32_t)*(uint16_t *)
                    (*(int *)((intptr_t)self + 0x2c) +
                    *(short *)(*(int *)((intptr_t)self + 0x4c) + 0x32 + value1) * 2);
  return;
}
