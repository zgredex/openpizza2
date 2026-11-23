// Unwind@00558230: ported from Pizza Connection 2 at 0x558230.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558230
#include "pc2_port.h"

void Unwind_00558230(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x1c0));
  return;
}
