// CRT_Fopen: ported from Pizza Connection 2 at 0x54dfe0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54dfe0
#include "pc2_port.h"

void __cdecl CRT_Fopen(LPCSTR arg1,char *arg2)

{
  CRT_Fsopen(arg1,arg2,0x40);
  return;
}
