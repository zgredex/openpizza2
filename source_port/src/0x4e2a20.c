// Game_GetMostCommonTypeIndex: ported from Pizza Connection 2 at 0x4e2a20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e2a20
#include "pc2_port.h"

int __fastcall Game_GetMostCommonTypeIndex(int arg1)

{
  int value1;
  int value2;
  int value3;
  int value4;
  int *ptr5;
  int local_14 [5];
  
  value2 = *(int *)(arg1 + 0x194);
  value3 = -1;
  if (value2 == 0) {
    return -1;
  }
  value4 = 0;
  if (0 < value2) {
    do {
      value1 = IDMap_Lookup((void *)(arg1 + 0x180),value4,(int *)0x0);
      value1 = *(int *)(value1 + 0x30);
      if (-1 < value1) {
        local_14[value1] = local_14[value1] + 1;
      }
      value4 = value4 + 1;
    } while (value4 < value2);
  }
  value2 = -1;
  value4 = 0;
  ptr5 = local_14;
  do {
    if (value3 < *ptr5) {
      value2 = value4;
      value3 = *ptr5;
    }
    value4 = value4 + 1;
    ptr5 = ptr5 + 1;
  } while (value4 < 5);
  return value2;
}
