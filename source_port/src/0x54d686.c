// CRT_Ostream_Suffix: ported from Pizza Connection 2 at 0x54d686.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54d686
#include "pc2_port.h"

void __fastcall CRT_Ostream_Suffix(int *arg1)

{
  uint32_t *uptr1;
  int value2;
  
  *(uint32_t *)(*(int *)(*arg1 + 4) + 0x30 + (intptr_t)arg1) = 0;
  if ((*(uint8_t *)((intptr_t)arg1 + *(int *)(*arg1 + 4) + 0x25) & 0x20) != 0) {
    value2 = (**(code **)(**(int **)((intptr_t)arg1 + *(int *)(*arg1 + 4) + 4) + 4))();
    if (value2 == -1) {
      *(uint32_t *)(*(int *)(*arg1 + 4) + 8 + (intptr_t)arg1) = 6;
    }
  }
  if ((*(uint8_t *)(*(int *)(*arg1 + 4) + 0x25 + (intptr_t)arg1) & 0x40) != 0) {
    value2 = CRT_Fflush((int *)&DAT_005767a8);
    if (value2 == -1) {
      uptr1 = (uint32_t *)(*(int *)(*arg1 + 4) + 8 + (intptr_t)arg1);
      *uptr1 = *uptr1 | 2;
    }
    value2 = CRT_Fflush((int *)&DAT_005767c8);
    if (value2 == -1) {
      uptr1 = (uint32_t *)(*(int *)(*arg1 + 4) + 8 + (intptr_t)arg1);
      *uptr1 = *uptr1 | 2;
    }
  }
  value2 = *(int *)(*(int *)(*arg1 + 4) + 4 + (intptr_t)arg1);
  if (*(int *)(value2 + 0x30) < 0) {
    CS_LeaveRaw((LPCRITICAL_SECTION)(value2 + 0x34));
  }
  if (*(int *)((intptr_t)arg1 + *(int *)(*arg1 + 4) + 0x34) < 0) {
    CS_LeaveRaw((LPCRITICAL_SECTION)((intptr_t)arg1 + *(int *)(*arg1 + 4) + 0x38));
  }
  return;
}
