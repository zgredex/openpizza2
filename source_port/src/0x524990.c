// Window_DispatchMouseEvent: ported from Pizza Connection 2 at 0x524990.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x524990
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
Window_DispatchMouseEvent(void *self,int arg1,int arg2,int arg3,uint32_t arg4)

{
  void *pvVar1;
  uint32_t uvalue2;
  DWORD DVar3;
  int value4;
  int value5;
  uint32_t *uptr6;
  uint32_t *uptr7;
  
  value4 = arg1;
  _DAT_00584200 = arg2 - *(int *)((intptr_t)self + 0x248);
  _DAT_00584204 = arg3 - *(int *)((intptr_t)self + 0x24c);
  _DAT_005841f8 = arg2;
  *(int *)((intptr_t)self + 0x248) = arg2;
  _DAT_005841fc = arg3;
  *(int *)((intptr_t)self + 0x24c) = arg3;
  _DAT_00584208 = arg4;
  _DAT_0058420c = 0;
  switch(arg1) {
  case 0x200:
    uptr7 = (uint32_t *)0x4;
    if (*(int *)((intptr_t)self + 0x831c) != 0) {
      _DAT_00584220 = arg2;
      _DAT_00584224 = arg3;
      UI_QueueCommand(self,*(int *)((intptr_t)self + 0x8304),0,(intptr_t)self,0x12,0x584220);
    }
    if (*(int *)((intptr_t)self + 0x82dc) != 0) {
      DVar3 = timeGetTime();
      *(DWORD *)((intptr_t)self + 0x82e0) = DVar3 + *(int *)((intptr_t)self + 0x82f4);
      value5 = UI_HitTestExcludingChild
                        (*(void **)((intptr_t)self + 0x82d0),(int *)&DAT_005841f8,
                         *(void **)((intptr_t)self + 0x82dc));
      if (value5 == 0) {
        if ((*(int *)((intptr_t)self + 0x82d0) != 0) &&
           (value5 = Get_Field24(*(int *)((intptr_t)self + 0x82dc)), value5 != 0)) {
          UI_QueueControlCommand
                    (*(void **)((intptr_t)self + 0x82d0),*(int *)(*(int *)((intptr_t)self + 0x82dc) + 4),0xd,0
                    );
        }
        *(uint32_t *)((intptr_t)self + 0x82dc) = 0;
        UI_RefreshChildRect(self);
      }
    }
    break;
  case 0x201:
    uptr7 = (uint32_t *)0x6;
    break;
  case 0x202:
    uptr7 = (uint32_t *)0x7;
    break;
  default:
    goto switchD_005249fc_caseD_203;
  case 0x204:
    uptr7 = (uint32_t *)0x8;
    if (((arg4 & 4) != 0) && (value5 = Object_GetRootType(*(int *)((intptr_t)self + 0xc)), value5 != 0))
    {
      Window_ExportDialog(self,(void *)0x0,(void **)0x0,(int *)&DAT_005841f8);
    }
    break;
  case 0x205:
    uptr7 = (uint32_t *)0x9;
  }
  if (value4 != 0x200) {
    UI_RefreshChildRect(self);
  }
  if ((*(int *)((intptr_t)self + 0x240) != 0) && (*(int *)(*(int *)((intptr_t)self + 0x240) + 0x44) != 0)) {
    if ((*(int **)((intptr_t)self + 0x82d4) != (int *)0x0) && (*(int *)((intptr_t)self + 0x82c8) != 0)) {
      (**(code **)(**(int **)((intptr_t)self + 0x82d4) + 0xc))(5,0,&DAT_005841f8);
      *(uint32_t *)((intptr_t)self + 0x82d4) = 0;
    }
    if (uptr7 == (uint32_t *)0x4) {
      value4 = UI_UpdateHoveredRow(*(void **)((intptr_t)self + 0x240),(int *)&DAT_005841f8);
      if (value4 == 0) {
        return;
      }
      Window_RenderFrame(self);
      return;
    }
    if ((uptr7 == (uint32_t *)0x7) || (uptr7 == (uint32_t *)0x9)) {
      UI_FinishDragAndExpandDirtyRect(*(void **)((intptr_t)self + 0x240),self);
      Window_ReleaseResources(*(int *)((intptr_t)self + 0x240));
      Window_RenderFrame(self);
      return;
    }
    return;
  }
  if (*(int *)((intptr_t)self + 0x22c) != 0) {
    value4 = *(int *)((intptr_t)self + 0x23c) + -1;
    if (-1 < value4) {
      uptr6 = (uint32_t *)((intptr_t)self + value4 * 4 + 0x14);
      do {
        pvVar1 = (void *)*uptr6;
        if (pvVar1 == *(void **)((intptr_t)self + 0x224)) {
          value4 = -1;
          break;
        }
        if ((((pvVar1 != (void *)0x0) && (*(int *)((intptr_t)pvVar1 + 0x4c) != 0)) &&
            (value5 = Rect_ContainsPoint(pvVar1,(int *)&DAT_005841f8), value5 != 0)) &&
           (UI_HitTestChildAtPoint((void *)*uptr6,(int *)&DAT_005841f8,&arg1), arg1 != 0))
        break;
        value4 = value4 + -1;
        uptr6 = uptr6 + -1;
      } while (-1 < value4);
    }
    _DAT_0058420c = 1;
    if (value4 == -1) {
      value4 = UI_HitTestTopChild(*(void **)((intptr_t)self + 0x224),(int *)&DAT_005841f8,
                                 *(void **)((intptr_t)self + 0x22c));
      if (value4 == 0) {
        if (uptr7 != (uint32_t *)0x4) {
          value4 = (**(code **)(**(int **)((intptr_t)self + 0x22c) + 0xc))(uptr7,0,&DAT_005841f8);
          goto LAB_00524c8e;
        }
        value4 = **(int **)((intptr_t)self + 0x22c);
        uptr6 = (uint32_t *)0x5;
      }
      else {
LAB_00524c7b:
        value4 = **(int **)((intptr_t)self + 0x22c);
        uptr6 = uptr7;
      }
      value4 = (**(code **)(value4 + 0xc))(uptr6,0,&DAT_005841f8);
    }
    else {
      if (uptr7 != (uint32_t *)0x4) goto LAB_00524c7b;
      value4 = (**(code **)(**(int **)((intptr_t)self + 0x22c) + 0xc))(5,0,&DAT_005841f8);
    }
LAB_00524c8e:
    if (value4 != 0) {
      return;
    }
    *(uint32_t *)((intptr_t)self + 0x224) = 0;
    *(uint32_t *)((intptr_t)self + 0x22c) = 0;
    if (uptr7 == (uint32_t *)0x7) {
      return;
    }
    arg4 = 0;
    if (uptr7 == (uint32_t *)0x9) {
      return;
    }
  }
  if (uptr7 == (uint32_t *)0x4) {
    value4 = *(int *)((intptr_t)self + 0x23c) + -1;
    if (-1 < value4) {
      uptr6 = (uint32_t *)((intptr_t)self + value4 * 4 + 0x14);
      do {
        pvVar1 = (void *)*uptr6;
        if (pvVar1 != (void *)0x0) {
          if (pvVar1 == *(void **)((intptr_t)self + 0x82c8)) goto LAB_00524cf9;
          value5 = Rect_ContainsPoint(pvVar1,(int *)&DAT_005841f8);
          if (value5 != 0) break;
        }
        value4 = value4 + -1;
        uptr6 = uptr6 + -1;
      } while (-1 < value4);
    }
    if (value4 == -1) {
LAB_00524cf9:
      if ((*(void **)((intptr_t)self + 0x82d4) != (void *)0x0) &&
         (*(void **)((intptr_t)self + 0x82c8) != (void *)0x0)) {
        value4 = UI_HitTestTopChild(*(void **)((intptr_t)self + 0x82c8),(int *)&DAT_005841f8,
                                   *(void **)((intptr_t)self + 0x82d4));
        if (value4 != 0) {
          return;
        }
        (**(code **)(**(int **)((intptr_t)self + 0x82d4) + 0xc))(5,0,&DAT_005841f8);
LAB_00524d57:
        *(uint32_t *)((intptr_t)self + 0x82d4) = 0;
      }
    }
    else if ((*(int **)((intptr_t)self + 0x82d4) != (int *)0x0) && (*(int *)((intptr_t)self + 0x82c8) != 0)) {
      (**(code **)(**(int **)((intptr_t)self + 0x82d4) + 0xc))(5,0,&DAT_005841f8);
      goto LAB_00524d57;
    }
  }
  value4 = *(int *)((intptr_t)self + 0x23c) + -1;
  if (-1 < value4) {
    uptr6 = (uint32_t *)((intptr_t)self + value4 * 4 + 0x14);
    do {
      if (((void *)*uptr6 != (void *)0x0) &&
         (value5 = UI_DispatchMouseToChild(self,uptr7,(int *)&DAT_005841f8,(void *)*uptr6,&arg4)
         , value5 != 0)) {
        if (*(int *)((intptr_t)self + 0x82d4) != 0) {
          uvalue2 = *(uint32_t *)((intptr_t)self + value4 * 4 + 0x14);
          *(uint32_t *)((intptr_t)self + 0x82c8) = uvalue2;
          if (arg4 == 0) {
            *(uint32_t *)((intptr_t)self + 0x224) = 0;
            *(uint32_t *)((intptr_t)self + 0x22c) = 0;
          }
          else {
            *(uint32_t *)((intptr_t)self + 0x224) = uvalue2;
            *(int *)((intptr_t)self + 0x22c) = *(int *)((intptr_t)self + 0x82d4);
          }
        }
        break;
      }
      value4 = value4 + -1;
      uptr6 = uptr6 + -1;
    } while (-1 < value4);
  }
  if (*(int *)((intptr_t)self + 0x8304) != 0) {
    _DAT_00584220 = arg2;
    _DAT_00584224 = arg3;
    if (uptr7 == (uint32_t *)0x6) {
      value4 = 0xf;
    }
    else {
      if (uptr7 == (uint32_t *)0x7) {
        UI_QueueCommand(self,*(int *)((intptr_t)self + 0x8304),0,(intptr_t)self,0x10,0x584220);
        return;
      }
      if (uptr7 == (uint32_t *)0x8) {
        UI_QueueCommand(self,*(int *)((intptr_t)self + 0x8304),0,(intptr_t)self,0x14,0x584220);
        return;
      }
      if (uptr7 != (uint32_t *)0x9) {
        return;
      }
      value4 = 0x15;
    }
    UI_QueueCommand(self,*(int *)((intptr_t)self + 0x8304),0,(intptr_t)self,value4,0x584220);
  }
switchD_005249fc_caseD_203:
  return;
}
