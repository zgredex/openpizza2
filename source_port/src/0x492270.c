// UI_FillObjectWithPaletteColor: ported from Pizza Connection 2 at 0x492270.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x492270
#include "pc2_port.h"

void __cdecl UI_FillObjectWithPaletteColor(void *arg1,int arg2,int arg3)

{
  void *self;
  
  self = (void *)UI_GetWindowObject(arg1,arg2);
  UI_RealizeSprite((intptr_t)self);
  UI_GetChildSize(self,(int *)&arg1,&arg2);
  Sprite_FillRectColor(self,0,0,(intptr_t)arg1,arg2,*(uint32_t *)(&DAT_0056869c + arg3 * 4));
  UI_ClipChildRect((intptr_t)self);
  return;
}
