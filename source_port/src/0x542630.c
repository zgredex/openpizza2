// Sound_UpdateBufferFade: ported from Pizza Connection 2 at 0x542630.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x542630
#include "pc2_port.h"

uint32_t __fastcall Sound_UpdateBufferFade(int arg1)

{
  DWORD DVar1;
  uint32_t uvalue2;
  
  if (*(int *)(arg1 + 0x8c) == 0) {
    return 1;
  }
  uvalue2 = *(uint32_t *)(arg1 + 0x90);
  DVar1 = timeGetTime();
  *(DWORD *)(arg1 + 0x94) = DVar1;
  if (DVar1 < uvalue2) {
    uvalue2 = (DVar1 - uvalue2) - 1;
  }
  else {
    uvalue2 = DVar1 - uvalue2;
  }
  if (uvalue2 < *(uint32_t *)(arg1 + 0x98)) {
    return 1;
  }
  uvalue2 = (uvalue2 * 100) / *(uint32_t *)(arg1 + 0x98);
  if (*(int *)(arg1 + 0x8c) == 1) {
    uvalue2 = *(int *)(arg1 + 0x9c) + uvalue2;
    if (*(uint32_t *)(arg1 + 0x78) <= uvalue2) {
      *(uint32_t *)(arg1 + 0x8c) = 0;
      *(uint32_t *)(arg1 + 0x9c) = *(uint32_t *)(arg1 + 0x78);
      goto LAB_005426b1;
    }
  }
  else {
    if (*(int *)(arg1 + 0x8c) != 2) goto LAB_005426b1;
    if (*(uint32_t *)(arg1 + 0x9c) < uvalue2) {
      *(uint32_t *)(arg1 + 0x8c) = 0;
      *(uint32_t *)(arg1 + 0x9c) = 0;
      goto LAB_005426b1;
    }
    uvalue2 = *(uint32_t *)(arg1 + 0x9c) - uvalue2;
  }
  *(uint32_t *)(arg1 + 0x9c) = uvalue2;
LAB_005426b1:
  DVar1 = timeGetTime();
  *(DWORD *)(arg1 + 0x90) = DVar1;
  *(DWORD *)(arg1 + 0x94) = DVar1;
  if (*(char *)(arg1 + 0x53) == '\0') {
    return 1;
  }
  EnterCriticalSection(*(LPCRITICAL_SECTION *)(arg1 + 0x38));
  uvalue2 = Sound_SetBufferVolume(*(void **)(arg1 + 0x28),*(uint32_t *)(arg1 + 0x9c));
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)(arg1 + 0x38));
  return uvalue2;
}
