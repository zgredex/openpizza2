// Unwind@0055987f: ported from Pizza Connection 2 at 0x55987f.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55987f
#include "pc2_port.h"

void Unwind_0055987f(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
