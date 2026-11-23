// CityMap_PlaceHouseBlocks: ported from Pizza Connection 2 at 0x4facb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4facb0
#include "pc2_port.h"

int CityMap_PlaceHouseBlocks(int *arg1,uint32_t arg2)

{
  int *ptr1;
  int value2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  int value5;
  int *ptr6;
  int *ptr7;
  int local_8;
  int local_4;
  
  uvalue4 = arg2;
  ptr1 = arg1;
  value5 = 0;
  if (arg2 == 0) {
    return 0;
  }
  value2 = AI_SelectBestPlan(6,*(int *)(*arg1 + 0x24),(intptr_t)arg1,(int *)&arg1,&arg2,-1,-1)
  ;
  if (value2 == -1) {
    return 0;
  }
  ptr7 = &local_4;
  ptr6 = &local_8;
  uvalue3 = Random_Mod(arg2);
  City_GetListEndpoints(DAT_0057c670,(intptr_t)arg1,uvalue3,ptr6,ptr7);
  if (0 < (intptr_t)uvalue4) {
    do {
      value2 = CityMap_StampObjectPattern(ptr1,4,4,(int *)s_aa_aa_00571f40,(intptr_t)&local_8,1,1,' ');
      if (value2 != 0) {
        value5 = value5 + 1;
      }
      uvalue4 = uvalue4 - 1;
    } while (uvalue4 != 0);
  }
  return value5;
}
