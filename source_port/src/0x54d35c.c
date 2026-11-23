// CS_EnterRaw: ported from Pizza Connection 2 at 0x54d35c.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54d35c
#include "pc2_port.h"

void __cdecl CS_EnterRaw(LPCRITICAL_SECTION arg1)

{
  EnterCriticalSection(arg1);
  return;
}
