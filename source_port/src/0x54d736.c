// Stream_AdvanceIterator: ported from Pizza Connection 2 at 0x54d736.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54d736
#include "pc2_port.h"

int * __fastcall Stream_AdvanceIterator(int *arg1)

{
  uint32_t *uptr1;
  int value2;
  
  if (*(int *)((intptr_t)arg1 + *(int *)(*arg1 + 4) + 0x34) < 0) {
    CS_EnterRaw((LPCRITICAL_SECTION)((intptr_t)arg1 + *(int *)(*arg1 + 4) + 0x38));
  }
  value2 = *(int *)(*(int *)(*arg1 + 4) + 4 + (intptr_t)arg1);
  if (*(int *)(value2 + 0x30) < 0) {
    CS_EnterRaw((LPCRITICAL_SECTION)(value2 + 0x34));
  }
  value2 = (**(code **)(**(int **)(*(int *)(*arg1 + 4) + 4 + (intptr_t)arg1) + 4))();
  if (value2 == -1) {
    uptr1 = (uint32_t *)(*(int *)(*arg1 + 4) + 8 + (intptr_t)arg1);
    *uptr1 = *uptr1 | 2;
  }
  value2 = *(int *)(*(int *)(*arg1 + 4) + 4 + (intptr_t)arg1);
  if (*(int *)(value2 + 0x30) < 0) {
    CS_LeaveRaw((LPCRITICAL_SECTION)(value2 + 0x34));
  }
  if (*(int *)((intptr_t)arg1 + *(int *)(*arg1 + 4) + 0x34) < 0) {
    CS_LeaveRaw((LPCRITICAL_SECTION)((intptr_t)arg1 + *(int *)(*arg1 + 4) + 0x38));
  }
  return arg1;
}
