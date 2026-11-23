// FUN_0055580a: ported from Pizza Connection 2 at 0x55580a.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55580a
#include "pc2_port.h"

uint32_t __cdecl FUN_0055580a(int arg1,int arg2)

{
  uint32_t *uptr1;
  int value2;
  uint8_t flag3;
  int value4;
  uint32_t *uptr5;
  uint32_t local_8;
  
  local_8 = 0;
  uptr1 = (uint32_t *)(arg1 + (arg2 / 0x20) * 4);
  flag3 = 0x1f - (char)(arg2 % 0x20);
  if (((*uptr1 & 1 << (flag3 & 0x1f)) != 0) &&
     (value2 = FUN_0055576b(arg1,arg2 + 1), value2 == 0)) {
    local_8 = FUN_005557b4(arg1,arg2 + -1);
  }
  *uptr1 = *uptr1 & -1 << (flag3 & 0x1f);
  value2 = arg2 / 0x20 + 1;
  if (value2 < 3) {
    uptr5 = (uint32_t *)(arg1 + value2 * 4);
    for (value4 = 3 - value2; value4 != 0; value4 = value4 + -1) {
      *uptr5 = 0;
      uptr5 = uptr5 + 1;
    }
  }
  return local_8;
}
