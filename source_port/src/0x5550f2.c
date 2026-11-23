// CRT_HeapFreeBlock: ported from Pizza Connection 2 at 0x5550f2.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5550f2
#include "pc2_port.h"

uint32_t __cdecl CRT_HeapFreeBlock(uint32_t *arg1,int arg2,int arg3)

{
  char *cptr1;
  int *ptr2;
  int value3;
  char cVar4;
  uint32_t uvalue5;
  int value6;
  uint32_t *uptr7;
  int value8;
  uint32_t uvalue9;
  uint32_t uvalue10;
  uint32_t uvalue11;
  uint32_t uvalue12;
  uint32_t local_c;
  
  uvalue5 = arg1[4];
  uvalue11 = arg3 + 0x17U & 0xfffffff0;
  uvalue9 = arg2 - arg1[3] >> 0xf;
  value3 = uvalue9 * 0x204 + 0x144 + uvalue5;
  value6 = *(int *)(arg2 + -4);
  value8 = value6 + -1;
  uvalue12 = *(uint32_t *)(value6 + -5 + arg2);
  value6 = value6 + -5 + arg2;
  if (value8 < (intptr_t)uvalue11) {
    if (((uvalue12 & 1) != 0) || ((intptr_t)(uvalue12 + value8) < (intptr_t)uvalue11)) {
      return 0;
    }
    local_c = ((intptr_t)uvalue12 >> 4) - 1;
    if (0x3f < local_c) {
      local_c = 0x3f;
    }
    if (*(int *)(value6 + 4) == *(int *)(value6 + 8)) {
      if (local_c < 0x20) {
        cptr1 = (char *)(local_c + 4 + uvalue5);
        uvalue10 = ~(0x80000000U >> ((uint8_t)local_c & 0x1f));
        uptr7 = (uint32_t *)(uvalue5 + 0x44 + uvalue9 * 4);
        *uptr7 = *uptr7 & uvalue10;
        *cptr1 = *cptr1 + -1;
        if (*cptr1 == '\0') {
          *arg1 = *arg1 & uvalue10;
        }
      }
      else {
        cptr1 = (char *)(local_c + 4 + uvalue5);
        uvalue10 = ~(0x80000000U >> ((uint8_t)local_c - 0x20 & 0x1f));
        uptr7 = (uint32_t *)(uvalue5 + 0xc4 + uvalue9 * 4);
        *uptr7 = *uptr7 & uvalue10;
        *cptr1 = *cptr1 + -1;
        if (*cptr1 == '\0') {
          arg1[1] = arg1[1] & uvalue10;
        }
      }
    }
    *(uint32_t *)(*(int *)(value6 + 8) + 4) = *(uint32_t *)(value6 + 4);
    *(uint32_t *)(*(int *)(value6 + 4) + 8) = *(uint32_t *)(value6 + 8);
    value6 = uvalue12 + (value8 - uvalue11);
    if (0 < value6) {
      uvalue12 = (value6 >> 4) - 1;
      value8 = arg2 + -4 + uvalue11;
      if (0x3f < uvalue12) {
        uvalue12 = 0x3f;
      }
      value3 = value3 + uvalue12 * 8;
      *(uint32_t *)(value8 + 4) = *(uint32_t *)(value3 + 4);
      *(int *)(value8 + 8) = value3;
      *(int *)(value3 + 4) = value8;
      *(int *)(*(int *)(value8 + 4) + 8) = value8;
      if (*(int *)(value8 + 4) == *(int *)(value8 + 8)) {
        cVar4 = *(char *)(uvalue12 + 4 + uvalue5);
        *(char *)(uvalue12 + 4 + uvalue5) = cVar4 + '\x01';
        if (uvalue12 < 0x20) {
          if (cVar4 == '\0') {
            *arg1 = *arg1 | 0x80000000U >> ((uint8_t)uvalue12 & 0x1f);
          }
          uptr7 = (uint32_t *)(uvalue5 + 0x44 + uvalue9 * 4);
        }
        else {
          if (cVar4 == '\0') {
            arg1[1] = arg1[1] | 0x80000000U >> ((uint8_t)uvalue12 - 0x20 & 0x1f);
          }
          uptr7 = (uint32_t *)(uvalue5 + 0xc4 + uvalue9 * 4);
          uvalue12 = uvalue12 - 0x20;
        }
        *uptr7 = *uptr7 | 0x80000000U >> ((uint8_t)uvalue12 & 0x1f);
      }
      ptr2 = (int *)(arg2 + -4 + uvalue11);
      *ptr2 = value6;
      *(int *)(value6 + -4 + (intptr_t)ptr2) = value6;
    }
    *(uint32_t *)(arg2 + -4) = uvalue11 + 1;
    *(uint32_t *)(arg2 + -8 + uvalue11) = uvalue11 + 1;
  }
  else if ((intptr_t)uvalue11 < value8) {
    arg3 = value8 - uvalue11;
    *(uint32_t *)(arg2 + -4) = uvalue11 + 1;
    ptr2 = (int *)(arg2 + -4 + uvalue11);
    uvalue10 = (arg3 >> 4) - 1;
    ptr2[-1] = uvalue11 + 1;
    if (0x3f < uvalue10) {
      uvalue10 = 0x3f;
    }
    if ((uvalue12 & 1) == 0) {
      uvalue11 = ((intptr_t)uvalue12 >> 4) - 1;
      if (0x3f < uvalue11) {
        uvalue11 = 0x3f;
      }
      if (*(int *)(value6 + 4) == *(int *)(value6 + 8)) {
        if (uvalue11 < 0x20) {
          cptr1 = (char *)(uvalue11 + 4 + uvalue5);
          uvalue11 = ~(0x80000000U >> ((uint8_t)uvalue11 & 0x1f));
          uptr7 = (uint32_t *)(uvalue5 + 0x44 + uvalue9 * 4);
          *uptr7 = *uptr7 & uvalue11;
          *cptr1 = *cptr1 + -1;
          if (*cptr1 == '\0') {
            *arg1 = *arg1 & uvalue11;
          }
        }
        else {
          cptr1 = (char *)(uvalue11 + 4 + uvalue5);
          uvalue11 = ~(0x80000000U >> ((uint8_t)uvalue11 - 0x20 & 0x1f));
          uptr7 = (uint32_t *)(uvalue5 + 0xc4 + uvalue9 * 4);
          *uptr7 = *uptr7 & uvalue11;
          *cptr1 = *cptr1 + -1;
          if (*cptr1 == '\0') {
            arg1[1] = arg1[1] & uvalue11;
          }
        }
      }
      *(uint32_t *)(*(int *)(value6 + 8) + 4) = *(uint32_t *)(value6 + 4);
      *(uint32_t *)(*(int *)(value6 + 4) + 8) = *(uint32_t *)(value6 + 8);
      arg3 = arg3 + uvalue12;
      uvalue10 = (arg3 >> 4) - 1;
      if (0x3f < uvalue10) {
        uvalue10 = 0x3f;
      }
    }
    value6 = value3 + uvalue10 * 8;
    ptr2[1] = *(int *)(value3 + 4 + uvalue10 * 8);
    ptr2[2] = value6;
    *(int **)(value6 + 4) = ptr2;
    *(int **)(ptr2[1] + 8) = ptr2;
    if (ptr2[1] == ptr2[2]) {
      cVar4 = *(char *)(uvalue10 + 4 + uvalue5);
      *(char *)(uvalue10 + 4 + uvalue5) = cVar4 + '\x01';
      if (uvalue10 < 0x20) {
        if (cVar4 == '\0') {
          *arg1 = *arg1 | 0x80000000U >> ((uint8_t)uvalue10 & 0x1f);
        }
        uptr7 = (uint32_t *)(uvalue5 + 0x44 + uvalue9 * 4);
      }
      else {
        if (cVar4 == '\0') {
          arg1[1] = arg1[1] | 0x80000000U >> ((uint8_t)uvalue10 - 0x20 & 0x1f);
        }
        uptr7 = (uint32_t *)(uvalue5 + 0xc4 + uvalue9 * 4);
        uvalue10 = uvalue10 - 0x20;
      }
      *uptr7 = *uptr7 | 0x80000000U >> ((uint8_t)uvalue10 & 0x1f);
    }
    *ptr2 = arg3;
    *(int *)(arg3 + -4 + (intptr_t)ptr2) = arg3;
  }
  return 1;
}
