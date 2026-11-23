// Unwind@00557e44: ported from Pizza Connection 2 at 0x557e44.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557e44
#include "pc2_port.h"

void Unwind_00557e44(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 8));
  return;
}
