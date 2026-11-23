// AI_Action_AssignSuppliers: ported from Pizza Connection 2 at 0x4fd190.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fd190
#include "pc2_port.h"

uint32_t __thiscall AI_Action_AssignSuppliers(void *self,uint32_t arg1)

{
  int value1;
  void *this_00;
  void *this_01;
  int value2;
  int value3;
  int value4;
  int64_t lvalue5;
  int local_8;
  
                    /* Assigns the best supplier to each AI branch. */
  value3 = 0;
  if (0 < *(int *)(*(int *)((intptr_t)self + arg1 * 0x168 + 0x70) + 0x15c)) {
    do {
      value1 = Game_GetPlayerSubrecord(self,arg1,value3,1);
      if (value1 != 0) {
        AI_EnsureBranchStorage(self,arg1,value1);
        switch(*(uint32_t *)(value1 + 0x24)) {
        case 0:
          break;
        case 1:
          break;
        case 2:
          break;
        case 3:
        }
      }
      value3 = value3 + 1;
    } while (value3 < *(int *)(*(int *)((intptr_t)self + arg1 * 0x168 + 0x70) + 0x15c));
  }
  value3 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)self + arg1 * 0x168 + 0x40));
  this_00 = (void *)IDMap_Lookup((void *)(value3 + 0x180),0,(int *)0x0);
  if (this_00 != (void *)0x0) {
    this_01 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)this_00 + 0x28),
                                   (int *)0x0);
    value1 = 0;
    value4 = 0;
    do {
      value2 = Array_GetStride60(this_01,value4);
      BuildingValue_Compute(value3,this_01,value2);
      lvalue5 = __ftol();
      if ((value4 == 0) || (value1 < (intptr_t)lvalue5)) {
        value1 = (intptr_t)lvalue5;
        local_8 = value4;
      }
      value4 = value4 + 1;
    } while (value4 < 4);
    Storage_SetSupplierBuilding(this_00,local_8);
  }
  return 1;
}
