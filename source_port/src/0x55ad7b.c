// Unwind@0055ad7b: ported from Pizza Connection 2 at 0x55ad7b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55ad7b
#include "pc2_port.h"

void Unwind_0055ad7b(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x344));
  return;
}
