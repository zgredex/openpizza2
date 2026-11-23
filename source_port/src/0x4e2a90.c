// AI_GetTopActionIndices: ported from Pizza Connection 2 at 0x4e2a90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e2a90
#include "pc2_port.h"


void __thiscall AI_GetTopActionIndices(void *self,int *arg1,uint32_t *arg2)

{
  int value1;
  int value2;
  int *ptr3;
  int *ptr4;
  int local_2b0 [172];
  
  value1 = 0;
  ptr4 = local_2b0 + 1;
  do {
    ptr4[-1] = value1;
    *ptr4 = 0;
    value1 = value1 + 1;
    ptr4 = ptr4 + 2;
  } while (value1 < 0x56);
  value1 = 0;
  if (0 < *(int *)((intptr_t)self + 0x124)) {
    do {
      value2 = IDMap_Lookup((void *)((intptr_t)self + 0x110),value1,(int *)0x0);
      ptr4 = local_2b0 + 3;
      ptr3 = (int *)(value2 + 0x68);
      value2 = 0x55;
      do {
        if (0 < *ptr3) {
          *ptr4 = *ptr4 + 1;
        }
        ptr3 = ptr3 + 1;
        ptr4 = ptr4 + 2;
        value2 = value2 + -1;
      } while (value2 != 0);
      value1 = value1 + 1;
    } while (value1 < *(int *)((intptr_t)self + 0x124));
  }
  CRT_QSort(local_2b0,(uint32_t *)0x56,8,&LAB_004e2b40);
  *arg1 = local_2b0[0];
  *arg2 = local_2b0[2];
  return;
}
