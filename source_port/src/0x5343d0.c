// RecordList_DrawVariantSprite: ported from Pizza Connection 2 at 0x5343d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5343d0
#include "pc2_port.h"

void __thiscall RecordList_DrawVariantSprite(void *self,int arg1,int arg2)

{
  short svalue1;
  int *ptr2;
  int value3;
  int value4;
  int64_t lvalue5;
  uint8_t *bptr6;
  int value7;
  
  if ((-1 < arg2) && (arg2 < *(int *)((intptr_t)self + 0x48))) {
    CS_Enter(0x5842a0);
    ptr2 = (int *)(*(int *)((intptr_t)self + 0x4c) + arg2 * 0x48);
    if ((*ptr2 != -1) &&
       ((svalue1 = *(short *)((intptr_t)ptr2 + 0x32), (intptr_t)svalue1 < *(int *)((intptr_t)self + 0x68) &&
        (-1 < svalue1)))) {
      if (*(char *)((intptr_t)self + 0x35) == '\0') {
        RecordList_EnsureLoaded((intptr_t)self);
      }
      value4 = arg2 * 0x48 + *(int *)((intptr_t)self + 0x4c);
      value7 = -1;
      bptr6 = (uint8_t *)0xffffffff;
      *(uint16_t *)((intptr_t)self + 6) =
           *(uint16_t *)(*(int *)((intptr_t)self + 0x20) + *(short *)(value4 + 0x32) * 2);
      *(uint16_t *)((intptr_t)self + 8) =
           *(uint16_t *)(*(int *)((intptr_t)self + 0x24) + *(short *)(value4 + 0x32) * 2);
      *(uint16_t *)((intptr_t)self + 10) =
           *(uint16_t *)(*(int *)((intptr_t)self + 0x28) + *(short *)(value4 + 0x32) * 2);
      *(uint16_t *)((intptr_t)self + 0xc) =
           *(uint16_t *)(*(int *)((intptr_t)self + 0x2c) + *(short *)(value4 + 0x32) * 2);
      lvalue5 = __ftol();
      value3 = (intptr_t)lvalue5;
      lvalue5 = __ftol();
      Sprite_BlitAlphaRLEAlt
                (self,arg1,*(uint32_t **)(*(int *)((intptr_t)self + 0x80) + *(short *)(value4 + 0x32) * 4),
                 *(int *)((intptr_t)self + 0x7c),(uint32_t *)lvalue5,value3,bptr6,value7);
      CS_Leave(0x5842a0);
      return;
    }
    CS_Leave(0x5842a0);
  }
  return;
}
