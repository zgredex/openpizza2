// Unwind@00558cab: ported from Pizza Connection 2 at 0x558cab.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558cab
#include "pc2_port.h"

void Unwind_00558cab(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
