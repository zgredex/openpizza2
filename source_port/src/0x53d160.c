// Sprite_Serialize: ported from Pizza Connection 2 at 0x53d160.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53d160
#include "pc2_port.h"

void __thiscall Sprite_Serialize(void *self,int arg1,int *arg2,void *arg3)

{
  uint8_t *bptr1;
  uint32_t *uptr2;
  uint8_t *bptr3;
  uint16_t uvalue4;
  uint16_t *uptr5;
  uint16_t *uptr6;
  uint16_t *uptr7;
  int value8;
  int local_c;
  uint16_t *local_8;
  int local_4;
  
  local_4 = 0;
  bptr1 = (uint8_t *)((intptr_t)self + 5);
  if (*(char *)((intptr_t)self + 5) == '\b') {
    local_4 = 1;
    if (1 < *(uint8_t *)((intptr_t)self + 0x34)) {
      *bptr1 = *(uint8_t *)((intptr_t)self + 0x34) | 0x80;
    }
    if ((arg3 != (void *)0x0) && (*bptr1 == 8)) {
      *bptr1 = 0x48;
    }
  }
  if (*(char *)((intptr_t)self + 0x39) == '\0') {
    Sprite_RealizeLazy(self);
  }
  local_8 = *(uint16_t **)((intptr_t)self + 0x1c);
  if ((*(char *)(arg1 + 0x18) != '\0') && (8 < *bptr1)) {
    *(uint32_t *)((intptr_t)self + 0x1c) = (intptr_t)local_8 >> 1 & 0x7fe0U | (uint32_t)local_8 & 0x1f;
  }
  uptr2 = (uint32_t *)((intptr_t)self + 0x18);
  CRT_FwriteLocked((char *)uptr2,1,4,arg2);
  CRT_FwriteLocked((char *)bptr1,1,1,arg2);
  bptr3 = (uint8_t *)((intptr_t)self + 4);
  CRT_FwriteLocked((char *)bptr3,1,0x1c,arg2);
  *(uint16_t **)((intptr_t)self + 0x1c) = local_8;
  if (((*(char *)(arg1 + 0x18) == '\0') || (*bptr1 < 9)) || ((*bptr3 & 0x10) != 0)) {
    CRT_FwriteLocked(*(char **)((intptr_t)self + 0x2c),1,*uptr2,arg2);
  }
  else {
    local_8 = *(uint16_t **)((intptr_t)self + 0x2c);
    uptr5 = operator_new(((intptr_t)*uptr2 >> 1) << 1);
    if ((*bptr3 & 1) == 0) {
      value8 = 0;
      if (0 < (intptr_t)(*uptr2 & 0xfffffffe)) {
        uptr6 = local_8;
        do {
          uvalue4 = *uptr6;
          uptr6 = uptr6 + 1;
          value8 = value8 + 1;
          *(uint16_t *)((intptr_t)uptr5 + (-2 - (intptr_t)local_8) + (intptr_t)uptr6) =
               uvalue4 >> 1 & 0x7fe0 | uvalue4 & 0x1f;
        } while (value8 < (intptr_t)*uptr2 >> 1);
      }
    }
    else {
      value8 = 0;
      if (0 < (intptr_t)(*uptr2 & 0xfffffffe)) {
        uptr6 = uptr5;
        uptr7 = local_8;
        do {
          uvalue4 = *uptr7;
          if ((uint32_t)uvalue4 == *(uint32_t *)((intptr_t)self + 0x1c)) {
            uptr7 = uptr7 + 1;
            *uptr6 = uvalue4 >> 1 & 0x7fe0 | uvalue4 & 0x1f;
            value8 = value8 + 1;
            uptr6 = uptr6 + 1;
            *uptr6 = *uptr7;
          }
          else {
            *uptr6 = uvalue4 >> 1 & 0x7fe0 | uvalue4 & 0x1f;
          }
          value8 = value8 + 1;
          uptr7 = uptr7 + 1;
          uptr6 = uptr6 + 1;
        } while (value8 < (intptr_t)*uptr2 >> 1);
      }
    }
    CRT_FwriteLocked((char *)uptr5,1,*uptr2,arg2);
    Mem_Free(uptr5);
  }
  if (local_4 != 0) {
    if (*(uint8_t *)((intptr_t)self + 0x34) < 2) {
      if ((*bptr1 & 0x40) == 0) {
        Palette_WriteToStream(*(void **)((intptr_t)self + 0x20),arg2);
        *bptr1 = 8;
        return;
      }
      local_c = Palette_FindIndex(arg3,*(uint32_t **)((intptr_t)self + 0x20));
      if (local_c == -1) {
        NoOp_Stub();
      }
      CRT_FwriteLocked((char *)&local_c,1,4,arg2);
      *bptr1 = 8;
      return;
    }
    value8 = 0;
    if (*(uint8_t *)((intptr_t)self + 0x34) != 0) {
      do {
        if ((*bptr1 & 0x40) == 0) {
          Palette_WriteToStream(*(void **)(*(int *)((intptr_t)self + 0x24) + value8 * 4),arg2);
        }
        else {
          local_c = Palette_FindIndex(arg3,*(uint32_t **)
                                               (*(int *)((intptr_t)self + 0x24) + value8 * 4));
          if (local_c == -1) {
            NoOp_Stub();
          }
          CRT_FwriteLocked((char *)&local_c,1,4,arg2);
        }
        value8 = value8 + 1;
      } while (value8 < (intptr_t)(uint32_t)*(uint8_t *)((intptr_t)self + 0x34));
    }
    *bptr1 = 8;
  }
  return;
}
