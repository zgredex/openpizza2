// Unwind@0055ada5: ported from Pizza Connection 2 at 0x55ada5.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55ada5
#include "pc2_port.h"

void Unwind_0055ada5(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x344));
  return;
}
