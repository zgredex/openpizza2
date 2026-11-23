// Unwind@00559326: ported from Pizza Connection 2 at 0x559326.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559326
#include "pc2_port.h"

void Unwind_00559326(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x14));
  return;
}
