// Unwind@00559fd0: ported from Pizza Connection 2 at 0x559fd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559fd0
#include "pc2_port.h"

void Unwind_00559fd0(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x224));
  return;
}
