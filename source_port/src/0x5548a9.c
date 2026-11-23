// Heap_InitSmallBlock: ported from Pizza Connection 2 at 0x5548a9.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5548a9
#include "pc2_port.h"

uint32_t Heap_InitSmallBlock(void)

{
  DAT_00585bdc = HeapAlloc(DAT_00585be0,0,0x140);
  if (DAT_00585bdc == (LPVOID)0x0) {
    return 0;
  }
  DAT_00585bd4 = 0;
  DAT_00585bd8 = 0;
  DAT_00585bd0 = DAT_00585bdc;
  DAT_00585bc8 = 0x10;
  return 1;
}
