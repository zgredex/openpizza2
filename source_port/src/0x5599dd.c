// Unwind@005599dd: ported from Pizza Connection 2 at 0x5599dd.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5599dd
#include "pc2_port.h"

void Unwind_005599dd(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
