// Rect_Zero: ported from Pizza Connection 2 at 0x545650.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x545650
#include "pc2_port.h"

void __fastcall Rect_Zero(uint32_t *arg1)

{
  *arg1 = 0;
  arg1[1] = 0;
  arg1[2] = 0;
  arg1[3] = 0;
  return;
}
