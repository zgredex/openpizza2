// CRT_InitHeap: ported from Pizza Connection 2 at 0x5541c7.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5541c7
#include "pc2_port.h"

uint32_t __cdecl CRT_InitHeap(int arg1)

{
  int value1;
  
  DAT_00585be0 = HeapCreate((uint32_t)(arg1 == 0),0x1000,0);
  if (DAT_00585be0 != (HANDLE)0x0) {
    value1 = Heap_InitSmallBlock();
    if (value1 != 0) {
      return 1;
    }
    HeapDestroy(DAT_00585be0);
  }
  return 0;
}
