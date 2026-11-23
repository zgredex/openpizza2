// Surface_BlitOriented: ported from Pizza Connection 2 at 0x520640.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x520640
#include "pc2_port.h"

void __thiscall
Surface_BlitOriented
          (void *self,int arg1,uint16_t *arg2,uint32_t arg3,uint32_t arg4,int *arg5)

{
  int value1;
  uint32_t *uptr2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  uint32_t uvalue5;
  int *ptr6;
  uint32_t *uptr7;
  uint16_t *uptr8;
  uint32_t uvalue9;
  uint32_t *uptr10;
  int value11;
  uint32_t *uptr12;
  int local_8;
  uint32_t local_4;
  
  switch(*arg5) {
  case 0:
    uptr7 = (uint32_t *)(arg1 + *(int *)((intptr_t)self + 0x20) * arg3 * 2);
    uptr2 = (uint32_t *)((intptr_t)arg2 + *(int *)((intptr_t)self + 0x1c) * arg3);
    if ((intptr_t)arg3 < (intptr_t)arg4) {
      arg3 = arg4 - arg3;
      do {
        uvalue5 = *(uint32_t *)((intptr_t)self + 0x28);
        uptr10 = uptr7;
        uptr12 = uptr2;
        for (uvalue4 = (uvalue5 & 0x7fffffff) >> 1; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
          *uptr12 = *uptr10;
          uptr10 = uptr10 + 1;
          uptr12 = uptr12 + 1;
        }
        for (value1 = (uvalue5 & 1) << 1; value1 != 0; value1 = value1 + -1) {
          *(uint8_t *)uptr12 = *(uint8_t *)uptr10;
          uptr10 = (uint32_t *)((intptr_t)uptr10 + 1);
          uptr12 = (uint32_t *)((intptr_t)uptr12 + 1);
        }
        uptr2 = (uint32_t *)((intptr_t)uptr2 + *(int *)((intptr_t)self + 0x1c));
        uptr7 = (uint32_t *)((intptr_t)uptr7 + *(int *)((intptr_t)self + 0x20) * 2);
        arg3 = arg3 - 1;
      } while (arg3 != 0);
      return;
    }
    break;
  case 1:
    value1 = (*(int *)((intptr_t)self + 0x28) - arg3) + -1;
    uptr7 = (uint32_t *)(arg1 + *(int *)((intptr_t)self + 0x20) * value1 * 2);
    uptr2 = (uint32_t *)((intptr_t)arg2 + value1 * *(int *)((intptr_t)self + 0x1c));
    if ((intptr_t)arg3 < (intptr_t)arg4) {
      arg3 = arg4 - arg3;
      do {
        uvalue5 = *(uint32_t *)((intptr_t)self + 0x28);
        uptr10 = uptr7;
        uptr12 = uptr2;
        for (uvalue4 = (uvalue5 & 0x7fffffff) >> 1; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
          *uptr12 = *uptr10;
          uptr10 = uptr10 + 1;
          uptr12 = uptr12 + 1;
        }
        for (value1 = (uvalue5 & 1) << 1; value1 != 0; value1 = value1 + -1) {
          *(uint8_t *)uptr12 = *(uint8_t *)uptr10;
          uptr10 = (uint32_t *)((intptr_t)uptr10 + 1);
          uptr12 = (uint32_t *)((intptr_t)uptr12 + 1);
        }
        uptr2 = (uint32_t *)((intptr_t)uptr2 - *(int *)((intptr_t)self + 0x1c));
        uptr7 = (uint32_t *)((intptr_t)uptr7 + *(int *)((intptr_t)self + 0x20) * -2);
        arg3 = arg3 - 1;
      } while (arg3 != 0);
      return;
    }
    break;
  case 2:
    uptr7 = (uint32_t *)(arg1 + arg3 * 2);
    uptr2 = (uint32_t *)(arg2 + arg3);
    uvalue5 = (arg4 - arg3) * 2;
    if ((0 < (intptr_t)uvalue5) && (local_8 = 0, 0 < *(int *)((intptr_t)self + 0x28))) {
      do {
        uptr10 = uptr7;
        uptr12 = uptr2;
        for (uvalue4 = (arg4 - arg3 & 0x7fffffff) >> 1; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
          *uptr12 = *uptr10;
          uptr10 = uptr10 + 1;
          uptr12 = uptr12 + 1;
        }
        for (uvalue4 = uvalue5 & 3; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
          *(uint8_t *)uptr12 = *(uint8_t *)uptr10;
          uptr10 = (uint32_t *)((intptr_t)uptr10 + 1);
          uptr12 = (uint32_t *)((intptr_t)uptr12 + 1);
        }
        uptr2 = (uint32_t *)((intptr_t)uptr2 + *(int *)((intptr_t)self + 0x1c));
        uptr7 = (uint32_t *)((intptr_t)uptr7 + *(int *)((intptr_t)self + 0x20) * 2);
        local_8 = local_8 + 1;
      } while (local_8 < *(int *)((intptr_t)self + 0x28));
      return;
    }
    break;
  case 3:
    value1 = *(int *)((intptr_t)self + 0x28) - arg4;
    uptr7 = (uint32_t *)(arg1 + value1 * 2);
    uptr2 = (uint32_t *)(arg2 + value1);
    uvalue5 = (arg4 - arg3) * 2;
    if ((0 < (intptr_t)uvalue5) && (local_8 = 0, 0 < *(int *)((intptr_t)self + 0x28))) {
      do {
        uptr10 = uptr7;
        uptr12 = uptr2;
        for (uvalue4 = (arg4 - arg3 & 0x7fffffff) >> 1; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
          *uptr12 = *uptr10;
          uptr10 = uptr10 + 1;
          uptr12 = uptr12 + 1;
        }
        for (uvalue4 = uvalue5 & 3; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
          *(uint8_t *)uptr12 = *(uint8_t *)uptr10;
          uptr10 = (uint32_t *)((intptr_t)uptr10 + 1);
          uptr12 = (uint32_t *)((intptr_t)uptr12 + 1);
        }
        uptr2 = (uint32_t *)((intptr_t)uptr2 + *(int *)((intptr_t)self + 0x1c));
        local_8 = local_8 + 1;
        uptr7 = (uint32_t *)((intptr_t)uptr7 + *(int *)((intptr_t)self + 0x20) * 2);
      } while (local_8 < *(int *)((intptr_t)self + 0x28));
      return;
    }
    break;
  case 4:
  case 6:
    goto LAB_0052083f;
  case 5:
  case 7:
    uvalue5 = *(int *)((intptr_t)self + 0x2c) - arg3;
    arg3 = *(int *)((intptr_t)self + 0x2c) - arg4;
    arg4 = uvalue5;
LAB_0052083f:
    uvalue5 = arg3 * 2;
    uvalue4 = arg4 * 2;
    uptr7 = (uint32_t *)(arg1 + arg3 * 4);
    uptr2 = (uint32_t *)(arg2 + arg3 * 2);
    uvalue9 = (uvalue4 + arg3 * -2) * 2;
    if (5 < *arg5) {
      value1 = *(int *)((intptr_t)self + 0x28) + -1;
      uptr7 = (uint32_t *)((intptr_t)uptr7 + *(int *)((intptr_t)self + 0x20) * value1 * 2);
      uptr2 = (uint32_t *)((intptr_t)uptr2 + *(int *)((intptr_t)self + 0x1c) * value1);
    }
    value1 = *(int *)((intptr_t)self + 0x28);
    local_8 = 0;
    arg3 = uvalue5;
    arg4 = uvalue4;
    local_4 = uvalue9;
    if (0 < value1) {
      while (0 < (intptr_t)uvalue9) {
        if (value1 < (intptr_t)uvalue4) {
          uvalue3 = uvalue9 + (value1 - uvalue4) * 2;
        }
        else {
          uvalue3 = uvalue9;
        }
        if (0 < (intptr_t)uvalue3) {
          uptr10 = uptr7;
          uptr12 = uptr2;
          for (uvalue5 = uvalue3 >> 2; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
            *uptr12 = *uptr10;
            uptr10 = uptr10 + 1;
            uptr12 = uptr12 + 1;
          }
          for (uvalue3 = uvalue3 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
            *(uint8_t *)uptr12 = *(uint8_t *)uptr10;
            uptr10 = (uint32_t *)((intptr_t)uptr10 + 1);
            uptr12 = (uint32_t *)((intptr_t)uptr12 + 1);
          }
          uvalue4 = arg4;
          uvalue9 = local_4;
          uvalue5 = arg3;
        }
        if ((intptr_t)uvalue5 < 1) {
          uvalue9 = uvalue9 - 2;
          local_4 = uvalue9;
        }
        else {
          uptr2 = (uint32_t *)((intptr_t)uptr2 + -2);
          uptr7 = (uint32_t *)((intptr_t)uptr7 + -2);
          uvalue5 = uvalue5 - 1;
          uvalue4 = uvalue4 - 1;
          arg3 = uvalue5;
          arg4 = uvalue4;
        }
        value1 = *(int *)((intptr_t)self + 0x1c);
        if (*arg5 < 6) {
          value11 = *(int *)((intptr_t)self + 0x20);
        }
        else {
          value1 = -value1;
          value11 = -*(int *)((intptr_t)self + 0x20);
        }
        uptr2 = (uint32_t *)((intptr_t)uptr2 + value1);
        uptr7 = (uint32_t *)((intptr_t)uptr7 + value11 * 2);
        local_8 = local_8 + 1;
        value1 = *(int *)((intptr_t)self + 0x28);
        if (value1 <= local_8) {
          return;
        }
      }
    }
    break;
  case 8:
    if (arg4 * 2 != 0) {
      arg3 = arg4;
      if ((arg4 & 1) == 0) {
        arg3 = arg4 | 1;
      }
      value1 = (intptr_t)(*(int *)((intptr_t)self + 0x2c) - arg3) / 2;
      uptr7 = (uint32_t *)(arg1 + (*(int *)((intptr_t)self + 0x20) + 1) * value1 * 2);
      uptr2 = (uint32_t *)((intptr_t)arg2 + (*(int *)((intptr_t)self + 0x1c) + 2) * value1);
      if (0 < (intptr_t)arg3) {
        do {
          uptr10 = uptr7;
          uptr12 = uptr2;
          for (uvalue5 = (arg4 & 0x7fffffff) >> 1; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
            *uptr12 = *uptr10;
            uptr10 = uptr10 + 1;
            uptr12 = uptr12 + 1;
          }
          for (uvalue5 = arg4 * 2 & 3; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
            *(uint8_t *)uptr12 = *(uint8_t *)uptr10;
            uptr10 = (uint32_t *)((intptr_t)uptr10 + 1);
            uptr12 = (uint32_t *)((intptr_t)uptr12 + 1);
          }
          uptr2 = (uint32_t *)((intptr_t)uptr2 + *(int *)((intptr_t)self + 0x1c));
          uptr7 = (uint32_t *)((intptr_t)uptr7 + *(int *)((intptr_t)self + 0x20) * 2);
          arg3 = arg3 - 1;
        } while (arg3 != 0);
        return;
      }
    }
    break;
  case 9:
    value1 = *(int *)((intptr_t)self + 0x28);
    local_8 = 0;
    if (0 < value1) {
      arg5 = (int *)0x0;
      ptr6 = arg5;
      do {
        for (; value1 <= (intptr_t)ptr6; ptr6 = (int *)((intptr_t)ptr6 - value1)) {
        }
        value11 = 0;
        if (0 < value1) {
          uptr8 = arg2;
          do {
            if (((intptr_t)arg3 <= *(int *)(&DAT_00573bc0 + (intptr_t)ptr6 * 4)) &&
               (*(int *)(&DAT_00573bc0 + (intptr_t)ptr6 * 4) <= (intptr_t)arg4)) {
              *uptr8 = *(uint16_t *)((arg1 - (intptr_t)arg2) + (intptr_t)uptr8);
            }
            ptr6 = (int *)((intptr_t)ptr6 + 1);
            if (*(int *)((intptr_t)self + 0x28) <= (intptr_t)ptr6) {
              ptr6 = (int *)0x0;
            }
            value11 = value11 + 1;
            uptr8 = uptr8 + 1;
          } while (value11 < *(int *)((intptr_t)self + 0x28));
        }
        arg2 = (uint16_t *)((intptr_t)arg2 + *(int *)((intptr_t)self + 0x1c));
        value1 = *(int *)((intptr_t)self + 0x28);
        arg1 = arg1 + *(int *)((intptr_t)self + 0x20) * 2;
        local_8 = local_8 + 1;
        ptr6 = (int *)((intptr_t)arg5 + 5);
        arg5 = ptr6;
      } while (local_8 < value1);
    }
  }
  return;
}
