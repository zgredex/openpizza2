// UI_DrawObjectWithBounds: ported from Pizza Connection 2 at 0x4f5990.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f5990
#include "pc2_port.h"

void __thiscall UI_DrawObjectWithBounds(void *self,int *arg1,int *arg2)

{
  int *ptr1;
  void *this_00;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int *local_10;
  int local_c;
  int *local_8;
  int local_4;
  
  ptr1 = arg1;
  if ((arg1 != (int *)0x0) && (arg1[2] != 0)) {
    this_00 = (void *)SparseMap_Lookup48(*(void **)((intptr_t)self + 4),*(int *)(arg1[2] + 0x10));
    if (this_00 == (void *)0x0) {
      UI_ComputeCenteredRect(self,ptr1,(int *)&arg1,&local_24);
      local_c = local_24 + -0x40;
      local_10 = arg1 + -0x10;
      local_4 = local_24 + 0x40;
      local_8 = arg1 + 0x10;
    }
    else {
      UI_AlignSpriteToRect(self,ptr1,this_00,(int *)&arg1,&local_24);
      Sprite_GetHotspot(this_00,&local_20,&local_1c);
      Sprite_GetSize(this_00,&local_18,&local_14);
      local_10 = (int *)(local_20 + (intptr_t)arg1);
      local_c = local_24 + local_1c;
      local_8 = (int *)(local_18 + (intptr_t)local_10);
      local_4 = local_14 + local_c;
    }
    if (arg2 != (int *)0x0) {
      *arg2 = (intptr_t)local_10 + -0x32;
      arg2[1] = local_c + -0x32;
      arg2[2] = (intptr_t)local_8 + 0x32;
      arg2[3] = local_4 + 0x32;
      return;
    }
    Gfx_BlitRectList(DAT_0058072c,(uint32_t *)&local_10);
  }
  return;
}
