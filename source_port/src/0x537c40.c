// Renderer_ConstructRoot: ported from Pizza Connection 2 at 0x537c40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x537c40
#include "pc2_port.h"

uint32_t * __thiscall
Renderer_ConstructRoot(void *self,uint32_t arg1,int arg2,int *arg3)

{
  uint32_t *uptr1;
  HWND hWnd;
  tagRECT *lpRect;
  tagRECT local_10;
  
  *(uint8_t ***)self = &PTR_Renderer_Delete_0055c818;
  *(uint8_t *)((intptr_t)self + 0x30) = 0;
  *(uint32_t *)((intptr_t)self + 0x98) = 0;
  Surface_ResetFlags((intptr_t)self);
  uptr1 = operator_new(0x14);
  *(uint32_t **)((intptr_t)self + 0x40) = uptr1;
  *uptr1 = 0;
  uptr1[1] = 0;
  uptr1[2] = 0;
  uptr1[3] = 0;
  uptr1[4] = 0;
  *(uint32_t *)((intptr_t)self + 0x80) = 1;
  *(uint32_t *)(*(int *)((intptr_t)self + 0x40) + 8) = 0;
  *(uint8_t *)((intptr_t)self + 0x18) = 0;
  *(uint32_t *)((intptr_t)self + 0x2c) = 0;
  **(uint32_t **)((intptr_t)self + 0x40) = 0;
  *(uint32_t *)(*(int *)((intptr_t)self + 0x40) + 4) = 0;
  *(uint32_t *)((intptr_t)self + 0x44) = arg1;
  *(uint32_t *)((intptr_t)self + 0x50) = 0;
  *(int *)((intptr_t)self + 0x4c) = arg2;
  *(uint32_t *)((intptr_t)self + 0x48) = 0;
  *(uint32_t *)((intptr_t)self + 0x54) = 0;
  *(uint32_t *)((intptr_t)self + 0x58) = 1;
  *(uint32_t *)((intptr_t)self + 0x5c) = 0;
  *(uint32_t *)((intptr_t)self + 0x60) = 0;
  *(uint32_t *)((intptr_t)self + 0x14) = 0;
  *(uint32_t *)((intptr_t)self + 0x78) = 0;
  *(uint32_t *)((intptr_t)self + 0x7c) = 0;
  *(uint32_t *)((intptr_t)self + 0x84) = 0;
  *(uint32_t *)((intptr_t)self + 0x88) = 0;
  *(uint32_t *)((intptr_t)self + 0x8c) = 0;
  *(uint32_t *)((intptr_t)self + 0x90) = 0;
  *(uint32_t *)((intptr_t)self + 0x94) = 0;
  if (arg2 != 2) {
    *arg3 = 0;
    Surface_InitPixelFormat(self,arg3,1);
    if (*arg3 != 0) {
      return self;
    }
    lpRect = &local_10;
    hWnd = GetDesktopWindow();
    GetWindowRect(hWnd,lpRect);
    *(short *)((intptr_t)self + 0x1c) = (short)(local_10.bottom - local_10.top);
    *(short *)((intptr_t)self + 0x1a) = (short)(local_10.right - local_10.left);
    SetRect((LPRECT)((intptr_t)self + 100),0,0,local_10.right - local_10.left & 0xffff,
            local_10.bottom - local_10.top & 0xffff);
    Surface_Reset((intptr_t)self);
  }
  *(uint8_t *)((intptr_t)self + 0x30) = 1;
  return self;
}
