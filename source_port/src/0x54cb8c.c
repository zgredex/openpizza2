// CRT_LeaveNestedLocks: ported from Pizza Connection 2 at 0x54cb8c.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54cb8c
#include "pc2_port.h"

void __fastcall CRT_LeaveNestedLocks(int *arg1)

{
  int value1;
  
  value1 = *(int *)(*(int *)(*arg1 + 4) + 4 + (intptr_t)arg1);
  if (*(int *)(value1 + 0x30) < 0) {
    CS_LeaveRaw((LPCRITICAL_SECTION)(value1 + 0x34));
  }
  if (*(int *)((intptr_t)arg1 + *(int *)(*arg1 + 4) + 0x34) < 0) {
    CS_LeaveRaw((LPCRITICAL_SECTION)((intptr_t)arg1 + *(int *)(*arg1 + 4) + 0x38));
  }
  return;
}
