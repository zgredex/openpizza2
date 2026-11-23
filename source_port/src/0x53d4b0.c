// Sprite_ConvertRGB555to565: ported from Pizza Connection 2 at 0x53d4b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53d4b0
#include "pc2_port.h"

void __thiscall Sprite_ConvertRGB555to565(void *self,void *arg1)

{
  uint16_t uvalue1;
  uint16_t *uptr2;
  int value3;
  
  if ((*(char *)((intptr_t)self + 5) == '\x0f') || (*(char *)((intptr_t)self + 5) == '\x10')) {
    uptr2 = *(uint16_t **)((intptr_t)self + 0x2c);
    if ((*(uint8_t *)((intptr_t)self + 4) & 1) == 0) {
      Color_Convert555To565(arg1,uptr2,*(int *)((intptr_t)self + 0x18) >> 1);
      if (*(char *)((intptr_t)arg1 + 0x18) == '\0') {
        return;
      }
    }
    else {
      if (*(char *)((intptr_t)arg1 + 0x18) != '\x01') {
        return;
      }
      if ((*(uint8_t *)((intptr_t)self + 4) & 0x10) != 0) {
        return;
      }
      value3 = 0;
      if (0 < (intptr_t)(*(uint32_t *)((intptr_t)self + 0x18) & 0xfffffffe)) {
        do {
          uvalue1 = *uptr2;
          if ((uint32_t)uvalue1 == *(uint32_t *)((intptr_t)self + 0x1c)) {
            value3 = value3 + 1;
            *uptr2 = (uvalue1 & 0xffe0) << 1 | uvalue1 & 0x1f;
            uptr2 = uptr2 + 1;
          }
          else {
            *uptr2 = (uvalue1 & 0xffe0) << 1 | uvalue1 & 0x1f;
          }
          value3 = value3 + 1;
          uptr2 = uptr2 + 1;
        } while (value3 < *(int *)((intptr_t)self + 0x18) >> 1);
      }
    }
    *(uint32_t *)((intptr_t)self + 0x1c) =
         (*(uint32_t *)((intptr_t)self + 0x1c) & 0x7fe0) << 1 | *(uint32_t *)((intptr_t)self + 0x1c) & 0x1f;
  }
  return;
}
