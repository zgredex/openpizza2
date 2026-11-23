// Atexit_RegisterListCritSectDtor: ported from Pizza Connection 2 at 0x522e60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x522e60
#include "pc2_port.h"

void Atexit_RegisterListCritSectDtor(void)

{
  CRT_Atexit(0x522e70);
  return;
}
