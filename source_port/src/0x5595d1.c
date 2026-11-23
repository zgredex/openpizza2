// Unwind@005595d1: ported from Pizza Connection 2 at 0x5595d1.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5595d1
#include "pc2_port.h"

void Unwind_005595d1(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
