// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x511ff0.c:111:22: error: operand of type 'float' cannot be cast to a pointer type
// Recipe_AddCategoryIngredients: ported from Pizza Connection 2 at 0x511ff0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x511ff0
#include "pc2_port.h"

void __thiscall
Recipe_AddCategoryIngredients
          (void *self,void *arg1,uint32_t arg2,uint32_t arg3,uint32_t arg4,uint8_t arg5,
          int arg6)

{
  float fVar1;
  uint8_t flag2;
  uint32_t *this_00;
  uint32_t uvalue3;
  int value4;
  float *fptr5;
  uint32_t uvalue6;
  uint32_t uvalue7;
  uint32_t uvalue8;
  int value9;
  double fVar10;
  int64_t lvalue11;
  uint8_t flag12;
  int *ptr13;
  int value14;
  float local_20 [3];
  int aiStack_14 [5];
  
  flag2 = arg5;
  this_00 = Recipe_CollectCategoryCandidates(arg1,arg2,arg5);
  lvalue11 = Math_TruncateDouble();
  uvalue7 = (uint32_t)lvalue11;
  if (arg6 == -1) {
    uvalue3 = Random_RangeFast(1,arg4);
    uvalue6 = (uint32_t)arg5;
    fVar1 = *(float *)((intptr_t)self + uvalue6 * 4 + 0x314) / (float)(intptr_t)uvalue3;
    _param_5 = uvalue3;
    while (fVar1 < 10.0) {
      _param_5 = _param_5 - 1;
      if (_param_5 == 0) {
        _param_5 = 1;
        break;
      }
      fVar1 = *(float *)((intptr_t)self + uvalue6 * 4 + 0x314) / (float)(intptr_t)_param_5;
    }
    if ((intptr_t)uvalue7 < (intptr_t)_param_5) {
      _param_5 = uvalue7;
    }
  }
  else {
    _param_5 = 1;
  }
  arg1 = (void *)0x0;
  uvalue6 = _param_5;
  if (0 < (intptr_t)_param_5) {
    value4 = DAT_0057c670;
    value14 = 0;
    do {
      if (arg6 == 1) {
        if (flag2 == 1) {
switchD_00512107_caseD_1:
          value9 = *(int *)(value4 + 0xa8);
          goto LAB_0051215a;
        }
        if (flag2 == 2) goto switchD_00512107_caseD_2;
        if (flag2 == 6) goto switchD_00512107_caseD_6;
      }
      else if (arg6 == 2) {
        switch(flag2) {
        case 1:
          goto switchD_00512107_caseD_1;
        case 2:
switchD_00512107_caseD_2:
          value9 = *(int *)(value4 + 0x1cc);
          break;
        case 3:
          value9 = *(int *)(value4 + 0x100);
          break;
        default:
          goto switchD_00512107_caseD_4;
        case 6:
switchD_00512107_caseD_6:
          value9 = *(int *)(value4 + 0x1e8);
        }
LAB_0051215a:
        aiStack_14[value14] = value9;
      }
      else if (arg6 == 3) {
        switch(flag2) {
        case 1:
          goto switchD_00512107_caseD_1;
        case 2:
          goto switchD_00512107_caseD_2;
        case 3:
          value9 = *(int *)(value4 + 0x108);
          goto LAB_0051215a;
        case 6:
          goto switchD_00512107_caseD_6;
        }
      }
      else {
        ptr13 = (int *)0x0;
        uvalue3 = Random_RangeFast(0,uvalue7 - 1);
        value4 = IDMap_Lookup(this_00,uvalue3,ptr13);
        aiStack_14[value14] = value4;
        value4 = DAT_0057c670;
      }
switchD_00512107_caseD_4:
      value9 = value14 + 1;
      arg1 = (void *)((float)*(double *)(aiStack_14[value14] + 0xc0) + (float)(intptr_t)(arg1));
      local_20[value14] = (float)*(double *)(aiStack_14[value14] + 0xc0);
      value14 = value9;
    } while (value9 < (intptr_t)_param_5);
    if (0 < (intptr_t)_param_5) {
      fptr5 = local_20;
      uvalue7 = _param_5;
      do {
        uvalue7 = uvalue7 - 1;
        *fptr5 = (*fptr5 * 100.0) / (float)(intptr_t)(arg1);
        fptr5 = fptr5 + 1;
      } while (uvalue7 != 0);
    }
  }
  while (uvalue6 = uvalue6 - 1, 0 < (intptr_t)uvalue6) {
    value4 = 0;
    if (0 < (intptr_t)uvalue6) {
      do {
        if (local_20[value4] < local_20[value4 + 1]) {
          fVar1 = local_20[value4];
          local_20[value4] = local_20[value4 + 1];
          local_20[value4 + 1] = fVar1;
        }
        value14 = aiStack_14[value4];
        if (*(double *)(aiStack_14[value4 + 1] + 0xc0) < *(double *)(value14 + 0xc0)) {
          aiStack_14[value4] = aiStack_14[value4 + 1];
          aiStack_14[value4 + 1] = value14;
        }
        value4 = value4 + 1;
      } while (value4 < (intptr_t)uvalue6);
    }
  }
  arg6 = 0;
  if (0 < (intptr_t)_param_5) {
    fptr5 = (float *)((intptr_t)self + (uint32_t)flag2 * 4 + 0x314);
    do {
      if ((arg2 == 2) || ((3 < (intptr_t)arg2 && ((intptr_t)arg2 < 7)))) {
        value4 = aiStack_14[arg6];
        flag2 = Game_GetMaxIndex4(value4);
      }
      else {
        value4 = aiStack_14[arg6];
        flag2 = Map_PickRandomExitDirection(value4);
      }
      do {
        while( true ) {
          lvalue11 = __ftol();
          value14 = (intptr_t)lvalue11;
          if (value14 == 0) break;
          if (value14 < 4) {
            if (value14 == 1) {
              value14 = 1;
              uvalue7 = 1;
              uvalue6 = 0xd;
              uvalue8 = *(uint32_t *)(*(int *)(DAT_0057c670 + 0xa0) + 0x18);
            }
            else {
              if (value14 == 2) {
                uvalue8 = *(uint32_t *)(*(int *)(DAT_0057c670 + 0xa0) + 0x18);
              }
              else {
                if (value14 != 3) goto LAB_00512387;
                fVar10 = Recipe_StreamConstruct
                                   (self,*(uint32_t *)(*(int *)(DAT_0057c670 + 0xa0) + 0x18),0xd,
                                    value4,1,flag2,1);
                *fptr5 = (float)((double)*fptr5 - fVar10);
                uvalue8 = *(uint32_t *)(*(int *)(DAT_0057c670 + 0xa0) + 0x18);
              }
              value14 = 2;
              uvalue7 = Random_RangeFast(1,0x20);
              uvalue6 = Random_RangeFast(5,0xc);
            }
            fVar10 = Recipe_StreamConstruct(self,uvalue8,uvalue6,value4,uvalue7,flag2,value14);
            *fptr5 = (float)((double)*fptr5 - fVar10);
            goto LAB_00512387;
          }
          value9 = 4;
          uvalue8 = *(uint32_t *)(*(int *)(DAT_0057c670 + 0xa0) + 0x18);
          flag12 = flag2;
          uvalue7 = Random_RangeFast(1,0x20);
          value14 = value4;
          uvalue6 = Random_RangeFast(4,10);
          fVar10 = Recipe_StreamConstruct(self,uvalue8,uvalue6,value14,uvalue7,flag12,value9);
          *fptr5 = (float)((double)*fptr5 - fVar10);
        }
        flag2 = flag2 + 1;
      } while (flag2 < 4);
LAB_00512387:
      arg6 = arg6 + 1;
    } while (arg6 < (intptr_t)_param_5);
  }
  if (this_00 != (uint32_t *)0x0) {
    (**(code **)*this_00)(1);
  }
  return;
}
