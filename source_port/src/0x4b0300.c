// StatisticsBackdrop_DrawCompanyBarChart: ported from Pizza Connection 2 at 0x4b0300.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b0300
#include "pc2_port.h"

void __cdecl StatisticsBackdrop_DrawCompanyBarChart(void *arg1)

{
  uint32_t *uptr1;
  uint32_t *uptr2;
  uint16_t uvalue3;
  void *self;
  void *pvVar4;
  int value5;
  uint32_t uvalue6;
  int64_t lvalue7;
  int64_t lvalue8;
  int local_38;
  int local_34;
  float local_30;
  float local_2c;
  int local_28;
  uint32_t local_24;
  void *local_20;
  float local_1c;
  int local_18;
  float local_14;
  float local_10;
  int local_c;
  int local_8;
  int *local_4;
  
  uvalue3 = *(uint16_t *)(*(int *)((intptr_t)DAT_0057c670 + 0x94) + 10);
  uvalue6 = (uint32_t)uvalue3;
  local_24 = uvalue6;
  self = (void *)UI_GetWindowObject(arg1,0x413);
  local_20 = self;
  UI_RealizeSprite((intptr_t)self);
  if (uvalue3 == 0) {
    UI_GetChildSize(self,&local_34,&local_38);
    pvVar4 = (void *)Object_GetActiveValue((intptr_t)self);
    Text_SetMetrics(DAT_0057d684,local_34 / 2,local_38 / 2,2);
    Set_Field9B8(DAT_0057d684,0);
    Font_DrawTextLine(DAT_0057d684,pvVar4,DAT_00581444);
    UI_ClipChildRect((intptr_t)self);
    return;
  }
  local_4 = UI_CreateWindowFromRect(self,0,3);
  UI_GetChildSize(self,&local_34,&local_38);
  local_34 = local_34 + -3;
  local_38 = local_38 + -3;
  local_14 = (float)local_34 / (float)(intptr_t)local_24;
  value5 = Stats_GetGlobalMaximum();
  Gadget_SetTextf(arg1,0x414,(uint8_t *)s__0_0f_0056a690,SUB84((double)value5,0));
  if ((float)value5 <= 0.0) {
    local_1c = 0.0;
  }
  else {
    local_1c = (float)local_38 / (float)value5;
  }
  Gadget_SetTextf(arg1,0x415,(uint8_t *)s__d__d_00568ef8,
                  (uint32_t)*(uint8_t *)(*(int *)((intptr_t)DAT_0057c670 + 0x94) + 8));
  local_c = 0;
  do {
    value5 = local_c;
    local_10 = (float)local_38;
    local_2c = 0.0;
    local_30 = 0.0;
    local_18 = Game_GetPlayerBySlot(DAT_0057c670,local_c);
    if (((local_18 != 0) && ((&DAT_0056a644)[value5] == '\x01')) && (local_28 = 0, 0 < (intptr_t)uvalue6)) {
      do {
        IDMap_Lookup((void *)(local_18 + 0x19c),local_28,(int *)0x0);
        local_30 = local_30 + local_14;
        switch(DAT_0056a68c) {
        case 0:
          break;
        case 1:
          break;
        case 2:
          break;
        case 3:
          break;
        case 4:
          break;
        case 5:
          break;
        case 6:
          break;
        case 7:
          break;
        case 0xffffffff:
        }
        lvalue7 = __ftol();
        value5 = local_38 - (intptr_t)lvalue7;
        local_8 = value5;
        lvalue7 = __ftol();
        uptr1 = (uint32_t *)((intptr_t)lvalue7 + 1);
        lvalue7 = __ftol();
        lvalue8 = __ftol();
        uptr2 = (uint32_t *)((intptr_t)lvalue8 + 1);
        UI_DrawChildSprite(local_20,uptr2,(intptr_t)lvalue7 + 2,uptr1,value5 + 2,0);
        UI_DrawChildSprite(local_20,uptr2,(intptr_t)lvalue7 + 1,uptr1,value5 + 1,
                           *(uint32_t *)(local_18 + 0x1dc));
        local_2c = local_2c + local_14;
        local_28 = local_28 + 1;
        local_10 = (float)local_8;
      } while (local_28 < (intptr_t)local_24);
      uvalue6 = local_24;
      self = local_20;
      value5 = local_c;
    }
    local_c = value5 + 1;
  } while (local_c < 6);
  UI_ClipChildRect((intptr_t)self);
  RefCounted_Free(local_4);
  return;
}
