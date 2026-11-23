// Surface_GetDescription: ported from Pizza Connection 2 at 0x5390b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5390b0
#include "pc2_port.h"

uint32_t __thiscall Surface_GetDescription(void *self,int *arg1,int *arg2)

{
  int value1;
  int value2;
  uint32_t *uptr3;
  uint32_t local_6c [2];
  uint16_t uStack_64;
  uint16_t uStack_60;
  int iStack_5c;
  uint32_t uStack_48;
  
  value2 = 0;
  uptr3 = local_6c;
  for (value1 = 0x1b; value1 != 0; value1 = value1 + -1) {
    *uptr3 = 0;
    uptr3 = uptr3 + 1;
  }
  local_6c[0] = 0x6c;
  while( true ) {
    if (DAT_005844fc != 0) {
      return 0;
    }
    value1 = (**(code **)(*arg1 + 100))(arg1,0,local_6c,1,0);
    if (value1 == 0) break;
    if (value1 == -0x7789fe3e) {
      Thread_WaitForExit((intptr_t)self);
    }
    Sleep(1);
    value2 = value2 + 1;
    if (200 < value2) {
      return 0;
    }
  }
  *arg2 = iStack_5c;
  *(uint16_t *)((intptr_t)self + 0x1a) = uStack_60;
  *(uint32_t *)((intptr_t)self + 0x28) = uStack_48;
  *(uint16_t *)((intptr_t)self + 0x1c) = uStack_64;
  *(int *)((intptr_t)self + 0x20) = iStack_5c >> 1;
  Surface_Reset((intptr_t)self);
  SetRect((LPRECT)((intptr_t)self + 100),0,0,(uint32_t)*(uint16_t *)((intptr_t)self + 0x1a),
          (uint32_t)*(uint16_t *)((intptr_t)self + 0x1c));
  return uStack_48;
}
