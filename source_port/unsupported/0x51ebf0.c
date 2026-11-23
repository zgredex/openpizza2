// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x51ebf0.c:11:33: error: redefinition of 'arg4' with a different type: 'struct pc2_obj_0x51ebf0_arg4 *' vs 'LPRECT' (aka 'struct tagRECT *')
// Renderer_ComposeSpriteScaled: ported from Pizza Connection 2 at 0x51ebf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x51ebf0
#include "pc2_port.h"

struct pc2_obj_0x51ebf0_arg4 { intptr_t bottom; intptr_t left; intptr_t right; intptr_t top; };
uint32_t __thiscall
Renderer_ComposeSpriteScaled(void *self,int arg1,int arg2,int arg3,LPRECT arg4)

{
  struct pc2_obj_0x51ebf0_arg4 *arg4;
  int xLeft;
  void *this_00;
  uint32_t *uptr1;
  uint32_t *uptr2;
  uint32_t *uptr3;
  int value4;
  int value5;
  uint32_t uvalue6;
  uint32_t local_24;
  int local_20;
  uint32_t local_1c;
  int local_18;
  int local_14;
  int local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0055a51b;
  local_c = ExceptionList;
  value5 = *(int *)((intptr_t)self + 0x18);
  if (*(int *)((intptr_t)self + 0x14) == 0) {
    return 0;
  }
  ExceptionList = &local_c;
  Sprite_GetSize(*(void **)self,(int *)&local_24,&local_20);
  if (*(void **)((intptr_t)self + 4) == (void *)0x0) {
    local_18 = 0;
    local_1c = 0;
  }
  else {
    Sprite_GetSize(*(void **)((intptr_t)self + 4),(int *)&local_1c,&local_18);
  }
  Sprite_GetHotspot(*(void **)self,&local_14,&local_10);
  if (arg2 == -9999) {
    if ((local_1c == local_24) && (local_18 == local_20)) {
      value5 = 0;
    }
    else {
      *(uint32_t *)((intptr_t)self + 0xc) = *(uint32_t *)(*(int *)((intptr_t)self + 8) + 0x248);
      *(uint32_t *)((intptr_t)self + 0x10) = *(uint32_t *)(*(int *)((intptr_t)self + 8) + 0x24c);
      *(int *)((intptr_t)self + 0xc) = *(int *)((intptr_t)self + 0xc) + *(int *)((intptr_t)self + 0x1c);
      *(int *)((intptr_t)self + 0x10) = *(int *)((intptr_t)self + 0x10) + *(int *)((intptr_t)self + 0x20);
    }
    uptr3 = (uint32_t *)(*(int *)((intptr_t)self + 0xc) - local_14);
    value4 = *(int *)((intptr_t)self + 0x10) - local_10;
  }
  else {
    uptr3 = (uint32_t *)(arg2 + *(int *)((intptr_t)self + 0x1c));
    value4 = arg3 + *(int *)((intptr_t)self + 0x20);
  }
  xLeft = *(int *)((intptr_t)self + 0xc);
  if ((xLeft == -9999) || (value5 == 0)) {
    SetRect(arg4,-9999,0,0,0);
  }
  else {
    if (arg4 != (LPRECT)0x0) {
      SetRect(arg4,xLeft,*(int *)((intptr_t)self + 0x10),local_1c + xLeft,
              local_18 + *(int *)((intptr_t)self + 0x10));
    }
    Sprite_Draw(*(void **)((intptr_t)self + 4),arg1,*(uint32_t **)((intptr_t)self + 0xc),
                *(int *)((intptr_t)self + 0x10));
    *(uint32_t *)((intptr_t)self + 0x18) = 0;
  }
  *(int *)((intptr_t)self + 0x10) = local_10 + value4;
  uptr1 = *(uint32_t **)((intptr_t)self + 4);
  *(int *)((intptr_t)self + 0xc) = local_14 + (intptr_t)uptr3;
  if ((uptr1 != (uint32_t *)0x0) && ((local_1c != local_24 || (local_18 != local_20)))) {
    if (uptr1 != (uint32_t *)0x0) {
      (**(code **)*uptr1)(1);
    }
    *(uint32_t *)((intptr_t)self + 4) = 0;
  }
  if (*(int *)((intptr_t)self + 4) == 0) {
    this_00 = operator_new(0x50);
    uStack_4 = 0;
    if (this_00 == (void *)0x0) {
      uptr1 = (uint32_t *)0x0;
    }
    else {
      uptr1 = Sprite_CreateRaw(this_00,local_24,local_20,0,0x10,0);
    }
    uStack_4 = 0xffffffff;
    *(uint32_t **)((intptr_t)self + 4) = uptr1;
  }
  uvalue6 = *(uint32_t *)((intptr_t)self + 0x10);
  value5 = *(int *)((intptr_t)self + 0xc);
  uptr1 = (uint32_t *)Sprite_GetPixelBuffer(*(void **)((intptr_t)self + 4));
  Gfx_BlitScaled16Rows(*(void **)((intptr_t)self + 4),arg1,uptr1,value5,uvalue6);
  *(uint32_t *)((intptr_t)self + 0x18) = 1;
  Sprite_Draw(*(void **)self,arg1,uptr3,value4);
  if (arg4 != (LPRECT)0x0) {
    uptr2 = (uint32_t *)arg4->left;
    if (uptr2 == (uint32_t *)0xffffd8f1) {
      arg4->left = (LONG)uptr3;
      arg4->top = value4;
      arg4->right = local_24 + (intptr_t)uptr3;
      arg4->bottom = local_20 + value4;
    }
    else {
      if ((intptr_t)uptr3 < (intptr_t)uptr2) {
        uptr2 = uptr3;
      }
      arg4->left = (LONG)uptr2;
      value5 = arg4->top;
      if (value4 < arg4->top) {
        value5 = value4;
      }
      arg4->top = value5;
      value5 = local_24 + (intptr_t)uptr3;
      if ((intptr_t)(local_24 + (intptr_t)uptr3) <= arg4->right) {
        value5 = arg4->right;
      }
      arg4->right = value5;
      value5 = local_20 + value4;
      if (local_20 + value4 <= arg4->bottom) {
        value5 = arg4->bottom;
      }
      arg4->bottom = value5;
    }
  }
  ExceptionList = local_c;
  return 1;
}
