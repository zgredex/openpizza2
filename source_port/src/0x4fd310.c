// AI_EnsureBranchStorage: ported from Pizza Connection 2 at 0x4fd310.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fd310
#include "pc2_port.h"

uint32_t __thiscall AI_EnsureBranchStorage(void *self,uint32_t arg1,int arg2)

{
  void *this_00;
  void *pvVar1;
  int value2;
  void *this_01;
  uint32_t uvalue3;
  int value4;
  void *pvVar5;
  int value6;
  bool flag7;
  int64_t lvalue8;
  int local_c;
  int local_8;
  int local_4;
  
                    /* Ensures a branch has a storage/supplier building. */
  value4 = *(int *)((intptr_t)self + arg1 * 0x168 + 0x40);
  this_00 = (void *)Game_GetPlayerBySlot(DAT_0057c670,value4);
  if (*(int *)((intptr_t)this_00 + 0x194) < 1) {
    local_8 = *(int *)(arg2 + 0x34);
    pvVar1 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),local_8,(int *)0x0);
    pvVar5 = (void *)AI_FindNearestHouse(value4,pvVar1);
    flag7 = pvVar5 == (void *)0x0;
    if (flag7) {
      pvVar5 = (void *)AI_FindCheapestShop(value4,pvVar1,1);
    }
    arg1 = (uint32_t)!flag7;
    if (pvVar5 == (void *)0x0) {
      return 3;
    }
    Game_ComputeTradeOffers(pvVar1,(intptr_t)pvVar5,3,&local_c,&local_4,value4,(int *)0x0);
    value4 = Player_BuildStorage(local_8,pvVar5,value4,0,arg1);
    value4 = IDMap_Lookup((void *)((intptr_t)this_00 + 0x180),value4,(int *)0x0);
    if (arg1 == 0) {
      *(uint8_t *)(value4 + 0x3c) = 1;
      lvalue8 = __ftol();
      *(int *)(value4 + 0x40) = (intptr_t)lvalue8;
      value4 = 2;
      local_c = local_4;
    }
    else {
      *(uint8_t *)(value4 + 0x3c) = 0;
      *(int *)(value4 + 0x40) = local_c;
      value4 = 0;
    }
    Game_CanAffordWithCurrency(this_00,value4,(float)local_c,'\0',0xffffffff);
  }
  else {
    pvVar1 = (void *)IDMap_Lookup((void *)((intptr_t)this_00 + 0x180),0,(int *)0x0);
    if (pvVar1 != (void *)0x0) {
      value6 = *(int *)((intptr_t)this_00 + 0x15c) >> 2;
      if (2 < value6) {
        value6 = 2;
      }
      value2 = Get_Field2C((intptr_t)pvVar1);
      if ((value2 < value6) &&
         (pvVar5 = *(void **)((intptr_t)pvVar1 + 0x34), *(int *)((intptr_t)pvVar5 + 0x38) == 0)) {
        this_01 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)pvVar5 + 0x28),
                                       (int *)0x0);
        value6 = Get_Field2C((intptr_t)pvVar1);
        lvalue8 = Stats_GetCombinedValue(3,value6);
        uvalue3 = Game_CanAffordWithCurrency(this_00,2,(float)(intptr_t)lvalue8,'\x01',0xffffffff);
        if ((char)uvalue3 != '\0') {
          *(int *)((intptr_t)pvVar5 + 0x3c) = (intptr_t)lvalue8;
          MapObject_SpawnByKind(this_01,pvVar5,3,value4,(void *)0xffffffff,-1);
        }
      }
      value4 = Storage_GetFillPercent((intptr_t)pvVar1);
      if (0 < value4) {
        Game_CompleteStaffAssignment(this_00,arg2,pvVar1);
      }
    }
  }
  *(uint32_t *)(arg2 + 0x28) = *(uint32_t *)(arg2 + 0x28) | 8;
  return 1;
}
