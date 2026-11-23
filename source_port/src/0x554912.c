// CRT_Free: ported from Pizza Connection 2 at 0x554912.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x554912
#include "pc2_port.h"

void __cdecl CRT_Free(uint32_t *arg1,uint32_t arg2)

{
  char *cptr1;
  uint32_t *uptr2;
  int *ptr3;
  char cVar4;
  uint32_t uvalue5;
  int value6;
  uint32_t uvalue7;
  uint8_t flag8;
  int *ptr9;
  uint32_t uvalue10;
  uint32_t uvalue11;
  uint32_t uvalue12;
  int local_10;
  
  uvalue5 = arg1[4];
  value6 = *(int *)(arg2 - 4);
  ptr9 = (int *)(arg2 - 4);
  uvalue10 = arg2 - arg1[3] >> 0xf;
  uvalue7 = *(uint32_t *)(arg2 - 8);
  local_10 = value6 + -1;
  ptr3 = (int *)(uvalue10 * 0x204 + 0x144 + uvalue5);
  uvalue12 = *(uint32_t *)(local_10 + (intptr_t)ptr9);
  if ((uvalue12 & 1) == 0) {
    arg2 = ((intptr_t)uvalue12 >> 4) - 1;
    if (0x3f < arg2) {
      arg2 = 0x3f;
    }
    if (*(int *)(value6 + 3 + (intptr_t)ptr9) == *(int *)(value6 + 7 + (intptr_t)ptr9)) {
      if (arg2 < 0x20) {
        cptr1 = (char *)(arg2 + 4 + uvalue5);
        uvalue11 = ~(0x80000000U >> ((uint8_t)arg2 & 0x1f));
        uptr2 = (uint32_t *)(uvalue5 + 0x44 + uvalue10 * 4);
        *uptr2 = *uptr2 & uvalue11;
        *cptr1 = *cptr1 + -1;
        if (*cptr1 == '\0') {
          *arg1 = *arg1 & uvalue11;
        }
      }
      else {
        cptr1 = (char *)(arg2 + 4 + uvalue5);
        uvalue11 = ~(0x80000000U >> ((uint8_t)arg2 - 0x20 & 0x1f));
        uptr2 = (uint32_t *)(uvalue5 + 0xc4 + uvalue10 * 4);
        *uptr2 = *uptr2 & uvalue11;
        *cptr1 = *cptr1 + -1;
        if (*cptr1 == '\0') {
          arg1[1] = arg1[1] & uvalue11;
        }
      }
    }
    *(uint32_t *)(*(int *)(value6 + 7 + (intptr_t)ptr9) + 4) =
         *(uint32_t *)(value6 + 3 + (intptr_t)ptr9);
    local_10 = local_10 + uvalue12;
    *(uint32_t *)(*(int *)(value6 + 3 + (intptr_t)ptr9) + 8) =
         *(uint32_t *)(value6 + 7 + (intptr_t)ptr9);
  }
  uvalue12 = (local_10 >> 4) - 1;
  if (0x3f < uvalue12) {
    uvalue12 = 0x3f;
  }
  if ((uvalue7 & 1) == 0) {
    ptr9 = (int *)((intptr_t)ptr9 - uvalue7);
    arg2 = ((intptr_t)uvalue7 >> 4) - 1;
    if (0x3f < arg2) {
      arg2 = 0x3f;
    }
    local_10 = local_10 + uvalue7;
    uvalue12 = (local_10 >> 4) - 1;
    if (0x3f < uvalue12) {
      uvalue12 = 0x3f;
    }
    if (arg2 != uvalue12) {
      if (ptr9[1] == ptr9[2]) {
        if (arg2 < 0x20) {
          cptr1 = (char *)(arg2 + 4 + uvalue5);
          uvalue11 = ~(0x80000000U >> ((uint8_t)arg2 & 0x1f));
          uptr2 = (uint32_t *)(uvalue5 + 0x44 + uvalue10 * 4);
          *uptr2 = *uptr2 & uvalue11;
          *cptr1 = *cptr1 + -1;
          if (*cptr1 == '\0') {
            *arg1 = *arg1 & uvalue11;
          }
        }
        else {
          cptr1 = (char *)(arg2 + 4 + uvalue5);
          uvalue11 = ~(0x80000000U >> ((uint8_t)arg2 - 0x20 & 0x1f));
          uptr2 = (uint32_t *)(uvalue5 + 0xc4 + uvalue10 * 4);
          *uptr2 = *uptr2 & uvalue11;
          *cptr1 = *cptr1 + -1;
          if (*cptr1 == '\0') {
            arg1[1] = arg1[1] & uvalue11;
          }
        }
      }
      *(int *)(ptr9[2] + 4) = ptr9[1];
      *(int *)(ptr9[1] + 8) = ptr9[2];
    }
  }
  if (((uvalue7 & 1) != 0) || (arg2 != uvalue12)) {
    ptr9[1] = ptr3[uvalue12 * 2 + 1];
    ptr9[2] = (intptr_t)(ptr3 + uvalue12 * 2);
    (ptr3 + uvalue12 * 2)[1] = (intptr_t)ptr9;
    *(int **)(ptr9[1] + 8) = ptr9;
    if (ptr9[1] == ptr9[2]) {
      cVar4 = *(char *)(uvalue12 + 4 + uvalue5);
      *(char *)(uvalue12 + 4 + uvalue5) = cVar4 + '\x01';
      flag8 = (uint8_t)uvalue12;
      if (uvalue12 < 0x20) {
        if (cVar4 == '\0') {
          *arg1 = *arg1 | 0x80000000U >> (flag8 & 0x1f);
        }
        uptr2 = (uint32_t *)(uvalue5 + 0x44 + uvalue10 * 4);
        *uptr2 = *uptr2 | 0x80000000U >> (flag8 & 0x1f);
      }
      else {
        if (cVar4 == '\0') {
          arg1[1] = arg1[1] | 0x80000000U >> (flag8 - 0x20 & 0x1f);
        }
        uptr2 = (uint32_t *)(uvalue5 + 0xc4 + uvalue10 * 4);
        *uptr2 = *uptr2 | 0x80000000U >> (flag8 - 0x20 & 0x1f);
      }
    }
  }
  *ptr9 = local_10;
  *(int *)(local_10 + -4 + (intptr_t)ptr9) = local_10;
  *ptr3 = *ptr3 + -1;
  if (*ptr3 != 0) {
    return;
  }
  if (DAT_00585bd4 != (uint32_t *)0x0) {
    VirtualFree((LPVOID)(DAT_00585bcc * 0x8000 + DAT_00585bd4[3]),0x8000,0x4000);
    DAT_00585bd4[2] = DAT_00585bd4[2] | 0x80000000U >> ((uint8_t)DAT_00585bcc & 0x1f);
    *(uint32_t *)(DAT_00585bd4[4] + 0xc4 + DAT_00585bcc * 4) = 0;
    *(char *)(DAT_00585bd4[4] + 0x43) = *(char *)(DAT_00585bd4[4] + 0x43) + -1;
    if (*(char *)(DAT_00585bd4[4] + 0x43) == '\0') {
      DAT_00585bd4[1] = DAT_00585bd4[1] & 0xfffffffe;
    }
    if (DAT_00585bd4[2] == 0xffffffff) {
      VirtualFree((LPVOID)DAT_00585bd4[3],0,0x8000);
      HeapFree(DAT_00585be0,0,(LPVOID)DAT_00585bd4[4]);
      _memmove(DAT_00585bd4,DAT_00585bd4 + 5,
               (DAT_00585bd8 * 0x14 - (intptr_t)DAT_00585bd4) + -0x14 + DAT_00585bdc);
      DAT_00585bd8 = DAT_00585bd8 + -1;
      if (DAT_00585bd4 < arg1) {
        arg1 = arg1 + -5;
      }
      DAT_00585bcc = uvalue10;
      DAT_00585bd0 = DAT_00585bdc;
      DAT_00585bd4 = arg1;
      return;
    }
  }
  DAT_00585bd4 = arg1;
  DAT_00585bcc = uvalue10;
  return;
}
