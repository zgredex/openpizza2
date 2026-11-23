// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x527e20.c:10:3: error: use of undeclared identifier 'tagPOINT'
// Window_SetCursorPosition: ported from Pizza Connection 2 at 0x527e20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x527e20
#include "pc2_port.h"

void __thiscall Window_SetCursorPosition(void *self,int arg1,int arg2,int arg3,int arg4)

{
  uint32_t uvalue1;
  tagPOINT local_8;
  
  local_8.x = arg1;
  *(int *)((intptr_t)self + 0x248) = arg1;
  local_8.y = arg2;
  *(int *)((intptr_t)self + 0x24c) = arg2;
  ClientToScreen(*(HWND *)((intptr_t)self + 0x8320),&local_8);
  SetCursorPos(local_8.x,local_8.y);
  if ((arg3 != 0) &&
     (uvalue1 = *(uint32_t *)((intptr_t)self + 0x32b4), uvalue1 != *(uint32_t *)((intptr_t)self + 0x32b8))) {
    do {
      if (*(int *)((intptr_t)self + uvalue1 * 0xc + 0x2b4) == 0x200) {
        *(uint32_t *)((intptr_t)self + uvalue1 * 0xc + 0x2b4) = 0;
      }
      uvalue1 = uvalue1 + 1 & 0x3ff;
    } while (uvalue1 != *(uint32_t *)((intptr_t)self + 0x32b8));
  }
  if (arg4 != 0) {
    Window_DispatchMouseEvent(self,0x200,*(int *)((intptr_t)self + 0x248),*(int *)((intptr_t)self + 0x24c),0);
  }
  return;
}
