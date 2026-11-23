// Unwind@005595fb: ported from Pizza Connection 2 at 0x5595fb.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5595fb
#include "pc2_port.h"

void Unwind_005595fb(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
