// ContextMenu_Construct: ported from Pizza Connection 2 at 0x528570.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x528570
#include "pc2_port.h"


uint32_t * __thiscall
ContextMenu_Construct(void *self,void *arg1,int arg2,uint32_t arg3,int *arg4)

{
  void *pvVar1;
  void *this_00;
  uint32_t *uptr2;
  int value3;
  uint32_t *local_11c;
  CHAR local_110 [260];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  puStack_8 = &LAB_0055a81e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(uint8_t ***)self = &PTR_UI_ContextMenu_Delete_0055c788;
  *(int *)((intptr_t)self + 100) = arg2;
  *(uint32_t *)((intptr_t)self + 0x50) = 0;
  *(uint32_t *)((intptr_t)self + 0x54) = 0;
  *(uint32_t *)((intptr_t)self + 0x68) = 0;
  pvVar1 = *(void **)(arg2 + 0x10);
  local_11c = (uint32_t *)((intptr_t)self + 4);
  uptr2 = local_11c;
  for (value3 = 9; value3 != 0; value3 = value3 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  value3 = 0;
  while( true ) {
    local_4 = 0xffffffff;
    String_Format(local_110,(uint8_t *)s__s__02d_spr_00573b9c,arg3);
    this_00 = operator_new(0x50);
    local_4 = 0;
    if (this_00 == (void *)0x0) {
      uptr2 = (uint32_t *)0x0;
    }
    else {
      uptr2 = Sprite_Load(this_00,arg1,pvVar1,local_110,arg4,0,(void *)0x0,0);
    }
    local_4 = 0xffffffff;
    *local_11c = uptr2;
    if ((arg4 != (int *)0x0) && (*arg4 != 0)) break;
    value3 = value3 + 1;
    local_11c = local_11c + 1;
    if (8 < value3) {
      *(uint32_t *)((intptr_t)self + 0x38) = 10;
      *(uint32_t *)((intptr_t)self + 0x3c) = 10;
      *(uint32_t *)((intptr_t)self + 0x28) = 0x50;
      *(uint32_t *)((intptr_t)self + 0x2c) = 200;
      *(uint32_t *)((intptr_t)self + 0x44) = 0;
      *(uint32_t *)((intptr_t)self + 0x54) = 0;
      *(uint32_t *)((intptr_t)self + 0x5c) = 0;
      *(uint32_t *)((intptr_t)self + 0x60) = 0xffffff;
      *(uint32_t *)((intptr_t)self + 0x68) = 0;
      *(uint32_t *)((intptr_t)self + 0x48) = 0xffffffff;
      Sprite_GetRenderSize
                (*(void **)((intptr_t)self + 4),(uint32_t *)((intptr_t)self + 0x30),(uint32_t *)((intptr_t)self + 0x34));
      uptr2 = Renderer_CreateChild(arg1);
      *(uint32_t **)((intptr_t)self + 0x50) = uptr2;
      ExceptionList = local_c;
      return self;
    }
  }
  if (uptr2 != (uint32_t *)0x0) {
    (**(code **)*uptr2)(1);
  }
  *(uint32_t *)((intptr_t)self + value3 * 4 + 4) = 0;
  ExceptionList = local_c;
  return self;
}
