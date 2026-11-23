// Unwind@005591b6: ported from Pizza Connection 2 at 0x5591b6.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5591b6
#include "pc2_port.h"

void Unwind_005591b6(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
