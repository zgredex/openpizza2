// CustomerGroups_DrawCountRow: ported from Pizza Connection 2 at 0x48b1b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48b1b0
#include "pc2_port.h"

uint32_t CustomerGroups_DrawCountRow(void *arg1,int arg2,int arg3)

{
  int value1;
  uint8_t *bptr2;
  uint32_t uvalue3;
  int value4;
  int value5;
  int value6;
  int64_t lvalue7;
  char *cptr8;
  int local_258;
  uint32_t local_254;
  uint32_t local_250 [2];
  float local_248;
  int local_244;
  char local_240 [64];
  char local_200 [512];
  
  Array_GetPairByKey(arg1,arg2,local_250,&local_254);
  Array_GetRectByKey(arg1,arg2,&local_258,&local_244);
  value6 = 0x31ce0;
  local_258 = local_258 >> 1;
  local_248 = (float)local_244 * 0.25;
  value4 = 0;
  do {
    Game_GetDataByIndex(value4);
    String_Format(local_200,(uint8_t *)s__d__s_00568324,*(uint32_t *)(arg3 + value4 * 4));
    value5 = *(int *)(arg3 + value4 * 4);
    if ((value5 != 0) &&
       (String_Format(local_240,(uint8_t *)s__s_spr_005680ec,(&PTR_s_M_KIDS_00567ef4)[value4]),
       0 < value5)) {
      do {
        value1 = Array_GetRecordByKeyPtr(arg1,value6);
        if (value1 == 0) {
          cptr8 = local_240;
          lvalue7 = __ftol();
          value1 = (intptr_t)lvalue7;
          lvalue7 = __ftol();
          UI_AddSprite(arg1,value6,(intptr_t)lvalue7,value1,cptr8);
        }
        else {
          lvalue7 = __ftol();
          value1 = (intptr_t)lvalue7;
          lvalue7 = __ftol();
          UI_SetObjectRangeByKey(arg1,value6,(intptr_t)lvalue7,value1);
          bptr2 = (uint8_t *)UI_GetButtonSpriteRecord(arg1,value6);
          uvalue3 = FUN_005570c0(local_240,bptr2,(uint8_t *)local_240);
          if (uvalue3 != 0) {
            UI_SetButtonSpriteByName(arg1,value6,local_240);
          }
        }
        UI_SetObjectTextByKey(arg1,value6,local_200);
        value6 = value6 + 1;
        value5 = value5 + -1;
      } while (value5 != 0);
    }
    value4 = value4 + 1;
  } while (value4 < 8);
  while (value4 = Array_GetRecordByKeyPtr(arg1,value6), value4 != 0) {
    UI_RemoveObject(arg1,value6);
    value6 = value6 + 1;
  }
  return 1;
}
