// Surface_BlitFormat: ported from Pizza Connection 2 at 0x53e1e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53e1e0
#include "pc2_port.h"

void __cdecl
Surface_BlitFormat(int arg1,int arg2,int arg3,int arg4,int arg5,uint32_t arg6,
                  uint32_t arg7,char arg8)

{
  bool flag1;
  char cVar2;
  uint16_t *uptr3;
  int value4;
  int value5;
  uint32_t uvalue6;
  int value7;
  uint16_t uvalue8;
  int value9;
  int value10;
  
  cVar2 = arg8;
  _param_8 = (uint16_t)arg6;
  if (*(char *)(arg1 + 0x18) == '\0') {
    if (cVar2 != '\0') {
      _param_8 = (uint16_t)((arg6 >> 0xd & 0x7c0 | arg6 & 0xf800) >> 6) |
                 (uint16_t)((arg6 & 0xf8) << 7);
      arg7 = (arg7 >> 0xd & 0x7c0 | arg7 & 0xf800) >> 6 | (arg7 & 0xf8) << 7;
    }
    arg6 = (arg6 & ~(0x0u << 16)) | ((((uint16_t)arg7) & 0x0u) << 16);
  }
  else if (cVar2 == '\0') {
    arg6 = (arg6 & ~(0x0u << 16)) | ((((uint16_t)arg7) & 0x0u) << 16);
  }
  else {
    _param_8 = (uint16_t)((arg6 >> 0xe & 0x3e0 | arg6 & 0xfc00) >> 5) |
               (uint16_t)((arg6 & 0xf8) << 8);
    arg6 = (arg6 & ~(0x0u << 16)) | ((((uint16_t)((arg7 >> 0xe & 0x3e0 | arg7 & 0xfc00) >> 5) |
         (uint16_t)((arg7 & 0xf8) << 8)) & 0x0u) << 16);
  }
  if (arg2 == arg4) {
    if ((*(int *)(arg1 + 4) <= arg2) && (arg2 < *(int *)(arg1 + 8))) {
      value5 = arg3;
      uvalue8 = _param_8;
      if (arg5 < arg3) {
        value5 = arg5;
        arg5 = arg3;
        uvalue8 = (uint16_t)arg6;
        arg6 = (arg6 & ~(0x0u << 16)) | (((_param_8) & 0x0u) << 16);
      }
      if ((*(int *)(arg1 + 0xc) <= arg5) && (value5 < *(int *)(arg1 + 0x10))) {
        if (value5 < *(int *)(arg1 + 0xc)) {
          value5 = *(int *)(arg1 + 0xc);
        }
        if (*(int *)(arg1 + 0x10) <= arg5) {
          arg5 = *(int *)(arg1 + 0x10) + -1;
        }
        uptr3 = (uint16_t *)
                 (value5 * *(int *)(arg1 + 0x20) + *(int *)(arg1 + 0x28) + arg2 * 3);
        value4 = (arg5 - value5 >> 1) + value5;
        for (; value5 < arg5; value5 = value5 + 1) {
          if (value5 < value4) {
            *uptr3 = uvalue8;
          }
          else {
            *uptr3 = (uint16_t)arg6;
          }
          uptr3 = (uint16_t *)((intptr_t)uptr3 + *(int *)(arg1 + 0x20));
        }
        *uptr3 = uvalue8;
        return;
      }
    }
  }
  else if (arg3 == arg5) {
    if ((*(int *)(arg1 + 0xc) <= arg3) && (arg3 < *(int *)(arg1 + 0x10))) {
      value5 = arg2;
      uvalue8 = _param_8;
      if (arg4 < arg2) {
        value5 = arg4;
        arg4 = arg2;
        uvalue8 = (uint16_t)arg6;
        arg6 = (arg6 & ~(0x0u << 16)) | (((_param_8) & 0x0u) << 16);
      }
      value4 = *(int *)(arg1 + 4);
      if ((value4 <= arg4) && (value9 = *(int *)(arg1 + 8), value5 < value9)) {
        if (value5 < value4) {
          value5 = value4;
        }
        if (value9 <= arg4) {
          arg4 = value9 + -1;
        }
        uptr3 = (uint16_t *)
                 (*(int *)(arg1 + 0x20) * arg3 + *(int *)(arg1 + 0x28) + value5 * 3);
        value4 = (arg4 - value5 >> 1) + value5;
        if (value5 <= arg4) {
          do {
            if (value5 < value4) {
              *uptr3 = uvalue8;
            }
            else {
              *uptr3 = (uint16_t)arg6;
            }
            uptr3 = (uint16_t *)((intptr_t)uptr3 + 3);
            value5 = value5 + 1;
          } while (value5 <= arg4);
          return;
        }
      }
    }
  }
  else {
    uvalue6 = arg4 - arg2 >> 0x1f;
    value5 = (arg4 - arg2 ^ uvalue6) - uvalue6;
    uvalue6 = arg5 - arg3 >> 0x1f;
    value4 = (arg5 - arg3 ^ uvalue6) - uvalue6;
    if (arg2 < arg4) {
      arg7 = 1;
    }
    else {
      arg7 = (arg2 <= arg4) - 1;
    }
    if (arg3 < arg5) {
      arg5 = 1;
    }
    else {
      arg5 = (arg3 <= arg5) - 1;
    }
    flag1 = value4 <= value5;
    value9 = value4;
    if (!flag1) {
      value9 = value5;
      value5 = value4;
    }
    uptr3 = (uint16_t *)(arg3 * *(int *)(arg1 + 0x20) + *(int *)(arg1 + 0x28) + arg2 * 3)
    ;
    value4 = -value5;
    if ((((*(int *)(arg1 + 4) <= arg2) && (arg2 < *(int *)(arg1 + 8))) &&
        (*(int *)(arg1 + 0xc) <= arg3)) && (arg3 < *(int *)(arg1 + 0x10))) {
      *uptr3 = _param_8;
    }
    if (0 < value5) {
      value10 = value5;
      do {
        value4 = value9 * 2 + value4;
        if (-1 < value4) {
          if (flag1) {
            uptr3 = (uint16_t *)((intptr_t)uptr3 + arg5 * *(int *)(arg1 + 0x20));
            arg3 = arg3 + arg5;
            value4 = value4 + value5 * -2;
          }
          else {
            arg2 = arg2 + arg7;
            value4 = value4 + value5 * -2;
            uptr3 = (uint16_t *)(arg7 * 3 + (intptr_t)uptr3);
          }
        }
        if (flag1) {
          value7 = arg7 * 3;
          arg2 = arg2 + arg7;
        }
        else {
          value7 = arg5 * *(int *)(arg1 + 0x20);
          arg3 = arg3 + arg5;
        }
        uptr3 = (uint16_t *)((intptr_t)uptr3 + value7);
        if (((*(int *)(arg1 + 4) <= arg2) && (arg2 < *(int *)(arg1 + 8))) &&
           ((*(int *)(arg1 + 0xc) <= arg3 && (arg3 < *(int *)(arg1 + 0x10))))) {
          if (value5 / 2 < value10) {
            *uptr3 = _param_8;
          }
          else {
            *uptr3 = (uint16_t)arg6;
          }
        }
        value10 = value10 + -1;
      } while (0 < value10);
    }
  }
  return;
}
