// Map_UpdateVisibilityFlags: ported from Pizza Connection 2 at 0x4edf30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4edf30
#include "pc2_port.h"

void __thiscall Map_UpdateVisibilityFlags(void *self,uint32_t *arg1)

{
  uint32_t *uptr1;
  uint32_t uvalue2;
  void *pvVar3;
  uint16_t *uptr4;
  uint32_t uvalue5;
  
  uptr1 = (uint32_t *)arg1[2];
  uvalue2 = uptr1[4];
  uvalue5 = *uptr1 & 7;
  if ((0x867 < (intptr_t)uvalue2) && ((intptr_t)uvalue2 < 0x87e)) {
    *(uint8_t *)((intptr_t)uptr1 + 0x2e) = 0;
  }
  if ((((DAT_00585518 <= (intptr_t)(uvalue5 + 0xa0)) && (*(char *)(arg1[2] + 0x2e) != '\x01')) &&
      (((intptr_t)uvalue2 < 0x6e8 || ((0x6f3 < (intptr_t)uvalue2 || (DAT_00585518 <= (intptr_t)(uvalue5 + 0x78))))))) &&
     (((intptr_t)uvalue2 < 0x6f4 || ((0x6fb < (intptr_t)uvalue2 || (DAT_00585518 <= (intptr_t)(uvalue5 + 0x8c))))))) {
    pvVar3 = *(void **)(*(int *)((intptr_t)self + 4) + 0x5c + uvalue2 * 0x48);
    if (pvVar3 != (void *)0x0) {
      uvalue5 = (uint32_t)*(uint8_t *)(arg1[2] + 0x2d);
      if (uvalue5 != 0) {
        uptr4 = (uint16_t *)Sprite_GetPalette((intptr_t)pvVar3);
        if (uptr4 != (uint16_t *)0x0) {
          Palette_Expand(uptr4,(uint32_t)*(uint8_t *)(*(int *)((intptr_t)self + 8) + 0x18),uvalue5 - 1);
        }
      }
      UI_DrawObjectSprite(self,arg1,pvVar3);
    }
    pvVar3 = *(void **)(*(int *)((intptr_t)self + 4) + 100 + uvalue2 * 0x48);
    if (pvVar3 != (void *)0x0) {
      Map_BlitAlignedObjectSprite(self,(int *)arg1,pvVar3);
    }
  }
  return;
}
