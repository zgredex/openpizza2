// String_SkipDelimiters: ported from Pizza Connection 2 at 0x4db2e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4db2e0
#include "pc2_port.h"

void __cdecl String_SkipDelimiters(int arg1,int *arg2)

{
  char cVar1;
  
  while( true ) {
    cVar1 = *(char *)(*arg2 + arg1);
    if (((cVar1 != ' ') && (cVar1 != '\t')) && (cVar1 != ',')) break;
    *arg2 = *arg2 + 1;
  }
  return;
}
