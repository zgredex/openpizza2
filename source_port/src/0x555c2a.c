// FUN_00555c2a: ported from Pizza Connection 2 at 0x555c2a.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x555c2a
#include "pc2_port.h"

void __cdecl FUN_00555c2a(uint32_t *arg1,uint32_t *arg2)

{
  uint16_t uvalue1;
  uint32_t uvalue2;
  uint32_t uvalue3;
  int value4;
  uint32_t local_8;
  
  uvalue1 = *(uint16_t *)((intptr_t)arg2 + 6);
  uvalue3 = (uvalue1 & 0x7ff0) >> 4;
  uvalue2 = *arg2;
  local_8 = 0x80000000;
  if (uvalue3 == 0) {
    if (((arg2[1] & 0xfffff) == 0) && (uvalue2 == 0)) {
      arg1[1] = 0;
      *arg1 = 0;
      *(uint16_t *)(arg1 + 2) = 0;
      return;
    }
    value4 = 0x3c01;
    local_8 = 0;
  }
  else if (uvalue3 == 0x7ff) {
    value4 = 0x7fff;
  }
  else {
    value4 = uvalue3 + 0x3c00;
  }
  local_8 = uvalue2 >> 0x15 | (arg2[1] & 0xfffff) << 0xb | local_8;
  arg1[1] = local_8;
  *arg1 = uvalue2 << 0xb;
  while ((local_8 & 0x80000000) == 0) {
    local_8 = *arg1 >> 0x1f | local_8 * 2;
    *arg1 = *arg1 * 2;
    arg1[1] = local_8;
    value4 = value4 + 0xffff;
  }
  *(uint16_t *)(arg1 + 2) = uvalue1 & 0x8000 | (uint16_t)value4;
  return;
}
