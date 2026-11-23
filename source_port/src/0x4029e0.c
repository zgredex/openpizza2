// ResourceManager_RegisterExtensionAlias: ported from Pizza Connection 2 at 0x4029e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4029e0
#include "pc2_port.h"

void __thiscall ResourceManager_RegisterExtensionAlias(void *self,char *arg1,char *arg2)

{
  char cVar1;
  char *cptr2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  int value5;
  uint32_t *uptr6;
  char *cptr7;
  uint32_t *uptr8;
  char *cptr9;
  
  cptr2 = (char *)ResourceManager_FindExtensionAlias(self,arg2);
  if (cptr2 == (char *)0x0) {
    cptr2 = operator_new(0x54);
    uvalue3 = 0xffffffff;
    do {
      cptr7 = arg1;
      if (uvalue3 == 0) break;
      uvalue3 = uvalue3 - 1;
      cptr7 = arg1 + 1;
      cVar1 = *arg1;
      arg1 = cptr7;
    } while (cVar1 != '\0');
    uvalue3 = ~uvalue3;
    cptr7 = cptr7 + -uvalue3;
    cptr9 = cptr2;
    for (uvalue4 = uvalue3 >> 2; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
      *(uint32_t *)cptr9 = *(uint32_t *)cptr7;
      cptr7 = cptr7 + 4;
      cptr9 = cptr9 + 4;
    }
    for (uvalue3 = uvalue3 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
      *cptr9 = *cptr7;
      cptr7 = cptr7 + 1;
      cptr9 = cptr9 + 1;
    }
    uvalue3 = 0xffffffff;
    do {
      cptr7 = arg2;
      if (uvalue3 == 0) break;
      uvalue3 = uvalue3 - 1;
      cptr7 = arg2 + 1;
      cVar1 = *arg2;
      arg2 = cptr7;
    } while (cVar1 != '\0');
    uvalue3 = ~uvalue3;
    uptr6 = (uint32_t *)(cptr7 + -uvalue3);
    uptr8 = (uint32_t *)(cptr2 + 0x40);
    for (uvalue4 = uvalue3 >> 2; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
      *uptr8 = *uptr6;
      uptr6 = uptr6 + 1;
      uptr8 = uptr8 + 1;
    }
    for (uvalue3 = uvalue3 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
      *(char *)uptr8 = (char)*uptr6;
      uptr6 = (uint32_t *)((intptr_t)uptr6 + 1);
      uptr8 = (uint32_t *)((intptr_t)uptr8 + 1);
    }
    CRT_Strlwr((uint32_t *)(cptr2 + 0x40));
    *(uint32_t *)(cptr2 + 0x50) = *(uint32_t *)((intptr_t)self + 0x1ab4);
    *(char **)((intptr_t)self + 0x1ab4) = cptr2;
  }
  else {
    uvalue3 = 0xffffffff;
    do {
      cptr7 = arg1;
      if (uvalue3 == 0) break;
      uvalue3 = uvalue3 - 1;
      cptr7 = arg1 + 1;
      cVar1 = *arg1;
      arg1 = cptr7;
    } while (cVar1 != '\0');
    uvalue3 = ~uvalue3;
    cptr7 = cptr7 + -uvalue3;
    cptr9 = cptr2;
    for (uvalue4 = uvalue3 >> 2; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
      *(uint32_t *)cptr9 = *(uint32_t *)cptr7;
      cptr7 = cptr7 + 4;
      cptr9 = cptr9 + 4;
    }
    for (uvalue3 = uvalue3 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
      *cptr9 = *cptr7;
      cptr7 = cptr7 + 1;
      cptr9 = cptr9 + 1;
    }
  }
  uvalue3 = 0xffffffff;
  cptr7 = cptr2;
  do {
    if (uvalue3 == 0) break;
    uvalue3 = uvalue3 - 1;
    cVar1 = *cptr7;
    cptr7 = cptr7 + 1;
  } while (cVar1 != '\0');
  if (cptr2[~uvalue3 - 2] != '\\') {
    uvalue3 = 0xffffffff;
    cptr7 = &DAT_00563278;
    do {
      cptr9 = cptr7;
      if (uvalue3 == 0) break;
      uvalue3 = uvalue3 - 1;
      cptr9 = cptr7 + 1;
      cVar1 = *cptr7;
      cptr7 = cptr9;
    } while (cVar1 != '\0');
    uvalue3 = ~uvalue3;
    value5 = -1;
    do {
      cptr7 = cptr2;
      if (value5 == 0) break;
      value5 = value5 + -1;
      cptr7 = cptr2 + 1;
      cVar1 = *cptr2;
      cptr2 = cptr7;
    } while (cVar1 != '\0');
    cptr2 = cptr9 + -uvalue3;
    cptr7 = cptr7 + -1;
    for (uvalue4 = uvalue3 >> 2; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
      *(uint32_t *)cptr7 = *(uint32_t *)cptr2;
      cptr2 = cptr2 + 4;
      cptr7 = cptr7 + 4;
    }
    for (uvalue3 = uvalue3 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
      *cptr7 = *cptr2;
      cptr2 = cptr2 + 1;
      cptr7 = cptr7 + 1;
    }
  }
  return;
}
