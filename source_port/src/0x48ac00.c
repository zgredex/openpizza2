// CustomerGroups_DrawProductSalesGrid: ported from Pizza Connection 2 at 0x48ac00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48ac00
#include "pc2_port.h"

uint32_t CustomerGroups_DrawProductSalesGrid(void *arg1,int arg2,int *arg3)

{
  char cVar1;
  int value2;
  uint8_t *bptr3;
  int value4;
  uint32_t uvalue5;
  uint32_t uvalue6;
  int *ptr7;
  int value8;
  char *cptr9;
  char *cptr10;
  char *cptr11;
  uint8_t **pptr12;
  int64_t lvalue13;
  int *local_2b8;
  int *local_2ac;
  int local_2a8;
  int local_2a0;
  int local_294 [2];
  uint32_t local_28c;
  uint32_t local_288;
  int local_284;
  char local_280 [64];
  char local_240 [64];
  char local_200 [512];
  
  Array_GetPairByKey(arg1,arg2,&local_28c,&local_288);
  Array_GetRectByKey(arg1,arg2,&local_284,local_294);
  value8 = 0x31510;
  local_2b8 = arg3;
  local_2a0 = 8;
  do {
    value4 = 8;
    ptr7 = local_2b8;
    do {
      ptr7 = ptr7 + 1;
      value4 = value4 + -1;
    } while (value4 != 0);
    local_200[0] = '\0';
    local_2a8 = 0;
    local_2ac = local_2b8;
    do {
      if (*local_2ac != 0) {
        Game_GetDataByIndex(local_2a8);
        String_Format(local_240,(uint8_t *)s__d__s_00568324,*local_2ac);
        if (local_200[0] != '\0') {
          uvalue5 = 0xffffffff;
          cptr9 = &DAT_0056832c;
          do {
            cptr11 = cptr9;
            if (uvalue5 == 0) break;
            uvalue5 = uvalue5 - 1;
            cptr11 = cptr9 + 1;
            cVar1 = *cptr9;
            cptr9 = cptr11;
          } while (cVar1 != '\0');
          uvalue5 = ~uvalue5;
          value4 = -1;
          cptr9 = local_200;
          do {
            cptr10 = cptr9;
            if (value4 == 0) break;
            value4 = value4 + -1;
            cptr10 = cptr9 + 1;
            cVar1 = *cptr9;
            cptr9 = cptr10;
          } while (cVar1 != '\0');
          cptr9 = cptr11 + -uvalue5;
          cptr11 = cptr10 + -1;
          for (uvalue6 = uvalue5 >> 2; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
            *(uint32_t *)cptr11 = *(uint32_t *)cptr9;
            cptr9 = cptr9 + 4;
            cptr11 = cptr11 + 4;
          }
          for (uvalue5 = uvalue5 & 3; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
            *cptr11 = *cptr9;
            cptr9 = cptr9 + 1;
            cptr11 = cptr11 + 1;
          }
        }
        uvalue5 = 0xffffffff;
        cptr9 = local_240;
        do {
          cptr11 = cptr9;
          if (uvalue5 == 0) break;
          uvalue5 = uvalue5 - 1;
          cptr11 = cptr9 + 1;
          cVar1 = *cptr9;
          cptr9 = cptr11;
        } while (cVar1 != '\0');
        uvalue5 = ~uvalue5;
        value4 = -1;
        cptr9 = local_200;
        do {
          cptr10 = cptr9;
          if (value4 == 0) break;
          value4 = value4 + -1;
          cptr10 = cptr9 + 1;
          cVar1 = *cptr9;
          cptr9 = cptr10;
        } while (cVar1 != '\0');
        cptr9 = cptr11 + -uvalue5;
        cptr11 = cptr10 + -1;
        for (uvalue6 = uvalue5 >> 2; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
          *(uint32_t *)cptr11 = *(uint32_t *)cptr9;
          cptr9 = cptr9 + 4;
          cptr11 = cptr11 + 4;
        }
        for (uvalue5 = uvalue5 & 3; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
          *cptr11 = *cptr9;
          cptr9 = cptr9 + 1;
          cptr11 = cptr11 + 1;
        }
      }
      local_2a8 = local_2a8 + 1;
      local_2ac = local_2ac + 1;
    } while (local_2a8 < 8);
    pptr12 = &PTR_s_M_KIDS_00567eb4;
    do {
      value4 = *local_2b8;
      if ((value4 != 0) && (String_Format(local_280,(uint8_t *)s__s_spr_005680ec,*pptr12), 0 < value4))
      {
        do {
          value2 = Array_GetRecordByKeyPtr(arg1,value8);
          if (value2 == 0) {
            cptr9 = local_280;
            lvalue13 = __ftol();
            value2 = (intptr_t)lvalue13;
            lvalue13 = __ftol();
            UI_AddSprite(arg1,value8,(intptr_t)lvalue13,value2,cptr9);
          }
          else {
            lvalue13 = __ftol();
            value2 = (intptr_t)lvalue13;
            lvalue13 = __ftol();
            UI_SetObjectRangeByKey(arg1,value8,(intptr_t)lvalue13,value2);
            bptr3 = (uint8_t *)UI_GetButtonSpriteRecord(arg1,value8);
            uvalue5 = FUN_005570c0(local_280,bptr3,(uint8_t *)local_280);
            if (uvalue5 != 0) {
              UI_SetButtonSpriteByName(arg1,value8,local_280);
            }
          }
          UI_SetObjectTextByKey(arg1,value8,local_200);
          value8 = value8 + 1;
          value4 = value4 + -1;
        } while (value4 != 0);
      }
      pptr12 = pptr12 + 1;
      local_2b8 = local_2b8 + 1;
    } while ((intptr_t)pptr12 < 0x567ed4);
    local_2a0 = local_2a0 + -1;
    local_2b8 = ptr7;
    if (local_2a0 == 0) {
      while (value4 = Array_GetRecordByKeyPtr(arg1,value8), value4 != 0) {
        UI_RemoveObject(arg1,value8);
        value8 = value8 + 1;
      }
      return 1;
    }
  } while( true );
}
