// Personnel_DrawEmployeeAbilityChart: ported from Pizza Connection 2 at 0x4b0d80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b0d80
#include "pc2_port.h"

void __cdecl
Personnel_DrawEmployeeAbilityChart
          (void *arg1,uint32_t *arg2,int arg3,float arg4,float arg5)

{
  uint32_t *uptr1;
  uint32_t *uptr2;
  uint16_t uvalue3;
  float fVar4;
  float fVar5;
  int value6;
  void *self;
  void *this_00;
  void *pvVar7;
  uint32_t uvalue8;
  int value9;
  int64_t lvalue10;
  int64_t lvalue11;
  int local_3c;
  int local_38;
  uint32_t *local_34;
  uint8_t local_20 [32];
  
  self = arg1;
  uvalue3 = *(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  uvalue8 = (uint32_t)uvalue3;
  this_00 = (void *)UI_GetWindowObject(arg1,arg3);
  UI_RealizeSprite((intptr_t)this_00);
  if (arg2 == (uint32_t *)0x0) {
    UI_ClipChildRect((intptr_t)this_00);
    return;
  }
  if (uvalue8 == 0) {
    UI_GetChildSize(this_00,(int *)&arg1,&arg3);
    pvVar7 = (void *)Object_GetActiveValue((intptr_t)this_00);
    Text_SetMetrics(DAT_0057d690,(intptr_t)arg1 / 2,arg3 / 2,2);
    Set_Field9B8(DAT_0057d690,0);
    Font_DrawTextLine(DAT_0057d690,pvVar7,DAT_00581444);
    Window_GadgetNotify_Text_SetText(self,(intptr_t)arg4,DAT_00582e4c);
    Window_GadgetNotify_Text_SetText(self,(intptr_t)arg5,DAT_00582e4c);
    UI_ClipChildRect((intptr_t)this_00);
    return;
  }
  arg2 = (uint32_t *)*arg2;
  if (uvalue3 < 0x29) {
    local_3c = 0;
    local_34 = (uint32_t *)uvalue8;
  }
  else {
    local_3c = uvalue8 - 0x28;
    local_34 = (uint32_t *)0x28;
  }
  UI_GetChildSize(this_00,(int *)&arg1,&arg3);
  UI_CreateWindowFromRect(this_00,0,3);
  arg1 = (void *)((intptr_t)arg1 + -3);
  fVar5 = (float)(intptr_t)arg1;
  arg3 = arg3 + -3;
  fVar4 = (float)(intptr_t)local_34;
  String_Format(local_20,(uint8_t *)s__0_2f_005685f4,0);
  Window_GadgetNotify_Text_SetText(self,(intptr_t)arg4,local_20);
  String_Format(local_20,(uint8_t *)s__d__d_00568ef8,*(uint8_t *)(*(int *)(DAT_0057c670 + 0x94) + 8) + 1);
  Window_GadgetNotify_Text_SetText(self,(intptr_t)arg5,local_20);
  local_34 = &DAT_0056a6f8;
  local_38 = 0;
  arg4 = (float)arg3 * 0.01;
  do {
    arg5 = 0.0;
    value6 = local_3c;
    if (local_3c == 0) {
      Stats_GetOrSumSeries(arg2,local_38,0);
      __ftol();
    }
    else {
      Stats_GetOrSumSeries(arg2,local_38,local_3c + -1);
    }
    for (; value6 < (intptr_t)uvalue8; value6 = value6 + 1) {
      arg5 = arg5 + fVar5 / fVar4;
      Stats_GetOrSumSeries(arg2,local_38,value6);
      lvalue10 = __ftol();
      value9 = arg3 - (intptr_t)lvalue10;
      lvalue10 = __ftol();
      uptr1 = (uint32_t *)((intptr_t)lvalue10 + 2);
      lvalue10 = __ftol();
      lvalue11 = __ftol();
      uptr2 = (uint32_t *)((intptr_t)lvalue11 + 2);
      UI_DrawChildSprite(this_00,uptr2,(intptr_t)lvalue10 + 3,uptr1,value9 + 3,0);
      UI_DrawChildSprite(this_00,uptr2,(intptr_t)lvalue10 + 2,uptr1,value9 + 2,*local_34);
    }
    local_38 = local_38 + 1;
    local_34 = local_34 + 1;
  } while ((intptr_t)local_34 < 0x56a70c);
  return;
}
