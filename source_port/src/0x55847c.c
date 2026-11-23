// Unwind@0055847c: ported from Pizza Connection 2 at 0x55847c.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55847c
#include "pc2_port.h"

void Unwind_0055847c(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
