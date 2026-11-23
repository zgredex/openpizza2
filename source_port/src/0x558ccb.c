// Unwind@00558ccb: ported from Pizza Connection 2 at 0x558ccb.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558ccb
#include "pc2_port.h"

void Unwind_00558ccb(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
