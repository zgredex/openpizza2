// UI_CreateContextMenu: ported from Pizza Connection 2 at 0x523800.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x523800
#include "pc2_port.h"


uint32_t __thiscall UI_CreateContextMenu(void *self,uint32_t arg1)

{
  uint32_t *uptr1;
  int iStack_14;
  void *pvStack_10;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0055a6db;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (*(uint32_t **)((intptr_t)self + 0x240) != (uint32_t *)0x0) {
    ExceptionList = &pvStack_c;
    (**(code **)**(uint32_t **)((intptr_t)self + 0x240))(1);
  }
  pvStack_10 = operator_new(0x38c);
  uStack_4 = 0;
  if (pvStack_10 == (void *)0x0) {
    uptr1 = (uint32_t *)0x0;
  }
  else {
    uptr1 = ContextMenu_Construct(pvStack_10,DAT_0057c5c8,(intptr_t)self,arg1,&iStack_14);
  }
  uStack_4 = 0xffffffff;
  *(uint32_t **)((intptr_t)self + 0x240) = uptr1;
  if (iStack_14 == 0) {
    ExceptionList = pvStack_c;
    return 1;
  }
  if (uptr1 != (uint32_t *)0x0) {
    (**(code **)*uptr1)(1);
  }
  *(uint32_t *)((intptr_t)self + 0x240) = 0;
  ExceptionList = pvStack_c;
  return 0;
}
