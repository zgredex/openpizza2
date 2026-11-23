// RecordList_BlitIndexedRLE: ported from Pizza Connection 2 at 0x5346a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5346a0
#include "pc2_port.h"

void __thiscall RecordList_BlitIndexedRLE(void *self,int arg1,uint32_t *arg2,int arg3)

{
  int value1;
  int value2;
  int64_t lvalue3;
  
  if ((-1 < arg3) && (arg3 < *(int *)((intptr_t)self + 0x48))) {
    CS_Enter(0x5842a0);
    if (*(int *)(*(int *)((intptr_t)self + 0x4c) + arg3 * 0x48) == -1) {
      CS_Leave(0x5842a0);
      return;
    }
    if (*(char *)((intptr_t)self + 0x35) == '\0') {
      RecordList_EnsureLoaded((intptr_t)self);
    }
    value2 = arg3 * 0x48 + *(int *)((intptr_t)self + 0x4c);
    *(uint16_t *)((intptr_t)self + 6) =
         *(uint16_t *)(*(int *)((intptr_t)self + 0x20) + *(short *)(value2 + 0x32) * 2);
    *(uint16_t *)((intptr_t)self + 8) =
         *(uint16_t *)(*(int *)((intptr_t)self + 0x24) + *(short *)(value2 + 0x32) * 2);
    *(uint16_t *)((intptr_t)self + 10) =
         *(uint16_t *)(*(int *)((intptr_t)self + 0x28) + *(short *)(value2 + 0x32) * 2);
    *(uint16_t *)((intptr_t)self + 0xc) =
         *(uint16_t *)(*(int *)((intptr_t)self + 0x2c) + *(short *)(value2 + 0x32) * 2);
    lvalue3 = __ftol();
    value1 = (intptr_t)lvalue3;
    lvalue3 = __ftol();
    Surface_BlitRLESkipToRGB
              (self,arg1,arg2,
               *(uint8_t **)(*(int *)((intptr_t)self + 0x80) + *(short *)(value2 + 0x32) * 4),(uint32_t)lvalue3,
               value1);
    CS_Leave(0x5842a0);
  }
  return;
}
