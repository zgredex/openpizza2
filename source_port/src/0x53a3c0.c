// Mem_FillWord: ported from Pizza Connection 2 at 0x53a3c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53a3c0
#include "pc2_port.h"

void __cdecl Mem_FillWord(uint32_t *arg1,uint16_t arg2,uint32_t arg3)

{
  uint32_t uvalue1;
  
  for (uvalue1 = arg3 >> 1; uvalue1 != 0; uvalue1 = uvalue1 - 1) {
    *arg1 = CONCAT22(arg2,arg2);
    arg1 = arg1 + 1;
  }
  if ((arg3 & 1) != 0) {
    *(uint16_t *)arg1 = arg2;
  }
  return;
}
