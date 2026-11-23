// City_GetTopProductCategory: ported from Pizza Connection 2 at 0x4e2b70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e2b70
#include "pc2_port.h"


int __fastcall City_GetTopProductCategory(int arg1)

{
  int value1;
  int *ptr2;
  int value3;
  int *ptr4;
  uint32_t *uptr5;
  int local_1c [7];
  
  value1 = 0;
  uptr5 = &DAT_0057dfc0;
  for (value3 = 7; value3 != 0; value3 = value3 + -1) {
    *uptr5 = 0;
    uptr5 = uptr5 + 1;
  }
  DAT_0057dfc0 = 0xffffffff;
  ptr2 = local_1c;
  do {
    *ptr2 = value1;
    value1 = value1 + 1;
    ptr2 = ptr2 + 1;
  } while (value1 < 7);
  value1 = 0;
  if (0 < *(int *)(arg1 + 0x124)) {
    do {
      value3 = IDMap_Lookup((void *)(arg1 + 0x110),value1,(int *)0x0);
      ptr4 = &DAT_0057dfc4;
      ptr2 = (int *)(value3 + 0x1c0);
      do {
        value3 = *ptr2;
        ptr2 = ptr2 + 1;
        *ptr4 = *ptr4 + value3;
        ptr4 = ptr4 + 1;
      } while ((intptr_t)ptr4 < 0x57dfdc);
      value1 = value1 + 1;
    } while (value1 < *(int *)(arg1 + 0x124));
  }
  CRT_QSort(local_1c,(uint32_t *)0x7,4,&LAB_004e2c10);
  return local_1c[0];
}
