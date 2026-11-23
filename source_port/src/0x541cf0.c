// Sound_AlignBufferSize: ported from Pizza Connection 2 at 0x541cf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x541cf0
#include "pc2_port.h"

uint32_t __cdecl Sound_AlignBufferSize(uint32_t arg1,uint32_t arg2,int arg3)

{
  uint32_t uvalue1;
  int value2;
  uint64_t uvalue3;
  
  uvalue3 = __ftol();
  uvalue1 = (uint32_t)uvalue3;
  if (*(uint16_t *)(arg3 + 0xc) < 2) {
    if ((uvalue3 & 1) != 0) {
      uvalue1 = uvalue1 - (uvalue1 & 1);
    }
  }
  else {
    value2 = (intptr_t)((uvalue3 & 0xffffffff) % (uint64_t)*(uint16_t *)(arg3 + 0xc));
    if (value2 != 0) {
      return uvalue1 - value2;
    }
  }
  return uvalue1;
}
