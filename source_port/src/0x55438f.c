// CRT_AllocOsfHandle: ported from Pizza Connection 2 at 0x55438f.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55438f
#include "pc2_port.h"

uint32_t CRT_AllocOsfHandle(void)

{
  uint32_t *uptr1;
  uint32_t *uptr2;
  int *ptr3;
  uint32_t uvalue4;
  int local_8;
  int local_4;
  
  uvalue4 = 0xffffffff;
  CRT_Lock(0x12);
  local_8 = 0;
  local_4 = 0;
  ptr3 = &DAT_00586c20;
  while (uptr2 = (uint32_t *)*ptr3, uptr1 = uptr2, uptr2 != (uint32_t *)0x0) {
    for (; uptr2 < uptr1 + 0x120; uptr2 = uptr2 + 9) {
      if ((*(uint8_t *)(uptr2 + 1) & 1) == 0) {
        if (uptr2[2] == 0) {
          CRT_Lock(0x11);
          if (uptr2[2] == 0) {
            InitializeCriticalSection((LPCRITICAL_SECTION)(uptr2 + 3));
            uptr2[2] = uptr2[2] + 1;
          }
          CS_LeaveIndexed(0x11);
        }
        EnterCriticalSection((LPCRITICAL_SECTION)(uptr2 + 3));
        if ((*(uint8_t *)(uptr2 + 1) & 1) == 0) {
          *uptr2 = 0xffffffff;
          uvalue4 = ((intptr_t)uptr2 - *ptr3) / 0x24 + local_4;
          if (uvalue4 != 0xffffffff) goto LAB_005544a1;
          break;
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)(uptr2 + 3));
      }
      uptr1 = (uint32_t *)*ptr3;
    }
    local_4 = local_4 + 0x20;
    ptr3 = ptr3 + 1;
    local_8 = local_8 + 1;
    if (0x586d1f < (intptr_t)ptr3) goto LAB_005544a1;
  }
  uptr2 = _malloc(0x480);
  if (uptr2 != (uint32_t *)0x0) {
    DAT_00586d20 = DAT_00586d20 + 0x20;
    (&DAT_00586c20)[local_8] = uptr2;
    uptr1 = uptr2;
    for (; uptr2 < uptr1 + 0x120; uptr2 = uptr2 + 9) {
      *(uint8_t *)(uptr2 + 1) = 0;
      *uptr2 = 0xffffffff;
      uptr2[2] = 0;
      *(uint8_t *)((intptr_t)uptr2 + 5) = 10;
      uptr1 = (uint32_t *)(&DAT_00586c20)[local_8];
    }
    uvalue4 = local_8 << 5;
    CRT_LockFileHandle(uvalue4);
  }
LAB_005544a1:
  CS_LeaveIndexed(0x12);
  return uvalue4;
}
