// Map_DrawSelectedObjectSprite: ported from Pizza Connection 2 at 0x4f58e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f58e0
#include "pc2_port.h"

void __fastcall Map_DrawSelectedObjectSprite(void *arg1)

{
  void *self;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  uint32_t local_10;
  int local_c;
  int local_8;
  int local_4;
  
  if (*(int *)(DAT_0057c670 + 0x348) != -1) {
    self = (void *)SparseMap_Lookup48(*(void **)((intptr_t)arg1 + 4),
                                      *(int *)(*(int *)(*(int *)((intptr_t)arg1 + 100) + 8) + 0x10));
    if (self != (void *)0x0) {
      UI_AlignSpriteToRect(arg1,*(int **)((intptr_t)arg1 + 100),self,&local_28,&local_20);
      Sprite_GetHotspot(self,&local_24,&local_1c);
      Sprite_GetSize(self,&local_18,&local_14);
      local_10 = local_24 + local_28;
      local_c = local_20 + local_1c;
      local_8 = local_10 + local_18;
      local_4 = local_c + local_14;
      Gfx_BlitRectList(DAT_0058072c,&local_10);
    }
  }
  return;
}
