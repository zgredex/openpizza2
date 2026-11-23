// Unwind@0055b698: ported from Pizza Connection 2 at 0x55b698.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b698
#include "pc2_port.h"

void Unwind_0055b698(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 8));
  return;
}
