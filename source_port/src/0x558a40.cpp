// Unwind@00558a40: ported from Pizza Connection 2 at 0x558a40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558a40
#include "pc2_port.h"

void Unwind_00558a40(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
