// UI_GetCenteredRectForRecord: ported from Pizza Connection 2 at 0x4d31b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d31b0
#include "pc2_port.h"

void __thiscall UI_GetCenteredRectForRecord(void *self,int *arg1,int *arg2)

{
  int value1;
  
  value1 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  UI_GetRecordCenteredRect(*(void **)(value1 + 0xfa8),*(int *)((intptr_t)self + 0x24),arg1,arg2);
  return;
}
