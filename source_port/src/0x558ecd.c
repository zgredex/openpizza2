// Unwind@00558ecd: ported from Pizza Connection 2 at 0x558ecd.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558ecd
#include "pc2_port.h"

void Unwind_00558ecd(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
