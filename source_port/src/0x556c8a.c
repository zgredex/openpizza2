// FUN_00556c8a: ported from Pizza Connection 2 at 0x556c8a.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x556c8a
#include "pc2_port.h"

void __cdecl FUN_00556c8a(uint32_t *arg1)

{
  uint32_t uvalue1;
  
  uvalue1 = arg1[1];
  arg1[1] = uvalue1 >> 1 | arg1[2] << 0x1f;
  arg1[2] = arg1[2] >> 1;
  *arg1 = *arg1 >> 1 | uvalue1 << 0x1f;
  return;
}
