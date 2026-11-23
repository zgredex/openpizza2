// Game_GetBestObject: ported from Pizza Connection 2 at 0x47f2e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47f2e0
#include "pc2_port.h"

uint32_t __thiscall Game_GetBestObject(void *self,int arg1,int arg2,float *arg3)

{
  bool flag1;
  int value2;
  void *this_00;
  int value3;
  double fVar4;
  float local_8;
  
  value3 = 0;
  local_8 = 0.0;
  flag1 = false;
  if (0 < *(int *)((intptr_t)self + 0x170c)) {
    do {
      value2 = IDMap_Lookup((void *)((intptr_t)self + 0x16f8),value3,(int *)0x0);
      if (*(int *)(value2 + 0xc) < arg2) {
        fVar4 = Game_ComputeCityPriceShare((intptr_t)self,value2,(float *)0x0);
        local_8 = (float)(fVar4 + (double)local_8);
      }
      value3 = value3 + 1;
    } while (value3 < *(int *)((intptr_t)self + 0x170c));
  }
  *arg3 = local_8;
  if (arg1 == 0) {
    if (local_8 <= 0.0) {
      return 0;
    }
  }
  else {
    Game_CanAfford(self,5,local_8,'\0',-1);
    value3 = 0;
    if (0 < *(int *)((intptr_t)self + 0x170c)) {
      do {
        this_00 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x16f8),value3,(int *)0x0);
        if (*(int *)((intptr_t)this_00 + 0xc) < arg2) {
          if (*(int *)((intptr_t)this_00 + 0xc) == 0) {
            Game_UpdateObject2(this_00,*(void **)((intptr_t)self + 0x14e0));
            flag1 = true;
          }
          else {
            Game_SetModeByte(this_00,100);
          }
        }
        value3 = value3 + 1;
      } while (value3 < *(int *)((intptr_t)self + 0x170c));
      if (flag1) {
        Game_AdjustPlayerObjectPercent(*(void **)(DAT_0057c670 + 0x90),*(int *)((intptr_t)self + 0x30),5)
        ;
      }
    }
  }
  return 1;
}
