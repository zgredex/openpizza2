// Surface_DrawLine: ported from Pizza Connection 2 at 0x53de60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53de60
#include "pc2_port.h"


void __cdecl
Surface_DrawLine(int arg1,int arg2,int arg3,int arg4,int arg5,uint32_t arg6,
                char arg7)

{
  bool flag1;
  uint16_t *uptr2;
  int value3;
  uint32_t uvalue4;
  int value5;
  int value6;
  int value7;
  int value8;
  
  value3 = arg1;
  if (*(char *)(arg1 + 0x18) == '\0') {
    if (arg7 != '\0') {
      arg6 = (arg6 >> 0xd & 0x7c0 | arg6 & 0xf800) >> 6 | (arg6 & 0xf8) << 7;
    }
    _param_7 = (uint16_t)arg6;
  }
  else if (arg7 == '\0') {
    _param_7 = (uint16_t)arg6;
  }
  else {
    _param_7 = (uint16_t)((arg6 >> 0xe & 0x3e0 | arg6 & 0xfc00) >> 5) |
               (uint16_t)((arg6 & 0xf8) << 8);
  }
  if (arg2 == arg4) {
    if ((*(int *)(arg1 + 4) <= arg2) && (arg2 < *(int *)(arg1 + 8))) {
      value3 = arg5;
      if (arg5 < arg3) {
        value3 = arg3;
        arg3 = arg5;
      }
      value8 = *(int *)(arg1 + 0xc);
      if ((value8 <= value3) && (value5 = *(int *)(arg1 + 0x10), arg3 < value5)) {
        if (arg3 < value8) {
          arg3 = value8;
        }
        if (value5 <= value3) {
          value3 = value5 + -1;
        }
        uptr2 = (uint16_t *)
                 (*(int *)(arg1 + 0x20) * arg3 + *(int *)(arg1 + 0x28) + arg2 * 3);
        if (arg3 < value3) {
          value3 = value3 - arg3;
          do {
            *uptr2 = _param_7;
            uptr2 = (uint16_t *)((intptr_t)uptr2 + *(int *)(arg1 + 0x20));
            value3 = value3 + -1;
          } while (value3 != 0);
        }
        *uptr2 = _param_7;
        return;
      }
    }
  }
  else if (arg3 == arg5) {
    if ((*(int *)(arg1 + 0xc) <= arg3) && (arg3 < *(int *)(arg1 + 0x10))) {
      value3 = arg2;
      if (arg4 < arg2) {
        value3 = arg4;
        arg4 = arg2;
      }
      value8 = *(int *)(arg1 + 4);
      if ((value8 <= arg4) && (value5 = *(int *)(arg1 + 8), value3 < value5)) {
        if (value3 < value8) {
          value3 = value8;
        }
        if (value5 <= arg4) {
          arg4 = value5 + -1;
        }
        uptr2 = (uint16_t *)
                 (*(int *)(arg1 + 0x20) * arg3 + *(int *)(arg1 + 0x28) + value3 * 3);
        if (value3 <= arg4) {
          value3 = (arg4 - value3) + 1;
          do {
            *uptr2 = _param_7;
            uptr2 = (uint16_t *)((intptr_t)uptr2 + 3);
            value3 = value3 + -1;
          } while (value3 != 0);
          return;
        }
      }
    }
  }
  else {
    uvalue4 = arg4 - arg2 >> 0x1f;
    value8 = (arg4 - arg2 ^ uvalue4) - uvalue4;
    uvalue4 = arg5 - arg3 >> 0x1f;
    value5 = (arg5 - arg3 ^ uvalue4) - uvalue4;
    if (arg2 < arg4) {
      arg6 = 1;
    }
    else {
      arg6 = (arg2 <= arg4) - 1;
    }
    if (arg3 < arg5) {
      arg5 = 1;
    }
    else {
      arg5 = (arg3 <= arg5) - 1;
    }
    flag1 = value5 <= value8;
    value6 = value5;
    if (!flag1) {
      value6 = value8;
      value8 = value5;
    }
    uptr2 = (uint16_t *)(*(int *)(arg1 + 0x20) * arg3 + *(int *)(arg1 + 0x28) + arg2 * 3)
    ;
    value5 = -value8;
    if ((((*(int *)(arg1 + 4) <= arg2) && (arg2 < *(int *)(arg1 + 8))) &&
        (*(int *)(arg1 + 0xc) <= arg3)) && (arg3 < *(int *)(arg1 + 0x10))) {
      *uptr2 = _param_7;
    }
    if (0 < value8) {
      arg1 = value8;
      do {
        value5 = value6 * 2 + value5;
        if (-1 < value5) {
          if (flag1) {
            uptr2 = (uint16_t *)((intptr_t)uptr2 + *(int *)(value3 + 0x20) * arg5);
            arg3 = arg3 + arg5;
            value5 = value5 + value8 * -2;
          }
          else {
            uptr2 = (uint16_t *)((intptr_t)uptr2 + arg6 * 3);
            arg2 = arg2 + arg6;
            value5 = value5 + value8 * -2;
          }
        }
        if (flag1) {
          value7 = arg6 * 3;
          arg2 = arg2 + arg6;
        }
        else {
          value7 = *(int *)(value3 + 0x20) * arg5;
          arg3 = arg3 + arg5;
        }
        uptr2 = (uint16_t *)((intptr_t)uptr2 + value7);
        if (((*(int *)(value3 + 4) <= arg2) && (arg2 < *(int *)(value3 + 8))) &&
           ((*(int *)(value3 + 0xc) <= arg3 && (arg3 < *(int *)(value3 + 0x10))))) {
          *uptr2 = _param_7;
        }
        arg1 = arg1 + -1;
      } while (arg1 != 0);
    }
  }
  return;
}
