// Unwind@0055958b: ported from Pizza Connection 2 at 0x55958b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55958b
#include "pc2_port.h"

void Unwind_0055958b(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
