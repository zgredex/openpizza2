// Game_AverageObjectField0C: ported from Pizza Connection 2 at 0x478250.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x478250
#include "pc2_port.h"

int __fastcall Game_AverageObjectField0C(int arg1)

{
  int value1;
  int *ptr2;
  int value3;
  int value4;
  
  value1 = *(int *)(arg1 + 0x1514);
  value4 = 0;
  value3 = 0;
  if (0 < value1) {
    do {
      ptr2 = (int *)IDMap_Lookup((void *)(arg1 + 0x1500),value3,(int *)0x0);
      value4 = value4 + *(int *)(*ptr2 + 0xc);
      value3 = value3 + 1;
    } while (value3 < value1);
  }
  if (value1 == 0) {
    return 0;
  }
  return value4 / value1;
}
