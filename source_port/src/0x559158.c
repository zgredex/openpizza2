// Unwind@00559158: ported from Pizza Connection 2 at 0x559158.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559158
#include "pc2_port.h"

void Unwind_00559158(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x118));
  return;
}
