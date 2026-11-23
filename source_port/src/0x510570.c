// Get_Float44: ported from Pizza Connection 2 at 0x510570.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x510570
#include "pc2_port.h"

double __fastcall Get_Float44(int arg1)

{
  return (double)*(float *)(arg1 + 0x44);
}
