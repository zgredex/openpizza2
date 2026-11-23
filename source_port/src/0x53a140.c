// Gfx_BuildBlendTable: ported from Pizza Connection 2 at 0x53a140.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53a140
#include "pc2_port.h"

int __fastcall Gfx_BuildBlendTable(int arg1)

{
  uint32_t uvalue1;
  int value2;
  int value3;
  int64_t lvalue4;
  
  value2 = 0;
  do {
    value3 = -0x1f;
    do {
      lvalue4 = __ftol();
      uvalue1 = value3 + 0x1f;
      value3 = value3 + 1;
      *(int *)(arg1 + (uvalue1 | value2 << 6) * 4) = (intptr_t)lvalue4;
    } while (value3 < 0x20);
    value2 = value2 + 1;
  } while (value2 < 0x10);
  return arg1;
}
