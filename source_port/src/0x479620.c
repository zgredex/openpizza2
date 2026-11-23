// Game_ComputeCityScore: ported from Pizza Connection 2 at 0x479620.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x479620
#include "pc2_port.h"

void __thiscall Game_ComputeCityScore(void *self,int arg1,int arg2)

{
  short svalue1;
  short *psVar2;
  int value3;
  int *ptr4;
  int value5;
  int value6;
  int value7;
  int64_t lvalue8;
  int local_1c;
  int local_10;
  int local_c [3];
  
  value6 = arg1 / 3;
  value3 = 0;
  value5 = 0;
  local_1c = -1;
  value7 = 0;
  psVar2 = (short *)(arg2 + 4);
  arg2 = 0x50;
  do {
    ptr4 = local_c + value7;
    arg1 = 0x50;
    do {
      svalue1 = *psVar2;
      if ((svalue1 < -3) || ((-1 < svalue1 && (svalue1 != 9)))) {
        if (svalue1 != 0) {
          value3 = value3 + 1;
        }
        value5 = value5 + 1;
        if (value6 <= value5) {
          *ptr4 = value3;
          if (local_1c < value3) {
            local_1c = value3;
            local_10 = value7;
          }
          value7 = value7 + 1;
          ptr4 = ptr4 + 1;
          value3 = 0;
          value5 = 0;
        }
      }
      psVar2 = psVar2 + 4;
      arg1 = arg1 + -1;
    } while (arg1 != 0);
    arg2 = arg2 + -1;
  } while (arg2 != 0);
  ptr4 = (int *)((intptr_t)self + 0x185c);
  *ptr4 = 100;
  if (local_1c < 1) {
    *ptr4 = 0;
    Clamp_0_100(ptr4);
    return;
  }
  value6 = 0;
  do {
    if (value6 != local_10) {
      lvalue8 = __ftol();
      value3 = (intptr_t)((uint64_t)((int64_t)(100 - (intptr_t)lvalue8) * -0x66666667) >> 0x20);
      *ptr4 = *ptr4 + ((value3 >> 1) - (value3 >> 0x1f));
    }
    value6 = value6 + 1;
  } while (value6 < 3);
  Clamp_0_100(ptr4);
  return;
}
