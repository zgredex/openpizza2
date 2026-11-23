// Rating_GetFloat: ported from Pizza Connection 2 at 0x489070.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x489070
#include "pc2_port.h"

double Rating_GetFloat(int arg1,uint32_t arg2)

{
  float fVar1;
  double fVar2;
  
  fVar1 = *(float *)(arg1 + 0x98);
  fVar2 = (double)(0xb - DAT_0057bb24) * (double)0.5;
  switch(arg2) {
  case 0:
    return (double)fVar1 * (double)3.0 + fVar2 + (double)4.0;
  case 1:
    return (double)fVar1 * (double)4.0 + fVar2 + (double)5.0;
  case 2:
    return (double)fVar1 * (double)4.0 + fVar2 + (double)8.0;
  case 3:
    return (double)fVar1 * (double)3.0 + fVar2 + (double)8.0;
  case 4:
    return (double)fVar1 * (double)7.0 + fVar2 + (double)10.0;
  case 5:
  case 8:
    return (double)fVar1 * (double)10.0 + fVar2 + (double)8.0;
  case 6:
    return (double)fVar1 * (double)3.0 + fVar2 + (double)7.0;
  case 7:
    fVar2 = fVar2 + (double)12.0;
  }
  return fVar2;
}
