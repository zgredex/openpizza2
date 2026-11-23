// Unwind@00557f4b: ported from Pizza Connection 2 at 0x557f4b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557f4b
#include "pc2_port.h"

void Unwind_00557f4b(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 8));
  return;
}
