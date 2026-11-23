// UI_AlignSpriteToObject: ported from Pizza Connection 2 at 0x4f5730.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f5730
#include "pc2_port.h"

void __thiscall
UI_AlignSpriteToObject
          (void *self,int *arg1,int *arg2,int *arg3,uint32_t *arg4,uint32_t *arg5)

{
  void *pvVar1;
  
  pvVar1 = Game_GetLinkedObjectExtent(self,(uint32_t)arg1,arg4,arg5);
  UI_AlignSpriteToRect(self,arg1,pvVar1,arg2,arg3);
  return;
}
