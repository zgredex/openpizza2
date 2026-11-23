// Recipe_CollectCategoryCandidates: ported from Pizza Connection 2 at 0x511e60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x511e60
#include "pc2_port.h"


uint32_t * Recipe_CollectCategoryCandidates(void *arg1,uint32_t arg2,char arg3)

{
  int value1;
  int value2;
  uint32_t *self;
  void *this_00;
  int value3;
  int *ptr4;
  int value5;
  uint32_t *local_2cc;
  int local_2c8;
  int local_2c4;
  uint32_t local_2c0;
  int local_2bc [172];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a4be;
  local_c = ExceptionList;
  value5 = 0;
  ExceptionList = &local_c;
  self = Ingredient_CollectByCategory(DAT_0057c670,arg3);
  this_00 = operator_new(0x1c);
  local_4 = 0;
  if (this_00 == (void *)0x0) {
    local_2cc = (uint32_t *)0x0;
  }
  else {
    local_2cc = List_Construct(this_00,0);
  }
  local_4 = 0xffffffff;
  if (0 < (intptr_t)self[5]) {
    ptr4 = local_2bc + 1;
    do {
      value3 = IDMap_Lookup(self,value5,(int *)0x0);
      ptr4[-1] = value3;
      value3 = Market_ComputeValueAdjustment(arg1,'\x01',arg2,value3,&local_2c0,&local_2c4);
      *ptr4 = value3;
      value5 = value5 + 1;
      ptr4 = ptr4 + 2;
    } while (value5 < (intptr_t)self[5]);
  }
  for (value3 = value5 + -2; 0 < value3; value3 = value3 + -1) {
    ptr4 = local_2bc;
    local_2c8 = value3;
    do {
      if (ptr4[1] < ptr4[3]) {
        value1 = *ptr4;
        value2 = ptr4[1];
        *ptr4 = ptr4[2];
        ptr4[1] = ptr4[3];
        ptr4[2] = value1;
        ptr4[3] = value2;
      }
      ptr4 = ptr4 + 2;
      local_2c8 = local_2c8 + -1;
    } while (local_2c8 != 0);
  }
  if (0 < value5) {
    ptr4 = local_2bc;
    do {
      List_Add(local_2cc,*ptr4);
      ptr4 = ptr4 + 2;
      value5 = value5 + -1;
    } while (value5 != 0);
  }
  if (self != (uint32_t *)0x0) {
    (**(code **)*self)(1);
  }
  ExceptionList = local_c;
  return local_2cc;
}
