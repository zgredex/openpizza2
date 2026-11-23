// __ftol: ported from Pizza Connection 2 at 0x54f140.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54f140
#include "pc2_port.h"

/* Library Function - Single Match
    __ftol
   
   Library: Visual Studio */

int64_t __ftol(void)

{
  double in_ST0;
  
  return (int64_t)ROUND(in_ST0);
}
