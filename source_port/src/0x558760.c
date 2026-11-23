// Unwind@00558760: ported from Pizza Connection 2 at 0x558760.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558760
#include "pc2_port.h"

void Unwind_00558760(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x110));
  return;
}
