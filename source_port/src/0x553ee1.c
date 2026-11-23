// ParseCommandLine: ported from Pizza Connection 2 at 0x553ee1.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x553ee1
#include "pc2_port.h"

void __cdecl
ParseCommandLine(uint8_t *arg1,uint32_t *arg2,uint8_t *arg3,int *arg4,int *arg5)

{
  uint8_t flag1;
  bool flag2;
  bool flag3;
  uint8_t *bptr4;
  uint32_t uvalue5;
  uint32_t *uptr6;
  
  *arg5 = 0;
  *arg4 = 1;
  if (arg2 != (uint32_t *)0x0) {
    *arg2 = arg3;
    arg2 = arg2 + 1;
  }
  if (*arg1 == 0x22) {
    while( true ) {
      flag1 = arg1[1];
      bptr4 = arg1 + 1;
      if ((flag1 == 0x22) || (flag1 == 0)) break;
      if (((*(uint8_t *)((intptr_t)&DAT_00585ac0 + flag1 + 1) & 4) != 0) &&
         (*arg5 = *arg5 + 1, arg3 != (uint8_t *)0x0)) {
        *arg3 = *bptr4;
        arg3 = arg3 + 1;
        bptr4 = arg1 + 2;
      }
      *arg5 = *arg5 + 1;
      arg1 = bptr4;
      if (arg3 != (uint8_t *)0x0) {
        *arg3 = *bptr4;
        arg3 = arg3 + 1;
      }
    }
    *arg5 = *arg5 + 1;
    if (arg3 != (uint8_t *)0x0) {
      *arg3 = 0;
      arg3 = arg3 + 1;
    }
    if (*bptr4 == 0x22) {
      bptr4 = arg1 + 2;
    }
  }
  else {
    do {
      *arg5 = *arg5 + 1;
      if (arg3 != (uint8_t *)0x0) {
        *arg3 = *arg1;
        arg3 = arg3 + 1;
      }
      flag1 = *arg1;
      bptr4 = arg1 + 1;
      if ((*(uint8_t *)((intptr_t)&DAT_00585ac0 + flag1 + 1) & 4) != 0) {
        *arg5 = *arg5 + 1;
        if (arg3 != (uint8_t *)0x0) {
          *arg3 = *bptr4;
          arg3 = arg3 + 1;
        }
        bptr4 = arg1 + 2;
      }
      if (flag1 == 0x20) break;
      if (flag1 == 0) goto LAB_00553f8c;
      arg1 = bptr4;
    } while (flag1 != 9);
    if (flag1 == 0) {
LAB_00553f8c:
      bptr4 = bptr4 + -1;
    }
    else if (arg3 != (uint8_t *)0x0) {
      arg3[-1] = 0;
    }
  }
  flag2 = false;
  uptr6 = arg2;
  while (*bptr4 != 0) {
    for (; (*bptr4 == 0x20 || (*bptr4 == 9)); bptr4 = bptr4 + 1) {
    }
    if (*bptr4 == 0) break;
    if (uptr6 != (uint32_t *)0x0) {
      *uptr6 = arg3;
      uptr6 = uptr6 + 1;
      arg2 = uptr6;
    }
    *arg4 = *arg4 + 1;
    while( true ) {
      flag3 = true;
      uvalue5 = 0;
      for (; *bptr4 == 0x5c; bptr4 = bptr4 + 1) {
        uvalue5 = uvalue5 + 1;
      }
      if (*bptr4 == 0x22) {
        if ((uvalue5 & 1) == 0) {
          if ((!flag2) || (bptr4[1] != 0x22)) {
            flag3 = false;
          }
          else {
            bptr4 = bptr4 + 1;
          }
          flag2 = !flag2;
          uptr6 = arg2;
        }
        uvalue5 = uvalue5 >> 1;
      }
      if (uvalue5 != 0) {
        do {
          if (arg3 != (uint8_t *)0x0) {
            *arg3 = 0x5c;
            arg3 = arg3 + 1;
          }
          *arg5 = *arg5 + 1;
          uvalue5 = uvalue5 - 1;
        } while (uvalue5 != 0);
      }
      flag1 = *bptr4;
      if ((flag1 == 0) || ((!flag2 && ((flag1 == 0x20 || (flag1 == 9)))))) break;
      if (flag3) {
        if (arg3 == (uint8_t *)0x0) {
          if ((*(uint8_t *)((intptr_t)&DAT_00585ac0 + flag1 + 1) & 4) != 0) {
            bptr4 = bptr4 + 1;
            *arg5 = *arg5 + 1;
          }
        }
        else {
          if ((*(uint8_t *)((intptr_t)&DAT_00585ac0 + flag1 + 1) & 4) != 0) {
            *arg3 = flag1;
            arg3 = arg3 + 1;
            bptr4 = bptr4 + 1;
            *arg5 = *arg5 + 1;
          }
          *arg3 = *bptr4;
          arg3 = arg3 + 1;
        }
        *arg5 = *arg5 + 1;
      }
      bptr4 = bptr4 + 1;
    }
    if (arg3 != (uint8_t *)0x0) {
      *arg3 = 0;
      arg3 = arg3 + 1;
    }
    *arg5 = *arg5 + 1;
  }
  if (uptr6 != (uint32_t *)0x0) {
    *uptr6 = 0;
  }
  *arg4 = *arg4 + 1;
  return;
}
