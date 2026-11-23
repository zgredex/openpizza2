// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x52ef20.c:11:10: error: redefinition of 'lprc' with a different type: 'LPRECT' (aka 'struct tagRECT *') vs 'struct pc2_obj_0x52ef20_lprc *'
// UI_SetWindowBounds: ported from Pizza Connection 2 at 0x52ef20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52ef20
#include "pc2_port.h"

struct pc2_obj_0x52ef20_lprc { intptr_t left; };
void __thiscall UI_SetWindowBounds(void *self,int arg1,int arg2,uint32_t arg3,int arg4)

{
  struct pc2_obj_0x52ef20_lprc *lprc;
  LPRECT lprc;
  uint32_t uvalue1;
  void *pvVar2;
  int value3;
  uint32_t *uptr4;
  uint32_t *uptr5;
  uint8_t bStack_e;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055aa3b;
  local_c = ExceptionList;
  value3 = 4;
  uptr4 = (uint32_t *)((intptr_t)self + 0xfc);
  ExceptionList = &local_c;
  do {
    if (*uptr4 != 0xff000000) {
      *(int *)((intptr_t)self + 0x10c) = *(int *)((intptr_t)self + 0x10c) + 1;
      uvalue1 = *uptr4;
      bStack_e = (uint8_t)(uvalue1 >> 0x10);
      if ((((uvalue1 & 0xff) < 8) && (bStack_e < 8)) && (0xf7 < (uvalue1 >> 8 & 0xff))) {
        *uptr4 = 0xf700;
      }
    }
    uptr4 = uptr4 + 1;
    value3 = value3 + -1;
  } while (value3 != 0);
  uptr5 = (uint32_t *)0x0;
  if (*(int *)((intptr_t)self + 0x114) != 0) {
    pvVar2 = operator_new(0x50);
    local_4 = 0;
    if (pvVar2 != (void *)0x0) {
      uptr5 = Sprite_CreateRaw(pvVar2,arg3,arg4,0,0x10,0);
    }
    pvVar2 = *(void **)((intptr_t)self + 0xdc);
    *(uint32_t **)((intptr_t)self + 0x50) = uptr5;
    local_4 = 0xffffffff;
    if (*(char *)((intptr_t)uptr5 + 0x39) == '\0') {
      Sprite_RealizeLazy(uptr5);
    }
    Surface_Configure(pvVar2,uptr5[0xb],(uint16_t)((intptr_t)*(short *)((intptr_t)uptr5 + 6) >> 1),
                      *(uint16_t *)(uptr5 + 2),(intptr_t)*(short *)((intptr_t)uptr5 + 6));
  }
  lprc = (LPRECT)((intptr_t)self + 8);
  SetRect(lprc,arg1,arg2,arg1 + 0x140,arg2 + 200);
  UI_RenderMapPreviewPanel((intptr_t)self);
  if (*(int *)((intptr_t)self + 0x168) == 0) {
    SetRect(lprc,arg1,arg2,arg3 + arg1,arg2 + arg4);
  }
  *(LONG *)((intptr_t)self + 0x18) = lprc->left;
  *(uint32_t *)((intptr_t)self + 0x1c) = *(uint32_t *)((intptr_t)self + 0xc);
  *(uint32_t *)((intptr_t)self + 0x20) = *(uint32_t *)((intptr_t)self + 0x10);
  *(uint32_t *)((intptr_t)self + 0x24) = *(uint32_t *)((intptr_t)self + 0x14);
  ExceptionList = local_c;
  return;
}
