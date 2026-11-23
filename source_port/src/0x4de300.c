// Stats_GetMaxObjectMatrixValue: ported from Pizza Connection 2 at 0x4de300.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4de300
#include "pc2_port.h"

double __thiscall Stats_GetMaxObjectMatrixValue(int arg1,int arg2)

{
  int value1;
  int value2;
  double fVar3;
  float local_4;
  
  local_4 = 0.0;
  if (arg2 != 0) {
    fVar3 = Grid_GetMaxValue(arg2);
    return fVar3;
  }
  value2 = 0;
  do {
    value1 = 0;
    do {
      fVar3 = Stats_SumRecordFloatMatrix(arg1,value2,value1,0);
      if ((double)local_4 < fVar3) {
        local_4 = (float)fVar3;
      }
      value1 = value1 + 1;
    } while (value1 < 9);
    value2 = value2 + 1;
  } while (value2 < 8);
  return (double)local_4;
}
