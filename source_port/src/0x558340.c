// Unwind@00558340: ported from Pizza Connection 2 at 0x558340.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558340
#include "pc2_port.h"

void Unwind_00558340(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x14));
  return;
}
