// Record_GetFlag3E48: ported from Pizza Connection 2 at 0x4d3530.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d3530
#include "pc2_port.h"

uint8_t __fastcall Record_GetFlag3E48(int arg1)

{
  int *ptr1;
  int value2;
  
  ptr1 = *(int **)(arg1 + 8);
  if (ptr1 != (int *)0x0) {
    value2 = *ptr1;
    if ((-1 < value2) && (value2 < *(int *)(ptr1[0x16] + 0x48))) {
      return *(uint8_t *)(*(int *)(ptr1[0x16] + 0x4c) + 0x3e + value2 * 0x48);
    }
  }
  return 0;
}
