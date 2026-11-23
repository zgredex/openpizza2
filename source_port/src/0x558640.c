// Unwind@00558640: ported from Pizza Connection 2 at 0x558640.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558640
#include "pc2_port.h"

void Unwind_00558640(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x110));
  return;
}
