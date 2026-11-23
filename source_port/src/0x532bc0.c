// Atexit_RegisterAnimSwapCritSectDtor: ported from Pizza Connection 2 at 0x532bc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x532bc0
#include "pc2_port.h"

void Atexit_RegisterAnimSwapCritSectDtor(void)

{
  CRT_Atexit(0x532bd0);
  return;
}
