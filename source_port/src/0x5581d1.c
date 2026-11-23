// Unwind@005581d1: ported from Pizza Connection 2 at 0x5581d1.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5581d1
#include "pc2_port.h"

void Unwind_005581d1(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x48));
  return;
}
