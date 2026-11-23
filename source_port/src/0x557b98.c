// FUN_00557b98: ported from Pizza Connection 2 at 0x557b98.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557b98
#include "pc2_port.h"


uint32_t __cdecl FUN_00557b98(uint32_t arg1)

{
  uint32_t uvalue1;
  uint8_t flag2;
  int value3;
  uint8_t uvalue4;
  uint16_t local_8;
  
  uvalue1 = arg1;
  if (arg1 < 0x100) {
    if ((*(uint8_t *)((intptr_t)&DAT_00585ac0 + arg1 + 1) & 0x20) == 0x20) {
      return (uint32_t)(uint8_t)(&DAT_005859c0)[arg1];
    }
  }
  else {
    uvalue4 = (uint8_t)arg1;
    flag2 = (uint8_t)(arg1 >> 8);
    arg1 = CONCAT13(uvalue4,CONCAT12(flag2,(uint16_t)arg1));
    if (((*(uint8_t *)((intptr_t)&DAT_00585ac0 + flag2 + 1) & 4) != 0) &&
       (value3 = CRT_LCMapStringA(DAT_00585bc4,0x200,(char *)((intptr_t)&arg1 + 2),2,&local_8,2,
                                 DAT_005859ac,1), value3 != 0)) {
      return (uint32_t)CONCAT11((uint8_t)local_8,((uint8_t)((local_8) >> 8)));
    }
  }
  return uvalue1;
}
