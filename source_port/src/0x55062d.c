// CRT_Isspace_L: ported from Pizza Connection 2 at 0x55062d.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55062d
#include "pc2_port.h"

uint32_t __thiscall CRT_Isspace_L(void *self,int arg1)

{
  uint32_t uvalue1;
  
  if (DAT_00576cf0 < 2) {
    return (uint8_t)PTR_DAT_00576ae4[arg1 * 2] & 8;
  }
  uvalue1 = CRT_Mbtowc(self,arg1,8);
  return uvalue1;
}
