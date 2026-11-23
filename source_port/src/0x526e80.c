// UI_SetBackgroundSurfaceEnabled: ported from Pizza Connection 2 at 0x526e80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x526e80
#include "pc2_port.h"

void __thiscall UI_SetBackgroundSurfaceEnabled(void *self,int arg1)

{
  DWORD DVar1;
  int value2;
  uint32_t uvalue3;
  
  DVar1 = WaitForSingleObject(DAT_0057c0d8,0);
  if (DVar1 != 0) {
    CS_Enter(*(int *)((intptr_t)self + 0x1c8));
    *(int *)((intptr_t)self + 0x284) = arg1;
    if (arg1 != 0) {
      if ((*(int *)(DAT_0057c5c8 + 0x98) == 0) && (*(int *)((intptr_t)self + 0x8358) == 0)) {
        value2 = Object_GetRootType(DAT_0057c5c8);
        if (value2 == 2) {
          if (*(int *)(DAT_0057c5c8 + 0x40) == 0) {
            uvalue3 = 0;
          }
          else {
            uvalue3 = *(uint32_t *)(*(int *)(DAT_0057c5c8 + 0x40) + 8);
          }
          *(uint32_t *)((intptr_t)self + 0x1c0) = uvalue3;
        }
        Sprite_ClearBuffers(*(int **)((intptr_t)self + 0x1c0));
      }
      UI_MarkFullRectDirty(self);
    }
    CS_Leave(*(int *)((intptr_t)self + 0x1c8));
  }
  return;
}
