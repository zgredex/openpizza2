// Unwind@0055a390: ported from Pizza Connection 2 at 0x55a390.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55a390
#include "pc2_port.h"

void Unwind_0055a390(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
