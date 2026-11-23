// FUN_005558d8: ported from Pizza Connection 2 at 0x5558d8.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5558d8
#include "pc2_port.h"

void __cdecl FUN_005558d8(uint32_t *arg1,uint32_t arg2)

{
  uint32_t uvalue1;
  int value2;
  uint8_t flag3;
  int value4;
  int value5;
  uint32_t *uptr6;
  int local_8;
  
  local_8 = 3;
  value2 = (intptr_t)arg2 / 0x20;
  value5 = (intptr_t)arg2 % 0x20;
  arg2 = 0;
  flag3 = (uint8_t)value5;
  uptr6 = arg1;
  do {
    uvalue1 = *uptr6;
    *uptr6 = uvalue1 >> (flag3 & 0x1f) | arg2;
    uptr6 = uptr6 + 1;
    arg2 = (uvalue1 & ~(-1 << (flag3 & 0x1f))) << (0x20 - flag3 & 0x1f);
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  value5 = 2;
  value4 = 8;
  do {
    if (value5 < value2) {
      *(uint32_t *)(value4 + (intptr_t)arg1) = 0;
    }
    else {
      *(uint32_t *)(value4 + (intptr_t)arg1) = *(uint32_t *)(value4 + value2 * -4 + (intptr_t)arg1);
    }
    value5 = value5 + -1;
    value4 = value4 + -4;
  } while (-1 < value4);
  return;
}
