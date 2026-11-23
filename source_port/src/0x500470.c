// Map_FindEdgeDot: ported from Pizza Connection 2 at 0x500470.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x500470
#include "pc2_port.h"

uint32_t __cdecl Map_FindEdgeDot(int arg1,int *arg2,int *arg3,uint32_t *arg4,int arg5)

{
  bool flag1;
  uint32_t uvalue2;
  int value3;
  int value4;
  char *cptr5;
  char *cptr6;
  
  flag1 = false;
  if ((char)arg5 == '\0') {
    uvalue2 = _rand();
    *arg4 = uvalue2 & 3;
  }
  else {
    *arg4 = 0;
  }
  uvalue2 = *arg4;
  if (uvalue2 == 0) {
    arg5 = 0;
    value4 = arg1 + 0x28;
    do {
      value3 = 0;
      do {
        if (*(char *)(value4 + value3) == '.') {
          flag1 = true;
          goto LAB_005004ce;
        }
        value3 = value3 + 1;
      } while (value3 < 0x50);
      arg5 = arg5 + 1;
      value4 = value4 + 0x50;
    } while (arg5 < 0x50);
  }
  else {
    value3 = arg5;
  }
LAB_005004ce:
  if (uvalue2 == 1) {
    arg5 = 0x4f;
    value4 = arg1 + 0x18d8;
    do {
      value3 = 0x4f;
      do {
        if (*(char *)(value4 + value3) == '.') {
          flag1 = true;
          goto LAB_005004fc;
        }
        value3 = value3 + -1;
      } while (-1 < value3);
      if (flag1) break;
      arg5 = arg5 - 1;
      value4 = value4 + -0x50;
    } while (-1 < arg5);
  }
LAB_005004fc:
  if (uvalue2 == 2) {
    value3 = 0;
    cptr6 = (char *)(arg1 + 0x18d8);
    do {
      arg5 = 0x4f;
      cptr5 = cptr6;
      do {
        if (*cptr5 == '.') {
          flag1 = true;
          goto LAB_0050052c;
        }
        arg5 = arg5 - 1;
        cptr5 = cptr5 + -0x50;
      } while (-1 < arg5);
      if (flag1) break;
      value3 = value3 + 1;
      cptr6 = cptr6 + 1;
    } while (value3 < 0x50);
  }
LAB_0050052c:
  if (uvalue2 == 3) {
    value3 = 0x4f;
    cptr6 = (char *)(arg1 + 0x1927);
    do {
      arg5 = 0x4f;
      cptr5 = cptr6;
      do {
        if (*cptr5 == '.') goto LAB_00500567;
        arg5 = arg5 - 1;
        cptr5 = cptr5 + -0x50;
      } while (-1 < arg5);
      if (flag1) goto LAB_00500567;
      value3 = value3 + -1;
      cptr6 = cptr6 + -1;
    } while (-1 < value3);
  }
  else if (flag1) {
LAB_00500567:
    *arg2 = arg5;
    *arg3 = value3;
    return CONCAT31((int3)((uint32_t)arg3 >> 8),1);
  }
  return arg5 & 0xffffff00;
}
