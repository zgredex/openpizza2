// FUN_00556bdd: ported from Pizza Connection 2 at 0x556bdd.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x556bdd
#include "pc2_port.h"

uint32_t __cdecl FUN_00556bdd(uint32_t arg1,uint32_t arg2,uint32_t *arg3)

{
  uint32_t uvalue1;
  uint32_t uvalue2;
  
  uvalue2 = 0;
  uvalue1 = arg1 + arg2;
  if ((uvalue1 < arg1) || (uvalue1 < arg2)) {
    uvalue2 = 1;
  }
  *arg3 = uvalue1;
  return uvalue2;
}
