// Object_GetChildField2C: ported from Pizza Connection 2 at 0x50e4a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50e4a0
#include "pc2_port.h"

uint32_t __fastcall Object_GetChildField2C(int arg1)

{
  if (*(int *)(arg1 + 200) == 0) {
    return 0;
  }
  return *(uint32_t *)(*(int *)(arg1 + 200) + 0x2c);
}
