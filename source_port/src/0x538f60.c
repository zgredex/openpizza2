// Surface_LockAndMark: ported from Pizza Connection 2 at 0x538f60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x538f60
#include "pc2_port.h"

uint32_t __fastcall Surface_LockAndMark(void *arg1)

{
  int value1;
  
  value1 = Surface_Lock(arg1,1);
  if (value1 == 0) {
    return 0;
  }
  *(uint32_t *)((intptr_t)arg1 + 0x2c) = 1;
  return 1;
}
