// CRT_OpenFile: ported from Pizza Connection 2 at 0x5520f9.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5520f9
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint32_t * __cdecl CRT_OpenFile(LPCSTR arg1,char *arg2,uint32_t arg3,uint32_t *arg4)

{
  char cVar1;
  bool flag2;
  bool flag3;
  bool flag4;
  uint32_t uvalue5;
  uint32_t uvalue6;
  
  flag4 = false;
  flag3 = false;
  cVar1 = *arg2;
  if (cVar1 == 'a') {
    uvalue5 = 0x109;
  }
  else {
    if (cVar1 == 'r') {
      uvalue5 = 0;
      uvalue6 = DAT_005858fc | 1;
      goto LAB_0055213a;
    }
    if (cVar1 != 'w') {
      return (uint32_t *)0x0;
    }
    uvalue5 = 0x301;
  }
  uvalue6 = DAT_005858fc | 2;
LAB_0055213a:
  flag2 = true;
LAB_0055213d:
  cVar1 = arg2[1];
  arg2 = arg2 + 1;
  if ((cVar1 == '\0') || (!flag2)) {
    uvalue5 = CRT_Sopen(arg1,uvalue5,arg3,0x1a4);
    if ((intptr_t)uvalue5 < 0) {
      return (uint32_t *)0x0;
    }
    _DAT_00585660 = _DAT_00585660 + 1;
    arg4[3] = uvalue6;
    arg4[1] = 0;
    *arg4 = 0;
    arg4[2] = 0;
    arg4[7] = 0;
    arg4[4] = uvalue5;
    return arg4;
  }
  if (cVar1 < 'U') {
    if (cVar1 == 'T') {
      if ((uvalue5 & 0x1000) == 0) {
        uvalue5 = uvalue5 | 0x1000;
        goto LAB_0055213d;
      }
    }
    else if (cVar1 == '+') {
      if ((uvalue5 & 2) == 0) {
        uvalue5 = uvalue5 & 0xfffffffe | 2;
        uvalue6 = uvalue6 & 0xfffffffc | 0x80;
        goto LAB_0055213d;
      }
    }
    else if (cVar1 == 'D') {
      if ((uvalue5 & 0x40) == 0) {
        uvalue5 = uvalue5 | 0x40;
        goto LAB_0055213d;
      }
    }
    else if (cVar1 == 'R') {
      if (!flag3) {
        flag3 = true;
        uvalue5 = uvalue5 | 0x10;
        goto LAB_0055213d;
      }
    }
    else if ((cVar1 == 'S') && (!flag3)) {
      flag3 = true;
      uvalue5 = uvalue5 | 0x20;
      goto LAB_0055213d;
    }
  }
  else {
    if (cVar1 == 'b') {
      if ((uvalue5 & 0xc000) != 0) goto LAB_0055221d;
      uvalue5 = uvalue5 | 0x8000;
      goto LAB_0055213d;
    }
    if (cVar1 == 'c') {
      if (!flag4) {
        flag4 = true;
        uvalue6 = uvalue6 | 0x4000;
        goto LAB_0055213d;
      }
    }
    else {
      if (cVar1 != 'n') {
        if ((cVar1 != 't') || ((uvalue5 & 0xc000) != 0)) goto LAB_0055221d;
        uvalue5 = uvalue5 | 0x4000;
        goto LAB_0055213d;
      }
      if (!flag4) {
        flag4 = true;
        uvalue6 = uvalue6 & 0xffffbfff;
        goto LAB_0055213d;
      }
    }
  }
LAB_0055221d:
  flag2 = false;
  goto LAB_0055213d;
}
