// City_EnsurePedestrianCoverage: ported from Pizza Connection 2 at 0x4fd520.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fd520
#include "pc2_port.h"

void __thiscall City_EnsurePedestrianCoverage(void *self,int arg1)

{
  int *ptr1;
  void *this_00;
  void *pvVar2;
  void *this_01;
  int value3;
  int value4;
  int local_c;
  
                    /* Ensures residential buildings have pedestrian coverage. */
  local_c = 0;
  ptr1 = (int *)((intptr_t)self + arg1 * 0x168 + 0x70);
  if (0 < *(int *)(*ptr1 + 0x15c)) {
    do {
      pvVar2 = (void *)Game_GetPlayerSubrecord(self,arg1,local_c,1);
      if (pvVar2 != (void *)0x0) {
        this_01 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)pvVar2 + 0x34),
                                       (int *)0x0);
        value3 = Game_CountFreeResidentialBuildings((intptr_t)pvVar2);
        value4 = *ptr1;
        if (0 < value3) {
          this_00 = *(void **)((intptr_t)pvVar2 + 0x16f0);
          value3 = Game_CountFreeBuildingsByType(this_00,0x20);
          if (value3 < 1) {
            if (*(double *)(value4 + 0x108) <= 30000.0) {
              value4 = Game_CountFilteredObjects(DAT_0057c670,1,0x20,(intptr_t)this_00,-1);
              if (value4 < 1) {
                value4 = 1;
                goto LAB_004fd5e4;
              }
            }
            else {
              value4 = Game_CountFilteredObjects(DAT_0057c670,2,0x20,(intptr_t)this_00,-1);
              if (value4 < 1) {
                value4 = 2;
LAB_004fd5e4:
                Branch_HireExterminator(this_01,value4,pvVar2);
              }
            }
          }
        }
      }
      local_c = local_c + 1;
    } while (local_c < *(int *)(*ptr1 + 0x15c));
  }
  return;
}
