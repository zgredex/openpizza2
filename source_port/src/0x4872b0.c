// UI_ClearActiveRecordSlots: ported from Pizza Connection 2 at 0x4872b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4872b0
#include "pc2_port.h"

void __fastcall UI_ClearActiveRecordSlots(int arg1)

{
  void *self;
  int value1;
  int value2;
  
  self = *(void **)(DAT_0057c5cc + 0x2c3d4);
  value2 = 0x2c41c;
  do {
    value1 = *(int *)(value2 + DAT_0057c5cc);
    if (((-1 < value1) && (value1 < *(int *)((intptr_t)self + 0x48))) &&
       (*(char *)(*(int *)((intptr_t)self + 0x4c) + 0x3e + value1 * 0x48) != '\0')) {
      Record_ClearFlags48(self,value1);
      *(uint32_t *)(arg1 + -0x2c0b0 + value2) = 0xffffffff;
    }
    value2 = value2 + 4;
  } while (value2 < 0x2c434);
  return;
}
