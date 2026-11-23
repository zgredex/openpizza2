// Recipe_FindIngredientsByCategory: ported from Pizza Connection 2 at 0x512750.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x512750
#include "pc2_port.h"


uint32_t * __thiscall
Recipe_FindIngredientsByCategory(void *self,char arg1,char arg2,int *arg3)

{
  void *this_00;
  int value1;
  int value2;
  uint32_t *local_14;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a4db;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = operator_new(0x1c);
  value2 = 0;
  local_4 = 0;
  if (this_00 == (void *)0x0) {
    local_14 = (uint32_t *)0x0;
  }
  else {
    local_14 = List_Construct(this_00,0);
  }
  local_4 = 0xffffffff;
  *arg3 = 0;
  if (*(int *)((intptr_t)self + 0x5c) < 1) {
    ExceptionList = local_c;
    return local_14;
  }
  do {
    value1 = IDMap_Lookup((void *)((intptr_t)self + 0x48),value2,(int *)0x0);
    if ((*(char *)(value1 + 4) == arg1) && (*(char *)(value1 + 6) == arg2)) {
      *arg3 = *arg3 + 1;
      List_Add(local_14,value1);
    }
    value2 = value2 + 1;
  } while (value2 < *(int *)((intptr_t)self + 0x5c));
  ExceptionList = local_c;
  return local_14;
}
