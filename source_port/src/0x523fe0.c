// UI_ProcessChildEvent: ported from Pizza Connection 2 at 0x523fe0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x523fe0
#include "pc2_port.h"

void __thiscall UI_ProcessChildEvent(void *self,void *arg1)

{
  int value1;
  void *pvVar2;
  bool flag3;
  bool flag4;
  uint32_t uvalue5;
  int value6;
  int local_20;
  uint32_t *local_1c;
  int local_14;
  tagRECT local_10;
  
  uvalue5 = Renderer_DrawPendingSprite
                    (*(void **)((intptr_t)self + 0x8310),(intptr_t)arg1,(LPRECT)((intptr_t)self + 0x83c0));
  *(uint32_t *)((intptr_t)self + 0x83bc) = uvalue5;
  local_20 = 0;
  *(uint32_t *)((intptr_t)self + 0x83d0) = 0xfffffc19;
  if ((*(int *)((intptr_t)self + 0x238) == 0) && (*(int *)((intptr_t)self + 0x83e4) == 0)) {
    value6 = *(int *)((intptr_t)self + 0x1a4);
    if (value6 != -999) {
      local_20 = 1;
      *(uint32_t *)((intptr_t)self + 0x83d0) = *(uint32_t *)((intptr_t)self + 0x1a4);
      *(uint32_t *)((intptr_t)self + 0x83d4) = *(uint32_t *)((intptr_t)self + 0x1a8);
      *(uint32_t *)((intptr_t)self + 0x83d8) = *(uint32_t *)((intptr_t)self + 0x1ac);
      *(uint32_t *)((intptr_t)self + 0x83dc) = *(uint32_t *)((intptr_t)self + 0x1b0);
      if (*(void **)((intptr_t)self + 0x1c4) != (void *)0x0) {
        value1 = *(int *)((intptr_t)self + 0x1a8);
        Sprite_Blit24Bit(*(void **)((intptr_t)self + 0x1c4),(intptr_t)arg1,value6,value1,
                         *(int *)((intptr_t)self + 0x1ac) - value6,*(int *)((intptr_t)self + 0x1b0) - value1,
                         value6,value1);
      }
      *(uint32_t *)((intptr_t)self + 0x1a4) = 0xfffffc19;
    }
  }
  else {
    local_20 = 2;
    *(uint32_t *)((intptr_t)self + 0x238) = 0;
    if (*(void **)((intptr_t)self + 0x1c4) == (void *)0x0) {
      if (*(int *)((intptr_t)self + 0x1b4) == 0) {
        if (*(int *)((intptr_t)self + 0x1bc) != 0) {
          Surface_Clear(*(int *)((intptr_t)self + 0x1bc));
        }
      }
      else {
        Surface_ClearRows((intptr_t)arg1);
      }
    }
    else {
      Sprite_Blit24Bit(*(void **)((intptr_t)self + 0x1c4),(intptr_t)arg1,0,0,-9999,-9999,0,0);
    }
    *(uint32_t *)((intptr_t)self + 0x234) = 0;
  }
  local_14 = 0;
  if (0 < *(int *)((intptr_t)self + 0x23c)) {
    local_1c = (uint32_t *)((intptr_t)self + 0x14);
    do {
      pvVar2 = (void *)*local_1c;
      if ((pvVar2 != (void *)0x0) && (*(int *)((intptr_t)pvVar2 + 0x4c) != 0)) {
        if ((*(int *)((intptr_t)pvVar2 + 0xe0) == 0) && (*(int *)((intptr_t)pvVar2 + 0x38) == -999)) {
          flag3 = false;
        }
        else {
          flag3 = true;
        }
        flag4 = false;
        if (local_20 == 0) {
          if (!flag3) goto LAB_005242b4;
          local_20 = 1;
          UI_GetWindowRect(pvVar2,(LPRECT)((intptr_t)self + 0x83d0));
        }
        else if (local_20 == 1) {
          if ((!flag3) && (*(int *)((intptr_t)self + 0x83d0) != -999)) {
            local_10.left = *(int *)((intptr_t)pvVar2 + 8);
            local_10.top = *(int *)((intptr_t)pvVar2 + 0xc);
            local_10.right = *(int *)((intptr_t)pvVar2 + 0x10);
            local_10.bottom = *(int *)((intptr_t)pvVar2 + 0x14);
            if ((*(int *)((intptr_t)self + 0x83d0) < local_10.right) &&
               (((local_10.left < *(int *)((intptr_t)self + 0x83d8) &&
                 (*(int *)((intptr_t)self + 0x83d4) < local_10.bottom)) &&
                (local_10.top < *(int *)((intptr_t)self + 0x83dc))))) {
              flag4 = true;
            }
          }
          if ((*(int *)((intptr_t)pvVar2 + 0xe0) == 0) && (*(int *)((intptr_t)pvVar2 + 0x38) == -999)) {
            if (!flag4) goto LAB_005242b4;
          }
          else {
            UI_GetWindowRect(pvVar2,&local_10);
            value6 = *(int *)((intptr_t)self + 0x83d0);
            if (value6 == -999) {
              *(int *)((intptr_t)self + 0x83d0) = local_10.left;
              *(LONG *)((intptr_t)self + 0x83d4) = local_10.top;
              *(LONG *)((intptr_t)self + 0x83d8) = local_10.right;
              *(LONG *)((intptr_t)self + 0x83dc) = local_10.bottom;
            }
            else {
              if (local_10.left <= value6) {
                value6 = local_10.left;
              }
              *(int *)((intptr_t)self + 0x83d0) = value6;
              value6 = *(int *)((intptr_t)self + 0x83d8);
              if (*(int *)((intptr_t)self + 0x83d8) <= local_10.right) {
                value6 = local_10.right;
              }
              *(int *)((intptr_t)self + 0x83d8) = value6;
              value6 = *(int *)((intptr_t)self + 0x83d4);
              if (local_10.top <= *(int *)((intptr_t)self + 0x83d4)) {
                value6 = local_10.top;
              }
              *(int *)((intptr_t)self + 0x83d4) = value6;
              value6 = *(int *)((intptr_t)self + 0x83dc);
              if (*(int *)((intptr_t)self + 0x83dc) <= local_10.bottom) {
                value6 = local_10.bottom;
              }
              *(int *)((intptr_t)self + 0x83dc) = value6;
            }
          }
        }
        else {
          if (local_20 != 2) goto LAB_005242b4;
          SetRect((LPRECT)((intptr_t)self + 0x83d0),0,0,*(int *)((intptr_t)self + 0x270),
                  *(int *)((intptr_t)self + 0x274));
        }
        if (*(int *)((intptr_t)self + 0x83d0) != -999) {
          UI_ClipRect((void *)*local_1c,(int *)((intptr_t)self + 0x83d0),0);
        }
        UI_ProcessWindowEvent((void *)*local_1c,arg1);
      }
LAB_005242b4:
      local_14 = local_14 + 1;
      local_1c = local_1c + 1;
    } while (local_14 < *(int *)((intptr_t)self + 0x23c));
  }
  if (*(int *)((intptr_t)self + 0x240) != 0) {
    Surface_SetBounds(arg1,0,0,DAT_00574734,DAT_00574738);
    UI_DrawChildAt(*(void **)((intptr_t)self + 0x240),arg1);
  }
  pvVar2 = *(void **)((intptr_t)self + 0x244);
  if (pvVar2 != (void *)0x0) {
    if (*(int *)((intptr_t)pvVar2 + 0x3c) != 0) {
      Window_GetRect(pvVar2,&local_10.left);
      value6 = *(int *)((intptr_t)self + 0x83d0);
      if (local_10.left <= *(int *)((intptr_t)self + 0x83d0)) {
        value6 = local_10.left;
      }
      *(int *)((intptr_t)self + 0x83d0) = value6;
      value6 = *(int *)((intptr_t)self + 0x83d8);
      if (*(int *)((intptr_t)self + 0x83d8) <= local_10.right) {
        value6 = local_10.right;
      }
      *(int *)((intptr_t)self + 0x83d8) = value6;
      value6 = *(int *)((intptr_t)self + 0x83d4);
      if (local_10.top <= *(int *)((intptr_t)self + 0x83d4)) {
        value6 = local_10.top;
      }
      *(int *)((intptr_t)self + 0x83d4) = value6;
      value6 = *(int *)((intptr_t)self + 0x83dc);
      if (*(int *)((intptr_t)self + 0x83dc) <= local_10.bottom) {
        value6 = local_10.bottom;
      }
      *(int *)((intptr_t)self + 0x83dc) = value6;
    }
    Surface_SetBounds(arg1,0,0,DAT_00574734,DAT_00574738);
    Renderer_FlushTarget(*(void **)((intptr_t)self + 0x244),(intptr_t)arg1);
  }
  Renderer_ComposeSpriteScaled(*(void **)((intptr_t)self + 0x8310),(intptr_t)arg1,-9999,-9999,(LPRECT)0x0);
  return;
}
