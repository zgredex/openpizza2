// Game_CountRecordsWithoutFlag: ported from Pizza Connection 2 at 0x510580.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x510580
#include "pc2_port.h"

int __fastcall Game_CountRecordsWithoutFlag(int arg1)

{
  int value1;
  int value2;
  int value3;
  
  value2 = 0;
  value3 = 0;
  if (*(int *)(arg1 + 0x5c) < 1) {
    return 0;
  }
  do {
    value1 = IDMap_Lookup((void *)(arg1 + 0x48),value3,(int *)0x0);
    if (*(char *)(value1 + 0x11) == '\0') {
      value2 = value2 + 1;
    }
    value3 = value3 + 1;
  } while (value3 < *(int *)(arg1 + 0x5c));
  return value2;
}
