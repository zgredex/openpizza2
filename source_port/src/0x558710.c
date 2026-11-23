// Unwind@00558710: ported from Pizza Connection 2 at 0x558710.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558710
#include "pc2_port.h"

void Unwind_00558710(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x50));
  return;
}
