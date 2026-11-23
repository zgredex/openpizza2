// Rating_StoreClampedScores: ported from Pizza Connection 2 at 0x513270.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x513270
#include "pc2_port.h"

void __fastcall Rating_StoreClampedScores(int arg1)

{
  int *ptr1;
  int value2;
  int64_t lvalue3;
  
  ptr1 = (int *)(arg1 + 0x264);
  lvalue3 = __ftol();
  *ptr1 = (intptr_t)lvalue3;
  lvalue3 = __ftol();
  *(int *)(arg1 + 0x268) = (intptr_t)lvalue3;
  lvalue3 = __ftol();
  *(int *)(arg1 + 0x26c) = (intptr_t)lvalue3;
  lvalue3 = __ftol();
  *(int *)(arg1 + 0x270) = (intptr_t)lvalue3;
  lvalue3 = __ftol();
  *(int *)(arg1 + 0x274) = (intptr_t)lvalue3;
  lvalue3 = __ftol();
  *(int *)(arg1 + 0x278) = (intptr_t)lvalue3;
  lvalue3 = __ftol();
  *(int *)(arg1 + 0x27c) = (intptr_t)lvalue3;
  lvalue3 = __ftol();
  *(int *)(arg1 + 0x280) = (intptr_t)lvalue3;
  value2 = 8;
  do {
    if (*ptr1 < 0) {
      *ptr1 = 0;
    }
    if (100 < *ptr1) {
      *ptr1 = 100;
    }
    ptr1 = ptr1 + 1;
    value2 = value2 + -1;
  } while (value2 != 0);
  return;
}
