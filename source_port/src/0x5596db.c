// Unwind@005596db: ported from Pizza Connection 2 at 0x5596db.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5596db
#include "pc2_port.h"

void Unwind_005596db(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
