// Unwind@00557c4b: ported from Pizza Connection 2 at 0x557c4b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557c4b
#include "pc2_port.h"

void Unwind_00557c4b(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
