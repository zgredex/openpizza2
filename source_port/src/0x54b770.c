// UI_DrawOverlaySprites: ported from Pizza Connection 2 at 0x54b770.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54b770
#include "pc2_port.h"

void __thiscall
UI_DrawOverlaySprites
          (void *self,int arg1,int arg2,void *arg3,int arg4,int arg5,int arg6)

{
  void *this_00;
  void *this_01;
  void *pvVar1;
  
  if (arg2 == 0) {
    this_00 = (void *)IDMap_Lookup((void *)((intptr_t)self + 4),(intptr_t)arg3,(int *)0x0);
    this_01 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x3c),arg4,(int *)0x0);
    arg3 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x74),arg5,(int *)0x0);
    pvVar1 = (void *)((intptr_t)self + 0xac);
  }
  else {
    this_00 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x20),(intptr_t)arg3,(int *)0x0);
    this_01 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x58),arg4,(int *)0x0);
    arg3 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x90),arg5,(int *)0x0);
    pvVar1 = (void *)((intptr_t)self + 200);
  }
  pvVar1 = (void *)IDMap_Lookup(pvVar1,arg6,(int *)0x0);
  if (this_00 != (void *)0x0) {
    Sprite_Draw(this_00,arg1,(uint32_t *)0x0,0);
  }
  if (pvVar1 != (void *)0x0) {
    Sprite_Draw(pvVar1,arg1,(uint32_t *)0x0,0);
  }
  if (this_01 != (void *)0x0) {
    Sprite_Draw(this_01,arg1,(uint32_t *)0x0,0);
  }
  if (arg3 != (void *)0x0) {
    Sprite_Draw(arg3,arg1,(uint32_t *)0x0,0);
  }
  return;
}
