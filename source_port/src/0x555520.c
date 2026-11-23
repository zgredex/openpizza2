// __aulldiv: ported from Pizza Connection 2 at 0x555520.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x555520
#include "pc2_port.h"

/* Library Function - Single Match
    __aulldiv
   
   Library: Visual Studio */

uint64_t __aulldiv(uint32_t arg1,uint32_t arg2,uint32_t arg3,uint32_t arg4)

{
  uint64_t uvalue1;
  int64_t lvalue2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  int value5;
  uint32_t uvalue6;
  uint32_t uvalue7;
  uint32_t uvalue8;
  
  if (arg4 == 0) {
    uvalue4 = arg2 / arg3;
    value5 = (intptr_t)(((uint64_t)arg2 % (uint64_t)arg3 << 0x20 | (uint64_t)arg1) /
                 (uint64_t)arg3);
  }
  else {
    uvalue8 = arg1;
    uvalue6 = arg4;
    uvalue7 = arg2;
    uvalue4 = arg3;
    do {
      uvalue3 = uvalue6 & 1;
      uvalue6 = uvalue6 >> 1;
      uvalue4 = (uint32_t)(CONCAT14(uvalue3 != 0,uvalue4) >> 1);
      uvalue3 = uvalue7 & 1;
      uvalue7 = uvalue7 >> 1;
      uvalue8 = (uint32_t)(CONCAT14(uvalue3 != 0,uvalue8) >> 1);
    } while (uvalue6 != 0);
    uvalue1 = CONCAT44(uvalue7,uvalue8) / (uint64_t)uvalue4;
    value5 = (intptr_t)uvalue1;
    lvalue2 = (uint64_t)arg3 * (uvalue1 & 0xffffffff);
    uvalue4 = (uint32_t)((uint64_t)lvalue2 >> 0x20);
    uvalue8 = uvalue4 + value5 * arg4;
    if (((CARRY4(uvalue4,value5 * arg4)) || (arg2 < uvalue8)) ||
       ((arg2 <= uvalue8 && (arg1 < (uint32_t)lvalue2)))) {
      value5 = value5 + -1;
    }
    uvalue4 = 0;
  }
  return CONCAT44(uvalue4,value5);
}
