// EndResultGraph_DrawChart: ported from Pizza Connection 2 at 0x4c8320.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c8320
#include "pc2_port.h"

void __cdecl EndResultGraph_DrawChart(void *arg1)

{
  uint32_t *uptr1;
  uint32_t *uptr2;
  uint16_t uvalue3;
  void *self;
  int value4;
  uint32_t uvalue5;
  int64_t lvalue6;
  int64_t lvalue7;
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
  uvalue5 = (uint32_t)uvalue3;
  if (uvalue3 != 0) {
    local_24 = uvalue5;
    self = (void *)UI_GetWindowObject(arg1,0x581);
    local_20 = self;
    UI_RealizeSprite((intptr_t)self);
    local_4 = UI_CreateWindowFromRect(self,0,2);
    UI_GetChildSize(self,&local_34,&local_38);
    local_34 = local_34 + -2;
    local_38 = local_38 + -2;
    local_14 = (float)local_34 / (float)(intptr_t)local_24;
    value4 = Stats_GetGlobalMaxByMode();
    Gadget_SetTextf(arg1,0x582,(uint8_t *)s__0_0f_0056a690,SUB84((double)value4,0));
    if ((float)value4 <= 0.0) {
      local_1c = 0.0;
    }
    else {
      local_1c = (float)local_38 / (float)value4;
    }
    local_c = 0;
    do {
      value4 = local_c;
      local_10 = (float)local_38;
      local_2c = 0.0;
      local_30 = 0.0;
      local_18 = Game_GetPlayerBySlot(DAT_0057c670,local_c);
      if (((local_18 != 0) && ((&DAT_0056b250)[value4] == '\x01')) && (local_28 = 0, 0 < (intptr_t)uvalue5))
      {
        do {
          IDMap_Lookup((void *)(local_18 + 0x19c),local_28,(int *)0x0);
          local_30 = local_30 + local_14;
          switch(DAT_0056b270) {
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
          lvalue6 = __ftol();
          value4 = local_38 - (intptr_t)lvalue6;
          local_8 = value4;
          lvalue6 = __ftol();
          uptr1 = (uint32_t *)((intptr_t)lvalue6 + 1);
          lvalue6 = __ftol();
          lvalue7 = __ftol();
          uptr2 = (uint32_t *)((intptr_t)lvalue7 + 1);
          UI_DrawChildSprite(local_20,uptr2,(intptr_t)lvalue6 + 2,uptr1,value4 + 2,0);
          UI_DrawChildSprite(local_20,uptr2,(intptr_t)lvalue6 + 1,uptr1,value4 + 1,
                             *(uint32_t *)(local_18 + 0x1dc));
          local_2c = local_2c + local_14;
          local_28 = local_28 + 1;
          local_10 = (float)local_8;
        } while (local_28 < (intptr_t)local_24);
        uvalue5 = local_24;
        self = local_20;
        value4 = local_c;
      }
      local_c = value4 + 1;
    } while (local_c < 6);
    UI_ClipChildRect((intptr_t)self);
    RefCounted_Free(local_4);
  }
  return;
}
