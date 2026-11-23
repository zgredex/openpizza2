// Sprite_FillColor8: ported from Pizza Connection 2 at 0x53dd90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53dd90
#include "pc2_port.h"

uint32_t __fastcall Sprite_FillColor8(void *arg1)

{
  uint8_t uvalue1;
  short svalue2;
  short svalue3;
  int value4;
  uint8_t *uptr5;
  uint32_t uvalue6;
  uint32_t uvalue7;
  int value8;
  int value9;
  int local_4;
  
  if (((*(uint8_t *)((intptr_t)arg1 + 4) & 1) != 0) || (*(char *)((intptr_t)arg1 + 5) != '\b')) {
    return 0;
  }
  if (*(uint8_t *)((intptr_t)arg1 + 0x36) == 0xffffffff) {
    Sprite_Rotate(arg1,(uint16_t *)0x0);
  }
  if (*(uint8_t *)((intptr_t)arg1 + 0x36) == 0xffffffff) {
    return 0;
  }
  value9 = *(int *)((intptr_t)arg1 + 0x30);
  if (*(char *)((intptr_t)arg1 + 0x37) == '\0') {
    svalue2 = *(short *)((intptr_t)arg1 + 8);
    svalue3 = *(short *)((intptr_t)arg1 + 6);
  }
  else {
    svalue2 = *(short *)((intptr_t)arg1 + 6);
    svalue3 = *(short *)((intptr_t)arg1 + 8);
  }
  local_4 = (intptr_t)svalue2;
  value8 = (intptr_t)svalue3;
  uvalue1 = *(uint8_t *)((intptr_t)arg1 + 0x1c);
  uvalue7 = 0;
  if (0 < local_4) {
    do {
      if ((*(uint8_t *)((intptr_t)arg1 + 4) & 0x10) == 0) {
        for (uvalue6 = uvalue7 & 1; value4 = value8, (intptr_t)uvalue6 < value8; uvalue6 = uvalue6 + 2) {
          *(uint8_t *)(uvalue6 + value9) = uvalue1;
        }
      }
      else {
        uvalue6 = uvalue7 & 1;
        if ((intptr_t)uvalue6 < value8) {
          uptr5 = (uint8_t *)(value9 + uvalue6 * 2);
          uvalue6 = (value8 - uvalue6) + 1 >> 1;
          do {
            *uptr5 = 0;
            uptr5[1] = 1;
            uptr5 = uptr5 + 4;
            uvalue6 = uvalue6 - 1;
          } while (uvalue6 != 0);
        }
        value4 = value8 * 2;
      }
      value9 = value9 + value4;
      uvalue7 = uvalue7 + 1;
    } while ((intptr_t)uvalue7 < local_4);
  }
  return 1;
}
