// CS_Delete: ported from Pizza Connection 2 at 0x53fd90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53fd90
#include "pc2_port.h"

void __fastcall CS_Delete(LPCRITICAL_SECTION arg1)

{
  DeleteCriticalSection(arg1);
  return;
}
