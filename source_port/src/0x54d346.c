// CS_Initialize: ported from Pizza Connection 2 at 0x54d346.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54d346
#include "pc2_port.h"

void __cdecl CS_Initialize(LPCRITICAL_SECTION arg1)

{
  InitializeCriticalSection(arg1);
  return;
}
