// Game_InitCompanySlots: ported from Pizza Connection 2 at 0x4f6e70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f6e70
#include "pc2_port.h"

void __fastcall Game_InitCompanySlots(int arg1)

{
  uint32_t uvalue1;
  uint32_t uvalue2;
  int value3;
  uint32_t *uptr4;
  int value5;
  uint32_t *uptr6;
  uint32_t *uptr7;
  int local_8;
  
  value5 = 0;
  uptr6 = (uint32_t *)(arg1 + 0x114);
  uvalue1 = *(uint32_t *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2f0) * 4 + 0x224);
  local_8 = 0x224;
  do {
    uvalue2 = *(uint32_t *)(local_8 + (intptr_t)DAT_0057c670);
    if (uvalue2 == 0) {
      uptr6[1] = 0;
      *uptr6 = 0;
    }
    else {
      uptr4 = uptr6 + -0x36;
      for (value3 = 0x5a; value3 != 0; value3 = value3 + -1) {
        *uptr4 = 0;
        uptr4 = uptr4 + 1;
      }
      *uptr6 = (uint32_t)(uvalue2 != uvalue1);
      *(uint8_t *)(uptr6 + 0x23) = 0;
      uptr6[2] = 0xffffffff;
      uptr6[3] = 0xffffffff;
      uptr6[-0x2a] = uvalue2;
      uvalue2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(uvalue2 + 8));
      uptr6[-0x29] = uvalue2;
      uvalue2 = Game_GetPlayerField8(DAT_0057c670,value5);
      uptr6[-0x35] = uvalue2;
      uptr6[0x22] = 50000;
      uvalue2 = Random_RangeFast(DAT_0057bb24 * 6,DAT_0057bb24 * 9);
      uptr4 = uptr6 + -0x28;
      *(short *)(uptr6 + 5) = (short)uvalue2;
      uptr7 = uptr4;
      for (value3 = 0x28; value3 != 0; value3 = value3 + -1) {
        *uptr7 = 0;
        uptr7 = uptr7 + 1;
      }
      uptr7 = uptr6 + -0x34;
      for (value3 = 10; value3 != 0; value3 = value3 + -1) {
        *uptr7 = 0;
        uptr7 = uptr7 + 1;
      }
      value3 = 10;
      do {
        uptr4[3] = 0;
        *uptr4 = 0xffffffff;
        uptr4 = uptr4 + 4;
        value3 = value3 + -1;
      } while (value3 != 0);
      uptr4 = uptr6 + 9;
      for (value3 = 0x18; value3 != 0; value3 = value3 + -1) {
        *uptr4 = 0;
        uptr4 = uptr4 + 1;
      }
      uptr6[6] = 3;
      uptr6[1] = 1;
    }
    local_8 = local_8 + 4;
    value5 = value5 + 1;
    uptr6 = uptr6 + 0x5a;
  } while (local_8 < 0x23c);
  return;
}
