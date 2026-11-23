// FUN_005577d5: ported from Pizza Connection 2 at 0x5577d5.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5577d5
#include "pc2_port.h"

uint32_t __cdecl FUN_005577d5(uint32_t *arg1,int arg2)

{
  uint32_t *uptr1;
  int value2;
  int *ptr3;
  size_t svalue4;
  uint32_t *lpName;
  uint8_t *bptr5;
  int *ptr6;
  bool flag7;
  
  if (arg1 == (uint32_t *)0x0) {
    return 0xffffffff;
  }
  uptr1 = (uint32_t *)FUN_00557a1b((uint8_t *)arg1,0x3d);
  if (uptr1 == (uint32_t *)0x0) {
    return 0xffffffff;
  }
  if (arg1 == uptr1) {
    return 0xffffffff;
  }
  flag7 = *(uint8_t *)((intptr_t)uptr1 + 1) == 0;
  if (DAT_00585630 == DAT_00585634) {
    DAT_00585630 = FUN_005579b4(DAT_00585630);
  }
  if (DAT_00585630 == (int *)0x0) {
    if ((arg2 == 0) || (DAT_00585638 == (uint32_t *)0x0)) {
      if (flag7) {
        return 0;
      }
      DAT_00585630 = _malloc(4);
      if (DAT_00585630 == (int *)0x0) {
        return 0xffffffff;
      }
      *DAT_00585630 = 0;
      if (DAT_00585638 == (uint32_t *)0x0) {
        DAT_00585638 = _malloc(4);
        if (DAT_00585638 == (uint32_t *)0x0) {
          return 0xffffffff;
        }
        *DAT_00585638 = 0;
      }
    }
    else {
      value2 = FUN_00557050();
      if (value2 != 0) {
        return 0xffffffff;
      }
    }
  }
  ptr3 = DAT_00585630;
  value2 = FUN_0055795c((uint8_t *)arg1,(intptr_t)uptr1 - (intptr_t)arg1);
  if ((value2 < 0) || (*ptr3 == 0)) {
    if (flag7) {
      return 0;
    }
    if (value2 < 0) {
      value2 = -value2;
    }
    ptr3 = CRT_Realloc(ptr3,(uint32_t *)(value2 * 4 + 8));
    if (ptr3 == (int *)0x0) {
      return 0xffffffff;
    }
    ptr3[value2] = (intptr_t)arg1;
    ptr3[value2 + 1] = 0;
  }
  else {
    if (!flag7) {
      ptr3[value2] = (intptr_t)arg1;
      goto LAB_00557909;
    }
    ptr6 = ptr3 + value2;
    CRT_FreeInternal((LPVOID)ptr3[value2]);
    for (; *ptr6 != 0; ptr6 = ptr6 + 1) {
      value2 = value2 + 1;
      *ptr6 = ptr6[1];
    }
    ptr3 = CRT_Realloc(ptr3,(uint32_t *)(value2 << 2));
    if (ptr3 == (int *)0x0) goto LAB_00557909;
  }
  DAT_00585630 = ptr3;
LAB_00557909:
  if (arg2 != 0) {
    svalue4 = _strlen((char *)arg1);
    lpName = _malloc(svalue4 + 2);
    if (lpName != (uint32_t *)0x0) {
      _strcpy(lpName,arg1);
      bptr5 = (uint8_t *)(((intptr_t)lpName - (intptr_t)arg1) + (intptr_t)uptr1);
      *bptr5 = 0;
      SetEnvironmentVariableA((LPCSTR)lpName,(LPCSTR)(~-(uint32_t)flag7 & (uint32_t)(bptr5 + 1)));
      CRT_FreeInternal(lpName);
    }
  }
  return 0;
}
