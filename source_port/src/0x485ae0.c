// Game_ShowBranchScene: ported from Pizza Connection 2 at 0x485ae0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x485ae0
#include "pc2_port.h"

void __thiscall Game_ShowBranchScene(void *self,void *arg1,int arg2)

{
  int value1;
  
  CS_Enter(*(int *)((intptr_t)self + 0x240));
  if (*(uint32_t **)((intptr_t)self + 0x300) != (uint32_t *)0x0) {
    (**(code **)**(uint32_t **)((intptr_t)self + 0x300))(1);
    *(uint32_t *)((intptr_t)self + 0x300) = 0;
  }
  if (arg2 == 1) {
    if (*(char *)(*(int *)((intptr_t)self + 0x9c) + 0x16f5) != '\0') {
      value1 = *(int *)(*(int *)((intptr_t)self + 0x9c) + 0x38);
      if (-1 < value1) {
        if (value1 < 2) {
          Game_LoadBackgroundImage(self,s_BAUHINTERGRUND_MITTEL_tga_00567cdc);
          goto LAB_00485b69;
        }
        if (value1 == 2) {
          Game_LoadBackgroundImage(self,s_BAUHINTERGRUND_GROSS_tga_00567cf8);
          goto LAB_00485b69;
        }
      }
      Game_LoadBackgroundImage(self,(char *)0x1);
    }
  }
  else {
    Game_ReleaseConstructionSpriteLists(DAT_0057c5cc);
  }
LAB_00485b69:
  *(int *)((intptr_t)self + 0x33c) = arg2;
  *(void **)((intptr_t)self + 0x2fc) = arg1;
  Map_UpdateObjectScreenBounds(arg1);
  *(uint32_t *)(*(int *)((intptr_t)self + 0x2fc) + 0xf4) = 1;
  CS_Leave(*(int *)((intptr_t)self + 0x240));
  Map_DrawMinimap(self);
  return;
}
