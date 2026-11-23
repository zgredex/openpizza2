// Object_IsIdIn840Range: ported from Pizza Connection 2 at 0x4d2e60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d2e60
#include "pc2_port.h"

uint32_t __fastcall Object_IsIdIn840Range(int arg1)

{
  if ((*(int *)(arg1 + 0x20) < 0x840) || (0x84b < *(int *)(arg1 + 0x20))) {
    return 0;
  }
  return 1;
}
