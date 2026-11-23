// Unwind@00557f61: ported from Pizza Connection 2 at 0x557f61.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557f61
#include "pc2_port.h"

void Unwind_00557f61(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 8));
  return;
}
