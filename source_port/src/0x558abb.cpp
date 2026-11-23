// Unwind@00558abb: ported from Pizza Connection 2 at 0x558abb.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558abb
#include "pc2_port.h"

void Unwind_00558abb(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 0x10));
  return;
}
