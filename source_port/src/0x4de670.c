// Game_GetMaxMatrixValue: ported from Pizza Connection 2 at 0x4de670.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4de670
#include "pc2_port.h"

int __thiscall Game_GetMaxMatrixValue(void *self,int arg1)

{
  int value1;
  int value2;
  int value3;
  int value4;
  
  value4 = 0;
  if (arg1 != 0) {
    value4 = Matrix_Max4x9(arg1);
    return value4;
  }
  value2 = 0;
  do {
    value3 = 0;
    do {
      value1 = Game_SumPlayerMatrixValues(self,value2,value3,(void *)0x0);
      if (value4 < value1) {
        value4 = value1;
      }
      value3 = value3 + 1;
    } while (value3 < 9);
    value2 = value2 + 1;
  } while (value2 < 4);
  return value4;
}
