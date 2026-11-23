// Rating_GetCompositeTruncated: ported from Pizza Connection 2 at 0x4d3990.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d3990
#include "pc2_port.h"

int64_t __fastcall Rating_GetCompositeTruncated(int arg1)

{
  int64_t lvalue1;
  
  Rating_GetComposite(arg1);
  switch(*(uint8_t *)(arg1 + 0x824)) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
  }
  lvalue1 = __ftol();
  return lvalue1;
}
