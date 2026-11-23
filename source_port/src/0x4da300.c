// Game_ChargeQuarterlyBribes: ported from Pizza Connection 2 at 0x4da300.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4da300
#include "pc2_port.h"

void __fastcall Game_ChargeQuarterlyBribes(int arg1)

{
  void *self;
  uint32_t uvalue1;
  int value2;
  int value3;
  int *ptr4;
  
  value3 = 0;
  ptr4 = (int *)(arg1 + 0xcc8);
  do {
    self = (void *)Game_GetPlayerBySlot(DAT_0057c670,value3);
    if ((self != (void *)0x0) && (ptr4[0x39] != 0)) {
      uvalue1 = Game_CanAffordWithCurrency(self,0x14,(float)(uint32_t)ptr4[0x39],'\x01',0xffffffff);
      if ((char)uvalue1 == '\0') {
        ptr4[0x39] = 0;
        *ptr4 = 0;
        value2 = Game_GetPlayerCity((intptr_t)self);
        value2 = *ptr4 + (*(int *)(value2 + 0x60) + *(int *)(value2 + 0x48)) * 3;
        *ptr4 = value2;
        if (value2 < 0) {
          *ptr4 = 0;
        }
        if (100 < *ptr4) {
          *ptr4 = 100;
        }
      }
    }
    value3 = value3 + 1;
    ptr4 = ptr4 + 1;
  } while (value3 < 6);
  return;
}
