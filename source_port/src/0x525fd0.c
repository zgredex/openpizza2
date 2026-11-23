// Window_DispatchWindowMessage: ported from Pizza Connection 2 at 0x525fd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x525fd0
#include "pc2_port.h"

void __thiscall Window_DispatchWindowMessage(void *self,uint32_t arg1,void *arg2,uint32_t arg3)

{
  if (arg1 < 0x1f5) {
    if (arg1 == 500) {
      UI_RemoveObject(arg2,arg3);
      return;
    }
    if (arg1 == 0x100) {
      Window_HandleKeyInput(self,(intptr_t)arg2);
      return;
    }
    if (arg1 == 0x102) {
      Window_HandleKeyInput(self,(intptr_t)arg2);
      return;
    }
    if (arg1 == 0x104) {
      if ((arg2 == (void *)0x58) || (arg2 == (void *)0x73)) {
        if (*(int *)((intptr_t)self + 0x8304) == 0) {
          SetEvent(DAT_0057c0d8);
          return;
        }
        UI_QueueCommand(self,*(int *)((intptr_t)self + 0x8304),0,(intptr_t)self,0x17,(intptr_t)arg2);
        return;
      }
      if (arg2 == (void *)0x79) {
        UI_UpdateChildLayout(self);
        return;
      }
    }
  }
  else {
    switch(arg1) {
    case 0x200:
    case 0x201:
    case 0x202:
    case 0x204:
    case 0x205:
      Window_DispatchMouseEvent(self,arg1,arg3 & 0xffff,arg3 >> 0x10,(uint32_t)arg2);
      return;
    case 0x20a:
      UI_DispatchMouseEvent(self,arg1,(intptr_t)arg2,arg3);
    }
  }
  return;
}
