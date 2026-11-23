// Game_CountRecordsWithFlag16F4: ported from Pizza Connection 2 at 0x4de710.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4de710
#include "pc2_port.h"

int __fastcall Game_CountRecordsWithFlag16F4(int arg1)

{
  int value1;
  int value2;
  int value3;
  
  value2 = 0;
  value3 = 0;
  if (*(int *)(arg1 + 0x15c) < 1) {
    return 0;
  }
  do {
    value1 = IDMap_Lookup((void *)(arg1 + 0x148),value3,(int *)0x0);
    if (*(char *)(value1 + 0x16f4) != '\0') {
      value2 = value2 + 1;
    }
    value3 = value3 + 1;
  } while (value3 < *(int *)(arg1 + 0x15c));
  return value2;
}
