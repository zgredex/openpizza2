// Unwind@0055909b: ported from Pizza Connection 2 at 0x55909b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55909b
#include "pc2_port.h"

void Unwind_0055909b(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
