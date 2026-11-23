// Unwind@0055996d: ported from Pizza Connection 2 at 0x55996d.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55996d
#include "pc2_port.h"

void Unwind_0055996d(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
