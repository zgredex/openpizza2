// RecordList_TickFrameAtTimeAndGetPoints: ported from Pizza Connection 2 at 0x534250.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x534250
#include "pc2_port.h"

uint32_t __thiscall
RecordList_TickFrameAtTimeAndGetPoints
          (void *self,int arg1,uint32_t arg2,uint32_t *arg3,uint32_t *arg4,
          uint32_t *arg5)

{
  int value1;
  uint32_t in_EAX;
  int value2;
  
  if ((-1 < arg1) && (arg1 < *(int *)((intptr_t)self + 0x48))) {
    in_EAX = *(uint32_t *)((intptr_t)self + 0x4c);
    value2 = arg1 * 0x48;
    if (*(int *)(in_EAX + value2) != -1) {
      CS_Enter(0x5842a0);
      value1 = *(int *)((intptr_t)self + 0x4c) + value2;
      Record_AdvanceFrameSequence
                (self,arg1,arg2,(double *)(value1 + 8),(double *)(value1 + 0x10),arg5);
      value1 = *(int *)((intptr_t)self + 0x4c);
      *arg3 = *(uint32_t *)(value1 + 8 + value2);
      arg3[1] = *(uint32_t *)(value1 + 0xc + value2);
      value1 = *(int *)((intptr_t)self + 0x4c);
      *arg4 = *(uint32_t *)(value1 + 0x10 + value2);
      arg4[1] = *(uint32_t *)(value1 + 0x14 + value2);
      in_EAX = CS_Leave(0x5842a0);
    }
  }
  return in_EAX & 0xffffff00;
}
