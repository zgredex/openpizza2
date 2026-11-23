// Stats_AverageActiveCategories: ported from Pizza Connection 2 at 0x5104f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5104f0
#include "pc2_port.h"

double __thiscall Stats_AverageActiveCategories(void *arg1,int arg2)

{
  int value1;
  int value2;
  int *ptr3;
  int value4;
  int value5;
  int local_28;
  int local_20 [8];
  
  value5 = 0;
  value4 = 0;
  local_28 = 0;
  value1 = 0;
  ptr3 = local_20;
  do {
    if (*(char *)(value1 + arg2) == '\x01') {
      *ptr3 = value1;
      value4 = value4 + 1;
      ptr3 = ptr3 + 1;
    }
    value1 = value1 + 1;
  } while (value1 < 8);
  if (value4 == 0) {
    return (double)0.0;
  }
  if (0 < value4) {
    ptr3 = local_20;
    value1 = value4;
    do {
      value2 = Game_MapInputIndex(arg1,*ptr3);
      value5 = value5 + value2;
      ptr3 = ptr3 + 1;
      value1 = value1 + -1;
    } while (value1 != 0);
    local_28 = value5;
  }
  return (double)local_28 / (double)value4;
}
