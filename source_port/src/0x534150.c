// RecordList_TickFrame: ported from Pizza Connection 2 at 0x534150.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x534150
#include "pc2_port.h"

uint32_t __thiscall RecordList_TickFrame(void *self,int arg1)

{
  int value1;
  double *pdVar2;
  DWORD DVar3;
  uint32_t uvalue4;
  double *pdVar5;
  uint32_t *uptr6;
  
  if (((arg1 < 0) || (*(int *)((intptr_t)self + 0x48) <= arg1)) ||
     (*(int *)(*(int *)((intptr_t)self + 0x4c) + arg1 * 0x48) == -1)) {
    return 0;
  }
  CS_Enter(0x5842a0);
  uptr6 = (uint32_t *)0x0;
  value1 = *(int *)((intptr_t)self + 0x4c) + arg1 * 0x48;
  pdVar5 = (double *)(value1 + 0x10);
  pdVar2 = (double *)(value1 + 8);
  DVar3 = timeGetTime();
  uvalue4 = Record_AdvanceFrameSequence(self,arg1,DVar3,pdVar2,pdVar5,uptr6);
  CS_Leave(0x5842a0);
  return uvalue4;
}
