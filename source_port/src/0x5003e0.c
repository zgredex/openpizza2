// Game_UpdateCompanyAccount: ported from Pizza Connection 2 at 0x5003e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5003e0
#include "pc2_port.h"

void __thiscall Game_UpdateCompanyAccount(void *self,int arg1)

{
  int *ptr1;
  int value2;
  double dVar3;
  int64_t lvalue4;
  
  value2 = *(int *)(arg1 + 0x4c);
  if (value2 != 0) {
    ptr1 = (int *)((intptr_t)self + value2 * 0x168 + 0x19c);
    value2 = *(int *)((intptr_t)self + value2 * 0x168 + 0x19c);
    if (0 < value2) {
      if (*(double *)(arg1 + 0x108) < 0.0) {
        dVar3 = (double)value2;
        if (1000.0 < dVar3) {
          dVar3 = 1000.0;
        }
        *(double *)(arg1 + 0x108) = dVar3 + *(double *)(arg1 + 0x108);
        lvalue4 = __ftol();
        *ptr1 = *ptr1 - (intptr_t)lvalue4;
        return;
      }
      *ptr1 = value2 + -0xfa;
      if (value2 + -0xfa < 0) {
        *ptr1 = 0;
      }
    }
  }
  return;
}
