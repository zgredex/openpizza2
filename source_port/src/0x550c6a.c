// CRT_SetMode: ported from Pizza Connection 2 at 0x550c6a.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x550c6a
#include "pc2_port.h"

int __cdecl CRT_SetMode(uint32_t arg1,int arg2)

{
  uint8_t flag1;
  DWORD *pDVar2;
  uint8_t flag3;
  
  flag1 = *(uint8_t *)((&DAT_00586c20)[(intptr_t)arg1 >> 5] + 4 + (arg1 & 0x1f) * 0x24);
  if (arg2 == 0x8000) {
    flag3 = flag1 & 0x7f;
  }
  else {
    if (arg2 != 0x4000) {
      pDVar2 = CRT_GetErrnoPtr();
      *pDVar2 = 0x16;
      return -1;
    }
    flag3 = flag1 | 0x80;
  }
  *(uint8_t *)((&DAT_00586c20)[(intptr_t)arg1 >> 5] + 4 + (arg1 & 0x1f) * 0x24) = flag3;
  return (-(uint32_t)((flag1 & 0x80) != 0) & 0xffffc000) + 0x8000;
}
