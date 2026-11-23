// CRT_Atexit: ported from Pizza Connection 2 at 0x54dea3.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54dea3
#include "pc2_port.h"

int __cdecl CRT_Atexit(int arg1)

{
  int value1;
  
  value1 = CRT_Onexit(arg1);
  return (value1 != 0) - 1;
}
