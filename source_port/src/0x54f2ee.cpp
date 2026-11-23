// __exit: ported from Pizza Connection 2 at 0x54f2ee.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54f2ee
#include "pc2_port.h"

/* Library Function - Single Match
    __exit
   
   Library: Visual Studio 2003 Release */

void __cdecl __exit(int _Code)

{
  CRT_DoExit(_Code,1,0);
  return;
}
