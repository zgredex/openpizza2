// Object_GetByte36Max7: ported from Pizza Connection 2 at 0x51ef60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x51ef60
#include "pc2_port.h"

uint8_t __fastcall Object_GetByte36Max7(int *arg1)

{
  uint8_t flag1;
  
  if ((*arg1 == 0) || (flag1 = *(uint8_t *)(*arg1 + 0x36), 7 < flag1)) {
    return 0;
  }
  return flag1;
}
