// Surface_Lock: ported from Pizza Connection 2 at 0x538fa0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x538fa0
#include "pc2_port.h"

uint32_t __thiscall Surface_Lock(void *self,int arg1)

{
  int *ptr1;
  int value2;
  int value3;
  uint32_t *uptr4;
  uint32_t local_6c [2];
  uint16_t uStack_64;
  uint16_t uStack_60;
  int iStack_5c;
  uint32_t uStack_48;
  
  value3 = 0;
  if ((DAT_00584504 != 0) && (DAT_005844fc == 0)) {
    uptr4 = local_6c;
    for (value2 = 0x1b; value2 != 0; value2 = value2 + -1) {
      *uptr4 = 0;
      uptr4 = uptr4 + 1;
    }
    local_6c[0] = 0x6c;
    while( true ) {
      if (arg1 == 0) {
        ptr1 = *(int **)(*(int *)((intptr_t)self + 0x40) + 0x10);
      }
      else {
        ptr1 = *(int **)(*(int *)((intptr_t)self + 0x40) + 0xc);
      }
      value2 = (**(code **)(*ptr1 + 100))(ptr1,0,local_6c,1,0);
      if (value2 == 0) {
        *(uint16_t *)((intptr_t)self + 0x1a) = uStack_60;
        *(uint16_t *)((intptr_t)self + 0x1c) = uStack_64;
        *(uint32_t *)((intptr_t)self + 0x28) = uStack_48;
        *(int *)((intptr_t)self + 0x20) = iStack_5c >> 1;
        Surface_Reset((intptr_t)self);
        SetRect((LPRECT)((intptr_t)self + 100),0,0,(uint32_t)*(uint16_t *)((intptr_t)self + 0x1a),
                (uint32_t)*(uint16_t *)((intptr_t)self + 0x1c));
        *(uint32_t *)((intptr_t)self + 0x14) = 1;
        *(int *)((intptr_t)self + 0x28) =
             *(int *)((intptr_t)self + 0x28) +
             (*(int *)((intptr_t)self + 0x7c) * *(int *)((intptr_t)self + 0x20) + *(int *)((intptr_t)self + 0x78))
             * 2;
        return 1;
      }
      if ((0 < value3) || (value3 = value3 + 1, value2 != -0x7789fe3e)) break;
      Thread_WaitForExit((intptr_t)self);
      Sleep(1);
    }
  }
  return 0;
}
