// Map_BlitAlignedObjectSprite: ported from Pizza Connection 2 at 0x4edee0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4edee0
#include "pc2_port.h"

void __thiscall Map_BlitAlignedObjectSprite(void *self,int *arg1,void *arg2)

{
  void *this_00;
  
  this_00 = arg2;
  if (arg2 != (void *)0x0) {
    UI_AlignSpriteToRect(self,arg1,arg2,(int *)&arg1,(int *)&arg2);
    Surface_BlitRLEEnsureFormat
              (this_00,*(int *)((intptr_t)self + 8),DAT_0058072c,(uint32_t)arg1,(intptr_t)arg2);
  }
  return;
}
