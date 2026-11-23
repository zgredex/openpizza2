// Window_HandleInputMessage: ported from Pizza Connection 2 at 0x525cf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x525cf0
#include "pc2_port.h"

void __thiscall
Window_HandleInputMessage(void *self,int arg1,int arg2,uint32_t arg3,uint32_t arg4)

{
  int value1;
  int value2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  uint32_t uvalue5;
  tagRECT local_10;
  
  value1 = arg2;
  if (((arg2 != 0x200) || (*(int *)((intptr_t)self + 0x284) == 0)) || (DAT_00584504 == 0))
  goto LAB_00525e95;
  uvalue5 = arg4 & 0xffff;
  uvalue4 = arg4 >> 0x10;
  if (*(int *)(*(int *)((intptr_t)self + 0x8310) + 0x14) == 0) goto LAB_00525e95;
  CS_Enter(*(int *)((intptr_t)self + 0x1c8));
  if (*(int *)((intptr_t)self + 0x1b4) == 0) {
    if (*(void **)((intptr_t)self + 0x1bc) == (void *)0x0) {
      uvalue3 = Surface_GetDescription
                        (*(void **)((intptr_t)self + 0xc),*(int **)((intptr_t)self + 0x1c0),&arg2);
      Surface_Configure(*(void **)((intptr_t)self + 0xc),uvalue3,(uint16_t)*(uint32_t *)((intptr_t)self + 0x270)
                        ,(uint16_t)*(uint32_t *)((intptr_t)self + 0x274),arg2);
      Surface_IsReady(*(int **)((intptr_t)self + 0x1c0));
      value2 = Renderer_ComposeSpriteScaled
                        (*(void **)((intptr_t)self + 0x8310),*(int *)((intptr_t)self + 0xc),uvalue5,uvalue4,
                         &local_10);
      if (value2 != 0) {
        value2 = *(int *)((intptr_t)self + 0x1c0);
        goto LAB_00525e68;
      }
    }
    else {
      Surface_ConfigureFromOwner(*(void **)((intptr_t)self + 0x1bc),*(void **)((intptr_t)self + 0xc));
      value2 = Renderer_ComposeSpriteScaled
                        (*(void **)((intptr_t)self + 0x8310),*(int *)((intptr_t)self + 0xc),uvalue5,uvalue4,
                         &local_10);
      if (value2 != 0) {
        value2 = *(int *)((intptr_t)self + 0x1bc);
        Gfx_BlitClipped16(DAT_0057c5c8,*(HWND *)((intptr_t)self + 0x8320),*(int *)(value2 + 0x18),
                          local_10.left,(HDC)local_10.top,local_10.right - local_10.left,
                          local_10.bottom - local_10.top,*(int *)(value2 + 4),*(uint16_t **)(value2 + 8)
                          ,(HDC)0x0,-1,(uint16_t *)0xffffffff);
      }
    }
  }
  else {
    Surface_LockAndMark(*(void **)((intptr_t)self + 0xc));
    value2 = Renderer_ComposeSpriteScaled
                      (*(void **)((intptr_t)self + 0x8310),*(int *)((intptr_t)self + 0xc),uvalue5,uvalue4,
                       &local_10);
    Surface_ReleaseThunk(*(int *)((intptr_t)self + 0xc));
    if (value2 != 0) {
      value2 = 0;
LAB_00525e68:
      Surface_BlitRectRetry
                (*(void **)((intptr_t)self + 0xc),local_10.left,local_10.top,
                 local_10.right - local_10.left,local_10.bottom - local_10.top,0,value2);
    }
  }
  CS_Leave(*(int *)((intptr_t)self + 0x1c8));
LAB_00525e95:
  if (arg1 == 0) {
    uvalue4 = *(uint32_t *)((intptr_t)self + 0x32b4);
    if (uvalue4 != *(uint32_t *)((intptr_t)self + 0x32b8)) {
      while (uvalue4 = uvalue4 + 1 & 0x3ff, uvalue4 != *(uint32_t *)((intptr_t)self + 0x32b8)) {
        if (*(int *)((intptr_t)self + uvalue4 * 0xc + 0x2b4) == value1) {
          *(int *)((intptr_t)self + uvalue4 * 0xc + 0x2b4) = value1;
          *(uint32_t *)((intptr_t)self + (uvalue4 * 3 + 0xae) * 4) = arg3;
          *(uint32_t *)((intptr_t)self + uvalue4 * 0xc + 700) = arg4;
          return;
        }
      }
    }
  }
  if ((*(int *)((intptr_t)self + 0x32b8) + 1U & 0x3ff) != *(uint32_t *)((intptr_t)self + 0x32b4)) {
    if (value1 == 0x202) {
      if (*(int *)((intptr_t)self + 0x8350) == 0) {
        return;
      }
      *(uint32_t *)((intptr_t)self + 0x8350) = 0;
    }
    else if (value1 == 0x205) {
      if (*(int *)((intptr_t)self + 0x834c) == 0) {
        return;
      }
      *(uint32_t *)((intptr_t)self + 0x834c) = 0;
    }
    else if (value1 == 0x201) {
      *(uint32_t *)((intptr_t)self + 0x8350) = 1;
    }
    else if (value1 == 0x204) {
      *(uint32_t *)((intptr_t)self + 0x834c) = 1;
    }
    *(int *)((intptr_t)self + *(int *)((intptr_t)self + 0x32b8) * 0xc + 0x2b4) = value1;
    *(uint32_t *)((intptr_t)self + (*(int *)((intptr_t)self + 0x32b8) + 0x3a) * 0xc) = arg3;
    *(uint32_t *)((intptr_t)self + *(int *)((intptr_t)self + 0x32b8) * 0xc + 700) = arg4;
    *(uint32_t *)((intptr_t)self + 0x32b8) = *(int *)((intptr_t)self + 0x32b8) + 1U & 0x3ff;
  }
  return;
}
