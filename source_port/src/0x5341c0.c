// RecordList_TickFrameAndGetPoints: ported from Pizza Connection 2 at 0x5341c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5341c0
#include "pc2_port.h"

uint32_t __thiscall
RecordList_TickFrameAndGetPoints(void *self,int arg1,uint32_t *arg2,uint32_t *arg3)

{
  int value1;
  double *pdVar2;
  DWORD DVar3;
  uint32_t uvalue4;
  int value5;
  double *pdVar6;
  uint32_t *uptr7;
  
  if (((arg1 < 0) || (*(int *)((intptr_t)self + 0x48) <= arg1)) ||
     (value5 = arg1 * 0x48, *(int *)(*(int *)((intptr_t)self + 0x4c) + value5) == -1)) {
    return 0;
  }
  CS_Enter(0x5842a0);
  uptr7 = (uint32_t *)0x0;
  value1 = *(int *)((intptr_t)self + 0x4c) + value5;
  pdVar6 = (double *)(value1 + 0x10);
  pdVar2 = (double *)(value1 + 8);
  DVar3 = timeGetTime();
  uvalue4 = Record_AdvanceFrameSequence(self,arg1,DVar3,pdVar2,pdVar6,uptr7);
  value1 = *(int *)((intptr_t)self + 0x4c);
  *arg2 = *(uint32_t *)(value1 + 8 + value5);
  arg2[1] = *(uint32_t *)(value1 + 0xc + value5);
  value1 = *(int *)((intptr_t)self + 0x4c);
  *arg3 = *(uint32_t *)(value1 + 0x10 + value5);
  arg3[1] = *(uint32_t *)(value1 + 0x14 + value5);
  CS_Leave(0x5842a0);
  return uvalue4;
}
