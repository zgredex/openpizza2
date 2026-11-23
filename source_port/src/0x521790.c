// UI_DrawLine: ported from Pizza Connection 2 at 0x521790.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x521790
#include "pc2_port.h"

void __thiscall
UI_DrawLine(void *self,uint32_t *arg1,int arg2,uint32_t *arg3,int arg4,int *arg5)

{
  uint32_t *uptr1;
  bool flag2;
  int value3;
  int value4;
  uint32_t uvalue5;
  uint32_t *uptr6;
  int value7;
  int value8;
  
  uptr6 = arg1;
  if ((arg5 != (int *)0x0) && ((*arg5 != 1 || (arg5[1] != 0)))) {
    if (arg1 == arg3) {
      value7 = *(int *)((intptr_t)self + 0x68);
      if ((*(int *)(value7 + 4) <= (intptr_t)arg1) && ((intptr_t)arg1 < *(int *)(value7 + 8))) {
        value3 = arg4;
        if (arg4 < arg2) {
          value3 = arg2;
          arg2 = arg4;
        }
        value4 = *(int *)(value7 + 0xc);
        if ((value4 <= value3) && (value7 = *(int *)(value7 + 0x10), arg2 < value7)) {
          if (arg2 < value4) {
            arg2 = value4;
          }
          if (value7 <= value3) {
            value3 = value7 + -1;
          }
          for (; arg2 < value3; arg2 = arg2 + 1) {
            UI_RenderDrawCommand(self,arg1,arg2,arg5);
          }
          UI_RenderDrawCommand(self,arg1,arg2,arg5);
          return;
        }
      }
    }
    else if (arg2 == arg4) {
      value7 = *(int *)((intptr_t)self + 0x68);
      if ((*(int *)(value7 + 0xc) <= arg2) && (arg2 < *(int *)(value7 + 0x10))) {
        uptr6 = arg3;
        if ((intptr_t)arg3 < (intptr_t)arg1) {
          uptr6 = arg1;
          arg1 = arg3;
        }
        uptr1 = *(uint32_t **)(value7 + 4);
        if (((intptr_t)uptr1 <= (intptr_t)uptr6) && (value7 = *(int *)(value7 + 8), (intptr_t)arg1 < value7)) {
          if ((intptr_t)arg1 < (intptr_t)uptr1) {
            arg1 = uptr1;
          }
          if (value7 <= (intptr_t)uptr6) {
            uptr6 = (uint32_t *)(value7 + -1);
          }
          for (; (intptr_t)arg1 < (intptr_t)uptr6; arg1 = (uint32_t *)((intptr_t)arg1 + 1)) {
            UI_RenderDrawCommand(self,arg1,arg2,arg5);
          }
          UI_RenderDrawCommand(self,arg1,arg2,arg5);
          return;
        }
      }
    }
    else {
      uvalue5 = (intptr_t)arg3 - (intptr_t)arg1 >> 0x1f;
      value7 = ((intptr_t)arg3 - (intptr_t)arg1 ^ uvalue5) - uvalue5;
      uvalue5 = arg4 - arg2 >> 0x1f;
      value3 = (arg4 - arg2 ^ uvalue5) - uvalue5;
      if ((intptr_t)arg1 < (intptr_t)arg3) {
        arg1 = (uint32_t *)0x1;
      }
      else {
        arg1 = (uint32_t *)(((intptr_t)arg1 <= (intptr_t)arg3) - 1);
      }
      if (arg2 < arg4) {
        arg4 = 1;
      }
      else {
        arg4 = (arg2 <= arg4) - 1;
      }
      flag2 = value3 <= value7;
      value4 = value3;
      if (!flag2) {
        value4 = value7;
        value7 = value3;
      }
      value3 = -value7;
      UI_RenderDrawCommand(self,uptr6,arg2,arg5);
      value8 = value7;
      if (0 < value7) {
        do {
          value3 = value4 * 2 + value3;
          if (-1 < value3) {
            if (flag2) {
              arg2 = arg2 + arg4;
            }
            else {
              uptr6 = (uint32_t *)((intptr_t)uptr6 + (intptr_t)arg1);
            }
            value3 = value3 + value7 * -2;
          }
          if (flag2) {
            uptr6 = (uint32_t *)((intptr_t)uptr6 + (intptr_t)arg1);
          }
          else {
            arg2 = arg2 + arg4;
          }
          UI_RenderDrawCommand(self,uptr6,arg2,arg5);
          value8 = value8 + -1;
        } while (value8 != 0);
      }
    }
  }
  return;
}
