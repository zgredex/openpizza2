// CRT_Malloc: ported from Pizza Connection 2 at 0x554c3d.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x554c3d
#include "pc2_port.h"

int * __cdecl CRT_Malloc(uint32_t *arg1)

{
  uint32_t *uptr1;
  char *cptr2;
  int *ptr3;
  char cVar4;
  int *ptr5;
  uint8_t flag6;
  uint32_t uvalue7;
  int value8;
  int value9;
  uint32_t *uptr10;
  int value11;
  int *ptr12;
  uint32_t uvalue13;
  uint32_t local_10;
  uint32_t local_c;
  int local_8;
  
  uptr10 = DAT_00585bdc + DAT_00585bd8 * 5;
  uvalue7 = (intptr_t)arg1 + 0x17U & 0xfffffff0;
  value8 = (intptr_t)((intptr_t)arg1 + 0x17U) >> 4;
  value9 = value8 + -1;
  if (value9 < 0x20) {
    local_10 = 0xffffffff >> ((uint8_t)value9 & 0x1f);
    local_c = 0xffffffff;
  }
  else {
    local_c = 0xffffffff >> ((char)value8 - 0x21U & 0x1f);
    local_10 = 0;
  }
  for (arg1 = DAT_00585bd0;
      (arg1 < uptr10 && ((arg1[1] & local_c) == 0 && (*arg1 & local_10) == 0));
      arg1 = arg1 + 5) {
  }
  if (arg1 == uptr10) {
    for (arg1 = DAT_00585bdc;
        (arg1 < DAT_00585bd0 && ((arg1[1] & local_c) == 0 && (*arg1 & local_10) == 0));
        arg1 = arg1 + 5) {
    }
    if (arg1 == DAT_00585bd0) {
      for (; (arg1 < uptr10 && (arg1[2] == 0)); arg1 = arg1 + 5) {
      }
      if (arg1 == uptr10) {
        for (arg1 = DAT_00585bdc; (arg1 < DAT_00585bd0 && (arg1[2] == 0));
            arg1 = arg1 + 5) {
        }
        if ((arg1 == DAT_00585bd0) &&
           (arg1 = CRT_SmallBlockNewRegion(), arg1 == (uint32_t *)0x0)) {
          return (int *)0x0;
        }
      }
      value8 = CRT_HeapCreateRegion((intptr_t)arg1);
      *(int *)arg1[4] = value8;
      if (*(int *)arg1[4] == -1) {
        return (int *)0x0;
      }
    }
  }
  ptr5 = (int *)arg1[4];
  local_8 = *ptr5;
  if ((local_8 == -1) ||
     ((ptr5[local_8 + 0x31] & local_c) == 0 && (ptr5[local_8 + 0x11] & local_10) == 0)) {
    local_8 = 0;
    uptr10 = (uint32_t *)(ptr5 + 0x11);
    if ((ptr5[0x31] & local_c) == 0 && (ptr5[0x11] & local_10) == 0) {
      do {
        uptr1 = uptr10 + 0x21;
        local_8 = local_8 + 1;
        uptr10 = uptr10 + 1;
      } while ((*uptr1 & local_c) == 0 && (local_10 & *uptr10) == 0);
    }
  }
  value8 = 0;
  ptr3 = ptr5 + local_8 * 0x81 + 0x51;
  local_10 = ptr5[local_8 + 0x11] & local_10;
  if (local_10 == 0) {
    local_10 = ptr5[local_8 + 0x31] & local_c;
    value8 = 0x20;
  }
  for (; -1 < (intptr_t)local_10; local_10 = local_10 << 1) {
    value8 = value8 + 1;
  }
  ptr12 = (int *)ptr3[value8 * 2 + 1];
  value11 = *ptr12 - uvalue7;
  value9 = (value11 >> 4) + -1;
  if (0x3f < value9) {
    value9 = 0x3f;
  }
  DAT_00585bd0 = arg1;
  if (value9 != value8) {
    if (ptr12[1] == ptr12[2]) {
      if (value8 < 0x20) {
        cptr2 = (char *)((intptr_t)ptr5 + value8 + 4);
        uvalue13 = ~(0x80000000U >> ((uint8_t)value8 & 0x1f));
        ptr5[local_8 + 0x11] = uvalue13 & ptr5[local_8 + 0x11];
        *cptr2 = *cptr2 + -1;
        if (*cptr2 == '\0') {
          *arg1 = *arg1 & uvalue13;
        }
      }
      else {
        cptr2 = (char *)((intptr_t)ptr5 + value8 + 4);
        uvalue13 = ~(0x80000000U >> ((uint8_t)value8 - 0x20 & 0x1f));
        ptr5[local_8 + 0x31] = ptr5[local_8 + 0x31] & uvalue13;
        *cptr2 = *cptr2 + -1;
        if (*cptr2 == '\0') {
          arg1[1] = arg1[1] & uvalue13;
        }
      }
    }
    *(int *)(ptr12[2] + 4) = ptr12[1];
    *(int *)(ptr12[1] + 8) = ptr12[2];
    if (value11 == 0) goto LAB_00554f03;
    ptr12[1] = ptr3[value9 * 2 + 1];
    ptr12[2] = (intptr_t)(ptr3 + value9 * 2);
    (ptr3 + value9 * 2)[1] = (intptr_t)ptr12;
    *(int **)(ptr12[1] + 8) = ptr12;
    if (ptr12[1] == ptr12[2]) {
      cVar4 = *(char *)(value9 + 4 + (intptr_t)ptr5);
      flag6 = (uint8_t)value9;
      if (value9 < 0x20) {
        *(char *)(value9 + 4 + (intptr_t)ptr5) = cVar4 + '\x01';
        if (cVar4 == '\0') {
          *arg1 = *arg1 | 0x80000000U >> (flag6 & 0x1f);
        }
        ptr5[local_8 + 0x11] = ptr5[local_8 + 0x11] | 0x80000000U >> (flag6 & 0x1f);
      }
      else {
        *(char *)(value9 + 4 + (intptr_t)ptr5) = cVar4 + '\x01';
        if (cVar4 == '\0') {
          arg1[1] = arg1[1] | 0x80000000U >> (flag6 - 0x20 & 0x1f);
        }
        ptr5[local_8 + 0x31] = ptr5[local_8 + 0x31] | 0x80000000U >> (flag6 - 0x20 & 0x1f);
      }
    }
  }
  if (value11 != 0) {
    *ptr12 = value11;
    *(int *)(value11 + -4 + (intptr_t)ptr12) = value11;
  }
LAB_00554f03:
  ptr12 = (int *)((intptr_t)ptr12 + value11);
  *ptr12 = uvalue7 + 1;
  *(uint32_t *)((intptr_t)ptr12 + (uvalue7 - 4)) = uvalue7 + 1;
  value8 = *ptr3;
  *ptr3 = value8 + 1;
  if (((value8 == 0) && (arg1 == DAT_00585bd4)) && (local_8 == DAT_00585bcc)) {
    DAT_00585bd4 = (uint32_t *)0x0;
  }
  *ptr5 = local_8;
  return ptr12 + 1;
}
