// Branch_ComputeWorkDuration: ported from Pizza Connection 2 at 0x47d340.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47d340
#include "pc2_port.h"

uint32_t __thiscall Branch_ComputeWorkDuration(void *self,int arg1)

{
  int value1;
  int *ptr2;
  uint32_t *this_00;
  int value3;
  int value4;
  int64_t lvalue5;
  int local_c;
  
  value3 = 0;
  value4 = 0;
  local_c = 0;
  if (0 < *(int *)((intptr_t)self + 0x1514)) {
    do {
      ptr2 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0x1500),value4,(int *)0x0);
      value1 = *ptr2;
      if ((*(char *)(value1 + 0x824) == '\0') && (value1 != arg1)) {
        Game_GetRecordByField814(value1);
      }
      value4 = value4 + 1;
    } while (value4 < *(int *)((intptr_t)self + 0x1514));
  }
  this_00 = Branch_CollectOrdersByCategory(self,5);
  if (0 < (intptr_t)this_00[5]) {
    do {
      value4 = IDMap_Lookup(this_00,value3,(int *)0x0);
      if (value4 != 0) {
        value4 = IDMap_Lookup((void *)(DAT_0057c670 + 0x74),*(int *)(value4 + 4),(int *)0x0);
        Product_ComputeFreshness(value4);
        local_c = local_c + 1;
      }
      value3 = value3 + 1;
    } while (value3 < (intptr_t)this_00[5]);
  }
  if (this_00 != (uint32_t *)0x0) {
    (**(code **)*this_00)(1);
  }
  if (local_c < 1) {
    return 0xb4;
  }
  Rating_GetComposite(arg1);
  lvalue5 = __ftol();
  return (intptr_t)lvalue5;
}
