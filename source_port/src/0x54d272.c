// Stream_GetWritePosition: ported from Pizza Connection 2 at 0x54d272.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54d272
#include "pc2_port.h"

int __fastcall Stream_GetWritePosition(int *arg1)

{
  int value1;
  int value2;
  
  value2 = *(int *)(*(int *)(*arg1 + 4) + 4 + (intptr_t)arg1);
  if (*(int *)(value2 + 0x30) < 0) {
    CS_EnterRaw((LPCRITICAL_SECTION)(value2 + 0x34));
  }
  value2 = (**(code **)(**(int **)(*(int *)(*arg1 + 4) + 4 + (intptr_t)arg1) + 0xc))(0,1,2);
  if (value2 == -1) {
    Thread_SetField8Locked
              ((void *)(*(int *)(*arg1 + 4) + (intptr_t)arg1),
               *(uint32_t *)(*(int *)(*arg1 + 4) + 8 + (intptr_t)arg1) | 2);
  }
  value1 = *(int *)(*(int *)(*arg1 + 4) + 4 + (intptr_t)arg1);
  if (*(int *)(value1 + 0x30) < 0) {
    CS_LeaveRaw((LPCRITICAL_SECTION)(value1 + 0x34));
  }
  return value2;
}
