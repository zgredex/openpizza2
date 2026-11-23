// Unwind@00559801: ported from Pizza Connection 2 at 0x559801.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559801
#include "pc2_port.h"

void Unwind_00559801(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
