// Array_CountValid8: ported from Pizza Connection 2 at 0x4edbd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4edbd0
#include "pc2_port.h"

int Array_CountValid8(int arg1)

{
  int value1;
  short *psVar2;
  int value3;
  
  value1 = 0;
  psVar2 = (short *)(arg1 + 0x14);
  value3 = 8;
  do {
    if (*psVar2 != -1) {
      value1 = value1 + 1;
    }
    psVar2 = psVar2 + 1;
    value3 = value3 + -1;
  } while (value3 != 0);
  return value1;
}
