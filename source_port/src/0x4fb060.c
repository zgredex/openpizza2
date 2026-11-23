// CityMap_PlaceLargeComplexes: ported from Pizza Connection 2 at 0x4fb060.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fb060
#include "pc2_port.h"

int CityMap_PlaceLargeComplexes(int *arg1,int arg2)

{
  int *ptr1;
  int value2;
  uint32_t uvalue3;
  int value4;
  int value5;
  int *ptr6;
  int *ptr7;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  value4 = arg2;
  ptr1 = arg1;
  value5 = 0;
  value2 = AI_SelectBestPlan(7,arg2,(intptr_t)arg1,&arg2,(uint32_t *)&arg1,-1,-1);
  if (value2 == -1) {
    return 0;
  }
  ptr7 = &local_c;
  ptr6 = &local_10;
  uvalue3 = Random_Mod((uint32_t)arg1);
  City_GetListEndpoints(DAT_0057c670,arg2,uvalue3,ptr6,ptr7);
  value2 = AI_SelectBestPlan(3,4,(intptr_t)ptr1,&arg2,(uint32_t *)&arg1,2,2);
  if (value2 == -1) {
    return 0;
  }
  ptr7 = &local_4;
  ptr6 = &local_8;
  uvalue3 = Random_Mod((uint32_t)arg1);
  City_GetListEndpoints(DAT_0057c670,arg2,uvalue3,ptr6,ptr7);
  if (value4 == 3) {
    uvalue3 = 1;
  }
  else {
    uvalue3 = 2;
  }
  uvalue3 = Random_RangeFast((uint32_t)(value4 != 3),uvalue3);
  if (0 < (intptr_t)uvalue3) {
    do {
      value4 = CityMap_StampObjectPattern
                        (ptr1,0xc,6,(int *)s_bbaaaabb_bbaaaabb_aaaa_aaaa_00571f8c,(intptr_t)&local_10,1
                         ,0,' ');
      if (value4 != 0) {
        value5 = value5 + 1;
      }
      uvalue3 = uvalue3 - 1;
    } while (uvalue3 != 0);
  }
  return value5;
}
