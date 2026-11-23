// Unwind@00558680: ported from Pizza Connection 2 at 0x558680.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558680
#include "pc2_port.h"

void Unwind_00558680(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x110));
  return;
}
