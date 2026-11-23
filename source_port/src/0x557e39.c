// Unwind@00557e39: ported from Pizza Connection 2 at 0x557e39.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557e39
#include "pc2_port.h"

void Unwind_00557e39(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 8));
  return;
}
