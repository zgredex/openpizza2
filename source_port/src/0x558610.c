// Unwind@00558610: ported from Pizza Connection 2 at 0x558610.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558610
#include "pc2_port.h"

void Unwind_00558610(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x368));
  return;
}
