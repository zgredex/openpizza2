// Storage_DistributeCostToShops: ported from Pizza Connection 2 at 0x514100.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x514100
#include "pc2_port.h"


void __thiscall Storage_DistributeCostToShops(void *self,float arg1,char arg2)

{
  void *this_00;
  void *this_01;
  int value1;
  int value2;
  int value3;
  int *ptr4;
  
  value3 = 0;
  this_00 = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)self + 0x24));
  ptr4 = (int *)((intptr_t)self + 0x60);
  value1 = 0x14;
  value2 = (-(uint32_t)(arg2 != '\0') & 0xfffffff2) + 0xe;
  do {
    if (*ptr4 != 0) {
      value3 = value3 + 1;
    }
    ptr4 = ptr4 + 3;
    value1 = value1 + -1;
  } while (value1 != 0);
  if (value3 == 0) {
    Game_CanAffordWithCurrency(this_00,value2,arg1,'\0',0xffffffff);
    return;
  }
  ptr4 = (int *)((intptr_t)self + 100);
  _param_2 = 0x14;
  do {
    if (ptr4[-1] != 0) {
      this_01 = (void *)IDMap_Lookup((void *)((intptr_t)this_00 + 0x148),*ptr4,(int *)0x0);
      Game_CanAfford(this_01,value2,arg1 / (float)value3,'\0',-1);
    }
    ptr4 = ptr4 + 3;
    _param_2 = _param_2 + -1;
  } while (_param_2 != 0);
  return;
}
