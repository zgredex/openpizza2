// Game_ResizeZoomSurfaces: ported from Pizza Connection 2 at 0x4ea230.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ea230
#include "pc2_port.h"


void __thiscall
Game_ResizeZoomSurfaces
          (void *self,void *arg1,uint32_t arg2,uint32_t arg3,int arg4,uint32_t arg5,
          uint32_t arg6)

{
  void *pvVar1;
  uint32_t *uptr2;
  uint32_t uvalue3;
  int value4;
  uint32_t uvalue5;
  uint32_t uvalue6;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t uStack_4;
  
  uvalue6 = arg3;
  uvalue5 = arg2;
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00559e86;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if ((*(void **)((intptr_t)self + 0x2f884) != (void *)0x0) &&
     ((ExceptionList = &pvStack_c,
      Sprite_GetSize(*(void **)((intptr_t)self + 0x2f884),(int *)&arg3,(int *)&arg2),
      arg3 != uvalue5 || (arg2 != uvalue6)))) {
    if (*(uint32_t **)((intptr_t)self + 0x2f884) != (uint32_t *)0x0) {
      (**(code **)**(uint32_t **)((intptr_t)self + 0x2f884))(1);
    }
    *(uint32_t *)((intptr_t)self + 0x2f884) = 0;
  }
  if ((DAT_0058072c != (uint32_t *)0x0) &&
     ((Object_GetPair4(DAT_0058072c,&arg3,&arg2), arg3 != uvalue5 || (arg2 != uvalue6)))) {
    if (DAT_0058072c != (uint32_t *)0x0) {
      (**(code **)*DAT_0058072c)(1);
    }
    DAT_0058072c = (uint32_t *)0x0;
  }
  if ((uvalue5 & 1) != 0) {
    uvalue5 = uvalue5 + 1;
  }
  if (DAT_0058072c == (uint32_t *)0x0) {
    pvVar1 = operator_new(0x18);
    uStack_4 = 0;
    if (pvVar1 == (void *)0x0) {
      DAT_0058072c = (uint32_t *)0x0;
    }
    else {
      DAT_0058072c = Gfx_RectList_Construct(pvVar1,uvalue5,uvalue6,0xf);
    }
    uStack_4 = 0xffffffff;
  }
  if (*(int *)((intptr_t)self + 0x2f884) == 0) {
    pvVar1 = operator_new(0x50);
    uStack_4 = 1;
    if (pvVar1 == (void *)0x0) {
      uptr2 = (uint32_t *)0x0;
    }
    else {
      uptr2 = Sprite_CreateRaw(pvVar1,uvalue5 * 3,uvalue6,0,8,0);
    }
    uStack_4 = 0xffffffff;
    *(uint32_t **)((intptr_t)self + 0x2f884) = uptr2;
  }
  if (*(int *)((intptr_t)self + 0x2f87c) == 0) {
    uptr2 = Renderer_CreateChild(arg1);
    *(uint32_t **)((intptr_t)self + 0x2f87c) = uptr2;
  }
  value4 = uvalue5 * 6;
  uvalue3 = Sprite_GetPixelBuffer(*(void **)((intptr_t)self + 0x2f884));
  Surface_Configure(*(void **)((intptr_t)self + 0x2f87c),uvalue3,(uint16_t)uvalue5,(uint16_t)uvalue6,value4);
  if (arg4 == 0) {
    *(uint32_t *)((intptr_t)self + 0x2f888) = arg5;
    *(uint32_t *)((intptr_t)self + 0x2f88c) = arg6;
    ExceptionList = pvStack_c;
    return;
  }
  *(int *)((intptr_t)self + 0x2f880) = arg4;
  *(uint32_t *)((intptr_t)self + 0x2f88c) = arg6;
  *(uint32_t *)((intptr_t)self + 0x2f888) = arg5;
  ExceptionList = pvStack_c;
  return;
}
