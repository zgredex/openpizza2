// CRT_FindClose: ported from Pizza Connection 2 at 0x54f565.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54f565
#include "pc2_port.h"

uint32_t __cdecl CRT_FindClose(HANDLE arg1)

{
  BOOL BVar1;
  DWORD *pDVar2;
  
  BVar1 = FindClose(arg1);
  if (BVar1 == 0) {
    pDVar2 = CRT_GetErrnoPtr();
    *pDVar2 = 0x16;
    return 0xffffffff;
  }
  return 0;
}
