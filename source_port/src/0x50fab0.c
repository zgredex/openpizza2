// GamePlan_GetCompanyCategoryMetric: ported from Pizza Connection 2 at 0x50fab0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50fab0
#include "pc2_port.h"

int __fastcall
GamePlan_GetCompanyCategoryMetric
          (uint32_t arg1,uint32_t arg2,void *arg3,int arg4,uint32_t arg5)

{
  int value1;
  
  switch(arg5) {
  case 1:
    value1 = Branch_GetPriceRating(arg3,arg4);
    return value1;
  case 2:
    value1 = Branch_GetMenuRating(arg3,arg4);
    return value1;
  default:
    return 0;
  case 4:
    value1 = Branch_ComputeBuildingRating(arg3,arg2,arg4);
    return value1;
  case 8:
    value1 = Stats_GetAverage8(arg3,arg4);
    return value1;
  }
}
