// Game_DrawMapObjectSprite: ported from Pizza Connection 2 at 0x4e6340.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e6340
#include "pc2_port.h"

void __thiscall Game_DrawMapObjectSprite(void *self,void *arg1)

{
  int value1;
  int value2;
  void *this_00;
  void *this_01;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  uint32_t local_10;
  int local_c;
  int local_8;
  int local_4;
  
  this_00 = arg1;
  value1 = *(int *)((intptr_t)self + 0x20);
  value2 = *(int *)((intptr_t)arg1 + 0x4c);
  this_01 = (void *)SparseMap_Lookup48(DAT_0057c5cc,
                                       *(int *)(*(int *)(value2 + 8 + value1 * 0xc) + 0x10));
  if (this_01 != (void *)0x0) {
    UI_AlignSpriteToRect(this_00,(int *)(value2 + value1 * 0xc),this_01,(int *)&arg1,&local_20);
    Sprite_GetHotspot(this_01,&local_24,&local_1c);
    Sprite_GetSize(this_01,&local_18,&local_14);
    local_10 = local_24 + (intptr_t)arg1;
    local_c = local_20 + local_1c;
    local_8 = local_10 + local_18;
    local_4 = local_c + local_14;
    Gfx_BlitRectList(DAT_0058072c,&local_10);
  }
  return;
}
