// Unwind@00558185: ported from Pizza Connection 2 at 0x558185.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558185
#include "pc2_port.h"

void Unwind_00558185(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
