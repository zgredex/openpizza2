// CRT_FflushLocked: ported from Pizza Connection 2 at 0x550684.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x550684
#include "pc2_port.h"

int __cdecl CRT_FflushLocked(int *arg1)

{
  int value1;
  
  value1 = CRT_FlushStream(arg1);
  if (value1 != 0) {
    return -1;
  }
  if ((*(uint8_t *)((intptr_t)arg1 + 0xd) & 0x40) == 0) {
    return 0;
  }
  value1 = CRT_Flush(arg1[4]);
  return -(uint32_t)(value1 != 0);
}
