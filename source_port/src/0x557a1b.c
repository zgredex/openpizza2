// FUN_00557a1b: ported from Pizza Connection 2 at 0x557a1b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557a1b
#include "pc2_port.h"

uint8_t * __cdecl FUN_00557a1b(uint8_t *arg1,uint32_t arg2)

{
  uint8_t flag1;
  uint8_t *bptr2;
  uint32_t uvalue3;
  
  if (DAT_005859bc == 0) {
    bptr2 = (uint8_t *)_strchr((char *)arg1,arg2);
  }
  else {
    CRT_Lock(0x19);
    while( true ) {
      flag1 = *arg1;
      uvalue3 = (uint32_t)flag1;
      if (flag1 == 0) break;
      if ((*(uint8_t *)((intptr_t)&DAT_00585ac0 + uvalue3 + 1) & 4) == 0) {
        bptr2 = arg1;
        if (arg2 == uvalue3) break;
      }
      else {
        bptr2 = arg1 + 1;
        if (arg1[1] == 0) {
          CS_LeaveIndexed(0x19);
          return (uint8_t *)0x0;
        }
        if (arg2 == CONCAT11(flag1,arg1[1])) {
          CS_LeaveIndexed(0x19);
          return arg1;
        }
      }
      arg1 = bptr2 + 1;
    }
    CS_LeaveIndexed(0x19);
    bptr2 = (uint8_t *)(~-(uint32_t)(arg2 != uvalue3) & (uint32_t)arg1);
  }
  return bptr2;
}
