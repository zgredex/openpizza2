// Heap_FindBlock: ported from Pizza Connection 2 at 0x5548e7.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5548e7
#include "pc2_port.h"

uint32_t __cdecl Heap_FindBlock(int arg1)

{
  uint32_t uvalue1;
  
  uvalue1 = DAT_00585bdc;
  while( true ) {
    if (DAT_00585bdc + DAT_00585bd8 * 0x14 <= uvalue1) {
      return 0;
    }
    if ((uint32_t)(arg1 - *(int *)(uvalue1 + 0xc)) < 0x100000) break;
    uvalue1 = uvalue1 + 0x14;
  }
  return uvalue1;
}
