// Unwind@00558eee: ported from Pizza Connection 2 at 0x558eee.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558eee
#include "pc2_port.h"

void Unwind_00558eee(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 8));
  return;
}
