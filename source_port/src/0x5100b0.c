// Stats_SumMaskedMapFloats: ported from Pizza Connection 2 at 0x5100b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5100b0
#include "pc2_port.h"

double __thiscall Stats_SumMaskedMapFloats(int arg1,int arg2,int arg3,int arg4)

{
  int value1;
  int value2;
  int value3;
  int *ptr4;
  int value5;
  int value6;
  float local_2c;
  int local_20 [8];
  
  local_2c = 0.0;
  if (*(int *)(arg1 + 0x304) == 0) {
    return (double)0.0;
  }
  value1 = *(int *)(*(int *)(arg1 + 0x304) + 0x14);
  if (arg3 == 0) {
    value6 = 0;
    if (0 < value1) {
      do {
        value2 = IDMap_Lookup(*(void **)(arg1 + 0x304),value6,(int *)0x0);
        if (((*(int *)(value2 + 0x10) == arg2) || (arg2 == -1)) &&
           ((arg4 == -1 || (*(int *)(value2 + 0x14) == arg4)))) {
          local_2c = local_2c + *(float *)(value2 + 4);
        }
        value6 = value6 + 1;
      } while (value6 < value1);
      return (double)local_2c;
    }
  }
  else {
    value2 = 0;
    value6 = 0;
    ptr4 = local_20;
    do {
      if (*(char *)(value6 + arg3) == '\x01') {
        *ptr4 = value6;
        value2 = value2 + 1;
        ptr4 = ptr4 + 1;
      }
      value6 = value6 + 1;
    } while (value6 < 8);
    value6 = 0;
    if (0 < value1) {
      do {
        value3 = IDMap_Lookup(*(void **)(arg1 + 0x304),value6,(int *)0x0);
        if (((*(int *)(value3 + 0x10) == arg2) || (arg2 == -1)) && (0 < value2)) {
          ptr4 = local_20;
          value5 = value2;
          do {
            if ((*ptr4 == *(int *)(value3 + 0x18)) &&
               ((arg4 == -1 || (*(int *)(value3 + 0x14) == arg4)))) {
              local_2c = local_2c + *(float *)(value3 + 4);
            }
            ptr4 = ptr4 + 1;
            value5 = value5 + -1;
          } while (value5 != 0);
        }
        value6 = value6 + 1;
      } while (value6 < value1);
    }
  }
  return (double)local_2c;
}
