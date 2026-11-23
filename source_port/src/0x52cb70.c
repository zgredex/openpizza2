// Text_SkipFieldSeparators: ported from Pizza Connection 2 at 0x52cb70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52cb70
#include "pc2_port.h"

void Text_SkipFieldSeparators(int arg1,int *arg2)

{
  char cVar1;
  
  while( true ) {
    cVar1 = *(char *)(*arg2 + arg1);
    if (((cVar1 == '}') || (cVar1 == '\0')) || ((' ' < cVar1 && (cVar1 != ',')))) break;
    *arg2 = *arg2 + 1;
  }
  return;
}
