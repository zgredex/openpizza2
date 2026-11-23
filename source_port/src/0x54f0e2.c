// _rand: ported from Pizza Connection 2 at 0x54f0e2.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54f0e2
#include "pc2_port.h"

/* Library Function - Single Match
    _rand
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release, Visual Studio 2008 Release */

int __cdecl _rand(void)

{
  DWORD *pDVar1;
  uint32_t uvalue2;
  
  pDVar1 = CRT_GetThreadData();
  uvalue2 = pDVar1[5] * 0x343fd + 0x269ec3;
  pDVar1[5] = uvalue2;
  return uvalue2 >> 0x10 & 0x7fff;
}
