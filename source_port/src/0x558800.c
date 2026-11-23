// Unwind@00558800: ported from Pizza Connection 2 at 0x558800.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558800
#include "pc2_port.h"

void Unwind_00558800(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
