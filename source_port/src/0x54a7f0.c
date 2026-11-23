// Window_MoveToRect: ported from Pizza Connection 2 at 0x54a7f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54a7f0
#include "pc2_port.h"

void __thiscall Window_MoveToRect(void *self,int *arg1)

{
  if (*(HWND *)((intptr_t)self + 4) != (HWND)0x0) {
    MoveWindow(*(HWND *)((intptr_t)self + 4),*arg1,arg1[1],arg1[2] - *arg1,
               arg1[3] - arg1[1],1);
  }
  return;
}
