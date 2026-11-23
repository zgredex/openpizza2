// Stats_GetAmountByType: ported from Pizza Connection 2 at 0x48d070.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48d070
#include "pc2_port.h"

double Stats_GetAmountByType(uint32_t arg1)

{
  switch(arg1) {
  case 0:
    return (double)576.0;
  case 1:
    return (double)2322.0;
  case 2:
    return (double)1368.0;
  case 3:
    return (double)1656.0;
  default:
    return (double)0.0;
  }
}
