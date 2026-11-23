// Company_CollectUnprofitableBranches: ported from Pizza Connection 2 at 0x4e1bc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e1bc0
#include "pc2_port.h"


uint32_t * __fastcall Company_CollectUnprofitableBranches(int arg1)

{
  int value1;
  int *ptr2;
  void *self;
  int value3;
  int *ptr4;
  int value5;
  int value6;
  int value7;
  int *ptr8;
  uint32_t *local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005594db;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  ptr2 = operator_new(*(int *)(arg1 + 0x124) * 8 + 0x50);
  self = operator_new(0x1c);
  value7 = 0;
  local_4 = 0;
  if (self == (void *)0x0) {
    local_10 = (uint32_t *)0x0;
  }
  else {
    local_10 = List_Construct(self,0);
  }
  local_4 = 0xffffffff;
  if (0 < *(int *)(arg1 + 0x124)) {
    value6 = 0;
    value5 = 0;
    if (0 < *(int *)(arg1 + 0x124)) {
      ptr8 = ptr2;
      do {
        *ptr8 = value7;
        value3 = IDMap_Lookup((void *)(arg1 + 0x110),value7,(int *)0x0);
        value3 = *(int *)(value3 + 0x30c);
        ptr8[1] = value3;
        value5 = value5 + value3;
        value6 = value6 + 1;
        ptr8 = ptr8 + 2;
        value7 = value7 + 1;
      } while (value7 < *(int *)(arg1 + 0x124));
    }
    value5 = value5 / *(int *)(arg1 + 0x124);
    if (0 < value5) {
      while (value6 = value6 + -1, 0 < value6) {
        value7 = value6;
        ptr8 = ptr2;
        do {
          ptr4 = ptr8 + 2;
          if (ptr8[3] < ptr8[1]) {
            value3 = *ptr8;
            value1 = ptr8[1];
            *ptr8 = *ptr4;
            ptr8[1] = ptr8[3];
            *ptr4 = value3;
            ptr8[3] = value1;
          }
          value7 = value7 + -1;
          ptr8 = ptr4;
        } while (value7 != 0);
      }
      value7 = 0;
      if (0 < *(int *)(arg1 + 0x124)) {
        ptr8 = ptr2;
        do {
          value6 = IDMap_Lookup((void *)(arg1 + 0x110),*ptr8,(int *)0x0);
          if (*(int *)(value6 + 0x30c) < value5 / 2) {
            List_Add(local_10,value6);
          }
          value7 = value7 + 1;
          ptr8 = ptr8 + 2;
        } while (value7 < *(int *)(arg1 + 0x124));
      }
    }
  }
  Mem_Free(ptr2);
  ExceptionList = local_c;
  return local_10;
}
