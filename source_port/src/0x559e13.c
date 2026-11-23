// Unwind@00559e13: ported from Pizza Connection 2 at 0x559e13.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559e13
#include "pc2_port.h"

void Unwind_00559e13(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
