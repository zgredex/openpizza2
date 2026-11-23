// Stats_BuildRanking: ported from Pizza Connection 2 at 0x478880.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x478880
#include "pc2_port.h"

void __fastcall Stats_BuildRanking(void *arg1)

{
  int value1;
  uint32_t *uptr2;
  int *ptr3;
  int value4;
  int value5;
  uint32_t uvalue6;
  int value7;
  int value8;
  int *ptr9;
  int64_t lvalue10;
  char *local_1c;
  int *local_18;
  int local_14 [5];
  
  value8 = 0;
  value5 = *(int *)((intptr_t)arg1 + 0x1514);
  uvalue6 = 0;
  local_1c = (char *)((intptr_t)arg1 + 0x1a08);
  local_14[4] = 0;
  local_14[0] = 0;
  local_14[1] = 0;
  local_14[2] = 0;
  local_14[3] = 0;
  do {
    if ((*local_1c != '\0') && (value7 = 0, 0 < value5)) {
      do {
        uptr2 = (uint32_t *)IDMap_Lookup((void *)((intptr_t)arg1 + 0x1500),value7,(int *)0x0);
        AI_IsDirectionOnRoute(arg1,(int *)*uptr2,uvalue6);
        value7 = value7 + 1;
      } while (value7 < value5);
    }
    uvalue6 = uvalue6 + 1;
    local_1c = local_1c + 3;
  } while ((intptr_t)uvalue6 < 8);
  lvalue10 = __ftol();
  value7 = 0;
  Game_IsBuildingOpenAtHour(arg1);
  local_18 = (int *)0x0;
  if (0 < value5) {
    do {
      ptr3 = (int *)IDMap_Lookup((void *)((intptr_t)arg1 + 0x1500),value7,(int *)0x0);
      value1 = *ptr3;
      if (*(char *)(value1 + 0x824) == '\x01') {
        local_18 = (int *)value1;
      }
      local_14[0] = local_14[0] + *(int *)(value1 + 4);
      value4 = Rating_AdjustA(value1);
      local_14[1] = local_14[1] + value4;
      local_14[2] = local_14[2] + *(int *)(value1 + 0xc);
      value4 = Rating_AdjustB(value1);
      value8 = value8 + *(int *)(value1 + 0x38);
      value7 = value7 + 1;
      local_14[3] = local_14[3] + value4;
    } while (value7 < value5);
    local_14[4] = value8;
  }
  *(int **)((intptr_t)arg1 + 0x14c4) = local_18;
  uptr2 = (uint32_t *)((intptr_t)arg1 + 0x17bc);
  for (value5 = 8; value5 != 0; value5 = value5 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  if (value7 != 0) {
    value5 = 5;
    ptr3 = local_14;
    do {
      value5 = value5 + -1;
      *ptr3 = *ptr3 / value7;
      ptr3 = ptr3 + 1;
    } while (value5 != 0);
    local_18 = local_14;
    ptr3 = &DAT_005675b8;
    do {
      ptr9 = (int *)((intptr_t)arg1 + 0x17bc);
      value8 = 8;
      value5 = *local_18;
      do {
        value7 = value5 - *ptr3;
        if (value7 < 0) {
          value7 = *ptr9 + (value7 >> 2) + 0x19;
        }
        else {
          value7 = *ptr9 + value7 / 5 + 0x19;
        }
        *ptr9 = value7;
        ptr3 = ptr3 + 1;
        ptr9 = ptr9 + 1;
        value8 = value8 + -1;
      } while (value8 != 0);
      local_18 = local_18 + 1;
    } while ((intptr_t)ptr3 < 0x567638);
    ptr9 = &DAT_00567678;
    ptr3 = (int *)((intptr_t)arg1 + 0x17bc);
    do {
      uvalue6 = local_14[4] - ptr9[-0x10] >> 0x1f;
      value8 = *ptr3 - ((local_14[4] - ptr9[-0x10] ^ uvalue6) - uvalue6);
      *ptr3 = value8;
      value5 = (intptr_t)lvalue10 - *ptr9;
      if (value5 < 0) {
        *ptr3 = value8 + value5 * 3;
      }
      value5 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)arg1 + 0x30));
      value5 = *(int *)(value5 + 100);
      value8 = Game_UpdateFreeBuildingCount((intptr_t)arg1);
      value5 = value8 * value5 - ptr9[-8];
      if (0 < value5) {
        *ptr3 = *ptr3 + value5 * -3;
      }
      value5 = Game_GetMarketBonus((intptr_t)arg1);
      ptr9 = ptr9 + 1;
      *ptr3 = *ptr3 + value5;
      ptr3 = ptr3 + 1;
    } while ((intptr_t)ptr9 < 0x567698);
  }
  return;
}
