// Unwind@00558dab: ported from Pizza Connection 2 at 0x558dab.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558dab
#include "pc2_port.h"

void Unwind_00558dab(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
