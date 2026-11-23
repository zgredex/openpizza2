// Unwind@00557f40: ported from Pizza Connection 2 at 0x557f40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557f40
#include "pc2_port.h"

void Unwind_00557f40(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 8));
  return;
}
