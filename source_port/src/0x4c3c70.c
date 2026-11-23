// Lookup_BytePlusOne: ported from Pizza Connection 2 at 0x4c3c70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c3c70
#include "pc2_port.h"

int __cdecl Lookup_BytePlusOne(int arg1)

{
  if (arg1 == 0) {
    return 0;
  }
  return (&DAT_0057d73c)[arg1] + 1;
}
