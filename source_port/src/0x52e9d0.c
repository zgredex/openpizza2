// Dialog_ConstructFixed: ported from Pizza Connection 2 at 0x52e9d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52e9d0
#include "pc2_port.h"


uint32_t * __thiscall
Dialog_ConstructFixed
          (void *self,uint32_t arg1,void *arg2,int arg3,int arg4,int arg5,
          int arg6,uint32_t arg7,uint32_t *arg8,uint32_t arg9,uint32_t arg10,
          uint32_t arg11,uint32_t arg12)

{
  uint32_t uvalue1;
  uint32_t uvalue2;
  uint32_t uvalue3;
  uint32_t *uptr4;
  int value5;
  uint32_t local_28;
  uint32_t local_24;
  void *local_20;
  uint32_t local_1c;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a9ac;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_20 = self;
  Array_Construct((void *)((intptr_t)self + 0x148),0);
  local_4 = 0;
  Array_Construct((void *)((intptr_t)self + 0x2a8),0);
  local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),1);
  *(uint8_t ***)self = &PTR_Dialog_Delete_0055c808;
  SetRect((LPRECT)((intptr_t)self + 0x28),arg3,arg4,arg5,arg6);
  Dialog_InitBase(self,arg2,arg1,arg7);
  *(uint32_t *)((intptr_t)self + 0xfc) = arg9;
  *(uint32_t *)((intptr_t)self + 0x100) = arg10;
  *(uint32_t *)((intptr_t)self + 0x104) = arg11;
  *(uint32_t *)((intptr_t)self + 0x108) = arg12;
  uptr4 = (uint32_t *)((intptr_t)self + 0x114);
  value5 = 8;
  do {
    uvalue1 = *arg8;
    arg8 = arg8 + 1;
    *uptr4 = uvalue1;
    uptr4 = uptr4 + 1;
    value5 = value5 + -1;
  } while (value5 != 0);
  Sprite_GetRenderSize(*(void **)((intptr_t)self + 0x118),&local_24,&local_28);
  uvalue2 = local_28;
  Sprite_GetRenderSize(*(void **)((intptr_t)self + 0x120),&local_24,&local_28);
  uvalue3 = local_24;
  Sprite_GetRenderSize(*(void **)((intptr_t)self + 0x128),&local_24,&local_28);
  Sprite_GetRenderSize(*(void **)((intptr_t)self + 0x130),&local_24,&local_28);
  local_1c = local_24;
  UI_SetWindowBounds(self,arg3,arg4,local_24 + uvalue3 + arg5,uvalue2 + local_28 + arg6);
  *(uint32_t *)((intptr_t)self + 0x1c) = *(int *)((intptr_t)self + 0xc) + uvalue2;
  *(uint32_t *)((intptr_t)self + 0x20) = *(int *)((intptr_t)self + 0x10) - uvalue3;
  *(uint32_t *)((intptr_t)self + 0x18) = *(int *)((intptr_t)self + 8) + local_1c;
  *(uint32_t *)((intptr_t)self + 0x24) = *(int *)((intptr_t)self + 0x14) - local_28;
  *(uint32_t *)((intptr_t)self + 0x2c4) = 0;
  ExceptionList = local_c;
  return self;
}
