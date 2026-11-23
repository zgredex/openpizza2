// CS_DeleteRaw: ported from Pizza Connection 2 at 0x54d351.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54d351
#include "pc2_port.h"

void __cdecl CS_DeleteRaw(LPCRITICAL_SECTION arg1)

{
  DeleteCriticalSection(arg1);
  return;
}
