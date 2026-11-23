// Renderer_InitForWindow: ported from Pizza Connection 2 at 0x539f90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x539f90
#include "pc2_port.h"

struct pc2_obj_0x539f90_hWnd { intptr_t unused; };
uint32_t __thiscall Renderer_InitForWindow(char *self,HWND arg1)

{
  int *ptr1;
  struct pc2_obj_0x539f90_hWnd *hWnd;
  int value2;
  int *unaff_EDI;
  uint32_t uvalue3;
  
  hWnd = arg1;
  GetClientRect(arg1,(LPRECT)((intptr_t)self + 0x84));
  ClientToScreen(hWnd,(LPPOINT)((intptr_t)self + 0x84));
  ClientToScreen(hWnd,(LPPOINT)((intptr_t)self + 0x8c));
  uvalue3 = 0;
  value2 = (**(code **)(*(int *)**(uint32_t **)((intptr_t)self + 0x40) + 0x10))
                    ((int *)**(uint32_t **)((intptr_t)self + 0x40),0,&arg1,0);
  if (value2 < 0) {
    return 0;
  }
  (**(code **)(*unaff_EDI + 0x20))(unaff_EDI,0);
  ptr1 = *(int **)(*(int *)((intptr_t)self + 0x40) + 4);
  (**(code **)(*ptr1 + 0x70))(ptr1,uvalue3);
  (**(code **)(hWnd->unused + 8))(hWnd);
  *(uint32_t *)((intptr_t)self + 0x94) = 1;
  Renderer_CopyStateToChildren((intptr_t)self);
  return 1;
}
