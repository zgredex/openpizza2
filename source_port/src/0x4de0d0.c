// Stats_GetMaxMatrixValue: ported from Pizza Connection 2 at 0x4de0d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4de0d0
#include "pc2_port.h"

int __thiscall Stats_GetMaxMatrixValue(void *self,void *arg1)

{
  int value1;
  int value2;
  int value3;
  int value4;
  
  value4 = 0;
  if (arg1 != (void *)0x0) {
    value4 = Matrix_MaxByRow9x8(arg1,-1);
    return value4;
  }
  value2 = 0;
  do {
    value3 = 0;
    do {
      value1 = Game_SumStatGridAll(self,value2,value3,(void *)0x0);
      if (value4 < value1) {
        value4 = value1;
      }
      value3 = value3 + 1;
    } while (value3 < 9);
    value2 = value2 + 1;
  } while (value2 < 8);
  return value4;
}
