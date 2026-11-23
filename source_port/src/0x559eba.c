// Unwind@00559eba: ported from Pizza Connection 2 at 0x559eba.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559eba
#include "pc2_port.h"

void Unwind_00559eba(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x120));
  return;
}
