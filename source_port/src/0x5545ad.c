// CRT_GetOsHandle: ported from Pizza Connection 2 at 0x5545ad.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5545ad
#include "pc2_port.h"

uint32_t __cdecl CRT_GetOsHandle(uint32_t arg1)

{
  DWORD *pDVar1;
  
  if ((arg1 < DAT_00586d20) &&
     ((*(uint8_t *)((&DAT_00586c20)[(intptr_t)arg1 >> 5] + 4 + (arg1 & 0x1f) * 0x24) & 1) != 0)) {
    return *(uint32_t *)((&DAT_00586c20)[(intptr_t)arg1 >> 5] + (arg1 & 0x1f) * 0x24);
  }
  pDVar1 = CRT_GetErrnoPtr();
  *pDVar1 = 9;
  pDVar1 = CRT_GetDosErrnoPtr();
  *pDVar1 = 0;
  return 0xffffffff;
}
