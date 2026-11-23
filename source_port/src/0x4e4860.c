// Game_SetBuildingDesc: ported from Pizza Connection 2 at 0x4e4860.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e4860
#include "pc2_port.h"

void __thiscall
Game_SetBuildingDesc
          (void *self,char *arg1,uint8_t arg2,uint32_t arg3,uint32_t arg4,
          uint32_t arg5,uint32_t arg6,uint32_t arg7,uint32_t arg8,
          uint8_t arg9,uint8_t arg10,uint8_t arg11,uint8_t arg12,
          uint8_t arg13,uint8_t arg14)

{
  char cVar1;
  uint32_t uvalue2;
  uint32_t uvalue3;
  char *cptr4;
  char *cptr5;
  
  uvalue2 = 0xffffffff;
  do {
    cptr4 = arg1;
    if (uvalue2 == 0) break;
    uvalue2 = uvalue2 - 1;
    cptr4 = arg1 + 1;
    cVar1 = *arg1;
    arg1 = cptr4;
  } while (cVar1 != '\0');
  uvalue2 = ~uvalue2;
  cptr4 = cptr4 + -uvalue2;
  cptr5 = (char *)((intptr_t)self + 0x88);
  for (uvalue3 = uvalue2 >> 2; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
    *(uint32_t *)cptr5 = *(uint32_t *)cptr4;
    cptr4 = cptr4 + 4;
    cptr5 = cptr5 + 4;
  }
  for (uvalue2 = uvalue2 & 3; uvalue2 != 0; uvalue2 = uvalue2 - 1) {
    *cptr5 = *cptr4;
    cptr4 = cptr4 + 1;
    cptr5 = cptr5 + 1;
  }
  *(uint32_t *)((intptr_t)self + 0xac) = arg3;
  *(uint8_t *)((intptr_t)self + 0xa8) = arg2;
  *(uint32_t *)((intptr_t)self + 0xb4) = arg5;
  *(uint32_t *)((intptr_t)self + 0xb0) = arg4;
  *(uint32_t *)((intptr_t)self + 0xc0) = arg7;
  *(uint32_t *)((intptr_t)self + 0xb8) = arg6;
  *(uint8_t *)((intptr_t)self + 0xcc) = arg9;
  *(uint32_t *)((intptr_t)self + 0xc4) = arg8;
  *(uint8_t *)((intptr_t)self + 200) = arg11;
  *(uint8_t *)((intptr_t)self + 0xcd) = arg10;
  *(uint8_t *)((intptr_t)self + 0xc9) = arg12;
  *(uint8_t *)((intptr_t)self + 0xca) = arg13;
  *(uint8_t *)((intptr_t)self + 0xcb) = arg14;
  return;
}
