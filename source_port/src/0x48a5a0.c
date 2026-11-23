// Chart_DrawCustomerGroups: ported from Pizza Connection 2 at 0x48a5a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48a5a0
#include "pc2_port.h"

uint32_t Chart_DrawCustomerGroups(void *arg1,int arg2,int arg3,int *arg4)

{
  void *self;
  int value1;
  int value2;
  int value3;
  int value4;
  int64_t lvalue5;
  char *cptr6;
  int *local_c4;
  int local_c0;
  int local_b8;
  int local_b0;
  int *local_ac;
  int local_a8;
  int *local_a4;
  int local_a0;
  int local_9c;
  void *local_98;
  int local_94;
  uint32_t local_90;
  int *local_8c;
  int local_88;
  int local_84;
  char local_80 [64];
  char local_40 [64];
  
  self = (void *)UI_GetButtonSprite(arg1,arg2);
  if (self == (void *)0x0) {
    return 0;
  }
  Sprite_GetSize(self,&local_84,&local_88);
  local_94 = local_88 >> 3;
  Array_GetPairByKey(arg1,arg2,&local_90,&local_9c);
  local_c0 = local_9c;
  local_a8 = 210000;
  local_a4 = arg4;
  local_ac = arg4 + arg3;
  local_a0 = (arg3 * 5 + 0x41a) * 200;
  local_b0 = 0;
  do {
    value3 = 8;
    local_8c = local_a4;
    do {
      local_8c = local_8c + 1;
      value3 = value3 + -1;
    } while (value3 != 0);
    value3 = *local_ac;
    String_Format(local_80,(uint8_t *)s__s_spr_005680ec,
                  *(uint32_t *)((intptr_t)&PTR_s_M_KIDS_00567e94 + local_b0));
    String_Format(local_40,(uint8_t *)s__d__s_00568324,value3);
    value4 = local_a0;
    if (0 < value3) {
      do {
        value1 = Array_GetRecordByKeyPtr(arg1,value4);
        if (value1 == 0) {
          cptr6 = local_80;
          value1 = local_c0 + -3;
          lvalue5 = __ftol();
          UI_AddSprite(arg1,value4,(intptr_t)lvalue5,value1,cptr6);
        }
        else {
          value1 = local_c0 + -3;
          lvalue5 = __ftol();
          UI_SetObjectRangeByKey(arg1,value4,(intptr_t)lvalue5,value1);
        }
        UI_SetObjectTextByKey(arg1,value4,local_40);
        value4 = value4 + 1;
        value3 = value3 + -1;
      } while (value3 != 0);
    }
    value3 = Array_GetRecordByKeyPtr(arg1,value4);
    while (value3 != 0) {
      UI_RemoveObject(arg1,value4);
      value4 = value4 + 1;
      value3 = Array_GetRecordByKeyPtr(arg1,value4);
    }
    local_b8 = 0;
    local_c4 = local_a4;
    value3 = local_a8;
    do {
      if (arg3 != local_b8) {
        value4 = *local_c4;
        value1 = value3;
        if (value4 != 0) {
          value2 = Game_GetPlayerBySlot(local_98,local_b8);
          if (value2 == 0) {
            value2 = 1;
          }
          else {
            value2 = Game_FindCityIndex(value2);
            value2 = value2 + 1;
          }
          String_Format(local_80,(uint8_t *)s_SP_RING_02d_spr_00568314,value2);
          String_Format(local_40,(uint8_t *)s__d__s__s__s_00568304,value4);
          if (0 < value4) {
            do {
              value2 = Array_GetRecordByKeyPtr(arg1,value1);
              if (value2 == 0) {
                cptr6 = local_80;
                value2 = local_c0;
                lvalue5 = __ftol();
                UI_AddSprite(arg1,value1,(intptr_t)lvalue5,value2,cptr6);
              }
              else {
                value2 = local_c0;
                lvalue5 = __ftol();
                UI_SetObjectRangeByKey(arg1,value1,(intptr_t)lvalue5,value2);
              }
              UI_SetObjectTextByKey(arg1,value1,local_40);
              value1 = value1 + 1;
              value4 = value4 + -1;
            } while (value4 != 0);
          }
        }
        value4 = Array_GetRecordByKeyPtr(arg1,value1);
        while (value4 != 0) {
          UI_RemoveObject(arg1,value1);
          value1 = value1 + 1;
          value4 = Array_GetRecordByKeyPtr(arg1,value1);
        }
      }
      local_b8 = local_b8 + 1;
      value3 = value3 + 1000;
      local_c4 = local_c4 + 1;
    } while (local_b8 < 8);
    local_c0 = local_c0 + local_94;
    local_a8 = local_a8 + 10000;
    local_a0 = local_a0 + 10000;
    local_ac = local_ac + 8;
    local_b0 = local_b0 + 4;
    local_a4 = local_8c;
  } while (local_a8 < 290000);
  return 1;
}
