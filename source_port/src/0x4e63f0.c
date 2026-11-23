// Game_ComputeRecordCompanyPrice: ported from Pizza Connection 2 at 0x4e63f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e63f0
#include "pc2_port.h"

double __thiscall Game_ComputeRecordCompanyPrice(int arg1,int arg2)

{
  int value1;
  double fVar2;
  
  value1 = IDMap_Lookup((void *)(DAT_0057c670 + 0x74),*(int *)(arg1 + 4),(int *)0x0);
  if (value1 == 0) {
    return (double)0.0;
  }
  fVar2 = Game_ComputePrice(value1,arg2);
  return fVar2;
}
