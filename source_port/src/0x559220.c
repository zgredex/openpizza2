// Unwind@00559220: ported from Pizza Connection 2 at 0x559220.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559220
#include "pc2_port.h"

void Unwind_00559220(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x50));
  return;
}
