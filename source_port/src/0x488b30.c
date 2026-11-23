// Ingredient_CollectByCategory: ported from Pizza Connection 2 at 0x488b30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x488b30
#include "pc2_port.h"


uint32_t * __thiscall Ingredient_CollectByCategory(void *self,char arg1)

{
  void *this_00;
  uint32_t *this_01;
  int *ptr1;
  int value2;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005582cb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = operator_new(0x1c);
  this_01 = (uint32_t *)0x0;
  local_4 = 0;
  if (this_00 != (void *)0x0) {
    this_01 = List_Construct(this_00,0);
  }
  local_4 = 0xffffffff;
  ptr1 = (int *)((intptr_t)self + 0xa8);
  value2 = 0x56;
  do {
    if (*(char *)(*ptr1 + 0xa8) == arg1) {
      List_Add(this_01,*ptr1);
    }
    ptr1 = ptr1 + 1;
    value2 = value2 + -1;
  } while (value2 != 0);
  ExceptionList = local_c;
  return this_01;
}
