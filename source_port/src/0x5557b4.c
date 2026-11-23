// FUN_005557b4: ported from Pizza Connection 2 at 0x5557b4.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5557b4
#include "pc2_port.h"

void __cdecl FUN_005557b4(int arg1,int arg2)

{
  int value1;
  int value2;
  uint32_t *uptr3;
  
  uptr3 = (uint32_t *)(arg1 + (arg2 / 0x20) * 4);
  value1 = FUN_00556bdd(*uptr3,1 << (0x1fU - (char)(arg2 % 0x20) & 0x1f),uptr3);
  value2 = arg2 / 0x20 + -1;
  if (-1 < value2) {
    uptr3 = (uint32_t *)(arg1 + value2 * 4);
    do {
      if (value1 == 0) {
        return;
      }
      value1 = FUN_00556bdd(*uptr3,1,uptr3);
      value2 = value2 + -1;
      uptr3 = uptr3 + -1;
    } while (-1 < value2);
  }
  return;
}
