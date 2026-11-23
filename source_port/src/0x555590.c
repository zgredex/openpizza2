// __aullrem: ported from Pizza Connection 2 at 0x555590.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x555590
#include "pc2_port.h"

/* Library Function - Single Match
    __aullrem
   
   Library: Visual Studio */

uint64_t __aullrem(uint32_t arg1,uint32_t arg2,uint32_t arg3,uint32_t arg4)

{
  uint64_t uvalue1;
  int64_t lvalue2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  uint32_t uvalue5;
  uint32_t uvalue6;
  int value7;
  int value8;
  uint32_t uvalue9;
  bool flag10;
  
  if (arg4 == 0) {
    value7 = (intptr_t)(((uint64_t)arg2 % (uint64_t)arg3 << 0x20 | (uint64_t)arg1) %
                 (uint64_t)arg3);
    value8 = 0;
  }
  else {
    uvalue5 = arg1;
    uvalue6 = arg4;
    uvalue9 = arg2;
    uvalue4 = arg3;
    do {
      uvalue3 = uvalue6 & 1;
      uvalue6 = uvalue6 >> 1;
      uvalue4 = (uint32_t)(CONCAT14(uvalue3 != 0,uvalue4) >> 1);
      uvalue3 = uvalue9 & 1;
      uvalue9 = uvalue9 >> 1;
      uvalue5 = (uint32_t)(CONCAT14(uvalue3 != 0,uvalue5) >> 1);
    } while (uvalue6 != 0);
    uvalue1 = CONCAT44(uvalue9,uvalue5) / (uint64_t)uvalue4;
    uvalue4 = (intptr_t)uvalue1 * arg4;
    lvalue2 = (uvalue1 & 0xffffffff) * (uint64_t)arg3;
    uvalue6 = (uint32_t)((uint64_t)lvalue2 >> 0x20);
    uvalue5 = (uint32_t)lvalue2;
    uvalue9 = uvalue6 + uvalue4;
    if (((CARRY4(uvalue6,uvalue4)) || (arg2 < uvalue9)) || ((arg2 <= uvalue9 && (arg1 < uvalue5)))) {
      flag10 = uvalue5 < arg3;
      uvalue5 = uvalue5 - arg3;
      uvalue9 = (uvalue9 - arg4) - (uint32_t)flag10;
    }
    value7 = -(uvalue5 - arg1);
    value8 = -(uint32_t)(uvalue5 - arg1 != 0) - ((uvalue9 - arg2) - (uint32_t)(uvalue5 < arg1));
  }
  return CONCAT44(value8,value7);
}
