// Array_ClearStride34: ported from Pizza Connection 2 at 0x47c590.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47c590
#include "pc2_port.h"

void __fastcall Array_ClearStride34(int arg1)

{
  uint8_t *uptr1;
  int value2;
  
  uptr1 = (uint8_t *)(arg1 + 0x154e);
  value2 = 8;
  do {
    *uptr1 = 0;
    uptr1 = uptr1 + 0x34;
    value2 = value2 + -1;
  } while (value2 != 0);
  return;
}
