// Atexit_RegisterAnimCritSectDtor: ported from Pizza Connection 2 at 0x532c00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x532c00
#include "pc2_port.h"

void Atexit_RegisterAnimCritSectDtor(void)

{
  CRT_Atexit(0x532c10);
  return;
}
