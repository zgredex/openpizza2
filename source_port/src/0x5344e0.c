// Record_DrawSprite48: ported from Pizza Connection 2 at 0x5344e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5344e0
#include "pc2_port.h"

void __thiscall Record_DrawSprite48(void *self,uint32_t *arg1,void *arg2,int arg3)

{
  uint16_t *uptr1;
  int value2;
  int64_t lvalue3;
  int in_stack_00000020;
  uint32_t in_stack_00000024;
  uint32_t uvalue4;
  uint8_t uvalue5;
  uint32_t uvalue6;
  
  if ((-1 < arg3) && (arg3 < *(int *)((intptr_t)self + 0x48))) {
    CS_Enter(0x5842a0);
    if (*(int *)(*(int *)((intptr_t)self + 0x4c) + arg3 * 0x48) == -1) {
      CS_Leave(0x5842a0);
      return;
    }
    if (*(char *)((intptr_t)self + 0x35) == '\0') {
      RecordList_EnsureLoaded((intptr_t)self);
    }
    uvalue4 = DAT_00585518;
    value2 = *(int *)((intptr_t)self + 0x4c) + arg3 * 0x48;
    *(uint16_t *)((intptr_t)self + 6) =
         *(uint16_t *)(*(int *)((intptr_t)self + 0x20) + *(short *)(value2 + 0x32) * 2);
    *(uint16_t *)((intptr_t)self + 8) =
         *(uint16_t *)(*(int *)((intptr_t)self + 0x24) + *(short *)(value2 + 0x32) * 2);
    *(uint16_t *)((intptr_t)self + 10) =
         *(uint16_t *)(*(int *)((intptr_t)self + 0x28) + *(short *)(value2 + 0x32) * 2);
    *(uint16_t *)((intptr_t)self + 0xc) =
         *(uint16_t *)(*(int *)((intptr_t)self + 0x2c) + *(short *)(value2 + 0x32) * 2);
    uptr1 = *(uint16_t **)(*(int *)((intptr_t)self + 0x80) + *(short *)(value2 + 0x32) * 4);
    if (uptr1 != (uint16_t *)0x0) {
      if ((((*(uint8_t *)((intptr_t)self + 4) & 0x10) == 0) && (in_stack_00000020 != -2)) &&
         (*(char *)((intptr_t)self + 5) == '\b')) {
        if (in_stack_00000020 < 0) {
          uvalue6 = 0;
          uvalue4 = 0xffffffff;
          lvalue3 = __ftol();
          value2 = (intptr_t)lvalue3;
          lvalue3 = __ftol();
          Sprite_BlitRLEOpaque
                    (self,arg1,(uint8_t *)uptr1,*(int *)((intptr_t)self + 0x7c),(intptr_t)lvalue3,value2,uvalue4,
                     uvalue6);
          CS_Leave(0x5842a0);
          return;
        }
        lvalue3 = __ftol();
        value2 = (intptr_t)lvalue3;
        lvalue3 = __ftol();
        Sprite_BlitRLEOpaque
                  (self,arg1,(uint8_t *)uptr1,*(int *)((intptr_t)self + 0x7c),(intptr_t)lvalue3,value2,
                   in_stack_00000020,in_stack_00000024);
        CS_Leave(0x5842a0);
        return;
      }
      lvalue3 = __ftol();
      uvalue5 = (uint8_t)uvalue4;
      value2 = (intptr_t)lvalue3;
      lvalue3 = __ftol();
      Sprite_BlitAlphaRLE(self,arg1,arg2,uptr1,*(int *)((intptr_t)self + 0x7c),(uint32_t *)lvalue3,value2
                          ,uvalue5);
    }
    CS_Leave(0x5842a0);
  }
  return;
}
