// UI_UpdateAnimatedSprites: ported from Pizza Connection 2 at 0x54bd10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54bd10
#include "pc2_port.h"

bool __thiscall UI_UpdateAnimatedSprites(void *self,uint32_t *arg1)

{
  float fVar1;
  bool flag2;
  DWORD DVar3;
  uint32_t uvalue4;
  int value5;
  void *this_00;
  int value6;
  int value7;
  int *ptr8;
  uint32_t uvalue9;
  int64_t lvalue10;
  int local_c;
  
  DVar3 = timeGetTime();
  uvalue4 = *(uint32_t *)((intptr_t)self + 0x1ac);
  value7 = 0;
  if (uvalue4 == 0) {
    *(DWORD *)((intptr_t)self + 0x1ac) = DVar3;
    local_c = 1;
  }
  else {
    local_c = 0;
    while (uvalue4 < DVar3) {
      uvalue4 = *(int *)((intptr_t)self + 0x1ac) + 0x32;
      local_c = local_c + 1;
      *(uint32_t *)((intptr_t)self + 0x1ac) = uvalue4;
    }
  }
  uvalue4 = Object_GetActiveValue((intptr_t)arg1);
  UI_RealizeSprite((intptr_t)arg1);
  arg1 = (uint32_t *)0x0;
  flag2 = true;
  ptr8 = (int *)((intptr_t)self + 0x1c4);
  do {
    value5 = 0;
    value6 = 0;
    if (ptr8[0x20] != 0) {
      flag2 = false;
      if (0 < local_c) {
        do {
          if (0x1d < *ptr8) break;
          ptr8[-2] = (intptr_t)(*(float *)((intptr_t)self + (*ptr8 + value7) * 4 + 0x1c8) +
                            (float)ptr8[-2]);
          value5 = value5 + 1;
          *ptr8 = *ptr8 + 1;
        } while (value5 < local_c);
      }
      fVar1 = ABS(*(float *)((intptr_t)self + (*ptr8 + value7) * 4 + 0x1c4));
      if (fVar1 <= 8.0) {
        if (4.0 < fVar1) {
          value6 = 1;
        }
      }
      else {
        value6 = 2;
      }
      if (160.0 < (float)ptr8[-2]) {
        do {
          ptr8[-2] = (intptr_t)((float)ptr8[-2] - 160.0);
          if (ptr8[0x1f] != *(int *)((intptr_t)self + 0x1b8)) {
            ptr8[0x1f] = *(int *)((intptr_t)self + 0x1b8);
          }
        } while (160.0 < (float)ptr8[-2]);
      }
      if ((float)ptr8[-2] < 0.0) {
        do {
          ptr8[-2] = (intptr_t)((float)ptr8[-2] + 160.0);
          if (ptr8[0x1f] != *(int *)((intptr_t)self + 0x1b8)) {
            ptr8[0x1f] = *(int *)((intptr_t)self + 0x1b8);
          }
        } while ((float)ptr8[-2] < 0.0);
      }
      if (*ptr8 == 0x1e) {
        ptr8[-2] = ptr8[-1];
        ptr8[0x20] = 0;
      }
    }
    uvalue9 = -(uint32_t)(ptr8[0x1f] != 0) & 3;
    if (value6 == 0) {
      lvalue10 = __ftol();
      value5 = (intptr_t)lvalue10;
      this_00 = *(void **)((intptr_t)self + uvalue9 * 0x44 + 0x48);
    }
    else if (value6 == 1) {
      lvalue10 = __ftol();
      value5 = (intptr_t)lvalue10;
      this_00 = *(void **)((intptr_t)self + uvalue9 * 0x44 + 0x8c);
    }
    else {
      lvalue10 = __ftol();
      value5 = (intptr_t)lvalue10;
      this_00 = *(void **)((intptr_t)self + uvalue9 * 0x44 + 0xd0);
    }
    Sprite_Draw(this_00,uvalue4,arg1,value5);
    value7 = value7 + 0x23;
    arg1 = arg1 + 3;
    ptr8 = ptr8 + 0x23;
    if (0x13a < value7) {
      return !flag2;
    }
  } while( true );
}
