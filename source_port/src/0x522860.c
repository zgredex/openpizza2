// UI_EditFieldHandleKey: ported from Pizza Connection 2 at 0x522860.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x522860
#include "pc2_port.h"

uint32_t __thiscall UI_EditFieldHandleKey(void *self,uint32_t arg1)

{
  char cVar1;
  int value2;
  uint8_t uvalue3;
  uint8_t uvalue4;
  int value5;
  uint32_t uvalue6;
  char *cptr7;
  uint32_t extraout_var;
  uint32_t extraout_var_00;
  uint32_t extraout_var_01;
  uint32_t uvalue8;
  uint32_t *uptr9;
  
  value5 = Font_MeasureText(*(void **)((intptr_t)self + 0x54),*(char **)((intptr_t)self + 0x6c));
  if ((0x1f < (intptr_t)arg1) && ((intptr_t)arg1 < 0x100)) {
    value2 = *(int *)((intptr_t)self + 0x58);
    if ((value2 == 2) && (((intptr_t)arg1 < 0x30 || (0x39 < (intptr_t)arg1)))) {
      return 0;
    }
    if (value2 == 1) {
      if ((arg1 == 0x2b) || (arg1 == 0x2d)) {
        if (*(int *)((intptr_t)self + 0x80) != 0) {
          return 0;
        }
      }
      else if (((intptr_t)arg1 < 0x30) || (0x39 < (intptr_t)arg1)) {
        return 0;
      }
    }
    if ((value2 == 3) || (value2 == 4)) {
      uvalue6 = CRT_Toupper(arg1);
      cptr7 = _strchr(s_ABCDEFGHIJKLMNOPQRSTUVWXYZ012345_00573c6c,uvalue6);
      if (cptr7 == (char *)0x0) {
        return 0;
      }
      if ((*(int *)((intptr_t)self + 0x58) == 3) && (arg1 == 0x2e)) {
        return 0;
      }
    }
    if (*(int *)((intptr_t)self + 0x98) != 0) {
      uvalue8 = *(int *)((intptr_t)self + 0x78) + 1;
      uptr9 = *(uint32_t **)((intptr_t)self + 0x6c);
      for (uvalue6 = uvalue8 >> 2; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
        *uptr9 = 0;
        uptr9 = uptr9 + 1;
      }
      for (uvalue8 = uvalue8 & 3; uvalue8 != 0; uvalue8 = uvalue8 - 1) {
        *(uint8_t *)uptr9 = 0;
        uptr9 = (uint32_t *)((intptr_t)uptr9 + 1);
      }
      *(uint32_t *)((intptr_t)self + 0x80) = 0;
      *(uint32_t *)((intptr_t)self + 0x98) = 0;
      value5 = 0;
    }
    if (*(int *)((intptr_t)self + 0x7c) == 0) {
      uvalue3 = Font_GetCharWidth(*(void **)((intptr_t)self + 0x54),
                                (uint32_t)*(uint8_t *)(*(int *)((intptr_t)self + 0x80) +
                                               *(int *)((intptr_t)self + 0x6c)));
      uvalue4 = Font_GetCharWidth(*(void **)((intptr_t)self + 0x54),arg1);
      if (*(int *)((intptr_t)self + 0x84) <=
          (value5 - CONCAT31(extraout_var_00,uvalue3)) + CONCAT31(extraout_var_01,uvalue4)) {
        return 0;
      }
      uvalue6 = 0xffffffff;
      cptr7 = *(char **)((intptr_t)self + 0x6c);
      do {
        if (uvalue6 == 0) break;
        uvalue6 = uvalue6 - 1;
        cVar1 = *cptr7;
        cptr7 = cptr7 + 1;
      } while (cVar1 != '\0');
      if (*(uint32_t *)((intptr_t)self + 0x78) <= ~uvalue6) {
        return 0;
      }
      (*(char **)((intptr_t)self + 0x6c))[*(int *)((intptr_t)self + 0x80)] = (char)arg1;
LAB_005229f5:
      *(int *)((intptr_t)self + 0x80) = *(int *)((intptr_t)self + 0x80) + 1;
    }
    else {
      uvalue3 = Font_GetCharWidth(*(void **)((intptr_t)self + 0x54),arg1);
      if (*(int *)((intptr_t)self + 0x84) <= value5 + CONCAT31(extraout_var,uvalue3)) {
        return 0;
      }
      uvalue6 = 0xffffffff;
      cptr7 = *(char **)((intptr_t)self + 0x6c);
      do {
        if (uvalue6 == 0) break;
        uvalue6 = uvalue6 - 1;
        cVar1 = *cptr7;
        cptr7 = cptr7 + 1;
      } while (cVar1 != '\0');
      if (*(uint32_t *)((intptr_t)self + 0x78) <= ~uvalue6) {
        return 0;
      }
      uvalue6 = (*(uint32_t *)((intptr_t)self + 0x78) - *(int *)((intptr_t)self + 0x80)) - 1;
      if (0 < (intptr_t)uvalue6) {
        cptr7 = *(char **)((intptr_t)self + 0x6c) + *(int *)((intptr_t)self + 0x80);
        _memmove((uint32_t *)(cptr7 + 1),(uint32_t *)cptr7,uvalue6);
        *(char *)(*(int *)((intptr_t)self + 0x80) + *(int *)((intptr_t)self + 0x6c)) = (char)arg1;
        goto LAB_005229f5;
      }
    }
    *(uint32_t *)((intptr_t)self + 0x88) = 0xfffffc19;
    goto switchD_00522a7a_caseD_12d;
  }
  if (*(int *)((intptr_t)self + 0x98) == 0) goto switchD_00522a29_caseD_12d;
  switch(arg1) {
  case 300:
  case 0x138:
    uvalue8 = *(int *)((intptr_t)self + 0x78) + 1;
    uptr9 = *(uint32_t **)((intptr_t)self + 0x6c);
    for (uvalue6 = uvalue8 >> 2; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
      *uptr9 = 0;
      uptr9 = uptr9 + 1;
    }
    for (uvalue8 = uvalue8 & 3; uvalue8 != 0; uvalue8 = uvalue8 - 1) {
      *(uint8_t *)uptr9 = 0;
      uptr9 = (uint32_t *)((intptr_t)uptr9 + 1);
    }
    *(uint32_t *)((intptr_t)self + 0x80) = 0;
    *(uint32_t *)((intptr_t)self + 0x98) = 0;
    *(uint32_t *)((intptr_t)self + 0x88) = 0xfffffc19;
    break;
  case 0x12e:
  case 0x131:
  case 0x133:
  case 0x134:
    *(uint32_t *)((intptr_t)self + 0x98) = 0;
  default:
switchD_00522a29_caseD_12d:
  }
  switch(arg1) {
  case 300:
    value5 = *(int *)((intptr_t)self + 0x80);
    if (value5 != 0) {
      *(uint32_t *)((intptr_t)self + 0x88) = 0xfffffc19;
      uvalue6 = *(int *)((intptr_t)self + 0x78) - value5;
      if (0 < (intptr_t)uvalue6) {
        uptr9 = (uint32_t *)(value5 + *(int *)((intptr_t)self + 0x6c));
        _memmove((uint32_t *)((intptr_t)uptr9 + -1),uptr9,uvalue6);
      }
      *(int *)((intptr_t)self + 0x80) = *(int *)((intptr_t)self + 0x80) + -1;
    }
  default:
    goto switchD_00522a7a_caseD_12d;
  case 0x12e:
    *(uint32_t *)((intptr_t)self + 0x80) = 0;
    break;
  case 0x131:
    if (0 < *(int *)((intptr_t)self + 0x80)) {
      *(int *)((intptr_t)self + 0x80) = *(int *)((intptr_t)self + 0x80) + -1;
    }
    break;
  case 0x133:
    if (*(char *)(*(int *)((intptr_t)self + 0x80) + *(int *)((intptr_t)self + 0x6c)) != '\0') {
      *(int *)((intptr_t)self + 0x80) = *(int *)((intptr_t)self + 0x80) + 1;
    }
    break;
  case 0x134:
    uvalue6 = 0xffffffff;
    cptr7 = *(char **)((intptr_t)self + 0x6c);
    do {
      if (uvalue6 == 0) break;
      uvalue6 = uvalue6 - 1;
      cVar1 = *cptr7;
      cptr7 = cptr7 + 1;
    } while (cVar1 != '\0');
    *(uint32_t *)((intptr_t)self + 0x88) = 0xfffffc19;
    *(uint32_t *)((intptr_t)self + 0x80) = ~uvalue6 - 1;
    goto switchD_00522a7a_caseD_12d;
  case 0x137:
    *(uint32_t *)((intptr_t)self + 0x7c) = (uint32_t)(*(int *)((intptr_t)self + 0x7c) == 0);
    break;
  case 0x138:
    value5 = *(int *)((intptr_t)self + 0x80);
    uptr9 = (uint32_t *)(value5 + *(int *)((intptr_t)self + 0x6c));
    if (*(char *)(value5 + *(int *)((intptr_t)self + 0x6c)) == '\0') goto switchD_00522a7a_caseD_12d;
    uvalue6 = (*(int *)((intptr_t)self + 0x78) - value5) - 1;
    if (0 < (intptr_t)uvalue6) {
      _memmove(uptr9,(uint32_t *)((intptr_t)uptr9 + 1),uvalue6);
    }
  }
  *(uint32_t *)((intptr_t)self + 0x88) = 0xfffffc19;
switchD_00522a7a_caseD_12d:
  if (*(int *)((intptr_t)self + 0x88) == -999) {
    UI_ClipRect(*(void **)((intptr_t)self + 8),(int *)((intptr_t)self + 0x28),1);
  }
  return 1;
}
