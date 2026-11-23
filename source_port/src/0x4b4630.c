// CompanyOverview_DrawQuarterChart: ported from Pizza Connection 2 at 0x4b4630.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b4630
#include "pc2_port.h"

void __cdecl CompanyOverview_DrawQuarterChart(void *arg1)

{
  uint32_t *uptr1;
  uint32_t *uptr2;
  uint16_t uvalue3;
  void *pvVar4;
  void *pvVar5;
  uint32_t uvalue6;
  int value7;
  int value8;
  int value9;
  float fVar10;
  uint32_t unaff_EDI;
  int value11;
  double fVar12;
  int64_t lvalue13;
  int64_t lvalue14;
  float local_8c;
  int local_88;
  float local_84;
  float local_80;
  int local_7c;
  float local_78;
  float local_74;
  int local_70;
  int local_6c;
  int local_68;
  void *local_64;
  int local_60;
  int local_5c;
  float local_58;
  int local_54;
  void *local_50;
  float local_4c;
  int *local_48;
  void *local_44;
  uint8_t local_40 [64];
  
  uvalue3 = *(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  fVar10 = (float)(uint32_t)uvalue3;
  local_68 = 0;
  local_4c = fVar10;
  pvVar4 = (void *)UI_GetWindowObject(arg1,0x41d);
  local_64 = pvVar4;
  UI_RealizeSprite((intptr_t)pvVar4);
  if (fVar10 == 0.0) {
    UI_GetChildSize(pvVar4,&local_7c,&local_88);
    pvVar5 = (void *)Object_GetActiveValue((intptr_t)pvVar4);
    Text_SetMetrics(DAT_0057d698,local_7c / 2,local_88 / 2,2);
    Set_Field9B8(DAT_0057d698,0);
    Font_DrawTextLine(DAT_0057d698,pvVar5,DAT_00581444);
    UI_ClipChildRect((intptr_t)pvVar4);
    return;
  }
  if (DAT_0057d6a4 == (void *)0x0) {
    UI_ClipChildRect((intptr_t)pvVar4);
    return;
  }
  if (uvalue3 < 0x29) {
    local_54 = 0;
    local_84 = fVar10;
  }
  else {
    local_54 = (intptr_t)fVar10 + -0x28;
    local_84 = 5.60519e-44;
  }
  value11 = local_54;
  local_6c = *(int *)((intptr_t)DAT_0057d6a4 + 0x14);
  pvVar5 = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  local_50 = pvVar5;
  if (local_6c == 0) {
    UI_ClipChildRect((intptr_t)pvVar4);
    return;
  }
  if (DAT_0056a7d4 != -1) {
    local_68 = IDMap_Lookup((void *)((intptr_t)pvVar5 + 0x148),DAT_0056a7d4,(int *)0x0);
  }
  UI_GetChildSize(pvVar4,&local_7c,&local_88);
  local_48 = UI_CreateWindowFromRect(pvVar4,0,5);
  local_88 = local_88 + -5;
  local_7c = local_7c + -5;
  if (DAT_0057d69c == 0) {
    pvVar4 = Game_FindTopScoringCompany(pvVar5,0x56a734,local_68);
    if (pvVar4 == (void *)0x0) {
LAB_004b4825:
      local_8c = 0.0;
    }
    else {
      local_60 = Stats_GetMaxTimelineCount(pvVar4,0x56a734);
      local_8c = (float)local_60;
    }
LAB_004b482d:
    local_84 = (float)local_7c / (float)(intptr_t)local_84;
LAB_004b4839:
    if (local_8c <= 0.0) {
      String_Format(local_40,DAT_00582e4c,unaff_EDI);
      goto LAB_004b487c;
    }
  }
  else {
    if (DAT_0057d69c == 1) {
      value7 = Stats_GetLeadingCompanyForCategory(pvVar5,0x56a734,local_68);
      if (value7 == 0) goto LAB_004b4825;
      fVar12 = Stats_GetMaxTimelineCategoryValue(value7,0x56a734);
      local_8c = (float)fVar12;
      goto LAB_004b482d;
    }
    if (DAT_0057d69c != 2) goto LAB_004b4839;
    local_8c = 100.0;
    local_84 = (float)local_7c / (float)local_6c;
  }
  String_Format(local_40,(uint8_t *)s__0_2f_005685f4,SUB84((double)local_8c,0));
LAB_004b487c:
  Window_GadgetNotify_Text_SetText(arg1,0x41f,local_40);
  String_Format(local_40,(uint8_t *)s__d__d_00568ef8,*(uint8_t *)(*(int *)(DAT_0057c670 + 0x94) + 8) + 1);
  Window_GadgetNotify_Text_SetText(arg1,0x41e,local_40);
  if (local_8c <= 0.0) {
    local_74 = 0.0;
  }
  else {
    local_74 = (float)local_88 / local_8c;
  }
  if (DAT_0057d69c < 2) {
    local_60 = 0;
    if (0 < local_6c) {
      do {
        value7 = local_60;
        local_78 = 0.0;
        pvVar4 = (void *)IDMap_Lookup(DAT_0057d6a4,*(int *)(DAT_0057d6a0 + local_60 * 4),(int *)0x0)
        ;
        local_44 = pvVar4;
        if (*(int *)(&DAT_0056a760 + *(int *)(DAT_0057d6a0 + value7 * 4) * 4) != 0) {
          if (value11 == 0) {
            fVar12 = (double)local_88;
          }
          else {
            local_80 = (float)local_88;
            if (DAT_0057d69c == 0) {
              local_70 = AI_CountPlanSteps(pvVar4,value11 + -1,0x56a734,DAT_0056a7d4);
              fVar12 = (double)local_70;
            }
            else {
              fVar12 = Stats_SumMaskedMapFloats((intptr_t)pvVar4,value11 + -1,0x56a734,DAT_0056a7d4);
            }
            fVar12 = (double)local_80 - fVar12 * (double)local_74;
          }
          local_80 = (float)fVar12;
          local_5c = value11;
          if (value11 < (intptr_t)fVar10) {
            while( true ) {
              if (DAT_0057d69c == 0) {
                local_70 = AI_CountPlanSteps(pvVar4,local_5c,0x56a734,DAT_0056a7d4);
              }
              else {
                Stats_SumMaskedMapFloats((intptr_t)pvVar4,local_5c,0x56a734,DAT_0056a7d4);
              }
              lvalue13 = __ftol();
              fVar10 = (float)(local_88 - (intptr_t)lvalue13);
              local_58 = fVar10;
              if ((local_68 == 0) || (*(void **)(local_68 + 0x14dc) != pvVar4)) {
                local_70 = Game_GetActiveCompanyOrdinal(local_50,(intptr_t)pvVar4);
              }
              else {
                local_70 = 0x14;
              }
              lvalue13 = __ftol();
              uptr1 = (uint32_t *)((intptr_t)lvalue13 + 2);
              lvalue13 = __ftol();
              lvalue14 = __ftol();
              uptr2 = (uint32_t *)((intptr_t)lvalue14 + 2);
              UI_DrawChildSprite(local_64,uptr2,(intptr_t)lvalue13 + 3,uptr1,(intptr_t)fVar10 + 3,0);
              uvalue6 = Game_GetGlobalTableValue(local_70);
              UI_DrawChildSprite(local_64,uptr2,(intptr_t)lvalue13 + 2,uptr1,(intptr_t)fVar10 + 2,uvalue6);
              local_78 = local_78 + local_84;
              local_5c = local_5c + 1;
              local_80 = (float)(intptr_t)local_58;
              if ((intptr_t)local_4c <= local_5c) break;
              pvVar4 = local_44;
            }
            fVar10 = local_4c;
            value11 = local_54;
            value7 = local_60;
          }
        }
        local_60 = value7 + 1;
      } while (local_60 < local_6c);
    }
  }
  else {
    local_80 = (float)local_88;
    value11 = 0;
    local_78 = 0.0;
    if (0 < local_6c) {
      do {
        pvVar4 = (void *)IDMap_Lookup(DAT_0057d6a4,*(int *)(DAT_0057d6a0 + value11 * 4),(int *)0x0);
        if (*(int *)(&DAT_0056a760 + *(int *)(DAT_0057d6a0 + value11 * 4) * 4) != 0) {
          fVar12 = Stats_AverageActiveCategories(pvVar4,0x56a734);
          local_58 = (float)(fVar12 * (double)local_74);
          if ((local_68 == 0) || (*(void **)(local_68 + 0x14dc) != pvVar4)) {
            value7 = Game_GetActiveCompanyOrdinal(local_50,(intptr_t)pvVar4);
          }
          else {
            value7 = 0x14;
          }
          uvalue6 = Game_GetGlobalTableValue(value7);
          lvalue13 = __ftol();
          value7 = (intptr_t)lvalue13;
          lvalue13 = __ftol();
          value8 = (intptr_t)lvalue13;
          lvalue13 = __ftol();
          value9 = local_88 - (intptr_t)lvalue13;
          lvalue13 = __ftol();
          Sprite_FillRectColor(local_64,(intptr_t)lvalue13,value9,value8,value7,uvalue6);
          local_78 = local_78 + local_84;
        }
        value11 = value11 + 1;
      } while (value11 < local_6c);
    }
  }
  UI_ClipChildRect((intptr_t)local_64);
  RefCounted_Free(local_48);
  return;
}
