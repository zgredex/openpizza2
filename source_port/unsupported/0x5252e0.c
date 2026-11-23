// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x5252e0.c:20:3: error: use of undeclared identifier 'tagPAINTSTRUCT'
// Window_HandleMessage: ported from Pizza Connection 2 at 0x5252e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5252e0
#include "pc2_port.h"

LRESULT __thiscall
Window_HandleMessage(void *self,HWND arg1,uint32_t arg2,WPARAM arg3,HCURSOR arg4)

{
  uint16_t *uptr1;
  HDC pHVar2;
  BOOL BVar3;
  uint32_t uvalue4;
  HMENU hMenu;
  LRESULT LVar5;
  uint32_t *uptr6;
  int value7;
  tagRECT local_60;
  tagRECT local_50;
  tagPAINTSTRUCT local_40;
  
  if (arg2 < 0x105) {
    if (arg2 == 0x104) {
      if ((arg3 == 0x58) || (arg3 == 0x73)) {
        Window_HandleInputMessage(self,1,0x104,arg3,(uint32_t)arg4);
        return 0;
      }
      LVar5 = DefWindowProcA(arg1,0x104,arg3,(LPARAM)arg4);
      return LVar5;
    }
    if (arg2 < 0x15) {
      if (arg2 == 0x14) {
        return 1;
      }
      switch(arg2) {
      case 2:
        UI_SetBackgroundSurfaceEnabled(self,0);
        SetWindowLongA(*(HWND *)((intptr_t)self + 0x8320),-0x15,0);
        *(uint32_t *)((intptr_t)self + 0x8320) = 0;
        SetEvent(DAT_0057c0d8);
        PostQuitMessage(0);
        return 0;
      case 3:
        goto switchD_00525321_caseD_3;
      default:
        goto switchD_00525321_caseD_4;
      case 0xf:
        GetUpdateRect(arg1,&local_50,0);
        pHVar2 = BeginPaint(arg1,&local_40);
        if ((local_50.left != 0) || (local_50.right != 0)) {
          Window_BlitToDC(self,(uint32_t *)&local_50,pHVar2);
        }
        EndPaint(arg1,&local_40);
        return 0;
      case 0x10:
        DestroyWindow(arg1);
        return 0;
      }
    }
    switch(arg2) {
    case 0x1c:
      if (DAT_00584504 == 1) {
        Renderer_RestoreDisplay(*(int *)((intptr_t)self + 0xc));
        UI_MarkFullRectDirty(self);
        return 0;
      }
      break;
    default:
      goto switchD_00525321_caseD_4;
    case 0x7e:
switchD_00525321_caseD_3:
      BVar3 = IsIconic(arg1);
      if (BVar3 == 0) {
        local_60.left = BVar3;
        local_60.top = BVar3;
        ClientToScreen(arg1,(LPPOINT)&local_60);
        Window_SetRectAndUpdateChildren(DAT_0057c5c8,local_60.left,local_60.top);
      }
      if (arg2 == 3) {
        GetWindowRect(arg1,(LPRECT)&DAT_00573d38);
        return 0;
      }
      break;
    case 0x100:
      value7 = 0;
      if ((short)DAT_00573cc8 != 0) {
        uptr6 = &DAT_00573cc8;
        uvalue4 = DAT_00573cc8;
        do {
          if ((short)uvalue4 == (short)arg3) {
            Window_HandleInputMessage
                      (self,1,arg2,(intptr_t)*(short *)((intptr_t)&DAT_00573cc8 + value7 * 4 + 2),0);
            return 0;
          }
          uptr1 = (uint16_t *)(uptr6 + 1);
          uvalue4 = (uint32_t)*uptr1;
          uptr6 = uptr6 + 1;
          value7 = value7 + 1;
        } while (*uptr1 != 0);
      }
      LVar5 = DefWindowProcA(arg1,arg2,arg3,(LPARAM)arg4);
      return LVar5;
    case 0x102:
      Window_HandleInputMessage(self,1,arg2,arg3,(uint32_t)arg4);
      return 0;
    }
    return 0;
  }
  if (0x204 < arg2) {
    if (arg2 == 0x205) {
      Window_HandleInputMessage(self,1,0x205,arg3,(uint32_t)arg4);
      return 0;
    }
    if (arg2 == 0x20a) {
      Window_HandleInputMessage(self,1,0x20a,arg3,(uint32_t)arg4);
      return 1;
    }
    if (arg2 == 0x400) {
      SetClassLongA(*(HWND *)((intptr_t)self + 0x8320),-0xc,(LONG)arg4);
      SetCursor(arg4);
      SetEvent(*(HANDLE *)((intptr_t)self + 0x8354));
      return 0;
    }
switchD_00525321_caseD_4:
    LVar5 = DefWindowProcA(arg1,arg2,arg3,(LPARAM)arg4);
    return LVar5;
  }
  if (arg2 == 0x204) {
    Window_HandleInputMessage(self,0,0x204,arg3,(uint32_t)arg4);
    return 0;
  }
  switch(arg2) {
  case 0x112:
    uvalue4 = arg3 & 0xfff0;
    if (uvalue4 < 0x4301) {
      if (uvalue4 == 0x4300) {
        hMenu = GetSystemMenu(arg1,0);
        if (*(int *)((intptr_t)self + 8) == 0) {
          CheckMenuItem(hMenu,0x4300,8);
          UI_SetMenuToggle(self,1);
          return 0;
        }
        CheckMenuItem(hMenu,0x4300,0);
        UI_SetMenuToggle(self,0);
        return 0;
      }
      if (uvalue4 == 0x4200) {
        Window_ToggleVisibility(DAT_0057c1e0);
        return 0;
      }
      if (uvalue4 == 0x4210) {
        Dialog_SetItemText((intptr_t)DAT_0057c1e0);
        return 0;
      }
    }
    else if (uvalue4 == 0x4310) {
      GetWindowRect(arg1,&local_60);
      MoveWindow(arg1,0,0,local_60.right - local_60.left,local_60.bottom - local_60.top,1);
      Window_MoveToSidePanel((intptr_t)DAT_0057c1e0);
      return 0;
    }
    LVar5 = DefWindowProcA(arg1,arg2,arg3,(LPARAM)arg4);
    return LVar5;
  default:
    goto switchD_00525321_caseD_4;
  case 0x200:
    if (DAT_00584230 != 0) {
      DAT_00584230 = 0;
      Window_HandleInputMessage(self,0,arg2,arg3,(uint32_t)arg4);
      return 0;
    }
    break;
  case 0x201:
    SetCapture(arg1);
    break;
  case 0x202:
    ReleaseCapture();
    Window_HandleInputMessage(self,1,arg2,arg3,(uint32_t)arg4);
    return 0;
  }
  Window_HandleInputMessage(self,0,arg2,arg3,(uint32_t)arg4);
  return 0;
}
