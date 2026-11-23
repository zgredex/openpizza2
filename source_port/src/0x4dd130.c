// Map_CollectBillboardDistances: ported from Pizza Connection 2 at 0x4dd130.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dd130
#include "pc2_port.h"


uint32_t * __thiscall Map_CollectBillboardDistances(void *self,int arg1)

{
  int value1;
  int *ptr2;
  void *pvVar3;
  int value4;
  int64_t lvalue5;
  uint32_t *local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055926b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_10 = operator_new(0x1c);
  value4 = 0;
  local_4 = 0;
  if (local_10 == (void *)0x0) {
    local_24 = (uint32_t *)0x0;
  }
  else {
    local_24 = List_Construct(local_10,0);
  }
  local_4 = 0xffffffff;
  UI_GetRecordCenteredRect
            (*(void **)((intptr_t)self + 0xfa8),*(int *)(arg1 + 0x24),&local_20,&local_18);
  pvVar3 = *(void **)((intptr_t)self + 0xfc0);
  local_10 = pvVar3;
  if ((intptr_t)pvVar3 < 1) {
    ExceptionList = local_c;
    return local_24;
  }
  do {
    value1 = IDMap_Lookup((void *)((intptr_t)self + 0xfac),value4,(int *)0x0);
    if (*(int *)(value1 + 4) == 0x1b) {
      ptr2 = operator_new(0xc);
      *ptr2 = value4;
      UI_GetRecordCenteredRect
                (*(void **)((intptr_t)self + 0xfa8),*(int *)(value1 + 0x24),&local_1c,&local_14);
      lvalue5 = __ftol();
      ptr2[1] = (intptr_t)lvalue5;
      List_Add(local_24,ptr2);
      pvVar3 = local_10;
    }
    value4 = value4 + 1;
  } while (value4 < (intptr_t)pvVar3);
  ExceptionList = local_c;
  return local_24;
}
