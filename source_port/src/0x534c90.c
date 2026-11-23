// Record_TryAdvanceFrame: ported from Pizza Connection 2 at 0x534c90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x534c90
#include "pc2_port.h"

uint32_t __thiscall
Record_TryAdvanceFrame
          (void *self,int arg1,uint32_t arg2,uint32_t *arg3,uint32_t *arg4,
          uint32_t *arg5)

{
  uint32_t in_EAX;
  uint32_t uvalue1;
  int value2;
  int value3;
  uint32_t *uptr4;
  uint32_t *uptr5;
  uint32_t *uptr6;
  uint32_t local_48 [18];
  
  if ((-1 < arg1) && (arg1 < *(int *)((intptr_t)self + 0x48))) {
    in_EAX = *(uint32_t *)((intptr_t)self + 0x4c);
    value3 = arg1 * 0x48;
    if (*(int *)(in_EAX + value3) != -1) {
      CS_Enter(0x5842a0);
      uptr5 = (uint32_t *)(*(int *)((intptr_t)self + 0x4c) + value3);
      uptr4 = uptr5;
      uptr6 = local_48;
      for (value2 = 0x12; value2 != 0; value2 = value2 + -1) {
        *uptr6 = *uptr4;
        uptr4 = uptr4 + 1;
        uptr6 = uptr6 + 1;
      }
      Record_AdvanceFrameSequence
                (self,arg1,arg2,(double *)(uptr5 + 2),(double *)(uptr5 + 4),arg5);
      value2 = *(int *)((intptr_t)self + 0x4c);
      *arg3 = *(uint32_t *)(value2 + 8 + value3);
      arg3[1] = *(uint32_t *)(value2 + 0xc + value3);
      value2 = *(int *)((intptr_t)self + 0x4c);
      *arg4 = *(uint32_t *)(value2 + 0x10 + value3);
      arg4[1] = *(uint32_t *)(value2 + 0x14 + value3);
      uptr5 = local_48;
      uptr4 = (uint32_t *)(*(int *)((intptr_t)self + 0x4c) + value3);
      for (value2 = 0x12; value2 != 0; value2 = value2 + -1) {
        *uptr4 = *uptr5;
        uptr5 = uptr5 + 1;
        uptr4 = uptr4 + 1;
      }
      uvalue1 = CS_Leave(0x5842a0);
      return uvalue1 & 0xffffff00;
    }
  }
  return in_EAX & 0xffffff00;
}
