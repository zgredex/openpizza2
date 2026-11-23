// Game_SetRecordOpenState: ported from Pizza Connection 2 at 0x4d4070.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d4070
#include "pc2_port.h"

void __thiscall Game_SetRecordOpenState(void *self,uint8_t arg1)

{
  void *this_00;
  uint16_t uvalue1;
  
  *(uint8_t *)((intptr_t)self + 0x825) = arg1;
  this_00 = (void *)Game_GetRecordByField814((intptr_t)self);
  if (this_00 != (void *)0x0) {
    CS_Enter(*(int *)(DAT_0057c670 + 0x240));
    if (*(char *)((intptr_t)self + 0x825) == '\x01') {
      uvalue1 = 0x11;
    }
    else {
      uvalue1 = 0x10;
    }
    UI_SetChildState(this_00,uvalue1);
    CS_Leave(*(int *)(DAT_0057c670 + 0x240));
  }
  return;
}
