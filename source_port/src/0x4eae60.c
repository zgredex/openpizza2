// Map_CompactVisibleDrawRecords: ported from Pizza Connection 2 at 0x4eae60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4eae60
#include "pc2_port.h"

void __fastcall Map_CompactVisibleDrawRecords(int arg1)

{
  int *ptr1;
  char *pvVar2;
  int value3;
  int value4;
  uint32_t *uptr5;
  int value6;
  uint32_t *uptr7;
  int value8;
  uint32_t *uptr9;
  int local_24;
  int local_20;
  int local_1c;
  char *local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  value8 = *(int *)(arg1 + 0x70);
  local_18 = (void *)0x0;
  local_24 = 0;
  if (value8 == 0) {
    Sprite_GetSize(*(void **)(arg1 + 0x74),&local_20,&local_1c);
    Sprite_GetHotspot(*(void **)(arg1 + 0x74),&local_8,&local_4);
    local_20 = local_20 + local_8;
    local_1c = local_1c + local_4;
  }
  else {
    local_20 = *(int *)(value8 + 4) + 0x200;
    local_1c = *(int *)(value8 + 8) + 0x100;
  }
  local_10 = 0;
  if (0 < *(int *)(arg1 + 0x20)) {
    do {
      local_14 = 0;
      if (0 < *(int *)(arg1 + 0x1c)) {
        local_c = local_24 * 0xc;
        do {
          if (*(int *)(arg1 + 0xc) == 0x10) {
            ptr1 = (int *)(*(int *)(arg1 + 0x4c) + local_c);
            if ((((*ptr1 + 100 < *(int *)(arg1 + 0x2c) + DAT_00571960 * -0x10) ||
                 (ptr1[1] + 100 <
                  *(int *)(arg1 + 0x30) - *(int *)(arg1 + 0x10) * DAT_00571964)) ||
                (*(int *)(arg1 + 0x2c) + local_20 < *ptr1 + -100)) ||
               (*(int *)(arg1 + 0x30) + local_1c < ptr1[1] + -100)) {
              ptr1[2] = 0;
              goto LAB_004eafcf;
            }
          }
          else {
            ptr1 = (int *)(*(int *)(arg1 + 0x4c) + local_c);
            if (((*ptr1 + 100 < *(int *)(arg1 + 0x2c) - *(int *)(arg1 + 0xc) * DAT_00571960)
                || (ptr1[1] + 100 <
                    (*(int *)(arg1 + 0x30) - *(int *)(arg1 + 0x10) * DAT_00571964) -
                    *(int *)(arg1 + 0x10174))) ||
               ((*(int *)(arg1 + 0x2c) + local_20 < *ptr1 + -100 ||
                (*(int *)(arg1 + 0x10170) + *(int *)(arg1 + 0x30) + local_1c <
                 ptr1[1] + -100)))) {
              ptr1[2] = 0;
LAB_004eafcf:
              local_18 = (void *)((intptr_t)local_18 + 1);
            }
          }
          local_24 = local_24 + 1;
          local_c = local_c + 0xc;
          local_14 = local_14 + 1;
        } while (local_14 < *(int *)(arg1 + 0x1c));
      }
      local_10 = local_10 + 1;
    } while (local_10 < *(int *)(arg1 + 0x20));
  }
  value6 = 0;
  value8 = *(int *)(arg1 + 0x20) * *(int *)(arg1 + 0x1c) - (intptr_t)local_18;
  local_c = value8;
  pvVar2 = operator_new(value8 * 0x3c);
  value3 = 0;
  local_24 = 0;
  local_10 = 0;
  if (0 < *(int *)(arg1 + 0x20)) {
    do {
      local_14 = 0;
      if (0 < *(int *)(arg1 + 0x1c)) {
        value4 = value3 * 0xc;
        uptr5 = (uint32_t *)((intptr_t)pvVar2 + value6 * 0x3c);
        do {
          uptr7 = *(uint32_t **)(*(int *)(arg1 + 0x4c) + 8 + value4);
          if (uptr7 != (uint32_t *)0x0) {
            uptr9 = uptr5;
            for (value8 = 0xf; value8 != 0; value8 = value8 + -1) {
              *uptr9 = *uptr7;
              uptr7 = uptr7 + 1;
              uptr9 = uptr9 + 1;
            }
            value6 = value6 + 1;
            *(uint32_t **)(*(int *)(arg1 + 0x4c) + 8 + value4) = uptr5;
            uptr5 = uptr5 + 0xf;
            value8 = local_c;
          }
          value3 = local_24 + 1;
          value4 = value4 + 0xc;
          local_14 = local_14 + 1;
          local_24 = value3;
        } while (local_14 < *(int *)(arg1 + 0x1c));
      }
      local_10 = local_10 + 1;
    } while (local_10 < *(int *)(arg1 + 0x20));
  }
  local_18 = pvVar2;
  Mem_Free(*(LPVOID *)(arg1 + 0x138));
  *(int *)(arg1 + 0x13c) = value8;
  *(void **)(arg1 + 0x138) = pvVar2;
  return;
}
