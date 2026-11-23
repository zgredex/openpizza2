// Game_ComputeRecordMapPercent: ported from Pizza Connection 2 at 0x4781e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4781e0
#include "pc2_port.h"

int __fastcall Game_ComputeRecordMapPercent(int arg1)

{
  int value1;
  int *ptr2;
  int value3;
  int value4;
  
  value1 = *(int *)(arg1 + 0x19ac);
  value4 = 0;
  value3 = 0;
  if (0 < value1) {
    do {
      ptr2 = (int *)IDMap_Lookup((void *)(arg1 + 0x1998),value3,(int *)0x0);
      if (ptr2[7] != 0) {
        value4 = value4 + *ptr2;
      }
      value3 = value3 + 1;
    } while (value3 < value1);
  }
  if (value1 == 0) {
    return 0;
  }
  return (value4 * 100 + 199999) / (value1 * 200000);
}
