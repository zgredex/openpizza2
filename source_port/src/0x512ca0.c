// AI_CheckPriceCompetitiveness: ported from Pizza Connection 2 at 0x512ca0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x512ca0
#include "pc2_port.h"

void __fastcall AI_CheckPriceCompetitiveness(void *arg1)

{
  float fVar1;
  bool flag2;
  int value3;
  void *self;
  uint32_t extraout_var;
  uint32_t extraout_var_00;
  uint32_t extraout_var_01;
  uint32_t extraout_var_02;
  int *ptr4;
  uint32_t uvalue5;
  int64_t lvalue6;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  do {
    value3 = Game_GetPlayerBySlot(DAT_0057c670,local_8);
    if ((value3 != 0) && (local_c = 0, 0 < *(int *)(value3 + 0x124))) {
      do {
        self = (void *)IDMap_Lookup((void *)(value3 + 0x110),local_c,(int *)0x0);
        if ((self != (void *)0x0) && (self != arg1)) {
          local_14 = 0;
          local_10 = 0;
          local_18 = 0;
          local_1c = 0;
          uvalue5 = 0;
          ptr4 = (int *)((intptr_t)self + 100);
          do {
            flag2 = Product_HasStock(self,uvalue5);
            if (CONCAT31(extraout_var,flag2) != 0) {
              local_1c = local_1c + 1;
            }
            flag2 = Product_HasStock(arg1,uvalue5);
            if (CONCAT31(extraout_var_00,flag2) == 0) {
              flag2 = Product_HasStock(self,uvalue5);
              if ((CONCAT31(extraout_var_02,flag2) != 0) && (10 < *ptr4)) {
                local_14 = local_14 + 1;
              }
            }
            else {
              flag2 = Product_HasStock(self,uvalue5);
              if (CONCAT31(extraout_var_01,flag2) == 0) {
                if (10 < *(int *)((intptr_t)ptr4 + ((intptr_t)arg1 - (intptr_t)self))) {
                  local_18 = local_18 + 1;
                }
              }
              else {
                fVar1 = (float)*(int *)((intptr_t)ptr4 + ((intptr_t)arg1 - (intptr_t)self));
                if ((fVar1 * 0.8 <= (float)*ptr4) && ((float)*ptr4 <= fVar1 * 1.2)) {
                  local_10 = local_10 + 1;
                }
              }
            }
            uvalue5 = uvalue5 + 1;
            ptr4 = ptr4 + 1;
          } while ((intptr_t)uvalue5 < 0x56);
          if ((local_18 < 2) && (local_14 < 2)) {
            if (local_1c == local_10) {
              *(uint32_t *)((intptr_t)arg1 + 0x240) = 0;
              return;
            }
            if ((2 < local_1c) && (lvalue6 = __ftol(), (intptr_t)lvalue6 <= local_10)) {
              *(uint32_t *)((intptr_t)arg1 + 0x240) = 0;
              return;
            }
          }
        }
        local_c = local_c + 1;
      } while (local_c < *(int *)(value3 + 0x124));
    }
    local_8 = local_8 + 1;
    if (5 < local_8) {
      *(uint32_t *)((intptr_t)arg1 + 0x240) = 1;
      return;
    }
  } while( true );
}
