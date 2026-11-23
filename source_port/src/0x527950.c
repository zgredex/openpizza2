// UI_LoadChildSprite: ported from Pizza Connection 2 at 0x527950.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x527950
#include "pc2_port.h"


uint32_t * __thiscall UI_LoadChildSprite(void *self,LPCSTR arg1)

{
  uint32_t *uptr1;
  int iStack_14;
  void *pvStack_10;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0055a7fb;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  UI_ClearChildExtent(*(uint32_t **)((intptr_t)self + 0x8310));
  if (*(uint32_t **)((intptr_t)self + 0x8314) != (uint32_t *)0x0) {
    (**(code **)**(uint32_t **)((intptr_t)self + 0x8314))(1);
  }
  pvStack_10 = operator_new(0x50);
  uStack_4 = 0;
  if (pvStack_10 == (void *)0x0) {
    uptr1 = (uint32_t *)0x0;
  }
  else {
    uptr1 = Sprite_Load(pvStack_10,DAT_0057c5c8,*(void **)((intptr_t)self + 0x10),arg1,&iStack_14,0,
                         (void *)0x0,0);
  }
  uStack_4 = 0xffffffff;
  *(uint32_t **)((intptr_t)self + 0x8314) = uptr1;
  if (iStack_14 != 0) {
    if (uptr1 != (uint32_t *)0x0) {
      (**(code **)*uptr1)(1);
    }
    *(uint32_t *)((intptr_t)self + 0x8314) = 0;
    uptr1 = (uint32_t *)0x0;
  }
  ExceptionList = pvStack_c;
  return uptr1;
}
