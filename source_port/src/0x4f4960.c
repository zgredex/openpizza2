// Sprite_ApplyPaletteRemap: ported from Pizza Connection 2 at 0x4f4960.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f4960
#include "pc2_port.h"

void __thiscall
Sprite_ApplyPaletteRemap(char *self,uint32_t arg1,uint32_t arg2,uint8_t *arg3,int arg4)

{
  int value1;
  uint8_t *bptr2;
  int value3;
  int value4;
  uint8_t *bptr5;
  int value6;
  int local_18;
  uint32_t local_14;
  int local_10;
  int local_c;
  uint32_t local_8;
  int local_4;
  
  value6 = 0;
  local_c = 0;
  value3 = (*(int *)((intptr_t)self + 0xc) * DAT_00571960 - *(int *)((intptr_t)self + 0x2c)) + -0x100 +
          *(int *)((intptr_t)self + 0x24);
  value4 = (*(int *)((intptr_t)self + 0x10) * DAT_00571964 - *(int *)((intptr_t)self + 0x30)) + -0x80 +
          *(int *)((intptr_t)self + 0x28);
  local_4 = *(int *)(arg3 + 4);
  local_18 = *(int *)(arg3 + 8);
  local_10 = local_4;
  if (value3 < 0) {
    local_10 = local_4 + value3;
    local_c = -value3;
    value3 = 0;
  }
  if (value4 < 0) {
    local_18 = local_18 + value4;
    value6 = -value4;
    value4 = 0;
  }
  value1 = *(int *)((intptr_t)self + 0x70);
  if (value1 == 0) {
    if (*(void **)((intptr_t)self + 0x74) == (void *)0x0) {
      bptr2 = arg3;
    }
    else {
      Sprite_GetRenderSize(*(void **)((intptr_t)self + 0x74),&local_14,&local_8);
      value1 = Sprite_GetPixelBuffer(*(void **)((intptr_t)self + 0x74));
      bptr2 = (uint8_t *)(local_14 * value4 + value3 + value1);
    }
  }
  else {
    local_14 = *(uint32_t *)(value1 + 4);
    local_8 = *(uint32_t *)(value1 + 8);
    bptr2 = (uint8_t *)(local_14 * value4 + *(int *)(value1 + 0x18) + value3);
  }
  arg3 = (uint8_t *)(value6 * local_4 + *(int *)(arg3 + 0x18) + local_c);
  if ((intptr_t)local_14 < local_10 + value3) {
    local_10 = local_14 - value3;
  }
  if ((intptr_t)local_8 < local_18 + value4) {
    local_18 = local_8 - value4;
  }
  if (0 < local_18) {
    local_c = local_18;
    do {
      if (0 < local_10) {
        bptr5 = bptr2;
        value4 = local_10;
        do {
          if (bptr5[(intptr_t)arg3 - (intptr_t)bptr2] < 0xff) {
            *bptr5 = *(uint8_t *)((uint32_t)*bptr5 +
                               arg4 + (uint32_t)bptr5[(intptr_t)arg3 - (intptr_t)bptr2] * 0x100);
          }
          bptr5 = bptr5 + 1;
          value4 = value4 + -1;
        } while (value4 != 0);
      }
      arg3 = arg3 + local_4;
      bptr2 = bptr2 + local_14;
      local_c = local_c + -1;
    } while (local_c != 0);
  }
  return;
}
