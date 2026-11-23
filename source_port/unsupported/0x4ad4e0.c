// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x4ad4e0.c:150:30: error: operand of type 'float' cannot be cast to a pointer type
// StatisticsBranchBalance_DrawDailyChart: ported from Pizza Connection 2 at 0x4ad4e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ad4e0
#include "pc2_port.h"

void __cdecl StatisticsBranchBalance_DrawDailyChart(void *arg1)

{
  uint32_t *uptr1;
  uint16_t uvalue2;
  float fVar3;
  void *self;
  void *pvVar4;
  void *pvVar5;
  uint32_t uvalue6;
  int value7;
  uint32_t unaff_EDI;
  int value8;
  double fVar9;
  int64_t lvalue10;
  int64_t lvalue11;
  int local_88;
  int local_84;
  float local_80;
  int local_7c;
  float local_78;
  int local_74;
  uint32_t *local_70;
  void *local_6c;
  uint32_t local_68;
  int local_64;
  uint32_t *local_60;
  void *local_5c;
  int local_58;
  float local_54;
  float local_50;
  void *local_4c;
  int local_48;
  int *local_44;
  uint8_t local_40 [64];
  
  pvVar4 = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  uvalue2 = *(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  uvalue6 = (uint32_t)uvalue2;
  pvVar5 = (void *)0x0;
  local_6c = (void *)0x0;
  local_68 = uvalue6;
  local_4c = pvVar4;
  self = (void *)UI_GetWindowObject(arg1,0x86b);
  local_5c = self;
  UI_RealizeSprite((intptr_t)self);
  if (DAT_0056951c != -1) {
    pvVar5 = (void *)IDMap_Lookup((void *)((intptr_t)pvVar4 + 0x148),DAT_0056951c,(int *)0x0);
    local_6c = pvVar5;
  }
  if (uvalue6 == 0) {
    UI_GetChildSize(self,&local_74,&local_84);
    pvVar4 = (void *)Object_GetActiveValue((intptr_t)self);
    Text_SetMetrics(DAT_0057d638,local_74 / 2,local_84 / 2,2);
    Set_Field9B8(DAT_0057d638,0);
    Font_DrawTextLine(DAT_0057d638,pvVar4,DAT_00581444);
    Window_GadgetNotify_Text_SetText(arg1,0x840,DAT_00582e4c);
    Window_GadgetNotify_Text_SetText(arg1,0x841,DAT_00582e4c);
    UI_ClipChildRect((intptr_t)self);
    return;
  }
  if (DAT_0057d62c < 3) {
    local_78 = 1.12104e-44;
    local_64 = 0;
    local_68 = 8;
    if (DAT_0057d62c == 0) {
      local_88 = Stats_GetMaxMatrixValue(pvVar4,pvVar5);
    }
    else {
      if (DAT_0057d62c != 1) {
        if (DAT_0057d62c == 2) {
          local_88 = Game_GetMaxMatrixValue(pvVar4,(intptr_t)pvVar5);
          local_7c = 4;
        }
        goto LAB_004ad6b3;
      }
      Stats_GetMaxObjectMatrixValue((intptr_t)pvVar4,(intptr_t)pvVar5);
      lvalue10 = __ftol();
      local_88 = (intptr_t)lvalue10;
    }
  }
  else {
    if (uvalue2 < 0x29) {
      local_64 = 0;
      local_78 = (float)(intptr_t)(uvalue6);
    }
    else {
      local_64 = uvalue6 - 0x28;
      local_78 = 5.60519e-44;
    }
    if (DAT_0057d62c == 3) {
      local_88 = Stats_GetMaxCityMatrixValue(pvVar4,(uint32_t)pvVar5);
    }
    else {
      if (DAT_0057d62c != 4) {
        if (DAT_0057d62c == 5) {
          Game_GetObjectValue((intptr_t)pvVar4,(intptr_t)pvVar5);
          lvalue10 = __ftol();
          local_88 = (intptr_t)lvalue10;
          local_7c = 7;
        }
        goto LAB_004ad6b3;
      }
      Stats_GetMaxDailyFilteredSum((intptr_t)pvVar4,(intptr_t)pvVar5);
      lvalue10 = __ftol();
      local_88 = (intptr_t)lvalue10;
    }
  }
  local_7c = 9;
LAB_004ad6b3:
  fVar3 = (float)(intptr_t)(local_88);
  UI_GetChildSize(self,&local_74,&local_84);
  local_74 = local_74 + -3;
  local_84 = local_84 + -3;
  local_50 = (float)(intptr_t)(local_74) / (float)(intptr_t)local_78;
  if (fVar3 <= 0.0) {
    String_Format(local_40,DAT_00582e4c,unaff_EDI);
  }
  else {
    String_Format(local_40,(uint8_t *)s__0_2f_005685f4,SUB84((double)local_88,0));
  }
  Window_GadgetNotify_Text_SetText(arg1,0x840,local_40);
  String_Format(local_40,(uint8_t *)s__d__d_00568ef8,*(uint8_t *)(*(int *)(DAT_0057c670 + 0x94) + 8) + 1);
  Window_GadgetNotify_Text_SetText(arg1,0x841,local_40);
  if (fVar3 <= 0.0) {
    local_78 = 0.0;
  }
  else {
    local_78 = (float)(intptr_t)(local_84) / fVar3;
  }
  local_44 = UI_CreateWindowFromRect(self,0,3);
  local_58 = 0;
  if (0 < local_7c) {
    local_60 = &DAT_005695f4;
    do {
      value7 = local_58;
      local_54 = 0.0;
      fVar9 = Stats_SumByStorageMode(local_58,pvVar5);
      if (fVar9 <= (double)0.0) {
        fVar9 = (double)local_84;
      }
      else {
        fVar9 = (double)local_84 - fVar9 * (double)local_78;
      }
      local_70 = (uint32_t *)(float)(intptr_t)(fVar9);
      value8 = local_64;
      if (local_64 < (intptr_t)local_68) {
        do {
          switch(DAT_0057d62c) {
          case 0:
            value7 = Game_SumStatGridAll(pvVar4,value7,value8,pvVar5);
            fVar9 = (double)value7;
            break;
          case 1:
            fVar9 = Stats_SumRecordFloatMatrix((intptr_t)pvVar4,value7,value8,(intptr_t)pvVar5);
            break;
          case 2:
            value7 = Game_SumPlayerMatrixValues(pvVar4,value7,value8,pvVar5);
            fVar9 = (double)value7;
            break;
          case 3:
            value7 = Stats_SumMatrixCells(pvVar4,value7,value8,pvVar5);
            fVar9 = (double)value7;
            break;
          case 4:
            fVar9 = Stats_SumForPlayer((intptr_t)pvVar4,value7,value8,(intptr_t)pvVar5);
            break;
          case 5:
            fVar9 = Stats_SumGroupScores((intptr_t)pvVar4,value7,value8,(intptr_t)pvVar5);
            break;
          default:
            fVar9 = (double)local_80;
          }
          local_80 = (float)(fVar9 * (double)local_78);
          lvalue10 = __ftol();
          value7 = local_84 - (intptr_t)lvalue10;
          local_48 = value7;
          lvalue10 = __ftol();
          uptr1 = (uint32_t *)((intptr_t)lvalue10 + 1);
          lvalue10 = __ftol();
          lvalue11 = __ftol();
          local_70 = (uint32_t *)((intptr_t)lvalue11 + 1);
          UI_DrawChildSprite(local_5c,local_70,(intptr_t)lvalue10 + 2,uptr1,value7 + 2,0);
          UI_DrawChildSprite(local_5c,local_70,(intptr_t)lvalue10 + 1,uptr1,value7 + 1,*local_60);
          local_54 = local_54 + local_50;
          value8 = value8 + 1;
          local_70 = (uint32_t *)(float)(intptr_t)(local_48);
          pvVar5 = local_6c;
          pvVar4 = local_4c;
          value7 = local_58;
        } while (value8 < (intptr_t)local_68);
      }
      local_58 = value7 + 1;
      local_60 = local_60 + 1;
    } while (local_58 < local_7c);
    self = local_5c;
  }
  UI_ClipChildRect((intptr_t)self);
  RefCounted_Free(local_44);
  return;
}
