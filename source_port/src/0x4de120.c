// Stats_GetMaxCityMatrixValue: ported from Pizza Connection 2 at 0x4de120.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4de120
#include "pc2_port.h"

int __thiscall Stats_GetMaxCityMatrixValue(void *self,uint32_t arg1)

{
  uint16_t uvalue1;
  int value2;
  int value3;
  int value4;
  int value5;
  
  value5 = 0;
  if (arg1 != 0) {
    value5 = Matrix_Max100x8(arg1);
    return value5;
  }
  uvalue1 = *(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  arg1 = (uint32_t)uvalue1;
  if (100 < uvalue1) {
    arg1 = 100;
  }
  value3 = 0;
  if (arg1 == 0) {
    return 0;
  }
  do {
    value4 = 0;
    do {
      value2 = Stats_SumMatrixCells(self,value4,value3,(void *)0x0);
      if (value5 < value2) {
        value5 = value2;
      }
      value4 = value4 + 1;
    } while (value4 < 8);
    value3 = value3 + 1;
  } while (value3 < (intptr_t)arg1);
  return value5;
}
