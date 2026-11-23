// Unwind@00558281: ported from Pizza Connection 2 at 0x558281.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558281
#include "pc2_port.h"

void Unwind_00558281(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
