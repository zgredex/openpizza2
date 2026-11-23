// City_IsIdle: ported from Pizza Connection 2 at 0x480880.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x480880
#include "pc2_port.h"

bool __fastcall City_IsIdle(int arg1)

{
  if (*(int *)(arg1 + 0x16f0) == 0) {
    return true;
  }
  return *(int *)(*(int *)(arg1 + 0x16f0) + 0x94) != 0;
}
