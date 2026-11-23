// CityMap_PlaceBuildingBlocks: ported from Pizza Connection 2 at 0x4fab10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fab10
#include "pc2_port.h"

int CityMap_PlaceBuildingBlocks(int *arg1,uint32_t arg2,char arg3,int arg4)

{
  uint32_t uvalue1;
  void *self;
  int value2;
  int *ptr3;
  int *ptr4;
  uint32_t local_90;
  uint32_t local_8c;
  int local_88;
  int local_84;
  uint32_t local_80;
  uint32_t local_7c;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64 [25];
  
  local_84 = 0;
  if (arg4 < 1) {
    return 0;
  }
  if (arg2 == 5) {
    local_88 = City_FindMatchingCity(arg1);
    local_80 = 1;
  }
  else {
    AI_SelectBestPlan(arg2,*(int *)(*arg1 + 0x24),(intptr_t)arg1,&local_88,&local_80,-1,-1);
  }
  ptr3 = &local_70;
  ptr4 = &local_74;
  uvalue1 = Random_Mod(local_80);
  City_GetListEndpoints(DAT_0057c670,local_88,uvalue1,ptr4,ptr3);
  local_6c = local_74;
  local_68 = local_70;
  self = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 0x74),local_88,(int *)0x0);
  Object_GetPair68(self,&local_8c,&local_90);
  if ((intptr_t)local_8c < 1) {
    local_8c = 1;
  }
  if ((intptr_t)local_90 < 1) {
    local_90 = 1;
  }
  ptr3 = local_64;
  for (uvalue1 = local_8c * local_90 >> 2; uvalue1 != 0; uvalue1 = uvalue1 - 1) {
    *ptr3 = 0x20202020;
    ptr3 = ptr3 + 1;
  }
  for (uvalue1 = local_8c * local_90 & 3; uvalue1 != 0; uvalue1 = uvalue1 - 1) {
    *(uint8_t *)ptr3 = 0x20;
    ptr3 = (int *)((intptr_t)ptr3 + 1);
  }
  if (0 < (intptr_t)local_90) {
    ptr3 = local_64;
    local_7c = local_90;
    do {
      ptr4 = ptr3;
      for (uvalue1 = local_8c >> 2; uvalue1 != 0; uvalue1 = uvalue1 - 1) {
        *ptr4 = 0x61616161;
        ptr4 = ptr4 + 1;
      }
      ptr3 = (int *)((intptr_t)ptr3 + local_8c);
      for (uvalue1 = local_8c & 3; uvalue1 != 0; uvalue1 = uvalue1 - 1) {
        *(uint8_t *)ptr4 = 0x61;
        ptr4 = (int *)((intptr_t)ptr4 + 1);
      }
      local_7c = local_7c - 1;
    } while (local_7c != 0);
    local_7c = 0;
  }
  if (0 < arg4) {
    do {
      value2 = CityMap_StampObjectPattern
                        (arg1,local_8c,local_90,local_64,(intptr_t)&local_74,1,0,arg3);
      if (value2 != 0) {
        local_84 = local_84 + 1;
      }
      arg4 = arg4 + -1;
    } while (arg4 != 0);
  }
  return local_84;
}
