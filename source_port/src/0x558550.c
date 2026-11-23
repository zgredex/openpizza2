// Unwind@00558550: ported from Pizza Connection 2 at 0x558550.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558550
#include "pc2_port.h"

void Unwind_00558550(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 0x10));
  return;
}
