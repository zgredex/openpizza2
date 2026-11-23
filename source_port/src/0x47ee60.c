// Stats_GetAverageFlaggedValue: ported from Pizza Connection 2 at 0x47ee60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47ee60
#include "pc2_port.h"

int __fastcall Stats_GetAverageFlaggedValue(int arg1)

{
  int value1;
  int value2;
  int value3;
  int value4;
  int value5;
  
  value1 = *(int *)(arg1 + 0x19ac);
  value5 = 0;
  value3 = 0;
  value4 = 0;
  if (0 < value1) {
    do {
      value2 = IDMap_Lookup((void *)(arg1 + 0x1998),value4,(int *)0x0);
      if (*(int *)(value2 + 0x1c) != 0) {
        value5 = value5 + *(int *)(value2 + 4);
        value3 = value3 + 1;
      }
      value4 = value4 + 1;
    } while (value4 < value1);
    if (value3 != 0) {
      return (value5 / 10) / value3;
    }
  }
  return 0;
}
