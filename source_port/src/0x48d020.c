// Building_GetAreaByLevel: ported from Pizza Connection 2 at 0x48d020.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48d020
#include "pc2_port.h"

double Building_GetAreaByLevel(uint32_t arg1)

{
  switch(arg1) {
  case 0:
    return (double)2070.0;
  case 1:
    return (double)2916.0;
  case 2:
    return (double)3420.0;
  case 3:
    return (double)3960.0;
  default:
    return (double)0.0;
  }
}
