// Branch_RecomputeMenuPriceRatings: ported from Pizza Connection 2 at 0x4784e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4784e0
#include "pc2_port.h"

void __fastcall Branch_RecomputeMenuPriceRatings(int arg1)

{
  int value1;
  void *self;
  void *this_00;
  int value2;
  uint32_t uvalue3;
  int value4;
  int *ptr5;
  double fVar6;
  int64_t lvalue7;
  uint32_t uvalue8;
  float local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  void *local_68;
  int local_64;
  int local_60 [8];
  int local_40 [16];
  
  value4 = 0;
  local_40[0] = 4;
  local_40[1] = 7;
  local_40[2] = 9;
  local_40[3] = 5;
  local_40[4] = 10;
  local_40[5] = 3;
  local_40[6] = 6;
  local_40[7] = 8;
  local_7c = 0.0;
  local_78 = 0;
  value1 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)(arg1 + 0x34),(int *)0x0);
  self = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)(arg1 + 0x30));
  local_68 = self;
  Rating_GetFloat(value1,0);
  lvalue7 = __ftol();
  local_60[0] = (intptr_t)lvalue7;
  Rating_GetFloat(value1,1);
  lvalue7 = __ftol();
  local_60[1] = (intptr_t)lvalue7;
  Rating_GetFloat(value1,2);
  lvalue7 = __ftol();
  local_60[2] = (intptr_t)lvalue7;
  Rating_GetFloat(value1,3);
  lvalue7 = __ftol();
  local_60[3] = (intptr_t)lvalue7;
  Rating_GetFloat(value1,4);
  lvalue7 = __ftol();
  local_60[4] = (intptr_t)lvalue7;
  Rating_GetFloat(value1,5);
  lvalue7 = __ftol();
  local_60[5] = (intptr_t)lvalue7;
  Rating_GetFloat(value1,6);
  lvalue7 = __ftol();
  local_60[6] = (intptr_t)lvalue7;
  Rating_GetFloat(value1,7);
  lvalue7 = __ftol();
  local_60[7] = (intptr_t)lvalue7;
  *(uint32_t *)(arg1 + 0x1714) = 1;
  ptr5 = local_40 + 8;
  for (value1 = 8; value1 != 0; value1 = value1 + -1) {
    *ptr5 = 0;
    ptr5 = ptr5 + 1;
  }
  local_70 = 0;
  value1 = Game_CountActiveCompanies((intptr_t)self);
  if (-1 < value1) {
    do {
      if (value4 == 0) {
        this_00 = *(void **)(arg1 + 0x14dc);
      }
      else {
        this_00 = (void *)Game_GetActiveCompanyById(self,value4 + -1);
      }
      if (this_00 != (void *)0x0) {
        fVar6 = Branch_ComputeRecipePrice((intptr_t)this_00,arg1,-999);
        local_78 = local_78 + 1;
        uvalue3 = 0;
        local_7c = (float)(fVar6 + (double)local_7c);
        ptr5 = local_40 + 8;
        do {
          fVar6 = Branch_ComputeRecipePrice((intptr_t)this_00,arg1,-999);
          local_6c = Game_ComputeCompanyProductScore(this_00,arg1,uvalue3,(float)fVar6);
          uvalue8 = uvalue3;
          fVar6 = Branch_ComputeRecipePrice((intptr_t)this_00,arg1,-999);
          local_64 = Game_GetSkillRating(this_00,arg1,(float)fVar6,uvalue8);
          uvalue3 = uvalue3 + 1;
          *ptr5 = *ptr5 + local_6c;
          ptr5 = ptr5 + 1;
        } while ((intptr_t)uvalue3 < 8);
        self = local_68;
        value4 = local_70;
      }
      value4 = value4 + 1;
      local_70 = value4;
      value1 = Game_CountActiveCompanies((intptr_t)self);
    } while (value4 <= value1);
  }
  ptr5 = local_40 + 8;
  value4 = 8;
  do {
    if (local_78 < 1) {
      *ptr5 = 0;
    }
    else {
      *ptr5 = *ptr5 / local_78;
      Clamp_0_100(ptr5);
    }
    ptr5 = ptr5 + 1;
    value4 = value4 + -1;
  } while (value4 != 0);
  if (local_78 < 1) {
    local_7c = 200.0;
  }
  else {
    local_7c = local_7c / (float)local_78;
  }
  ptr5 = (int *)(arg1 + 0x177c);
  value4 = 0;
  do {
    if (local_7c <= (float)*(int *)((intptr_t)local_60 + value4)) {
      value1 = 100;
    }
    else {
      lvalue7 = __ftol();
      value1 = 100 - (intptr_t)lvalue7;
    }
    value2 = *(int *)((intptr_t)local_40 + value4);
    ptr5[8] = value1;
    if (local_78 < value2) {
      value2 = value2 - local_78;
      value2 = value2 * value2;
      local_74 = 100 - value2 * value2;
      Clamp_0_100(&local_74);
    }
    else {
      local_74 = 100;
    }
    value2 = *(int *)((intptr_t)local_40 + value4 + 0x20) + local_74 >> 1;
    if (value1 < value2) {
      value2 = value1;
    }
    *ptr5 = value2;
    Clamp_0_100(ptr5);
    value4 = value4 + 4;
    ptr5 = ptr5 + 1;
  } while (value4 < 0x20);
  return;
}
