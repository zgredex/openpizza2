// Palette_Convert256: ported from Pizza Connection 2 at 0x535e50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x535e50
#include "pc2_port.h"

void __thiscall Palette_Convert256(void *self,int arg1)

{
  int value1;
  int value2;
  int value3;
  uint16_t *uptr4;
  
  if (*(int *)self != 0) {
    value3 = 0x100;
    *(bool *)((intptr_t)self + 0x208) = arg1 == 1;
    value2 = 0;
    uptr4 = (uint16_t *)((intptr_t)self + 4);
    if (arg1 != 0) {
      do {
        value1 = *(int *)self;
        value2 = value2 + 3;
        value3 = value3 + -1;
        *uptr4 = ((uint16_t)(*(uint8_t *)(value1 + -1 + value2) & 0xf8) << 5 |
                  (uint16_t)(*(uint8_t *)(value1 + -2 + value2) & 0xf8)) << 3 |
                  (uint16_t)(*(uint8_t *)(value1 + -3 + value2) >> 3);
        uptr4 = uptr4 + 1;
      } while (value3 != 0);
      return;
    }
    do {
      value1 = *(int *)self;
      value2 = value2 + 3;
      value3 = value3 + -1;
      *uptr4 = ((uint16_t)(*(uint8_t *)(value1 + -1 + value2) & 0xf8) << 5 |
                (uint16_t)(*(uint8_t *)(value1 + -2 + value2) & 0xf8)) << 2 |
                (uint16_t)(*(uint8_t *)(value1 + -3 + value2) >> 3);
      uptr4 = uptr4 + 1;
    } while (value3 != 0);
  }
  return;
}
