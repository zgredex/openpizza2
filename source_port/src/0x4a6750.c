// UI_DrawAwardMedals: ported from Pizza Connection 2 at 0x4a6750.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a6750
#include "pc2_port.h"

void __cdecl UI_DrawAwardMedals(void *arg1,int arg2,int arg3,int arg4)

{
  void *self;
  int value1;
  uint8_t *bptr2;
  uint32_t uvalue3;
  void *this_00;
  int value4;
  int64_t lvalue5;
  int local_164;
  int local_15c;
  int local_158;
  int local_154;
  int local_150;
  uint32_t local_14c;
  int local_148;
  int local_144;
  uint8_t local_140 [64];
  char local_100 [256];
  
  self = (void *)UI_GetWindowObject(arg1,arg2);
  if (self != (void *)0x0) {
    UI_GetChildSize(self,&local_15c,&local_148);
    Array_GetPairByKey(arg1,arg2,&local_14c,&local_150);
    Array_GetRectByKey(arg1,arg2,&local_144,&local_154);
    local_158 = (local_154 + -0x12 >> 1) + local_150;
    value4 = (arg4 * 5 + 2000) * 100;
    if ((arg3 != 0) &&
       (String_Format(local_140,&DAT_005630d0,s_Medallien_filiale_spr_00569088 + arg4 * 0x40),
       0 < arg3)) {
      local_164 = arg3;
      do {
        value1 = Array_GetRecordByKeyPtr(arg1,value4);
        if (value1 == 0) {
          bptr2 = local_140;
          value1 = local_158;
          lvalue5 = __ftol();
          UI_AddSprite(arg1,value4,(intptr_t)lvalue5,value1,(char *)bptr2);
          String_Format(local_100,(uint8_t *)s__d__s_00568324,arg3);
LAB_004a6946:
          UI_SetObjectTextByKey(arg1,value4,local_100);
        }
        else {
          value1 = local_158;
          lvalue5 = __ftol();
          UI_SetObjectRangeByKey(arg1,value4,(intptr_t)lvalue5,value1);
          bptr2 = (uint8_t *)UI_GetButtonSpriteRecord(arg1,value4);
          uvalue3 = FUN_005570c0(this_00,bptr2,local_140);
          if (uvalue3 != 0) {
            UI_SetButtonSpriteByName(arg1,value4,(char *)local_140);
            String_Format(local_100,(uint8_t *)s__d__s_00568324,arg3);
            goto LAB_004a6946;
          }
        }
        value4 = value4 + 1;
        local_164 = local_164 + -1;
      } while (local_164 != 0);
    }
    while (value1 = Array_GetRecordByKeyPtr(arg1,value4), value1 != 0) {
      UI_RemoveObject(arg1,value4);
      value4 = value4 + 1;
    }
  }
  return;
}
