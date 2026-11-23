// CRT_GetStream: ported from Pizza Connection 2 at 0x552269.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x552269
#include "pc2_port.h"

uint32_t * CRT_GetStream(void)

{
  int value1;
  void *pvVar2;
  int value3;
  uint32_t *uptr4;
  
  uptr4 = (uint32_t *)0x0;
  CRT_Lock(2);
  value3 = 0;
  if (0 < DAT_00586c00) {
    do {
      value1 = *(int *)(DAT_00585bec + value3 * 4);
      if (value1 == 0) {
        value3 = value3 * 4;
        pvVar2 = _malloc(0x38);
        *(void **)(value3 + DAT_00585bec) = pvVar2;
        if (*(int *)(value3 + DAT_00585bec) != 0) {
          InitializeCriticalSection((LPCRITICAL_SECTION)(*(int *)(value3 + DAT_00585bec) + 0x20));
          EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(value3 + DAT_00585bec) + 0x20));
          uptr4 = *(uint32_t **)(value3 + DAT_00585bec);
LAB_0055230d:
          if (uptr4 != (uint32_t *)0x0) {
            uptr4[4] = 0xffffffff;
            uptr4[1] = 0;
            uptr4[3] = 0;
            uptr4[2] = 0;
            *uptr4 = 0;
            uptr4[7] = 0;
          }
        }
        break;
      }
      if ((*(uint8_t *)(value1 + 0xc) & 0x83) == 0) {
        CRT_LockFile2(value3,value1);
        value1 = *(int *)(DAT_00585bec + value3 * 4);
        if ((*(uint8_t *)(value1 + 0xc) & 0x83) == 0) {
          uptr4 = *(uint32_t **)(DAT_00585bec + value3 * 4);
          goto LAB_0055230d;
        }
        CRT_UnlockHandle(value3,value1);
      }
      value3 = value3 + 1;
    } while (value3 < DAT_00586c00);
  }
  CS_LeaveIndexed(2);
  return uptr4;
}
