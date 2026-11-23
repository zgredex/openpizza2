// CRT_MapWin32Error: ported from Pizza Connection 2 at 0x553593.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x553593
#include "pc2_port.h"

void __cdecl CRT_MapWin32Error(uint32_t arg1)

{
  DWORD *pDVar1;
  uint32_t *uptr2;
  int value3;
  
  pDVar1 = CRT_GetDosErrnoPtr();
  value3 = 0;
  *pDVar1 = arg1;
  uptr2 = &DAT_00576d08;
  do {
    if (arg1 == *uptr2) {
      pDVar1 = CRT_GetErrnoPtr();
      *pDVar1 = *(DWORD *)(value3 * 8 + 0x576d0c);
      return;
    }
    uptr2 = uptr2 + 2;
    value3 = value3 + 1;
  } while ((intptr_t)uptr2 < 0x576e70);
  if ((0x12 < arg1) && (arg1 < 0x25)) {
    pDVar1 = CRT_GetErrnoPtr();
    *pDVar1 = 0xd;
    return;
  }
  if ((arg1 < 0xbc) || (0xca < arg1)) {
    pDVar1 = CRT_GetErrnoPtr();
    *pDVar1 = 0x16;
    return;
  }
  pDVar1 = CRT_GetErrnoPtr();
  *pDVar1 = 8;
  return;
}
