// Game_ComputeAreaAttraction: ported from Pizza Connection 2 at 0x4d8320.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d8320
#include "pc2_port.h"

int __thiscall Game_ComputeAreaAttraction(void *self,int arg1,int arg2)

{
  int value1;
  int *ptr2;
  int value3;
  int value4;
  int value5;
  int value6;
  int local_8;
  int local_4;
  
  value5 = 0;
  value4 = arg2 * arg2 * 4;
  local_8 = 0;
  arg2 = value4;
  UI_GetRecordCenteredRect(*(void **)((intptr_t)self + 0xfa8),*(int *)(arg1 + 0x24),&arg1,&local_4)
  ;
  value6 = *(int *)((intptr_t)self + 0xfc0);
  if (0 < value6) {
    do {
      value4 = IDMap_Lookup((void *)((intptr_t)self + 0xfac),value5,(int *)0x0);
      if (*(int *)(value4 + 0x48) != -1) {
        *(uint32_t *)(value4 + 0x98) = 0;
      }
      value5 = value5 + 1;
    } while (value5 < value6);
    value4 = arg2;
  }
  value5 = 0;
  value6 = *(int *)(DAT_0057c670 + 0x50);
  if (0 < value6) {
    do {
      value1 = IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),value5,(int *)0x0);
      if (*(int *)(value1 + 0xa0) != 0) {
        ptr2 = (int *)(value1 + 0xd4);
        value1 = 8;
        do {
          value3 = *ptr2;
          ptr2 = ptr2 + 1;
          *(int *)(value3 + 0x98) = *(int *)(value3 + 0x98) + 1;
          value1 = value1 + -1;
        } while (value1 != 0);
      }
      value5 = value5 + 1;
    } while (value5 < value6);
  }
  arg2 = *(int *)((intptr_t)self + 0xfc0);
  value6 = 0;
  if (0 < arg2) {
    do {
      value5 = IDMap_Lookup((void *)((intptr_t)self + 0xfac),value6,(int *)0x0);
      if (*(int *)(value5 + 0x48) != -1) {
        value1 = Array_GetRecord28(*(void **)((intptr_t)self + 0xfa8),1,*(int *)(value5 + 0x54));
        value3 = *(int *)(value1 + 0xc) - arg1;
        value1 = *(int *)(value1 + 0x10) - local_4;
        if (value3 * value3 + value1 * value1 * 4 < value4) {
          if (*(int *)(value5 + 4) == 0x20) {
            local_8 = local_8 + (*(int *)((intptr_t)self + 0x48) >> 3);
          }
          else {
            local_8 = local_8 + *(int *)(value5 + 0x98);
          }
        }
      }
      value6 = value6 + 1;
    } while (value6 < arg2);
  }
  return local_8;
}
