// Unwind@005589db: ported from Pizza Connection 2 at 0x5589db.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5589db
#include "pc2_port.h"

void Unwind_005589db(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
