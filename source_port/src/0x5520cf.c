// CRT_ReleaseStreamBuffer: ported from Pizza Connection 2 at 0x5520cf.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5520cf
#include "pc2_port.h"

void __cdecl CRT_ReleaseStreamBuffer(int arg1,int *arg2)

{
  if ((arg1 != 0) && ((*(uint8_t *)((intptr_t)arg2 + 0xd) & 0x10) != 0)) {
    CRT_FlushStream(arg2);
    *(uint8_t *)((intptr_t)arg2 + 0xd) = *(uint8_t *)((intptr_t)arg2 + 0xd) & 0xee;
    arg2[6] = 0;
    *arg2 = 0;
    arg2[2] = 0;
  }
  return;
}
