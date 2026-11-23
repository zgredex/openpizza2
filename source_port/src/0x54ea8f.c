// CRT_QSort: ported from Pizza Connection 2 at 0x54ea8f.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54ea8f
#include "pc2_port.h"

void __cdecl CRT_QSort(int *arg1,uint32_t *arg2,uint32_t arg3,uint8_t *arg4)

{
  int *ptr1;
  uint32_t uvalue2;
  int *ptr3;
  int value4;
  int *ptr5;
  int *ptr6;
  uint32_t local_fc [30];
  int local_84 [30];
  int *local_c;
  int local_8;
  
  if ((arg2 < (uint32_t *)0x2) || (arg3 == 0)) {
    return;
  }
  local_8 = 0;
  value4 = (intptr_t)arg2 + -1;
  arg2 = local_fc;
  ptr5 = (int *)(value4 * arg3 + (intptr_t)arg1);
  ptr3 = arg1;
  arg1 = local_84;
LAB_0054eace:
  uvalue2 = (uint32_t)((intptr_t)ptr5 - (intptr_t)ptr3) / arg3 + 1;
  if (8 < uvalue2) {
    Mem_Swap((uint8_t *)((uvalue2 >> 1) * arg3 + (intptr_t)ptr3),(uint8_t *)ptr3,arg3);
    ptr6 = (int *)(arg3 + (intptr_t)ptr5);
    local_c = ptr3;
LAB_0054eb25:
    local_c = (int *)((intptr_t)local_c + arg3);
    if (local_c <= ptr5) goto code_r0x0054eb32;
    goto LAB_0054eb3d;
  }
  CRT_SelectionSort((uint8_t *)ptr3,(uint8_t *)ptr5,arg3,arg4);
  goto LAB_0054eaed;
code_r0x0054eb32:
  value4 = (*(code *)arg4)(local_c,ptr3);
  if (value4 < 1) goto LAB_0054eb25;
LAB_0054eb3d:
  do {
    ptr6 = (int *)((intptr_t)ptr6 - arg3);
    if (ptr6 <= ptr3) break;
    value4 = (*(code *)arg4)(ptr6,ptr3);
  } while (-1 < value4);
  if (local_c <= ptr6) {
    Mem_Swap((uint8_t *)local_c,(uint8_t *)ptr6,arg3);
    goto LAB_0054eb25;
  }
  Mem_Swap((uint8_t *)ptr3,(uint8_t *)ptr6,arg3);
  ptr1 = local_c;
  if ((intptr_t)((intptr_t)ptr6 + (-1 - (intptr_t)ptr3)) < (intptr_t)ptr5 - (intptr_t)local_c) {
    if (local_c < ptr5) {
      local_8 = local_8 + 1;
      *arg2 = local_c;
      *arg1 = (intptr_t)ptr5;
      arg1 = arg1 + 1;
      arg2 = arg2 + 1;
    }
    if ((int *)(arg3 + (intptr_t)ptr3) < ptr6) {
      ptr5 = (int *)((intptr_t)ptr6 - arg3);
      goto LAB_0054eace;
    }
  }
  else {
    if ((int *)((intptr_t)ptr3 + arg3) < ptr6) {
      local_8 = local_8 + 1;
      *arg2 = ptr3;
      *arg1 = (intptr_t)ptr6 - arg3;
      arg1 = arg1 + 1;
      arg2 = arg2 + 1;
    }
    if (ptr1 < ptr5) {
      ptr3 = ptr1;
      goto LAB_0054eace;
    }
  }
LAB_0054eaed:
  local_8 = local_8 + -1;
  arg2 = arg2 + -1;
  arg1 = arg1 + -1;
  if (local_8 < 0) {
    return;
  }
  ptr5 = (int *)*arg1;
  ptr3 = (int *)*arg2;
  goto LAB_0054eace;
}
