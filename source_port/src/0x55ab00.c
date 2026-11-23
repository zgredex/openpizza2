// Unwind@0055ab00: ported from Pizza Connection 2 at 0x55ab00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55ab00
#include "pc2_port.h"

void Unwind_0055ab00(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
