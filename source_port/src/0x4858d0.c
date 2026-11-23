// Game_LoadBackgroundImage: ported from Pizza Connection 2 at 0x4858d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4858d0
#include "pc2_port.h"


void __thiscall Game_LoadBackgroundImage(void *self,char *arg1)

{
  void *this_00;
  uint32_t *uptr1;
  int value2;
  void *pvStack_10;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0055821b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvStack_10 = self;
  CS_Enter(*(int *)((intptr_t)self + 0x240));
  if (*(uint32_t **)((intptr_t)self + 0x300) != (uint32_t *)0x0) {
    (**(code **)**(uint32_t **)((intptr_t)self + 0x300))(1);
    *(uint32_t *)((intptr_t)self + 0x300) = 0;
  }
  if (arg1 != (char *)0x0) {
    this_00 = operator_new(0x11c);
    uStack_4 = 0;
    if (this_00 == (void *)0x0) {
      uptr1 = (uint32_t *)0x0;
    }
    else {
      uptr1 = FullscreenImage_Load
                         (this_00,arg1,DAT_0057c5c8,DAT_0057c5d8,&pvStack_10,(uint8_t *)0x0);
    }
    uStack_4 = 0xffffffff;
    *(uint32_t **)((intptr_t)self + 0x300) = uptr1;
    if (pvStack_10 != (void *)0x0) {
      if (uptr1 != (uint32_t *)0x0) {
        (**(code **)*uptr1)(1);
      }
      *(uint32_t *)((intptr_t)self + 0x300) = 0;
    }
  }
  value2 = Window_GetGadgetChecked(DAT_0057c674,0x2a);
  if (value2 != 0) {
    UI_ClipChildRect(value2);
  }
  CS_Leave(*(int *)((intptr_t)self + 0x240));
  ExceptionList = pvStack_c;
  return;
}
