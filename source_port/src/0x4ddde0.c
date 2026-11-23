// Game_CountActiveCompanies: ported from Pizza Connection 2 at 0x4ddde0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ddde0
#include "pc2_port.h"

int __fastcall Game_CountActiveCompanies(int arg1)

{
  int value1;
  int value2;
  int value3;
  int local_4;
  
  value1 = *(int *)(arg1 + 0x124);
  value3 = 0;
  local_4 = 0;
  value2 = 0;
  if (0 < value1) {
    do {
      value2 = IDMap_Lookup((void *)(arg1 + 0x110),value3,(int *)0x0);
      if (*(char *)(value2 + 0x1dc) == '\x01') {
        local_4 = local_4 + 1;
      }
      value3 = value3 + 1;
    } while (value3 < value1);
    value2 = local_4;
  }
  return value2;
}
