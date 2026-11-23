// Stream_BeginRead: ported from Pizza Connection 2 at 0x54d612.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54d612
#include "pc2_port.h"

uint32_t __fastcall Stream_BeginRead(int *arg1)

{
  int value1;
  uint32_t uvalue2;
  int *ptr3;
  
  if (*(int *)((intptr_t)arg1 + *(int *)(*arg1 + 4) + 0x34) < 0) {
    CS_EnterRaw((LPCRITICAL_SECTION)((intptr_t)arg1 + *(int *)(*arg1 + 4) + 0x38));
  }
  value1 = *(int *)(*arg1 + 4);
  uvalue2 = *(uint32_t *)(value1 + 8 + (intptr_t)arg1);
  if (uvalue2 != 0) {
    *(uint32_t *)((intptr_t)arg1 + value1 + 8) = uvalue2 | 2;
    if (*(int *)((intptr_t)arg1 + *(int *)(*arg1 + 4) + 0x34) < 0) {
      CS_LeaveRaw((LPCRITICAL_SECTION)((intptr_t)arg1 + *(int *)(*arg1 + 4) + 0x38));
    }
    return 0;
  }
  ptr3 = *(int **)((intptr_t)arg1 + value1 + 0x20);
  if (ptr3 != (int *)0x0) {
    Stream_AdvanceIterator(ptr3);
  }
  value1 = *(int *)(*(int *)(*arg1 + 4) + 4 + (intptr_t)arg1);
  if (*(int *)(value1 + 0x30) < 0) {
    CS_EnterRaw((LPCRITICAL_SECTION)(value1 + 0x34));
  }
  return 1;
}
