// Stats_GetMinMapField10: ported from Pizza Connection 2 at 0x5102f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5102f0
#include "pc2_port.h"

int __fastcall Stats_GetMinMapField10(int arg1)

{
  int value1;
  int value2;
  int value3;
  int value4;
  
  value4 = 99999999;
  if (*(int *)(arg1 + 0x304) == 0) {
    return 0;
  }
  value1 = *(int *)(*(int *)(arg1 + 0x304) + 0x14);
  value3 = 0;
  if (0 < value1) {
    do {
      value2 = IDMap_Lookup(*(void **)(arg1 + 0x304),value3,(int *)0x0);
      if (*(int *)(value2 + 0x10) < value4) {
        value4 = *(int *)(value2 + 0x10);
      }
      value3 = value3 + 1;
    } while (value3 < value1);
  }
  return value4;
}
