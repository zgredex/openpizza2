// CRT_Remove: ported from Pizza Connection 2 at 0x54f613.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54f613
#include "pc2_port.h"

void __cdecl CRT_Remove(LPCSTR arg1)

{
  CRT_Unlink(arg1);
  return;
}
