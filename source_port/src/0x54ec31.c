// Mem_Swap: ported from Pizza Connection 2 at 0x54ec31.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54ec31
#include "pc2_port.h"

void __cdecl Mem_Swap(uint8_t *arg1,uint8_t *arg2,int arg3)

{
  uint8_t uvalue1;
  
  if ((arg1 != arg2) && (arg3 != 0)) {
    do {
      uvalue1 = *arg1;
      *arg1 = *arg2;
      arg1 = arg1 + 1;
      *arg2 = uvalue1;
      arg2 = arg2 + 1;
      arg3 = arg3 + -1;
    } while (arg3 != 0);
  }
  return;
}
