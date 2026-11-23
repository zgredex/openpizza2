// UI_ProcessWindowEvent: ported from Pizza Connection 2 at 0x52f2e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52f2e0
#include "pc2_port.h"


void __thiscall UI_ProcessWindowEvent(void *self,void *arg1)

{
  uint32_t *this_00;
  int value1;
  int value2;
  uint32_t *uptr3;
  int value4;
  int *ptr5;
  int value6;
  uint32_t local_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  void *pvStack_10;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0055aa8b;
  pvStack_c = ExceptionList;
  local_20 = 0;
  if ((*(int *)((intptr_t)self + 0xe0) != 0) ||
     (ptr5 = (int *)((intptr_t)self + 0x38), *(int *)((intptr_t)self + 0x13c) != 0)) {
    ptr5 = (int *)((intptr_t)self + 8);
  }
  if (*(code **)((intptr_t)self + 0x284) == (code *)0x0) {
    ExceptionList = &pvStack_c;
  }
  else {
    ExceptionList = &pvStack_c;
    local_20 = (**(code **)((intptr_t)self + 0x284))(arg1,ptr5,*(uint32_t *)((intptr_t)self + 0x288));
  }
  if ((*(int *)((intptr_t)self + 0x168) != 0) &&
     ((*(int *)((intptr_t)self + 0x164) != 0 || (*(int *)((intptr_t)self + 0x50) == 0)))) {
    *(uint32_t *)((intptr_t)self + 0x164) = 0;
    *(uint32_t *)((intptr_t)self + 0x16c) = 1;
    UI_RenderMapPreviewPanel((intptr_t)self);
    *(uint32_t *)((intptr_t)self + 0x16c) = 0;
  }
  if ((local_20 & 2) == 0) {
    Surface_SetBounds(arg1,*ptr5,ptr5[1],ptr5[2],ptr5[3]);
    iStack_1c = *(int *)((intptr_t)self + 0xc);
    uptr3 = *(uint32_t **)((intptr_t)self + 8);
    if (*(int *)((intptr_t)self + 0x13c) != 0) {
      uptr3 = (uint32_t *)((intptr_t)uptr3 + *(int *)((intptr_t)self + 0x140));
      iStack_1c = iStack_1c + *(int *)((intptr_t)self + 0x144);
    }
    if (*(void **)((intptr_t)self + 0x50) == (void *)0x0) {
      if (*(void **)((intptr_t)self + 0x94) == (void *)0x0) {
        if (*(void **)((intptr_t)self + 0x138) != (void *)0x0) {
          Sprite_Blit24Bit(*(void **)((intptr_t)self + 0x138),(intptr_t)arg1,(intptr_t)uptr3,iStack_1c,-9999,
                           -9999,0,0);
        }
      }
      else {
        Sprite_GetHotspot(*(void **)((intptr_t)self + 0x94),&iStack_14,&iStack_18);
        Sprite_Draw(*(void **)((intptr_t)self + 0x94),(intptr_t)arg1,(uint32_t *)((intptr_t)uptr3 - iStack_14),
                    iStack_1c - iStack_18);
      }
    }
    else {
      Sprite_Draw(*(void **)((intptr_t)self + 0x50),(intptr_t)arg1,uptr3,iStack_1c);
    }
    if ((((*(int *)((intptr_t)self + 0x168) == 0) && (*(int *)((intptr_t)self + 0x50) == 0)) &&
        (*(int *)((intptr_t)self + 0x138) == 0)) && (*(int *)((intptr_t)self + 0x94) == 0)) {
      value6 = *(int *)((intptr_t)self + 0x10) - *(int *)((intptr_t)self + 8);
      value4 = *(int *)((intptr_t)self + 0x14) - *(int *)((intptr_t)self + 0xc);
      if ((0 < value6) && (0 < value4)) {
        pvStack_10 = operator_new(0x11c);
        uStack_4 = 0;
        if (pvStack_10 == (void *)0x0) {
          this_00 = (uint32_t *)0x0;
        }
        else {
          this_00 = Window_Construct(pvStack_10,value6,value4,2);
        }
        uStack_4 = 0xffffffff;
        *(uint32_t **)((intptr_t)self + 0x138) = this_00;
        Surface_CopyRect16(this_00,(intptr_t)arg1,(intptr_t)uptr3,iStack_1c);
        *(uint32_t *)((intptr_t)self + 0x2c0) = 1;
      }
    }
  }
  if ((local_20 & 1) == 0) {
    if (*(int *)((intptr_t)self + 0xe0) == 0) {
      value4 = *(int *)((intptr_t)self + 0x44);
      if (*(int *)((intptr_t)self + 0x24) <= *(int *)((intptr_t)self + 0x44)) {
        value4 = *(int *)((intptr_t)self + 0x24);
      }
      value6 = *(int *)((intptr_t)self + 0x40);
      if (*(int *)((intptr_t)self + 0x20) <= *(int *)((intptr_t)self + 0x40)) {
        value6 = *(int *)((intptr_t)self + 0x20);
      }
      value2 = *(int *)((intptr_t)self + 0x3c);
      if (*(int *)((intptr_t)self + 0x3c) <= *(int *)((intptr_t)self + 0x1c)) {
        value2 = *(int *)((intptr_t)self + 0x1c);
      }
      value1 = *(int *)((intptr_t)self + 0x38);
      if (*(int *)((intptr_t)self + 0x38) <= *(int *)((intptr_t)self + 0x18)) {
        value1 = *(int *)((intptr_t)self + 0x18);
      }
    }
    else {
      value4 = *(int *)((intptr_t)self + 0x24);
      value6 = *(int *)((intptr_t)self + 0x20);
      value2 = *(int *)((intptr_t)self + 0x1c);
      value1 = *(int *)((intptr_t)self + 0x18);
    }
    Surface_SetBounds(arg1,value1,value2,value6,value4);
    value4 = 0;
    if (0 < *(int *)((intptr_t)self + 0xf0)) {
      do {
        ptr5 = *(int **)(*(int *)((intptr_t)self + 0xec) + value4 * 8);
        if ((ptr5 != (int *)0x0) && (ptr5[8] != 0)) {
          (**(code **)(*ptr5 + 4))
                    (arg1,*(uint32_t *)((intptr_t)self + 0x18),*(uint32_t *)((intptr_t)self + 0x1c));
        }
        value4 = value4 + 1;
      } while (value4 < *(int *)((intptr_t)self + 0xf0));
    }
  }
  if (*(code **)((intptr_t)self + 0x27c) != (code *)0x0) {
    (**(code **)((intptr_t)self + 0x27c))(arg1,(intptr_t)self + 0x18,*(uint32_t *)((intptr_t)self + 0x280));
  }
  *(uint32_t *)((intptr_t)self + 0xe0) = 0;
  *(uint32_t *)((intptr_t)self + 0x38) = 0xfffffc19;
  ExceptionList = pvStack_c;
  return;
}
