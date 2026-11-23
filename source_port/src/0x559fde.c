// Unwind@00559fde: ported from Pizza Connection 2 at 0x559fde.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559fde
#include "pc2_port.h"

void Unwind_00559fde(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x224));
  return;
}
