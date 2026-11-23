// Unwind@005588fd: ported from Pizza Connection 2 at 0x5588fd.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5588fd
#include "pc2_port.h"

void Unwind_005588fd(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 0x10));
  return;
}
