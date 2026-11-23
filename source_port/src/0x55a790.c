// Unwind@0055a790: ported from Pizza Connection 2 at 0x55a790.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55a790
#include "pc2_port.h"

void Unwind_0055a790(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x114));
  return;
}
