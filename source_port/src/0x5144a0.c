// Stats_GetAverageRecordValue: ported from Pizza Connection 2 at 0x5144a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5144a0
#include "pc2_port.h"

int __fastcall Stats_GetAverageRecordValue(int arg1)

{
  int value1;
  int value2;
  int value3;
  int value4;
  
  value1 = *(int *)(arg1 + 0x58);
  value4 = 0;
  value3 = 0;
  if (0 < value1) {
    do {
      value2 = IDMap_Lookup((void *)(arg1 + 0x44),value3,(int *)0x0);
      value4 = value4 + *(int *)(value2 + 4);
      value3 = value3 + 1;
    } while (value3 < value1);
  }
  if (value1 == 0) {
    return 0;
  }
  return (value4 / 10) / value1;
}
