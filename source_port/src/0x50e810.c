// Object_GetClampedLevel: ported from Pizza Connection 2 at 0x50e810.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50e810
#include "pc2_port.h"

uint32_t __fastcall Object_GetClampedLevel(int arg1)

{
  if ((*(int *)(arg1 + 0x10c) < 1) || (3 < *(int *)(arg1 + 0x10c))) {
    *(uint32_t *)(arg1 + 0x10c) = 1;
  }
  return *(uint32_t *)(arg1 + 0x10c);
}
