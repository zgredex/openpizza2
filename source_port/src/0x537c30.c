// Object_GetChildField14: ported from Pizza Connection 2 at 0x537c30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x537c30
#include "pc2_port.h"

uint32_t __fastcall Object_GetChildField14(int arg1)

{
  if (*(uint32_t **)(arg1 + 0x14) == (uint32_t *)0x0) {
    return 0;
  }
  return **(uint32_t **)(arg1 + 0x14);
}
