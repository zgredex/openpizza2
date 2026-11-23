// CRT_Exit: ported from Pizza Connection 2 at 0x54f2dd.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54f2dd
#include "pc2_port.h"

void __cdecl CRT_Exit(UINT arg1)

{
  CRT_DoExit(arg1,0,0);
  return;
}
