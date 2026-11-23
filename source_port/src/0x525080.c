// UI_DispatchMouseToChild: ported from Pizza Connection 2 at 0x525080.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x525080
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint32_t __thiscall
UI_DispatchMouseToChild
          (void *self,uint32_t *arg1,int *arg2,void *arg3,uint32_t *arg4)

{
  void *this_00;
  int value1;
  int *ptr2;
  DWORD DVar3;
  int value4;
  uint32_t uvalue5;
  
  this_00 = arg3;
  if ((arg3 != (void *)0x0) && (*(int *)((intptr_t)arg3 + 0x4c) != 0)) {
    value1 = Rect_ContainsPoint(arg3,arg2);
    if (value1 != 0) {
      if ((*(void **)((intptr_t)self + 0x228) != (void *)0x0) &&
         (*(void **)((intptr_t)self + 0x228) != this_00)) {
        *(uint32_t *)((intptr_t)self + 0x82d4) = 0;
        return 1;
      }
      ptr2 = UI_HitTestChildAtPoint(this_00,arg2,&arg3);
      if (ptr2 != (int *)0x0) {
        if (*(int **)((intptr_t)self + 0x82dc) != ptr2) {
          *(void **)((intptr_t)self + 0x82d0) = this_00;
          *(int **)((intptr_t)self + 0x82dc) = ptr2;
          *(uint32_t *)((intptr_t)self + 0x82f0) = 0;
          DVar3 = timeGetTime();
          *(DWORD *)((intptr_t)self + 0x82e0) = DVar3 + *(int *)((intptr_t)self + 0x82f4);
          value1 = Get_Field24((intptr_t)ptr2);
          if (value1 != 0) {
            value1 = ptr2[1];
            value4 = Object_GetField10((intptr_t)ptr2);
            UI_QueueControlCommand(*(void **)((intptr_t)self + 0x82d0),value1,0xc,value4);
          }
          if (*(int *)((intptr_t)self + 0x82ec) == 0) {
            *(uint32_t *)((intptr_t)self + 0x82f0) = 1;
          }
        }
        if (ptr2[7] == 0) {
          uvalue5 = (**(code **)(*ptr2 + 0xc))(arg1,0,arg2);
          *arg1 = uvalue5;
          *(int **)((intptr_t)self + 0x82d4) = ptr2;
          return 1;
        }
        *arg4 = 0;
        *(int **)((intptr_t)self + 0x82d4) = ptr2;
        return 1;
      }
      if (*(int **)((intptr_t)self + 0x82dc) != (int *)0x0) {
        UI_RefreshChildRect(self);
        if (*(int *)((intptr_t)self + 0x82d0) != 0) {
          value1 = Get_Field24(*(int *)((intptr_t)self + 0x82dc));
          if (value1 != 0) {
            UI_QueueControlCommand
                      (*(void **)((intptr_t)self + 0x82d0),*(int *)(*(int *)((intptr_t)self + 0x82dc) + 4),0xd
                       ,0);
          }
        }
        *(uint32_t *)((intptr_t)self + 0x82dc) = 0;
      }
      *(uint32_t *)((intptr_t)self + 0x82d4) = 0;
      if (arg3 != (void *)0x0) {
        if (arg1 == (uint32_t *)0x7) {
          _DAT_00584228 = *arg2;
          _DAT_0058422c = arg2[1];
          UI_QueueControlCommand(this_00,-1,0x11,0x584228);
          return 1;
        }
        if (arg1 == (uint32_t *)0x9) {
          _DAT_00584228 = *arg2;
          _DAT_0058422c = arg2[1];
          UI_QueueControlCommand(this_00,-1,0x16,0x584228);
        }
        return 1;
      }
    }
  }
  return 0;
}
