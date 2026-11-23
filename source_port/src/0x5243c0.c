// Window_RenderFrame: ported from Pizza Connection 2 at 0x5243c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5243c0
#include "pc2_port.h"

void __fastcall Window_RenderFrame(void *arg1)

{
  LPRECT lprc;
  void *self;
  uint16_t *uptr1;
  DWORD DVar2;
  int value3;
  int value4;
  int value5;
  HWND pHVar6;
  uint32_t uvalue7;
  HDC pHVar8;
  uint16_t *uptr9;
  int value10;
  int value11;
  int value12;
  
  DVar2 = WaitForSingleObject(DAT_0057c0d8,0);
  if (DVar2 == 0) {
    return;
  }
  lprc = (LPRECT)((intptr_t)arg1 + 0x83d0);
  SetRect(lprc,0,0,0,0);
  CS_Enter(*(int *)((intptr_t)arg1 + 0x1c8));
  if (*(int *)((intptr_t)arg1 + 0x284) == 0) {
    CS_Leave(*(int *)((intptr_t)arg1 + 0x1c8));
    return;
  }
  value3 = UI_RenderScene((intptr_t)arg1);
  if (value3 == 0) {
    CS_Leave(*(int *)((intptr_t)arg1 + 0x1c8));
    return;
  }
  if (*(int *)((intptr_t)arg1 + 8) != 0) {
    if (*(int *)((intptr_t)arg1 + 0x1b4) == 0) {
      if (*(int *)((intptr_t)arg1 + 0x1bc) == 0) {
        Sprite_ClearBuffers(*(int **)((intptr_t)arg1 + 0x1c0));
        value3 = UI_RenderScene((intptr_t)arg1);
        if (value3 == 0) {
          CS_Leave(*(int *)((intptr_t)arg1 + 0x1c8));
          return;
        }
      }
      else {
        Surface_Clear(*(int *)((intptr_t)arg1 + 0x1bc));
      }
    }
    else {
      Surface_ClearRows(*(int *)((intptr_t)arg1 + 0xc));
    }
  }
  self = *(void **)((intptr_t)arg1 + 0x83ac);
  if ((self == (void *)0x0) || (*(int *)((intptr_t)self + 8) == 0)) {
    UI_ProcessChildEvent(arg1,*(void **)((intptr_t)arg1 + 0xc));
  }
  else {
    Screen_AnimateTileWipe(self,*(uint32_t *)((intptr_t)arg1 + 0xc));
    SetRect(lprc,0,0,800,600);
  }
  if (*(int *)((intptr_t)arg1 + 0x83b8) != 0) {
    if (*(void **)((intptr_t)arg1 + 0x83ac) != (void *)0x0) {
      Screen_BeginTileWipeTransition
                (*(void **)((intptr_t)arg1 + 0x83ac),*(uint32_t *)((intptr_t)arg1 + 0xc),500);
    }
    UI_QueueChildCommand(arg1,0x20,0);
    *(uint32_t *)((intptr_t)arg1 + 0x83b8) = 0;
  }
  if (DAT_00584504 == 0) goto LAB_005246b9;
  if (*(int *)((intptr_t)arg1 + 0x1b4) == 0) {
    if (*(int *)((intptr_t)arg1 + 0x83a8) != 0) {
      Sprite_Draw(*(void **)((intptr_t)arg1 + 0x839c),*(int *)((intptr_t)arg1 + 0xc),
                  *(uint32_t **)((intptr_t)arg1 + 0x83a0),*(int *)((intptr_t)arg1 + 0x83a4));
    }
    value3 = *(int *)((intptr_t)arg1 + 0x1bc);
    if (value3 != 0) {
      uvalue7 = lprc->left;
      value4 = *(int *)(value3 + 4);
      uptr1 = *(uint16_t **)(value3 + 8);
      if (uvalue7 == 0xfffffc19) {
        value3 = *(int *)(value3 + 0x18);
        pHVar6 = *(HWND *)((intptr_t)arg1 + 0x8320);
        pHVar8 = (HDC)0x0;
        uvalue7 = 0;
        value5 = value4;
        uptr9 = uptr1;
      }
      else {
        pHVar8 = *(HDC *)((intptr_t)arg1 + 0x83d4);
        value3 = *(int *)(value3 + 0x18);
        pHVar6 = *(HWND *)((intptr_t)arg1 + 0x8320);
        value5 = *(int *)((intptr_t)arg1 + 0x83d8) - uvalue7;
        uptr9 = (uint16_t *)(*(int *)((intptr_t)arg1 + 0x83dc) - (intptr_t)pHVar8);
      }
      Gfx_BlitClipped16(DAT_0057c5c8,pHVar6,value3,uvalue7,pHVar8,value5,(intptr_t)uptr9,value4,uptr1,
                        (HDC)0x0,-1,(uint16_t *)0xffffffff);
      if (*(int *)((intptr_t)arg1 + 0x83bc) != 0) {
        Gfx_BlitClipped16(DAT_0057c5c8,*(HWND *)((intptr_t)arg1 + 0x8320),
                          *(int *)(*(int *)((intptr_t)arg1 + 0x1bc) + 0x18),
                          *(uint32_t *)((intptr_t)arg1 + 0x83c0),*(HDC *)((intptr_t)arg1 + 0x83c4),
                          *(int *)((intptr_t)arg1 + 0x83c8) - *(uint32_t *)((intptr_t)arg1 + 0x83c0),
                          *(int *)((intptr_t)arg1 + 0x83cc) - (intptr_t)*(HDC *)((intptr_t)arg1 + 0x83c4),
                          value4,uptr1,(HDC)0x0,-1,(uint16_t *)0xffffffff);
      }
      goto LAB_005246b9;
    }
    value3 = lprc->left;
    if (value3 == -999) {
      value12 = *(int *)((intptr_t)arg1 + 0x1c0);
      value4 = *(int *)((intptr_t)arg1 + 0x274);
      value5 = *(int *)((intptr_t)arg1 + 0x270);
      value11 = 0;
      goto LAB_005246ad;
    }
    value12 = *(int *)((intptr_t)arg1 + 0x1c0);
    value10 = *(int *)((intptr_t)arg1 + 0x83d4);
    value4 = *(int *)((intptr_t)arg1 + 0x83dc) - value10;
    value11 = 0;
    value5 = *(int *)((intptr_t)arg1 + 0x83d8) - value3;
  }
  else {
    if (*(int *)((intptr_t)arg1 + 0x83a8) != 0) {
      Sprite_Draw(*(void **)((intptr_t)arg1 + 0x839c),*(int *)((intptr_t)arg1 + 0xc),
                  *(uint32_t **)((intptr_t)arg1 + 0x83a0),*(int *)((intptr_t)arg1 + 0x83a4));
    }
    Renderer_FlipPrimarySurface(*(int *)((intptr_t)arg1 + 0xc));
    value3 = lprc->left;
    if (value3 == -999) {
      value4 = *(int *)((intptr_t)arg1 + 0x274);
      value5 = *(int *)((intptr_t)arg1 + 0x270);
      value12 = 0;
      value11 = 1;
LAB_005246ad:
      value10 = 0;
      value3 = 0;
    }
    else {
      value10 = *(int *)((intptr_t)arg1 + 0x83d4);
      value12 = 0;
      value4 = *(int *)((intptr_t)arg1 + 0x83dc) - value10;
      value11 = 1;
      value5 = *(int *)((intptr_t)arg1 + 0x83d8) - value3;
    }
  }
  Surface_BlitRectRetry(*(void **)((intptr_t)arg1 + 0xc),value3,value10,value5,value4,value11,value12);
LAB_005246b9:
  *(uint32_t *)((intptr_t)arg1 + 0x234) = 0;
  CS_Leave(*(int *)((intptr_t)arg1 + 0x1c8));
  return;
}
