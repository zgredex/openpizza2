// FUN_00557190: ported from Pizza Connection 2 at 0x557190.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557190
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint32_t __cdecl FUN_00557190(uint8_t *arg1,char *arg2,void *arg3)

{
  char cVar1;
  int value2;
  uint8_t flag3;
  uint16_t uvalue4;
  uint32_t uvalue5;
  uint32_t uvalue6;
  void *self;
  uint32_t uvalue7;
  bool flag8;
  uint32_t uvalue9;
  
  value2 = _DAT_00585be8;
  uvalue6 = 0;
  if (arg3 != (void *)0x0) {
    if (DAT_005857cc == 0) {
      do {
        flag3 = *arg1;
        cVar1 = *arg2;
        uvalue4 = CONCAT11(flag3,cVar1);
        if (flag3 == 0) break;
        uvalue4 = CONCAT11(flag3,cVar1);
        uvalue7 = (uint32_t)uvalue4;
        if (cVar1 == '\0') break;
        arg1 = arg1 + 1;
        arg2 = arg2 + 1;
        if ((0x40 < flag3) && (flag3 < 0x5b)) {
          uvalue7 = (uint32_t)CONCAT11(flag3 + 0x20,cVar1);
        }
        uvalue4 = (uint16_t)uvalue7;
        flag3 = (uint8_t)uvalue7;
        if ((0x40 < flag3) && (flag3 < 0x5b)) {
          uvalue4 = (uint16_t)CONCAT31((int3)(uvalue7 >> 8),flag3 + 0x20);
        }
        flag3 = (uint8_t)(uvalue4 >> 8);
        flag8 = flag3 < (uint8_t)uvalue4;
        if (flag3 != (uint8_t)uvalue4) goto LAB_005571ef;
        arg3 = (void *)((intptr_t)arg3 + -1);
      } while (arg3 != (void *)0x0);
      uvalue6 = 0;
      flag3 = (uint8_t)(uvalue4 >> 8);
      flag8 = flag3 < (uint8_t)uvalue4;
      if (flag3 != (uint8_t)uvalue4) {
LAB_005571ef:
        uvalue6 = 0xffffffff;
        if (!flag8) {
          uvalue6 = 1;
        }
      }
    }
    else {
      LOCK();
      _DAT_00585be8 = _DAT_00585be8 + 1;
      UNLOCK();
      flag8 = 0 < DAT_00585be4;
      if (flag8) {
        LOCK();
        UNLOCK();
        _DAT_00585be8 = value2;
        CRT_Lock(0x13);
      }
      uvalue9 = (uint32_t)flag8;
      uvalue5 = 0;
      uvalue7 = 0;
      do {
        uvalue5 = CONCAT31((int3)(uvalue5 >> 8),*arg1);
        uvalue7 = CONCAT31((int3)(uvalue7 >> 8),*arg2);
        if ((uvalue5 == 0) || (uvalue7 == 0)) break;
        arg1 = arg1 + 1;
        arg2 = arg2 + 1;
        uvalue7 = CRT_Tolower_L(arg3,uvalue7);
        uvalue5 = CRT_Tolower_L(self,uvalue5);
        flag8 = uvalue5 < uvalue7;
        if (uvalue5 != uvalue7) goto LAB_00557265;
        arg3 = (void *)((intptr_t)arg3 + -1);
      } while (arg3 != (void *)0x0);
      uvalue6 = 0;
      flag8 = uvalue5 < uvalue7;
      if (uvalue5 != uvalue7) {
LAB_00557265:
        uvalue6 = 0xffffffff;
        if (!flag8) {
          uvalue6 = 1;
        }
      }
      if (uvalue9 == 0) {
        LOCK();
        _DAT_00585be8 = _DAT_00585be8 + -1;
        UNLOCK();
      }
      else {
        CS_LeaveIndexed(0x13);
      }
    }
  }
  return uvalue6;
}
