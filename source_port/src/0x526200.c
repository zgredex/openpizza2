// UI_UpdateChildLayout: ported from Pizza Connection 2 at 0x526200.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x526200
#include "pc2_port.h"


void __fastcall UI_UpdateChildLayout(void *arg1)

{
  int *ptr1;
  bool flag2;
  int value3;
  uint32_t *uptr4;
  uint32_t uvalue5;
  void *local_20;
  tagRECT local_1c;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a77b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  UI_SetBackgroundSurfaceEnabled(arg1,0);
  CS_Enter(*(int *)((intptr_t)arg1 + 0x1c8));
  value3 = Object_GetRootType((intptr_t)DAT_0057c5c8);
  if (value3 == 0) {
LAB_00526252:
    flag2 = true;
  }
  else {
    value3 = Object_GetRootType((intptr_t)DAT_0057c5c8);
    if (value3 == 2) goto LAB_00526252;
    flag2 = false;
  }
  if (flag2) {
    *(uint32_t *)((intptr_t)arg1 + 0x1b4) = 0;
    Renderer_ToggleRenderTarget(DAT_0057c5c8);
    SetWindowLongA(*(HWND *)((intptr_t)arg1 + 0x8320),-0x10,-0x79360000);
    ShowWindow(*(HWND *)((intptr_t)arg1 + 0x8320),1);
    MoveWindow(*(HWND *)((intptr_t)arg1 + 0x8320),0,0,*(int *)((intptr_t)arg1 + 0x270),
               *(int *)((intptr_t)arg1 + 0x274),1);
    GetClientRect(*(HWND *)((intptr_t)arg1 + 0x8320),&local_1c);
    MoveWindow(*(HWND *)((intptr_t)arg1 + 0x8320),0,0,
               *(int *)((intptr_t)arg1 + 0x270) * 2 - local_1c.right,
               *(int *)((intptr_t)arg1 + 0x274) * 2 - local_1c.bottom,1);
    if (*(int *)((intptr_t)arg1 + 0x8358) == 0) {
      uvalue5 = Surface_CreateDesc(DAT_0057c5c8,*(uint32_t *)((intptr_t)arg1 + 0x270),
                                 *(uint32_t *)((intptr_t)arg1 + 0x274),(int *)&local_20,0,0x2800);
      *(uint32_t *)((intptr_t)arg1 + 0x1c0) = uvalue5;
      if (local_20 != (void *)0x0) {
        NoOp_Stub();
      }
      Renderer_InitForWindow(DAT_0057c5c8,*(HWND *)((intptr_t)arg1 + 0x8320));
      Sprite_ClearBuffers(*(int **)((intptr_t)arg1 + 0x1c0));
    }
    else {
      local_20 = operator_new(0x11c);
      local_4 = 0;
      if (local_20 == (void *)0x0) {
        uptr4 = (uint32_t *)0x0;
      }
      else {
        uptr4 = Window_Construct(local_20,*(int *)((intptr_t)arg1 + 0x270),
                                  *(int *)((intptr_t)arg1 + 0x274),2);
      }
      local_4 = 0xffffffff;
      *(uint32_t **)((intptr_t)arg1 + 0x1bc) = uptr4;
      Surface_Clear((intptr_t)uptr4);
    }
  }
  else {
    ptr1 = *(int **)((intptr_t)arg1 + 0x1c0);
    if (ptr1 != (int *)0x0) {
      (**(code **)(*ptr1 + 8))(ptr1);
    }
    *(uint32_t *)((intptr_t)arg1 + 0x1c0) = 0;
    if (*(uint32_t **)((intptr_t)arg1 + 0x1bc) != (uint32_t *)0x0) {
      (**(code **)**(uint32_t **)((intptr_t)arg1 + 0x1bc))(1);
    }
    *(uint32_t *)((intptr_t)arg1 + 0x1bc) = 0;
    SetWindowLongA(*(HWND *)((intptr_t)arg1 + 0x8320),-0x10,-0x6a000000);
    Renderer_ToggleRenderTarget(DAT_0057c5c8);
    SetWindowPos(*(HWND *)((intptr_t)arg1 + 0x8320),(HWND)0xffffffff,0,0,0,0,0x43);
  }
  value3 = Object_GetRootType((intptr_t)DAT_0057c5c8);
  if (value3 != 0) {
    value3 = Object_GetRootType((intptr_t)DAT_0057c5c8);
    if (value3 != 2) {
      uvalue5 = 0;
      goto LAB_0052643f;
    }
  }
  uvalue5 = 1;
LAB_0052643f:
  *(uint32_t *)((intptr_t)arg1 + 0x1b4) = uvalue5;
  UI_MarkFullRectDirty(arg1);
  CS_Leave(*(int *)((intptr_t)arg1 + 0x1c8));
  UI_SetBackgroundSurfaceEnabled(arg1,1);
  ExceptionList = pvStack_c;
  return;
}
