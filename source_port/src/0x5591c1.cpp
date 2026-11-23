// Unwind@005591c1: ported from Pizza Connection 2 at 0x5591c1.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5591c1
#include "pc2_port.h"

void Unwind_005591c1(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
