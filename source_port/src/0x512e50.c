// Screen_ScoreColorHistogram: ported from Pizza Connection 2 at 0x512e50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x512e50
#include "pc2_port.h"

void __fastcall Screen_ScoreColorHistogram(int arg1)

{
  int *ptr1;
  int *ptr2;
  int value3;
  int value4;
  int64_t lvalue5;
  int64_t lvalue6;
  
  value4 = 0;
  ptr2 = (int *)(arg1 + 0x1e0);
  *(uint32_t *)(arg1 + 0x244) = 100;
  value3 = 0x18;
  ptr1 = ptr2;
  do {
    if (*ptr1 < 1) {
      value4 = value4 + 1;
    }
    ptr1 = ptr1 + 1;
    value3 = value3 + -1;
  } while (value3 != 0);
  lvalue5 = __ftol();
  lvalue6 = __ftol();
  value3 = 0x18;
  do {
    if ((*ptr2 < (intptr_t)lvalue5) || ((intptr_t)lvalue6 < *ptr2)) {
      *(int *)(arg1 + 0x244) = *(int *)(arg1 + 0x244) + -10;
    }
    ptr2 = ptr2 + 1;
    value3 = value3 + -1;
  } while (value3 != 0);
  value3 = *(int *)(arg1 + 0x244) + value4 * -0x14;
  *(int *)(arg1 + 0x244) = value3;
  if (value3 < 0) {
    *(uint32_t *)(arg1 + 0x244) = 0;
  }
  return;
}
