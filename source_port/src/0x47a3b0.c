// Branch_GetCustomerGroupRating: ported from Pizza Connection 2 at 0x47a3b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47a3b0
#include "pc2_port.h"

int __thiscall Branch_GetCustomerGroupRating(void *self,int arg1,int arg2)

{
  int value1;
  int value2;
  int value3;
  int value4;
  uint32_t extraout_EDX;
  int value5;
  
  value4 = arg1;
  value5 = 3;
  value1 = Stats_GetAverage8(self,arg1);
  value2 = Branch_ComputeBuildingRating(self,extraout_EDX,value4);
  value3 = Branch_GetMenuRating(self,value4);
  value3 = value1 + value2 + value3;
  if (arg2 != 0) {
    value1 = Branch_GetPriceComparisonRating(self,value4,&arg1);
    if (arg1 != 0) {
      value3 = value3 + value1;
      value5 = 4;
    }
  }
  value4 = Rating_ComputeBuildingScore(self,value4);
  value4 = value4 + value3 / value5;
  if (value4 < 0) {
    return 0;
  }
  value1 = 100;
  if (value4 < 0x65) {
    value1 = value4;
  }
  return value1;
}
