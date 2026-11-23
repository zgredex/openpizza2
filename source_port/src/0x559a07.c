// Unwind@00559a07: ported from Pizza Connection 2 at 0x559a07.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559a07
#include "pc2_port.h"

void Unwind_00559a07(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
