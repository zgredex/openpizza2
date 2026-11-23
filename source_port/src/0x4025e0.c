// Resource_OpenNativeHandle: ported from Pizza Connection 2 at 0x4025e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4025e0
#include "pc2_port.h"


HANDLE __thiscall Resource_OpenNativeHandle(void *self,char *arg1)

{
  char cVar1;
  HANDLE pvVar2;
  DWORD DVar3;
  uint32_t uvalue4;
  uint32_t uvalue5;
  int value6;
  char *cptr7;
  char *cptr8;
  char *cptr9;
  int local_210;
  int local_20c;
  char local_208 [260];
  uint32_t local_104;
  
  ResourceManager_NormalizeResourcePath(self,arg1,&local_104);
  if (*(int *)((intptr_t)self + 0x1ab8) != 0) {
    if (((uint8_t)((local_104) >> 8)) == ':') {
      local_208[0] = '\0';
    }
    else {
      uvalue4 = 0xffffffff;
      cptr7 = (char *)((intptr_t)self + 0x19b0);
      do {
        cptr9 = cptr7;
        if (uvalue4 == 0) break;
        uvalue4 = uvalue4 - 1;
        cptr9 = cptr7 + 1;
        cVar1 = *cptr7;
        cptr7 = cptr9;
      } while (cVar1 != '\0');
      uvalue4 = ~uvalue4;
      cptr7 = cptr9 + -uvalue4;
      cptr9 = local_208;
      for (uvalue5 = uvalue4 >> 2; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
        *(uint32_t *)cptr9 = *(uint32_t *)cptr7;
        cptr7 = cptr7 + 4;
        cptr9 = cptr9 + 4;
      }
      for (uvalue4 = uvalue4 & 3; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
        *cptr9 = *cptr7;
        cptr7 = cptr7 + 1;
        cptr9 = cptr9 + 1;
      }
    }
    uvalue4 = 0xffffffff;
    cptr7 = (char *)&local_104;
    do {
      cptr9 = cptr7;
      if (uvalue4 == 0) break;
      uvalue4 = uvalue4 - 1;
      cptr9 = cptr7 + 1;
      cVar1 = *cptr7;
      cptr7 = cptr9;
    } while (cVar1 != '\0');
    uvalue4 = ~uvalue4;
    value6 = -1;
    cptr7 = local_208;
    do {
      cptr8 = cptr7;
      if (value6 == 0) break;
      value6 = value6 + -1;
      cptr8 = cptr7 + 1;
      cVar1 = *cptr7;
      cptr7 = cptr8;
    } while (cVar1 != '\0');
    cptr7 = cptr9 + -uvalue4;
    cptr9 = cptr8 + -1;
    for (uvalue5 = uvalue4 >> 2; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
      *(uint32_t *)cptr9 = *(uint32_t *)cptr7;
      cptr7 = cptr7 + 4;
      cptr9 = cptr9 + 4;
    }
    for (uvalue4 = uvalue4 & 3; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
      *cptr9 = *cptr7;
      cptr7 = cptr7 + 1;
      cptr9 = cptr9 + 1;
    }
    pvVar2 = CreateFileA(local_208,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
    if (pvVar2 != (HANDLE)0xffffffff) {
      return pvVar2;
    }
  }
  value6 = Pak_FindEntry(self,(uint8_t *)&local_104,&local_210,&local_20c);
  if (((value6 != 0) && (*(int *)((local_210 * 9 + 9) * 0x20 + (intptr_t)self) != 0)) &&
     (pvVar2 = CreateFileA((LPCSTR)(local_210 * 0x120 + 0xc + (intptr_t)self),0x80000000,1,
                           (LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0),
     pvVar2 != (HANDLE)0xffffffff)) {
    DVar3 = SetFilePointer(pvVar2,*(int *)(*(int *)(local_210 * 0x120 + 0x114 + (intptr_t)self) + 0xc +
                                          local_20c * 0x14) + 0x6c,(PLONG)0x0,0);
    if (DVar3 != 0xffffffff) {
      return pvVar2;
    }
    CloseHandle(pvVar2);
  }
  return (HANDLE)0xffffffff;
}
