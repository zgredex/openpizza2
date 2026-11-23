// Character_Construct: ported from Pizza Connection 2 at 0x4d3730.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d3730
#include "pc2_port.h"


uint32_t * __thiscall Character_Construct(void *self,int arg1,int arg2)

{
  uint32_t uvalue1;
  void *pvVar2;
  uint32_t *uptr3;
  int value4;
  int value5;
  int *ptr6;
  int64_t lvalue7;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558db6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(uint8_t ***)self = &PTR_Character_Delete_0055c4fc;
  *(uint32_t *)((intptr_t)self + 0x814) = 0xffffffff;
  *(uint32_t *)((intptr_t)self + 0x818) = 0xffffffff;
  *(uint32_t *)((intptr_t)self + 0x81c) = 0xffffffff;
  *(uint32_t *)((intptr_t)self + 0x820) = 0xffffffff;
  uvalue1 = Random_RangeFast(0x1e,0x46);
  *(uint32_t *)((intptr_t)self + 4) = uvalue1;
  uvalue1 = Random_RangeFast(0x1e,0x46);
  *(uint32_t *)((intptr_t)self + 8) = uvalue1;
  uvalue1 = Random_RangeFast(0x1e,0x46);
  *(uint32_t *)((intptr_t)self + 0x10) = uvalue1;
  uvalue1 = Random_RangeFast(0x1e,0x46);
  *(uint32_t *)((intptr_t)self + 0xc) = uvalue1;
  uvalue1 = Random_RangeFast(0x12,0x3c);
  *(uint32_t *)((intptr_t)self + 0x38) = uvalue1;
  *(uint8_t *)((intptr_t)self + 0x824) = (uint8_t)arg2;
  *(uint32_t *)((intptr_t)self + 0x40) = 0;
  *(uint8_t *)((intptr_t)self + 0x825) = 2;
  *(uint32_t *)((intptr_t)self + 0x14) = 0;
  *(uint32_t *)((intptr_t)self + 0x18) = 0;
  *(uint32_t *)((intptr_t)self + 0x1c) = 0;
  *(uint32_t *)((intptr_t)self + 0x20) = 0;
  ptr6 = (int *)((intptr_t)self + 0x44);
  for (value5 = 500; value5 != 0; value5 = value5 + -1) {
    *ptr6 = 0;
    ptr6 = ptr6 + 1;
  }
  value5 = Rating_GetComposite((intptr_t)self);
  *(int *)((intptr_t)self + 0x44) = value5;
  value5 = Rating_ClampAdjusted((intptr_t)self);
  *(int *)((intptr_t)self + 0x1d4) = value5;
  value5 = Rating_AdjustA((intptr_t)self);
  *(int *)((intptr_t)self + 0x364) = value5;
  *(uint32_t *)((intptr_t)self + 0x4f4) = *(uint32_t *)((intptr_t)self + 0xc);
  value5 = Rating_AdjustB((intptr_t)self);
  *(int *)((intptr_t)self + 0x684) = value5;
  if (arg1 == -1) goto LAB_004d38e4;
  if (arg2 == 3) {
    pvVar2 = operator_new(0x16c);
    local_4 = 0;
    if (pvVar2 == (void *)0x0) {
LAB_004d3889:
      uptr3 = (uint32_t *)0x0;
    }
    else {
      uptr3 = Object_Construct(pvVar2,0x10,arg1,0,0,3);
    }
  }
  else {
    pvVar2 = operator_new(0x16c);
    local_4 = 1;
    if (pvVar2 == (void *)0x0) goto LAB_004d3889;
    value5 = 0;
    uvalue1 = _rand();
    uptr3 = Object_Construct(pvVar2,0x10,arg1,uvalue1 & 1,value5,arg2);
  }
  local_4 = 0xffffffff;
  IDMap_GetRandomName(DAT_0057ba10,uptr3[9],(char *)(uptr3 + 1));
  value5 = Game_AddObjectToRegistry(DAT_0057c670,uptr3);
  Employee_ApplySkillMultipliers(self,uptr3[9]);
  value4 = List_Add((void *)((intptr_t)DAT_0057c670 + 0x20),self);
  *(int *)((intptr_t)self + 0x818) = arg1;
  *(int *)((intptr_t)self + 0x814) = value5;
  uptr3[0x14] = value4;
LAB_004d38e4:
  lvalue7 = Rating_GetCompositeTruncated((intptr_t)self);
  *(int *)((intptr_t)self + 0x3c) = (intptr_t)lvalue7;
  ExceptionList = local_c;
  return self;
}
