// Palette_Expand: ported from Pizza Connection 2 at 0x48ce70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48ce70
#include "pc2_port.h"

void Palette_Expand(uint16_t *arg1,int arg2,uint32_t arg3)

{
  uint16_t uvalue1;
  uint16_t *uptr2;
  uint16_t *uptr3;
  uint16_t *uptr4;
  uint16_t *uptr5;
  uint16_t *uptr6;
  uint8_t *bptr7;
  uint16_t *uptr8;
  int local_8;
  
  uptr5 = arg1 + 2;
  uptr6 = (uint16_t *)((uint32_t)uptr5 & 0xff);
  local_8 = 0x100;
  bptr7 = (uint8_t *)(*(int *)arg1 + 1);
  uptr8 = uptr5;
  arg1 = uptr5;
  do {
    uptr2 = (uint16_t *)(uint32_t)bptr7[-1];
    uptr3 = (uint16_t *)(uint32_t)*bptr7;
    uptr4 = (uint16_t *)(uint32_t)bptr7[1];
    switch(arg3) {
    case 0:
      uptr5 = uptr4;
      uptr6 = uptr2;
      uptr8 = uptr2;
      break;
    case 1:
      uptr5 = uptr4;
      uptr6 = uptr4;
      uptr8 = uptr2;
      break;
    case 2:
      uptr2 = uptr3;
      goto LAB_0048cf0a;
    case 3:
      uptr5 = uptr2;
      uptr6 = uptr4;
      uptr8 = uptr3;
      break;
    case 4:
      uptr4 = (uint16_t *)((intptr_t)uptr4 + (intptr_t)uptr3 >> 1);
      uptr2 = uptr4;
      goto LAB_0048cf0a;
    case 5:
      goto LAB_0048cf08;
    case 6:
      uptr5 = uptr4;
      uptr6 = uptr3;
      uptr8 = uptr2;
      break;
    case 7:
      uptr4 = (uint16_t *)((uint32_t)((intptr_t)uptr4 + (intptr_t)uptr3) / 2);
LAB_0048cf08:
      uptr3 = uptr4;
LAB_0048cf0a:
      uptr5 = uptr2;
      uptr6 = uptr3;
      uptr8 = uptr4;
    }
    if (arg2 == 0) {
      uvalue1 = (uint16_t)((((uint32_t)uptr5 & 0xf8) << 5 | (uint32_t)uptr6 & 0xf8) << 2);
    }
    else {
      uvalue1 = (uint16_t)((((uint32_t)uptr5 & 0xfff8) << 5 | (uint32_t)uptr6 & 0xf8) << 3);
    }
    *arg1 = uvalue1 | (uint16_t)((intptr_t)uptr8 >> 3);
    arg1 = arg1 + 1;
    local_8 = local_8 + -1;
    if (local_8 == 0) {
      return;
    }
    bptr7 = bptr7 + 3;
  } while( true );
}
