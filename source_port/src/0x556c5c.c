// FUN_00556c5c: ported from Pizza Connection 2 at 0x556c5c.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x556c5c
#include "pc2_port.h"

void __cdecl FUN_00556c5c(uint32_t *arg1)

{
  uint32_t uvalue1;
  uint32_t uvalue2;
  
  uvalue1 = *arg1;
  uvalue2 = arg1[1];
  *arg1 = uvalue1 * 2;
  arg1[1] = uvalue2 * 2 | uvalue1 >> 0x1f;
  arg1[2] = arg1[2] << 1 | uvalue2 >> 0x1f;
  return;
}
