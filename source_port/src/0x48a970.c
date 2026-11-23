// Chart_DrawCustomerPortraits: ported from Pizza Connection 2 at 0x48a970.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48a970
#include "pc2_port.h"

uint32_t Chart_DrawCustomerPortraits(void *arg1,int arg2,int *arg3)

{
  char cVar1;
  void *self;
  int *ptr2;
  char *cptr3;
  int value4;
  int value5;
  uint32_t uvalue6;
  uint32_t uvalue7;
  void *this_00;
  int value8;
  uint8_t *bptr9;
  char *cptr10;
  uint8_t *bptr11;
  int64_t lvalue12;
  int local_78;
  int local_74;
  float local_70;
  int local_6c;
  int *local_68;
  int local_64;
  int local_60;
  uint32_t local_5c;
  uint8_t *local_58;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  uint8_t local_40 [64];
  
  self = (void *)UI_GetButtonSprite(arg1,arg2);
  if (self == (void *)0x0) {
    return 0;
  }
  Sprite_GetSize(self,&local_78,&local_48);
  Array_GetPairByKey(arg1,arg2,&local_5c,&local_60);
  Array_GetRectByKey(arg1,arg2,&local_44,&local_64);
  local_6c = (local_64 + -0x12 >> 1) + local_60;
  value5 = 0;
  value8 = 0x24;
  ptr2 = arg3;
  do {
    value4 = *ptr2;
    ptr2 = ptr2 + 1;
    value5 = value5 + value4;
    value8 = value8 + -1;
  } while (value8 != 0);
  if (value5 < 2) {
    local_70 = 0.0;
  }
  else if ((float)local_78 <= (float)value5 * 18.0) {
    local_70 = ((float)local_78 - 18.0) / (float)(value5 + -1);
  }
  else {
    local_70 = 18.0;
  }
  value5 = (intptr_t)&PTR_s_M_X_KID_M01_spr_005729dc - (intptr_t)arg3;
  value8 = 0x31128;
  local_74 = 0;
  local_68 = arg3;
  local_4c = value5;
  do {
    local_50 = *local_68;
    if (local_50 != 0) {
      local_58 = local_40;
      if (*(char **)(value5 + (intptr_t)local_68) == (char *)0x0) {
        uvalue6 = 0xffffffff;
        cptr3 = DAT_00572a68;
        do {
          cptr10 = cptr3;
          if (uvalue6 == 0) break;
          uvalue6 = uvalue6 - 1;
          cptr10 = cptr3 + 1;
          cVar1 = *cptr3;
          cptr3 = cptr10;
        } while (cVar1 != '\0');
        uvalue6 = ~uvalue6;
        bptr9 = (uint8_t *)(cptr10 + -uvalue6);
      }
      else {
        uvalue6 = 0xffffffff;
        cptr3 = *(char **)(value5 + (intptr_t)local_68);
        do {
          cptr10 = cptr3;
          if (uvalue6 == 0) break;
          uvalue6 = uvalue6 - 1;
          cptr10 = cptr3 + 1;
          cVar1 = *cptr3;
          cptr3 = cptr10;
        } while (cVar1 != '\0');
        uvalue6 = ~uvalue6;
        bptr9 = (uint8_t *)(cptr10 + -uvalue6);
      }
      bptr11 = local_58;
      for (uvalue7 = uvalue6 >> 2; uvalue7 != 0; uvalue7 = uvalue7 - 1) {
        *(uint32_t *)bptr11 = *(uint32_t *)bptr9;
        bptr9 = bptr9 + 4;
        bptr11 = bptr11 + 4;
      }
      for (uvalue6 = uvalue6 & 3; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
        *bptr11 = *bptr9;
        bptr9 = bptr9 + 1;
        bptr11 = bptr11 + 1;
      }
      cptr3 = Game_GetDataByIndex(local_74);
      if (0 < local_50) {
        value5 = local_50;
        do {
          value4 = Array_GetRecordByKeyPtr(arg1,value8);
          if (value4 == 0) {
            bptr9 = local_40;
            value4 = local_6c;
            lvalue12 = __ftol();
            UI_AddSprite(arg1,value8,(intptr_t)lvalue12,value4,(char *)bptr9);
joined_r0x0048ab8d:
            if (cptr3 != (char *)0x0) {
              UI_SetObjectTextByKey(arg1,value8,cptr3);
            }
          }
          else {
            value4 = local_6c;
            lvalue12 = __ftol();
            UI_SetObjectRangeByKey(arg1,value8,(intptr_t)lvalue12,value4);
            bptr9 = (uint8_t *)UI_GetButtonSpriteRecord(arg1,value8);
            uvalue6 = FUN_005570c0(this_00,bptr9,local_40);
            if (uvalue6 != 0) {
              UI_SetButtonSpriteByName(arg1,value8,(char *)local_40);
              goto joined_r0x0048ab8d;
            }
          }
          value8 = value8 + 1;
          value5 = value5 + -1;
        } while (value5 != 0);
      }
      value5 = local_4c;
    }
    local_74 = local_74 + 1;
    local_68 = local_68 + 1;
    if (0x23 < local_74) {
      while (value5 = Array_GetRecordByKeyPtr(arg1,value8), value5 != 0) {
        UI_RemoveObject(arg1,value8);
        value8 = value8 + 1;
      }
      return 1;
    }
  } while( true );
}
