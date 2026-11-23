// FUN_005570c0: ported from Pizza Connection 2 at 0x5570c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5570c0
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint32_t __thiscall FUN_005570c0(void *self,uint8_t *arg1,uint8_t *arg2)

{
  bool flag1;
  int value2;
  uint8_t flag3;
  uint8_t flag4;
  uint8_t flag5;
  char cVar6;
  uint32_t uvalue7;
  void *extraout_ECX;
  void *this_00;
  void *extraout_ECX_00;
  uint32_t uvalue8;
  uint32_t uvalue9;
  
  value2 = _DAT_00585be8;
  if (DAT_005857cc == 0) {
    flag5 = 0xff;
    do {
      do {
        cVar6 = '\0';
        if (flag5 == 0) goto LAB_0055710e;
        flag5 = *arg2;
        arg2 = arg2 + 1;
        flag4 = *arg1;
        arg1 = arg1 + 1;
      } while (flag4 == flag5);
      flag3 = flag5 + 0xbf + (-((uint8_t)(flag5 + 0xbf) < 0x1a) & 0x20U) + 0x41;
      flag4 = flag4 + 0xbf;
      flag5 = flag4 + (-(flag4 < 0x1a) & 0x20U) + 0x41;
    } while (flag5 == flag3);
    cVar6 = (flag5 < flag3) * -2 + '\x01';
LAB_0055710e:
    uvalue7 = (uint32_t)cVar6;
  }
  else {
    LOCK();
    _DAT_00585be8 = _DAT_00585be8 + 1;
    UNLOCK();
    flag1 = 0 < DAT_00585be4;
    if (flag1) {
      LOCK();
      UNLOCK();
      _DAT_00585be8 = value2;
      CRT_Lock(0x13);
      self = extraout_ECX;
    }
    uvalue9 = (uint32_t)flag1;
    uvalue7 = 0xff;
    uvalue8 = 0;
    do {
      do {
        if ((char)uvalue7 == '\0') goto LAB_0055716f;
        flag5 = *arg2;
        uvalue7 = CONCAT31((int3)(uvalue7 >> 8),flag5);
        arg2 = arg2 + 1;
        flag4 = *arg1;
        uvalue8 = CONCAT31((int3)(uvalue8 >> 8),flag4);
        arg1 = arg1 + 1;
      } while (flag5 == flag4);
      uvalue8 = CRT_Tolower_L(self,uvalue8);
      uvalue7 = CRT_Tolower_L(this_00,uvalue7);
      self = extraout_ECX_00;
    } while ((uint8_t)uvalue8 == (uint8_t)uvalue7);
    uvalue8 = (uint32_t)((uint8_t)uvalue8 < (uint8_t)uvalue7);
    uvalue7 = (1 - uvalue8) - (uint32_t)(uvalue8 != 0);
LAB_0055716f:
    if (uvalue9 == 0) {
      LOCK();
      _DAT_00585be8 = _DAT_00585be8 + -1;
      UNLOCK();
    }
    else {
      CS_LeaveIndexed(0x13);
    }
  }
  return uvalue7;
}
