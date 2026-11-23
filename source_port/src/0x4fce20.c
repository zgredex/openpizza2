// AI_Action_BuildNewBranch: ported from Pizza Connection 2 at 0x4fce20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fce20
#include "pc2_port.h"

uint64_t __thiscall AI_Action_BuildNewBranch(void *self,int arg1)

{
  int value1;
  int value2;
  void *this_00;
  int value3;
  void *pvVar4;
  int value5;
  void *pvVar6;
  uint32_t extraout_EDX;
  uint32_t extraout_EDX_00;
  uint32_t extraout_EDX_01;
  uint32_t extraout_EDX_02;
  uint32_t extraout_EDX_03;
  uint32_t extraout_EDX_04;
  uint32_t extraout_EDX_05;
  uint32_t uvalue7;
  int value8;
  int64_t lvalue9;
  int64_t lvalue10;
  int local_1c;
  int local_4;
  
                    /* Starts a new branch project when the AI company can expand. */
  value2 = arg1;
  value1 = *(int *)((intptr_t)self + arg1 * 0x168 + 0x40);
  this_00 = (void *)Game_GetPlayerBySlot(DAT_0057c670,value1);
  value8 = 0;
  pvVar6 = *(void **)((intptr_t)this_00 + 0x1d8);
  if (((pvVar6 == (void *)0x0) || (uvalue7 = extraout_EDX, *(int *)((intptr_t)pvVar6 + 0x38) == 0)) &&
     (value3 = Game_GetPlayerCount((intptr_t)DAT_0057c670), uvalue7 = extraout_EDX_00, 1 < value3)) {
    local_1c = 0;
    if (0 < value3) {
      do {
        pvVar4 = (void *)Game_GetPlayerBySlot(DAT_0057c670,value8);
        if ((pvVar4 != this_00) && (value5 = Game_GetPlayerFieldC20((intptr_t)pvVar4), local_1c <= value5))
        {
          local_1c = Game_GetPlayerFieldC20((intptr_t)pvVar4);
        }
        value8 = value8 + 1;
      } while (value8 < value3);
    }
    value8 = *(int *)((intptr_t)self + value2 * 0x168 + 0x134);
    value3 = Game_GetPlayerFieldC20((intptr_t)this_00);
    pvVar4 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),
                                  *(int *)((intptr_t)DAT_0057c670 + 0x2f4),(int *)0x0);
    uvalue7 = extraout_EDX_01;
    if (value3 != DAT_0057bb38) {
      if ((pvVar6 == (void *)0x0) || (value3 == 0)) {
        pvVar6 = (void *)AI_FindCheapestShop(*(int *)((intptr_t)this_00 + 0x48),pvVar4,0);
        if (pvVar6 == (void *)0x0) {
          return CONCAT44(extraout_EDX_03,3);
        }
        Game_ComputeTradeOffers(pvVar4,(intptr_t)pvVar6,4,&local_4,&arg1,value1,(int *)0x0);
        value1 = arg1;
        if (local_1c < 2) {
          lvalue10 = CONCAT44(extraout_EDX_04,arg1 * 2);
        }
        else {
          lvalue10 = __ftol();
        }
        arg1 = (intptr_t)lvalue10;
        if (value8 < arg1) {
          return CONCAT44((intptr_t)((uint64_t)lvalue10 >> 0x20),2);
        }
        Game_CanAffordWithCurrency(this_00,3,(float)value1,'\0',0xffffffff);
        Player_BuildHeadquarters(*(int *)((intptr_t)self + value2 * 0x168 + 0x40),pvVar4,pvVar6,0,0);
        *(int *)((intptr_t)pvVar6 + 0x3c) = value1;
        uvalue7 = extraout_EDX_05;
      }
      else if ((0 < value3) && (value3 < 7)) {
        lvalue9 = Stats_GetCombinedValue(4,value3);
        arg1 = (intptr_t)lvalue9;
        lvalue10 = __ftol();
        arg1 = (intptr_t)lvalue10;
        if (value3 + 1 < local_1c) {
          lvalue10 = __ftol();
          arg1 = (intptr_t)lvalue10;
        }
        if (value8 < (intptr_t)lvalue10) {
          return CONCAT44((intptr_t)((uint64_t)lvalue10 >> 0x20),2);
        }
        Game_CanAffordWithCurrency(this_00,3,(float)(intptr_t)lvalue9,'\0',0xffffffff);
        *(int *)((intptr_t)pvVar6 + 0x3c) = arg1;
        MapObject_SpawnByKind(pvVar4,pvVar6,4,value1,(void *)0xffffffff,-1);
        return CONCAT44(extraout_EDX_02,1);
      }
    }
  }
  return CONCAT44(uvalue7,1);
}
