// Map_UpdateObjectScreenBounds: ported from Pizza Connection 2 at 0x4ed0a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ed0a0
#include "pc2_port.h"

struct pc2_obj_0x4ed0a0_local_10 { intptr_t right; intptr_t left; intptr_t bottom; intptr_t top; };
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall Map_UpdateObjectScreenBounds(char *arg1)

{
  int *ptr1;
  uint32_t *uptr2;
  int value3;
  int value4;
  int value5;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  struct pc2_obj_0x4ed0a0_local_10 *local_10;
  
  ptr1 = (int *)Grid_GetCell(arg1,(*(int *)((intptr_t)arg1 + 0x1c) >> 1) -
                                       (*(int *)((intptr_t)arg1 + 0x14) >> 1),
                               (*(int *)((intptr_t)arg1 + 0x20) >> 1) +
                               (*(int *)((intptr_t)arg1 + 0x18) >> 1));
  *(int *)((intptr_t)arg1 + 0x2c) = *ptr1 + (*(int *)((intptr_t)arg1 + 0xc) >> 1);
  uptr2 = (uint32_t *)
           Grid_GetCell(arg1,(*(int *)((intptr_t)arg1 + 0x1c) >> 1) +
                                (*(int *)((intptr_t)arg1 + 0x14) >> 1),
                        (*(int *)((intptr_t)arg1 + 0x20) >> 1) - (*(int *)((intptr_t)arg1 + 0x18) >> 1))
  ;
  *(uint32_t *)((intptr_t)arg1 + 0x34) = *uptr2;
  value3 = Grid_GetCell(arg1,(*(int *)((intptr_t)arg1 + 0x1c) >> 1) -
                               (*(int *)((intptr_t)arg1 + 0x14) >> 1),
                       (*(int *)((intptr_t)arg1 + 0x20) >> 1) - (*(int *)((intptr_t)arg1 + 0x18) >> 1));
  *(int *)((intptr_t)arg1 + 0x30) = *(int *)(value3 + 4) + *(int *)((intptr_t)arg1 + 0x10);
  value3 = Grid_GetCell(arg1,(*(int *)((intptr_t)arg1 + 0x1c) >> 1) +
                               (*(int *)((intptr_t)arg1 + 0x14) >> 1),
                       (*(int *)((intptr_t)arg1 + 0x20) >> 1) + (*(int *)((intptr_t)arg1 + 0x18) >> 1));
  *(uint32_t *)((intptr_t)arg1 + 0x38) = *(uint32_t *)(value3 + 4);
  if (*(int *)((intptr_t)arg1 + 0xc) == 0x10) {
    value3 = DAT_00571958;
    value4 = DAT_0057195c;
  }
  else {
    value3 = DAT_00571950;
    value4 = DAT_00571954;
  }
  SetRect(&local_10,0,0,value3,value4);
  _DAT_0058073c = *(uint32_t *)((intptr_t)arg1 + 0x2c);
  _DAT_00580740 = *(uint32_t *)((intptr_t)arg1 + 0x30);
  _DAT_00580744 = *(uint32_t *)((intptr_t)arg1 + 0x34);
  _DAT_00580748 = *(uint32_t *)((intptr_t)arg1 + 0x38);
  value3 = *(int *)((intptr_t)arg1 + 0x70);
  if (value3 == 0) {
    if (*(int *)((intptr_t)arg1 + 0x74) == 0) {
      *(int *)((intptr_t)arg1 + 0x34) =
           *(int *)((intptr_t)arg1 + 0x34) +
           ((*(int *)((intptr_t)arg1 + 0xc) >> 1) - local_10->right) + local_10->left;
      *(int *)((intptr_t)arg1 + 0x38) =
           *(int *)((intptr_t)arg1 + 0x38) +
           (*(int *)((intptr_t)arg1 + 0x10) - local_10->bottom) + local_10->top;
      goto LAB_004ed2a1;
    }
    Sprite_GetSize(*(void **)((intptr_t)arg1 + 0x74),&local_20,&local_18);
    Sprite_GetHotspot(*(void **)((intptr_t)arg1 + 0x74),&local_1c,&local_14);
    local_20 = local_20 + local_1c;
    local_18 = local_18 + local_14;
  }
  else {
    local_20 = *(int *)(value3 + 4) + 0x200;
    local_18 = *(int *)(value3 + 8) + 0x100;
  }
  local_20 = *(int *)((intptr_t)arg1 + 0x2c) + *(int *)((intptr_t)arg1 + 0xc) * DAT_00571960 * -2 +
             local_20;
  value3 = local_18 + *(int *)((intptr_t)arg1 + 0x10) * DAT_00571964 * -2 +
          *(int *)((intptr_t)arg1 + 0x30);
  if (local_20 < *(int *)((intptr_t)arg1 + 0x34)) {
    *(int *)((intptr_t)arg1 + 0x34) = local_20;
  }
  if (value3 < *(int *)((intptr_t)arg1 + 0x38)) {
    *(int *)((intptr_t)arg1 + 0x38) = value3;
  }
  *(int *)((intptr_t)arg1 + 0x10160) = *(int *)((intptr_t)arg1 + 0x34);
  *(int *)((intptr_t)arg1 + 0x10164) = *(int *)((intptr_t)arg1 + 0x38);
  *(int *)((intptr_t)arg1 + 0x34) = (*(int *)((intptr_t)arg1 + 0x34) - local_10->right) + local_10->left;
  *(int *)((intptr_t)arg1 + 0x38) = (*(int *)((intptr_t)arg1 + 0x38) - local_10->bottom) + local_10->top;
LAB_004ed2a1:
  value3 = *(int *)((intptr_t)arg1 + 0x2c);
  if (*(int *)((intptr_t)arg1 + 0x34) < value3) {
    *(int *)((intptr_t)arg1 + 0x34) = value3;
  }
  value4 = *(int *)((intptr_t)arg1 + 0x30);
  if (*(int *)((intptr_t)arg1 + 0x38) < value4) {
    *(int *)((intptr_t)arg1 + 0x38) = value4;
  }
  value5 = *(int *)((intptr_t)arg1 + 0x34) - *(int *)((intptr_t)arg1 + 0x10168);
  if (value5 < *(int *)((intptr_t)arg1 + 0x24)) {
    *(int *)((intptr_t)arg1 + 0x24) = value5;
  }
  value5 = *(int *)((intptr_t)arg1 + 0x10170) + *(int *)((intptr_t)arg1 + 0x38);
  if (value5 < *(int *)((intptr_t)arg1 + 0x28)) {
    *(int *)((intptr_t)arg1 + 0x28) = value5;
  }
  value3 = *(int *)((intptr_t)arg1 + 0x1016c) + value3;
  if (*(int *)((intptr_t)arg1 + 0x24) < value3) {
    *(int *)((intptr_t)arg1 + 0x24) = value3;
  }
  value4 = value4 - *(int *)((intptr_t)arg1 + 0x10174);
  if (*(int *)((intptr_t)arg1 + 0x28) < value4) {
    *(int *)((intptr_t)arg1 + 0x28) = value4;
  }
  return;
}
