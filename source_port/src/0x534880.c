// RecordList_BlitRecordSprite: ported from Pizza Connection 2 at 0x534880.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x534880
#include "pc2_port.h"

bool __thiscall RecordList_BlitRecordSprite(void *self,int arg1,int arg2,int arg3)

{
  bool flag1;
  int value2;
  int64_t lvalue3;
  int64_t lvalue4;
  
  if (((arg1 < 0) || (*(int *)((intptr_t)self + 0x48) <= arg1)) ||
     (*(int *)(*(int *)((intptr_t)self + 0x4c) + arg1 * 0x48) == -1)) {
    return false;
  }
  if (*(char *)((intptr_t)self + 0x35) == '\0') {
    RecordList_EnsureLoaded((intptr_t)self);
  }
  value2 = arg1 * 0x48 + *(int *)((intptr_t)self + 0x4c);
  lvalue3 = __ftol();
  lvalue4 = __ftol();
  *(uint16_t *)((intptr_t)self + 6) =
       *(uint16_t *)(*(int *)((intptr_t)self + 0x20) + *(short *)(value2 + 0x32) * 2);
  *(uint16_t *)((intptr_t)self + 8) =
       *(uint16_t *)(*(int *)((intptr_t)self + 0x24) + *(short *)(value2 + 0x32) * 2);
  *(uint16_t *)((intptr_t)self + 10) =
       *(uint16_t *)(*(int *)((intptr_t)self + 0x28) + *(short *)(value2 + 0x32) * 2);
  *(uint16_t *)((intptr_t)self + 0xc) =
       *(uint16_t *)(*(int *)((intptr_t)self + 0x2c) + *(short *)(value2 + 0x32) * 2);
  flag1 = Sprite_BlitClipped(self,*(uint16_t **)
                                   (*(int *)((intptr_t)self + 0x80) + *(short *)(value2 + 0x32) * 4),
                             arg2 - (intptr_t)lvalue3,arg3 - (intptr_t)lvalue4,(uint32_t *)0x0);
  return flag1;
}
