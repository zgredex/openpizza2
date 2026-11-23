// CRT_FormatExponent: ported from Pizza Connection 2 at 0x551b47.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x551b47
#include "pc2_port.h"

uint8_t * __cdecl
CRT_FormatExponent(uint8_t *arg1,int arg2,int arg3,int *arg4,char arg5)

{
  uint8_t *uptr1;
  uint8_t *uptr2;
  uint32_t *uptr3;
  int value4;
  
  if (arg5 != '\0') {
    String_MakeRoomAtFront(arg1 + (*arg4 == 0x2d),(uint32_t)(0 < arg2));
  }
  uptr1 = arg1;
  if (*arg4 == 0x2d) {
    *arg1 = 0x2d;
    uptr1 = arg1 + 1;
  }
  uptr2 = uptr1;
  if (0 < arg2) {
    uptr2 = uptr1 + 1;
    *uptr1 = uptr1[1];
    *uptr2 = DAT_00576cf4;
  }
  uptr3 = _strcpy((uint32_t *)(uptr2 + arg2 + (uint32_t)(arg5 == '\0')),(uint32_t *)"e+000");
  if (arg3 != 0) {
    *(uint8_t *)uptr3 = 0x45;
  }
  if (*(char *)arg4[3] != '0') {
    value4 = arg4[1] + -1;
    if (value4 < 0) {
      value4 = -value4;
      *(uint8_t *)((intptr_t)uptr3 + 1) = 0x2d;
    }
    if (99 < value4) {
      *(char *)((intptr_t)uptr3 + 2) = *(char *)((intptr_t)uptr3 + 2) + (char)(value4 / 100);
      value4 = value4 % 100;
    }
    if (9 < value4) {
      *(char *)((intptr_t)uptr3 + 3) = *(char *)((intptr_t)uptr3 + 3) + (char)(value4 / 10);
      value4 = value4 % 10;
    }
    *(char *)(uptr3 + 1) = (char)uptr3[1] + (char)value4;
  }
  return arg1;
}
