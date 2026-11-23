// Stats_HasCurrentSales: ported from Pizza Connection 2 at 0x480010.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x480010
#include "pc2_port.h"

uint32_t __fastcall Stats_HasCurrentSales(int arg1)

{
  double fVar1;
  
  fVar1 = Stats_SumFilteredFloats
                    (arg1,0x19,(uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 4),
                     (uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10));
  if ((double)0.0 < fVar1) {
    return 6;
  }
  return 0;
}
