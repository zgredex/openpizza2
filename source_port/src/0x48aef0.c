// CustomerGroups_DrawTrafficGrid: ported from Pizza Connection 2 at 0x48aef0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48aef0
#include "pc2_port.h"

uint32_t CustomerGroups_DrawTrafficGrid(void *arg1,int arg2,int *arg3)

{
  char cVar1;
  int *ptr2;
  uint8_t *bptr3;
  uint32_t uvalue4;
  int value5;
  uint32_t uvalue6;
  int value7;
  char *cptr8;
  int value9;
  char *cptr10;
  char *cptr11;
  int value12;
  int local_2b0;
  int local_2ac;
  int local_2a8;
  int local_2a4;
  int local_2a0;
  int *local_29c;
  int local_298;
  int local_294;
  int local_290;
  int local_28c;
  int local_288;
  int local_284;
  char local_280 [64];
  char local_240 [64];
  char local_200 [512];
  
  Array_GetPairByKey(arg1,arg2,&local_2a0,&local_28c);
  Array_GetRectByKey(arg1,arg2,&local_288,&local_298);
  local_200[0] = '\0';
  value7 = 0;
  ptr2 = arg3;
  do {
    if (*ptr2 != 0) {
      Game_GetDataByIndex(value7);
      String_Format(local_240,(uint8_t *)s__d__s_00568324,*ptr2);
      if (local_200[0] != '\0') {
        uvalue4 = 0xffffffff;
        cptr8 = &DAT_0056832c;
        do {
          cptr11 = cptr8;
          if (uvalue4 == 0) break;
          uvalue4 = uvalue4 - 1;
          cptr11 = cptr8 + 1;
          cVar1 = *cptr8;
          cptr8 = cptr11;
        } while (cVar1 != '\0');
        uvalue4 = ~uvalue4;
        value5 = -1;
        cptr8 = local_200;
        do {
          cptr10 = cptr8;
          if (value5 == 0) break;
          value5 = value5 + -1;
          cptr10 = cptr8 + 1;
          cVar1 = *cptr8;
          cptr8 = cptr10;
        } while (cVar1 != '\0');
        cptr8 = cptr11 + -uvalue4;
        cptr11 = cptr10 + -1;
        for (uvalue6 = uvalue4 >> 2; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
          *(uint32_t *)cptr11 = *(uint32_t *)cptr8;
          cptr8 = cptr8 + 4;
          cptr11 = cptr11 + 4;
        }
        for (uvalue4 = uvalue4 & 3; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
          *cptr11 = *cptr8;
          cptr8 = cptr8 + 1;
          cptr11 = cptr11 + 1;
        }
      }
      uvalue4 = 0xffffffff;
      cptr8 = local_240;
      do {
        cptr11 = cptr8;
        if (uvalue4 == 0) break;
        uvalue4 = uvalue4 - 1;
        cptr11 = cptr8 + 1;
        cVar1 = *cptr8;
        cptr8 = cptr11;
      } while (cVar1 != '\0');
      uvalue4 = ~uvalue4;
      value5 = -1;
      cptr8 = local_200;
      do {
        cptr10 = cptr8;
        if (value5 == 0) break;
        value5 = value5 + -1;
        cptr10 = cptr8 + 1;
        cVar1 = *cptr8;
        cptr8 = cptr10;
      } while (cVar1 != '\0');
      cptr8 = cptr11 + -uvalue4;
      cptr11 = cptr10 + -1;
      for (uvalue6 = uvalue4 >> 2; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
        *(uint32_t *)cptr11 = *(uint32_t *)cptr8;
        cptr8 = cptr8 + 4;
        cptr11 = cptr11 + 4;
      }
      for (uvalue4 = uvalue4 & 3; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
        *cptr11 = *cptr8;
        cptr8 = cptr8 + 1;
        cptr11 = cptr11 + 1;
      }
    }
    value7 = value7 + 1;
    ptr2 = ptr2 + 1;
  } while (value7 < 8);
  value9 = 0x318f8;
  value7 = 0;
  value5 = 8;
  ptr2 = arg3;
  do {
    value12 = *ptr2;
    ptr2 = ptr2 + 1;
    value7 = value7 + value12;
    value5 = value5 + -1;
  } while (value5 != 0);
  local_2ac = 0xc;
  do {
    local_284 = (local_288 + -0x12) / local_2ac;
    if (value7 < local_284 * 5) break;
    local_2ac = local_2ac + -1;
  } while (0 < local_2ac);
  if (local_2ac == 0) {
    local_2ac = 1;
  }
  local_294 = local_298 / 5;
  value7 = (intptr_t)&PTR_s_M_KIDS_00567ed4 - (intptr_t)arg3;
  local_2b0 = 0;
  local_2a8 = 8;
  local_29c = arg3;
  value5 = local_28c;
  value12 = local_2a0;
  local_290 = value7;
  do {
    local_2a4 = *local_29c;
    if (local_2a4 != 0) {
      String_Format(local_280,(uint8_t *)s__s_spr_005680ec,*(uint32_t *)(value7 + (intptr_t)local_29c));
      if (0 < local_2a4) {
        do {
          value7 = Array_GetRecordByKeyPtr(arg1,value9);
          if (value7 == 0) {
            UI_AddSprite(arg1,value9,value12,value5,local_280);
          }
          else {
            UI_SetObjectRangeByKey(arg1,value9,value12,value5);
            bptr3 = (uint8_t *)UI_GetButtonSpriteRecord(arg1,value9);
            uvalue4 = FUN_005570c0(local_280,bptr3,(uint8_t *)local_280);
            if (uvalue4 != 0) {
              UI_SetButtonSpriteByName(arg1,value9,local_280);
            }
          }
          UI_SetObjectTextByKey(arg1,value9,local_200);
          value9 = value9 + 1;
          local_2b0 = local_2b0 + 1;
          if (local_2b0 < local_284) {
            value12 = value12 + local_2ac;
          }
          else {
            value5 = value5 + local_294;
            local_2b0 = 0;
            value12 = local_2a0;
          }
          local_2a4 = local_2a4 + -1;
        } while (local_2a4 != 0);
      }
      value7 = local_290;
    }
    local_29c = local_29c + 1;
    local_2a8 = local_2a8 + -1;
  } while (local_2a8 != 0);
  while (value7 = Array_GetRecordByKeyPtr(arg1,value9), value7 != 0) {
    UI_RemoveObject(arg1,value9);
    value9 = value9 + 1;
  }
  return 1;
}
