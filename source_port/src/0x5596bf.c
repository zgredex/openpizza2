// Unwind@005596bf: ported from Pizza Connection 2 at 0x5596bf.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5596bf
#include "pc2_port.h"

void Unwind_005596bf(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
