// Unwind@00558536: ported from Pizza Connection 2 at 0x558536.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558536
#include "pc2_port.h"

void Unwind_00558536(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
