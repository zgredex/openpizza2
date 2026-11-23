// Window_LoadSpriteCached: ported from Pizza Connection 2 at 0x527580.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x527580
#include "pc2_port.h"


uint32_t __thiscall
Window_LoadSpriteCached(void *self,char *arg1,uint32_t *arg2,uint32_t *arg3)

{
  char *cptr1;
  int value2;
  uint32_t *uptr3;
  uint32_t uvalue4;
  uint32_t uvalue5;
  uint32_t *uptr6;
  uint32_t *uptr7;
  uint32_t *uptr8;
  uint32_t *uptr9;
  int local_54;
  void *local_50;
  uint32_t local_4c [16];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  cptr1 = arg1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a7db;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  SpriteCache_MakeKey(arg1,local_4c);
  value2 = StringList_Find(self,(uint8_t *)local_4c,(int *)&arg1);
  if (value2 == 0) {
    local_50 = operator_new(0x50);
    local_4 = 0;
    if (local_50 == (void *)0x0) {
      uptr3 = (uint32_t *)0x0;
    }
    else {
      uptr3 = Sprite_Load(local_50,DAT_0057c5c8,*(void **)((intptr_t)self + 0x10),cptr1,&local_54,0,
                           (void *)0x0,0);
    }
    local_4 = 0xffffffff;
    if (local_54 != 0) {
      if (uptr3 != (uint32_t *)0x0) {
        (**(code **)*uptr3)(1);
      }
      if (arg2 == (uint32_t *)0x0) {
        ExceptionList = local_c;
        return 0;
      }
      DebugConsole_Errorf(self,5,(uint8_t *)s_Unable_to_load_sprite___s____005742ac,cptr1);
    }
    if (*(int *)((intptr_t)self + 0x8300) <= *(int *)((intptr_t)self + 0x82fc)) {
      arg2 = operator_new((*(int *)((intptr_t)self + 0x8300) * 9 + 900) * 8);
      if (0 < *(int *)((intptr_t)self + 0x82fc)) {
        uptr6 = *(uint32_t **)((intptr_t)self + 0x82f8);
        uptr9 = arg2;
        for (uvalue4 = (uint32_t)(*(int *)((intptr_t)self + 0x82fc) * 0x48) >> 2; uvalue4 != 0; uvalue4 = uvalue4 - 1
            ) {
          *uptr9 = *uptr6;
          uptr6 = uptr6 + 1;
          uptr9 = uptr9 + 1;
        }
        for (value2 = 0; value2 != 0; value2 = value2 + -1) {
          *(uint8_t *)uptr9 = *(uint8_t *)uptr6;
          uptr6 = (uint32_t *)((intptr_t)uptr6 + 1);
          uptr9 = (uint32_t *)((intptr_t)uptr9 + 1);
        }
        Mem_Free(*(LPVOID *)((intptr_t)self + 0x82f8));
      }
      *(uint32_t **)((intptr_t)self + 0x82f8) = arg2;
      *(int *)((intptr_t)self + 0x8300) = *(int *)((intptr_t)self + 0x8300) + 100;
    }
    value2 = *(int *)((intptr_t)self + 0x82fc) - (intptr_t)arg1;
    if (0 < value2) {
      _memmove((uint32_t *)(*(int *)((intptr_t)self + 0x82f8) + ((intptr_t)arg1 * 9 + 9) * 8),
               (uint32_t *)(*(int *)((intptr_t)self + 0x82f8) + (intptr_t)arg1 * 0x48),value2 * 0x48);
    }
    *(uint32_t *)(*(int *)((intptr_t)self + 0x82f8) + 0x44 + (intptr_t)arg1 * 0x48) = 1;
    *(uint32_t **)(*(int *)((intptr_t)self + 0x82f8) + 0x40 + (intptr_t)arg1 * 0x48) = uptr3;
    *(int *)((intptr_t)self + 0x82fc) = *(int *)((intptr_t)self + 0x82fc) + 1;
    uvalue4 = 0xffffffff;
    uptr7 = local_4c;
    do {
      uptr8 = uptr7;
      if (uvalue4 == 0) break;
      uvalue4 = uvalue4 - 1;
      uptr8 = (uint32_t *)((intptr_t)uptr7 + 1);
      uvalue5 = *uptr7;
      uptr7 = uptr8;
    } while ((char)uvalue5 != '\0');
    uvalue4 = ~uvalue4;
    uptr6 = (uint32_t *)((intptr_t)uptr8 - uvalue4);
    uptr9 = (uint32_t *)(*(int *)((intptr_t)self + 0x82f8) + (intptr_t)arg1 * 0x48);
    for (uvalue5 = uvalue4 >> 2; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
      *uptr9 = *uptr6;
      uptr6 = uptr6 + 1;
      uptr9 = uptr9 + 1;
    }
    for (uvalue4 = uvalue4 & 3; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
      *(uint8_t *)uptr9 = *(uint8_t *)uptr6;
      uptr6 = (uint32_t *)((intptr_t)uptr6 + 1);
      uptr9 = (uint32_t *)((intptr_t)uptr9 + 1);
    }
    arg3[0x10] = uptr3;
  }
  else {
    *(int *)(*(int *)((intptr_t)self + 0x82f8) + 0x44 + (intptr_t)arg1 * 0x48) =
         *(int *)(*(int *)((intptr_t)self + 0x82f8) + 0x44 + (intptr_t)arg1 * 0x48) + 1;
    arg3[0x10] = *(uint32_t *)(*(int *)((intptr_t)self + 0x82f8) + 0x40 + (intptr_t)arg1 * 0x48);
  }
  uvalue4 = 0xffffffff;
  uptr7 = local_4c;
  do {
    uptr8 = uptr7;
    if (uvalue4 == 0) break;
    uvalue4 = uvalue4 - 1;
    uptr8 = (uint32_t *)((intptr_t)uptr7 + 1);
    uvalue5 = *uptr7;
    uptr7 = uptr8;
  } while ((char)uvalue5 != '\0');
  uvalue4 = ~uvalue4;
  uptr3 = (uint32_t *)((intptr_t)uptr8 - uvalue4);
  for (uvalue5 = uvalue4 >> 2; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
    *arg3 = *uptr3;
    uptr3 = uptr3 + 1;
    arg3 = arg3 + 1;
  }
  for (uvalue4 = uvalue4 & 3; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
    *(uint8_t *)arg3 = *(uint8_t *)uptr3;
    uptr3 = (uint32_t *)((intptr_t)uptr3 + 1);
    arg3 = (uint32_t *)((intptr_t)arg3 + 1);
  }
  ExceptionList = local_c;
  return 1;
}
