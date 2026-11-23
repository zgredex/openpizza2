// SchoolMenu_FillLocalStructure: ported from Pizza Connection 2 at 0x4bf400.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4bf400
#include "pc2_port.h"

void __cdecl SchoolMenu_FillLocalStructure(void *arg1)

{
  void *pvVar1;
  int value2;
  int value3;
  int *ptr4;
  int local_190 [36];
  int local_100 [64];
  
  pvVar1 = *(void **)((intptr_t)DAT_0057c670 + 0x218);
  if (*(int *)((intptr_t)pvVar1 + 4) == 0xb) {
    pvVar1 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),
                                  *(int *)((intptr_t)DAT_0057c670 + 0x2f4),(int *)0x0);
    pvVar1 = (void *)Map_GetRandomBuildingOfType(pvVar1,0xb,0,'\0');
  }
  value3 = 0;
  ptr4 = local_190;
  for (value2 = 0x24; value2 != 0; value2 = value2 + -1) {
    *ptr4 = 0;
    ptr4 = ptr4 + 1;
  }
  ptr4 = local_100;
  for (value2 = 0x40; value2 != 0; value2 = value2 + -1) {
    *ptr4 = 0;
    ptr4 = ptr4 + 1;
  }
  ptr4 = local_190;
  do {
    value2 = Game_CountFreeBuildingsByType(pvVar1,value3);
    *ptr4 = value2;
    value3 = value3 + 1;
    ptr4 = ptr4 + 1;
  } while (value3 < 0x24);
  Chart_DrawCustomerPortraits(arg1,0x429,local_190);
  Game_CountProductUsageByCategory(DAT_0057c670,(intptr_t)pvVar1,local_100);
  CustomerGroups_DrawProductSalesGrid(arg1,0x1f45,local_100);
  return;
}
