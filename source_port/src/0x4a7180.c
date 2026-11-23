// BauenPage_UpdateBuildingMarket: ported from Pizza Connection 2 at 0x4a7180.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a7180
#include "pc2_port.h"


void __cdecl BauenPage_UpdateBuildingMarket(void *arg1,char arg2)

{
  uint32_t *uptr1;
  uint32_t *uptr2;
  int value3;
  
                    /* Refreshes the build page's property market and selection. */
  DAT_0057d290 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  DAT_0057d284 = 0;
  UI_SetPosition(arg1,&LAB_004a6f80,0);
  if (DAT_0057d288 != (uint32_t *)0x0) {
    (**(code **)*DAT_0057d288)(1);
    DAT_0057d288 = (uint32_t *)0x0;
  }
  if (arg2 != '\0') {
    UI_Group_Create(arg1,0,2,0x4ef);
    if (*(int *)(DAT_0057c670 + 0x218) == 0) {
      uptr1 = City_CollectBranchBuildings(DAT_0057d290);
      DAT_0057d280 = (uint32_t)((intptr_t)uptr1[5] < 1);
      if (uptr1 != (uint32_t *)0x0) {
        (**(code **)*uptr1)(1);
      }
    }
    else {
      value3 = *(int *)(*(int *)(DAT_0057c670 + 0x218) + 4);
      if ((value3 < 0x14) || (DAT_0057d280 = 0, 0x16 < value3)) {
        DAT_0057d280 = 1;
      }
    }
  }
  Window_GadgetNotify_Button_SetState(arg1,DAT_0057d280 + 0x4ef,1);
  if (DAT_0057d280 == 0) {
    DAT_0057d288 = City_CollectBranchBuildings(DAT_0057d290);
  }
  else {
    DAT_0057d288 = City_CollectBusinessBuildings(DAT_0057d290);
  }
  uptr1 = (uint32_t *)DAT_0057d288[5];
  BuildingMarket_BuildSortedIndex(uptr1);
  uptr2 = City_CollectBranchBuildings(DAT_0057d290);
  UI_SetChildVisibleByID(arg1,0x4ef,(uint32_t)(0 < (intptr_t)uptr2[5]));
  if (uptr2 != (uint32_t *)0x0) {
    (**(code **)*uptr2)(1);
  }
  uptr2 = City_CollectBusinessBuildings(DAT_0057d290);
  UI_SetChildVisibleByID(arg1,0x4f0,(uint32_t)(0 < (intptr_t)uptr2[5]));
  if (uptr2 != (uint32_t *)0x0) {
    (**(code **)*uptr2)(1);
  }
  if (0 < (intptr_t)uptr1) {
    value3 = *(int *)(DAT_0057c670 + 0x218);
    if (value3 == 0) {
      value3 = IDMap_Lookup(DAT_0057d288,*DAT_0057d28c,(int *)0x0);
    }
    DAT_0057d27c = value3;
    if (*(int *)(value3 + 0x4c) == 0) {
      DAT_0057d27c = IDMap_Lookup(DAT_0057d288,*DAT_0057d28c,(int *)0x0);
    }
  }
  *(int *)(DAT_0057c670 + 0x218) = DAT_0057d27c;
  UI_DrawNeighborhoodCustomerIcons(arg1,0x1f43);
  BuildingMarket_ShowSelectedBuildingInfo(arg1);
  return;
}
