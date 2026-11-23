// Unwind@00558b5d: ported from Pizza Connection 2 at 0x558b5d.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558b5d
#include "pc2_port.h"

void Unwind_00558b5d(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 0x10));
  return;
}
